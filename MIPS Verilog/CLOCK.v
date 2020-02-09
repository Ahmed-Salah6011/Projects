`timescale 10ns/10ns
module CLK(clk);
output reg clk;

initial
begin
clk=0;
end

always
begin
#3.1
clk=~clk;
end

endmodule 