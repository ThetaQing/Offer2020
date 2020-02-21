#include "leetcode.h"
#include <iostream>
#include <numeric>
using namespace std;

/********************************
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