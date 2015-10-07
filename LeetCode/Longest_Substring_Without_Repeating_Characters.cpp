/************************************************************************
Longest Substring Without Repeating Characters
Given a string, find the length of the longest substring without repeating characters.
For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
For "bbbbb" the longest substring is "b", with the length of 1.

************************************************************************/

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int slen = s.length();
		int llen = 0;
		int tlen = 0;
		int place = -1;
		string str = "";
		for (int i = 0; i < slen; i++) {
			place = str.find(s[i]);
			if (-1 == place) {
				str += s[i];
			}
			else {
				tlen = str.length();
				llen = llen > tlen ? llen : tlen;
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
	cout << b->lengthOfLongestSubstring(a) <<endl;
}