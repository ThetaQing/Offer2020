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