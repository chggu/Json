/*
* ����ĺ���
* д�ĺ���
* Copyright (C) 2022 chggu
*/
#include<stdio.h>
#include<Windows.h>
#include<string>
#include<iostream>
#include<stack>
#include"TimeTiming.h"
#include"HdStr.h"

int main() {
	C_RunTimeTiming* timing = new C_RunTimeTiming();
	int ST_ReturnVal = timing->StartTiming();
	if (ST_ReturnVal) {
		if (ST_ReturnVal == 1) {
			printf("�쳣���޷�����DLLTimeTiming.dll");
		} else if (ST_ReturnVal == 2) {
			printf("�쳣���޷���ȡ������ַ");
		} else {
			printf("�쳣������");
		}
		return 0;
	}//�쳣����
	//�������뿪ʼ

	//���ļ���д����λ�� �Ժ�д
	std::string JsonStr;
	std::cin >> JsonStr;//��װ�Ѿ�������ַ�����
	std::stack<char> JsonSta;
	int JsonStrLen = JsonStr.length();
	//�����������
	long long ED_ReturnVal = timing->EndTiming();
	printf("%lld", ED_ReturnVal);
	delete(timing);
	return 0;
}