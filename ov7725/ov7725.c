#include "ov7725.h"



#define delay_ms(ms) HAL_Delay(ms) 




typedef struct
{
	uint8_t Address;			       /*�Ĵ�����ַ*/
	uint8_t Value;		           /*�Ĵ���ֵ*/
}Register_Info;



/*OV7725��ʼ�����ñ�*/
Register_Info Sensor_Config[] =
{


//{0x12, 0x40},
//{0x3d, 0x03},
//{0x17, 0x3f-1},//{0x17, 0x22},why
//{0x18, 0x50+4},//{0x18, 0xa4},
//{0x19, 0x03},//{0x19, 0x07},
//{0x1a, 0x78},//{0x1a, 0xf0},
//{0x32, 0x00},
//{0x29, 0x50},//{0x29, 0xa0},
//{0x2c, 0x78},//{0x2c, 0xf0},
//{0x2a, 0x00},
//{0x11, 0x01},//cklrc
//{0x42, 0x7f},
//{0x4d, 0x09},
//{0x63, 0xe0},
//{0x64, 0xff},
//{0x65, 0x20},
//{0x66, 0x00},
//{0x67, 0x48},
//{0x13, 0xf0},
//{0x0d, 0x41}, // 0x51/0x61/0x71 for different AEC/AGC window//pll
//{0x0f, 0xc5},
//{0x14, 0x11},
//{0x22, 0x7f},
//{0x23, 0x03},
//{0x24, 0x40},


//{0x25, 0x30},
//{0x26, 0xa1},
//{0x2b, 0x00},
//{0x6b, 0xaa},
//{0x13, 0xff},
//{0x90, 0x05},
//{0x91, 0x01},
//{0x92, 0x03},
//{0x93, 0x00},
//{0x94, 0xb0},
//{0x95, 0x9d},
//{0x96, 0x13},
//{0x97, 0x16},
//{0x98, 0x7b},
//{0x99, 0x91},
//{0x9a, 0x1e},
//{0x9b, 0x08},
//{0x9c, 0x20},
//{0x9e, 0x81},
//{0xa6, 0x06},
////Gamma
//{0x7e, 0x0c},
//{0x7f, 0x16},
//{0x80, 0x2a},
//{0x81, 0x4e},
//{0x82, 0x61},
//{0x83, 0x6f},
//{0x84, 0x7b},
//{0x85, 0x86},
//{0x86, 0x8e},
//{0x87, 0x97},
//{0x88, 0xa4},
//{0x89, 0xaf},
//{0x8a, 0xc5},
//{0x8b, 0xd7},
//{0x8c, 0xe8},
//{0x8d, 0x20},
//// for 30 fps, 60Hz
//{0x33, 0x00},
//{0x22, 0x7f},
//{0x23, 0x03},
//// for 25 fps, 50Hz
////{0x33, 0x66},
////{0x22, 0x99},


////{0x23, 0x03},
//// Lens Correction, should be tuned with real camera module
//{0x4a, 0x10},
//{0x49, 0x10},
//{0x4b, 0x14},
//{0x4c, 0x17},
//{0x46, 0x05},
//{0x0e, 0x65},

#define GAIN      0x00
#define BLUE      0x01
#define RED       0x02
#define RED       0x02
#define GREEN     0x03
#define BAVG      0x05
#define GAVG      0x06
#define RAVG      0x07
#define AECH      0x08
#define COM2      0x09
#define PID       0x0A
#define VER       0x0B
#define COM3      0x0C
#define COM4      0x0D
#define COM5      0x0E
#define COM6      0x0F
#define AEC       0x10
#define CLKRC     0x11
#define COM7      0x12
#define COM8      0x13
#define COM9      0x14
#define COM10     0x15
#define REG16     0x16
#define HSTART    0x17
#define HSIZE     0x18
#define VSTRT     0x19
#define VSIZE     0x1A
#define PSHFT     0x1B
#define MIDH      0x1C
#define MIDL      0x1D
#define LAEC      0x1F
#define COM11     0x20
#define BDBase    0x22
#define BDMStep   0x23
#define AEW       0x24
#define AEB       0x25
#define VPT       0x26
#define REG28     0x28
#define HOutSize  0x29
#define EXHCH     0x2A
#define EXHCL     0x2B
#define VOutSize  0x2C
#define ADVFL     0x2D
#define ADVFH     0x2E
#define YAVE      0x2F
#define LumHTh    0x30
#define LumLTh    0x31
#define HREF      0x32
#define DM_LNL    0x33
#define DM_LNH    0x34
#define ADoff_B   0x35
#define ADoff_R   0x36
#define ADoff_Gb  0x37
#define ADoff_Gr  0x38
#define Off_B     0x39
#define Off_R     0x3A
#define Off_Gb    0x3B
#define Off_Gr    0x3C
#define COM12     0x3D
#define COM13     0x3E
#define COM14     0x3F
#define COM16     0x41
#define TGT_B     0x42
#define TGT_R     0x43
#define TGT_Gb    0x44
#define TGT_Gr    0x45
#define LC_CTR    0x46
#define LC_XC     0x47
#define LC_YC     0x48
#define LC_COEF   0x49
#define LC_RADI   0x4A
#define LC_COEFB  0x4B
#define LC_COEFR  0x4C
#define FixGain   0x4D
#define AREF1     0x4F
#define AREF6     0x54
#define UFix      0x60
#define VFix      0x61
#define AWBb_blk  0x62
#define AWB_Ctrl0 0x63
#define DSP_Ctrl1 0x64
#define DSP_Ctrl2 0x65
#define DSP_Ctrl3 0x66
#define DSP_Ctrl4 0x67
#define AWB_bias  0x68
#define AWBCtrl1  0x69
#define AWBCtrl2  0x6A
#define AWBCtrl3  0x6B
#define AWBCtrl4  0x6C
#define AWBCtrl5  0x6D
#define AWBCtrl6  0x6E
#define AWBCtrl7  0x6F
#define AWBCtrl8  0x70
#define AWBCtrl9  0x71
#define AWBCtrl10 0x72
#define AWBCtrl11 0x73
#define AWBCtrl12 0x74
#define AWBCtrl13 0x75
#define AWBCtrl14 0x76
#define AWBCtrl15 0x77
#define AWBCtrl16 0x78
#define AWBCtrl17 0x79
#define AWBCtrl18 0x7A
#define AWBCtrl19 0x7B
#define AWBCtrl20 0x7C
#define AWBCtrl21 0x7D
#define GAM1      0x7E
#define GAM2      0x7F
#define GAM3      0x80
#define GAM4      0x81
#define GAM5      0x82
#define GAM6      0x83
#define GAM7      0x84
#define GAM8      0x85
#define GAM9      0x86
#define GAM10     0x87
#define GAM11     0x88
#define GAM12     0x89
#define GAM13     0x8A
#define GAM14     0x8B
#define GAM15     0x8C
#define SLOP      0x8D
#define DNSTh     0x8E
#define EDGE0     0x8F
#define EDGE1     0x90
#define DNSOff    0x91
#define EDGE2     0x92
#define EDGE3     0x93
#define MTX1      0x94
#define MTX2      0x95
#define MTX3      0x96
#define MTX4      0x97
#define MTX5      0x98
#define MTX6      0x99
#define MTX_Ctrl  0x9A
#define BRIGHT    0x9B
#define CNST      0x9C
#define UVADJ0    0x9E
#define UVADJ1    0x9F
#define SCAL0     0xA0
#define SCAL1     0xA1
#define SCAL2     0xA2
#define SDE       0xA6
#define USAT      0xA7
#define VSAT      0xA8
#define HUECOS    0xA9
#define HUESIN    0xAA
#define SIGN      0xAB
#define DSPAuto   0xAC



{0x3d, 0x03},
{0x42, 0x7f},
{0x4d, 0x09},
{0x63, 0xe0},
{0x64, 0xff},
{0x65, 0x20},
{0x66, 0x00},
{0x67, 0x48},
{0x13, 0xf0},
//{0x0d, 0x41}, // 0x51/0x61/0x71 for different AEC/AGC window
{0x0f, 0xc5},//��������������
{0x14, 0x11},
{0x22, 0x7f},
{0x23, 0x03},
{0x24, 0x40},


{0x25, 0x30},
{0x26, 0xa1},
//{0x2b, 0x00},
{0x6b, 0xaa},
{0x13, 0xff},
{0x90, 0x05},
{0x91, 0x01},
{0x92, 0x03},
{0x93, 0x00},
{0x94, 0xb0},
{0x95, 0x9d},
{0x96, 0x13},
{0x97, 0x16},
{0x98, 0x7b},
{0x99, 0x91},
{0x9a, 0x1e},
{0x9b, 0x08},
{0x9c, 0x20},
{0x9e, 0x81},
{0xa6, 0x06},
//Gamma
{0x7e, 0x0c},
{0x7f, 0x16},
{0x80, 0x2a},
{0x81, 0x4e},
{0x82, 0x61},
{0x83, 0x6f},
{0x84, 0x7b},
{0x85, 0x86},
{0x86, 0x8e},
{0x87, 0x97},
{0x88, 0xa4},
{0x89, 0xaf},
{0x8a, 0xc5},
{0x8b, 0xd7},
{0x8c, 0xe8},
{0x8d, 0x20},
// for 30 fps, 60Hz
{0x33, 0x00},
{0x22, 0x7f},
{0x23, 0x03},
// for 25 fps, 50Hz
//{0x33, 0x66},
//{0x22, 0x99},


//{0x23, 0x03},
//// Lens Correction, should be tuned with real camera module
{0x4a, 0x10},
{0x49, 0x10},
{0x4b, 0x14},
{0x4c, 0x17},
{0x46, 0x05},
{0x0e, 0x65},



	    //�Ĵ������Ĵ���ֵ��
    {COM4         , 0xC1},//ok
    {CLKRC        , 0x02},//ok
    {COM2         , 0x03},//ok
    {COM3         , 0xD0},//    {COM3         , 0xD0},
    {COM7         , 0x40},//ok
    {HSTART       , 0x3F},//ok
    {HSIZE        , 0x50},//ok
    {VSTRT        , 0x03},//ok
    {VSIZE        , 0x78},//ok
    {HREF         , 0x00},//maybe ok
    {SCAL0        , 0x0A},//down sampling?
    {AWB_Ctrl0    , 0xE0},
    {DSPAuto      , 0xff},
    {DSP_Ctrl2    , 0x0C},
    {DSP_Ctrl3    , 0x00},
    {DSP_Ctrl4    , 0x00},



    {HOutSize     , 0x50},


    {VOutSize     , 0x78},






////	//30 fps, PCLK = 24Mhz
//	{0x11, 0x01},
//	{0x0d, 0x40},



	////60 fps, PCLK = 24/5*4Mhz
	{0x11, 0x04},
	{0x0d, 0xC0},
	

	
	

};


static uint8_t ov7725_Config(void)
{
	for( uint16_t i = 0 ; i < sizeof(Sensor_Config)/sizeof(Sensor_Config[0]) ; i++ )
	{
			if(sccb_WriteByte(Sensor_Config[i].Address, Sensor_Config[i].Value) )
			{
					return 1;
			}
	}
	return 0;
}



#define OV7725_ID       0x21
static uint8_t ov7725_Detect(void)
{
	uint8_t ID;
	if(sccb_ReadByte(0x0b,&ID))
		return 1;
	if(ID != OV7725_ID)
		return 2;
	return 0;
}


uint8_t ov7725_Init(void)
{
	uint16_t i = 0;
	while(sccb_WriteByte ( 0x12, 0x80 )) /*��λsensor */
	{
		i++;
		if(i == 20)
		{
			return 1;//��Ӧ��
		}
	}
	delay_ms(50);
	
	if(ov7725_Detect())
		return 2;//��������
	
	if(ov7725_Config())
		return 3;//����ʱ����
	
	return 0;
}