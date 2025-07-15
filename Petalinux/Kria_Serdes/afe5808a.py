import ctypes

# Define las estructuras de bits
# Estructura REG00BITS
class REG00BITS(ctypes.LittleEndianStructure):
    _fields_ = [
        ("SOFTWARE_RESET", ctypes.c_uint16, 1),
        ("REGISTER_READOUT_ENABLE", ctypes.c_uint16, 1),
        ("reserved", ctypes.c_uint16, 14)
    ]

# Estructura REG01BITS
class REG01BITS(ctypes.LittleEndianStructure):
    _fields_ = [
        ("ADC_COMPLETE_PDN", ctypes.c_uint16, 1),
        ("LVDS_OUTPUT_DISABLE", ctypes.c_uint16, 1),
        ("ADC_PDN_CH", ctypes.c_uint16, 8),
        ("PARTIAL_PDN", ctypes.c_uint16, 1),
        ("LOW_FREQUENCY_NOISE_SUPPRESSION", ctypes.c_uint16, 1),
        ("reserved1", ctypes.c_uint16, 1),
        ("EXT_REF", ctypes.c_uint16, 1),
        ("LVDS_OUTPUT_RATE_2X", ctypes.c_uint16, 1),
        ("SINGLE_ENDED_CLK_MODE", ctypes.c_uint16, 1),
        ("reserved2", ctypes.c_uint16, 2),
        ("ADC_PDN_CH1", ctypes.c_uint16, 1),
        ("ADC_PDN_CH2", ctypes.c_uint16, 1),
        ("ADC_PDN_CH3", ctypes.c_uint16, 1),
        ("ADC_PDN_CH4", ctypes.c_uint16, 1),
        ("ADC_PDN_CH5", ctypes.c_uint16, 1),
        ("ADC_PDN_CH6", ctypes.c_uint16, 1),
        ("ADC_PDN_CH7", ctypes.c_uint16, 1),
        ("ADC_PDN_CH8", ctypes.c_uint16, 1),
        ("reserved3", ctypes.c_uint16, 6),
        ("VALUE", ctypes.c_uint16)
    ]

# Estructura REG02BITS
class REG02BITS(ctypes.LittleEndianStructure):
    _fields_ = [
        ("reserved1", ctypes.c_uint16, 3),
        ("POWER_DOWN_LVDS", ctypes.c_uint16, 8),
        ("AVERAGING_ENABLE", ctypes.c_uint16, 1),
        ("LOW_LATENCY", ctypes.c_uint16, 1),
        ("TEST_PATTERN_MODES", ctypes.c_uint16, 3)
    ]

# Estructura REG03BITS
class REG03BITS(ctypes.LittleEndianStructure):
    _fields_ = [
        ("INVERT_CHANNELS", ctypes.c_uint16, 8),
        ("CHANNEL_OFFSET_SUBSTRACTION_ENABLE", ctypes.c_uint16, 1),
        ("reserved1", ctypes.c_uint16, 3),
        ("DIGITAL_GAIN_ENABLE", ctypes.c_uint16, 1),
        ("SERIALIZED_DATA_RATE", ctypes.c_uint16, 2),
        ("ENABLE_EXTERNAL_REFERENCE_MODE", ctypes.c_uint16, 1)
    ]

# Estructura REG04BITS
class REG04BITS(ctypes.LittleEndianStructure):
    _fields_ = [
        ("reserved1", ctypes.c_uint16, 1),
        ("ADC_RESOLUTION_SELECT", ctypes.c_uint16, 1),
        ("reserved2", ctypes.c_uint16, 1),
        ("ADC_OUTPUT_FORMAT", ctypes.c_uint16, 1),
        ("LSB_MSB_FIRST", ctypes.c_uint16, 1),
        ("reserved3", ctypes.c_uint16, 11)
    ]

# Estructura REG05BITS
class REG05BITS(ctypes.LittleEndianStructure):
    _fields_ = [
        ("CUSTOM_PATTERN", ctypes.c_uint16, 14),
        ("reserved1", ctypes.c_uint16, 2)
    ]

# Estructura REG10BITS
class REG10BITS(ctypes.LittleEndianStructure):
    _fields_ = [
        ("reserved1", ctypes.c_uint16, 8),
        ("SYNC_PATTERN", ctypes.c_uint16, 1),
        ("reserved2", ctypes.c_uint16, 7)
    ]

# Estructura REG13BITS
class REG13BITS(ctypes.LittleEndianStructure):
    _fields_ = [
        ("OFFSET_CH1", ctypes.c_uint16, 10),
        ("reserved1", ctypes.c_uint16, 1),
        ("DIGITAL_GAIN_CH1", ctypes.c_uint16, 5)
    ]

# Estructura REG15BITS
class REG15BITS(ctypes.LittleEndianStructure):
    _fields_ = [
        ("OFFSET_CH2", ctypes.c_uint16, 10),
        ("reserved1", ctypes.c_uint16, 1),
        ("DIGITAL_GAIN_CH2", ctypes.c_uint16, 5)
    ]

# Estructura REG17BITS
class REG17BITS(ctypes.LittleEndianStructure):
    _fields_ = [
        ("OFFSET_CH3", ctypes.c_uint16, 10),
        ("reserved1", ctypes.c_uint16, 1),
        ("DIGITAL_GAIN_CH3", ctypes.c_uint16, 5)
    ]

# Estructura REG19BITS
class REG19BITS(ctypes.LittleEndianStructure):
    _fields_ = [
        ("OFFSET_CH4", ctypes.c_uint16, 10),
        ("reserved1", ctypes.c_uint16, 1),
        ("DIGITAL_GAIN_CH4", ctypes.c_uint16, 5)
    ]

# Estructura REG21BITS
class REG21BITS(ctypes.LittleEndianStructure):
    _fields_ = [
        ("DIGITAL_HPF_FILTER_ENABLE_CH1_4", ctypes.c_uint16, 1),
        ("DIGITAL_HPF_FILTER_K_CH1_4", ctypes.c_uint16, 4),
        ("reserved1", ctypes.c_uint16, 11)
    ]

# Estructura REG25BITS
class REG25BITS(ctypes.LittleEndianStructure):
    _fields_ = [
        ("OFFSET_CH8", ctypes.c_uint16, 10),
        ("reserved1", ctypes.c_uint16, 1),
        ("DIGITAL_GAIN_CH8", ctypes.c_uint16, 5)
    ]

# Estructura REG27BITS
class REG27BITS(ctypes.LittleEndianStructure):
    _fields_ = [
        ("OFFSET_CH7", ctypes.c_uint16, 10),
        ("reserved1", ctypes.c_uint16, 1),
        ("DIGITAL_GAIN_CH7", ctypes.c_uint16, 5)
    ]

# Estructura REG29BITS
class REG29BITS(ctypes.LittleEndianStructure):
    _fields_ = [
        ("OFFSET_CH6", ctypes.c_uint16, 10),
        ("reserved1", ctypes.c_uint16, 1),
        ("DIGITAL_GAIN_CH6", ctypes.c_uint16, 5)
    ]

# Estructura REG31BITS
class REG31BITS(ctypes.LittleEndianStructure):
    _fields_ = [
        ("OFFSET_CH5", ctypes.c_uint16, 10),
        ("reserved1", ctypes.c_uint16, 1),
        ("DIGITAL_GAIN_CH5", ctypes.c_uint16, 5)
    ]

# Estructura REG33BITS
class REG33BITS(ctypes.LittleEndianStructure):
    _fields_ = [
        ("DIGITAL_HPF_FILTER_ENABLE_CH5_8", ctypes.c_uint16, 1),
        ("DIGITAL_HPF_FILTER_K_CH5_8", ctypes.c_uint16, 4),
        ("reserved1", ctypes.c_uint16, 11)
    ]

# Estructura REG66BITS
class REG66BITS(ctypes.LittleEndianStructure):
    _fields_ = [
        ("reserved1", ctypes.c_uint16, 15),
        ("DITHER", ctypes.c_uint16, 1)
    ]

# Estructura REG50BITS
class REG50BITS(ctypes.LittleEndianStructure):
    _fields_ = [
        ("reserved1", ctypes.c_uint16, 10),
        ("PGA_CLAMP_m6dB", ctypes.c_uint16, 1),
        ("reserved2", ctypes.c_uint16, 5)
    ]

# Estructura REG51BITS
class REG51BITS(ctypes.LittleEndianStructure):
    _fields_ = [
        ("reserved1", ctypes.c_uint16, 1),
        ("LPF_PROGRAMMABILITY", ctypes.c_uint16, 3),
        ("PGA_INTEGRATOR_DISABLE", ctypes.c_uint16, 1),
        ("PGA_CLAMP_LEVEL", ctypes.c_uint16, 3),
        ("reserved2", ctypes.c_uint16, 5),
        ("PGA_GAIN_CONTROL", ctypes.c_uint16, 1),
        ("reserved3", ctypes.c_uint16, 2)
    ]

# Estructura REG52BITS
class REG52BITS(ctypes.LittleEndianStructure):
    _fields_ = [
        ("ACTIVE_TERMINATION_INDIVIDUAL_RESISTOR_CNTL", ctypes.c_uint16, 5),
        ("ACTIVE_TERMINATION_INDIVIDUAL_RESISTOR_ENABLE", ctypes.c_uint16, 1),
        ("PRESET_ACTIVE_TERMINATIONS", ctypes.c_uint16, 2),
        ("ACTIVE_TERMINATION_ENABLE", ctypes.c_uint16, 1),
        ("LNA_INPUT_CLAMP_SETTING", ctypes.c_uint16, 2),
        ("reserved1", ctypes.c_uint16, 1),
        ("LNA_INTEGRATOR_DISABLE", ctypes.c_uint16, 1),
        ("LNA_GAIN", ctypes.c_uint16, 2),
        ("LNA_INDIVIDUAL_CH_CNTL", ctypes.c_uint16, 1)
    ]

# Estructura REG53BITS
class REG53BITS(ctypes.LittleEndianStructure):
    _fields_ = [
        ("PDN_CH", ctypes.c_uint16, 8),
        ("reserved1", ctypes.c_uint16, 2),
        ("LOW_POWER", ctypes.c_uint16, 1),
        ("MED_POWER", ctypes.c_uint16, 1),
        ("PDN_VCAT_PGA", ctypes.c_uint16, 1),
        ("PDN_LNA", ctypes.c_uint16, 1),
        ("VCA_PARTIAL_PDN", ctypes.c_uint16, 1),
        ("VCA_COMPLETE_PDN", ctypes.c_uint16, 1)
    ]

# Estructura REG54BITS
class REG54BITS(ctypes.LittleEndianStructure):
    _fields_ = [
        ("CW_SUM_AMP_GAIN_CNTL", ctypes.c_uint16, 5),
        ("CW_16X_CLK_SEL", ctypes.c_uint16, 1),
        ("CW_1X_CLK_SEL", ctypes.c_uint16, 1),
        ("reserved1", ctypes.c_uint16, 1),
        ("CW_TGC_SEL", ctypes.c_uint16, 1),
        ("CW_SUM_AMP_ENABLE", ctypes.c_uint16, 1),
        ("CW_CLK_MODE_SEL", ctypes.c_uint16, 2),
        ("reserved2", ctypes.c_uint16, 4)
    ]

# Estructura REG55BITS
class REG55BITS(ctypes.LittleEndianStructure):
    _fields_ = [
        ("CH1_CW_MIXER_PHASE", ctypes.c_uint16, 4),
        ("CH2_CW_MIXER_PHASE", ctypes.c_uint16, 4),
        ("CH3_CW_MIXER_PHASE", ctypes.c_uint16, 4),
        ("CH4_CW_MIXER_PHASE", ctypes.c_uint16, 4)
    ]

# Estructura REG56BITS
class REG56BITS(ctypes.LittleEndianStructure):
    _fields_ = [
        ("CH5_CW_MIXER_PHASE", ctypes.c_uint16, 4),
        ("CH6_CW_MIXER_PHASE", ctypes.c_uint16, 4),
        ("CH7_CW_MIXER_PHASE", ctypes.c_uint16, 4),
        ("CH8_CW_MIXER_PHASE", ctypes.c_uint16, 4)
    ]

# Estructura REG57BITS
class REG57BITS(ctypes.LittleEndianStructure):
    _fields_ = [
        ("CH1_LNA_GAIN_CNTL", ctypes.c_uint16, 2),
        ("CH2_LNA_GAIN_CNTL", ctypes.c_uint16, 2),
        ("CH3_LNA_GAIN_CNTL", ctypes.c_uint16, 2),
        ("CH4_LNA_GAIN_CNTL", ctypes.c_uint16, 2),
        ("CH5_LNA_GAIN_CNTL", ctypes.c_uint16, 2),
        ("CH6_LNA_GAIN_CNTL", ctypes.c_uint16, 2),
        ("CH7_LNA_GAIN_CNTL", ctypes.c_uint16, 2),
        ("CH8_LNA_GAIN_CNTL", ctypes.c_uint16, 2)
    ]

# Estructura REG59BITS
class REG59BITS(ctypes.LittleEndianStructure):
    _fields_ = [
        ("reserved1", ctypes.c_uint16, 2),
        ("HPF_LNA", ctypes.c_uint16, 2),
        ("DIG_TGC_ATT_GAIN", ctypes.c_uint16, 3),
        ("DIG_TGC_ATT", ctypes.c_uint16, 1),
        ("CW_SUM_AMP_PDN", ctypes.c_uint16, 1),
        ("PGA_TEST_MODE", ctypes.c_uint16, 1),
        ("reserved2", ctypes.c_uint16, 6)
    ]


# Define más estructuras de bits siguiendo el mismo patrón...

# Define la estructura principal AFE_ADCRegisterMap
class AFE_ADCRegisterMap(ctypes.LittleEndianStructure):
    _fields_ = [
        ("REG00bits", REG00BITS),
        ("REG01bits", REG01BITS),
        ("REG02bits", REG02BITS),
        ("REG03bits", REG03BITS),
        ("REG04bits", REG04BITS),
        ("REG05bits", REG05BITS),
        ("REG10bits", REG10BITS),
        ("REG13bits", REG13BITS),
        ("REG15bits", REG15BITS),
        ("REG17bits", REG17BITS),
        ("REG19bits", REG19BITS),
        ("REG21bits", REG21BITS),
        ("REG25bits", REG25BITS),
        ("REG27bits", REG27BITS),
        ("REG29bits", REG29BITS),
        ("REG31bits", REG31BITS),
        ("REG33bits", REG33BITS),
        ("REG66bits", REG66BITS)
    ]

# Define la estructura principal AFE_VCARegisterMap
class AFE_VCARegisterMap(ctypes.LittleEndianStructure):
    _fields_ = [
        ("REG50bits", REG50BITS),
        ("REG51bits", REG51BITS),
        ("REG52bits", REG52BITS),
        ("REG53bits", REG53BITS),
        ("REG54bits", REG54BITS),
        ("REG55bits", REG55BITS),
        ("REG56bits", REG56BITS),
        ("REG57bits", REG57BITS),
        ("REG59bits", REG59BITS)
    ]
    
# Define la estructura principal AFE_HandleTypeDef
class SPI_HandleTypeDef(ctypes.LittleEndianStructure):
    _fields_ = [
        ("SPI_Device", ctypes.c_char_p),
        ("spi_trx", ctypes.c_void_p),
        ("fileDevice", ctypes.c_int),
        ("fileReturn", ctypes.c_int),
        ("spi_state", ctypes.c_uint32)
    ]

# Define la estructura principal AFE_HandleTypeDef
class AFE_HandleTypeDef(ctypes.LittleEndianStructure):
    _fields_ = [
        ("SPI_handle", SPI_HandleTypeDef),
        ("CS_Pin", ctypes.c_uint16),
        ("RST_Pin", ctypes.c_uint16),
        ("PDN_Pin", ctypes.c_uint16),
        ("ADCRegisterMap", AFE_ADCRegisterMap),
        ("VCARegisterMap", AFE_VCARegisterMap)
    ]


