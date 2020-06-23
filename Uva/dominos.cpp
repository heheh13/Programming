#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 100006
#define mod  1000000007
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
bool visited[mx];
std::vector<int> g[mx];
stack<int> stk;
void topsort(int src){
	if(visited[src])return ;
	visited[src]=1;
	for(auto x:g[src]){
		topsort(x);
	}
	stk.push(src);
}
void dfs(int src){
	if(visited[src])return ;
	visited[src]=1;
	for(auto x:g[src]){
		dfs(x);
	}
}
int main(){
	File_IO();
	int t;
	cin>>t;
	while(t--){
		for(int i = 0;i<mx;i++)g[i].clear();
		int n,m ;
		cin>>n>>m;
		for(int i =0;i<m;i++){
			int a,b;
			cin>>a>>b;
			g[a].push_back(b);
		}
		memset(visited,0,sizeof(visited));
		for(int i = 1;i<=n;i++){
			if(!visited[i])topsort(i);
		}
		memset(visited,0,sizeof(visited));
		int cnt = 0;
		while(!stk.empty()){
			if(!visited[stk.top()]){
				dfs(stk.top());
				cnt++;
			}
			stk.pop();
		}
		cout<<cnt<<endl;
	}
}