module lab10ex1(d,reset,cp,q);
input d,cp,reset;
output q;
reg q;
always @(posedge reset or posedge cp)
begin
if(reset)
q = 0;
else
q = d;
end
endmodule
