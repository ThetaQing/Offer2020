// �����ķ���ֵ����

#include <iostream>
#include <string>
#include <vector>
#include "transValue.h"
using namespace std;
// ���ݽṹ���㷨����C++����


/************����˵��*****************
* ��Դ��1.5.3 ����ֵ���ݣ����������÷���
* ������maxValue�Ǿֲ����������������ص�ʱ��Ͳ��������ˣ�������û�н��и���
֮ǰ�ͷ���ʱ��ǡ���ģ�ȡ���ڱ������ͷ�maxValue��ʹ�õ��ڴ���ٶȡ�

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

