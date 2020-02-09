module arbitration(clk,holdAck_Proc,intReq1,intReq2,intAck1,intAck2,hReady1,hReady2,hReady,intReq_Proc,intAck_Proc,intReq_Dma,intAck_Dma,Data1,Data2,Data,inAddress1,inAddress2,inAddress);
input holdAck_Proc,clk;
input [2:0]intReq1,intReq2;
output reg intAck1,intAck2;
input hReady1,hReady2;
output reg [2:0]intReq_Proc;
input intAck_Proc;
output reg [2:0]intReq_Dma;
input intAck_Dma;
input[5:0]inAddress1,inAddress2;

inout[31:0]Data1,Data2,Data;


output reg hReady;
output reg [5:0]inAddress;

reg [2:0]pr_intReq;
reg pr_intAck;

/////
assign Data = (((intReq1[1]==1 && intReq2[1]==0 ) || (intReq1[1]==1 && intReq2[1]==1 )) && intReq1[2]==1)?Data1
	     :((intReq1[1]==0 && intReq2[1]==1 ) && intReq2[2]==1)? Data2 
	     :32'hzzzzzzzz;
assign Data=32'hzzzzzzzz;

////
assign Data1 = (((intReq1[1]==1 && intReq2[1]==0 ) || (intReq1[1]==1 && intReq2[1]==1 )) && (intReq1[2]==0))?Data : 32'hzzzzzzzz;
assign Data1 = 32'hzzzzzzzz;
/////
assign Data2 = ((intReq1[1]==0 && intReq2[1]==1 ) && intReq2[2]==0)?Data:32'hzzzzzzzz;
assign Data2=32'hzzzzzzzz;
////


////
////holdreq pr
always @(posedge clk or holdAck_Proc or intReq1 or intReq2 or hReady1 or hReady2)
begin

if(holdAck_Proc==0)
begin
intReq_Dma<=0;
pr_intAck<=intAck_Proc;
intReq_Proc<=pr_intReq;
end

else if (holdAck_Proc==1)
begin
intReq_Proc<=0;
pr_intAck<=intAck_Dma;
intReq_Dma<=pr_intReq;
end


end


////pri always
always@(posedge clk ,intReq1,intReq2,hReady1,hReady2)
begin
///first i/o
if((intReq1[1]==1 && intReq2[1]==0 ) || (intReq1[1]==1 && intReq2[1]==1 ))
begin
pr_intReq<=intReq1;
intAck1<=pr_intAck;
intAck2<=0;
hReady<=hReady1;
//Data <= Data1;///mis
inAddress <= inAddress1;
end

//second i/o
else if (intReq1[1]==0 && intReq2[1]==1 )
begin
pr_intReq<=intReq2;
intAck2<=pr_intAck;
intAck1<=0;
hReady<=hReady2;
//Data <= Data2;///mis
inAddress <= inAddress2;
end

///
else if (intReq1[1]==0 && intReq2[1]==0 )
begin
intReq_Proc<=0;
intReq_Dma<=0;
end

end


endmodule


