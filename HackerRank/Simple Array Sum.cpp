// problem link: https://www.hackerrank.com/challenges/simple-array-sum/problem

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-9;


int array_sum(vector<int>& numbers){
    int sum = 0;
    for(int number : numbers){
        sum+= number;
    }
    return sum;
}


int main(){ 
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
    int n;
    cin>>n;
    vector<int> numbers(n);
    for(int& number : numbers)
        cin>>number;
    cout<< array_sum(numbers)<<'\n';
    return 0;
}
