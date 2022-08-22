#include<Windows.h>
#include<stdio.h>
_declspec(dllexport) void StartTiming(LARGE_INTEGER& pFre, LARGE_INTEGER& start) {//频率 开始时间 结束时间
	//计时 单位us
	QueryPerformanceFrequency(&pFre);
	QueryPerformanceCounter(&start);
	//获取频率和开始时间
	return;
}
_declspec(dllexport) long long EndTimeing(LARGE_INTEGER& pFre, LARGE_INTEGER& start) {
	//结束
	LARGE_INTEGER end;
	QueryPerformanceCounter(&end);
	return (end.QuadPart - start.QuadPart) / (pFre.QuadPart / 1000000);
}