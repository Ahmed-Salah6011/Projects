`timescale 10ns/10ns
////ins memory
module InstructionMemory(NIN,Address); //N-IN==NEXT INSTRUCTION  ,Address==pc 
output reg [31:0] NIN;
input  [31:0] Address;
reg[31:0] M [0:8191];


initial 
begin
$readmemb("E:/InsMemoryFile.txt",M);
end


always@(Address) //concept of counter as pc increment,choose new address <<instruction >>
begin 
NIN=M[Address>>2]; 
end

/////////

/////////////////
endmodule 