module johnson(clk,q);
output[4:0]q;
input clk;
dff2 s4 (~q[0],clk,q[4]);
dff2 s3 (q[4],clk,q[3]);
dff2 s2 (q[3],clk,q[2]);
dff2 s1 (q[2],clk,q[1]);
dff2 s0 (q[1],clk,q[0]);
endmodule
module dff2(d,clk,q);
input d;
input clk;
output q;
reg q;
always@(posedge clk)
begin
q<=d;
end
endmodule
