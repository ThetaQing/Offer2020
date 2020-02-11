#include <iostream>
#include "MySolutionForOffer67.h"
#include <vector>
#include <string.h>
#include <stack>
#include <algorithm>
#include <bitset>
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

/***************函数说明***************
* 问题描述：用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
* 函数名：void push(int Nod);int pop()
* 函数参数： 待入队的值；空
* 函数返回值：空； 队头元素
* 实现思路：实际上就是个汉诺塔模型，原来是从头到尾，变为从尾到头，但是只有两个栈；
	stack1栈功能，入栈的时候直接入栈，出栈的时候要出的元素在栈底，所以先把所有元素转移到stack2，然后pop出stack2的栈顶元素
	最后再把stack2的所有元素重新入栈到stack1.

*/
void Solution::push(int Node)
{
	stack1.push(Node);
}
int Solution::pop()
{
	
		if (stack1.empty())
		{
			return 0;
		}
		int ans = 0;
		while (!stack1.empty())
		{
			int tmp = stack1.top();
			stack1.pop();
			stack2.push(tmp);
		}
		if (!stack2.empty())
		{
			ans = stack2.top();
			stack2.pop();

		}
		while (!stack2.empty())
		{
			int tmp = stack2.top();
			stack2.pop();
			stack1.push(tmp);
		}
		return ans;

	
}

/***************函数说明*************
* 问题描述：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
* 函数名：
* 函数参数：
* 函数返回值：
* 实现算法：

*/
int Solution::minNumberInRotateArray(vector<int> rotateArray)
{
	if (rotateArray.empty())
		return 0;
	int minNumber = *min_element(rotateArray.begin(), rotateArray.end());

	int minIndex = 0;
	for (minIndex = 0; minIndex < rotateArray.size(); ++minIndex)
	{
		if (rotateArray[minIndex] != minNumber)
		{
			tempStore.push(rotateArray[minIndex]);  // 入队
		}
		else
			break;
	}
	if (minIndex == 0)  // 判断是否是第一个元素
		return minNumber;
	rotateArray.erase(rotateArray.begin(), rotateArray.begin() + minIndex - 1);
	while(!tempStore.empty())
	{
		int temp = tempStore.front();
		tempStore.pop();

		rotateArray.push_back(temp);
	}
	return minNumber;


}
/**************函数说明***************
* 问题描述：一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
* 函数名：int jumpFloorII(int number)
* 函数参数：台阶数
* 函数返回值：跳n级台阶的跳法
* 函数实现：f(n) = f(n-1)+f(n-2)+……+f(2)+f(1)

*/
int jumpFloorII(int number) {

	return pow(2, number - 1);

}

/****************函数说明***************
* 问题描述：我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
			请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
* 函数名：int rectCover(int number)
* 函数参数：大矩形的长
* 函数返回值：覆盖的方法总数
* 函数实现：递归，拆解成2*2小矩形


*/
int rectCover(int number) {
	if (number == 0)
		return 0;
	if (number == 1)
		return 1;
	if (number == 2)
		return 2;
	return rectCover(number - 1) + rectCover(number - 2);

}


/***************函数说明***************
* 问题描述：输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
* 函数名：int  NumberOf1(int n)
* 函数参数：输入一个整数
* 函数返回值：
* 实现方法：

*/
int  NumberOf1(int n)
{
	bitset<sizeof(int) * 8> bitN(n);
	cout << bitN  << endl;

	return bitN.count();

}

/****************函数说明********************
* 问题描述：给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。 

			保证base和exponent不同时为0 
* 函数名：double Power(double base, int exponent)
* 函数参数：浮点数base；整数exponent
* 函数返回值：base的exponent次方
* 实现算法：库函数pow

***/
double Power(double base, int exponent)
{
	return pow(base, exponent);
}

/*************函数说明*************
* 问题描述：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
			所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
* 函数名：void reOrderArray(vector<int> &array)
* 函数参数：整数数组
* 函数返回值：空
* 实现算法：准备两个队列，odd存储奇数，even存储偶数，全部存储完后清空数组，再按顺序放入数组中
*/
void reOrderArray(vector<int> &array)
{
	queue<int> odd, even;
	for (auto number : array)
	{
		if (number % 2)  // 奇数
			odd.push(number);
		else  // 偶数
			even.push(number);

	}
	array.clear();  // 清空数组
	while (!odd.empty())
	{
		int temp = odd.front();  // 队头元素
		odd.pop();
		array.push_back(temp);
	}
	while (!even.empty())
	{
		int temp = even.front();
		even.pop();
		array.push_back(temp);
	}
}

/*************函数说明************
* 问题描述：输入一个链表，输出该链表中倒数第k个结点。
* 函数名：
* 函数参数：
* 函数返回值：
* 实现方法：倒数第k个就是正数第len-k-1个，可是为什么不对呢


ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
	int len = 0;
	ListNode *temp = pListHead;
	while (temp != NULL)
	{
		len += 1;
		temp = temp->next;
	}
	cout << "链表长度：" << len << endl;
	temp = pListHead;

	for (int i = 0; i < len - k; ++i)
	{
		temp = temp->next;
	}
	return temp;

}*/
// 双指针法，还是不对？？？
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
	ListNode *fast = pListHead, *low = pListHead;
	for (int i = 0; i < k; ++i)
	{
		fast = fast->next;
	}
	while (fast != NULL)
	{		
		fast = fast->next; 
		low = low->next;

	}
	return low;
}

/****************函数说明***************
* 问题描述：输入一个链表，反转链表后，输出新链表的表头。
* 函数名：ListNode* ReverseList(ListNode* pHead) 
* 函数参数：
* 函数返回值：
* 函数实现：


*/
ListNode* ReverseList(ListNode* pHead)
{
	if (pHead == NULL || pHead->next == NULL)
		return pHead;
	   		
	ListNode* newHead = pHead, *next = pHead->next, *before = pHead;
	pHead->next = NULL;  // 原头节点的next变为空
	while (newHead != NULL && next != NULL)
	{
		
		newHead = next;  // 头节点
		next = newHead->next;  // 后一个节点

		newHead->next = before;  // 将头节点与前一个节点反转
		before = newHead;  // 前一个节点
		newHead = next;  // 将头节点转移到下一个节点
		
		
	}
	newHead = before;
	return newHead;
	
}