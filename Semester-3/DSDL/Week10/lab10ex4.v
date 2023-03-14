module lab10ex4(w,cp,Q);
input [4:0]w;
input cp;
output [4:0]Q;
Dff1 stage0(w[0],cp,Q[0]);
Dff1 stage1(w[1],cp,Q[1]);
Dff1 stage2(w[2],cp,Q[2]);
Dff1 stage3(w[3],cp,Q[3]);
Dff1 stage4(w[4],cp,Q[4]);
endmodule
module Dff1(d,cp,q);
input d,cp;
output q;
reg q;
always @(negedge cp)
begin
q <= d;
end
endmodule
