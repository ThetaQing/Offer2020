#ifndef MySolutionForOffer67_H
#define MySolutionForOffer67_H
#include <iostream>
#include <vector>
using namespace std;
// �ṹ������
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}

};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};
// ��������
bool Find(int target, vector<vector<int>> array);
void replaceSpace(char *str, int length);
vector<int> printListFromTailToHead(ListNode* head);
TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin);

#endif


#pragma once
