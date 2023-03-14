module regn (R, L, Clock, Q);
parameter n = 8;
input [n-1:0] R;
input L, Clock;
output [n-1:0] Q;
reg [n-1:0] Q;
always @(posedge Clock)
if (L)
Q <= R;
endmodule
//module trin (Y, E, F);
//parameter n = 8;
//input [n-1:0] Y;
//input E;
//output [n-1:0] F;
//wire [n-1:0] F;
//assign F = E ? Y : 'bz;
//endmodule
module swap1 (Resetn, Clock, w, Data, Extern, R1, R2, R3, BusWires, Done);
parameter n = 8;
input Resetn, Clock, w, Extern;
input [n-1:0] Data;
output [n-1:0] BusWires,R1, R2, R3 ;
reg [n-1:0] BusWires, R1, R2, R3;
output Done;
//wire [n-1:0] R1, R2, R3;
wire R1in, R1out, R2in, R2out, R3in, R3out, RinExt1, RinExt2;
reg [2:0] y, Y;
parameter [2:0] A = 3'b000, B = 3'b001, C = 3'b010, D = 3'b011, E = 3'b100;
// Define the next state combinational circuit for FSM
always @(w or y)
begin
case (y)
A: if (w) Y = B;
else Y = A;
B: Y = C;
C: Y = D;
D: Y = E;
E: Y = A;
//F: Y = A; 
endcase
end
// Define the sequential block for FSM
always @(negedge Resetn or posedge Clock)
begin
if (Resetn == 0) y <= A;
else y <= Y;
end
// Define outputs of FSM
assign RinExt1 = (y == A);
assign RinExt2 = (y == B);
assign R3in = (y == C);
assign R1out = (y == C);
assign R2out = (y == D);
assign R1in = (y == D);
assign R3out = (y == E);
assign R2in = (y == E);
assign Done = (y == E);
always @(Extern or R1out or R2out or R3out)
if (Extern) BusWires = Data;
//else if (RinExt1) R1= BusWires;
//else if (RinExt2) R2= BusWires;
else if (R1out) BusWires = R1;
else if (R2out) BusWires = R2;
else if (R3out) BusWires = R3;
//assign BusWires=BusWires1;
// Instantiate registers
//regn reg1 (BusWires, RinExt1, Clock, R1);
//regn reg2 (BusWires, RinExt2, Clock, R2);
regn reg3 (BusWires, R3in, Clock, R3);
regn reg4 (BusWires, RinExt1 | R1in, Clock, R1);
regn reg5 (BusWires, RinExt2 | R2in, Clock, R2);
// Instantiate tri-state drivers
//trin triext (Data, Extern, BusWires1);
//trin tr1 (R1, R1out, BusWires1);
//trin tr2 (R2, R2out, BusWires1);
//trin tr3 (R3, R3out, BusWires1);
//assign BusWires=BusWires1;
//endmodule
endmodule
