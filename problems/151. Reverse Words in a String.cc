#include <iostream>
#include <string>

using namespace std;


void reverseString(string &s, int i, int j){
	while(i<j){
		char t = s[i];
		s[i++] = s[j];
		s[j--] = t;
	}
}

int main(){

	string s = "the      sky is blue";


	int i=0, j=0;
	int l=0;
	int worldCount=0;

	while(true){
		while(i<s.length() && s[i]==' '){
			i++;
		}
		if(i==s.length()) break;
		if(worldCount) s[j++] = ' ';
		l = j;
		while(i<s.length() && s[i]!=' '){
			s[j] = s[i];
			i++; j++;
		}
		reverseString(s, l, j-1);
		worldCount++;
	}

	s.resize(j);
	reverseString(s, 0, j-1);

	cout<<s;


}