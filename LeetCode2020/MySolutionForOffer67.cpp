#include <iostream>
#include "MySolutionForOffer67.h"
#include <vector>
#include <string.h>
using namespace std;
/****************函数说明*****************
* 问题描述：
	在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
	每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，
	判断数组中是否含有该整数。 
* 函数名：bool Find(int target, vector<vector<int> > array)
* 函数参数：待查找整数、一个二维数组
* 函数返回值：当且仅当该二维数组中存在该整数时返回True。
* 实现思路：以左下角为比较点，每一个二维数组左下角的元素都是该行元素中最小的，该列元素中最大的
	如果目标值小于该元素，可以排除该行元素（向上移），形成新的搜索二维数组区间；
	如果目标值大于该元素，可以排除该列元素（向右移），形成新的搜索二维数组区间；
	如果目标值等于该元素，实现查找。
**/
bool Find(int target, vector<vector<int> > array) {
	int rows = array.size();
	// 有效性判断
	if (!rows)
		return 0;

	int columns = array[0].size();
	if (!columns)
		return 0;

	// 以左下角为比较点
	int row = rows - 1; 
	int col = 0;
	while (row >= 0 && col < columns)
	{
		if (array[row][col] == target)
			return 1;
		else if (array[row][col] < target)
			col += 1;  // 左下角是该行最小的，该列最大的，如果target大于该值，可以排除该列
		else
			row -= 1;  // 排除该行            
	}
	return 0;
}

/******************函数说明***************
* 问题描述：
	请实现一个函数，将一个字符串中的每个空格替换成“%20”。
	例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
* 函数名：void replaceSpace(char *str, int length) 
* 函数参数：一个字符串，字符串长度
* 函数返回值：无
* 实现算法：分配一个原字符串长度2倍的字符串空间，遍历字符串，若该字符是空格字符，新字符串就用"%20"代替，否则，新字符用
	原字符赋值；然后将新字符串末尾取结束符'\0'；最后，用新字符给原字符赋值。
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

/****************函数说明***************
* 问题描述：输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
* 函数名：vector<int> printListFromTailToHead(ListNode* head) 
* 函数参数：输入一个链表
* 函数返回值：链表从尾到头的顺序的vector序列
* 实现算法：遍历链表各个节点，每个节点值从vector的头部插入

**/
vector<int> printListFromTailToHead(ListNode* head) {
	ListNode *temp = head;
	vector<int> ans;
	while (temp)  // 当节点不为空时
	{
		ans.insert(ans.begin(), temp->val);
		temp = temp->next;
		
	}
	return ans;
}

/*****************函数说明****************
* 问题描述：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
* 函数名：TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin)
* 函数参数：二叉树的前序遍历、中序遍历
* 函数返回值：二叉树的根节点
* 实现算法：先从前序遍历中找到根节点；
	再根据根节点将中序遍历分为左子树（根节点左边的元素）和右子树（根节点右边的元素）；
	最后递归实现左右节点。
**/
TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
	if (!pre.size())
		return NULL;
	
	TreeNode *root = new TreeNode(pre[0]);
	vector<int> pre_left, pre_right, vin_left, vin_right;  // 分别表示以根节点为界，前序遍历的左节点、右节点和中序遍历的左节点、右节点
	// 因为不含重复数字，所以可以直接查找

	// 先找到根节点的索引
	int index = 0;
	for (int i = 0; i < pre.size(); ++i)
	{
		if (vin[i] == pre[0])
		{
			index = i;
			break;
		}
	}
	// 将左右子树分割开
	for (int i = 0; i < index; ++i)
	{
		// 左子树
		pre_left.push_back(pre[i + 1]);
		vin_left.push_back(vin[i]);
		
	}
	for (int i = index + 1; i < pre.size(); ++i)
	{
		// 右子树
		pre_right.push_back(pre[i]);
		vin_right.push_back(vin[i]);
	}

	// 递归
	root->left = reConstructBinaryTree(pre_left, vin_left);
	root->right = reConstructBinaryTree(pre_right, vin_right);
	// 返回
	return root;
	

}