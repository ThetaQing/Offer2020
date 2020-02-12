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

// ����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��������СԪ�ص�min������ʱ�临�Ӷ�ӦΪO��1������
class minStack {
	stack<int> mystack;
	int mymin, mytop;
public:
	void push(int value) {
		if (mystack.empty())
			mymin = value;
		mystack.push(value - mymin);  // ��ջ��ֵ��ȥ��ǰ��Сֵ
		if (value - mymin < 0)  // �����ջ��ֵ�ȵ�ǰ��СֵС��������Сֵ
			mymin = value;
		// ����topֵ
		mytop = value;
	}
	void pop() {

		if (!mystack.empty())  // ����ǿ�
		{
			if (mystack.top() < 0)  // ˵����ʱpop��ȥ������Сֵ
			{
				mymin = mymin - mystack.top();  // ԭ������Сֵ�������ڵ���Сֵ - ��ֵ�����ģ�
			}
			mystack.pop(); // ��ջ

			mytop = mymin + (mystack.top() < 0 ? 0 : mystack.top());  // ����topֵ�������ʱtopֵС��0����ʾtopֵ��minֵ������Ӳ�ֵ

		}
		
	}
	int top() {
		return mytop;

	}
	int min() {
		return mymin;

	}
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
