module lab10ex3(j,k,cp,reset,q);
input j,k,cp,reset;
output q;
reg q;
always @(posedge cp)
begin
casex({reset,j,k})
3'b1xx : q<=0;
3'b001 : q<=0;
3'b010 : q<=1;
3'b011 : q<=~q;
3'b000 : q<=q;
endcase
end
endmodule
