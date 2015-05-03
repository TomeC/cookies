/*
content:	Given an array of integers, find two numbers such that they add up to a specific target number.
			The function twoSum should return indices of the two numbers such that they add up to the target, 
			where index1 must be less than index2. Please note that your returned answers (both index1 and index2) 
			are not zero-based.
			You may assume that each input would have exactly one solution.
			Input: numbers={2, 7, 11, 15}, target=9
			Output: index1=1, index2=2
author:    	benjamin
created:   	2015-05-03 15:14
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
		map<int, int> tmp;

		for (int i = 0; i < nums.size(); ++i)
		{
			if (tmp.find(target - nums[i]) != tmp.end())
			{
				result.push_back(tmp[target - nums[i]] + 1);
				result.push_back(i + 1);
				break;
			}
			tmp[nums[i]] = i;
		}
		return result;
	}
};

int main()
{
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(11);
	nums.push_back(15);
	Solution s;
	vector<int> result = s.twoSum(nums, 22);
	return 0;
}