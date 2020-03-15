class Solution {
public:
    string helper(int num){
        vector<string> digits = {"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
        vector<string> ten = {"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
        vector<string> tens = {"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
        
        int d3 = num/100;
        num = num%100;
        int d2 = num/10;
        num = num%10;
        int d1 = num;
        
        string s1,s2;
        s1 = d3>0 ? digits[d3]+" Hundred":"";
        
        if(d2==1){
            s2 += ten[d1];
        } else if(d2==0) {
            s2 += digits[d1];
        } else if(d1==0){
            s2 += tens[d2];
        } else {
            s2 += tens[d2]+" "+digits[d1];
        }
        
        if(s1=="") return s2;
        else if(s2=="") return s1;
        else return s1+" "+s2;
    }
    
    string numberToWords(int num) {
        int billion, million, thousand, one;
        billion = num/1000000000;
        num = num%1000000000;
        million = num/1000000;
        num = num%1000000;
        thousand = num/1000;
        num = num%1000;
        one = num;
        
        string s;
        if(billion>0) s = helper(billion)+" Billion";
        if(million>0){
            s = s=="" ? s : s+=" ";
            s += helper(million)+" Million";
        }
        if(thousand>0){
            s = s=="" ? s : s+=" ";
            s += helper(thousand)+" Thousand";
        }
        if(one>0){
            s = s=="" ? s : s+=" ";
            s += helper(one);
        }
        return s.length()>0 ? s:"Zero";
    }
};