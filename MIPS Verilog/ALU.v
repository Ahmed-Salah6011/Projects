////////////ALU
module alu_processor(aluout , zeroflag, in1 , in2 , aluctrl ,sll);
output reg [31:0] aluout ;
output zeroflag ;
input [31:0] in1 , in2 ;
input [3:0] aluctrl ;
 input [4:0] sll ;
assign zeroflag = aluout==0? 1 :0 ;
always @ (in1 , in2 ,aluctrl,sll)
begin
case(aluctrl)
0 : aluout <= in1 & in2 ;
1 : aluout <= in1 | in2 ;
2 : aluout <= in1 + in2 ;
6 : aluout <= in1 - in2 ;
7 : aluout <=  in1< in2 ?1 : 0 ;
15 : aluout <= in2<< sll;
default : aluout <= 0 ;
endcase
end
endmodule 