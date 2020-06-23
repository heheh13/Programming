#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 30005
#define mod  6
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
std::vector<pair<int,int> > g[mx];
int maxi = 0,source;
int dfs(int src,int par ,int cst){
	if(cst>maxi){
		maxi = cst;
		source = src;
	}
	for(int i =0;i<g[src].size();i++){
		int  x = g[src][i].first;
		if(x == par)continue;
		dfs(x,src,cst+g[src][i].second);
	}
}
int main(){
	File_IO();
	int t;
	scanf("%d",&t);
	for(int ts  = 1;ts<=t;ts++){
		for(int i = 0;i<mx;i++)g[i].clear();
		int n;
		scanf("%d",&n); 
		for(int i = 0;i<n-1;i++){
			int a,b,w;
			scanf("%d%d%d",&a,&b,&w);
			g[a].push_back({b,w});
			g[b].push_back({a,w});
		}
		maxi = 0,source =0;
		///key ovservation simple path o a tree;
		dfs(0,-1,0);
		dfs(source,-1,0);
		printf("Case %d: %d\n",ts,maxi);
	}
}