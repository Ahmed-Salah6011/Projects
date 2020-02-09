`timescale 10ns/10ns
module pc(NIN,inp,out,clk);
	
input wire[31:0]  inp,NIN;
input clk;
output reg [31:0]  out;
integer file2;
initial
begin
out=0;
#1200
file2=$fopen("E:/PC.txt");
$fmonitor(file2,"%b",out-4);
end


always@(posedge clk )
begin
if(NIN!==32'hxxxxxxxx)
   out <= inp;
end
endmodule 