library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity AXI_AFE_iddr_v1_0_S00_AXI is
	generic (
		-- Users to add parameters here
        
		-- User parameters ends
		-- Do not modify the parameters beyond this line

		-- Width of S_AXI data bus
		C_S_AXI_DATA_WIDTH	: integer	:= 32;
		-- Width of S_AXI address bus
		C_S_AXI_ADDR_WIDTH	: integer	:= 16
	);
	port (
		-- Users to add ports here
		--%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
		-- Se agregan los puertos necesarios para el funcionamiento del IP
		rst          :  in  std_logic;

		-- Senales diferenciales de entrada, falta agregar los otros canales
		afe_fclk_p   :  in  std_logic;
		afe_fclk_n   :  in  std_logic;

		afe_dat1_p   :  in  std_logic;
		afe_dat1_n   :  in  std_logic;		
		afe_dat2_p   :  in  std_logic;
		afe_dat2_n   :  in  std_logic;
		afe_dat3_p   :  in  std_logic;
		afe_dat3_n   :  in  std_logic;
		afe_dat4_p   :  in  std_logic;
		afe_dat4_n   :  in  std_logic;
		afe_dat5_p   :  in  std_logic;
		afe_dat5_n   :  in  std_logic;
		afe_dat6_p   :  in  std_logic;
		afe_dat6_n   :  in  std_logic;
		afe_dat7_p   :  in  std_logic;
		afe_dat7_n   :  in  std_logic;
		afe_dat8_p   :  in  std_logic;
		afe_dat8_n   :  in  std_logic;

		-- Senales de reloj generadas por el IP.
		afe_fclk_out :  out std_logic;
		afe_dclk_out :  out std_logic;

		-- Dato deserializado
		afe_dat1_out :  out std_logic_vector (15 downto 0);
		afe_dat2_out :  out std_logic_vector (15 downto 0);
		afe_dat3_out :  out std_logic_vector (15 downto 0);
		afe_dat4_out :  out std_logic_vector (15 downto 0);
		afe_dat5_out :  out std_logic_vector (15 downto 0);
		afe_dat6_out :  out std_logic_vector (15 downto 0);
		afe_dat7_out :  out std_logic_vector (15 downto 0);
		afe_dat8_out :  out std_logic_vector (15 downto 0);
		valid        :  out std_logic;
		--%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
		-- User ports ends
		-- Do not modify the ports beyond this line

		-- Global Clock Signal
		S_AXI_ACLK	: in std_logic;
		-- Global Reset Signal. This Signal is Active LOW
		S_AXI_ARESETN	: in std_logic;
		-- Write address (issued by master, acceped by Slave)
		S_AXI_AWADDR	: in std_logic_vector(C_S_AXI_ADDR_WIDTH-1 downto 0);
		-- Write channel Protection type. This signal indicates the
    		-- privilege and security level of the transaction, and whether
    		-- the transaction is a data access or an instruction access.
		S_AXI_AWPROT	: in std_logic_vector(2 downto 0);
		-- Write address valid. This signal indicates that the master signaling
    		-- valid write address and control information.
		S_AXI_AWVALID	: in std_logic;
		-- Write address ready. This signal indicates that the slave is ready
    		-- to accept an address and associated control signals.
		S_AXI_AWREADY	: out std_logic;
		-- Write data (issued by master, acceped by Slave) 
		S_AXI_WDATA	: in std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
		-- Write strobes. This signal indicates which byte lanes hold
    		-- valid data. There is one write strobe bit for each eight
    		-- bits of the write data bus.    
		S_AXI_WSTRB	: in std_logic_vector((C_S_AXI_DATA_WIDTH/8)-1 downto 0);
		-- Write valid. This signal indicates that valid write
    		-- data and strobes are available.
		S_AXI_WVALID	: in std_logic;
		-- Write ready. This signal indicates that the slave
    		-- can accept the write data.
		S_AXI_WREADY	: out std_logic;
		-- Write response. This signal indicates the status
    		-- of the write transaction.
		S_AXI_BRESP	: out std_logic_vector(1 downto 0);
		-- Write response valid. This signal indicates that the channel
    		-- is signaling a valid write response.
		S_AXI_BVALID	: out std_logic;
		-- Response ready. This signal indicates that the master
    		-- can accept a write response.
		S_AXI_BREADY	: in std_logic;
		-- Read address (issued by master, acceped by Slave)
		S_AXI_ARADDR	: in std_logic_vector(C_S_AXI_ADDR_WIDTH-1 downto 0);
		-- Protection type. This signal indicates the privilege
    		-- and security level of the transaction, and whether the
    		-- transaction is a data access or an instruction access.
		S_AXI_ARPROT	: in std_logic_vector(2 downto 0);
		-- Read address valid. This signal indicates that the channel
    		-- is signaling valid read address and control information.
		S_AXI_ARVALID	: in std_logic;
		-- Read address ready. This signal indicates that the slave is
    		-- ready to accept an address and associated control signals.
		S_AXI_ARREADY	: out std_logic;
		-- Read data (issued by slave)
		S_AXI_RDATA	: out std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
		-- Read response. This signal indicates the status of the
    		-- read transfer.
		S_AXI_RRESP	: out std_logic_vector(1 downto 0);
		-- Read valid. This signal indicates that the channel is
    		-- signaling the required read data.
		S_AXI_RVALID	: out std_logic;
		-- Read ready. This signal indicates that the master can
    		-- accept the read data and response information.
		S_AXI_RREADY	: in std_logic
	);
end AXI_AFE_iddr_v1_0_S00_AXI;

architecture arch_imp of AXI_AFE_iddr_v1_0_S00_AXI is

	-- AXI4LITE signals
	signal axi_awaddr	: std_logic_vector(C_S_AXI_ADDR_WIDTH-1 downto 0);
	signal axi_awready	: std_logic;
	signal axi_wready	: std_logic;
	signal axi_bresp	: std_logic_vector(1 downto 0);
	signal axi_bvalid	: std_logic;
	signal axi_araddr	: std_logic_vector(C_S_AXI_ADDR_WIDTH-1 downto 0);
	signal axi_arready	: std_logic;
	signal axi_rdata	: std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
	signal axi_rresp	: std_logic_vector(1 downto 0);
	signal axi_rvalid	: std_logic;

	-- Example-specific design signals
	-- local parameter for addressing 32 bit / 64 bit C_S_AXI_DATA_WIDTH
	-- ADDR_LSB is used for addressing 32/64 bit registers/memories
	-- ADDR_LSB = 2 for 32 bits (n downto 2)
	-- ADDR_LSB = 3 for 64 bits (n downto 3)
	constant ADDR_LSB  : integer := (C_S_AXI_DATA_WIDTH/32)+ 1;
	constant OPT_MEM_ADDR_BITS : integer := 1;
	------------------------------------------------
	---- Signals for user logic register space example
	--------------------------------------------------
	---- Number of Slave Registers 4
	signal slv_reg00	:std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
	signal slv_reg01	:std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
	signal slv_reg02	:std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
	signal slv_reg03	:std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);	
	signal slv_reg04	:std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);	
	signal slv_reg05	:std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);	
	signal slv_reg06	:std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);	
	signal slv_reg07	:std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);	
	signal slv_reg08	:std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);	
	signal slv_reg09	:std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);	
	signal slv_reg10	:std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);	
	signal slv_reg11	:std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);	
	signal slv_reg12	:std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);	
	signal slv_reg13	:std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);	
	signal slv_reg14	:std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);	
	signal slv_reg15	:std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);	
	signal slv_reg_rden	: std_logic;
	signal slv_reg_wren	: std_logic;
	signal reg_data_out	:std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
	signal byte_index	: integer;
	signal aw_en	: std_logic;


	--**************************************************
	---- Parte agregada por Fabian
	--**************************************************
	signal fclk_out    : std_logic;  
	signal fclk_raw    : std_logic;                     -- signal output from fclk single ended

	signal dat1_out    : std_logic;                      -- signal output from data single ended
	signal dat2_out    : std_logic;                      -- signal output from data single ended
	signal dat3_out    : std_logic;                      -- signal output from data single ended
	signal dat4_out    : std_logic;                      -- signal output from data single ended
	signal dat5_out    : std_logic;                      -- signal output from data single ended
	signal dat6_out    : std_logic;                      -- signal output from data single ended
	signal dat7_out    : std_logic;                      -- signal output from data single ended
	signal dat8_out    : std_logic;                      -- signal output from data single ended

	signal dclk_out    : std_logic;                      -- signal output from dclk generator

	signal dat1_sample : std_logic_vector (31 downto 0); -- circular buffer with deserialized data
	signal dat2_sample : std_logic_vector (31 downto 0); -- circular buffer with deserialized data
	signal dat3_sample : std_logic_vector (31 downto 0); -- circular buffer with deserialized data
	signal dat4_sample : std_logic_vector (31 downto 0); -- circular buffer with deserialized data
	signal dat5_sample : std_logic_vector (31 downto 0); -- circular buffer with deserialized data
	signal dat6_sample : std_logic_vector (31 downto 0); -- circular buffer with deserialized data
	signal dat7_sample : std_logic_vector (31 downto 0); -- circular buffer with deserialized data
	signal dat8_sample : std_logic_vector (31 downto 0); -- circular buffer with deserialized data

	signal afe_d1_out  : std_logic_vector (15 downto 0);
	signal afe_d2_out  : std_logic_vector (15 downto 0);
	signal afe_d3_out  : std_logic_vector (15 downto 0);
	signal afe_d4_out  : std_logic_vector (15 downto 0);
	signal afe_d5_out  : std_logic_vector (15 downto 0);
	signal afe_d6_out  : std_logic_vector (15 downto 0);
	signal afe_d7_out  : std_logic_vector (15 downto 0);
	signal afe_d8_out  : std_logic_vector (15 downto 0);

	signal delay1_reg  : std_logic_vector ( 3 downto 0);
	signal delay2_reg  : std_logic_vector ( 3 downto 0);
	signal delay3_reg  : std_logic_vector ( 3 downto 0);
	signal delay4_reg  : std_logic_vector ( 3 downto 0);
	signal delay5_reg  : std_logic_vector ( 3 downto 0);
	signal delay6_reg  : std_logic_vector ( 3 downto 0);
	signal delay7_reg  : std_logic_vector ( 3 downto 0);
	signal delay8_reg  : std_logic_vector ( 3 downto 0);

	signal sel1_reg    : std_logic_vector ( 3 downto 0);
	signal sel2_reg    : std_logic_vector ( 3 downto 0);
	signal sel3_reg    : std_logic_vector ( 3 downto 0);
	signal sel4_reg    : std_logic_vector ( 3 downto 0);
	signal sel5_reg    : std_logic_vector ( 3 downto 0);
	signal sel6_reg    : std_logic_vector ( 3 downto 0);
	signal sel7_reg    : std_logic_vector ( 3 downto 0);
	signal sel8_reg    : std_logic_vector ( 3 downto 0);

	--signal Q_reg       : std_logic_vector (15 downto 0);
	--signal T_reg       : std_logic_vector (15 downto 0);
	
	--**************************************************
        ---- Final Parte agregada por Fabian
	--**************************************************


	--**************************************************
	---- Parte agregada por Fabian
	--**************************************************
	-- Components instantiation
	
	-- component afe_fclk_single
	component afe_fclk_single is
    Port ( 
		fclk_in_p    : in  std_logic;
        fclk_in_n    : in  std_logic;
		fclk_raw     : out STD_LOGIC;
        fclk_out     : out std_logic
	);
	end component afe_fclk_single;

	-- component afe_fclk_single
	component afe_data_single is
    Port ( 
		data_in_p    : in  STD_LOGIC;
        data_in_n    : in  STD_LOGIC;
        data_out     : out STD_LOGIC
    );
	end component afe_data_single;

	-- component afe_dclk_source
	component afe_dclk_source is
    Port ( 
		rst      : in  std_logic;
        fclk_in  : in  std_logic;  -- Input clock
        dclk_out : out std_logic     -- Output clock
    );
	end component afe_dclk_source;

	-- component afe_deserializer
	component afe_deserializer is
    Port ( 
        rst       : in  std_logic;
        fclk      : in  std_logic;
        dclk      : in  std_logic;     
        data_in   : in  std_logic;  -- Serial DDR data from AFE
        sample    : out std_logic_vector(31 downto 0);  -- 14-bit parallel output
        valid     : out std_logic; 
        Q         : out std_logic_vector(15 downto 0);
        T         : out std_logic_vector(15 downto 0)
    );
	end component afe_deserializer;

	-- component afe_slice_data
	component afe_slice_data is
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
	end component afe_slice_data;
	--**************************************************
    ---- Final Parte agregada por Fabian
    --**************************************************

begin
	-- I/O Connections assignments

	S_AXI_AWREADY	<= axi_awready;
	S_AXI_WREADY	<= axi_wready;
	S_AXI_BRESP	    <= axi_bresp;
	S_AXI_BVALID	<= axi_bvalid;
	S_AXI_ARREADY	<= axi_arready;
	S_AXI_RDATA	    <= axi_rdata;
	S_AXI_RRESP	    <= axi_rresp;
	S_AXI_RVALID	<= axi_rvalid;
	-- Implement axi_awready generation
	-- axi_awready is asserted for one S_AXI_ACLK clock cycle when both
	-- S_AXI_AWVALID and S_AXI_WVALID are asserted. axi_awready is
	-- de-asserted when reset is low.

	process (S_AXI_ACLK)
	begin
	  if rising_edge(S_AXI_ACLK) then 
	    if S_AXI_ARESETN = '0' then
	      axi_awready <= '0';
	      aw_en <= '1';
	    else
	      if (axi_awready = '0' and S_AXI_AWVALID = '1' and S_AXI_WVALID = '1' and aw_en = '1') then
	        -- slave is ready to accept write address when
	        -- there is a valid write address and write data
	        -- on the write address and data bus. This design 
	        -- expects no outstanding transactions. 
	           axi_awready <= '1';
	           aw_en <= '0';
	        elsif (S_AXI_BREADY = '1' and axi_bvalid = '1') then
	           aw_en <= '1';
	           axi_awready <= '0';
	      else
	        axi_awready <= '0';
	      end if;
	    end if;
	  end if;
	end process;

	-- Implement axi_awaddr latching
	-- This process is used to latch the address when both 
	-- S_AXI_AWVALID and S_AXI_WVALID are valid. 

	process (S_AXI_ACLK)
	begin
	  if rising_edge(S_AXI_ACLK) then 
	    if S_AXI_ARESETN = '0' then
	      axi_awaddr <= (others => '0');
	    else
	      if (axi_awready = '0' and S_AXI_AWVALID = '1' and S_AXI_WVALID = '1' and aw_en = '1') then
	        -- Write Address latching
	        axi_awaddr <= S_AXI_AWADDR;
	      end if;
	    end if;
	  end if;                   
	end process; 

	-- Implement axi_wready generation
	-- axi_wready is asserted for one S_AXI_ACLK clock cycle when both
	-- S_AXI_AWVALID and S_AXI_WVALID are asserted. axi_wready is 
	-- de-asserted when reset is low. 

	process (S_AXI_ACLK)
	begin
	  if rising_edge(S_AXI_ACLK) then 
	    if S_AXI_ARESETN = '0' then
	      axi_wready <= '0';
	    else
	      if (axi_wready = '0' and S_AXI_WVALID = '1' and S_AXI_AWVALID = '1' and aw_en = '1') then
	          -- slave is ready to accept write data when 
	          -- there is a valid write address and write data
	          -- on the write address and data bus. This design 
	          -- expects no outstanding transactions.           
	          axi_wready <= '1';
	      else
	        axi_wready <= '0';
	      end if;
	    end if;
	  end if;
	end process; 

	-- Implement memory mapped register select and write logic generation
	-- The write data is accepted and written to memory mapped registers when
	-- axi_awready, S_AXI_WVALID, axi_wready and S_AXI_WVALID are asserted. Write strobes are used to
	-- select byte enables of slave registers while writing.
	-- These registers are cleared when reset (active low) is applied.
	-- Slave register write enable is asserted when valid address and data are available
	-- and the slave is ready to accept the write address and write data.
	slv_reg_wren <= axi_wready and S_AXI_WVALID and axi_awready and S_AXI_AWVALID ;

	process (S_AXI_ACLK)
	variable loc_addr :std_logic_vector(OPT_MEM_ADDR_BITS downto 0); 
	begin
	  if rising_edge(S_AXI_ACLK) then 
	    if S_AXI_ARESETN = '0' then
	      slv_reg00 <= (others => '0');
	      slv_reg01 <= (others => '0');
	      slv_reg02 <= (others => '0');
	      slv_reg03 <= (others => '0');
	      slv_reg04 <= (others => '0');
	      slv_reg05 <= (others => '0');
	      slv_reg06 <= (others => '0');
	      slv_reg07 <= (others => '0');
	      slv_reg08 <= (others => '0');
	      slv_reg09 <= (others => '0');
	      slv_reg10 <= (others => '0');
	      slv_reg11 <= (others => '0');
	      slv_reg12 <= (others => '0');
	      slv_reg13 <= (others => '0');
	      slv_reg14 <= (others => '0');
	      slv_reg15 <= (others => '0');
	    else
	      loc_addr := axi_awaddr(ADDR_LSB + OPT_MEM_ADDR_BITS downto ADDR_LSB);
	      if (slv_reg_wren = '1') then
	        case loc_addr is
	          when b"0000" =>
	            for byte_index in 0 to (C_S_AXI_DATA_WIDTH/8-1) loop
	              if ( S_AXI_WSTRB(byte_index) = '1' ) then
	                -- Respective byte enables are asserted as per write strobes                   
	                -- slave registor 0
	                slv_reg00(byte_index*8+7 downto byte_index*8) <= S_AXI_WDATA(byte_index*8+7 downto byte_index*8);
	              end if;
	            end loop;
	          when b"0001" =>
	            for byte_index in 0 to (C_S_AXI_DATA_WIDTH/8-1) loop
	              if ( S_AXI_WSTRB(byte_index) = '1' ) then
	                -- Respective byte enables are asserted as per write strobes                   
	                -- slave registor 1
	                slv_reg01(byte_index*8+7 downto byte_index*8) <= S_AXI_WDATA(byte_index*8+7 downto byte_index*8);
	              end if;
	            end loop;
	          when b"0010" =>
	            for byte_index in 0 to (C_S_AXI_DATA_WIDTH/8-1) loop
	              if ( S_AXI_WSTRB(byte_index) = '1' ) then
	                -- Respective byte enables are asserted as per write strobes                   
	                -- slave registor 2
	                slv_reg02(byte_index*8+7 downto byte_index*8) <= S_AXI_WDATA(byte_index*8+7 downto byte_index*8);
	              end if;
	            end loop;
	          when b"0011" =>
	            for byte_index in 0 to (C_S_AXI_DATA_WIDTH/8-1) loop
	              if ( S_AXI_WSTRB(byte_index) = '1' ) then
	                -- Respective byte enables are asserted as per write strobes                   
	                -- slave registor 3
	                slv_reg03(byte_index*8+7 downto byte_index*8) <= S_AXI_WDATA(byte_index*8+7 downto byte_index*8);
	              end if;
	            end loop;
			  when b"0100" =>
	            for byte_index in 0 to (C_S_AXI_DATA_WIDTH/8-1) loop
	              if ( S_AXI_WSTRB(byte_index) = '1' ) then
	                -- Respective byte enables are asserted as per write strobes                   
	                -- slave registor 3
	                slv_reg04(byte_index*8+7 downto byte_index*8) <= S_AXI_WDATA(byte_index*8+7 downto byte_index*8);
	              end if;
	            end loop;
              when b"0101" =>
	            for byte_index in 0 to (C_S_AXI_DATA_WIDTH/8-1) loop
	              if ( S_AXI_WSTRB(byte_index) = '1' ) then
	                -- Respective byte enables are asserted as per write strobes                   
	                -- slave registor 3
	                slv_reg05(byte_index*8+7 downto byte_index*8) <= S_AXI_WDATA(byte_index*8+7 downto byte_index*8);
	              end if;
	            end loop;
			  when b"0110" =>
	            for byte_index in 0 to (C_S_AXI_DATA_WIDTH/8-1) loop
	              if ( S_AXI_WSTRB(byte_index) = '1' ) then
	                -- Respective byte enables are asserted as per write strobes                   
	                -- slave registor 3
	                slv_reg06(byte_index*8+7 downto byte_index*8) <= S_AXI_WDATA(byte_index*8+7 downto byte_index*8);
	              end if;
	            end loop;
			  when b"0111" =>
	            for byte_index in 0 to (C_S_AXI_DATA_WIDTH/8-1) loop
	              if ( S_AXI_WSTRB(byte_index) = '1' ) then
	                -- Respective byte enables are asserted as per write strobes                   
	                -- slave registor 3
	                slv_reg07(byte_index*8+7 downto byte_index*8) <= S_AXI_WDATA(byte_index*8+7 downto byte_index*8);
	              end if;
	            end loop;
			  when b"1000" =>
	            for byte_index in 0 to (C_S_AXI_DATA_WIDTH/8-1) loop
	              if ( S_AXI_WSTRB(byte_index) = '1' ) then
	                -- Respective byte enables are asserted as per write strobes                   
	                -- slave registor 3
	                slv_reg08(byte_index*8+7 downto byte_index*8) <= S_AXI_WDATA(byte_index*8+7 downto byte_index*8);
	              end if;
	            end loop;
			  when b"1001" =>
	            for byte_index in 0 to (C_S_AXI_DATA_WIDTH/8-1) loop
	              if ( S_AXI_WSTRB(byte_index) = '1' ) then
	                -- Respective byte enables are asserted as per write strobes                   
	                -- slave registor 3
	                slv_reg09(byte_index*8+7 downto byte_index*8) <= S_AXI_WDATA(byte_index*8+7 downto byte_index*8);
	              end if;
	            end loop;
			  when b"1010" =>
	            for byte_index in 0 to (C_S_AXI_DATA_WIDTH/8-1) loop
	              if ( S_AXI_WSTRB(byte_index) = '1' ) then
	                -- Respective byte enables are asserted as per write strobes                   
	                -- slave registor 3
	                slv_reg10(byte_index*8+7 downto byte_index*8) <= S_AXI_WDATA(byte_index*8+7 downto byte_index*8);
	              end if;
	            end loop;
			  when b"1011" =>
	            for byte_index in 0 to (C_S_AXI_DATA_WIDTH/8-1) loop
	              if ( S_AXI_WSTRB(byte_index) = '1' ) then
	                -- Respective byte enables are asserted as per write strobes                   
	                -- slave registor 3
	                slv_reg11(byte_index*8+7 downto byte_index*8) <= S_AXI_WDATA(byte_index*8+7 downto byte_index*8);
	              end if;
	            end loop;
			  when b"1100" =>
	            for byte_index in 0 to (C_S_AXI_DATA_WIDTH/8-1) loop
	              if ( S_AXI_WSTRB(byte_index) = '1' ) then
	                -- Respective byte enables are asserted as per write strobes                   
	                -- slave registor 3
	                slv_reg12(byte_index*8+7 downto byte_index*8) <= S_AXI_WDATA(byte_index*8+7 downto byte_index*8);
	              end if;
	            end loop;
			  when b"1101" =>
	            for byte_index in 0 to (C_S_AXI_DATA_WIDTH/8-1) loop
	              if ( S_AXI_WSTRB(byte_index) = '1' ) then
	                -- Respective byte enables are asserted as per write strobes                   
	                -- slave registor 3
	                slv_reg13(byte_index*8+7 downto byte_index*8) <= S_AXI_WDATA(byte_index*8+7 downto byte_index*8);
	              end if;
	            end loop;
			  when b"1110" =>
	            for byte_index in 0 to (C_S_AXI_DATA_WIDTH/8-1) loop
	              if ( S_AXI_WSTRB(byte_index) = '1' ) then
	                -- Respective byte enables are asserted as per write strobes                   
	                -- slave registor 3
	                slv_reg14(byte_index*8+7 downto byte_index*8) <= S_AXI_WDATA(byte_index*8+7 downto byte_index*8);
	              end if;
	            end loop;
			  when b"1111" =>
	            for byte_index in 0 to (C_S_AXI_DATA_WIDTH/8-1) loop
	              if ( S_AXI_WSTRB(byte_index) = '1' ) then
	                -- Respective byte enables are asserted as per write strobes                   
	                -- slave registor 3
	                slv_reg15(byte_index*8+7 downto byte_index*8) <= S_AXI_WDATA(byte_index*8+7 downto byte_index*8);
	              end if;
	            end loop;
	          when others =>
	            slv_reg00 <= slv_reg00;
	            slv_reg01 <= slv_reg01;
	            slv_reg02 <= slv_reg02;
	            slv_reg03 <= slv_reg03;
	            slv_reg04 <= slv_reg04;
	            slv_reg05 <= slv_reg05;
	            slv_reg06 <= slv_reg06;
	            slv_reg07 <= slv_reg07;
	            slv_reg08 <= slv_reg08;
	            slv_reg09 <= slv_reg09;
	            slv_reg10 <= slv_reg10;
	            slv_reg11 <= slv_reg11;
	            slv_reg12 <= slv_reg12;
	            slv_reg13 <= slv_reg13;
	            slv_reg14 <= slv_reg14;
	            slv_reg15 <= slv_reg15;
	        end case;
	      end if;
	    end if;
	  end if;                   
	end process; 

	-- Implement write response logic generation
	-- The write response and response valid signals are asserted by the slave 
	-- when axi_wready, S_AXI_WVALID, axi_wready and S_AXI_WVALID are asserted.  
	-- This marks the acceptance of address and indicates the status of 
	-- write transaction.

	process (S_AXI_ACLK)
	begin
	  if rising_edge(S_AXI_ACLK) then 
	    if S_AXI_ARESETN = '0' then
	      axi_bvalid  <= '0';
	      axi_bresp   <= "00"; --need to work more on the responses
	    else
	      if (axi_awready = '1' and S_AXI_AWVALID = '1' and axi_wready = '1' and S_AXI_WVALID = '1' and axi_bvalid = '0'  ) then
	        axi_bvalid <= '1';
	        axi_bresp  <= "00"; 
	      elsif (S_AXI_BREADY = '1' and axi_bvalid = '1') then   --check if bready is asserted while bvalid is high)
	        axi_bvalid <= '0';                                 -- (there is a possibility that bready is always asserted high)
	      end if;
	    end if;
	  end if;                   
	end process; 

	-- Implement axi_arready generation
	-- axi_arready is asserted for one S_AXI_ACLK clock cycle when
	-- S_AXI_ARVALID is asserted. axi_awready is 
	-- de-asserted when reset (active low) is asserted. 
	-- The read address is also latched when S_AXI_ARVALID is 
	-- asserted. axi_araddr is reset to zero on reset assertion.

	process (S_AXI_ACLK)
	begin
	  if rising_edge(S_AXI_ACLK) then 
	    if S_AXI_ARESETN = '0' then
	      axi_arready <= '0';
	      axi_araddr  <= (others => '1');
	    else
	      if (axi_arready = '0' and S_AXI_ARVALID = '1') then
	        -- indicates that the slave has acceped the valid read address
	        axi_arready <= '1';
	        -- Read Address latching 
	        axi_araddr  <= S_AXI_ARADDR;           
	      else
	        axi_arready <= '0';
	      end if;
	    end if;
	  end if;                   
	end process; 

	-- Implement axi_arvalid generation
	-- axi_rvalid is asserted for one S_AXI_ACLK clock cycle when both 
	-- S_AXI_ARVALID and axi_arready are asserted. The slave registers 
	-- data are available on the axi_rdata bus at this instance. The 
	-- assertion of axi_rvalid marks the validity of read data on the 
	-- bus and axi_rresp indicates the status of read transaction.axi_rvalid 
	-- is deasserted on reset (active low). axi_rresp and axi_rdata are 
	-- cleared to zero on reset (active low).  
	process (S_AXI_ACLK)
	begin
	  if rising_edge(S_AXI_ACLK) then
	    if S_AXI_ARESETN = '0' then
	      axi_rvalid <= '0';
	      axi_rresp  <= "00";
	    else
	      if (axi_arready = '1' and S_AXI_ARVALID = '1' and axi_rvalid = '0') then
	        -- Valid read data is available at the read data bus
	        axi_rvalid <= '1';
	        axi_rresp  <= "00"; -- 'OKAY' response
	      elsif (axi_rvalid = '1' and S_AXI_RREADY = '1') then
	        -- Read data is accepted by the master
	        axi_rvalid <= '0';
	      end if;            
	    end if;
	  end if;
	end process;

	-- Implement memory mapped register select and read logic generation
	-- Slave register read enable is asserted when valid address is available
	-- and the slave is ready to accept the read address.
	slv_reg_rden <= axi_arready and S_AXI_ARVALID and (not axi_rvalid) ;

	process (slv_reg0, slv_reg1, slv_reg2, slv_reg3, axi_araddr, S_AXI_ARESETN, slv_reg_rden)
	variable loc_addr :std_logic_vector(OPT_MEM_ADDR_BITS downto 0);
	begin
	    -- Address decoding for reading registers
	    loc_addr := axi_araddr(ADDR_LSB + OPT_MEM_ADDR_BITS downto ADDR_LSB);
	    case loc_addr is
	      when b"0000" =>
	        reg_data_out <= slv_reg00;
	      when b"0001" =>
	        reg_data_out <= dat1_sample;  --slv_reg01; -- read the data sample in the PS side
	      when b"0010" =>
	        reg_data_out <= slv_reg02;  -- read the data sample in the PS side
	      when b"0011" =>
	        reg_data_out <= dat2_sample;  --slv_reg03;
		  when b"0100" =>
	        reg_data_out <= slv_reg04;
		  when b"0101" =>
	        reg_data_out <= dat3_sample;  --slv_reg05;
		  when b"0110" =>
	        reg_data_out <= slv_reg06;
		  when b"0111" =>
	        reg_data_out <= dat4_sample;  --slv_reg07;
		  when b"1000" =>
	        reg_data_out <= slv_reg08;
		  when b"1001" =>
	        reg_data_out <= dat5_sample;  --slv_reg09;
		  when b"1010" =>
	        reg_data_out <= slv_reg10;
		  when b"1011" =>
	        reg_data_out <= dat6_sample;  --slv_reg11;
		  when b"1100" =>
	        reg_data_out <= slv_reg12;
		  when b"1101" =>
	        reg_data_out <= dat7_sample;  --slv_reg13;
		  when b"1110" =>
	        reg_data_out <= slv_reg14;
		  when b"1111" =>
	        reg_data_out <= dat8_sample;  --slv_reg15;
	      when others =>
	        reg_data_out  <= (others => '0');
	    end case;
	end process; 

	-- Output register or memory read data
	process( S_AXI_ACLK ) is
	begin
	  if (rising_edge (S_AXI_ACLK)) then
	    if ( S_AXI_ARESETN = '0' ) then
	      axi_rdata  <= (others => '0');
	    else
	      if (slv_reg_rden = '1') then
	        -- When there is a valid read address (S_AXI_ARVALID) with 
	        -- acceptance of read address by the slave (axi_arready), 
	        -- output the read dada 
	        -- Read address mux
	          axi_rdata <= reg_data_out;     -- register read data
	      end if;   
	    end if;
	  end if;
	end process;


	-- Add user logic here
	--**************************************************
	---- Parte agregada por Fabian
	--**************************************************

	-- component afe_fclk_single
	afe_fclk_single_comp: component afe_fclk_single
    port map ( 
		fclk_in_p   =>  afe_fclk_p,
        fclk_in_n   =>  afe_fclk_n,
		fclk_raw    =>  fclk_raw,
        fclk_out    =>  fclk_out
	);

	-- component afe_fclk_single
	afe_dat1_single_comp: component afe_data_single
    port map ( 
		data_in_p   =>  afe_dat1_p,
		data_in_n   =>  afe_dat1_n,
        data_out    =>  dat1_out
    );	
	-- component afe_fclk_single
	afe_dat2_single_comp: component afe_data_single
    port map ( 
		data_in_p   =>  afe_dat2_p,
		data_in_n   =>  afe_dat2_n,
        data_out    =>  dat2_out
    );
	-- component afe_fclk_single
	afe_dat3_single_comp: component afe_data_single
    port map ( 
		data_in_p   =>  afe_dat3_p,
		data_in_n   =>  afe_dat3_n,
        data_out    =>  dat3_out
    );
	-- component afe_fclk_single
	afe_dat4_single_comp: component afe_data_single
    port map ( 
		data_in_p   =>  afe_dat4_p,
		data_in_n   =>  afe_dat4_n,
        data_out    =>  dat4_out
    );
	-- component afe_fclk_single
	afe_dat5_single_comp: component afe_data_single
    port map ( 
		data_in_p   =>  afe_dat5_p,
		data_in_n   =>  afe_dat5_n,
        data_out    =>  dat5_out
    );
	-- component afe_fclk_single
	afe_dat6_single_comp: component afe_data_single
    port map ( 
		data_in_p   =>  afe_dat6_p,
		data_in_n   =>  afe_dat6_n,
        data_out    =>  dat6_out
    );
	-- component afe_fclk_single
	afe_dat7_single_comp: component afe_data_single
    port map ( 
		data_in_p   =>  afe_dat7_p,
		data_in_n   =>  afe_dat7_n,
        data_out    =>  dat7_out
    );
	-- component afe_fclk_single
	afe_dat8_single_comp: component afe_data_single
    port map ( 
		data_in_p   =>  afe_dat8_p,
		data_in_n   =>  afe_dat8_n,
        data_out    =>  dat8_out
    );
	
	-- component afe_dclk_source
	afe_dclk_source_comp: component afe_dclk_source
    port map ( 
		rst         =>  rst,
        fclk_in     =>  fclk_raw,
        dclk_out    =>  dclk_out
    );
	
	-- component afe_deserializer
	afe_deserializer_1_comp: component afe_deserializer
    port map ( 
        rst         =>  rst,
        fclk        =>  fclk_out,
        dclk        =>  dclk_out,
        data_in     =>  dat1_out,
        sample      =>  dat1_sample,
        valid       =>  open,
        Q           =>  open,
        T           =>  open
    );
	-- component afe_deserializer
	afe_deserializer_2_comp: component afe_deserializer
    port map ( 
        rst         =>  rst,
        fclk        =>  fclk_out,
        dclk        =>  dclk_out,
        data_in     =>  dat2_out,
        sample      =>  dat2_sample,
        valid       =>  open,
        Q           =>  open,
        T           =>  open
    );
	-- component afe_deserializer
	afe_deserializer_3_comp: component afe_deserializer
    port map ( 
        rst         =>  rst,
        fclk        =>  fclk_out,
        dclk        =>  dclk_out,
        data_in     =>  dat3_out,
        sample      =>  dat3_sample,
        valid       =>  open,
        Q           =>  open,
        T           =>  open
    );
	-- component afe_deserializer
	afe_deserializer_4_comp: component afe_deserializer
    port map ( 
        rst         =>  rst,
        fclk        =>  fclk_out,
        dclk        =>  dclk_out,
        data_in     =>  dat4_out,
        sample      =>  dat4_sample,
        valid       =>  open,
        Q           =>  open,
        T           =>  open
    );
	-- component afe_deserializer
	afe_deserializer_5_comp: component afe_deserializer
    port map ( 
        rst         =>  rst,
        fclk        =>  fclk_out,
        dclk        =>  dclk_out,
        data_in     =>  dat5_out,
        sample      =>  dat5_sample,
        valid       =>  open,
        Q           =>  open,
        T           =>  open
    );
	-- component afe_deserializer
	afe_deserializer_6_comp: component afe_deserializer
    port map ( 
        rst         =>  rst,
        fclk        =>  fclk_out,
        dclk        =>  dclk_out,
        data_in     =>  dat6_out,
        sample      =>  dat6_sample,
        valid       =>  open,
        Q           =>  open,
        T           =>  open
    );
	-- component afe_deserializer
	afe_deserializer_7_comp: component afe_deserializer
    port map ( 
        rst         =>  rst,
        fclk        =>  fclk_out,
        dclk        =>  dclk_out,
        data_in     =>  dat7_out,
        sample      =>  dat7_sample,
        valid       =>  open,
        Q           =>  open,
        T           =>  open
    );
	-- component afe_deserializer
	afe_deserializer_8_comp: component afe_deserializer
    port map ( 
        rst         =>  rst,
        fclk        =>  fclk_out,
        dclk        =>  dclk_out,
        data_in     =>  dat8_out,
        sample      =>  dat8_sample,
        valid       =>  open,
        Q           =>  open,
        T           =>  open
    );

	-- component afe_slice_data
	afe_slice_dat1_comp: component afe_slice_data
    port map ( 
        data_in     =>  dat1_sample,
        rst         =>  rst,
        fclk        =>  fclk_out,
        dclk        =>  dclk_out,
        delay       =>  slv_reg00(3 downto 0),
        sel         =>  slv_reg00(7 downto 4),
        data_out    =>  afe_d1_out
    );
	-- component afe_slice_data
	afe_slice_dat2_comp: component afe_slice_data
    port map ( 
        data_in     =>  dat2_sample,
        rst         =>  rst,
        fclk        =>  fclk_out,
        dclk        =>  dclk_out,
        delay       =>  slv_reg02(3 downto 0),
        sel         =>  slv_reg02(7 downto 4),
        data_out    =>  afe_d2_out
    );
	-- component afe_slice_data
	afe_slice_dat3_comp: component afe_slice_data
    port map ( 
        data_in     =>  dat3_sample,
        rst         =>  rst,
        fclk        =>  fclk_out,
        dclk        =>  dclk_out,
        delay       =>  slv_reg04(3 downto 0),
        sel         =>  slv_reg04(7 downto 4),
        data_out    =>  afe_d3_out
    );
	-- component afe_slice_data
	afe_slice_dat4_comp: component afe_slice_data
    port map ( 
        data_in     =>  dat4_sample,
        rst         =>  rst,
        fclk        =>  fclk_out,
        dclk        =>  dclk_out,
        delay       =>  slv_reg06(3 downto 0),
        sel         =>  slv_reg06(7 downto 4),
        data_out    =>  afe_d4_out
    );
	-- component afe_slice_data
	afe_slice_dat5_comp: component afe_slice_data
    port map ( 
        data_in     =>  dat5_sample,
        rst         =>  rst,
        fclk        =>  fclk_out,
        dclk        =>  dclk_out,
        delay       =>  slv_reg08(3 downto 0),
        sel         =>  slv_reg08(7 downto 4),
        data_out    =>  afe_d5_out
    );
	-- component afe_slice_data
	afe_slice_dat6_comp: component afe_slice_data
    port map ( 
        data_in     =>  dat6_sample,
        rst         =>  rst,
        fclk        =>  fclk_out,
        dclk        =>  dclk_out,
        delay       =>  slv_reg10(3 downto 0),
        sel         =>  slv_reg10(7 downto 4),
        data_out    =>  afe_d6_out
    );
	-- component afe_slice_data
	afe_slice_dat7_comp: component afe_slice_data
    port map ( 
        data_in     =>  dat7_sample,
        rst         =>  rst,
        fclk        =>  fclk_out,
        dclk        =>  dclk_out,
        delay       =>  slv_reg12(3 downto 0),
        sel         =>  slv_reg12(7 downto 4),
        data_out    =>  afe_d7_out
    );
	-- component afe_slice_data
	afe_slice_dat8_comp: component afe_slice_data
    port map ( 
        data_in     =>  dat8_sample,
        rst         =>  rst,
        fclk        =>  fclk_out,
        dclk        =>  dclk_out,
        delay       =>  slv_reg14(3 downto 0),
        sel         =>  slv_reg14(7 downto 4),
        data_out    =>  afe_d8_out
    );
        
    -- direccionamiento de salidas
    afe_fclk_out <= fclk_out;
    afe_dclk_out <= dclk_out;

    -- Dato deserializado
    afe_dat1_out <= afe_d1_out;
	afe_dat2_out <= afe_d2_out;
	afe_dat3_out <= afe_d3_out;
	afe_dat4_out <= afe_d4_out;
	afe_dat5_out <= afe_d5_out;
	afe_dat6_out <= afe_d6_out;
	afe_dat7_out <= afe_d7_out;
	afe_dat8_out <= afe_d8_out;


	--**************************************************
	---- Final Parte agregada por Fabian
	--**************************************************

	-- User logic ends

end arch_imp;
