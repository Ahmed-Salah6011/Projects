module signExtender(inst,out);
input [15:0] inst;
output reg [31:0]out;
always@(inst)
begin
casez(inst)
16'b1zzzzzzzzzzzzzzz:out<={16'hffff,inst} ;
16'b0zzzzzzzzzzzzzzz:out<={16'h0000,inst} ;

endcase
end
endmodule