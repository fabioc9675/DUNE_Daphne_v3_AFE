library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity stimulus_gen is
    port (
        dclk       : in  std_logic;
        fclk       : in  std_logic;
        rst        : in  std_logic;
        data_out_p : out std_logic;
        data_out_n : out std_logic
    );
end stimulus_gen;

architecture Behavioral of stimulus_gen is
    type bit_array is array (0 to 13) of std_logic;
    signal shift_reg : bit_array := (others => '0');
    signal bit_idx   : integer range 0 to 13 := 0;
    signal toggle    : std_logic := '0';

begin
    -- Example shift pattern: 14 bits (e.g., 11001010011100)
    process(rst, fclk)
    begin
        if rst = '1' then
            shift_reg <= "11001010011100";
        elsif rising_edge(fclk) then
            -- Load next 14-bit pattern every new FCLK
            if toggle = '0' then
                shift_reg <= "01110101011001";  -- Change pattern per FCLK if desired
                toggle <= '1';
            else
                shift_reg <= "11001010011100";
                toggle <= '0';
            end if;
        end if;
    end process;

    -- DDR simulation: changes data on both edges of DCLK
    process(rst, dclk)
    begin
        if rst = '1' then
            bit_idx <= 0;
            data_out_p <= '0';
            data_out_n <= '1';
        elsif rising_edge(dclk) then
            data_out_p <= shift_reg(bit_idx);
            data_out_n <= not shift_reg(bit_idx);
            bit_idx <= (bit_idx + 1) mod 14;         
        end if;
    end process;
end Behavioral;
