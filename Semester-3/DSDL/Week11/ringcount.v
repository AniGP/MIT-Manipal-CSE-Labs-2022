module ringcount(clk,f);
input clk;
output [3:0]f;
wire [1:0]w;
dff1 stage0(w[0]^w[1],clk,w[1]);
dff1 stage1(~w[0],clk,w[0]);
dec24 stage2(w,clk,f);
endmodule
module dff1(d,clk,q);
input d;
input clk;
output q;
reg q;
always@(posedge clk)
begin
q<=d;
end
endmodule
module dec24(w,en,y);
input [1:0]w;
input en;
output [3:0]y;
reg [3:0]y;
always@(posedge en)
begin
casex(w)
0:y=4'b0001;
1:y=4'b0010;
2:y=4'b0100;
3:y=4'b1000;
endcase
end
endmodule
