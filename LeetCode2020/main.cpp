#include <iostream>
#include <vector>
#include "MySolutionForOffer67.h"
using namespace std;

int main(int argc, char** argv)
{
	/**
	// Find函数测试
	vector<int> row1 = { 1,2,3,4,5,6 };
	vector<int> row2 = { 7,8,9,10,11,12 };
	vector<int> row3 = { 13,14,15,16,17,18 };
	vector<vector<int>> myArray = { row1, row2, row3 };
	Find(16,myArray);
	*
	// 字符串中替换空格测试
	char* str = "we can win ";
	replaceSpace(str, 6);
	// 重建二叉树测试
	vector<int> pre = { 3,9,20,15,7 };
	vector<int> vin = { 9,3,15,20,7 };
	TreeNode * ans = reConstructBinaryTree(pre, vin);
	
	// 测试调整数组使奇数排在前面
	vector<int> arr = { 2,3,4,5,6,7,8 };
	reOrderArray(arr);
	for (auto i : arr)
		cout << i;
	// 链表测试
	ListNode Node0(1), Node1(2), Node2(4), Node3(7), Node4(3), Node5(6);
	Node0.next = &Node1; 
	Node1.next = &Node2;
	Node2.next = &Node3;
	// Node3.next = &Node4; 
	Node4.next = &Node5;
	Merge(&Node0, &Node4);*/
	vector<int> row1 = { 1,2,3,4 };
	vector<int> row2 = { 5,6,7,8 };
	vector<int> row3 = { 9,10,11,12 };
	vector<int> row4 = { 13,14,15,16 };
	vector<int> row5 = { 17,18,19,20 };
	vector<vector<int>> matrix = { row1, row2 , row3 , row4, row5};
	printMatrix(matrix);
	cin.get();
	
	return 0;
}