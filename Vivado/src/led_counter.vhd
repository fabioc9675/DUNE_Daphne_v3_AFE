----------------------------------------------------------------------------------
-- Company: 
-- Engineer: Fabian Castano
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity led_counter is
    Port ( rst     : in  STD_LOGIC;
           clk     : in  STD_LOGIC;
           led     : out STD_LOGIC
         );
end led_counter;

architecture Behavioral of led_counter is

    signal count   : Unsigned(23 downto 0) := (others => '0');
    signal led_reg : STD_LOGIC := '0';

begin

    process(clk, rst)
    begin
        if rst = '1' then
            count <= (others => '0');
            led_reg <= '0';
        elsif rising_edge(clk) then
            count <= count + 1;
            if count = X"FFFFFF" then
                led_reg <= not led_reg;  -- Toggle LED every 2^24 clock cycles
                count <= (others => '0');  -- Reset count
            end if;
        end if;
    end process;

    -- Output LED
    led <= led_reg;


end Behavioral;
