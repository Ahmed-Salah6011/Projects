`timescale 10ns/10ns
module mips();
wire clk;
wire [31:0] NIN;
wire [31:0]Address;
wire [4:0]writeRegister;
wire [1:0] RegDst;
wire [31:0] writeData;
wire RegWrite;
wire [31:0] readData1;
wire [31:0] readData2;
wire [31:0] signextend;
wire [31:0] AluInp2;
wire Jump,Branch,MemRead,MemWrite,ALUSrc;
wire[1:0] ALUOp ;
wire[1:0] MemtoReg;
wire [31:0] AluResult;
wire [31:0] AluResult2;
wire zeroflag;
wire [3:0]AluCtrl;
wire [31:0] ReadData;
wire [31:0] OutAdderpc;
wire [31:0]nextIns;
wire AndSel;
wire [31:0]outMux;
wire [27:0]sh = NIN[25:0]<<2;

CLK clkgen(clk);

InstructionMemory ins_mem(NIN,Address);

MUX4to1_5bit m4(NIN[20:16],NIN[15:11],5'd31,5'bxxxxx,writeRegister,RegDst);

registerFile rf(NIN[25:21],NIN[20:16],writeRegister,writeData,RegWrite,readData1,readData2,clk);

control cn(NIN,RegDst,Jump,Branch,MemRead,MemtoReg,ALUOp,MemWrite,ALUSrc,RegWrite);

muxTwoOnOne_32bit m2(readData2,signextend,ALUSrc,AluInp2);

alu_processor ap(AluResult , zeroflag, readData1 , AluInp2 , AluCtrl ,NIN[10:6]);

ALuControlUnit ac(ALUOp,NIN[5:0],AluCtrl);

DataMemory dm(AluResult,readData2,ReadData,MemWrite,MemRead,clk);

MUX4to1_32bit m6(AluResult,ReadData,OutAdderpc,32'hxxxxxxxx,writeData,MemtoReg);

Adderplus4 kj(OutAdderpc,Address);

pc cm(NIN,nextIns,Address,clk);

Adder adx(AluResult2,OutAdderpc,signextend<<2);

and g1(AndSel,Branch,zeroflag);

muxTwoOnOne_32bit m10(OutAdderpc,AluResult2,AndSel,outMux);

muxTwoOnOne_32bit m11(outMux,{OutAdderpc[31:28],sh},Jump,nextIns);

signExtender ex(NIN[15:0],signextend);

endmodule




