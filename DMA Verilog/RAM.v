`timescale 10ns/10ns
module Ram(ramCtrl,Data,Address,clk);
input clk,ramCtrl;
input [5:0] Address;
inout [31:0]Data;
reg ramflag;
reg [31:0]M[0:63];
integer i;

assign Data = 32'hzzzzzzzz;
assign Data = (ramflag==0 && ramCtrl==0)? M[Address]: 32'hzzzzzzzz;



initial
begin
ramflag=0;

for(i=0;i<64;i=i+1)
begin
M[i]=i;
end
end

always @(posedge clk or ramCtrl)
begin

if(ramCtrl)
begin
ramflag<=1;
if (!(Data === 32'hzzzzzzzz)) begin M[Address]<=Data; end


end

end

always @(posedge clk or ramCtrl)
begin

if(!ramCtrl)
begin
ramflag <=0;
end

end


endmodule



module ram_tb();
reg ramCtrl,clk;
wire [31:0]Data;
reg [5:0]Address;
reg flag;

Ram r(ramCtrl,Data,Address,clk);

assign Data=(flag==1)? 32'h0000000b:32'hzzzzzzzz;
assign Data=32'hzzzzzzzz;

always
begin
#3.1
clk=~clk;
end

initial
begin
clk=0;
flag=0;

ramCtrl=0;
Address =8;
#9
ramCtrl=1;
Address=2;
flag=1;
#8
ramCtrl=0;
Address =12;
flag=0;

end


endmodule 