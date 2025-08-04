----------------------------------------------------------------------------------
-- Company: 
-- Engineer: Fabian Castaño
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

entity afe_deserializer is
    Port ( 
        rst       : in  std_logic;
        fclk      : in  std_logic;
        dclk      : in  std_logic;     
        data_in   : in  std_logic;  -- Serial DDR data from AFE
        sample    : out std_logic_vector(15 downto 0);  -- 14-bit parallel output
        valid     : out std_logic; 
        Q         : out std_logic_vector(15 downto 0);
        T         : out std_logic_vector(15 downto 0)
    );
end afe_deserializer;

architecture Behavioral of afe_deserializer is

    type buffer_vector is array (integer range <>) of std_logic;

    signal Q1, Q2    : std_logic := '0';
    
    signal Q_int     : buffer_vector(0 to 15);  -- buffer memory initialization
    signal T_int     : buffer_vector(0 to 15);  -- buffer memory initialization
    signal data_reg  : std_logic_vector(13 downto 0) := (others => '0');
    signal bit_count : integer range 0 to 13 := 0;
    signal valid_reg : std_logic := '0';
    signal ack       : std_logic := '0';
    
    signal dclk_p : std_logic;
    signal dclk_n : std_logic;

        -- signal Q_int     : std_logic_vector(15 downto 0);
    -- signal T_int     : std_logic_vector(15 downto 0);

begin

    -- Generaci�n l�gica de reloj diferencial interno
    dclk_p <= dclk;
    dclk_n <= not dclk;

    -- IDDRE1: Dedicated Double Data Rate (DDR) Input Register
   --         Kintex UltraScale
   -- Xilinx HDL Language Template, version 2022.2

   IDDRE1_inst : IDDRE1
   generic map (
      DDR_CLK_EDGE => "SAME_EDGE_PIPELINED", -- IDDRE1 mode (OPPOSITE_EDGE, SAME_EDGE, SAME_EDGE_PIPELINED)
      IS_CB_INVERTED => '0',           -- Optional inversion for CB
      IS_C_INVERTED => '0'             -- Optional inversion for C
   )
   port map (
      Q1 => Q1, -- 1-bit output: Registered parallel output 1
      Q2 => Q2, -- 1-bit output: Registered parallel output 2
      C => dclk_p,   -- 1-bit input: High-speed clock
      CB => dclk_n, -- 1-bit input: Inversion of High-speed clock C
      D => data_in,   -- 1-bit input: Serial Data Input
      R => '0'    -- 1-bit input: Active-High Async Reset
   );

   -- End of IDDRE1_inst instantiation

    -- Circular buffer for 14-bit data
    serdes_fab: process (dclk, rst)
    begin
        if (rst = '1') then
            for i in Q_int'high downto 0 loop
                Q_int(i) <= '0';
            end loop;
            for i in T_int'high downto 0 loop
                T_int(i) <= '0';
            end loop;
--            bit_count <= 0;
            ack <= '0';
        elsif falling_edge(dclk) then
            Q_int(0) <= Q1;
            T_int(0) <= Q2;
            for i in Q_int'high-1 downto 0 loop
                Q_int(i+1) <= Q_int(i);
            end loop;
            for i in T_int'high-1 downto 0 loop
                T_int(i+1) <= T_int(i);
            end loop;
        end if;
    
    end process serdes_fab;
    
    -- Deserializa los datos en paralelo
    Q <= Q_int(15) & Q_int(14) & Q_int(13) & Q_int(12) & Q_int(11) & Q_int(10) & Q_int(9) & Q_int(8) & 
         Q_int(7) & Q_int(6) & Q_int(5) & Q_int(4) & Q_int(3) & Q_int(2) & Q_int(1) & Q_int(0);
    T <= T_int(15) & T_int(14) & T_int(13) & T_int(12) & T_int(11) & T_int(10) & T_int(9) & T_int(8) & 
         T_int(7) & T_int(6) & T_int(5) & T_int(4) & T_int(3) & T_int(2) & T_int(1) & T_int(0);
         
    sample <= "00"  & Q_int(7) & T_int(7) & Q_int(6) & T_int(6) & Q_int(5) & T_int(5) & Q_int(4) & T_int(4) & Q_int(3) & T_int(3) & Q_int(2) & T_int(2) & Q_int(1) & T_int(1);


   
   --    index_Q: process(dclk, rst)
--        begin
--            if rst = '1' then
--                bit_count <= 0;
--            elsif rising_edge(dclk) then
--                if fclk = '1' and ack = '0' then
--                    bit_count <= 0;
--                else
--                    bit_count <= (bit_count + 1) mod 7;
--                end if;
--            end if;
--        end process index_Q;
   
   
   
   
   
--    serdes_Q: process(dclk, rst)
--        begin
--            if rst = '1' then
--                Q_int <= "0000000000000000";
--                T_int <= "0000000000000000";
----                bit_count <= 0;
--                ack <= '0';
--            elsif falling_edge(dclk) then
--                if fclk = '1' and ack = '0' then
--                    Q_int(7) <= Q1;
--                    T_int(7) <= Q2;
--                    ack <= '1';
----                    valid_reg <= '1';
--                    bit_count <= 1;
--                elsif fclk = '1' and ack = '1' then
--                    Q_int(bit_count) <= Q1;
--                    T_int(bit_count) <= Q2;
--                    valid_reg <= '0';                    
--                    bit_count <= bit_count + 1;
--                elsif fclk = '0' then
--                    ack <= '0';
--                    Q_int(bit_count) <= Q1;
--                    T_int(bit_count) <= Q2;
--                    if bit_count = 6 then
--                        valid_reg <= '1';
--                    end if; 
--                    bit_count <= (bit_count + 1) mod 7;
--                end if;     
--            end if;
--        end process serdes_Q; 
        
        
--        deserialize: process(dclk, valid_reg , rst)
--        begin
--            if rst = '1' then
--                sample <= "0000000000000000";
--            elsif rising_edge(dclk) then
--                if valid_reg = '1' then
--                    sample <= "00"  & Q_int(7) & T_int(7) & Q_int(1) & T_int(1) & Q_int(2) & T_int(2) & Q_int(3) & T_int(3) & Q_int(4) & T_int(4) & Q_int(5) & T_int(5) & Q_int(6) & T_int(6);
--                    -- sample <= "00" & Q_int(0) & T_int(0) & Q_int(1) & T_int(1) & Q_int(2) & T_int(2) & Q_int(3) & T_int(3) & Q_int(4) & T_int(4) & Q_int(5) & T_int(5) & Q_int(6) & T_int(6) & Q_int(7) & T_int(7);
--                end if;
--            end if;
--        end process deserialize;
        
--        Q <= Q_int;
--        T <= T_int; 
        
--        valid <= valid_reg;   


end Behavioral;
