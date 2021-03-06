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
* 函数参数：链表头节点
* 函数返回值：反转链表后的新头节点
* 函数实现：三个节点，分别表示新头节点的前一个节点before、新头节点newhead、新头节点的后一个节点next；
			将before和newHead反转，三个节点向前移一个位置


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

		// 向前移一个节点
		before = newHead;  // 前一个节点
		newHead = next;  // 将头节点转移到下一个节点
		
		
	}
	newHead = before;
	return newHead;
	
}

/***************函数说明*****************
* 问题描述：输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
* 函数名：ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
* 函数参数：两个单调递增的链表的头节点
* 函数返回值：新链表的头节点
* 实现方法：虚拟头节点法，每次选择小的，记住要用next添加，否则就无法实现追踪

**/
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	ListNode * list1 = pHead1, *list2 = pHead2, *ansHead = new ListNode(0), *temp = ansHead;  // 建立一个虚拟头节点
	while (list1 != NULL && list2 != NULL)
	{
		if (list1->val < list2->val)  // 选择小的
		{
			temp->next = list1;  // 要用next指针，否则就无法追踪
			list1 = list1->next;
			
		}
		else
		{
			temp->next = list2;
			list2 = list2->next;
		}
		temp = temp->next;
	}
	if (list1)  // 剩余部分
		temp->next = list1;
	else
		temp->next = list2;
	return ansHead->next;
}

/***************函数说明***************
* 问题描述：输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
* 函数名：bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
* 函数参数：两个树的根节点
* 函数返回值：B是否是A的子结构
* 实现方法：
	先捋清楚：
	1、子结构可能出现的情况：从A的根节点开始；从A的左节点开始； 从A的右节点
	2、结构相同时根节点、左节点、右节点对应相等

	辅助函数：
	遍历两棵树，比较两棵树的根节点、左节点、右节点是否对应相等

*/
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if (!pRoot1 || !pRoot2)
		return 0;  // 有一个为空树就直接返回

	return isEquals(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);

}


bool isEquals(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if (!pRoot1 && !pRoot2)  // 两个空
		return 1;
	else if (pRoot1 && pRoot2)  // 两个非空
		return (pRoot1->val == pRoot2->val) && isEquals(pRoot1->left, pRoot2->left) && isEquals(pRoot1->right, pRoot2->right);
	else  // 一个空一个非空
		return 0;
}

/************函数说明***********
* 问题描述：操作给定的二叉树，将其变换为源二叉树的镜像。
* 函数名：void Mirror(TreeNode *pRoot)
* 函数参数：二叉树的根节点
* 函数返回值：空
* 实现方法：1、如果仅有根节点或空树，直接返回；
			2、将根节点左右节点镜像；
			3、递归根节点的左子树和右子树


*/
void Mirror(TreeNode *pRoot)
{
	if (pRoot == NULL || (pRoot->left == NULL && pRoot->right == NULL))  // 只有根节点或空树
		return ;
	TreeNode *left = pRoot->left, *right = pRoot->right, *root = pRoot;
	if (root != NULL)
	{
		root->left = right;
		root->right = left;
	}

	Mirror(root->left);
	Mirror(root->right);
}

/****************函数说明*****************
* 问题描述：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下4 X 4矩阵：
			1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
			则依次打印出数字
			1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
* 函数名： vector<int> printMatrix(vector<vector<int> > matrix)
* 函数参数：一个二维矩阵
* 函数返回值：从外向里顺时针依次打印
* 实现方法：
	链接：https://www.nowcoder.com/questionTerminal/9b4c81a02cd34f76be2659fa0d54342a?answerType=1&f=discussion
	来源：牛客网

	定义四个变量代表范围，up、down、left、right  
	向右走存入整行的值，当存入后，该行再也不会被遍历，代表上边界的 up 加一，同时判断是否和代表下边界的 down 交错 
	向下走存入整列的值，当存入后，该列再也不会被遍历，代表右边界的 right 减一，同时判断是否和代表左边界的 left 交错 
	向左走存入整行的值，当存入后，该行再也不会被遍历，代表下边界的 down 减一，同时判断是否和代表上边界的 up 交错 
	向上走存入整列的值，当存入后，该列再也不会被遍历，代表左边界的 left 加一，同时判断是否和代表右边界的 right 交错 

*/
vector<int> printMatrix(vector<vector<int> > matrix)
{
	vector<int> ans;
	
	int row = matrix.size();
	if (row == 0)
		return ans;
	int column = matrix[0].size();
	if (column == 0)
		return ans;
	int up = 0, down = row - 1, right = column - 1, left = 0;
	while (true)
	{
		int i = 0, j = 0;
		int temp;
		
		
		for (i = up, j = left; j <= right ; ++j)  //  && up < down 上 （up, left）起点，(up,right)终点
		{
			temp = matrix[i][j];
			ans.push_back(temp);
		}
		up += 1;
		if (up > down)
			break;
		for (j = right, i = up; i <= down ; ++i)  //&& right > left 右 (new up, right)起点， (down, right)终点
		{
			temp = matrix[i][j];
			ans.push_back(temp);
		}
		right -= 1;
		if (right < left)
			break;
		for (j = right, i = down; j >= left ; --j)  //&& down > up 下 (down, new right)起点， (down, left)终点
		{
			temp = matrix[i][j];
			ans.push_back(temp);
		}
		down -= 1;
		if (down < up)
			break;
		for (i = down, j = left; i >= up; --i)  // && left < right 左 (new down, left)起点， (new up, left)终点
		{
			temp = matrix[i][j];
			ans.push_back(temp);
		}
		left += 1;
		if (left > right)
			break;
		
		
	}
	return ans;

}

/*************函数说明***************
* 问题描述：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
			假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
			但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
* 函数名：bool IsPopOrder(vector<int> pushV,vector<int> popV)
* 函数参数：入栈序列和出栈序列
* 函数返回值：出栈序列是否可能是该栈的弹出序列
* 实现方法：模拟栈
		1、根据入栈序列入栈；
		2、比较栈顶元素是否是出栈节点，若是，出栈，直到不能继续出栈为止；
		3、继续入栈直到遍历完入栈序列；
		4、比较栈顶元素是否是出栈节点，若是，出栈，直到不能继续出栈为止；
		5、直接返回栈是否为空，若为空，模拟成功，该序列是一种弹出序列。

*/
bool IsPopOrder(vector<int> pushV, vector<int> popV)
{
	int pushOrd = 0, popOrd = 0;  // 遍历记录
	stack<int> V;
	for (pushOrd = 0, popOrd = 0; pushOrd < pushV.size(); ++pushOrd)  // 按顺序遍历
	{
		V.push(pushV[pushOrd]);  // 入栈
		while (!V.empty() && popV[popOrd] == V.top())  // 如果栈顶元素等于出栈元素
		{
			V.pop();   // 出栈
			popOrd += 1;
		}
	}
	// 全部入栈完毕，如果栈为空，直接返回
	
	while (!V.empty() && V.top() == popV[popOrd])
	{
		V.pop(); 
		popOrd += 1;
	}

	return V.empty();
}

/***************函数说明***************
* 问题描述：从上往下打印出二叉树的每个节点，同层节点从左至右打印。
* 函数名：vector<int> PrintFromTopToBottom(TreeNode* root)
* 函数参数：树的根节点
* 函数返回值：从上到下打印二叉树的每个节点，同层节点从左到右打印
* 实现方法：利用队列
		1、从根节点开始入队；
		2、加入根节点值，并将根节点的非空左右节点入队；
		3、弹出这个根节点，并将根节点更新为队列的头节点；
		4、重复上述三步，直到队空。

*/
vector<int> levelTree::PrintFromTopToBottom(TreeNode* root)
{	
	vector<int> topToBottom;
	if (root == NULL)
		return topToBottom;
	queue<TreeNode*> nodeQueue;
	TreeNode* temp = root;
	nodeQueue.push(temp);
	while (!nodeQueue.empty())  // 直到队列为空
	{
		
		topToBottom.push_back(temp->val);  // 加入根节点值
		// 对非空子节点从左到右依次入队
		if(temp->left)
			nodeQueue.push(temp->left);
		if (temp->right)
		{
			nodeQueue.push(temp->right);
		}
		nodeQueue.pop();  // 先出队
		if(!nodeQueue.empty())
			temp = nodeQueue.front();
				
	}
	return topToBottom;

}

/****************函数说明*********
* 问题描述：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
			如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
* 函数名：bool VerifySquenceOfBST(vector<int> sequence)
* 函数参数：
* 函数返回值：
* 实现方法：

**/

bool helperVerifyPostorder(vector<int>& post, int lo, int hi) {
	if (lo >= hi) return true; //单节点或空节点返回true
	int root = post[hi]; //后序遍历序列最后的值为根节点的值
	int l = lo;
	while (l < hi && post[l] < root)
		l++; //遍历左子树(值小于根)，左子树序列post[lo, l);
	int r = l;
	while (r<hi && post[r]>root)
		r++; //遍历右子树(值大于根)，右子树序列post[l, r);
	if (r != hi) return false;//若未将post[l, hi)遍历完，则非后序遍历序列 返回false
	return helperVerifyPostorder(post, lo, l - 1) && helperVerifyPostorder(post, l, hi - 1); //递归检查左右子树
}

bool verifyPostorder(vector<int>& postorder) {
		return helperVerifyPostorder(postorder, 0, postorder.size() - 1);
	}

	


