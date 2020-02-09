`timescale 10ns/10ns
module processor(clk,intReq , intAck , holdReq , holdAck , Data, inAddress, outAddress , hReady , ramCtrl , ramData);
input clk;
input holdReq,hReady;
output reg ramCtrl;
input[5:0]inAddress;
input [2:0] intReq;

inout [31:0]Data;	
inout [31:0]ramData;

output reg intAck,holdAck;
output reg[5:0]outAddress;
reg [31:0]tempReg;
//reg [4:0]i;
//reg [4:0]j;
reg flag;


assign Data = (ramCtrl==0 && hReady==1 && holdAck==0)? ramData : 32'hzzzzzzzz ;
assign Data=32'hzzzzzzzz;


assign ramData = (ramCtrl==1 && hReady==1 && holdAck==0)? Data : 32'hzzzzzzzz ;
assign ramData=32'hzzzzzzzz;

///////
initial
begin
flag=0;
//i=0;
//j=32;
intAck=0;
holdAck=0;
tempReg=0;
end
/////////////
/*always @(Data or intReq or inAddress)
begin
if(intReq[0]==0)
begin
if(i==31) begin i<=0; end
else begin i<=i+1; end
end

else if (intReq[0]==1)
begin
if(j==64) begin j<=32; end
else begin j<=j+1; end
end

end*/
////////////////adding
always @(posedge clk)
begin

if (flag==0)
begin
tempReg<=tempReg+1;
end

end
////////////////////


//////////////////////moving data
always @(posedge clk or hReady or intReq) 
begin
if(hReady && holdAck==0)
begin


if(intReq[1])///i/o requested
begin
flag=1;
intAck<=1;

if(intReq[0]==0)///first i/o
begin

if(intReq[2] ==0) ///read
begin
flag<=1;
outAddress <= inAddress;
ramCtrl<=0;
end

else if(intReq[2] ==1) ///write
begin
flag<=1;
outAddress <= inAddress;
ramCtrl<=1;
end



end



else if(intReq[0]==1)///second i/o
begin
if(intReq[2] ==0) ///read
begin
flag<=1;
ramCtrl<=0;
outAddress <= inAddress;
end


else if(intReq[2] ==1) ///write
begin
flag<=1;
outAddress <= inAddress;
ramCtrl<=1;
end


end




end



else if(intReq[1]==0) /// io not requested
begin
flag<=0;
intAck=0;
end




end



end
/////////////////////////


////////////hold condition
always@(posedge clk or holdReq)
begin
if(holdReq==1)
begin

if(flag==1) begin holdAck<=0; end
else if (flag==0) begin holdAck<=1; end

end

else 
begin holdAck<=0; end


end




endmodule
