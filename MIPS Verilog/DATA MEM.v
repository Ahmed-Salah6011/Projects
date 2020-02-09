`timescale 10ns/10ns
module DataMemory(Address,WriteData,ReadData,MemWrite,MemRead,clk);
input [31:0] Address,WriteData;
input MemWrite,MemRead,clk;
output reg [31:0] ReadData;

reg [31:0] M[0:8191];

integer i;
integer j;
integer file2;
reg [1:0] flag;
initial
begin
flag=2'b00;
for(i =0 ; i<=8191 ; i=i+1)
begin
M[i]=i;
end
#1200
file2=$fopen("E:/DataMemoryFile.txt");
$fmonitor(file2,"%b",M[j]);
for( j =0 ; j<=8190 ; j=j+1)
begin
#1
j=j;
end
//$fclose(file2);
end


/*always@(mainaddress)
begin
if(mainaddress===32'b0000_0000_0000_0000_0000_0000_0000_000x)
begin
flag=2'b01;
if(flag==2'b01)
begin
flag=2'b10;
#1200
file2=$fopen("E:/DataMemoryFile.txt");
$fmonitor(file2,"%b // %d",M[j],M[j]);
for( j =0 ; j<=8190 ; j=j+1)
begin
#1
j=j;
end
$fclose(file2);
end
end
end*/



always @ (posedge clk)
begin

if (MemWrite ==1)
begin
M[Address>>2]<=WriteData;
end

end

always@(Address)
begin

if(MemRead ==1)
begin
ReadData<=M[Address>>2];
end

end

endmodule 