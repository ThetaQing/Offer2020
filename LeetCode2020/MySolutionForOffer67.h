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

class levelTree
{

public:
	vector<int> PrintFromTopToBottom(TreeNode* root);

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
int  NumberOf1(int n);  // ����ת����������1�ĸ���
double Power(double base, int exponent);  // ���������ݳ�
void reOrderArray(vector<int> &array);  // ��������֮ǰ�ұ������λ�ò���
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k);  // �ҵ�����ĵ�����k���ڵ�
ListNode* ReverseList(ListNode* pHead);  // ��ת����
ListNode* Merge(ListNode* pHead1, ListNode* pHead2);  // �ϲ�������������
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2);  // pRoot2�Ƿ���pRoot1������
bool isEquals(TreeNode* pRoot1, TreeNode* pRoot2);  // �������Ƿ����
void Mirror(TreeNode *pRoot);  // �������ľ���
vector<int> printMatrix(vector<vector<int> > matrix);  // ��������˳ʱ���ӡ����
bool IsPopOrder(vector<int> pushV, vector<int> popV);  // ��ջ˳�����ջ˳��
#endif


#pragma once
