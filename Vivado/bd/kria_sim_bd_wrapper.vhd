--Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
----------------------------------------------------------------------------------
--Tool Version: Vivado v.2022.2 (win64) Build 3671981 Fri Oct 14 05:00:03 MDT 2022
--Date        : Mon Aug  4 14:23:03 2025
--Host        : DESKTOP-3FHD9AF running 64-bit major release  (build 9200)
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
    data_in_n : in STD_LOGIC;
    data_in_p : in STD_LOGIC;
    fclk_in_n : in STD_LOGIC;
    fclk_in_p : in STD_LOGIC;
    uf_led_0 : out STD_LOGIC;
    uf_led_1 : out STD_LOGIC
  );
end kria_sim_bd_wrapper;

architecture STRUCTURE of kria_sim_bd_wrapper is
  component kria_sim_bd is
  port (
    fclk_in_n : in STD_LOGIC;
    fclk_in_p : in STD_LOGIC;
    data_in_p : in STD_LOGIC;
    data_in_n : in STD_LOGIC;
    uf_led_0 : out STD_LOGIC;
    uf_led_1 : out STD_LOGIC
  );
  end component kria_sim_bd;
begin
kria_sim_bd_i: component kria_sim_bd
     port map (
      data_in_n => data_in_n,
      data_in_p => data_in_p,
      fclk_in_n => fclk_in_n,
      fclk_in_p => fclk_in_p,
      uf_led_0 => uf_led_0,
      uf_led_1 => uf_led_1
    );
end STRUCTURE;
