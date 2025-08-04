#set_property CLOCK_DEDICATED_ROUTE FALSE [get_nets kria_bd_i/ADC_AFE_Diff_interfa_0/U0/IBUFDS_fclk/O] 

set_property PACKAGE_PIN J7 [get_ports {fclk_in_p}]                          ;# AFE FCLK_P pin
set_property PACKAGE_PIN H7 [get_ports {fclk_in_n}]                          ;# AFE FCLK_N pin
set_property IOSTANDARD LVDS [get_ports {fclk_in_p fclk_in_n}]
set_property DIFF_TERM TRUE [get_ports {fclk_in_p fclk_in_n}]

set_property PACKAGE_PIN K9 [get_ports {data_in_p}]                          ;# AFE DATA_P pin
set_property PACKAGE_PIN J9 [get_ports {data_in_n}]                          ;# AFE DATA_N pin
set_property IOSTANDARD LVDS [get_ports {data_in_p data_in_n}]
set_property DIFF_TERM TRUE [get_ports {data_in_p data_in_n}]

#set_property CLOCK_DEDICATED_ROUTE FALSE [get_nets kria_bd_i/ADC_AFE_Diff_interfa_0/U0/IBUFDS_fclk/O] 
#set_property CLOCK_DEDICATED_ROUTE FALSE [get_nets kria_bd_i/ADC_AFE_Diff_interfa_0/fclk_out]
#set_property CLOCK_DEDICATED_ROUTE FALSE [get_nets kria_bd_i/fclk_lvds_receiver_0/U0/IBUFDS_inst/O]
#set_property CLOCK_DEDICATED_ROUTE FALSE [get_nets kria_bd_i/fclk_lvds_receiver_1/U0/IBUFDS_inst/O]

set_property CLOCK_DEDICATED_ROUTE FALSE [get_nets kria_sim_bd_i/afe_clk_data_input_0/U0/IBUFDS_fclk/O]
set_property CLOCK_DEDICATED_ROUTE FALSE [get_nets kria_sim_bd_i/afe_clk_data_input_0/U0/IBUFDS_data/O]


########################## UF User LEDs #############################
# set_property PACKAGE_PIN F8 [get_ports {uf_leds_tri_io[0]}]
# set_property IOSTANDARD LVCMOS18 [get_ports {uf_leds_tri_io[0]}]

# set_property PACKAGE_PIN E8 [get_ports {uf_leds_tri_io[1]}]
# set_property IOSTANDARD LVCMOS18 [get_ports {uf_leds_tri_io[1]}]

set_property PACKAGE_PIN E8 [get_ports {uf_led_0}]
set_property IOSTANDARD LVCMOS18 [get_ports {uf_led_0}]

 set_property PACKAGE_PIN F8 [get_ports {uf_led_1}]
 set_property IOSTANDARD LVCMOS18 [get_ports {uf_led_1}]

