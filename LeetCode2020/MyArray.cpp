#include <iostream>
#include "MyArray.h"
#include <vector>
using namespace std;
/****************����˵��*****************
* ����������
	��һ����ά�����У�ÿ��һά����ĳ�����ͬ����ÿһ�ж����մ����ҵ�����˳������
	ÿһ�ж����մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ��������
	�ж��������Ƿ��и������� 
* ��������bool Find(int target, vector<vector<int> > array)
* ����������������������һ����ά����
* ʵ��˼·�������½�Ϊ�Ƚϵ㣬ÿһ����ά�������½ǵ�Ԫ�ض��Ǹ���Ԫ������С�ģ�����Ԫ��������
	���Ŀ��ֵС�ڸ�Ԫ�أ������ų�����Ԫ�أ������ƣ����γ��µ�������ά�������䣻
	���Ŀ��ֵ���ڸ�Ԫ�أ������ų�����Ԫ�أ������ƣ����γ��µ�������ά�������䣻
	���Ŀ��ֵ���ڸ�Ԫ�أ�ʵ�ֲ��ҡ�
**/
bool Find(int target, vector<vector<int> > array) {
	int rows = array.size();
	// ��Ч���ж�
	if (!rows)
		return 0;

	int columns = array[0].size();
	if (!columns)
		return 0;

	// �����½�Ϊ�Ƚϵ�
	int row = rows - 1; 
	int col = 0;
	while (row >= 0 && col < columns)
	{
		if (array[row][col] == target)
			return 1;
		else if (array[row][col] < target)
			col += 1;  // ���½��Ǹ�����С�ģ��������ģ����target���ڸ�ֵ�������ų�����
		else
			row -= 1;  // �ų�����            
	}
	return 0;
}