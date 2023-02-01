	component de2_115_camera is
		port (
			clk_clk                                 : in    std_logic                     := 'X';             -- clk
			pixel_external_connection_export        : in    std_logic_vector(7 downto 0)  := (others => 'X'); -- export
			read_address_external_connection_export : out   std_logic_vector(11 downto 0);                    -- export
			reset_reset_n                           : in    std_logic                     := 'X';             -- reset_n
			switch_external_connection_export       : in    std_logic_vector(17 downto 0) := (others => 'X'); -- export
			character_lcd_0_external_interface_DATA : inout std_logic_vector(7 downto 0)  := (others => 'X'); -- DATA
			character_lcd_0_external_interface_ON   : out   std_logic;                                        -- ON
			character_lcd_0_external_interface_BLON : out   std_logic;                                        -- BLON
			character_lcd_0_external_interface_EN   : out   std_logic;                                        -- EN
			character_lcd_0_external_interface_RS   : out   std_logic;                                        -- RS
			character_lcd_0_external_interface_RW   : out   std_logic                                         -- RW
		);
	end component de2_115_camera;

	u0 : component de2_115_camera
		port map (
			clk_clk                                 => CONNECTED_TO_clk_clk,                                 --                                clk.clk
			pixel_external_connection_export        => CONNECTED_TO_pixel_external_connection_export,        --          pixel_external_connection.export
			read_address_external_connection_export => CONNECTED_TO_read_address_external_connection_export, --   read_address_external_connection.export
			reset_reset_n                           => CONNECTED_TO_reset_reset_n,                           --                              reset.reset_n
			switch_external_connection_export       => CONNECTED_TO_switch_external_connection_export,       --         switch_external_connection.export
			character_lcd_0_external_interface_DATA => CONNECTED_TO_character_lcd_0_external_interface_DATA, -- character_lcd_0_external_interface.DATA
			character_lcd_0_external_interface_ON   => CONNECTED_TO_character_lcd_0_external_interface_ON,   --                                   .ON
			character_lcd_0_external_interface_BLON => CONNECTED_TO_character_lcd_0_external_interface_BLON, --                                   .BLON
			character_lcd_0_external_interface_EN   => CONNECTED_TO_character_lcd_0_external_interface_EN,   --                                   .EN
			character_lcd_0_external_interface_RS   => CONNECTED_TO_character_lcd_0_external_interface_RS,   --                                   .RS
			character_lcd_0_external_interface_RW   => CONNECTED_TO_character_lcd_0_external_interface_RW    --                                   .RW
		);

