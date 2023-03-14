module Tflipflop(T,cp,q);
input T;
input cp;
output q;
reg q;
always @(negedge cp)
begin
if(!T)
q <= q;
else
q <= ~q;
end
endmodule
module 4bitupcounterasyn(cp,q);
input cp;
output [3:0]q;
Tflipflop stage0(1,cp,q[0]);
Tflipflop stage1(1,q[0],q[1]);
Tflipflop stage2(1,q[1],q[2]);
Tflipflop stage3(1,q[2],q[3]);
Tflipflop stage4(1,q[3],q[4]);
endmodule
