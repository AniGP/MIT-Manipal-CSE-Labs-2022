module lab10ex2(t,cp,reset,q);
input t;
input cp;
input reset;
output q;
reg q;
always @(negedge reset or negedge cp)
begin
if(!reset)
q = 0;
else
begin
if(t)
q = ~q;
end
end
endmodule
