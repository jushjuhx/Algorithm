/************************************************************************
Longest Substring Without Repeating Characters
Given a string, find the length of the longest substring without repeating characters.
For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
For "bbbbb" the longest substring is "b", with the length of 1.

************************************************************************/

#include<iostream>
#include<string>
using namespace std;
//��Ҫ˼�룺���ϸ��²��ظ�����ʱstr
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int slen = s.length();
		int llen = 0;   //���ս��
		int tlen = 0;   //��ʱstr�ĳ���
		int place = -1; //str��ĳ���ַ�λ��
		string str = "";//��ʱstr
		for (int i = 0; i < slen; i++) {
			place = str.find(s[i]);
			if (-1 == place) {
				//������str�Ĵ�С
				str += s[i];
			}
			else {
				//����Ŀǰ���ĳ���
				tlen = str.length();
				llen = llen > tlen ? llen : tlen;
				//û���ظ����µ�str
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