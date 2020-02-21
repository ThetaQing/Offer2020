#include "leetcode.h"
#include <iostream>
#include <numeric>
using namespace std;

/********************************
* ����������
	����һ���������͵����� nums�����дһ���ܹ��������顰�����������ķ�����
	���������������������������ģ����������������������Ԫ����ӵĺ͵����Ҳ�����Ԫ����ӵĺ͡�
	������鲻����������������ô����Ӧ�÷��� -1����������ж��������������ô����Ӧ�÷��������ߵ���һ����
* ��������int pivotIndex(vector<int>& nums)
* ʵ��˼·��
	ץסһ�㣺left = sum - nums[i] - left
*/
int pivotIndex(vector<int>& nums)
{
	int len = nums.size();
	if (len == 0)  // �ձ�����
		return -1;
	if (len < 2)  // ֻ��һ��Ԫ��
		return 0;
	int leftsum = 0;
	int S = accumulate(nums.begin(), nums.end(), 0);
	for (int i = 0; i < len; ++i)
	{
		if (leftsum == S - nums[i] - leftsum)  // �жϴ�ʱ�Ƿ���������
			return i;
		leftsum += nums[i];  // �������������ƶ�

	}
	return -1;

}