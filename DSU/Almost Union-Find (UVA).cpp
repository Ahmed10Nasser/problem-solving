// Problem Link : https://vjudge.net/problem/UVA-11987

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;


int findParent(int node, vector<int>& par){
  if(node==par[node]) return node;
  return  par[node]=findParent(par[node], par);
}


void join(int node1, int node2, vector<int>& par, vector<int>& size, vector<ll>& sum, vector<int>& id){
  node1=findParent(id[node1], par);
  node2=findParent(id[node2], par);
  if(node1!=node2){
    if(size[node2] > size[node1]) swap(node1,node2);
    par[node2]=node1;
    size[node1]+=size[node2];
    sum[node1]+=sum[node2];
  }
}


void move(int node1, int node2, vector<int>& par, vector<int>& size, vector<ll>& sum, vector<int>& id, int & numOfNodes){
  auto node1Par=findParent(id[node1],par);
  auto node2Par=findParent(id[node2],par);
  if(node1Par!=node2Par){
    size[node1Par]--;
    sum[node1Par]-=(node1+1);
    id[node1]=numOfNodes;
    par.push_back(numOfNodes);
    sum.push_back((node1+1));
    size.push_back(1);
    numOfNodes++;
    join(node1,node2, par, size, sum, id);
  }
}

int main(){
  FIO
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
  int n,m;
  while(cin>>n>>m){
    vector<int>par(n), size(n,1), id(n);
    vector<ll> sum(n);
    for(int i=0; i<n; i++){
      id[i]=i;
      par[i]=i;
      sum[i]=i+1;
    }
    while(m--){
      int type;
      cin>>type;
      if(type==1){
        int u,v;
        cin>>u>>v;
        u--,v--;
        join(u,v,par,size,sum,id);
      }
      else if(type==2){
        int u,v;
        cin>>u>>v;
        u--,v--;
        move(u,v,par,size,sum,id,n);
      }
      else{
        int u;
        cin>>u;
        u--;
        cout<<size[findParent(id[u], par)] << ' '<< sum[findParent(id[u], par)]<<'\n';
      }
    }
  }




  return 0;
}
