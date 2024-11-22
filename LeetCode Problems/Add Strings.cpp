class Solution {
public:
  string addStrings(string num1, string num2) {
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    int carry=0;
    string ans="";
    for(int i=0; i<max(num1.length(), num2.length()); i++){
      int d1 = (i < num1.length()) ? num1[i]-'0' : 0;
      int d2 = (i < num2.length()) ? num2[i]-'0' : 0;
      int sum = d1+d2+carry;
      carry=sum/10;
      int d=sum%10;
      ans+= (char)(d+'0');
    }
    if(carry!=0) ans+=(char)(carry+'0');
    reverse(ans.begin(), ans.end());
    return ans;
  }
};