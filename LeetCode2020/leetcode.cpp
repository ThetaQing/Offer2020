#include "leetcode.h"
#include <iostream>
#include <numeric>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
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

/********函数说明*********
* 问题描述：寻找重复的子树
给定一棵二叉树，返回所有重复的子树。对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。
两棵树重复是指它们具有相同的结构以及相同的结点值。
* 函数名：vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
* 解决方案：


*/
vector<TreeNode*> Solution::findDuplicateSubtrees(TreeNode* root)
{
	TreeNode* tempNode = root;
	map<TreeNode*, vector<int>> childNodeMap;  // 每个结点的子树序列
	vector<TreeNode*> childVec;
	while (tempNode != NULL)
	{
		// 使用先序遍历
	}
	return childVec;
}
//先序遍历
vector<int> Solution::findDuplicateSubtreesHelper(TreeNode* root)
{
	childNodeVec.push_back(root->val);
	findDuplicateSubtreesHelper(root->left);
	findDuplicateSubtreesHelper(root->right);
	return childNodeVec;
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




