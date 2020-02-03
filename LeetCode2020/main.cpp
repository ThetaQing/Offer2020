#include <iostream>
#include <vector>
#include "MySolutionForOffer67.h"
using namespace std;

int main(int argc, char** argv)
{
	/**
	// Findº¯Êý²âÊÔ
	vector<int> row1 = { 1,2,3,4,5,6 };
	vector<int> row2 = { 7,8,9,10,11,12 };
	vector<int> row3 = { 13,14,15,16,17,18 };
	vector<vector<int>> myArray = { row1, row2, row3 };
	Find(16,myArray);
	*
	// ×Ö·û´®ÖÐÌæ»»¿Õ¸ñ²âÊÔ
	char* str = "we can win ";
	replaceSpace(str, 6);*/
	// ÖØ½¨¶þ²æÊ÷²âÊÔ
	vector<int> pre = { 3,9,20,15,7 };
	vector<int> vin = { 9,3,15,20,7 };
	TreeNode * ans = reConstructBinaryTree(pre, vin);
	cout << "hello" << endl;
	cin.get();
	
	return 0;
}