/*
* 程序的核心
* 写的很烂
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
			printf("异常：无法加载DLLTimeTiming.dll");
		} else if (ST_ReturnVal == 2) {
			printf("异常：无法获取函数地址");
		} else {
			printf("异常：其他");
		}
		return 0;
	}//异常处理
	//正经代码开始

	//给文件读写留个位置 以后写
	std::string JsonStr;
	std::cin >> JsonStr;//假装已经处理好字符串了
	std::stack<char> JsonSta;
	int JsonStrLen = JsonStr.length();
	//正经代码结束
	long long ED_ReturnVal = timing->EndTiming();
	printf("%lld", ED_ReturnVal);
	delete(timing);
	return 0;
}