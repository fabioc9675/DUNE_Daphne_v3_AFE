##################### PL I2C Interface ################################
#set_property PACKAGE_PIN AD10 [get_ports {kria_i2c_0_sda_io}]     
#set_property IOSTANDARD LVCMOS33 [get_ports {kria_i2c_0_sda_io}] 
#set_property PULLUP TRUE [get_ports {kria_i2c_0_sda_io}]

#set_property PACKAGE_PIN AD11 [get_ports {kria_i2c_0_scl_io}]
#set_property IOSTANDARD LVCMOS33 [get_ports {kria_i2c_0_scl_io}]
#set_property PULLUP TRUE [get_ports {kria_i2c_0_scl_io}]


##################### AFEn_PDN pin ###################################
set_property PACKAGE_PIN AE12 [get_ports {afe_pdn_rst_bus_tri_io[0]}]          ;# AFE PDN pin
set_property IOSTANDARD LVCMOS33 [get_ports {afe_pdn_rst_bus_tri_io[0]}]

##################### AFEn_RST pin ###################################
set_property PACKAGE_PIN AG13 [get_ports {afe_pdn_rst_bus_tri_io[1]}]          ;# AFE RST pin
set_property IOSTANDARD LVCMOS33 [get_ports {afe_pdn_rst_bus_tri_io[1]}]


##################### AFE0_SPI Interface ###################################
set_property PACKAGE_PIN B10 [get_ports {afe0_sdout}]                          ;# AFE MISO
set_property IOSTANDARD LVCMOS33 [get_ports {afe0_sdout}]

set_property PACKAGE_PIN H11 [get_ports {afe0_sdata}]                          ;# AFE MOSI
set_property IOSTANDARD LVCMOS33 [get_ports {afe0_sdata}]

set_property PACKAGE_PIN H12 [get_ports {afe0_sclk}]                          ;# AFE SCK
set_property IOSTANDARD LVCMOS33 [get_ports {afe0_sclk}]


###################### AFE_CH1 ############################
set_property PACKAGE_PIN F12 [get_ports {fclk_in}]                          ;# AFE FCLK_P pin
set_property IOSTANDARD LVCMOS33 [get_ports {fclk_in}]

set_property PACKAGE_PIN AD10 [get_ports {data_in}]                         ;# AFE DATA_P pin
set_property IOSTANDARD LVCMOS33 [get_ports {data_in}]

set_property CLOCK_DEDICATED_ROUTE FALSE [get_nets kria_bd_i/ADC_AFE_interface_0/U0/IBUF_fclk_p/O]
set_property CLOCK_DEDICATED_ROUTE BACKBONE [get_nets kria_bd_i/ADC_AFE_interface_0/fclk_out]


###################### AFE_CH1 DIFFERENTIAL LVDS ############################
set_property PACKAGE_PIN AE15 [get_ports {fclk_in_p}]                          ;# AFE FCLK_P pin
set_property IOSTANDARD DIFF_HSTL_I_18 [get_ports {fclk_in_p}]
set_property PACKAGE_PIN AE14 [get_ports {fclk_in_n}]                          ;# AFE FCLK_N pin
set_property IOSTANDARD DIFF_HSTL_I_18 [get_ports {fclk_in_n}]
#set_property DIFF_TERM TRUE [get_ports fclk_in_p]

set_property PACKAGE_PIN W14 [get_ports {data_in_p}]                          ;# AFE DATA_P pin
set_property IOSTANDARD DIFF_HSTL_I_18 [get_ports {data_in_p}]
set_property PACKAGE_PIN W13 [get_ports {data_in_n}]                          ;# AFE DATA_N pin
set_property IOSTANDARD DIFF_HSTL_I_18 [get_ports {data_in_n}]
#set_property DIFF_TERM TRUE [get_ports data_in_p]

set_property CLOCK_DEDICATED_ROUTE FALSE [get_nets kria_bd_i/ADC_AFE_Diff_interfa_0/U0/IBUFDS_fclk/O] 


##################### AFE1_AFE2_SPI Interface ##############################
#set_property PACKAGE_PIN E12 [get_ports {afe1_afe2_sdout}]                     ;# AFE MISO
#set_property IOSTANDARD LVCMOS33 [get_ports {afe1_afe2_sdout}]

#set_property PACKAGE_PIN J12 [get_ports {afe1_afe2_sdata}]                     ;# AFE MOSI
#set_property IOSTANDARD LVCMOS33 [get_ports {afe1_afe2_sdata}]

#set_property PACKAGE_PIN F12 [get_ports {afe1_afe2_sclk}]                      ;# AFE SCK
#set_property IOSTANDARD LVCMOS33 [get_ports {afe1_afe2_sclk}]

###################### AFE3_AFE4_SPI Interface ##############################
#set_property PACKAGE_PIN AH14 [get_ports {afe3_afe4_sdout}]                    ;# AFE MISO
#set_property IOSTANDARD LVCMOS33 [get_ports {afe3_afe4_sdout}]

#set_property PACKAGE_PIN AC13 [get_ports {afe3_afe4_sdata}]                    ;# AFE MOSI
#set_property IOSTANDARD LVCMOS33 [get_ports {afe3_afe4_sdata}]

#set_property PACKAGE_PIN AD12 [get_ports {afe3_afe4_sclk}]                     ;# AFE SCK
#set_property IOSTANDARD LVCMOS33 [get_ports {afe3_afe4_sclk}]



##################### BIAS_DAC_SPI Interface ##############################
#set_property PACKAGE_PIN AD15 [get_ports {bias_dac_din}]                       ;# DAC MOSI
#set_property IOSTANDARD LVCMOS33 [get_ports {bias_dac_din}]

#set_property PACKAGE_PIN AD14 [get_ports {bias_dac_sclk}]                      ;# DAC SCK
#set_property IOSTANDARD LVCMOS33 [get_ports {bias_dac_sclk}]


###################### GPIO_CTRL_BIAS Interface ############################
#set_property PACKAGE_PIN AF10 [get_ports {bias_gpio_ctrl_tri_io[0]}]          ;# DAC SYNC pin
#set_property IOSTANDARD LVCMOS33 [get_ports {bias_gpio_ctrl_tri_io[0]}]

#set_property PACKAGE_PIN AE10 [get_ports {bias_gpio_ctrl_tri_io[1]}]          ;# DAC LDAC pin
#set_property IOSTANDARD LVCMOS33 [get_ports {bias_gpio_ctrl_tri_io[1]}]




##################### GPIO_CTRL_AFE0 Interface ############################
set_property PACKAGE_PIN J11 [get_ports {afe_gpio_ctrl_tri_io[0]}]          ;# AFE SEn pin
set_property IOSTANDARD LVCMOS33 [get_ports {afe_gpio_ctrl_tri_io[0]}]

#set_property PACKAGE_PIN AB14 [get_ports {afe_gpio_ctrl_tri_io[1]}]          ;# TRM SYNC pin
#set_property IOSTANDARD LVCMOS33 [get_ports {afe_gpio_ctrl_tri_io[1]}]

#set_property PACKAGE_PIN Y12 [get_ports {afe_gpio_ctrl_tri_io[2]}]           ;# TRM LDAC pin
#set_property IOSTANDARD LVCMOS33 [get_ports {afe_gpio_ctrl_tri_io[2]}]

#set_property PACKAGE_PIN W12 [get_ports {afe_gpio_ctrl_tri_io[3]}]           ;# OFF SYNC pin
#set_property IOSTANDARD LVCMOS33 [get_ports {afe_gpio_ctrl_tri_io[3]}]

#set_property PACKAGE_PIN W11 [get_ports {afe_gpio_ctrl_tri_io[4]}]           ;# OFF LDAC pin
#set_property IOSTANDARD LVCMOS33 [get_ports {afe_gpio_ctrl_tri_io[4]}]




##################### GPIO_CTRL_AFE1 Interface ############################
#set_property PACKAGE_PIN E10 [get_ports {afe_gpio_ctrl_tri_io[5]}]           ;# AFE SEn pin
#set_property IOSTANDARD LVCMOS33 [get_ports {afe_gpio_ctrl_tri_io[5]}]

#set_property PACKAGE_PIN B11 [get_ports {afe_gpio_ctrl_tri_io[6]}]           ;# TRM SYNC pin
#set_property IOSTANDARD LVCMOS33 [get_ports {afe_gpio_ctrl_tri_io[6]}]

#set_property PACKAGE_PIN A10 [get_ports {afe_gpio_ctrl_tri_io[7]}]           ;# TRM LDAC pin
#set_property IOSTANDARD LVCMOS33 [get_ports {afe_gpio_ctrl_tri_io[7]}]

#set_property PACKAGE_PIN D10 [get_ports {afe_gpio_ctrl_tri_io[8]}]           ;# OFF SYNC pin
#set_property IOSTANDARD LVCMOS33 [get_ports {afe_gpio_ctrl_tri_io[8]}]

#set_property PACKAGE_PIN C11 [get_ports {afe_gpio_ctrl_tri_io[9]}]           ;# OFF LDAC pin
#set_property IOSTANDARD LVCMOS33 [get_ports {afe_gpio_ctrl_tri_io[9]}]




###################### GPIO_CTRL_AFE2 Interface ############################
#set_property PACKAGE_PIN B10 [get_ports {afe_gpio_ctrl_tri_io[10]}]           ;# AFE SEn pin
#set_property IOSTANDARD LVCMOS33 [get_ports {afe_gpio_ctrl_tri_io[10]}]

#set_property PACKAGE_PIN K13 [get_ports {afe_gpio_ctrl_tri_io[11]}]           ;# TRM SYNC pin
#set_property IOSTANDARD LVCMOS33 [get_ports {afe_gpio_ctrl_tri_io[11]}]

#set_property PACKAGE_PIN J10 [get_ports {afe_gpio_ctrl_tri_io[12]}]           ;# TRM LDAC pin
#set_property IOSTANDARD LVCMOS33 [get_ports {afe_gpio_ctrl_tri_io[12]}]

#set_property PACKAGE_PIN K12 [get_ports {afe_gpio_ctrl_tri_io[13]}]           ;# OFF SYNC pin
#set_property IOSTANDARD LVCMOS33 [get_ports {afe_gpio_ctrl_tri_io[13]}]

#set_property PACKAGE_PIN H12 [get_ports {afe_gpio_ctrl_tri_io[14]}]           ;# OFF LDAC pin
#set_property IOSTANDARD LVCMOS33 [get_ports {afe_gpio_ctrl_tri_io[14]}]




###################### GPIO_CTRL_AFE3 Interface ############################
#set_property PACKAGE_PIN AF11 [get_ports {afe_gpio_ctrl_tri_io[15]}]          ;# AFE SEn pin
#set_property IOSTANDARD LVCMOS33 [get_ports {afe_gpio_ctrl_tri_io[15]}]

#set_property PACKAGE_PIN AG10 [get_ports {afe_gpio_ctrl_tri_io[16]}]          ;# TRM SYNC pin
#set_property IOSTANDARD LVCMOS33 [get_ports {afe_gpio_ctrl_tri_io[16]}]

#set_property PACKAGE_PIN AH11 [get_ports {afe_gpio_ctrl_tri_io[17]}]          ;# TRM LDAC pin
#set_property IOSTANDARD LVCMOS33 [get_ports {afe_gpio_ctrl_tri_io[17]}]

#set_property PACKAGE_PIN AC12 [get_ports {afe_gpio_ctrl_tri_io[18]}]          ;# OFF SYNC pin
#set_property IOSTANDARD LVCMOS33 [get_ports {afe_gpio_ctrl_tri_io[18]}]

#set_property PACKAGE_PIN AH10 [get_ports {afe_gpio_ctrl_tri_io[19]}]          ;# OFF LDAC pin
#set_property IOSTANDARD LVCMOS33 [get_ports {afe_gpio_ctrl_tri_io[19]}]




###################### GPIO_CTRL_AFE4 Interface ############################
#set_property PACKAGE_PIN AG14 [get_ports {afe_gpio_ctrl_tri_io[20]}]          ;# AFE SEn pin
#set_property IOSTANDARD LVCMOS33 [get_ports {afe_gpio_ctrl_tri_io[20]}]

#set_property PACKAGE_PIN AE15 [get_ports {afe_gpio_ctrl_tri_io[21]}]          ;# TRM SYNC pin
#set_property IOSTANDARD LVCMOS33 [get_ports {afe_gpio_ctrl_tri_io[21]}]

#set_property PACKAGE_PIN AH13 [get_ports {afe_gpio_ctrl_tri_io[22]}]          ;# TRM LDAC pin
#set_property IOSTANDARD LVCMOS33 [get_ports {afe_gpio_ctrl_tri_io[22]}]

#set_property PACKAGE_PIN AC14 [get_ports {afe_gpio_ctrl_tri_io[23]}]          ;# OFF SYNC pin
#set_property IOSTANDARD LVCMOS33 [get_ports {afe_gpio_ctrl_tri_io[23]}]

#set_property PACKAGE_PIN AE14 [get_ports {afe_gpio_ctrl_tri_io[24]}]          ;# OFF LDAC pin
#set_property IOSTANDARD LVCMOS33 [get_ports {afe_gpio_ctrl_tri_io[24]}]





