#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
	int longestPalindrome(string s){
		map<char, int> dict;
		int length = 0;
		
		// go through string s
		for(int i=0; i<s.length(); i++){
			dict[s[i]]++;
			if(dict[s[i]]%2==0) length += 2;
		}

		// go through dict (find odd)
		for(map<char,int>::iterator i = dict.begin(); i != dict.end(); i++){
			if(i->second%2==1){
				length++;
				break;
			}
		}
		return length;
	}
};

int main(){
	string s = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";

	Solution sol;
	cout<<sol.longestPalindrome(s);
}