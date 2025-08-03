----------------------------------------------------------------------------------
-- Company: Universidad de Antioquia
-- Engineer: Fabian Castano
----------------------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
library std;
use std.textio.all;

entity top_tb is
--  Port ( );
end top_tb;

architecture Behavioral of top_tb is
    
    signal clk_gen      : std_logic;
    
    signal clk_p        : std_logic;
    signal clk_n        : std_logic;
    
    signal data_p       : std_logic;
    signal data_n       : std_logic;
    
    signal fclk_s       : std_logic;
    signal dclk_s       : std_logic;
    signal data_s       : std_logic;
    
    signal Q_o          : std_logic_vector ( 7 downto 0 );
    signal T_o          : std_logic_vector ( 7 downto 0 );
    
    signal salida       : std_logic_vector (15 downto 0);
    
    signal d_valid      : std_logic;
    
    signal stop         : boolean       := FALSE;
    
    
begin

    do_clock : entity work.clock
    port map(
        clk_p  => clk_p,
        clk_n  => clk_n,        
        dclk_o => clk_gen,        
        stop_i => stop
    ); 
    
    stimulus_gen : entity work.stimulus_gen
    port map(
        dclk       => clk_gen,
        fclk       => fclk_s,
        rst        => '0',
        data_out_p => data_p,
        data_out_n => data_n
    );
    
    
    dut : entity work.kria_sim_bd_wrapper
    port map (
        fclk_in_p  => clk_p,
        fclk_in_n  => clk_n,
        data_in_p  => data_p,
        data_in_n  => data_n,   
        data_out_0 => data_s, 
        dclk_out_0 => dclk_s,
        fclk_out_0 => fclk_s,
        Q_0        => Q_o,
        T_0        => T_o,        
        sample_0   => salida,
        valid_0    => d_valid
    );


end Behavioral;





