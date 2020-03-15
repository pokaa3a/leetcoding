#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string decode(string& s, int& index){
		string res;
		while(index<s.size() && s[index]!=']'){
			if(!isdigit(s[index]))
				res += s[index++];
			else{
				string num;
				while(index<s.size() && s[index]!='['){
					num += s[index++];
				}
				index++;	// '['
				string element = decode(s, index);
				index++;	// ']'
				for(int i=0; i<stoi(num); i++){
					res += element;
				}
			}
		}
		return res;
	}

	string decodeString(string s){
		int index = 0;
		return decode(s, index);
	}
};


int main(){
	// string s = "3[a]2[bc]"; 	// return "aaabcbc"
	// string s = "3[a2[c]]";		// return "accaccacc"
	string s = "2[abc]3[cd]ef";	// return "abcabccdcdcdef"

	Solution sol;
	cout<<sol.decodeString(s)<<endl;
}



