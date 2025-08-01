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

entity afe_dclk_source is
    Port ( rst      : in  std_logic;
           fclk_in  : in  std_logic;  -- Input clock
           dclk_out : out std_logic     -- Output clock
         );
end afe_dclk_source;

architecture Behavioral of afe_dclk_source is

    signal dclk_mmcm   : std_logic;
    signal fclk_buf    : std_logic;
    signal clkfb_mmcm  : std_logic;
    signal clkfb_bufg  : std_logic;

begin

    -- Buffer FCLK input
    fclk_bufg : BUFG
        port map (
            I => fclk_in,
            O => fclk_buf
        );

    -- Buffer feedback path
    clkfb_bufg_inst : BUFG
        port map (
            I => clkfb_mmcm,
            O => clkfb_bufg
        );


    -- MMCME2_BASE: Base Mixed Mode Clock Manager
    -- Artix-7
    -- Xilinx HDL Language Template, version 2022.2

    MMCME2_BASE_inst : MMCME2_BASE
    generic map (
        BANDWIDTH => "OPTIMIZED",  -- Jitter programming (OPTIMIZED, HIGH, LOW)
        CLKFBOUT_MULT_F => 21.0, --7.0,    -- Multiply value for all CLKOUT (2.000-64.000).
        CLKFBOUT_PHASE => 0.0,     -- Phase offset in degrees of CLKFB (-360.000-360.000).
        CLKIN1_PERIOD => 25.0,    -- for 5 MHz FCLK; real(dclk_period),      -- Input clock period in ns to ps resolution (i.e. 25.0 is 40 MHz).
        -- CLKOUT0_DIVIDE - CLKOUT6_DIVIDE: Divide amount for each CLKOUT (1-128)
        CLKOUT0_DIVIDE_F => 3.0,   -- Divide amount for CLKOUT0 (1.000-128.000).
        CLKOUT1_DIVIDE => 1,
        -- CLKOUT2_DIVIDE => 1,
        -- CLKOUT3_DIVIDE => 1,
        -- CLKOUT4_DIVIDE => 1,
        -- CLKOUT5_DIVIDE => 1,
        -- CLKOUT6_DIVIDE => 1,
        -- CLKOUT0_DUTY_CYCLE - CLKOUT6_DUTY_CYCLE: Duty cycle for each CLKOUT (0.01-0.99).
        CLKOUT0_DUTY_CYCLE => 0.5,
        -- CLKOUT1_DUTY_CYCLE => 0.5,
        -- CLKOUT2_DUTY_CYCLE => 0.5,
        -- CLKOUT3_DUTY_CYCLE => 0.5,
        -- CLKOUT4_DUTY_CYCLE => 0.5,
        -- CLKOUT5_DUTY_CYCLE => 0.5,
        -- CLKOUT6_DUTY_CYCLE => 0.5,
        -- CLKOUT0_PHASE - CLKOUT6_PHASE: Phase offset for each CLKOUT (-360.000-360.000).
        CLKOUT0_PHASE => 90.0,
        -- CLKOUT1_PHASE => 0.0,
        -- CLKOUT2_PHASE => 0.0,
        -- CLKOUT3_PHASE => 0.0,
        -- CLKOUT4_PHASE => 0.0,
        -- CLKOUT5_PHASE => 0.0,
        -- CLKOUT6_PHASE => 0.0,
        CLKOUT4_CASCADE => FALSE,  -- Cascade CLKOUT4 counter with CLKOUT6 (FALSE, TRUE)
        DIVCLK_DIVIDE => 1,        -- Master division value (1-106)
        REF_JITTER1 => 0.0,        -- Reference input jitter in UI (0.000-0.999).
        STARTUP_WAIT => FALSE      -- Delays DONE until MMCM is locked (FALSE, TRUE)
    )
    port map (
        -- Clock Outputs: 1-bit (each) output: User configurable clock outputs
        CLKOUT0  => dclk_mmcm,     -- 1-bit output: CLKOUT0
        CLKOUT0B => open,     -- 1-bit output: Inverted CLKOUT0
        CLKOUT1  => open,       -- 1-bit output: CLKOUT1
        CLKOUT1B => open,       -- 1-bit output: Inverted CLKOUT1
        CLKOUT2  => open,       -- 1-bit output: CLKOUT2
        CLKOUT2B => open,       -- 1-bit output: Inverted CLKOUT2
        CLKOUT3  => open,       -- 1-bit output: CLKOUT3
        CLKOUT3B => open,       -- 1-bit output: Inverted CLKOUT3
        CLKOUT4  => open,       -- 1-bit output: CLKOUT4
        CLKOUT5  => open,       -- 1-bit output: CLKOUT5
        CLKOUT6  => open,       -- 1-bit output: CLKOUT6
        -- Feedback Clocks: 1-bit (each) output: Clock feedback ports
        CLKFBOUT => clkfb_mmcm,   -- 1-bit output: Feedback clock
        CLKFBOUTB => open, -- 1-bit output: Inverted CLKFBOUT
        -- Status Ports: 1-bit (each) output: MMCM status ports
        LOCKED => open,       -- 1-bit output: LOCK
        -- Clock Inputs: 1-bit (each) input: Clock input
        CLKIN1 => fclk_buf,       -- 1-bit input: Clock
        -- Control Ports: 1-bit (each) input: MMCM control ports
        PWRDWN => '0',       -- 1-bit input: Power-down
        RST => rst,             -- 1-bit input: Reset
        -- Feedback Clocks: 1-bit (each) input: Clock feedback ports
        CLKFBIN => clkfb_bufg   -- 1-bit input: Feedback clock
    );
    -- End of MMCME2_BASE_inst instantiation

    -- buffer the DCLK output
    dclk_bufg : BUFG
        port map (
            I => dclk_mmcm,
            O => dclk_out
        );


end Behavioral;
