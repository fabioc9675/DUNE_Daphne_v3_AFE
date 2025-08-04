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

entity afe_fclk_single is
    Port ( fclk_in_p    : in  STD_LOGIC;
           fclk_in_n    : in  STD_LOGIC;
           fclk_out     : out STD_LOGIC
         );
end afe_fclk_single;

architecture Behavioral of afe_fclk_single is

    signal fclk_lvds    : STD_LOGIC;

begin

    -- IBUFDS: Differential Input Buffer
    --         Artix-7
    -- Xilinx HDL Language Template, version 2022.2

    IBUFDS_fclk : IBUFDS
    generic map (
        DIFF_TERM => TRUE, -- Differential Termination 
        IBUF_LOW_PWR => TRUE, -- Low power (TRUE) vs. performance (FALSE) setting for referenced I/O standards
        IOSTANDARD => "LVDS")
    port map (
        I  => fclk_in_p,  -- Diff_p buffer input (connect directly to top-level port)
        IB => fclk_in_n, -- Diff_n buffer input (connect directly to top-level port)
        O  => fclk_lvds    -- Buffer output
    );

    -- End of IBUFDS_inst instantiation
    
    -- Output assignments
    
    -- buffer the FCLK output
    fclk_bufg : BUFG
        port map (
            I => fclk_lvds,
            O => fclk_out
        );

end Behavioral;
