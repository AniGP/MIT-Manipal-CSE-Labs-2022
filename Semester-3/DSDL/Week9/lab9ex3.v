module lab9ex3(abc, m, en);
	input [2:0]abc;
	output m;
	input en;
	
	wire w1, w2;
	wire [7:0]f;

	assign w1 = ~abc[2]&en;
	assign w2 = abc[2]&en;

	threetwotofr stage0(abc[1:0], f[3:0], w1);
	threetwotofr stage1(abc[1:0], f[7:4], w2);
	assign m = f[3]|f[5]|f[6]|f[7];
endmodule

module threetwotofr(w, y, en);
	input [1:0]w;
	output [3:0]y;
	input en;
	reg [3:0]y;

	always@(w or en)
	begin
		if(en==0)
			y=0;
	
		else
		begin
			case(w)
				0:y=1;
				1:y=2;
				2:y=4;
				3:y=8;
			endcase
		end
	end
endmodule  
