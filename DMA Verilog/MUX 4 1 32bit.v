//////////Mux 4-1 32
module MUX4to1_32bit(in0,in1,in2,in3,out,sel);
input [31:0] in0;
input [31:0] in1;
input [31:0] in2;
input [31:0] in3;
input [1:0] sel;
output reg [31:0] out;

always@(sel , in0 , in1 , in2 , in3)
begin

case(sel)
0: out<= in0;
1: out<= in1;
2: out<= in2;
default: out<= in3;
endcase

end

endmodule 