#pragma once
#include<Windows.h>

class C_RunTimeTiming{
	private:
		typedef void (CALLBACK* StartRunTimeTimingDLL) (LARGE_INTEGER&, LARGE_INTEGER&);//定义一个函数专属类型Start开始
		typedef long long (CALLBACK* EndRunTimeTimingDLL) (LARGE_INTEGER&, LARGE_INTEGER&);//End结束
		LARGE_INTEGER Start = {}, pFre = {};//开始结束时间
		HMODULE hDLL_RTT = NULL;
	public:
		C_RunTimeTiming();
		int StartTiming();//记录开始时间
		long long EndTiming();//记录结束时间
		~C_RunTimeTiming();
};
C_RunTimeTiming::C_RunTimeTiming() {
	hDLL_RTT= LoadLibrary(L"RunTimeTiming");//加载DLL
}
C_RunTimeTiming::~C_RunTimeTiming() {
	FreeLibrary(hDLL_RTT);//解除DLL
}
int C_RunTimeTiming::StartTiming(){//0为成功 非0值为失败
	StartRunTimeTimingDLL lpfnDLLStart = NULL;//函数指针
	if (hDLL_RTT == NULL) {
		return 1;//加载DLL错误
	}
	lpfnDLLStart = (StartRunTimeTimingDLL)\
	GetProcAddress(hDLL_RTT, "?StartTiming@@YAXAEAT_LARGE_INTEGER@@0@Z");//获取DLL函数地址
	if (lpfnDLLStart == NULL) {
		return 2;//获取函数地址错误
	}
	lpfnDLLStart(pFre, Start);
	return 0;
}
long long C_RunTimeTiming::EndTiming() {
	EndRunTimeTimingDLL lpfnDLLEnd = NULL;
	lpfnDLLEnd = (EndRunTimeTimingDLL)\
	GetProcAddress(hDLL_RTT, "?EndTimeing@@YA_JAEAT_LARGE_INTEGER@@0@Z");
	long long ReturnVal = lpfnDLLEnd(pFre, Start);
	return ReturnVal;
}