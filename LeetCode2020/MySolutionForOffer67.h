#ifndef MySolutionForOffer67_H
#define MySolutionForOffer67_H
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
// 结构体声明
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

// 类的声明
// 两个栈实现队列
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
// 函数声明
bool Find(int target, vector<vector<int>> array);
void replaceSpace(char *str, int length);
vector<int> printListFromTailToHead(ListNode* head);
TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin);  // 前序遍历和中序遍历重建二叉树
int rectCover(int number);  // 矩形覆盖
int jumpFloorII(int number);  // 疯狂跳台阶，一次可最多跳number下
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
