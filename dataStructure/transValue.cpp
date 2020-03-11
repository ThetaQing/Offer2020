// 函数的返回值传递

#include <iostream>
#include <string>
#include <vector>
#include "transValue.h"
using namespace std;
// 数据结构与算法分析C++描述


/************函数说明*****************
* 来源：1.5.3 返回值传递，按常量引用返回
* 分析：maxValue是局部变量，当函数返回的时候就不复存在了，所以在没有进行复制
之前就返回时不恰当的，取决于编译器释放maxValue所使用的内存的速度。

*/

const string & findMax(const vector<string> & arr)
{
	int maxIndex = 0; 
	for (int i = 1; i < arr.size(); ++i)
		if (arr[maxIndex] < arr[i])
			maxIndex = i;
	return arr[maxIndex];
}

const string & findMaxWrong(const vector<string> & arr)
{
	string maxValue = arr[0];
	for (int i = 1; i < arr.size(); ++i)
		if (maxValue < arr[i])
			maxValue = arr[i];
	return maxValue;
}

