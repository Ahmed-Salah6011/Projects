///////////RF
`timescale 10ns/10ns
module registerFile(rg1,rg2,wrg,wdata,rgwr,rd1,rd2,clk);
input [4:0]rg1;
input [4:0]rg2;
input [4:0]wrg;
input [31:0]wdata;
input rgwr;
input clk;
output reg[31:0]rd1;
output reg[31:0]rd2;
integer file2;
integer k;

reg [31:0]RF[0:31];



integer j;
initial
begin
for(j=0;j<=31;j=j+1)
begin
RF[j]=j;
end
#1200
file2=$fopen("E:/RegFile.txt");
$fmonitor(file2,"%b",RF[j]);
for( j =0 ; j<=30 ; j=j+1)
begin
#1
j=j;
end
//$fclose(file2);
end

/*always@(rd1)
begin
if(rd1===32'bxxxx_xxxx_xxxx_xxxx_xxxx_xxxx_xxxx_xxxx)
begin
$fmonitor(file2,"%b",RF[k]);
for( k =0 ; k<=30 ; k=k+1)
begin
#1
k=k;
end


end

end*/


always@(posedge clk)
begin
if(rgwr==1)
begin
RF[wrg]=wdata;
end
end

always @(rg1 or rg2)
begin
rd2=RF[rg2];
rd1=RF[rg1];
end


endmodule 
