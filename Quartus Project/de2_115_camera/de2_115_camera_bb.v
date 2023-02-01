
module de2_115_camera (
	clk_clk,
	pixel_external_connection_export,
	read_address_external_connection_export,
	reset_reset_n,
	switch_external_connection_export,
	character_lcd_0_external_interface_DATA,
	character_lcd_0_external_interface_ON,
	character_lcd_0_external_interface_BLON,
	character_lcd_0_external_interface_EN,
	character_lcd_0_external_interface_RS,
	character_lcd_0_external_interface_RW);	

	input		clk_clk;
	input	[7:0]	pixel_external_connection_export;
	output	[11:0]	read_address_external_connection_export;
	input		reset_reset_n;
	input	[17:0]	switch_external_connection_export;
	inout	[7:0]	character_lcd_0_external_interface_DATA;
	output		character_lcd_0_external_interface_ON;
	output		character_lcd_0_external_interface_BLON;
	output		character_lcd_0_external_interface_EN;
	output		character_lcd_0_external_interface_RS;
	output		character_lcd_0_external_interface_RW;
endmodule
