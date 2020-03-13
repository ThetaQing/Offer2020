#ifndef leetcode_h
#define leetcode_h
#include <iostream>
#include <vector>
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
	vector<int> childNodeVec;
public:
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root);
	vector<int> findDuplicateSubtreesHelper(TreeNode* root);

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
#endif // !leetcode_h


#pragma once
