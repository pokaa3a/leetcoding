#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <map>

using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        istringstream ss(input);
        int maxlength = 0;
        map<int, int> depth_len;
        depth_len[0] = 0;
        string token;
        while(getline(ss, token)){
            size_t pos = token.find_last_of('\t');
            string name = (pos!=string::npos) ? token.substr(pos+1):token;
            
            int depth = token.length() - name.length();
            if(name.find('.')!=string::npos){
                maxlength = maxlength > depth_len[depth]+name.length() ? maxlength : depth_len[depth]+name.length();
            } else{
                depth_len[depth+1] = depth_len[depth] + name.length() + 1;
            }
        }
        return maxlength;
    }
};