#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 100005
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
bool visited[mx];
int t;
vector<pair<int,int> > v(mx);
void dfs(int src,int par=-1){
	v[src].second=t++;
	bool first = true;
	for(auto x:g[src]){
		if(x==par)continue;
		if(first){
			first=false;
			v[x].first=v[src].second;
			dfs(x,src);
		}
		else {
			v[x].first=v[src].first;
			dfs(x,src);
		}
	}
}
int  main(){
	File_IO();
	int n;
	while(cin>>n)
	{
		for(int i = 0;i<mx;i++)g[i].clear();
			v.clear();
		for(int i = 1;i<n;i++){
			int a,b;
			cin>>a>>b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		t=2;
		if(n==2){
			cout<<"1 2\n1 2\n";
			continue;
		}
		v[1].first = 1;
		dfs(1);
		for(int i = 1;i<=n;i++)
			cout<<v[i].first<<" "<<v[i].second<<endl;
	}
	(~x)
}