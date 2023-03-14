module swapmux (Resetn, Clock, w, Data, RinExt1, RinExt2, RinExt3, BusWires, Done, R1, R2, R3);
parameter n = 8;
input Resetn, Clock, w, RinExt1, RinExt2, RinExt3;
input [n-1:0] Data;
output [n-1:0] BusWires, R1, R2, R3;
reg [n-1:0] BusWires;
output Done;
wire [n-1:0] R1, R2, R3;
wire R1in, R2in, R3in;
reg [2:1] y, Y;
parameter [2:1] A = 2'b00, B = 2'b01, C = 2'b10, D = 2'b11;
// Define the next state combinational circuit for FSM
always @(w or y)
case (y)
A: if (w) Y = B;
else Y = A;
B: Y = C;
C: Y = D;
D: Y = A;
endcase
// Define the sequential block for FSM
always @(negedge Resetn or posedge Clock)
if (Resetn == 0) y<=A;
else y<=Y;
// Define control signals
assign R3in = (y == B);
assign R2in = (y == C);
assign R1in = (y == D);
assign Done = (y == D);
// Instantiate registers
regn reg1 (BusWires, RinExt1 | R1in, Clock, R1);
regn reg2 (BusWires, RinExt2 | R2in, Clock, R2);
regn reg3 (BusWires, RinExt3 | R3in, Clock, R3);
// Define the multiplexers
always @(y or Data or R1 or R2 or R3)
if (y == A) BusWires = Data;
else if (y == B) BusWires = R2;
else if (y == C) BusWires = R1;
else BusWires = R3;
endmodule
module regn(R, L, Clock, Q);
parameter n = 8;
input [n-1:0] R;
input L, Clock;
output[n-1:0] Q;
reg [n-1:0] Q;
always @(posedge Clock)
if (L)
Q <= R;
endmodule
