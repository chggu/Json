#pragma once
#include<Windows.h>

class C_RunTimeTiming{
	private:
		typedef void (CALLBACK* StartRunTimeTimingDLL) (LARGE_INTEGER&, LARGE_INTEGER&);//����һ������ר������Start��ʼ
		typedef long long (CALLBACK* EndRunTimeTimingDLL) (LARGE_INTEGER&, LARGE_INTEGER&);//End����
		LARGE_INTEGER Start = {}, pFre = {};//��ʼ����ʱ��
		HMODULE hDLL_RTT = NULL;
	public:
		C_RunTimeTiming();
		int StartTiming();//��¼��ʼʱ��
		long long EndTiming();//��¼����ʱ��
		~C_RunTimeTiming();
};
C_RunTimeTiming::C_RunTimeTiming() {
	hDLL_RTT= LoadLibrary(L"RunTimeTiming");//����DLL
}
C_RunTimeTiming::~C_RunTimeTiming() {
	FreeLibrary(hDLL_RTT);//���DLL
}
int C_RunTimeTiming::StartTiming(){//0Ϊ�ɹ� ��0ֵΪʧ��
	StartRunTimeTimingDLL lpfnDLLStart = NULL;//����ָ��
	if (hDLL_RTT == NULL) {
		return 1;//����DLL����
	}
	lpfnDLLStart = (StartRunTimeTimingDLL)\
	GetProcAddress(hDLL_RTT, "?StartTiming@@YAXAEAT_LARGE_INTEGER@@0@Z");//��ȡDLL������ַ
	if (lpfnDLLStart == NULL) {
		return 2;//��ȡ������ַ����
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