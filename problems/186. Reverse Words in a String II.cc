class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        
        int head=0, tail;
        while(head<s.length()){
            for(tail=head+1; tail<s.length(); tail++){
                if(isspace(s[tail])) break;
            }
            reverse(s.begin()+head, s.begin()+tail);
            head = tail+1;
        }
    }
};