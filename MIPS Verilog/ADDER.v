module Adder(sum,In1,In2); //In1=pc
output reg [31:0] sum;
input [31:0] In1;
input [31:0] In2;
always @ (In1 or In2)
begin
 sum = In1+In2;
end
endmodule 