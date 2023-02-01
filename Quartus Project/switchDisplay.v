module switchDisplay(
					sw, 
					rVGA, 
					gVGA, 
					bVGA, 
					grey, 
					sobel, 
					rOUT, 
					gOUT, 
					bOUT);

input		[1:0]	sw;
input		[7:0]	rVGA, gVGA , bVGA, grey, sobel;		
output 		[7:0]	rOUT, gOUT, bOUT;

assign rOUT = (sw == 2'b00 ? rVGA : (
					sw == 2'b01 ? grey : (
					sw == 2'b10 ? sobel : 10'd0)));
					
assign gOUT = (sw == 2'b00 ? gVGA : (
					sw == 2'b01 ? grey : (
					sw == 2'b10 ? sobel : 10'd0)));

assign bOUT = (sw == 2'b00 ? bVGA : (
					sw == 2'b01 ? grey : (
					sw == 2'b10 ? sobel : 10'd0)));

endmodule