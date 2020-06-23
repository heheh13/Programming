#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define MAX 30005
#define mod  1000000007
#define inf 1e9
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
std::vector<pair<int,int> > g[MAX];
int maxi ,source;
int ans[MAX];
void dfs(int src, int cost,int par=-1){
	if(cost>maxi){
		maxi= cost;
		source =src;
	}
	for(int i = 0;i<g[src].size();i++){
		if(g[src][i].first==par)continue;
		dfs(g[src][i].first,cost+g[src][i].second,src);
	}
}
void bfs(int src,int n){
	int dist[MAX];
	for(int i = 0;i<MAX;i++)dist[i]=inf;
	dist[src]=0;
	queue<int> q;
	q.push(src);
	while(!q.empty()){
		int fnt = q.front();
		q.pop();
		for(int i = 0;i<g[fnt].size();i++){
			int u = g[fnt][i].first;
			int c = g[fnt][i].second;
			if(dist[u] > dist[fnt]+c){
				dist[u]=dist[fnt]+c;
				q.push(u);
			}
		}
	}
	for(int i = 0;i<n;i++){
		ans [i] = max(ans[i],dist[i]);
	}
}
int main(){
	File_IO();
	//optimizar;
	int t;
	scanf("%d",&t);
	for(int ts = 1;ts<=t;ts++){
		for(int i = 0;i<MAX;i++)g[i].clear();
		memset(ans,0,sizeof(ans));
		int n;
		scanf("%d",&n);
		int a,b,c;
		for(int i = 1;i<n;i++){
			scanf("%d%d%d",&a,&b,&c);
			g[a].push_back({b,c});
			g[b].push_back({a,c});
		}
		maxi  =0,source = -1;
		dfs(0,0);
		//dbg(maxi,source);
		bfs(source,n);
		maxi=0;
		dfs(source,0);
		bfs(source,n);
		printf("Case %d:\n",ts);
		for(int i  =0;i<n;i++)printf("%d\n",ans[i] );
		
	}
}