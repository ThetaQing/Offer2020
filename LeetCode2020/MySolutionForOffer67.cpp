#include <iostream>
#include "MySolutionForOffer67.h"
#include <vector>
#include <string.h>
#include <stack>
#include <algorithm>
#include <bitset>
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

/***************����˵��***************
* ����������������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������ �����е�Ԫ��Ϊint���͡�
* ��������void push(int Nod);int pop()
* ���������� ����ӵ�ֵ����
* ��������ֵ���գ� ��ͷԪ��
* ʵ��˼·��ʵ���Ͼ��Ǹ���ŵ��ģ�ͣ�ԭ���Ǵ�ͷ��β����Ϊ��β��ͷ������ֻ������ջ��
	stack1ջ���ܣ���ջ��ʱ��ֱ����ջ����ջ��ʱ��Ҫ����Ԫ����ջ�ף������Ȱ�����Ԫ��ת�Ƶ�stack2��Ȼ��pop��stack2��ջ��Ԫ��
	����ٰ�stack2������Ԫ��������ջ��stack1.

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

/***************����˵��*************
* ������������һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء�
��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1��
* ��������
* ����������
* ��������ֵ��
* ʵ���㷨��

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
			tempStore.push(rotateArray[minIndex]);  // ���
		}
		else
			break;
	}
	if (minIndex == 0)  // �ж��Ƿ��ǵ�һ��Ԫ��
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
/**************����˵��***************
* ����������һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨���ܹ��ж�����������
* ��������int jumpFloorII(int number)
* ����������̨����
* ��������ֵ����n��̨�׵�����
* ����ʵ�֣�f(n) = f(n-1)+f(n-2)+����+f(2)+f(1)

*/
int jumpFloorII(int number) {

	return pow(2, number - 1);

}

/****************����˵��***************
* �������������ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�
			������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����
* ��������int rectCover(int number)
* ��������������εĳ�
* ��������ֵ�����ǵķ�������
* ����ʵ�֣��ݹ飬����2*2С����


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


/***************����˵��***************
* ��������������һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��
* ��������int  NumberOf1(int n)
* ��������������һ������
* ��������ֵ��
* ʵ�ַ�����

*/
int  NumberOf1(int n)
{
	bitset<sizeof(int) * 8> bitN(n);
	cout << bitN  << endl;

	return bitN.count();

}

/****************����˵��********************
* ��������������һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η��� 

			��֤base��exponent��ͬʱΪ0 
* ��������double Power(double base, int exponent)
* ����������������base������exponent
* ��������ֵ��base��exponent�η�
* ʵ���㷨���⺯��pow

***/
double Power(double base, int exponent)
{
	return pow(base, exponent);
}

/*************����˵��*************
* ��������������һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣�
			���е�ż��λ������ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò��䡣
* ��������void reOrderArray(vector<int> &array)
* ������������������
* ��������ֵ����
* ʵ���㷨��׼���������У�odd�洢������even�洢ż����ȫ���洢���������飬�ٰ�˳�����������
*/
void reOrderArray(vector<int> &array)
{
	queue<int> odd, even;
	for (auto number : array)
	{
		if (number % 2)  // ����
			odd.push(number);
		else  // ż��
			even.push(number);

	}
	array.clear();  // �������
	while (!odd.empty())
	{
		int temp = odd.front();  // ��ͷԪ��
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

/*************����˵��************
* ��������������һ����������������е�����k����㡣
* ��������
* ����������
* ��������ֵ��
* ʵ�ַ�����������k������������len-k-1��������Ϊʲô������


ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
	int len = 0;
	ListNode *temp = pListHead;
	while (temp != NULL)
	{
		len += 1;
		temp = temp->next;
	}
	cout << "�����ȣ�" << len << endl;
	temp = pListHead;

	for (int i = 0; i < len - k; ++i)
	{
		temp = temp->next;
	}
	return temp;

}*/
// ˫ָ�뷨�����ǲ��ԣ�����
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

/****************����˵��***************
* ��������������һ��������ת��������������ı�ͷ��
* ��������ListNode* ReverseList(ListNode* pHead) 
* ��������������ͷ�ڵ�
* ��������ֵ����ת��������ͷ�ڵ�
* ����ʵ�֣������ڵ㣬�ֱ��ʾ��ͷ�ڵ��ǰһ���ڵ�before����ͷ�ڵ�newhead����ͷ�ڵ�ĺ�һ���ڵ�next��
			��before��newHead��ת�������ڵ���ǰ��һ��λ��


*/
ListNode* ReverseList(ListNode* pHead)
{
	if (pHead == NULL || pHead->next == NULL)
		return pHead;
	   		
	ListNode* newHead = pHead, *next = pHead->next, *before = pHead;
	pHead->next = NULL;  // ԭͷ�ڵ��next��Ϊ��
	while (newHead != NULL && next != NULL)
	{
		
		newHead = next;  // ͷ�ڵ�
		next = newHead->next;  // ��һ���ڵ�

		newHead->next = before;  // ��ͷ�ڵ���ǰһ���ڵ㷴ת

		// ��ǰ��һ���ڵ�
		before = newHead;  // ǰһ���ڵ�
		newHead = next;  // ��ͷ�ڵ�ת�Ƶ���һ���ڵ�
		
		
	}
	newHead = before;
	return newHead;
	
}

/***************����˵��*****************
* �������������������������������������������ϳɺ��������Ȼ������Ҫ�ϳɺ���������㵥����������
* ��������ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
* �����������������������������ͷ�ڵ�
* ��������ֵ���������ͷ�ڵ�
* ʵ�ַ���������ͷ�ڵ㷨��ÿ��ѡ��С�ģ���סҪ��next��ӣ�������޷�ʵ��׷��

**/
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	ListNode * list1 = pHead1, *list2 = pHead2, *ansHead = new ListNode(0), *temp = ansHead;  // ����һ������ͷ�ڵ�
	while (list1 != NULL && list2 != NULL)
	{
		if (list1->val < list2->val)  // ѡ��С��
		{
			temp->next = list1;  // Ҫ��nextָ�룬������޷�׷��
			list1 = list1->next;
			
		}
		else
		{
			temp->next = list2;
			list2 = list2->next;
		}
		temp = temp->next;
	}
	if (list1)  // ʣ�ಿ��
		temp->next = list1;
	else
		temp->next = list2;
	return ansHead->next;
}

/***************����˵��***************
* �����������������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��
* ��������bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
* �����������������ĸ��ڵ�
* ��������ֵ��B�Ƿ���A���ӽṹ
* ʵ�ַ�����
	���������
	1���ӽṹ���ܳ��ֵ��������A�ĸ��ڵ㿪ʼ����A����ڵ㿪ʼ�� ��A���ҽڵ�
	2���ṹ��ͬʱ���ڵ㡢��ڵ㡢�ҽڵ��Ӧ���

	����������
	�������������Ƚ��������ĸ��ڵ㡢��ڵ㡢�ҽڵ��Ƿ��Ӧ���

*/
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if (!pRoot1 || !pRoot2)
		return 0;  // ��һ��Ϊ������ֱ�ӷ���

	return isEquals(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);

}


bool isEquals(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if (!pRoot1 && !pRoot2)  // ������
		return 1;
	else if (pRoot1 && pRoot2)  // �����ǿ�
		return (pRoot1->val == pRoot2->val) && isEquals(pRoot1->left, pRoot2->left) && isEquals(pRoot1->right, pRoot2->right);
	else  // һ����һ���ǿ�
		return 0;
}

/************����˵��***********
* �������������������Ķ�����������任ΪԴ�������ľ���
* ��������void Mirror(TreeNode *pRoot)
* �����������������ĸ��ڵ�
* ��������ֵ����
* ʵ�ַ�����1��������и��ڵ�������ֱ�ӷ��أ�
			2�������ڵ����ҽڵ㾵��
			3���ݹ���ڵ����������������


*/
void Mirror(TreeNode *pRoot)
{
	if (pRoot == NULL || (pRoot->left == NULL && pRoot->right == NULL))  // ֻ�и��ڵ�����
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

/****************����˵��*****************
* ��������������һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֣����磬�����������4 X 4����
			1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
			�����δ�ӡ������
			1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
* �������� vector<int> printMatrix(vector<vector<int> > matrix)
* ����������һ����ά����
* ��������ֵ����������˳ʱ�����δ�ӡ
* ʵ�ַ�����
	���ӣ�https://www.nowcoder.com/questionTerminal/9b4c81a02cd34f76be2659fa0d54342a?answerType=1&f=discussion
	��Դ��ţ����

	�����ĸ���������Χ��up��down��left��right  
	�����ߴ������е�ֵ��������󣬸�����Ҳ���ᱻ�����������ϱ߽�� up ��һ��ͬʱ�ж��Ƿ�ʹ����±߽�� down ���� 
	�����ߴ������е�ֵ��������󣬸�����Ҳ���ᱻ�����������ұ߽�� right ��һ��ͬʱ�ж��Ƿ�ʹ�����߽�� left ���� 
	�����ߴ������е�ֵ��������󣬸�����Ҳ���ᱻ�����������±߽�� down ��һ��ͬʱ�ж��Ƿ�ʹ����ϱ߽�� up ���� 
	�����ߴ������е�ֵ��������󣬸�����Ҳ���ᱻ������������߽�� left ��һ��ͬʱ�ж��Ƿ�ʹ����ұ߽�� right ���� 

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
		
		
		for (i = up, j = left; j <= right ; ++j)  //  && up < down �� ��up, left����㣬(up,right)�յ�
		{
			temp = matrix[i][j];
			ans.push_back(temp);
		}
		up += 1;
		if (up > down)
			break;
		for (j = right, i = up; i <= down ; ++i)  //&& right > left �� (new up, right)��㣬 (down, right)�յ�
		{
			temp = matrix[i][j];
			ans.push_back(temp);
		}
		right -= 1;
		if (right < left)
			break;
		for (j = right, i = down; j >= left ; --j)  //&& down > up �� (down, new right)��㣬 (down, left)�յ�
		{
			temp = matrix[i][j];
			ans.push_back(temp);
		}
		down -= 1;
		if (down < up)
			break;
		for (i = down, j = left; i >= up; --i)  // && left < right �� (new down, left)��㣬 (new up, left)�յ�
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

/*************����˵��***************
* ��������������ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��������СԪ�ص�min������ʱ�临�Ӷ�ӦΪO��1������
* ��������
* ����������
* ��������ֵ��
* ʵ�ַ�����

*/