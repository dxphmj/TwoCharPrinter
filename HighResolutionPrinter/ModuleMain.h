#pragma once
#include <stdio.h>
#include "xml/tinyxml.h"
#include <iostream>
#include <string>
#include <vector>
//#include <atlconv.h>
//#include "windows.h"

#include <QDateTime>

using namespace std;

#define CString QString
#define CTime QTime
#define CStringA QString
#define CStringW QString
typedef unsigned char BYTE;

int TTLcomLoop(void* pParam);
int method1(void* pParam);
BYTE* VEC2ARRAY(vector<BYTE> tempVec,int n);
CString GETnBIT_from_bytReadData(int I , int m , int n );
CString GETnBIT_from_bytStatus(int I , int m , int n );

//const class nullptr_t
//{
//public:
//	template<class T>
//	inline operator T*() const
//	{ return 0; }
//
//	template<class C, class T>
//	inline operator T C::*() const
//	{ return 0; }
//
//private:
//	void operator&() const;
//} 
//nullptr = {};

//定时器用变量
class TimClass
{
public:
	TimClass()
	{
		staComFau = false;
		staInkEmpFau = false;
		staInkOveFau  = false;
		boStaLock = false;
		booUExist  = false;
		staRemPrinSwiLas = false;
		InkLifeTimeLas = 6000;
		boInkLifeTime = false;
		boServiceTime = false;
        //staPhaseLas = 0;
		staSysReaLas = false;
	}
	~TimClass(){}
	bool staComFau ;
		bool staInkEmpFau;
		bool staInkOveFau ;
		bool boStaLock ;
		//'  Dim TTLSendNumTim As Byte = 0       '定义串口故障后重发次数
		bool booUExist ;
		bool staRemPrinSwiLas ;
		string staSolLevFauLas, staInkLevFauLas ;
		int InkLifeTimeLas ;
		int ServiceTimeLasXML, InkLifeTimeLasXML ;
		CTime InkDateTimLas, SerDateTimLas, dateTimLasWri ;
		bool boInkLifeTime;
		bool boServiceTime;
        BYTE staPhaseLas;
		bool staSysReaLas ;
};
//控制变量类
class PcfClass//控制
{
public:
	PcfClass()
	{		
		 pcf0X00bit1_bit0  = 2; 
		 pcf0X00bit2 = 0 ;
		 pcf0X00bit4  = 0 ;
		 pcf0X00bit5  = 0 ;
		 pcf0X00bit6  = 0; 

		
		 pcf0X01bit0  = 1; 
		 pcf0X01bit2  = 0; 
		 pcf0X01bit3  = 0 ;
		  openselectfilename = "";
		  labForMName_temp  = "";

		  pcf_printmode_temp = "";

		  pcf_external_forwarddire_temp= "";
		  pcf_external_signal_temp  = "";
		  pcf_external_cirum_temp  = "";
		  pcf_external_ir_temp  = "";
		  pcf_external_fremul_temp  = "";
		  pcf_external_sensor_temp  = "";
		  pcf_external_active_temp  = "";
		  pcf_external_trilength_temp  = "";
	}
	~PcfClass(){}
	string pcf_currentname ;
	string pcf_currentpath ;


	string lab_currentname ;
	string lab_currentpath ;

	string strPCFlabForMName ;

	string strLABlabForMName ;

	string openselectfilename ;
	string labForMName_temp ;

	string pcf_printmode_temp ;

	string pcf_external_forwarddire_temp ;
	string pcf_external_signal_temp ;
	string pcf_external_cirum_temp ;
	string pcf_external_ir_temp ;
	string pcf_external_fremul_temp ;
	string pcf_external_sensor_temp ;
	string pcf_external_active_temp ;
	string pcf_external_trilength_temp ;
	string pcf0X02_05, pcf0X06_09, pcf0X13_16, pcf0X19_1C ;

	BYTE pcf0X00, pcf0X01, pcf0X02, pcf0X03, pcf0X04, pcf0X05, pcf0X06, pcf0X07, pcf0X08, pcf0X09, pcf0X0A, pcf0X13, pcf0X14, pcf0X15, pcf0X16, pcf0X18, pcf0X19, pcf0X1A, pcf0X1B, pcf0X1C ;
	//'pcf控制0X00
	BYTE pcf0X00bit1_bit0 ;// '列触发方式：0为编码器1相，1为编码器2相，2为内部一列点数（即等于64K/划速率）
	BYTE pcf0X00bit2 ; //'同步器反相，0：A->B，1:B->A
	BYTE pcf0X00bit4 ; //'故障运行，正在打印遇到故障时的处理，0打印停止，1 打印继续，但墨点没有喷出来
	BYTE pcf0X00bit5; //'产品计数器重置，0 不重置，1 重置到设定值
	BYTE pcf0X00bit6 ; //'打印计数器重置，0 不重置，1 重置到设定值

	//'pcf控制0X01
	BYTE pcf0X01bit0 ; //'是否启用电眼，0为关闭，1为启用
	BYTE pcf0X01bit2 ; //'电眼有效电平，0为低电平，1为高电平
	BYTE pcf0X01bit3 ; //'喷印模式为单次还是连续，0为单次，1为连续
};
//状态变量类
class StatusClass//状态
{
public:
	StatusClass(void){			
		 ctr0X00bit0  = 0 ;//'0关机，1开机
		 ctr0X00bit1  = 0 ;//'0正常，1快速
		 ctr0X00bit2  = 0 ;//'0泵速模式，1压力模式
		 ctr0X00bit3  = 0 ;//'0关泵，1开泵
		 ctr0X00bit5  = 0 ;//'清除下位机故障标志位，0平时，1清除下位机故障

		//'控制0X01
		 ctr0X01bit0  = 0 ;//'0关喷嘴，1开喷嘴
		 ctr0X01bit1  = 0; //'0关供墨阀，1开供墨阀
		 ctr0X01bit2  = 0; //'0关排气阀，1开排气阀
		 ctr0X01bit3  = 0 ;//'0关清洗阀，1开清洗阀
		 ctr0X01bit4  = 0; //'0关溶剂阀，1开溶剂阀
		 ctr0X01bit5  = 0; //'0关粘度阀，1开粘度阀
		 ctr0X01bit6  = 0; //'0关冲洗阀，1开冲洗阀

		//'控制0X02
		 ctr0X02bit0  = 0; //'关回收检测功能，1为关闭检测，0为开启检测
		 ctr0X02bit1  = 0; //'关墨线功能，1为关闭墨线，0为开启墨线
		 ctr0X02bit2  = 0; //'添加溶剂，0关，1开
		 ctr0X02bit3  = 0; //'测试粘度，0关，1开
		 ctr0X02bit4  = 0; //'冲洗喷嘴，0关，1开
		 ctr0X02bit5  = 0; //'反吸喷嘴，0关，1开
		 ctr0X02bit6  = 0; //'墨路校正，0关，1开
		 ctr0X02bit7  = 0; //'墨路循环，0关，1开

		//'控制0X03
		 ctr0X03bit0  = 0; //'开打印功能，1开启
		 ctr0X03bit1  = 0; //'故障重打印（需要重新确认该功能）
		 ctr0X03bit3  = 0; //'高压开关，1为开启
		 ctr0X03bit6  = 0; //'分裂模式，0为手动，1为自动 (下位机默认为1)

		//'其它
		 bytModuStep  = 10; //'固定分裂电压步级
	}
	~StatusClass(){}
	void getstatu();
	void byStatusFromSlaveState();

    //void us_button_onoff(HWND hwnd);//墨水普通句柄
    //void ad_button_onoff(HWND hwnd);//墨水高级句柄

	void download_inksystem_control00();
	void download_inksystem_control01();
	void download_inksystem_control02();
	void download_inksystem_control03();
public:
	bool staSysRea, staSysBus, staBumMod, staBum, staHarFin, staCleFauFin;
		bool staNozVal, staFeeVal, staBleVal, staFluVal, staSolVal, staVisVal, staWasVal ;
		bool staInkFloSenOff, staCloInkLin, staAddSol, staDetVis, staWasNoz, staSucNoz, staAdjInkLin, staInkCir ;
		bool staInkTemSenFau, staPriHeaTemFau, staBumSpeOveFau, staPreOveFau, staVisAbnFau, staVisSenFau, staInkFloFau, staPriHeaCle ;
		bool staFanFau, staChaFau, staPhaFau;
		bool staHigVolFau ;
		string staSolLevFau, staInkLevFau, staRFID ;
		bool staPrnting, staHigVolSwi, staActProSen, staProSenFas, staAutModFau, staValFau ;
		bool staPrinted, staRemPrinSwi, staBufFul, staBufRea, staEncDir, staLinFas, staPriHeaHot, staPriHeaHotFau, staSetTimeEna ;
		int staPressure, staBumSpe, staHigVol, staEncFre ;
		BYTE staPriHeaTem, staActVis, staTarVis, staInkLev, staSolLev, staPhase ;
		int staInkTem ;
		int staProCou, staPriCou, staInkLifeTime ;
		BYTE staPixDotNee, staAutModVol ;
		bool staFanFauLas, staChaFauLas, staPhaFauLas, staHigVolFauLas ;
		bool staProSenFasLas, staAutModFauLas, staValFauLas, staLinFasLas, staPriHeaHotFauLas ;
		bool staInkTemSenFauLas, staPriHeaTemFauLas, staBumSpeOveFauLas, staPreOveFauLas, staVisAbnFauLas, staVisSenFauLas, staInkFloFauLas ;


			BYTE ctr0X00, ctr0X01, ctr0X02, ctr0X03, ctr0X04 ;
			//'控制0X00
			BYTE ctr0X00bit0 ;//'0关机，1开机
			BYTE ctr0X00bit1   ;//'0正常，1快速
			BYTE ctr0X00bit2   ;//'0泵速模式，1压力模式
			BYTE ctr0X00bit3   ;//'0关泵，1开泵
			BYTE ctr0X00bit5   ;//'清除下位机故障标志位，0平时，1清除下位机故障

			//'控制0X01
			BYTE ctr0X01bit0   ;//'0关喷嘴，1开喷嘴
			BYTE ctr0X01bit1 ; //'0关供墨阀，1开供墨阀
			BYTE ctr0X01bit2  ; //'0关排气阀，1开排气阀
			BYTE ctr0X01bit3   ;//'0关清洗阀，1开清洗阀
			BYTE ctr0X01bit4 ; //'0关溶剂阀，1开溶剂阀
			BYTE ctr0X01bit5  ; //'0关粘度阀，1开粘度阀
			BYTE ctr0X01bit6  ; //'0关冲洗阀，1开冲洗阀

			//'控制0X02
			BYTE ctr0X02bit0 ; //'关回收检测功能，1为关闭检测，0为开启检测
			BYTE ctr0X02bit1 ; //'关墨线功能，1为关闭墨线，0为开启墨线
			BYTE ctr0X02bit2  ; //'添加溶剂，0关，1开
			BYTE ctr0X02bit3  ; //'测试粘度，0关，1开
			BYTE ctr0X02bit4  ; //'冲洗喷嘴，0关，1开
			BYTE ctr0X02bit5  ; //'反吸喷嘴，0关，1开
			BYTE ctr0X02bit6 ; //'墨路校正，0关，1开
			BYTE ctr0X02bit7  ; //'墨路循环，0关，1开

			//'控制0X03
			BYTE ctr0X03bit0  ; //'开打印功能，1开启
			BYTE ctr0X03bit1  ; //'故障重打印（需要重新确认该功能）
			BYTE ctr0X03bit3  ; //'高压开关，1为开启
			BYTE ctr0X03bit6  ; //'分裂模式，0为手动，1为自动 (下位机默认为1)

			//'其它
			BYTE bytModuStep  ; //'固定分裂电压步级
			int	bytModuVol, SolLevSum, InkLevSum, LevCoun ;
};
//通用算法库
class ModuleMain//通用算法库
{
public:
	ModuleMain(void);
	~ModuleMain(void);
    /*
    CString string2CString(string str){//return Utf8ToUnicode(str).c_str();
        //int unicodeLen = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);
        int unicodeLen;
        wchar_t m_wch[50]={0};
        mbstowcs(m_wch,str.c_str(),unicodeLen);
		// 给指向缓冲区的指针变量分配内存    
        wchar_t *pUnicode = (wchar_t*)malloc(sizeof(wchar_t)*unicodeLen);
		// 开始向缓冲区转换字节    
        //MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, pUnicode, unicodeLen);
        mbstowcs(pUnicode,str.c_str(),unicodeLen); //2.dai zhuan huan
        wstring ret_str = pUnicode;
        free(pUnicode);
        return QString::fromStdWString(ret_str);
    }
    */
    std::string ASCToUTF8(const std::string& str) ;
	string CString2string(CString cstr)
	{
		
		/*string st = W2A(strT.GetBuffer());*/
		
		//return UnicodeToUtf8_CSTR(cstr);
		return cstr.toStdString();
		
		//int iLen = cstr.GetLength() + 1;
		//char* pSrc = cstr.GetBuffer(iLen * sizeof(char));
		//string strRet = string(pSrc);
		//cstr.ReleaseBuffer(iLen);
		//return strRet;
		//USES_CONVERSION;
		//return W2A(cstr.GetString(),CP_UTF8);

		//string str;
		//str.resize(cstr.GetLength()*2);
		//WideCharToMultiByte(CP_ACP,0,cstr,cstr.GetLength(),&str[0],(int)str.size(),NULL,NULL);
		//return str;
		//CStringW cs = L"中文English";
		//CStringA temp = cstr.GetBuffer(0); //通过转化，temp接受了原来字符串的多字节形式
		//string dst = temp.GetBuffer(0); //现在就可以将值直接赋给string类型了
		//return dst;

		//USES_CONVERSION;
		//std::string str(W2A(cstr));
		//return str;

		//USES_CONVERSION;
		//string city=CT2CA(cstr);
		//return city;
	}
    //LPCWSTR stringToLPCWSTR(std::string orig);
    //string WcharToChar(const wchar_t* wp, size_t m_encode = CP_ACP);
	string ReadXml(string xmlFileName,string nameStr,string faultValue,string path);//查
    //bool writeXml(string xmlFileName,string valueStr,string textStr,string path);//增
	bool changeXml(string xmlFileName,string valueStr,string textStr,string path);//改
	void string2tchar(std::string &src, char* buf);
    //string TCHAR2STRING(TCHAR *STR);
   const char* CString2ConstChar(CString str);
   //void DisableAllBtn(HWND hwnd,bool booOpen);
   void ReportPower();
   //string CString2string(CString csStrData);
   //字符转数字
   int charToDigit(char c);
   int jinzhi16to10(string pre);
   int jinzhi8to10(string pre) ;
   int jinzhi2to10(string pre);
   string jinzhi10to2(int pre) ;
   string jinzhi10to8(int pre) ;
   string jinzhi10to16(int pre) ;
   bool MesDisIsB(int MesDis,int isNumber);
   string SerialFormatToText(int Value, int Digits, int Format);
   void getSerialDotBuf2();
	string TimeFormatToText(CString InPutTimeFormat,int tempstrETimeOffSet, int tempintTimeOffSet, int tempstrTimeOffSetUint);
public://字符转换库
	wstring AsciiToUnicode(const string& str);  
	string  UnicodeToAscii(const wstring& wstr);  
	// UTF8与Unicode互转  
	wstring Utf8ToUnicode(const string& str);  
	string  UnicodeToUtf8(const wstring& wstr);  
	// ASCII与UTF8互转  
	string  AsciiToUtf8(const string& str);  
	string  Utf8ToAscii(const string& str);  
	//**************CString******************//  
	// ASCII与Unicode互转  
	
	QString   AsciiToUnicode_CSTR(const QString& str);  
	QString    UnicodeToAscii_CSTR(const QString& wstr);
	//CStringW    AsciiToUnicode_CSTR(const CStringA& str);  
	//CStringA    UnicodeToAscii_CSTR(const CStringW& wstr);  
	// UTF8与Unicode互转  
	QString    Utf8ToUnicode_CSTR(const QString& str);  
	QString    UnicodeToUtf8_CSTR(const QString& wstr);  
	//CStringW    Utf8ToUnicode_CSTR(const CStringA& str);  
	//CStringA    UnicodeToUtf8_CSTR(const CStringW& wstr);  
	// ASCII与UTF8互转  
	QString    AsciiToUtf8_CSTR(const QString& str);  
	QString    Utf8ToAscii_CSTR(const QString& str);  
	//CStringA    AsciiToUtf8_CSTR(const CStringA& str);  
	//CStringA    Utf8ToAscii_CSTR(const CStringA& str);  
	/************string-int***************/  
	// string 转 Int  
	int StringToInt(const string& str);  
	string IntToString(int i);  
	string IntToString(char i);  
	string IntToString(double i);
public:
	void InitCommMsg();
};

