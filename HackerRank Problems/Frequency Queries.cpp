// problem link: https://www.hackerrank.com/challenges/frequency-queries/problem

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-9;



int main(){ 
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);    
    unordered_map<int,int> freq, freq_of_freqs;
    int q;
    cin>>q;
    while(q--){
        int type, num;
        cin>>type>>num;
        if(type==1){
            if(freq[num] != 0) freq_of_freqs[freq[num]]--;
            freq[num]++;
            freq_of_freqs[freq[num]]++;
        }
        else if(type == 2){
            if(freq.count(num) !=0 && freq[num] != 0){
                freq_of_freqs[freq[num]]--;
                freq[num]--;
                if(freq[num] != 0) freq_of_freqs[freq[num]]++;
            }
        }
        else{
            if(freq_of_freqs.count(num) != 0 && freq_of_freqs[num] != 0)
                cout<<"1\n";
            else
                cout<<"0\n";
        }
    }

    return 0;
}
