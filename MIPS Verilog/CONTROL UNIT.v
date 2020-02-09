module control(register,RegDst,Jump,Branch,MemRead,MemtoReg,ALUOp,MemWrite,ALUSrc,RegWrite);
input register;
wire[31:0] register;
output RegDst,Jump,Branch,MemRead,MemtoReg,ALUOp,MemWrite,ALUSrc,RegWrite;
reg Jump,Branch,MemRead,MemWrite,ALUSrc,RegWrite;
reg[1:0] ALUOp ;
reg[1:0] RegDst;
reg[1:0] MemtoReg;
reg[5:0] Data;
always@(register)
begin
Data=register[31:26];
case(Data) 
6'b000000 :          // R format
 begin
RegDst=2'b01;
Jump=1'b0;
Branch=1'b0;
MemRead=1'b0;
MemtoReg=2'b00;
ALUOp=2'b10;
MemWrite=1'b0;
ALUSrc=1'b0;
RegWrite=1'b1;
end
6'b100011 :            //LW
 begin
RegDst=2'b00;
Jump=0;
Branch=0;
MemRead=1;
MemtoReg=2'b01;
ALUOp=2'b00;
MemWrite=0;
ALUSrc=1;
RegWrite=1;
end
6'b101011 :              //SW
 begin
RegDst=2'bxx;
Jump=0;
Branch=0;
MemRead=0;
MemtoReg=2'bxx;
ALUOp=2'b00;
MemWrite=1;
ALUSrc=1;
RegWrite=0;
end
6'b000100 :                 //beg
begin
RegDst=2'bxx;
Jump=0;
Branch=1;
MemRead=0;
MemtoReg=2'bxx;
ALUOp=2'b01;
MemWrite=0;
ALUSrc=0;
RegWrite=0;
end
6'b000010 :               //Jump
begin
RegDst=2'bxx;
Jump=1;
Branch=0;
MemRead=0;
MemtoReg=2'bxx;
ALUOp=2'bxx;
MemWrite=0;
ALUSrc=1'bx;
RegWrite=0;
end
6'b001000 :           //addi 
begin
RegDst=2'b00;
Jump=0;
Branch=0;
MemRead=0;
MemtoReg=2'b00;
ALUOp=2'b00;
MemWrite=0;
ALUSrc=1;
RegWrite=1;
end
6'b001111  :         //lui
begin
RegDst=2'b00;
Jump=0;
Branch=0;
MemRead=0;
MemtoReg=2'b00;
ALUOp=2'b11;
MemWrite=0;
ALUSrc=1;
RegWrite=1;
end
6'b000011 :            //jal
begin
RegDst=2'b10;
Jump=1;
Branch=0;
MemRead=0;
MemtoReg=2'b10;
ALUOp=2'bxx;
MemWrite=0;
ALUSrc=1'bx;
RegWrite=1;
end
6'b001101 :           //ori
begin
RegDst=2'b00;
Jump=0;
Branch=0;
MemRead=0;
MemtoReg=2'b00;
ALUOp=2'b00;          //????????
MemWrite=0;
ALUSrc=1;
RegWrite=1;
end
/*default : begin
RegDst=2'bxx;
Jump=1'bx;
Branch=1'bx;
MemRead=1'bx;
MemtoReg=2'bxx;
ALUOp=2'bxx;          
MemWrite=1'bx;
ALUSrc=1'bx;
RegWrite=1'bx;
end*/
endcase
end
endmodule 