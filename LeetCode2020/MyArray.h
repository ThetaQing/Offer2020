#ifndef MYARRAY_H_
#define MYARRAY_H_
#include <iostream>
#include <vector>
using namespace std;
// ��������
bool Find(int target, vector<vector<int>> array);
void replaceSpace(char *str, int length);
vector<int> printListFromTailToHead(ListNode* head);

// �ṹ������
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
	
};
#endif


#pragma once
