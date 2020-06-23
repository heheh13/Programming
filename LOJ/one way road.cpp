#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 105
#define mod  6
#define inf 1e9
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
std::vector<pair<int,int> > g[mx];
int dfs(int src, int par,int dest){
	//dbg(src,par);
	if(src == dest)return 0;
	int ans =0;
	for(int i = 0;i<g[src].size();i++){
		int x = g[src][i].first;
		if(x==par)continue;
		ans+=dfs(x,src,dest)+g[src][i].second;
	}
	return ans;
}
int main(){
	File_IO();
	int t;
	cin>>t;
	for(int ts = 1;ts<=t;ts++){
		for(int i = 0;i<mx;i++)g[i].clear();
		int n;
		cin>>n;
		int a,b,c;
		for(int i =0;i<n;i++){
			cin>>a>>b>>c;
			g[a].push_back({b,0});
			g[b].push_back({a,c});

		}
		int ans =inf;
		for(int i = 0;i<g[1].size();i++){
			ans = min(ans,g[1][i].second+dfs(g[1][i].first,1,1));
		}
		printf("Case %d: %d\n",ts,ans);
		//cout<<ans<<endl;
	}
}