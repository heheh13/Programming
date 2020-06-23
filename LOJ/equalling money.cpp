#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 1005
#define mod  6
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int money[mx];
std::vector<int> g[mx];
int need ;
bool visited[mx];
int dfs(int src){
	if(visited[src])return 0;
	visited[src]=1;
	int ans = need-money[src];
	for(int i = 0;i<g[src].size();i++){
		ans +=dfs(g[src][i]);
	}
	return ans;
}
int main(){
	File_IO();
	int t;
	scanf("%d",&t);
	for(int ts  = 1; ts<= t; ts++){
		printf("Case %d: ",ts);
		for(int i = 0;i<mx;i++)g[i].clear();
		memset(visited,0,sizeof(visited));
		int n,m;
		scanf("%d %d",&n,&m);
		int sum = 0;
		for(int i = 1; i<=n; i++) scanf("%d",&money[i]),sum+=money[i];

		int a,b;
		for(int i = 0;i<m;i++){
			scanf("%d %d",&a,&b);
			g[a].push_back(b);
			g[b].push_back(a);
		}
		need = sum/n;
		int ans  = 0;
		bool flag = true;
		for(int i = 1;i<=n;i++){
			if(!visited[i]){
				ans =dfs(i);
				if(ans != 0) flag = false;
			}
		}
		if(flag)printf("YES\n");
		else printf("NO\n");
	}
}