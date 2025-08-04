----------------------------------------------------------------------------------
-- Company: 
-- Engineer: Fabian Castano
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity afe_slice_data is
    Port ( 
        data_in   : in  std_logic_vector(31 downto 0);
        rst       : in  std_logic;
        fclk      : in  std_logic;
        dclk      : in  std_logic;
        -- signal to select which slice of data to output
        delay     : in  std_logic_vector(3 downto 0);
        -- signal to select which slice of data to output
        sel       : in  std_logic_vector(3 downto 0);
        data_out  : out std_logic_vector(15 downto 0)
    );
end afe_slice_data;

architecture Behavioral of afe_slice_data is

    signal data_buffer : std_logic_vector(13 downto 0) := (others => '0');
    signal data_int    : std_logic_vector(15 downto 0) := (others => '0');
    signal delay_count : integer range 0 to 15 := 0;
    signal ack         : std_logic := '0';

begin

    data_pass: process(dclk, rst)
    begin
        if rst = '1' then
            data_int <= (others => '0');
        elsif rising_edge(dclk) then
            if fclk = '1' and ack = '0' then
                if delay_count = to_integer(unsigned(delay)) then
                    data_int <= "00" & data_buffer;
                    delay_count <= 0;
                    ack <= '1';  -- Indica que se ha completado el paso de datos
                else
                    delay_count <= delay_count + 1;
                end if;
            elsif fclk = '0' then
                ack <= '0';  -- Resetea el ack si no es flanco de fclk
                delay_count <= 0;
            end if;
        end if;
    end process data_pass;


    data_mux: process(sel)
    begin
        case sel is
            when X"0" => data_buffer <= data_in(13 downto 0);
            when X"1" => data_buffer <= data_in(14 downto 1);
            when X"2" => data_buffer <= data_in(15 downto 2);
            when X"3" => data_buffer <= data_in(16 downto 3);
            when X"4" => data_buffer <= data_in(17 downto 4);
            when X"5" => data_buffer <= data_in(18 downto 5);
            when X"6" => data_buffer <= data_in(19 downto 6);
            when X"7" => data_buffer <= data_in(20 downto 7);
            when X"8" => data_buffer <= data_in(21 downto 8);
            when X"9" => data_buffer <= data_in(22 downto 9);
            when X"A" => data_buffer <= data_in(23 downto 10);
            when X"B" => data_buffer <= data_in(24 downto 11);
            when X"C" => data_buffer <= data_in(25 downto 12);
            when X"D" => data_buffer <= data_in(26 downto 13);
            when X"E" => data_buffer <= data_in(27 downto 14);
            when X"F" => data_buffer <= data_in(28 downto 15);
            when others  => data_buffer <= data_in(29 downto 16);
        end case;
    end process data_mux;

    data_out <= data_int;



end Behavioral;




