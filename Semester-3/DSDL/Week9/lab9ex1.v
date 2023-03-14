module lab9ex1(w, y, en, f);
	input [3:0]w;
	output [15:0]y;
	input en;
	output f;

	deco stage0(w[3:0], y[15:0], en);
	assign f = y[1]|y[3]|y[6]|y[7]|y[9]|y[14]|y[15];
endmodule

module deco(w, y, en);
	input [3:0]w;
	output [15:0]y;
	input en;
	reg [15:0]y;

	integer i;
	always@(w)
	begin
		if(en==0)
			y=0;
		
		else
		begin
			
			for(i=0; i<16; i=i+1)
			begin
				if(w==i)
					y[i]=1;
				else
					y[i]=0;
			end
		
		end
	end
endmodule
