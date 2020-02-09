/////////Mux 2to1
module muxTwoOnOne_32bit(in1,in2,sel,out);
input [31:0] in1 ,in2 ;
input  sel;
output reg [31:0] out;
 
always @(in1,in2,sel)
case (sel)
0:out <= in1;
1:out <= in2;
default : out<=1'bx;
endcase 

endmodule
