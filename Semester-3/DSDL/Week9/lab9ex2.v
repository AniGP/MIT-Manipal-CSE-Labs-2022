module lab9ex2(abcd, f, g, h, en);
	input [3:0]abcd;
	output f, g, h;
	input en;

	wire [15:0]y;

	fourtosixtn stage7(abcd[3:0], y[15:0], en);
	assign f = y[10]|y[11]|y[3]|y[6]|y[7]|y[14];
	assign g = y[14]|y[10]|y[2]|y[3];
	assign h = y[0]|y[1]|y[14]|y[15]|y[3]|y[7];
endmodule

module fourtosixtn(w, y, en);
	input [3:0]w;
	output [15:0]y;
	input en;

	wire [3:0]f;

	twotofour stage0(w[3:2], f[3:0], en);
	twotofour stage1(w[1:0], y[3:0], f[0]);
	twotofour stage2(w[1:0], y[7:4], f[1]);
	twotofour stage3(w[1:0], y[11:8], f[2]);
	twotofour stage4(w[1:0], y[15:12], f[3]);
endmodule

module twotofour(w, y, en);
	input [1:0]w;
	output [3:0]y;
	input en;

	reg [3:0]y;
	always@(w)
	begin
		if(en==0)
			y=0;
	
		else
		begin
			case(w)
				0:y=4'b0001;
				1:y=4'b0010;
				2:y=4'b0100;
				3:y=4'b1000;
			endcase
		end
	end
endmodule
