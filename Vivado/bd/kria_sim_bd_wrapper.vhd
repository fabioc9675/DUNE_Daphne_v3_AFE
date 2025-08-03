--Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
----------------------------------------------------------------------------------
--Tool Version: Vivado v.2022.2 (win64) Build 3671981 Fri Oct 14 05:00:03 MDT 2022
--Date        : Sun Aug  3 01:53:57 2025
--Host        : fabiancastano running 64-bit major release  (build 9200)
--Command     : generate_target kria_sim_bd_wrapper.bd
--Design      : kria_sim_bd_wrapper
--Purpose     : IP block netlist
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity kria_sim_bd_wrapper is
  port (
    Q_0 : out STD_LOGIC_VECTOR ( 7 downto 0 );
    T_0 : out STD_LOGIC_VECTOR ( 7 downto 0 );
    data_in_n : in STD_LOGIC;
    data_in_p : in STD_LOGIC;
    data_out_0 : out STD_LOGIC;
    dclk_out_0 : out STD_LOGIC;
    fclk_in_n : in STD_LOGIC;
    fclk_in_p : in STD_LOGIC;
    fclk_out_0 : out STD_LOGIC;
    sample_0 : out STD_LOGIC_VECTOR ( 15 downto 0 );
    valid_0 : out STD_LOGIC
  );
end kria_sim_bd_wrapper;

architecture STRUCTURE of kria_sim_bd_wrapper is
  component kria_sim_bd is
  port (
    fclk_in_n : in STD_LOGIC;
    fclk_in_p : in STD_LOGIC;
    data_in_p : in STD_LOGIC;
    data_in_n : in STD_LOGIC;
    dclk_out_0 : out STD_LOGIC;
    fclk_out_0 : out STD_LOGIC;
    data_out_0 : out STD_LOGIC;
    sample_0 : out STD_LOGIC_VECTOR ( 15 downto 0 );
    valid_0 : out STD_LOGIC;
    Q_0 : out STD_LOGIC_VECTOR ( 7 downto 0 );
    T_0 : out STD_LOGIC_VECTOR ( 7 downto 0 )
  );
  end component kria_sim_bd;
begin
kria_sim_bd_i: component kria_sim_bd
     port map (
      Q_0(7 downto 0) => Q_0(7 downto 0),
      T_0(7 downto 0) => T_0(7 downto 0),
      data_in_n => data_in_n,
      data_in_p => data_in_p,
      data_out_0 => data_out_0,
      dclk_out_0 => dclk_out_0,
      fclk_in_n => fclk_in_n,
      fclk_in_p => fclk_in_p,
      fclk_out_0 => fclk_out_0,
      sample_0(15 downto 0) => sample_0(15 downto 0),
      valid_0 => valid_0
    );
end STRUCTURE;
