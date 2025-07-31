----------------------------------------------------------------------------------
-- Company: 
-- Engineer: Fabian Castano
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
library UNISIM;
use UNISIM.VComponents.all;

entity fclk_lvds_receiver is
  Port ( fclk_in_p : in  STD_LOGIC;
         fclk_in_n : in  STD_LOGIC;
         led       : out STD_LOGIC
        );
end fclk_lvds_receiver;

architecture Behavioral of fclk_lvds_receiver is

    signal clk_lvds : STD_LOGIC;
    signal counter  : Unsigned(23 downto 0) := (others => '0');
    signal led_reg  : STD_LOGIC := '0';

begin

   -- IBUFDS: Differential Input Buffer
   --         Artix-7
   -- Xilinx HDL Language Template, version 2022.2

   IBUFDS_inst : IBUFDS
   generic map (
      DIFF_TERM => TRUE, -- Differential Termination 
      IBUF_LOW_PWR => TRUE, -- Low power (TRUE) vs. performance (FALSE) setting for referenced I/O standards
      IOSTANDARD => "LVDS")
   port map (
      I => fclk_in_p,  -- Diff_p buffer input (connect directly to top-level port)
      IB => fclk_in_n, -- Diff_n buffer input (connect directly to top-level port)
      O => clk_lvds    -- Buffer output
   );

    -- Clock Divider Process
    Process(clk_lvds)
    begin
        if rising_edge(clk_lvds) then
            counter <= counter + 1;
            if counter = X"FFFFFF" then
                led_reg <= not led_reg;  -- Toggle LED every 2^24 clock cycles
                counter <= (others => '0'); -- Reset counter
            end if;
        end if;
    end Process;

    -- Output LED
    led <= led_reg;

end Behavioral;
