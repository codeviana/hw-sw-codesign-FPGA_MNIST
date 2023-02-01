library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;


entity greyscale is
	port(
		clk: in std_logic;
		r: in std_logic_vector(7 downto 0);
		g: in std_logic_vector(7 downto 0);
		b: in std_logic_vector(7 downto 0);
		grey: out std_logic_vector(7 downto 0)
	);
end greyscale;




architecture behavior of greyscale is
begin
	process(r,g,b)
	begin
			if ((to_integer(unsigned(r))+to_integer(unsigned(g))+to_integer(unsigned(b)))/3) < 100 then
				grey <= "00000000";
			else
				grey <= "11111111";
			end if;
	end process;
end behavior;
