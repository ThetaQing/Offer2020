#ifndef leetcode_h
#define leetcode_h
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <unordered_set>
#include <unordered_map>
using namespace std;
// 结构体说明
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
// 类说明
class Solution {
	vector<TreeNode*> childVec;
	unordered_map<vector<char>,TreeNode*> childNodeMap;  // 每个结点的子树序列
public:
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root);
	int findDuplicateSubtreesHelper(TreeNode* root);

};

int pivotIndex(vector<int>& nums);
int dominantIndex(vector<int>& nums);
vector<int> findDiagonalOrder(vector<vector<int>>& matrix);
int majorityElement(vector<int>& nums);
int sumDec(int n);
bool isHappy(int n);
bool isIsomorphic(string s, string t);
vector<string> findRestaurant(vector<string>& list1, vector<string>& list2);
bool containsNearbyDuplicate(vector<int>& nums, int k);
vector<vector<string>> groupAnagrams(vector<string>& strs);
int numJewelsInStones(string J, string S);
int lengthOfLongestSubstring(string s);
string replaceSpace(string s);
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D);
int fourSumCount2(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D);

vector<vector<int>> generate(int numRows);
string addBinary(string a, string b);
int arrayPairSum(vector<int>& nums);
vector<int> twoSum(vector<int>& numbers, int target);
int removeElement(vector<int>& nums, int val);
int findMaxConsecutiveOnes(vector<int>& nums);
int minSubArrayLen(int s, vector<int>& nums);
#endif // !leetcode_h


#pragma once
