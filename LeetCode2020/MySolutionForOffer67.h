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

class levelTree
{

public:
	vector<int> PrintFromTopToBottom(TreeNode* root);

};

// 定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
class minStack {
	stack<int> mystack;
	int mymin, mytop;
public:
	void push(int value) {
		if (mystack.empty())
			mymin = value;
		mystack.push(value - mymin);  // 入栈的值减去当前最小值
		if (value - mymin < 0)  // 如果入栈的值比当前最小值小，更新最小值
			mymin = value;
		// 更新top值
		mytop = value;
	}
	void pop() {

		if (!mystack.empty())  // 如果非空
		{
			if (mystack.top() < 0)  // 说明此时pop出去的是最小值
			{
				mymin = mymin - mystack.top();  // 原来的最小值等于现在的最小值 - 差值（负的）
			}
			mystack.pop(); // 出栈

			mytop = mymin + (mystack.top() < 0 ? 0 : mystack.top());  // 更新top值，如果此时top值小于0，表示top值是min值，否则加差值

		}
		
	}
	int top() {
		return mytop;

	}
	int min() {
		return mymin;

	}
};
// 函数声明
bool Find(int target, vector<vector<int>> array);
void replaceSpace(char *str, int length);
vector<int> printListFromTailToHead(ListNode* head);
TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin);  // 前序遍历和中序遍历重建二叉树
int rectCover(int number);  // 矩形覆盖
int jumpFloorII(int number);  // 疯狂跳台阶，一次可最多跳number下
int  NumberOf1(int n);  // 整数转二进制数后1的个数
double Power(double base, int exponent);  // 浮点数的幂乘
void reOrderArray(vector<int> &array);  // 所有奇数之前且保持相对位置不变
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k);  // 找到链表的倒数第k个节点
ListNode* ReverseList(ListNode* pHead);  // 反转链表
ListNode* Merge(ListNode* pHead1, ListNode* pHead2);  // 合并两个递增链表
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2);  // pRoot2是否是pRoot1的子树
bool isEquals(TreeNode* pRoot1, TreeNode* pRoot2);  // 两棵树是否相等
void Mirror(TreeNode *pRoot);  // 二叉树的镜像
vector<int> printMatrix(vector<vector<int> > matrix);  // 从外向里顺时针打印数组
bool IsPopOrder(vector<int> pushV, vector<int> popV);  // 入栈顺序与出栈顺序
#endif


#pragma once
