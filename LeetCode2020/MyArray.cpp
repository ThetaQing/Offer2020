#include <iostream>
#include "MyArray.h"
#include <vector>
#include <string.h>
using namespace std;
/****************函数说明*****************
* 问题描述：
	在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
	每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，
	判断数组中是否含有该整数。 
* 函数名：bool Find(int target, vector<vector<int> > array)
* 函数参数：待查找整数、一个二维数组
* 实现思路：以左下角为比较点，每一个二维数组左下角的元素都是该行元素中最小的，该列元素中最大的
	如果目标值小于该元素，可以排除该行元素（向上移），形成新的搜索二维数组区间；
	如果目标值大于该元素，可以排除该列元素（向右移），形成新的搜索二维数组区间；
	如果目标值等于该元素，实现查找。
**/
bool Find(int target, vector<vector<int> > array) {
	int rows = array.size();
	// 有效性判断
	if (!rows)
		return 0;

	int columns = array[0].size();
	if (!columns)
		return 0;

	// 以左下角为比较点
	int row = rows - 1; 
	int col = 0;
	while (row >= 0 && col < columns)
	{
		if (array[row][col] == target)
			return 1;
		else if (array[row][col] < target)
			col += 1;  // 左下角是该行最小的，该列最大的，如果target大于该值，可以排除该列
		else
			row -= 1;  // 排除该行            
	}
	return 0;
}

/******************函数说明***************
* 问题描述：
	请实现一个函数，将一个字符串中的每个空格替换成“%20”。
	例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
* 函数名：void replaceSpace(char *str, int length) 
* 函数参数：一个字符串，字符串长度
* 实现算法：分配一个原字符串长度2倍的字符串空间，遍历字符串，若该字符是空格字符，新字符串就用"%20"代替，否则，新字符用
	原字符赋值；然后将新字符串末尾取结束符'\0'；最后，用新字符给原字符赋值。
*/

void replaceSpace(char *str, int length) 
{
	char* tmp = new char[length*2]; 
	int k = 0;    
	for (int i = 0; i < length; i++) 
	{ 
		if (' ' == str[i]) 
		{ 
			tmp[k++] = '%';
			tmp[k++] = '2';     
			tmp[k++] = '0'; 
		}
		else 
		{ 
			tmp[k++] = str[i];
		} 
	}        
	tmp[k] = '\0';       
	for (int i = 0; i < k; i++) 
	{ 
		str[i] = tmp[i]; 
	}
	delete[] tmp;
}
