#ifndef MYARRAY_H_
#define MYARRAY_H_
#include <iostream>
#include <vector>
using namespace std;
// 函数声明
bool Find(int target, vector<vector<int>> array);
void replaceSpace(char *str, int length);
vector<int> printListFromTailToHead(ListNode* head);

// 结构体声明
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
	
};
#endif


#pragma once
