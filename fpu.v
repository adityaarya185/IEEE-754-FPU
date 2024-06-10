`include "fpu_cal.v"

module top_module
(
  input clk,
  input reset,
  input [31:0]  A,
  input [31:0]  B,
  input [1:0] mode,
  input round_mode,
  input start,
  output  reg error,
  output reg overflow,
  output reg underflow,
  output reg done,
  output reg [31:0] Y
);

reg [31:0] A_fpu, B_fpu;
reg [1:0] mode_fpu;
reg round_fpu;

wire under_flow,over_flow,err,done_fpu;
wire [31:0] Y_fpu;
fpu fpu(clk,start,A_fpu,B_fpu,mode_fpu,round_fpu,err,over_flow,under_flow,done_fpu,Y_fpu);

always @(posedge clk or negedge reset)
begin
    if(~reset) 
    begin
		A_fpu <=0;
		B_fpu <=0;
		mode_fpu <=0;
		round_fpu <=0;
		Y<=0;
		done<=0;
		
	 end
     else begin
		if(start) begin
			A_fpu <=A;
			B_fpu <=B;
			mode_fpu <=mode;
			round_fpu <=round_mode;
			done<=0;
		end
		else begin
			A_fpu <=A_fpu;
			B_fpu <=B_fpu;
			mode_fpu <=mode_fpu;
			round_fpu <=round_fpu;
			Y <= Y_fpu;
			overflow <= over_flow;
            underflow<=under_flow;
			error <= err;
			done<=done_fpu;
		end
	end
end
endmodule