module Adderplus4(sum,In1); //In1=pc
output reg [31:0] sum;
input [31:0] In1;
always @(In1)
begin
 sum = In1+4;
end
endmodule 