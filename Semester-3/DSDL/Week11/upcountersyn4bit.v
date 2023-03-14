module upcountersyn4bit(cp,q);
input cp;
output [3:0]q;
wire [1:0]q1;
Tflipflop stage0(1,cp,q[0]);
Tflipflop stage1(q[0],cp,q[1]);
assign q1[0] = q[0]&q[1];
Tflipflop stage2(q1[0],cp,q[2]);
assign q1[1] = q1[0]&q[2];
Tflipflop stage3(q1[1],cp,q[3]);
endmodule
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
