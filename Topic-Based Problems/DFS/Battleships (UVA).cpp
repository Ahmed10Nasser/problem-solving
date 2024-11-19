// Problem Link : https://vjudge.net/problem/UVA-11953

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;

int dr[]={0,0,1,-1};
int dc[]={1,-1,0,0};

bool inBorder(int r, int c, int n){
  return r>=0 && r<n && c>=0 && c<n;
}

bool DFS(int nodeR, int nodeC, vector<string>& grid, vector<vector<bool>>& vis){
  vis[nodeR][nodeC]=1;
  bool foundX= (grid[nodeR][nodeC]=='x') ? true : false;
  for(int i=0; i<4; i++){
    int neighR=nodeR + dr[i];
    int neighC=nodeC + dc[i];
    if(inBorder(neighR, neighC, grid.size()) && grid[neighR][neighC]!='.' && vis[neighR][neighC]==0)
      foundX = DFS(neighR, neighC, grid, vis) || foundX;
  }
  return foundX;
}

int main(){
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);

  int t, tc=0;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<string>grid(n);
    for(auto&  s : grid) cin>>s;
    vector<vector<bool>>vis(n, vector<bool>(n, 0));
    int counter=0;
    for(int r=0; r<n; r++){
      for(int c=0; c<n; c++){
        if(grid[r][c]!='.' && vis[r][c]==0){
          bool foundX=DFS(r,c,grid,vis);
          if(foundX) counter++;
        }
      }
    }
    cout<<"Case "<< ++tc <<": "<< counter <<'\n';
  }

  return 0; 
} 

