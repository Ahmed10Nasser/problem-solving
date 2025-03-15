// problem link: https://www.spoj.com/problems/TRUCKL/

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-9;


int truck_loads(int pile_size, int load_size){
    if(pile_size <= load_size) return 1;
    if(pile_size&1) return truck_loads(pile_size/2, load_size) + truck_loads(pile_size/2 + 1, load_size);
    return 2*truck_loads(pile_size/2, load_size);
}

int main(){ 
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);    
    int pile_size, load_size;
    while(cin>>pile_size>>load_size){
        cout<< truck_loads(pile_size, load_size)<<'\n';
    }
    return 0;
}
