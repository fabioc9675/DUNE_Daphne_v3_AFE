----------------------------------------------------------------------------------
-- Company: Universidad de Antioquia
-- Engineer: Fabian Castano
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity clock is
    generic(
        FREQUENCY        : positive    := 560000000;
        PERIOD           : time        := 0 sec;
        RESET_CLKS       : real        := 1.5;
        LATENCY          : positive    := 13       
    );
    port(
        clk_p            : out std_logic;    
        clk_n            : out std_logic;  
        dclk_o           : out std_logic;   
        stop_i           : in  boolean := FALSE    
    );
end clock;

architecture Simulator of clock is

    function get_clock_time(per: time; freq: positive) return time is
    begin
        if per > 0 sec then
            return per;
        end if;
        return 1 sec/(real(FREQUENCY));
    end function get_clock_time;
    
    signal counter      : integer     := 0;
    signal clk          : std_logic   := '1';
    signal dclk         : std_logic   := '1';
    
    constant CLOCK_TIME : time := get_clock_time(PERIOD, FREQUENCY);
    constant RESET_TIME : time := CLOCK_TIME*RESET_CLKS;

begin

    do_clock: process
    begin
        while not stop_i loop
            wait for CLOCK_TIME/2;
            dclk <= not dclk;
            counter <= counter + 1;
            if counter = LATENCY then
                counter <= 0;
                clk <= not clk;
            end if;
        end loop;
        wait;    
    end process;
    
    clk_p <= clk;
    clk_n <= not clk;
    dclk_o <= dclk;
    
end architecture Simulator;
