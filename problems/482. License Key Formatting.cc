class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
		string res = "";
		int count = 0;
		for(int i=S.length()-1; i>=0; i--){
			if(S[i]!='-'){
				if(++count<K){
					if(S[i]>='a'&&S[i]<='z'){
						char c = S[i]+'A'-'a';
						res = c+res;
					}
					else{
						res = S[i]+res;
					}
				}
				else{
					if(S[i]>='a'&&S[i]<='z'){
						char c = (S[i]+'A'-'a');
						res = c+res;
					}
					else{
						res = S[i]+res;
					}
					res = "-"+res;
					count = 0;
				}
			}
		}
		return res[0]=='-'? res.substr(1):res;
    }
};