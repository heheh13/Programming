#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 10005
#define mod  6
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
std::vector<int > g[mx];
int cnt ;
bool visted[mx];
void dfs(int src){
	if(visted[src])return ;
	visted[src]=1;
	cnt++;
	for(auto x:g[src]){
		dfs(x);
	}
}
int  main(){
	File_IO();
	optimizar;
	int t;
	cin>>t;
	while(t--){
		memset(visted,0,sizeof(visted));
		for(int i = 0;i<mx;i++){
			g[i].clear();
		}
		int n,m,l;
		cin>>n>>m>>l;
		for(int i = 0;i<m;i++){
			int a,b;
			cin>>a>>b;
			g[a].push_back(b);
		}
		cnt = 0;
		while(l--){
			int temp;
			cin>>temp;
			dfs(temp);
		}
		cout<<cnt<<endl;
	}
}