----------------------------------------------------------------------------------
-- Company: 
-- Engineer: Fabian Castano
-- 
-- Create Date: 01.02.2025 13:52:24
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

library UNISIM;
use UNISIM.VComponents.ALL;


entity ADC_AFE_interface is
    -- generic (dclk_period      : integer  := 8); -- Input clock period (DCLK) in ns to ps resolution (i.e. 33.333 is 30 MHz). 7.14 ns 
    Port (
            fclk_p      : in  std_logic;
--            fclk_n      : in  std_logic;
            rst         : in  std_logic;
            data_p      : in  std_logic;
--            data_n      : in  std_logic;
            fclk_out    : out std_logic;
            dataOut     : out std_logic_vector(15 downto 0)
          );
end ADC_AFE_interface;

architecture Behavioral of ADC_AFE_interface is

    component adc_lowFreq is
        -- generic (dclk_period      : integer  := 8);   -- Input clock period in ns to ps resolution (i.e. 33.333 is 30 MHz).
        Port (
                fclk       : in  std_logic;
                rst        : in  std_logic;
                data       : in  std_logic;
                dataOut    : out std_logic_vector(15 downto 0)    
              );
    end component;
    
    signal fclk_int    : std_logic;
    signal data_int    : std_logic;
    
    -- %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    -- Senales agregadas por incompactibilidad en los pines de conexion, buscar pines LVDS del PL
    -- %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    signal fake_fclk_n : std_logic;
--    signal fake_data_n : std_logic;
    signal data_p_buf  : std_logic; -- Salida del IBUF
    signal fclk_p_buf  : std_logic; -- Salida del IBUF
--    signal data_n_buf  : std_logic; -- Salida del IBUF
--    signal fclk_n_buf  : std_logic; -- Salida del IBUF
    -- %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
begin
    
    -- %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    -- Senales agregadas por incompactibilidad en los pines de conexion, buscar pines LVDS del PL
    -- %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
--    fake_fclk_n <= not fclk_p;
--    fake_data_n <= not data_p;
    -- %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    adc_lowf: adc_lowFreq
        -- generic map (dclk_period => dclk_period)
        Port map (
                    fclk      => fclk_int,
                    rst       => rst,
                    data      => data_int,
                    dataOut   => dataOut
                  );


    -- IBUF: Buffer single-ended para limpiar la señal
    IBUF_fclk_p : IBUF
    port map (
        O => fclk_int, --fclk_p_buf,  -- Salida del buffer
        I => fclk_p       -- Entrada desde el pin de la FPGA
    );
    
--    -- IBUF: Buffer single-ended para limpiar la señal
--    IBUF_fclk_n : IBUF
--    port map (
--        O => fclk_n_buf,  -- Salida del buffer
--        I => fclk_n       -- Entrada desde el pin de la FPGA
--    );

    -- IBUFDS: Differential Input Buffer
    --         Artix-7
    -- Xilinx HDL Language Template, version 2022.2

--    IBUFDS_fclk : IBUFDS
--    generic map (
--        DIFF_TERM => FALSE, -- Differential Termination 
--        IBUF_LOW_PWR => TRUE, -- Low power (TRUE) vs. performance (FALSE) setting for referenced I/O standards
--        IOSTANDARD => "DEFAULT")
--    port map (
--        O  => fclk_int,  -- Buffer output
--        I  => fclk_p_buf,  -- Diff_p buffer input (connect directly to top-level port)
--        IB => '0' --fclk_n -- Diff_n buffer input (connect directly to top-level port)
--    );
    
    -- IBUF: Buffer single-ended para limpiar la señal
    IBUF_data_p : IBUF
    port map (
        O => data_int, --data_p_buf,  -- Salida del buffer
        I => data_p       -- Entrada desde el pin de la FPGA
    );
    
--    -- IBUF: Buffer single-ended para limpiar la señal
--    IBUF_data_n : IBUF
--    port map (
--        O => data_n_buf,  -- Salida del buffer
--        I => data_n       -- Entrada desde el pin de la FPGA
--    );
    
--    IBUFDS_data : IBUFDS
--    generic map (
--        DIFF_TERM => FALSE, -- Differential Termination 
--        IBUF_LOW_PWR => TRUE, -- Low power (TRUE) vs. performance (FALSE) setting for referenced I/O standards
--        IOSTANDARD => "DEFAULT")
--    port map (
--        O  => data_int,  -- Buffer output
--        I  => data_p_buf,  -- Diff_p buffer input (connect directly to top-level port)
--        IB => '0' --data_n -- Diff_n buffer input (connect directly to top-level port)
--    );
   
    -- End of IBUFDS_inst instantiation
    
    fclk_out <= fclk_int;
    
end Behavioral;









  