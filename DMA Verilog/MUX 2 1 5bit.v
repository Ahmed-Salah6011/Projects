module MuxTwoOnOne_5bit(ins1,ins2,selector,out1);
input [4:0] ins1 ,ins2 ;
input  selector;
output reg [4:0] out1;
 
always @(ins1,ins2,selector)
case (selector)
0:out1 <= ins1;
1:out1 <= ins2;
//default : out<=1'bx;
endcase 

endmodule 