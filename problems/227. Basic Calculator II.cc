class Solution {
public:
    int calculate(string s) {
        stringstream stt("+"+s+"+");
        int total=0, term=0, n;
        char op;
        while(stt>>op){
            if(op=='+' || op=='-'){
                total += term;
                stt>>term;
                term *= op=='+'? 1:-1;
            } else {
                stt>>n;
                if(op=='*') term*=n;
                else term/=n;
            }
        }
        return total;
    }
};