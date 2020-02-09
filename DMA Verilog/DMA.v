`timescale 10ns/10ns
module DMA (holdreq,ramdata,Addressout,ramctrl,intrack,clk,Addressin,data,holdack,intrREQ,hRDY,rhr);
input rhr;
output  holdreq;
output reg[5:0] Addressout;
output reg ramctrl;
output reg intrack;
input clk;
input [5:0]Addressin;
input holdack;
input [2:0]intrREQ;
input hRDY;
inout [31:0] data;
inout [31:0]ramdata;

assign holdreq = rhr;

assign data=(ramctrl==0&&hRDY==1 &&holdack==1)? ramdata:32'hzzzzzzzz;
assign data =32'hzzzzzzzz;

assign ramdata=(ramctrl==1&&hRDY==1&&holdack==1)? data:32'hzzzzzzzz;
assign ramdata =32'hzzzzzzzz;

//reg [4:0]i;
//reg [4:0]j;
initial
begin
//i=0;
//j=32;
intrack=0;
end
////

/*always@(data or Addressin or intrREQ)
begin

if(intrREQ[0]==0)
begin
if(i==31) begin i<=0; end
else begin i<=i+1; end
end

else if (intrREQ[0]==1)
begin
if(j==64) begin j<=32; end
else begin j<=j+1; end
end

end*/

///

///////////////////our operation
always @(posedge clk or hRDY or intrREQ)
begin
if(hRDY==1 &&holdack==1)
begin


if(intrREQ[1]==1)
begin
intrack<=1;

if(intrREQ[0]==0)
begin

if(intrREQ[2] ==0) 
begin
Addressout <= Addressin;
ramctrl<=0;
end

else if(intrREQ[2] ==1) 
begin
Addressout <= Addressin;
ramctrl<=1;
end

end

else if(intrREQ[0]==1)
begin

if(intrREQ[2] ==0) 
begin
ramctrl<=0;
Addressout <= Addressin;
end

else if(intrREQ[2] ==1) 
begin
Addressout <= Addressin;
ramctrl<=1;
end

end


end

else if(intrREQ[1]==0)
begin
intrack=0;
end


end
end
endmodule
