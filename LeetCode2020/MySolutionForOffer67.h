#ifndef MySolutionForOffer67_H
#define MySolutionForOffer67_H
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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

// �������
// ����ջʵ�ֶ���
class Solution
{
public:
	void push(int node);

	int pop();

	int minNumberInRotateArray(vector<int> rotateArray);

private:
	stack<int> stack1;
	stack<int> stack2;
	queue<int> tempStore;

};
// ��������
bool Find(int target, vector<vector<int>> array);
void replaceSpace(char *str, int length);
vector<int> printListFromTailToHead(ListNode* head);
TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin);  // ǰ���������������ؽ�������
int rectCover(int number);  // ���θ���
int jumpFloorII(int number);  // �����̨�ף�һ�ο������number��
int  NumberOf1(int n);
double Power(double base, int exponent);
void reOrderArray(vector<int> &array);
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k);
ListNode* ReverseList(ListNode* pHead);
ListNode* Merge(ListNode* pHead1, ListNode* pHead2);
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2);
bool isEquals(TreeNode* pRoot1, TreeNode* pRoot2);
void Mirror(TreeNode *pRoot);
vector<int> printMatrix(vector<vector<int> > matrix);
#endif


#pragma once
