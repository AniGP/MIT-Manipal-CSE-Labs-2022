module lab10ex5(w,cp,q);
input w,cp;
output [5:0]q;
reg [5:0]q;
parameter n = 6;
integer i;
always @(posedge cp)
begin
for(i = 0 ; i < n-1 ; i = i+1)
q[i] <= q[i+1];
q[n-1] <= w;
end
endmodule
