/*
 * name:        A3G4250D
 * description: MEMS motion sensor: 3-axis digital output gyroscope
 * manuf:       STMicroelectronics
 * version:     Version 0.1
 * url:         http://www.st.com/resource/en/datasheet/a3g4250d.pdf
 * date:        2018-01-23
 * author       https://chisl.io/
 * file:        A3G4250D.hpp
 */

/*                                                                                                       *
 *                                   THIS FILE IS AUTOMATICALLY CREATED                                  *
 *                                    D O     N O T     M O D I F Y  !                                   *
 *                                                                                                       */

#include <cinttypes>

/* Derive from class A3G4250D_Base and implement the read and write functions! */

/* A3G4250D: MEMS motion sensor: 3-axis digital output gyroscope */
class A3G4250D_Base
{
public:
	/* Pure virtual functions that need to be implemented in derived class: */
	virtual uint8_t read8(uint16_t address, uint16_t n=8) = 0;  // 8 bit read
	virtual void write(uint16_t address, uint8_t value, uint16_t n=8) = 0;  // 8 bit write
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                           REG WHO_AM_I                                            *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG WHO_AM_I:
	 * 7.1
	 * Device identification register.
	 */
	struct WHO_AM_I
	{
		static const uint16_t __address = 15;
		
		/* Bits WHO_AM_I: */
		struct WHO_AM_I_
		{
			/* MODE r */
			static const uint8_t dflt = 0b11010011; // 8'b11010011
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register WHO_AM_I */
	void setWHO_AM_I(uint8_t value)
	{
		write(WHO_AM_I::__address, value, 8);
	}
	
	/* Get register WHO_AM_I */
	uint8_t getWHO_AM_I()
	{
		return read8(WHO_AM_I::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG CTRL_REG1                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG CTRL_REG1:
	 * 7.2
	 * In the following table (Table 22) all frequencies resulting in a combination of
	 * DR / BW bits are reported. ODR in Hz.
	 * DR  BW  ODR  Cut-off
	 * 00  00  100  12.5
	 * 00  01  100  25
	 * 00  10  100  25
	 * 00  11  100  25
	 * 01  00  200  12.5
	 * 01  01  200  25
	 * 01  10  200  50
	 * 01  11  200  70
	 * 10  00  400  20
	 * 10  01  400  25
	 * 10  10  400  50
	 * 10  11  400  110
	 * 11  00  800  30
	 * 11  01  800  35
	 * 11  10  800  50
	 * 11  11  800  110
	 * Combination of PD, Zen, Yen, and Xen are used to set the device in different modes
	 * (power-down / normal / sleep mode) according to the following table.
	 * Table 23.     Power mode selection configuration
	 * Mode	      PD Zen Yen Xen
	 * Power-down  0	   -   -   -
	 * Sleep       1	   0   0   0
	 * Normal      1    -   -   -
	 */
	struct CTRL_REG1
	{
		static const uint16_t __address = 32;
		
		/* Bits DR: */
		/*
		 * DR1-DR0: Output data rate selection. Refer to Table 22
		 * DR<1:0> is used to set ODR selection.
		 */
		struct DR
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b11000000; // [6,7]
		};
		/* Bits BW: */
		/*
		 * Bandwidth selection. Refer to Table 22
		 * BW <1:0> is used to set Bandwidth selection.
		 */
		struct BW
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b00110000; // [4,5]
		};
		/* Bits PD: */
		/* Power-down mode enable. */
		struct PD
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00001000; // [3]
			static const uint8_t POWER_DOWN = 0b0; // power-down mode
			static const uint8_t NORMAL = 0b1; // normal mode or sleep mode
		};
		/* Bits Zen: */
		/* Z-axis enable.  */
		struct Zen
		{
			/* MODE rw */
			static const uint8_t dflt = 0b1; // 1'b1
			static const uint8_t mask = 0b00000100; // [2]
			static const uint8_t DISABLED = 0b0; // Z-axis disabled
			static const uint8_t ENABLED = 0b1; // Z-axis enabled
		};
		/* Bits Yen: */
		/* Y-axis enable.  */
		struct Yen
		{
			/* MODE rw */
			static const uint8_t dflt = 0b1; // 1'b1
			static const uint8_t mask = 0b00000010; // [1]
			static const uint8_t DISABLED = 0b0; // Y-axis disabled
			static const uint8_t ENABLED = 0b1; // Y-axis enabled
		};
		/* Bits Xen: */
		/* X-axis enable.  */
		struct Xen
		{
			/* MODE rw */
			static const uint8_t dflt = 0b1; // 1'b1
			static const uint8_t mask = 0b00000001; // [0]
			static const uint8_t DISABLED = 0b0; // X-axis disabled
			static const uint8_t ENABLED = 0b1; // X-axis enabled
		};
	};
	
	/* Set register CTRL_REG1 */
	void setCTRL_REG1(uint8_t value)
	{
		write(CTRL_REG1::__address, value, 8);
	}
	
	/* Get register CTRL_REG1 */
	uint8_t getCTRL_REG1()
	{
		return read8(CTRL_REG1::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG CTRL_REG2                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG CTRL_REG2:
	 * 7.3
	 * 1.   Value loaded at boot.
	 */
	struct CTRL_REG2
	{
		static const uint16_t __address = 33;
		
		/* Bits reserved_0: */
		/* These values must not be changed.  */
		struct reserved_0
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b11000000; // [6,7]
		};
		/* Bits HPM1: */
		/* High-pass filter mode selection.  */
		struct HPM1
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b00110000; // [4,5]
			static const uint8_t NORMAL = 0b00; // Normal mode (reset reading HP_RESET_FILTER)
			static const uint8_t REFERENCE_SIGNAL = 0b01; // Reference signal for filtering
			static const uint8_t NORMAL2 = 0b10; // Normal mode
			static const uint8_t AUTO_RESET = 0b11; // Auto-reset on interrupt event
		};
		/* Bits HPCF: */
		/*
		 * High-pass filter cut-off frequency selection
		 * Table 27.     High-pass filter cut-off frequency configuration [Hz]
		 * -----ODR/Hz----
		 * HPCF  100 200   400  800
		 * 0000	8     15   30   56
		 * 0001	4      8    5   30
		 * 0010	2      4    8   15
		 * 0011	1      2    4    8
		 * 0100	0.5    1    2    4
		 * 0101	0.2	 0.5    1    2
		 * 0110	0.1	 0.2  0.5    1
		 * 0111	0.05 0.1  0.2  0.5
		 * 1000	0.02 0.05 0.1  0.2
		 * 1001	0.01 0.02 0.05 0.1
		 */
		struct HPCF
		{
			/* MODE rw */
			static const uint8_t mask = 0b00001111; // [0,1,2,3]
		};
	};
	
	/* Set register CTRL_REG2 */
	void setCTRL_REG2(uint8_t value)
	{
		write(CTRL_REG2::__address, value, 8);
	}
	
	/* Get register CTRL_REG2 */
	uint8_t getCTRL_REG2()
	{
		return read8(CTRL_REG2::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG CTRL_REG3                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG CTRL_REG3:
	 * 7.4
	 */
	struct CTRL_REG3
	{
		static const uint16_t __address = 34;
		
		/* Bits I1_Int1: */
		/* Interrupt enable on the INT1 pin.  */
		struct I1_Int1
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'd0
			static const uint8_t mask = 0b10000000; // [7]
			static const uint8_t DISABLE = 0b0; // 
			static const uint8_t ENABLE = 0b1; // 
		};
		/* Bits I1_Boot: */
		/* Boot status available on INT1.  */
		struct I1_Boot
		{
			/* MODE rw */
			static const uint8_t mask = 0b01000000; // [6]
		};
		/* Bits H_Lactive: */
		/* Interrupt active configuration on INT1.  */
		struct H_Lactive
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'd0
			static const uint8_t mask = 0b00100000; // [5]
			static const uint8_t HIGH = 0b0; // 
			static const uint8_t LOW = 0b1; // 
		};
		/* Bits PP_OD: */
		/* Push-pull / open drain.  */
		struct PP_OD
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'd0
			static const uint8_t mask = 0b00010000; // [4]
			static const uint8_t PUSH_PULL = 0b0; // 
			static const uint8_t OPEN_DRAIN = 0b1; // 
		};
		/* Bits I2_DRDY: */
		/* Date ready on DRDY/INT2.  */
		struct I2_DRDY
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'd0
			static const uint8_t mask = 0b00001000; // [3]
			static const uint8_t DISABLE = 0b0; // 
			static const uint8_t ENABLE = 0b1; // 
		};
		/* Bits I2_WTM: */
		/* FIFO watermark interrupt on DRDY/INT2.  */
		struct I2_WTM
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'd0
			static const uint8_t mask = 0b00000100; // [2]
			static const uint8_t DISABLE = 0b0; // 
			static const uint8_t ENABLE = 0b1; // 
		};
		/* Bits I2_ORun: */
		/* FIFO overrun interrupt on DRDY/INT2.  */
		struct I2_ORun
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'd0
			static const uint8_t mask = 0b00000010; // [1]
			static const uint8_t DISABLE = 0b0; // 
			static const uint8_t ENABLE = 0b1; // 
		};
		/* Bits I2_Empty: */
		/* FIFO empty interrupt on DRDY/INT2.  */
		struct I2_Empty
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'd0
			static const uint8_t mask = 0b00000001; // [0]
			static const uint8_t DISABLE = 0b0; // 
			static const uint8_t ENABLE = 0b1; // 
		};
	};
	
	/* Set register CTRL_REG3 */
	void setCTRL_REG3(uint8_t value)
	{
		write(CTRL_REG3::__address, value, 8);
	}
	
	/* Get register CTRL_REG3 */
	uint8_t getCTRL_REG3()
	{
		return read8(CTRL_REG3::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG CTRL_REG4                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG CTRL_REG4:
	 * 7.5
	 */
	struct CTRL_REG4
	{
		static const uint16_t __address = 35;
		
		/* Bits unused_0: */
		struct unused_0
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'd0
			static const uint8_t mask = 0b10000000; // [7]
		};
		/* Bits BLE: */
		/* Big/little endian data selection.  */
		struct BLE
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'd0
			static const uint8_t mask = 0b01000000; // [6]
			static const uint8_t LSB = 0b0; // data LSB @ lower address
			static const uint8_t MSB = 0b1; // data MSB @ lower address
		};
		/* Bits unused_1: */
		struct unused_1
		{
			/* MODE rw */
			static const uint8_t dflt = 0b000; // 3'b0
			static const uint8_t mask = 0b00111000; // [3,4,5]
		};
		/* Bits ST: */
		/* Self-test enable.  */
		struct ST
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b00000110; // [1,2]
			static const uint8_t NORMAL_MODE = 0b00; // 
			static const uint8_t SELF_TEST_0 = 0b01; // 
			static const uint8_t unused_0 = 0b10; // 
			static const uint8_t SELF_TEST_1 = 0b11; // 
		};
		/* Bits SIM: */
		/* SPI serial interface mode selection.  */
		struct SIM
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'd0
			static const uint8_t mask = 0b00000001; // [0]
			static const uint8_t SPI_4_WIRE = 0b0; // 4-wire interface
			static const uint8_t SPI_3_WIRE = 0b1; // 3-wire interface
		};
	};
	
	/* Set register CTRL_REG4 */
	void setCTRL_REG4(uint8_t value)
	{
		write(CTRL_REG4::__address, value, 8);
	}
	
	/* Get register CTRL_REG4 */
	uint8_t getCTRL_REG4()
	{
		return read8(CTRL_REG4::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG CTRL_REG5                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG CTRL_REG5:
	 * 7.6
	 */
	struct CTRL_REG5
	{
		static const uint16_t __address = 36;
		
		/* Bits BOOT: */
		/* Reboot memory content.  */
		struct BOOT
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'd0
			static const uint8_t mask = 0b10000000; // [7]
			static const uint8_t MORMAL_MODE = 0b0; // 
			static const uint8_t REBOOT_MEMORY_CONTENT = 0b1; // 
		};
		/* Bits FIFO_EN: */
		/* FIFO enable.  */
		struct FIFO_EN
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'd0
			static const uint8_t mask = 0b01000000; // [6]
			static const uint8_t FIFO_DISABLE = 0b0; // 
			static const uint8_t FIFO_ENABLE = 0b1; // 
		};
		/* Bits unused_0: */
		struct unused_0
		{
			/* MODE rw */
			static const uint8_t mask = 0b00100000; // [5]
		};
		/* Bits HPen: */
		/* High-pass filter enable.  */
		struct HPen
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'd0
			static const uint8_t mask = 0b00010000; // [4]
			static const uint8_t HPG_DISABLED = 0b0; // 
			static const uint8_t HPF_ENABLED = 0b1; // 
		};
		/* Bits INT1_Sel: */
		/*
		 * INT1 selection configuration. (see Figure 19)
		 * Table 36.     INT_SEL configuration settings
		 * Hpen  INT_SEL1  INT_SEL2	Description
		 * x     0         0         Non-high-pass-filtered data are used for interrupt generation
		 * x     0         1         High-pass-filtered data are used for interrupt generation
		 * 0     1         x         Low-pass-filtered data are used for interrupt generation
		 * 1     1         x         High-pass and low-pass-filtered data are used for interrupt generation
		 */
		struct INT1_Sel
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b00001100; // [2,3]
		};
		/* Bits Out_Sel: */
		/*
		 * Out selection configuration. (see Figure 19)
		 * Table 35.     Out_Sel configuration settings
		 * Hpen	OUT_SEL1 OUT_SEL0 Description
		 * x	    0        0        Data in DataReg and FIFO are non-high- pass-filtered
		 * x     0        1        Data in DataReg and FIFO are high-pass- filtered
		 * 0     1        x        Data in DataReg and FIFO are low-pass- filtered by LPF2
		 * 1     1        x        Data in DataReg and FIFO are high-pass and low-pass-filtered by LPF2
		 */
		struct Out_Sel
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b00000011; // [0,1]
		};
	};
	
	/* Set register CTRL_REG5 */
	void setCTRL_REG5(uint8_t value)
	{
		write(CTRL_REG5::__address, value, 8);
	}
	
	/* Get register CTRL_REG5 */
	uint8_t getCTRL_REG5()
	{
		return read8(CTRL_REG5::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG REFERENCE                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG REFERENCE:
	 * 7.7 REFERENCE/DATACAPTURE
	 * Reference value for interrupt generation.
	 */
	struct REFERENCE
	{
		static const uint16_t __address = 37;
		
		/* Bits REFERENCE: */
		struct REFERENCE_
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00000000; // 8'd0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register REFERENCE */
	void setREFERENCE(uint8_t value)
	{
		write(REFERENCE::__address, value, 8);
	}
	
	/* Get register REFERENCE */
	uint8_t getREFERENCE()
	{
		return read8(REFERENCE::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                           REG OUT_TEMP                                            *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG OUT_TEMP:
	 * 7.8
	 * Temperature data.
	 */
	struct OUT_TEMP
	{
		static const uint16_t __address = 38;
		
		/* Bits OUT_TEMP: */
		struct OUT_TEMP_
		{
			/* MODE r */
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register OUT_TEMP */
	void setOUT_TEMP(uint8_t value)
	{
		write(OUT_TEMP::__address, value, 8);
	}
	
	/* Get register OUT_TEMP */
	uint8_t getOUT_TEMP()
	{
		return read8(OUT_TEMP::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG STATUS_REG                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG STATUS_REG:
	 * 7.9
	 */
	struct STATUS_REG
	{
		static const uint16_t __address = 39;
		
		/* Bits ZYXOR: */
		/* X, Y, Z-axis data overrun.  */
		struct ZYXOR
		{
			/* MODE r */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
			static const uint8_t NO_OVERRUN = 0b0; // no overrun has occurred
			static const uint8_t OVERWRITTEN_BFORE_READ = 0b1; // new data has overwritten the previous one before it was read
		};
		/* Bits ZOR: */
		/* Z-axis data overrun.  */
		struct ZOR
		{
			/* MODE r */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b01000000; // [6]
			static const uint8_t NO_OVERRUN = 0b0; // no overrun has occurred
			static const uint8_t OVERWRITTEN = 0b1; // a new data for the Z-axis has overwritten the previous one
		};
		/* Bits YOR: */
		/* Y-axis data overrun.  */
		struct YOR
		{
			/* MODE r */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00100000; // [5]
			static const uint8_t NO_OVERRUN = 0b0; // no overrun has occurred
			static const uint8_t OVERWRITTEN = 0b1; // a new data for the Y-axis has overwritten the previous one
		};
		/* Bits XOR: */
		/* X-axis data overrun.  */
		struct XOR
		{
			/* MODE r */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00010000; // [4]
			static const uint8_t NO_OVERRUN = 0b0; // no overrun has occurred
			static const uint8_t OVERWRITTEN = 0b1; // a new data for the X-axis has overwritten the previous one
		};
		/* Bits ZYXDA: */
		/* X, Y, Z-axis new data available.  */
		struct ZYXDA
		{
			/* MODE r */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00001000; // [3]
			static const uint8_t NO_DATA_AVAILABLE = 0b0; // a new set of data is not yet available
			static const uint8_t DATA_AVAILABLE = 0b1; // a new set of data is available
		};
		/* Bits ZDA: */
		/* Z-axis new data available.  */
		struct ZDA
		{
			/* MODE r */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000100; // [2]
			static const uint8_t NO_DATA_AVAILABLE = 0b0; // a new data for the Z-axis is not yet available
			static const uint8_t DATA_AVAILABLE = 0b1; // a new data for the Z-axis is available
		};
		/* Bits YDA: */
		/* Y-axis new data available.  */
		struct YDA
		{
			/* MODE r */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000010; // [1]
			static const uint8_t NO_DATA_AVAILABLE = 0b0; // a new data for the Y-axis is not yet available
			static const uint8_t DATA_AVAILABLE = 0b1; // a new data for the Y-axis is available
		};
		/* Bits XDA: */
		/* X-axis new data available.  */
		struct XDA
		{
			/* MODE r */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
			static const uint8_t NO_DATA_AVAILABLE = 0b0; // a new data for the X-axis is not yet available
			static const uint8_t DATA_AVAILABLE = 0b1; // a new data for the X-axis is available
		};
	};
	
	/* Set register STATUS_REG */
	void setSTATUS_REG(uint8_t value)
	{
		write(STATUS_REG::__address, value, 8);
	}
	
	/* Get register STATUS_REG */
	uint8_t getSTATUS_REG()
	{
		return read8(STATUS_REG::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                           REG OUT_X_L                                            *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG OUT_X_L:
	 * 7.10
	 * X-axis angular rate data. The value is expressed as 2’s complement.
	 */
	struct OUT_X_L
	{
		static const uint16_t __address = 40;
		
		/* Bits OUT_X_L: */
		struct OUT_X_L_
		{
			/* MODE r */
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register OUT_X_L */
	void setOUT_X_L(uint8_t value)
	{
		write(OUT_X_L::__address, value, 8);
	}
	
	/* Get register OUT_X_L */
	uint8_t getOUT_X_L()
	{
		return read8(OUT_X_L::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                           REG OUT_Y_L                                            *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG OUT_Y_L:
	 * 7.11
	 * Y-axis angular rate data. The value is expressed as 2’s complement.
	 */
	struct OUT_Y_L
	{
		static const uint16_t __address = 42;
		
		/* Bits OUT_Y_L: */
		struct OUT_Y_L_
		{
			/* MODE r */
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register OUT_Y_L */
	void setOUT_Y_L(uint8_t value)
	{
		write(OUT_Y_L::__address, value, 8);
	}
	
	/* Get register OUT_Y_L */
	uint8_t getOUT_Y_L()
	{
		return read8(OUT_Y_L::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                           REG OUT_Z_L                                            *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG OUT_Z_L:
	 * 7.12
	 * Z-axis angular rate data. The value is expressed as 2’s complement.
	 */
	struct OUT_Z_L
	{
		static const uint16_t __address = 44;
		
		/* Bits OUT_Z_L: */
		struct OUT_Z_L_
		{
			/* MODE r */
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register OUT_Z_L */
	void setOUT_Z_L(uint8_t value)
	{
		write(OUT_Z_L::__address, value, 8);
	}
	
	/* Get register OUT_Z_L */
	uint8_t getOUT_Z_L()
	{
		return read8(OUT_Z_L::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                        REG FIFO_CTRL_REG                                         *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG FIFO_CTRL_REG:
	 * 7.13
	 */
	struct FIFO_CTRL_REG
	{
		static const uint16_t __address = 46;
		
		/* Bits FM: */
		/* FIFO mode selection.  */
		struct FM
		{
			/* MODE rw */
			static const uint8_t dflt = 0b000; // 3'b0
			static const uint8_t mask = 0b11100000; // [5,6,7]
			static const uint8_t BYPASS = 0b00; // Bypass mode
			static const uint8_t FIFO = 0b01; // FIFO mode
			static const uint8_t STREA = 0b10; // Stream mode §
		};
		/* Bits WTM: */
		/* FIFO threshold. Watermark level setting  */
		struct WTM
		{
			/* MODE rw */
			static const uint8_t mask = 0b00011111; // [0,1,2,3,4]
		};
	};
	
	/* Set register FIFO_CTRL_REG */
	void setFIFO_CTRL_REG(uint8_t value)
	{
		write(FIFO_CTRL_REG::__address, value, 8);
	}
	
	/* Get register FIFO_CTRL_REG */
	uint8_t getFIFO_CTRL_REG()
	{
		return read8(FIFO_CTRL_REG::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                         REG FIFO_SRC_REG                                          *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG FIFO_SRC_REG:
	 * 7.14
	 */
	struct FIFO_SRC_REG
	{
		static const uint16_t __address = 47;
		
		/* Bits WTM: */
		/* Watermark status.  */
		struct WTM
		{
			/* MODE r */
			static const uint8_t mask = 0b10000000; // [7]
			static const uint8_t LOWER_THAN_WTM = 0b0; // FIFO filling is lower than WTM level
			static const uint8_t AT_OR_ABOVE_WTM = 0b1; // FIFO filling is equal or higher than WTM level
		};
		/* Bits OVRN: */
		struct OVRN
		{
			/* MODE r */
			static const uint8_t mask = 0b01000000; // [6]
			static const uint8_t NOT_FILLED = 0b0; // FIFO is not completely filled
			static const uint8_t FILLED = 0b1; // FIFO is completely filled
		};
		/* Bits EMPTY: */
		/* FIFO empty bit  */
		struct EMPTY
		{
			/* MODE r */
			static const uint8_t mask = 0b00100000; // [5]
			static const uint8_t FIFO_NOT_EMPTY = 0b0; // 
			static const uint8_t FIFO_EMPTY = 0b1; // 
		};
		/* Bits FSS: */
		/* FIFO stored data level  */
		struct FSS
		{
			/* MODE r */
			static const uint8_t mask = 0b00011111; // [0,1,2,3,4]
		};
	};
	
	/* Set register FIFO_SRC_REG */
	void setFIFO_SRC_REG(uint8_t value)
	{
		write(FIFO_SRC_REG::__address, value, 8);
	}
	
	/* Get register FIFO_SRC_REG */
	uint8_t getFIFO_SRC_REG()
	{
		return read8(FIFO_SRC_REG::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                           REG INT1_CFG                                            *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG INT1_CFG:
	 * 7.15
	 * Configuration register for interrupt source.
	 */
	struct INT1_CFG
	{
		static const uint16_t __address = 48;
		
		/* Bits AND_OR: */
		/* AND/OR combination of interrupt events.  */
		struct AND_OR
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
			static const uint8_t OR = 0b0; // OR combination of interrupt events
			static const uint8_t AND = 0b1; // AND combination of interrupt events
		};
		/* Bits LIR: */
		/* Latch interrupt request.  */
		struct LIR
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b01000000; // [6]
			static const uint8_t NOT_LATCHED = 0b0; // interrupt request not latched
			static const uint8_t LATCHED = 0b1; // interrupt request latched. Cleared by reading the INT1_SRC reg.
		};
		/* Bits ZHIE: */
		/* Enable interrupt generation on Z high event.  */
		struct ZHIE
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00100000; // [5]
			static const uint8_t DISABLE = 0b0; // disable interrupt request
			static const uint8_t ENABLE = 0b1; // enable interrupt request on measured rate value higher than preset threshold
		};
		/* Bits ZLIE: */
		/* Enable interrupt generation on Z low event.  */
		struct ZLIE
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00010000; // [4]
			static const uint8_t DISABLE = 0b0; // disable interrupt request
			static const uint8_t ENABLE = 0b1; // enable interrupt request on measured rate value lower than preset threshold
		};
		/* Bits YHIE: */
		/* Enable interrupt generation on Y high event.  */
		struct YHIE
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00001000; // [3]
			static const uint8_t DISABLE = 0b0; // disable interrupt request
			static const uint8_t ENABLE = 0b1; // enable interrupt request on measured rate value higher than preset threshold
		};
		/* Bits YLIE: */
		/* Enable interrupt generation on Y low event.  */
		struct YLIE
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000100; // [2]
			static const uint8_t DISABLE = 0b0; // disable interrupt request
			static const uint8_t ENABLE = 0b1; // enable interrupt request on measured rate value lower than preset threshold
		};
		/* Bits XHIE: */
		/* Enable interrupt generation on X high event.  */
		struct XHIE
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000010; // [1]
			static const uint8_t DISABLE = 0b0; // disable interrupt request
			static const uint8_t ENABLE = 0b1; // enable interrupt request on measured rate value higher than preset threshold
		};
		/* Bits XLIE: */
		/* Enable interrupt generation on X low event.  */
		struct XLIE
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
			static const uint8_t DISABLE = 0b0; // disable interrupt request
			static const uint8_t ENABLE = 0b1; // enable interrupt request on measured rate value lower than preset threshold
		};
	};
	
	/* Set register INT1_CFG */
	void setINT1_CFG(uint8_t value)
	{
		write(INT1_CFG::__address, value, 8);
	}
	
	/* Get register INT1_CFG */
	uint8_t getINT1_CFG()
	{
		return read8(INT1_CFG::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                           REG INT1_SRC                                            *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG INT1_SRC:
	 * 7.16
	 * Interrupt source register.
	 * Reading at this address clears the INT1_SRC IA bit (and eventually the interrupt signal on the INT1 pin)
	 * and allows the refreshment of data in the INT1_SRC register if the latched option is chosen.
	 */
	struct INT1_SRC
	{
		static const uint16_t __address = 49;
		
		/* Bits unused_0: */
		struct unused_0
		{
			/* MODE r */
			static const uint8_t dflt = 0b0; // 1'd0
			static const uint8_t mask = 0b10000000; // [7]
		};
		/* Bits IA: */
		/* Interrupt active.  */
		struct IA
		{
			/* MODE r */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b01000000; // [6]
			static const uint8_t NO_INTERRUPT = 0b0; // no interrupt has been generated
			static const uint8_t INTERRUPT = 0b1; // one or more interrupts have been generated
		};
		/* Bits ZH: */
		/* Z high.  */
		struct ZH
		{
			/* MODE r */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00100000; // [5]
			static const uint8_t NO_INTERRUPT = 0b0; // no interrupt, 
			static const uint8_t INTERRUPT = 0b1; // Z high event has occurred
		};
		/* Bits ZL: */
		/* Z low.  */
		struct ZL
		{
			/* MODE r */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00010000; // [4]
			static const uint8_t NO_INTERRUPT = 0b0; // no interrupt
			static const uint8_t INTERRUPT = 0b1; // Z low event has occurred
		};
		/* Bits YH: */
		/* Y high.  */
		struct YH
		{
			/* MODE r */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00001000; // [3]
			static const uint8_t NO_INTERRUPT = 0b0; // no interrupt
			static const uint8_t INTERRUPT = 0b1; // Y high event has occurred
		};
		/* Bits YL: */
		/* Y low.  */
		struct YL
		{
			/* MODE r */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000100; // [2]
			static const uint8_t NO_INTERRUPT = 0b0; // no interrupt
			static const uint8_t INTERRUPT = 0b1; // Y low event has occurred
		};
		/* Bits XH: */
		/* X high.  */
		struct XH
		{
			/* MODE r */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000010; // [1]
			static const uint8_t NO_INTERRUPT = 0b0; // no interrupt
			static const uint8_t INTERRUPT = 0b1; // X high event has occurred
		};
		/* Bits XL: */
		/* X low.  */
		struct XL
		{
			/* MODE r */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
			static const uint8_t NO_INTERRUPT = 0b0; // no interrupt
			static const uint8_t INTERRUPT = 0b1; // X low event has occurred
		};
	};
	
	/* Set register INT1_SRC */
	void setINT1_SRC(uint8_t value)
	{
		write(INT1_SRC::__address, value, 8);
	}
	
	/* Get register INT1_SRC */
	uint8_t getINT1_SRC()
	{
		return read8(INT1_SRC::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                         REG INT1_THS_XH                                          *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG INT1_THS_XH:
	 * 7.17
	 * Table 53.     INT1_THS_XH description
	 * THSX14 - THSX9     Interrupt threshold. Default value: 0000 0000
	 */
	struct INT1_THS_XH
	{
		static const uint16_t __address = 50;
		
		/* Bits INT1_THS_XH: */
		struct INT1_THS_XH_
		{
			/* MODE rw */
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register INT1_THS_XH */
	void setINT1_THS_XH(uint8_t value)
	{
		write(INT1_THS_XH::__address, value, 8);
	}
	
	/* Get register INT1_THS_XH */
	uint8_t getINT1_THS_XH()
	{
		return read8(INT1_THS_XH::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                         REG INT1_THS_XL                                          *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG INT1_THS_XL:
	 * 7.18
	 * Interrupt threshold.
	 */
	struct INT1_THS_XL
	{
		static const uint16_t __address = 51;
		
		/* Bits INT1_THS_XL: */
		struct INT1_THS_XL_
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00000000; // 8'd0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register INT1_THS_XL */
	void setINT1_THS_XL(uint8_t value)
	{
		write(INT1_THS_XL::__address, value, 8);
	}
	
	/* Get register INT1_THS_XL */
	uint8_t getINT1_THS_XL()
	{
		return read8(INT1_THS_XL::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                         REG INT1_THS_YH                                          *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG INT1_THS_YH:
	 * 7.19
	 * Interrupt threshold.
	 */
	struct INT1_THS_YH
	{
		static const uint16_t __address = 52;
		
		/* Bits INT1_THS_YH: */
		struct INT1_THS_YH_
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00000000; // 8'd0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register INT1_THS_YH */
	void setINT1_THS_YH(uint8_t value)
	{
		write(INT1_THS_YH::__address, value, 8);
	}
	
	/* Get register INT1_THS_YH */
	uint8_t getINT1_THS_YH()
	{
		return read8(INT1_THS_YH::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                         REG INT1_THS_YL                                          *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG INT1_THS_YL:
	 * 7.20
	 * Interrupt threshold.
	 */
	struct INT1_THS_YL
	{
		static const uint16_t __address = 53;
		
		/* Bits INT1_THS_YL: */
		struct INT1_THS_YL_
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00000000; // 8'd0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register INT1_THS_YL */
	void setINT1_THS_YL(uint8_t value)
	{
		write(INT1_THS_YL::__address, value, 8);
	}
	
	/* Get register INT1_THS_YL */
	uint8_t getINT1_THS_YL()
	{
		return read8(INT1_THS_YL::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                         REG INT1_THS_ZH                                          *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG INT1_THS_ZH:
	 * 7.21
	 * Interrupt threshold.
	 */
	struct INT1_THS_ZH
	{
		static const uint16_t __address = 54;
		
		/* Bits INT1_THS_ZH: */
		struct INT1_THS_ZH_
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00000000; // 8'd0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register INT1_THS_ZH */
	void setINT1_THS_ZH(uint8_t value)
	{
		write(INT1_THS_ZH::__address, value, 8);
	}
	
	/* Get register INT1_THS_ZH */
	uint8_t getINT1_THS_ZH()
	{
		return read8(INT1_THS_ZH::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                         REG INT1_THS_ZL                                          *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG INT1_THS_ZL:
	 * 7.22
	 * Interrupt threshold.
	 */
	struct INT1_THS_ZL
	{
		static const uint16_t __address = 55;
		
		/* Bits INT1_THS_ZL: */
		struct INT1_THS_ZL_
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00000000; // 8'd0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register INT1_THS_ZL */
	void setINT1_THS_ZL(uint8_t value)
	{
		write(INT1_THS_ZL::__address, value, 8);
	}
	
	/* Get register INT1_THS_ZL */
	uint8_t getINT1_THS_ZL()
	{
		return read8(INT1_THS_ZL::__address, 8);
	}
	
};
