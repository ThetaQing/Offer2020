﻿#include "leetcode.h"
#include <iostream>
#include <numeric>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <tuple>
using namespace std;

/**************函数说明******************
* 问题描述：
	给定一个整数类型的数组 nums，请编写一个能够返回数组“中心索引”的方法。
	我们是这样定义数组中心索引的：数组中心索引的左侧所有元素相加的和等于右侧所有元素相加的和。
	如果数组不存在中心索引，那么我们应该返回 -1。如果数组有多个中心索引，那么我们应该返回最靠近左边的那一个。
* 函数名：int pivotIndex(vector<int>& nums)
* 实现思路：
	抓住一点：left = sum - nums[i] - left
*/
int pivotIndex(vector<int>& nums)
{
	int len = nums.size();
	if (len == 0)  // 空表不存在
		return -1;
	if (len < 2)  // 只有一个元素
		return 0;
	int leftsum = 0;
	int S = accumulate(nums.begin(), nums.end(), 0);
	for (int i = 0; i < len; ++i)
	{
		if (leftsum == S - nums[i] - leftsum)  // 判断此时是否满足条件
			return i;
		leftsum += nums[i];  // 如果不满足继续移动

	}
	return -1;

}

/****************函数说明********************
* 问题描述：在一个给定的数组nums中，总是存在一个最大元素 。
			查找数组中的最大元素是否至少是数组中每个其他数字的两倍。
			如果是，则返回最大元素的索引，否则返回-1。
* 函数名：int dominantIndex(vector<int>& nums)
* 实现思路：
	1、找到这个最大值
	2、与除这个最大值的其他值比较大小
*/

int dominantIndex(vector<int>& nums)
{
	if (nums.empty())
		return -1;
	int len = nums.size();

	auto max = max_element(nums.begin(), nums.end());
	for (auto i : nums)
	{
		if (*max < 2 * i  && *max != i)  // 与除这个最大值之外的其他值比较
			return -1;
	}
	return distance(begin(nums), max);
	


}

/***************函数说明*******************
* 问题描述：对角线遍历：给定一个含有 M x N 个元素的矩阵（M 行，N 列），
	请以对角线遍历的顺序返回这个矩阵中的所有元素，对角线遍历如下图所示。

* 函数名：vector<int> findDiagonalOrder(vector<vector<int>>& matrix)


*/
vector<int> findDiagonalOrder(vector<vector<int>>& matrix)
{
	vector<int> nums;
	// 特殊情况
	int m = matrix.size();
	if (m == 0) return nums;
	int n = matrix[0].size();
	if (n == 0) return nums;

	bool bXFlag = true;  // 区分方向
	for (int i = 0; i < m + n; i++)
	{
		int pm = bXFlag ? m : n;
		int pn = bXFlag ? n : m;

		int x = (i < pm) ? i : pm - 1;
		int y = i - x;

		while (x >= 0 && y < pn)
		{
			nums.push_back(bXFlag ? matrix[x][y] : matrix[y][x]);
			x--;
			y++;
		}

		bXFlag = !bXFlag;
	}
	return nums;

	
}

/****************函数说明**************
* 问题描述：
	给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
	你可以假设数组是非空的，并且给定的数组总是存在多数元素。
* 函数名：int majorityElement(vector<int>& nums)
* 解决方案：该多数元素在有序序列中的索引为[length/2]
	所以直接排序，再直接返回即可。

*/
int majorityElement(vector<int>& nums)
{
	if (nums.size() == 0)
		return 0;
	sort(nums.begin(), nums.end());
	return (nums[nums.size() / 2]);

}


/***************函数说明***********************
* 问题描述：求两个数组的交集
* 函数名：vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
* 解决方案：1、一个数组填入表中；
			2、查找交集元素
			3、去重

*/
vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
	vector<int> ans;
	unordered_set<int> myset;
	set<int> ansset;
	// 其中一个数组填入表中
	for (auto i : nums1)
	{		
		myset.insert(i);
	}
	// 查找交集元素
	for (auto i : nums2)
	{
		if (myset.count(i) > 0)
		{
			ansset.insert(i);
		}
	}
	// 去重
	for (auto i : ansset)
	{
		ans.push_back(i);
	}
	return ans;
}

/************函数说明***********
* 问题描述：编写一个算法来判断一个数是不是“快乐数”。
一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，
然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到 1。如果可以变为 1，那么这个数就是快乐数。
* 函数名：bool isHappy(int n)
* 解决方案：快慢指针
1、慢指针一次走一步，快指针一次走两步；
2、如果快指针等于慢指针，则判断是否是由1引起的循环。
*/
bool isHappy(int n)
{
	int fast = n, slow = n;  // 定义快慢指针
	do
	{
		slow = sumDec(slow);  // 慢指针走一步
		fast = sumDec(fast);  // 快指针走两步
		fast = sumDec(fast);

	} while (fast != slow);  // 可能是由于1引起的循环，也有可能不是
	return fast == 1;  // 如果是1引起的循环，则fast为1
}
int sumDec(int n)  // 求这个数的各个位数的平方
{
	int sum = 0;	
	int temp = n;
	while (temp)
	{
		sum += (temp % 10) * (temp % 10);  // 取余数		
		temp = temp / 10;  // 更新值
	}	
	return sum;
}

/**************函数说明***************
* 问题说明：同构字符串
给定两个字符串 s 和 t，判断它们是否是同构的。
如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。
所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。
* 函数名：bool isIsomorphic(string s, string t)
* 解决方案：
两次映射，从s映射到t和从t映射到s；（一次映射不行，多个字符可映射到一个字符）

*/
bool isIsomorphic(string s, string t)
{
	map<char, char> s2t, t2s;  // 分别表示从s映射到t，从t映射到s
	for (int i = 0; i < s.size(); ++i)
	{
		char cs = s[i];
		char ct = t[i];
		// s字符串映射到t中
		if (s2t.count(cs) == 0)  // 如果没有这个关键字
		{
			s2t.insert(make_pair(cs, ct));  // 插入这个关键字和它的映射
		}
		else if (s2t[cs] != ct)  // 如果这个关键字映射的字符不是ct，说明存在两种映射
			return 0; // 如果找到了这个关键字
		
		// t字符串映射到s中
		if (t2s.count(ct) == 0)
		{
			t2s.insert(make_pair(ct, cs));
		}
		else if (t2s[ct] != cs)
			return 0;

	}
	return 1;
	
}

/***************函数说明************
* 问题描述：两个列表的最小索引总和
假设Andy和Doris想在晚餐时选择一家餐厅，并且他们都有一个表示最喜爱餐厅的列表，每个餐厅的名字用字符串表示。
你需要帮助他们用最少的索引和找出他们共同喜爱的餐厅。 如果答案不止一个，则输出所有答案并且不考虑顺序。 你可以假设总是存在一个答案。
* 函数名：vector<string> findRestaurant(vector<string>& list1, vector<string>& list2)
* 解决方案：
1、将其中一个链表和索引用字典存储；
2、遍历另一个链表，并查找相交的字符串，比较索引和；
3、如果出现更小的索引和，将原链表清零，并添加此时的字符串，如果索引和相等，继续添加。


*/
vector<string> findRestaurant(vector<string>& list1, vector<string>& list2)
{
	
	map<string, int> strList1;  // 链表1的映射
	vector<string> ans;
	if (list1.empty() || list2.empty())
		return ans;
	for (int i = 0; i < list1.size(); ++i)	
		strList1.insert(make_pair(list1[i], i));  // 字符串与索引形成数对
	
	int min = INT_MAX, index1 = 0;
	for (int i = 0; i < list2.size(); ++i)
	{
		if (strList1.count(list2[i]))  // 如果能够在字典中找到这个字符串，记录最小值
		{
			 // 该字符串在链表1中的索引
			if (min > strList1[list2[i]] + i)  // 更新
			{
				index1 = strList1[list2[i]];
				min = index1 + i;
				ans.clear();
				ans.push_back(list2[i]);  // 加入此时的字符串
			}
			else if (min == strList1[list2[i]] + i)
				ans.push_back(list2[i]);
				
		}
	}
	
	return ans;
	
}

/***************函数说明***************
* 问题描述：存在重复元素 II
给定一个整数数组和一个整数 k，
判断数组中是否存在两个不同的索引 i 和 j，
使得 nums [i] = nums [j]，并且 i 和 j 的差的绝对值最大为 k。
* 函数名：bool containsNearbyDuplicate(vector<int>& nums, int k)
* 解决方案：


*/
bool containsNearbyDuplicate(vector<int>& nums, int k)
{
	// 差的绝对值最大值为k
	multiset<int> numsSet;

	for (int i = 0, j = 0; i < nums.size(); ++i)
	{
		// 字典中只含k个元素
		if (numsSet.size() > k)
		{
			numsSet.erase(nums[j]);
			j += 1;
		}// 删除首部元素
		if (numsSet.count(nums[i]) > 0)
			return 1;  // 如果在k个元素中找到了这个元素，返回1
		numsSet.insert(nums[i]);

	}
	return 0;


}

/**************函数说明*******************
* 问题描述：字母异位词分组
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
* 函数名：vector<vector<string>> groupAnagrams(vector<string>& strs)
* 解决方案：



*/
vector<vector<string>> groupAnagrams(vector<string>& strs) {
	vector<vector<string>> ans;
	map<map<char, int>, vector<string> > hash;
	for (int i = 0; i < strs.size(); i++) 
	{
		//字符串hash
		map<char, int> tmp;
		for (int j = 0; j < strs[i].length(); j++) {
			tmp[strs[i][j]]++;
		}//记录字符串中每个字符出现的个数
		hash[tmp].push_back(strs[i]);//hash值相同的属于同一类
	}
	for (map<map<char, int>, vector<string> >::iterator it = hash.begin(); it != hash.end(); it++) 
		ans.push_back(it->second);
	//按照已经分好的类从map<map<char,int>,vector<string> > hash中提取出答案
	return ans;
}



/*********函数说明*******
* 问题描述：宝石与石头
给定字符串J 代表石头中宝石的类型，和字符串 S代表你拥有的石头。 S 中每个字符代表了一种你拥有的石头的类型，你想知道你拥有的石头中有多少是宝石。

J 中的字母不重复，J 和 S中的所有字符都是字母。字母区分大小写，因此"a"和"A"是不同类型的石头。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jewels-and-stones
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
* 函数名：int numJewelsInStones(string J, string S)
* 解决方案：
1、遍历石头序列，并放在multiset里面；
2、遍历宝石序列，找到石头序列中宝石的数目。


*/
int numJewelsInStones(string J, string S)
{
	multiset<char> stone;
	int sum = 0;
	// 把石头放在一个集合中
	for (auto i : S)
	{
		stone.insert(i);
	}
	for (auto i : J)
	{
		sum += stone.count(i);
	}
	return sum;

}

/************函数说明************
* 问题描述：无重复字符的最长字串
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
* 函数名：int lengthOfLongestSubstring(string s)
* 解决方案：
set，记录最长长度，如果新字符有重复的，删除重复元素直到这个新元素；
然后添加这个新元素并更新max

*/

int lengthOfLongestSubstring(string s)
{
	set<char> strSet;
	int max = 0;
	// i遍历字符串，j表示字符串在集合中加入最早的字符的索引
	for (int i = 0, j = 0; i < s.size(); ++i)
	{		
		if (strSet.count(s[i]) > 0)
		{
			while (s[j] != s[i])
			{
				strSet.erase(s[j]);
				j += 1;
			}
			strSet.erase(s[j]);  // 删除和新元素重复的元素
			j += 1;  // 更新j		
			
		}		
		strSet.insert(s[i]);  // 添加这个新元素
		// 此时无重复元素的长度
		int len = strSet.size();
		// 有必要则更新max值
		if (max < len)
			max = len;
	}
	return max;
}

/*************函数说明***********
* 问题描述：替换空格
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
* 函数名：string replaceSpace(string s)
* 解决方案：

*/

/***********函数说明***********
* 问题描述：四数相加II
给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，
使得 A[i] + B[j] + C[k] + D[l] = 0。为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，
且 0 ≤ N ≤ 500 。所有整数的范围在 -228 到 228 - 1 之间，最终结果不会超过 231 - 1 。
* 函数名：int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D)
* 解决方案：


*/
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D)
{
	multiset<int> AB, CD;
	int N = A.size();
	int count = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			AB.insert(A[i] + B[j]);
			CD.insert(C[i] + D[j]);
		}
	}
	for (auto i : AB)
	{
		count += CD.count(0-i);
	}
	return count;
}

int fourSumCount2(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D)
{
	if (A.empty() || B.empty() || C.empty() || D.empty()) return 0;
	unordered_map<int, int> ab;
	for (int a : A) {
		for (int b : B) { ab[a + b]++; }
	}
	int ans = 0;
	for (int c : C) {
		for (int d : D) {
			int t = c + d;
			ans += ab[-t];
		}
	}
	return ans;

	
}

/********函数说明*********
* 问题描述：寻找重复的子树
给定一棵二叉树，返回所有重复的子树。对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。
两棵树重复是指它们具有相同的结构以及相同的结点值。
* 函数名：vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
* 解决方案：



vector<TreeNode*> Solution::findDuplicateSubtrees(TreeNode* root)
{
	findDuplicateSubtreesHelper(root);
	return childVec;
}
//先序遍历
int Solution::findDuplicateSubtreesHelper(TreeNode* root)
{
	if (root == NULL)
		return 0;
	vector<char> v;
	if (root != NULL)
	{
		v.push_back(root->val);
		v.push_back(findDuplicateSubtreesHelper(root->left));
		v.push_back(findDuplicateSubtreesHelper(root->right));
		childNodeMap.insert(make_pair(v, root));
		if (childNodeMap.count(v) > 1)
			childVec.push_back(root);
	}
	return root->val;

}*/
/*************函数说明**************
* 问题描述：杨辉三角

给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。

* 函数名：vector<vector<int>> generate(int numRows)
* 解决方案：
1、按照规律就行：ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j]
2、特殊情况特殊考虑
注意：不能直接用下标索引，因为在vector<vector<int>> ans在没有push任何向量时，ans是空的，不存在任何元素
**/

vector<vector<int>> generate(int numRows)
{	
	vector<vector<int>> ans;

	for (int i = 0, level = 0; level < numRows && i < numRows; ++i)
	{
		vector<int> vec;
		for (int j = 0; j < level + 1; ++j)
		{
			if (j == 0 || j == level)
				vec.push_back(1);
			else
				vec.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
		}
		ans.push_back(vec);
		level += 1;
	}
	return ans;
}

/**********函数说明**********
* 问题描述：二进制求和

给定两个二进制字符串，返回他们的和（用二进制表示）。
输入为非空字符串且只包含数字 1 和 0。
* 函数名：string addBinary(string a, string b)
* 解决方案：
1、逆序输出用栈，从末尾开始，用整数值计算；
2、最后一位及特殊情况的讨论

*/
string addBinary(string a, string b)
{
	int asize = a.size(), bsize = b.size();	
	if (!asize && !bsize)  // 特殊情况
		return "0";
	stack<char> ansStack;  // 逆序输出用栈
	int flag = 0;
	int re = 0;
	string sAns;
	while (asize || bsize)  // 索引有效
	{
		if (asize && bsize)  // 双方都有效
		{
			re = a[asize - 1] - '0' + b[bsize - 1] - '0' + flag;
			asize -= 1;
			bsize -= 1;
		}
		else if (asize)
		{
			re = a[asize - 1] - '0' + flag;
			asize -= 1;
		}
		else if (bsize)
		{
			re = b[bsize - 1] - '0' + flag;
			bsize -= 1;
		}
		ansStack.push(re % 2 + '0');  // 压栈
		flag = re / 2;
	}
	if (flag)  // 最后一位是否有进位
		ansStack.push(flag);
	while (!ansStack.empty())
	{
		sAns.push_back(ansStack.top());
		ansStack.pop();
	}
	return sAns;

}

/*********函数说明********
* 问题描述：数组拆分 I

给定长度为 2n 的数组, 你的任务是将这些数分成 n 对, 
例如 (a1, b1), (a2, b2), ..., (an, bn) ，使得从1 到 n 的 min(ai, bi) 总和最大。
* 函数名：int arrayPairSum(vector<int>& nums)
* 解决方案：
1、排序
2、从第0个到倒数第二个的总和

*/
int arrayPairSum(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	int sum = 0;
	int n = nums.size();
	while (n >= 0)
	{
		sum += nums[--n];
		n -= 1;
	}
	return sum;
}

/**********函数说明**********
* 问题描述：两数之和 II - 输入有序数组

给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。
函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
说明:
返回的下标值（index1 和 index2）不是从零开始的。
你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
* 函数名：vector<int> twoSum(vector<int>& numbers, int target)
* 解决方案：双指针法
1、一大一小两个指针，小指针从前往后，大指针从后往前，若大指针值等于target-小指针，返回；
2、若大指针小于target-小指针，小指针往前移，保持大指针的位置，继续判断，否则大指针往前移


*/
vector<int> twoSum(vector<int>& numbers, int target)
{
	vector<int> ans;
	int index1 = 0, index2 = numbers.size() - 1;
	while (index1 <= index2)
	{
		if (numbers[index2] == target - numbers[index1])
		{
			ans.push_back(index1 + 1);
			ans.push_back(index2 + 1);
			break;
		}
		else if (numbers[index2] < target - numbers[index1])
			index1 += 1;
		else
			index2 -= 1;
	}
	return ans;
}


/**********函数说明*********
* 问题描述：移除元素

给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
* 函数名：int removeElement(vector<int>& nums, int val)
* 解决方案：双指针法
1、从前往后遍历，前指针等于该值，判断后指针；
2、后指针如果等于前指针，直接返回前指针（此时前后指针都表示该值，保留前指针的值即可）；
3、若不等于前指针，且值为该值，继续向前移，直到找到一个不等于该值的数，交换前后指针的数值，继续遍历。


*/
int removeElement(vector<int>& nums, int val)
{
	int size = nums.size();
	int front = 0;
	for (int back = size - 1; front <= back; ++front)
	{
		if (nums[front] == val)
		{
			while (back >= front && nums[back] == val)
				if (back == front)
					return front;
				else
					--back;
			swap(nums[front], nums[back]);
		}
	}
	return front;
}
/***********函数说明***********
* 问题描述：最大连续1的个数
给定一个二进制数组， 计算其中最大连续1的个数。
* 函数名：int findMaxConsecutiveOnes(vector<int>& nums)
* 解决方案：双指针
1、前指针先探寻1的起始位置，探寻到了后把前指针赋值给后指针；
2、后指针继续向后探寻，直到不为1为止；
3、更新完max值之后，移动front指针至此时back指针的位置，循环。

*/
int findMaxConsecutiveOnes(vector<int>& nums)
{
	int front = 0, back = 0, max = 0, size = nums.size();
	while (front < size)
	{
		if (nums[front] == 1)
		{
			back = front;
			while (back < size && nums[back] == 1)
				back += 1;  // 后指针持续到不为1			
			if (back - front > max)  // 如果有更新的必要就更新
				max = back - front;
			front = back;  // 更新此时的前指针
		}
		else front += 1;
	}
	return max;
}

/**************函数说明*************
* 问题描述：长度最小的子数组

给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组。如果不存在符合条件的连续子数组，返回 0。

* 函数名：int minSubArrayLen(int s, vector<int>& nums)
* 解决方案：双指针O(n^2)
1、前指针front从前往后遍历，target表示目标与front到end之间的数值和的差距，end指针不断向后移，直到target为负或0；
2、若有必要更新窗口最小值；
3、前指针front向后移，end与front指向同一位置，重复上两步。
4、min初始化为大于size值的不可能的数，若最后min>size表示不存在这样的子串，返回0，否则返回size。
*/
int minSubArrayLen(int s, vector<int>& nums)
{
	int begin = 0, end = 0, size = nums.size(), min = size + 1, target = s;  // min的初始定义是一个不可能的大数
	while (begin < size)
	{
		target = s;
		while (end < size && target > 0)
		{
			target -= nums[end++];
		}  // 找到所有数组中满足其和大于等于s的子数组
		if (end - begin < min && target <= 0)
			min = end - begin;
		begin += 1;
		end = begin;
	}
	return min > size ? 0 : min;
}

/*********函数说明************
* 问题描述：翻转字符串里的单词
给定一个字符串，逐个翻转字符串中的每个单词。
说明：
无空格字符构成一个单词。
输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
* 函数名：string reverseWords(string s)
* 解决方案：// 尚未解决

*/

string reverseWords(string s) {
	int left = 0, right = s.size() - 1;

	// 找到第一个不是空格的位置
	while (left <= right && isspace(s[left]))
		++left;
	// 找到最后一个不是空格的位置
	while (right >= 0 && isspace(s[right]))
		--right;

	// s中只含空格
	if (right < left)
		return string("");

	// 反向构造新的string  
	string res(s.rbegin() + (s.size() - right - 1), s.rbegin() + (s.size() - left));

	// 反转单词并删除多余空格
	auto iter = res.begin(), pre = iter;
	while (true) {
		// pre记录单词的起始位置
		if (iter != res.end() && *iter != ' ')
			pre = iter;
		// iter指向当前单词的下一个位置
		while (iter != res.end() && *iter != ' ')
			++iter;
		// 反转
		reverse(pre, iter);
		// 最后一个单词完成反转后退出
		if (iter == res.end())
			break;

		// 当前iter指向空格 
		pre = ++iter;
		// 若pre指向空格 说明含多余空格
		if (*pre == ' ') {
			// iter指向此后第一个不是空格的位置
			while (iter != res.end() && *iter == ' ')
				++iter;
			// 删除多余空格 pre指向iter原来指向的字符(此时iter已失效)
			pre = res.erase(pre, iter);
			// 从新的单词开始
			iter = pre;
		}
	}
	return res;
}

/************函数说明****************
* 问题描述：1162. 地图分析
你现在手里有一份大小为 N x N 的『地图』（网格） grid，上面的每个『区域』（单元格）都用 0 和 1 标记好了。其中 0 代表海洋，1 代表陆地，你知道距离陆地区域最远的海洋区域是是哪一个吗？请返回该海洋区域到离它最近的陆地区域的距离。

我们这里说的距离是『曼哈顿距离』（ Manhattan Distance）：(x0, y0) 和 (x1, y1) 这两个区域之间的距离是 |x0 - x1| + |y0 - y1| 。

如果我们的地图上只有陆地或者海洋，请返回 -1。
* 函数名：int maxDistance(vector<vector<int>>& grid)
* 解决方案：
遍历所有的海洋，每一个海洋都计算距离所有陆地的距离，并得到其中的距离最大值

**/

int maxDistance(vector<vector<int>>& grid)
{
	int max = -1, size = grid.size(), distance = 0;
	for (int i = 0; i < size; ++i)	
		for (int j = 0; j < size; ++j)		
			if (!grid[i][j])  // 如果是海洋区域			
			{
				int min = size * 2;
				for (int k = 0; k < size; ++k)
				{
					for (int l = 0; l < size; ++l)
						if (grid[k][l])  // 如果是陆地						
							min = min < abs(k - i) + abs(l - j) ? min : abs(k - i) + abs(l - j);  //该海洋与陆地的最近距离
				}
				max = max > min ? max : min;  // 求最小值中的最大值
			}
		
	return max;
}


class Solution {
public:
	static constexpr int MAX_N = 100 + 5;
	static constexpr int INF = int(1E6);

	int f[MAX_N][MAX_N];  // 表示各个海洋区域到陆地的最近区域，若是陆地则为0
	int n;

	int maxDistance(vector<vector<int>>& grid) {
		this->n = grid.size();
		vector<vector<int>>& a = grid;
		// 初始化，陆地f预置为0，海洋f预置为inf
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				f[i][j] = (a[i][j] ? 0 : INF);
			}
		}
		// 从左上方向
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (a[i][j]) continue;  // 如果是陆地，为0
				if (i - 1 >= 0) f[i][j] = min(f[i][j], f[i - 1][j] + 1);
				if (j - 1 >= 0) f[i][j] = min(f[i][j], f[i][j - 1] + 1);
			}
		}
		// 从右下方向
		for (int i = n - 1; i >= 0; --i) {
			for (int j = n - 1; j >= 0; --j) {
				if (a[i][j]) continue;
				if (i + 1 < n) f[i][j] = min(f[i][j], f[i + 1][j] + 1);
				if (j + 1 < n) f[i][j] = min(f[i][j], f[i][j + 1] + 1);
			}
		}
		// 求最大值
		int ans = -1;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (!a[i][j]) {
					ans = max(ans, f[i][j]);
				}
			}
		}

		if (ans == INF) return -1;
		else return ans;
	}
};

