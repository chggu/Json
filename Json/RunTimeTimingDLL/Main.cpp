#include<Windows.h>
#include<stdio.h>
_declspec(dllexport) void StartTiming(LARGE_INTEGER& pFre, LARGE_INTEGER& start) {//Ƶ�� ��ʼʱ�� ����ʱ��
	//��ʱ ��λus
	QueryPerformanceFrequency(&pFre);
	QueryPerformanceCounter(&start);
	//��ȡƵ�ʺͿ�ʼʱ��
	return;
}
_declspec(dllexport) long long EndTimeing(LARGE_INTEGER& pFre, LARGE_INTEGER& start) {
	//����
	LARGE_INTEGER end;
	QueryPerformanceCounter(&end);
	return (end.QuadPart - start.QuadPart) / (pFre.QuadPart / 1000000);
}