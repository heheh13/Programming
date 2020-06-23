#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 10006
#define mod  1000000007
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
map<string,int > mp;
std::vector<int> g[mx];
int in[mx],out[mx];
stack<int> stk;
int  color [mx];

bool cycle;
void dfs(int src){
	color[src]=1;
	for(int i = 0;i<g[src].size();i++){
		int v =g[src][i];
		if(color[v]==1)cycle=true;
		if(color[v]==0)
			dfs(v);
	}
	color[src]=2;
	stk.push(src);
}
int main(){
	File_IO();
	optimizar;
	int t;
	cin>>t;
	for(int ts = 1;ts<=t ;ts++){
		mp.clear();
		for(int i=0;i<mx;i++)g[i].clear();
		int n;
		cin>>n;
		int val =0;
		string a,b;
		for(int i = 0;i<n;++i){
			cin>>a>>b;
			if(!mp[a])mp[a]=++val;
			if(!mp[b])mp[b]=++val;
			g[mp[a]].push_back(mp[b]);
			++in[mp[b]];
			++out[mp[b]];
		}
		memset(color,0,sizeof(color));
		cycle = false;
		for(int i = 1;i<=val;i++) if(!color[i]) dfs(i);
		// while(!stk.empty()){
		// 	cout<<stk.top()<<endl;
		// 	stk.pop();
		// }
		// cout<<endl;
	   cout<<"Case "<<ts<<": ";
		if(cycle)cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
}