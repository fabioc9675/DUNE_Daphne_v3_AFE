----------------------------------------------------------------------------------
-- Company: 
-- Engineer: Fabian Castano
-- 
-- Create Date: 01.02.2025 12:48:07
----------------------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


entity dataOutParallel is
    Port (
           fclk         : in  std_logic;
           rst          : in  std_logic; 
           Q            : in  std_logic_vector(6 downto 0);
           T            : in  std_logic_vector(6 downto 0);
           dataOut      : out std_logic_vector(15 downto 0)  -- verify if 13 downto 0
             );
end dataOutParallel;

architecture Behavioral of dataOutParallel is

begin

    deserialize: process(fclk, rst)
        begin
            if rst = '1' then
                dataOut <= "0000000000000000";
            elsif rising_edge(fclk) then
                dataOut <= "00" & T(6) & Q(6) & T(5) & Q(5) & T(4) & Q(4) & T(3) & Q(3) & T(2) & Q(2) & T(1) & Q(1) & T(0) & Q(0);
            end if;
        end process deserialize;

end Behavioral;
