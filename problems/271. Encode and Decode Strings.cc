#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded_string;
        for(int i=0; i<strs.size(); i++){
        	encoded_string += to_string(strs[i].length())+"@"+strs[i];
        }
        return encoded_string;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> strs;
        int head = 0;
        int at_pos = s.find_first_of("@", head);
        while(at_pos!=string::npos){
        	int len = stoi(s.substr(head, at_pos-head));
        	strs.push_back(s.substr(at_pos+1, len));
        	head = at_pos+len+1;
        	at_pos = s.find_first_of("@", head);
        }
        return strs;
    }
};

int main(){
	string array[] = {"abc", "de", "fg"};
	vector<string> strs(array,array+3);
	Codec codec;
	string encoded_str = codec.encode(strs);
	cout<<encoded_str<<endl;
	vector<string> decoded_str = codec.decode(encoded_str);
	for(int i=0; i<decoded_str.size(); i++){
		cout<<decoded_str[i]<<endl;
	}
}






