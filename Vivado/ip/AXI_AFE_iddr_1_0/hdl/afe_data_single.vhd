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
library UNISIM;
use UNISIM.VComponents.all;

entity afe_data_single is
    Port ( data_in_p    : in  STD_LOGIC;
           data_in_n    : in  STD_LOGIC;
           data_out     : out STD_LOGIC
         );
end afe_data_single;

architecture Behavioral of afe_data_single is

    signal data_lvds    : STD_LOGIC;

begin


    -- IBUFDS: Differential Input Buffer
    --         Artix-7
    -- Xilinx HDL Language Template, version 2022.2

    IBUFDS_data : IBUFDS
    generic map (
        DIFF_TERM => TRUE, -- Differential Termination 
        IBUF_LOW_PWR => TRUE, -- Low power (TRUE) vs. performance (FALSE) setting for referenced I/O standards
        IOSTANDARD => "LVDS")
    port map (
        I  => data_in_p,  -- Diff_p buffer input (connect directly to top-level port)
        IB => data_in_n, -- Diff_n buffer input (connect directly to top-level port)
        O  => data_lvds    -- Buffer output
    );

    -- End of IBUFDS_inst instantiation
    
    -- Output assignments
    
    -- buffer the DATA output
    data_bufg : BUFG
        port map (
            I => data_lvds,
            O => data_out
        );

end Behavioral;
