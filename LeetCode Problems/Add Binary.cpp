class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string ans="";
        int carry=0;
        for(int i=0; i<max(a.length(), b.length()); i++){
            int a_val = (i < a.length()) ? a[i] - '0' : 0;
            int b_val = (i < b.length()) ? b[i] - '0' : 0;
            int sum = a_val + b_val + carry;
            switch (sum){
            case 0:
                ans+='0';
                carry = 0;
                break;
            case 1:
                ans+='1';
                carry = 0;
                break;
            case 2:
                ans+='0';
                carry = 1;
                break;
            case 3:
                ans+='1';
                carry = 1;
                break;
            default:
                break;
            }
        }
        if(carry == 1) ans+='1';
        reverse(ans.begin(), ans.end());
        return ans;

    }
};