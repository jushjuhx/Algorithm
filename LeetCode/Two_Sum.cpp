/************************************************************
Two Sum 排序好的
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.
Please note that your returned answers(both index1 and index2) are not zero - based.

You may assume that each input would have exactly one solution.

Input: numbers = { 2, 7, 11, 15 }, target = 9
	Output : index1 = 1, index2 = 2
**************************************************************/
//遍历方式
//#include <iostream> 
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//	vector<int> twoSum(vector<int>& nums, int target) {
//		vector<int> result(2);
//		int len = nums.size();
//		for (int i = 0; i < len;i++) {
//			for (int j = i + 1;j < len;j++) {
//				if (nums[i] + nums[j] == target) {
//					result[0] = i;
//					result[1] = j;
//					return result;
//				}
//			}
//		}
//		result[0] = -1;
//		result[1] = -1;
//		return result;
//	}
//};
//int main() {
//	vector<int> a(4);
//	vector<int> result;
//	int len = a.size();
//	for (int i = 0; i < len;i++) {
//		cin >> a[i];
//	}
//	int target;
//	cin >> target;
//	Solution * c = new Solution();
//	result = c->twoSum(a, target);
//	cout << result[0];
//	cout << result[1];
//
//}



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/********************************************
vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> hash;
	vector<int> res(2, 0);
	for (int i = 0; i < nums.size(); i++) {
		if (hash.find(target - nums[i]) != hash.end()) {
			res[0] = hash[target - nums[i]], res[1] = i + 1;
			return res;
		}
		hash[nums[i]] = i + 1;
	}
}
*********************************************/
class Solution
{
public:
	vector<int> twoSum(vector<int>& numbers, int target)
	{
		vector<int> tmpNumbers(numbers.begin(), numbers.end());
		sort(tmpNumbers.begin(), tmpNumbers.end());

		int val1 = -1;
		int val2 = -1;
		int i = 0;
		int j = tmpNumbers.size() - 1;
		// find two numbers added equals to target
		while (i < j)
		{
			if ((tmpNumbers[i] + tmpNumbers[j]) < target)
			{
				i++;
			}
			else if ((tmpNumbers[i] + tmpNumbers[j]) > target)
			{
				j--;
			}
			else
			{
				val1 = tmpNumbers[i];
				val2 = tmpNumbers[j];
				break;
			}
		}

		vector<int> result;
		// find the index of the two numbers
		for (int i = 0; i < numbers.size(); i++)
		{
			if (numbers[i] == val1 || numbers[i] == val2)
			{
				result.push_back(i + 1);
			}
			if (2 == result.size())
			{
				return result;
			}
		}
		return result;
	}
};
int main() {
	vector<int> a(4);
	vector<int> result;
	int len = a.size();
	for (int i = 0; i < len;i++) {
		cin >> a[i];
	}
	int target;
	cin >> target;
	Solution * c = new Solution();
	result = c->twoSum(a, target);
	cout << result[0];
	cout << result[1];

}