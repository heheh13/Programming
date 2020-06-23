#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 2010
#define mod  6
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
std::vector<int > g[mx],dep(mx),cnt(mx);
int cost[mx][mx];
int dfs(int src){
	if(visited[src])return 0;
	visited[src]=1;
	int ret  = dep[src];
	for(int i =0;i<g[src].size();i++){
		int t = dfs(g[src][i]);
		ret+=t;
		v.push_back(ret*cost[src][i]);
	}
	return ret;
}
int main(){
	File_IO();
	int n,k;
	cin>>n>>k;
	for(int i = 1;i<n;i++){
		cin>>dep[i];
	}
	for(int i =1;i<=k;i++){
		int a,b,c;
		cin>>a>>b>>c;
		g[a].push_back(b);
		g[b].push_back(a);
		cost[a][b]=c;
		cost[b][a]=c;
	}
	dfs(1);
}