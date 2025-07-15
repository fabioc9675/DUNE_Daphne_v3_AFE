----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 01.02.2025 23:00:41
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


entity serdes_tb is
--  Port ( );
end serdes_tb;

architecture Behavioral of serdes_tb is

    component ADC_AFE_Diff_interface is
    -- generic (dclk_period      : integer  := 10); -- Input clock period (DCLK) in ns to ps resolution (i.e. 33.333 is 30 MHz). 7.14 ns 
    Port (
            fclk_p      : in  std_logic;
            fclk_n      : in  std_logic;
            rst         : in  std_logic;
            data_p      : in  std_logic;
            data_n      : in  std_logic;
            fclk_out    : out std_logic;
            dataOut     : out std_logic_vector(15 downto 0)
          );
    end component;

    signal FCLK_P         : std_logic := '1';
    signal FCLK_N         : std_logic := '0';
    signal RST            : std_logic;
    signal DATA_P         : std_logic;
    signal DATA_N         : std_logic;
    signal FCLK_O         : std_logic;
    signal Data_out       : std_logic_vector(15 downto 0);

begin

    ADC: ADC_AFE_Diff_interface 
          -- generic map (dclk_period => 10) -- Input clock period in ns to ps resolution (i.e. 33.333 is 30 MHz).
          Port map (
                    fclk_p     => FCLK_P,
                    fclk_n     => FCLK_N,
                    rst        => RST,
                    data_p     => DATA_P,
                    data_n     => DATA_N,
                    dataOut    => Data_out,
                    fclk_out   => FCLK_O
                 );

    FCLK_P <= not FCLK_P after 35 ns;
    FCLK_N <= not FCLK_P;
        
    DATA_N <= not DATA_P;
    
    
    process
        begin

            RST <= '1';
            data_p <= '0';
            
            wait for 210 ns;
            
            RST <= '0';
            wait for 3500 ns;
            
            data_p <= '1';
            wait for 5 ns;
            data_p <= '1';
            wait for 5 ns;
            data_p <= '1';
            wait for 5 ns;
            data_p <= '1';
            wait for 5 ns;
            data_p <= '1';
            wait for 5 ns;
            data_p <= '1';
            wait for 5 ns;
            data_p <= '1';
            wait for 5 ns;
            data_p <= '1';
            wait for 5 ns;
            data_p <= '1';
            wait for 5 ns;
            data_p <= '1';
            wait for 5 ns;
            data_p <= '1';
            wait for 5 ns;
            data_p <= '1';
            wait for 5 ns;
            data_p <= '1';
            wait for 5 ns;
            data_p <= '1';
            wait for 5 ns;
            
            data_p <= '0';
            wait for 5 ns;
            data_p <= '0';
            wait for 5 ns;
            data_p <= '0';
            wait for 5 ns;
            data_p <= '0';
            wait for 5 ns;
            data_p <= '0';
            wait for 5 ns;
            data_p <= '0';
            wait for 5 ns;
            data_p <= '0';
            wait for 5 ns;
            data_p <= '0';
            wait for 5 ns;
            data_p <= '0';
            wait for 5 ns;
            data_p <= '0';
            wait for 5 ns;
            data_p <= '0';
            wait for 5 ns;
            data_p <= '0';
            wait for 5 ns;
            data_p <= '0';
            wait for 5 ns;
            data_p <= '0';
            wait for 5 ns;
            
            data_p <= '1';
            wait for 5 ns;
            data_p <= '0';
            wait for 5 ns;
            data_p <= '1';
            wait for 5 ns;
            data_p <= '0';
            wait for 5 ns;
            data_p <= '1';
            wait for 5 ns;
            data_p <= '0';
            wait for 5 ns;
            data_p <= '1';
            wait for 5 ns;
            data_p <= '0';
            wait for 5 ns;
            data_p <= '1';
            wait for 5 ns;
            data_p <= '0';
            wait for 5 ns;
            data_p <= '1';
            wait for 5 ns;
            data_p <= '0';
            wait for 5 ns;
            data_p <= '1';
            wait for 5 ns;
            data_p <= '0';
            wait for 5 ns;
            
            data_p <= '0';
            wait for 5 ns;
            data_p <= '0';
            wait for 5 ns;
            data_p <= '0';
            wait for 5 ns;
            data_p <= '0';
            wait for 5 ns;
            data_p <= '0';
            wait for 5 ns;
            data_p <= '0';
            wait for 5 ns;
            data_p <= '0';
            wait for 5 ns;
            data_p <= '1';
            wait for 5 ns;
            data_p <= '1';
            wait for 5 ns;
            data_p <= '1';
            wait for 5 ns;
            data_p <= '1';
            wait for 5 ns;
            data_p <= '1';
            wait for 5 ns;
            data_p <= '1';
            wait for 5 ns;
            data_p <= '1';
            wait for 5 ns;
            
            
            data_p <= '0';
            wait for 700 ns;
            
    end process;

end Behavioral;





























