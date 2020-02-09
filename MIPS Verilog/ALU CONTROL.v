/////////////Alu Control
module ALuControlUnit(ALUOP,func,ALUcontoloOut);
input [1:0] ALUOP;
input [5:0] func;
output reg [3:0] ALUcontoloOut;
wire [7:0]ALU_Fn;

assign ALU_Fn  ={ALUOP,func};

always@(ALU_Fn)

casex (ALU_Fn)

8'b10100100:ALUcontoloOut <=4'b0000 ;  //and
8'b10100101:ALUcontoloOut <=4'b0001 ; //or
8'b10100000:ALUcontoloOut <=4'b0010 ; //add
8'b10100010:ALUcontoloOut <=4'b0110 ; //sub
8'b10101010:ALUcontoloOut <=4'b0111 ; //slt
8'b10100111:ALUcontoloOut <=4'b1100 ; //nor
8'b10000000:ALUcontoloOut <=4'b1111 ; //sll

8'b00xxxxxx:ALUcontoloOut <=4'b0010 ; //sw,lw

8'b01xxxxxx:ALUcontoloOut <=4'b0110 ; //beq

endcase

endmodule 