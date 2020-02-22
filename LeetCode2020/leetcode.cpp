#include "leetcode.h"
#include <iostream>
#include <numeric>
#include <algorithm>
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



