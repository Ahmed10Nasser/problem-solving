// problem link: https://www.hackerrank.com/challenges/compare-the-triplets/problem

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-9;



pair<int,int> compare_ratings(vector<int>& a, vector<int>& b){
    int n=a.size();
    int a_points = 0, b_points = 0;
    for(int i=0; i<n; i++){
        if(a[i] > b[i]) a_points++;
        else if(b[i] > a[i]) b_points++;
    }
    return {a_points, b_points};
}



int main(){ 
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
  int n=3;
  vector<int> a(n), b(n);
  for(int& rating : a) cin>>rating;
  for(int& rating : b) cin>>rating;

  auto res = compare_ratings(a,b);

  cout<< res.first << ' ' << res.second << '\n';


    return 0;
}
