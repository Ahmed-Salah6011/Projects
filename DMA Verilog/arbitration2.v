module t7kim (Data,Data_Proc,Data_Dma,ramCtrl,outAddress,clk,ramctrldma,ramctrlproc,outaddressdma,outaddressproc,holdackproc);
input ramctrldma,ramctrlproc,holdackproc,clk;
input [5:0] outaddressdma,outaddressproc;
output reg ramCtrl;
output reg [5:0] outAddress;
//assign data=(ramctrl==0&&hRDY==1 &&holdack==1)? ramdata:32'hzzzzzzzz ;
reg flag;

inout [31:0] Data,Data_Proc,Data_Dma;

///
assign Data = (flag ==1 && ramctrldma==1)? Data_Dma
		:(flag ==0 && ramctrlproc ==1)? Data_Proc
		:32'hzzzzzzzz;
assign Data = 32'hzzzzzzzz;

////
assign Data_Proc = (flag==0 && ramctrlproc ==0)? Data:32'hzzzzzzzz;
assign Data_Proc = 32'hzzzzzzzz;
////
assign Data_Dma = (flag==1 && ramctrldma ==0)? Data:32'hzzzzzzzz;
assign Data_Dma = 32'hzzzzzzzz;

///
initial
begin
flag=0;
end

/////////////////////////ramctrl and address
always@(posedge clk or ramctrlproc or ramctrldma)
begin
if(holdackproc)
begin
flag<=1;
outAddress<=outaddressdma;
ramCtrl<=ramctrldma;
end
else
begin
flag<=0;
outAddress<=outaddressproc;
ramCtrl<=ramctrlproc;
end
end



endmodule


module ta7kim2(Data,Data_Proc,Data_Dma,holdAck,intReq_Dma,intReq_Proc);
input holdAck;
input [2:0] intReq_Dma,intReq_Proc;

inout [31:0] Data,Data_Proc,Data_Dma;


assign Data =(holdAck==1 && intReq_Dma[2]==0)? Data_Dma
		:(holdAck==0 && intReq_Proc[2]==0)? Data_Proc
		:32'hzzzzzzzz;
assign Data = 32'hzzzzzzzz;

assign Data_Proc =(holdAck==0 && intReq_Proc[2]==1)? Data: 32'hzzzzzzzz;
assign Data_Proc =32'hzzzzzzzz;

assign Data_Dma=(holdAck==1 && intReq_Dma[2]==1)? Data:32'hzzzzzzzz;
assign Data_Dma =32'hzzzzzzzz;

endmodule 


