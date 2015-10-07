/************************************************************************
Longest Substring Without Repeating Characters
Given a string, find the length of the longest substring without repeating characters.
For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
For "bbbbb" the longest substring is "b", with the length of 1.

************************************************************************/

#include<iostream>
#include<string>
using namespace std;
//主要思想：不断更新不重复的临时str
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int slen = s.length();
		int llen = 0;   //最终结果
		int tlen = 0;   //临时str的长度
		int place = -1; //str中某个字符位置
		string str = "";//临时str
		for (int i = 0; i < slen; i++) {
			place = str.find(s[i]);
			if (-1 == place) {
				//逐步增加str的大小
				str += s[i];
			}
			else {
				//更新目前最大的长度
				tlen = str.length();
				llen = llen > tlen ? llen : tlen;
				//没有重复的新的str
				str = str.substr(place + 1, tlen) + s[i];
			}
		}
		tlen = str.length();
		llen = llen > tlen ? llen : tlen;
		return llen;
	}
};

int main() {
	string a = "asdsjdlfjlowef";
	Solution * b = new Solution();
	cout << b->lengthOfLongestSubstring(a) << endl;
}