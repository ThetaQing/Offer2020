#include "leetcode.h"
#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;

/**************����˵��******************
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

/****************����˵��********************
* ������������һ������������nums�У����Ǵ���һ�����Ԫ�� ��
			���������е����Ԫ���Ƿ�������������ÿ���������ֵ�������
			����ǣ��򷵻����Ԫ�ص����������򷵻�-1��
* ��������int dominantIndex(vector<int>& nums)
* ʵ��˼·��
	1���ҵ�������ֵ
	2�����������ֵ������ֵ�Ƚϴ�С
*/

int dominantIndex(vector<int>& nums)
{
	if (nums.empty())
		return -1;
	int len = nums.size();

	auto max = max_element(nums.begin(), nums.end());
	for (auto i : nums)
	{
		if (*max < 2 * i  && *max != i)  // ���������ֵ֮�������ֵ�Ƚ�
			return -1;
	}
	return distance(begin(nums), max);
	


}

/***************����˵��*******************
* �����������Խ��߱���������һ������ M x N ��Ԫ�صľ���M �У�N �У���
	���ԶԽ��߱�����˳�򷵻���������е�����Ԫ�أ��Խ��߱�������ͼ��ʾ��

* ��������vector<int> findDiagonalOrder(vector<vector<int>>& matrix)


*/
vector<int> findDiagonalOrder(vector<vector<int>>& matrix)
{
	vector<int> nums;
	// �������
	int m = matrix.size();
	if (m == 0) return nums;
	int n = matrix[0].size();
	if (n == 0) return nums;

	bool bXFlag = true;  // ���ַ���
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


