#include <iostream>
#include "MySolutionForOffer67.h"
#include <vector>
#include <string.h>
using namespace std;
/****************����˵��*****************
* ����������
	��һ����ά�����У�ÿ��һά����ĳ�����ͬ����ÿһ�ж����մ����ҵ�����˳������
	ÿһ�ж����մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ��������
	�ж��������Ƿ��и������� 
* ��������bool Find(int target, vector<vector<int> > array)
* ����������������������һ����ά����
* ��������ֵ�����ҽ����ö�ά�����д��ڸ�����ʱ����True��
* ʵ��˼·�������½�Ϊ�Ƚϵ㣬ÿһ����ά�������½ǵ�Ԫ�ض��Ǹ���Ԫ������С�ģ�����Ԫ��������
	���Ŀ��ֵС�ڸ�Ԫ�أ������ų�����Ԫ�أ������ƣ����γ��µ�������ά�������䣻
	���Ŀ��ֵ���ڸ�Ԫ�أ������ų�����Ԫ�أ������ƣ����γ��µ�������ά�������䣻
	���Ŀ��ֵ���ڸ�Ԫ�أ�ʵ�ֲ��ҡ�
**/
bool Find(int target, vector<vector<int> > array) {
	int rows = array.size();
	// ��Ч���ж�
	if (!rows)
		return 0;

	int columns = array[0].size();
	if (!columns)
		return 0;

	// �����½�Ϊ�Ƚϵ�
	int row = rows - 1; 
	int col = 0;
	while (row >= 0 && col < columns)
	{
		if (array[row][col] == target)
			return 1;
		else if (array[row][col] < target)
			col += 1;  // ���½��Ǹ�����С�ģ��������ģ����target���ڸ�ֵ�������ų�����
		else
			row -= 1;  // �ų�����            
	}
	return 0;
}

/******************����˵��***************
* ����������
	��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ�%20����
	���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��
* ��������void replaceSpace(char *str, int length) 
* ����������һ���ַ������ַ�������
* ��������ֵ����
* ʵ���㷨������һ��ԭ�ַ�������2�����ַ����ռ䣬�����ַ����������ַ��ǿո��ַ������ַ�������"%20"���棬�������ַ���
	ԭ�ַ���ֵ��Ȼ�����ַ���ĩβȡ������'\0'����������ַ���ԭ�ַ���ֵ��
*/

void replaceSpace(char *str, int length) 
{
	char* tmp = new char[length*2]; 
	int k = 0;    
	for (int i = 0; i < length; i++) 
	{ 
		if (' ' == str[i]) 
		{ 
			tmp[k++] = '%';
			tmp[k++] = '2';     
			tmp[k++] = '0'; 
		}
		else 
		{ 
			tmp[k++] = str[i];
		} 
	}        
	tmp[k] = '\0';       
	for (int i = 0; i < k; i++) 
	{ 
		str[i] = tmp[i]; 
	}
	delete[] tmp;
}

/****************����˵��***************
* ��������������һ�������������β��ͷ��˳�򷵻�һ��ArrayList��
* ��������vector<int> printListFromTailToHead(ListNode* head) 
* ��������������һ������
* ��������ֵ�������β��ͷ��˳���vector����
* ʵ���㷨��������������ڵ㣬ÿ���ڵ�ֵ��vector��ͷ������

**/
vector<int> printListFromTailToHead(ListNode* head) {
	ListNode *temp = head;
	vector<int> ans;
	while (temp)  // ���ڵ㲻Ϊ��ʱ
	{
		ans.insert(ans.begin(), temp->val);
		temp = temp->next;
		
	}
	return ans;
}

/*****************����˵��****************
* ��������������ĳ��������ǰ���������������Ľ�������ؽ����ö�������
���������ǰ���������������Ľ���ж������ظ������֡�
��������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}�����ؽ������������ء�
* ��������TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin)
* ������������������ǰ��������������
* ��������ֵ���������ĸ��ڵ�
* ʵ���㷨���ȴ�ǰ��������ҵ����ڵ㣻
	�ٸ��ݸ��ڵ㽫���������Ϊ�����������ڵ���ߵ�Ԫ�أ��������������ڵ��ұߵ�Ԫ�أ���
	���ݹ�ʵ�����ҽڵ㡣
**/
TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
	if (!pre.size())
		return NULL;
	
	TreeNode *root = new TreeNode(pre[0]);
	vector<int> pre_left, pre_right, vin_left, vin_right;  // �ֱ��ʾ�Ը��ڵ�Ϊ�磬ǰ���������ڵ㡢�ҽڵ�������������ڵ㡢�ҽڵ�
	// ��Ϊ�����ظ����֣����Կ���ֱ�Ӳ���

	// ���ҵ����ڵ������
	int index = 0;
	for (int i = 0; i < pre.size(); ++i)
	{
		if (vin[i] == pre[0])
		{
			index = i;
			break;
		}
	}
	// �����������ָ
	for (int i = 0; i < index; ++i)
	{
		// ������
		pre_left.push_back(pre[i + 1]);
		vin_left.push_back(vin[i]);
		
	}
	for (int i = index + 1; i < pre.size(); ++i)
	{
		// ������
		pre_right.push_back(pre[i]);
		vin_right.push_back(vin[i]);
	}

	// �ݹ�
	root->left = reConstructBinaryTree(pre_left, vin_left);
	root->right = reConstructBinaryTree(pre_right, vin_right);
	// ����
	return root;
	

}