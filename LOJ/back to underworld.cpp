#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 200005
#define mod  6
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
std::vector<int> g[mx];
bool visited[mx];
int lyc,vamp;
void dfs(int src,int idx){
	if(visited[src])return;
	visited[src]=idx;
	if(idx == -1)lyc++;
	else vamp++;
	for(int i =0;i<g[src].size();i++){
		dfs(g[src][i],-idx);
	}
}
int main(){
	File_IO();
	optimizar;
	int t;
	cin>>t;
	for(int ts = 1;ts<=t ;ts++){
		memset(visited,0,sizeof(visited));
		for(int i=0;i<mx;i++)g[i].clear();
		int edge;
		cin>>edge;
		map<int,int>mp;
		for(int i = 0;i<edge;i++){
			int a,b;
			cin>>a>>b;
			g[a].push_back(b);
			g[b].push_back(a);
			mp[a]=1;
			mp[b]=1;
		}
		int ans=0;
		map<int,int> :: iterator it;
		for(it =mp.begin();it!=mp.end();it++){
			if(!visited[it->first]){
				vamp=lyc=0;
				dfs(it->first,1);
				ans+=max(vamp,lyc);
			}
		}
		cout<<"Case "<<ts<<": "<<ans<<endl;
	}
}