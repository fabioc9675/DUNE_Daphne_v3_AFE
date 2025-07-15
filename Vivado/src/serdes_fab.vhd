----------------------------------------------------------------------------------
-- Company: 
-- Engineer: Fabian Castano
-- 
-- Create Date: 01.02.2025 12:48:07
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


entity serdes_fab is
    Port (
            clk      : in  std_logic;
            fclk     : in  std_logic;
            rst      : in  std_logic;
            data     : in  std_logic;
            Q        : out std_logic_vector(6 downto 0)
             );
end serdes_fab;

architecture Behavioral of serdes_fab is

signal ack      : std_logic;
signal counter  : integer := 0;

begin
    
    serdes: process (clk, rst)
        begin
            if rst = '1' then
                Q <= "0000000";
                counter <= 0;
                ack <= '0';
            elsif rising_edge(clk) then
                if fclk = '1' and ack = '0' then
                    Q(0) <= data;
                    ack <= '1';
                    counter <= 1;
                elsif fclk = '1' and ack = '1' then
                    Q(counter) <= data;
                    counter <= counter + 1;
                elsif fclk = '0' then
                    ack <= '0';
                    Q(counter) <= data;
                    if counter >= 6 then
                        counter <= 0;
                    else
                        counter <= counter + 1;
                    end if;
                end if;     
            end if;
        end process serdes;

end Behavioral;
