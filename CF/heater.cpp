#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 20
#define mod  6
#define ff first
#define ss second
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
std::vector<pair<int,int> > v;
std::vector<int> g[mx];
bool cmp(const pair<int,int> a, const pair<int,int> b){
	if(a.ff== b.ff){
		return a.ss>b.ss;
	}
	return a.ff<b.ff;
}
int bfs(int src, int dest){
	int dist[mx];
	for(int i = 0;i<mx;i++)dist[i]=1e9;
	dist[src]=0;
	queue<int>q;
	q.push(src);
	while(!q.empty()){
		int fnt  = q.front();
		q.pop();
		for(auto x:g[fnt]){
			if(dist[x]>dist[fnt]+1){
				dist[x]=dist[fnt]+1;
				q.push(x);
			}
		}
	}
	return dist[dest];
}
int  main(){
	File_IO();
	int n,m;
	cin>>n>>m;
	int temp[n+1];
	for(int i = 1;i<=n;i++){
		cin>>temp[i];
		if(temp[i] == 1){
			int a = max(1,i-m+1);
			int b = min(n,i+m-1);
			v.push_back({a,b});
		}
	}
	sort(v.begin(),v.end(),cmp);

	for(auto x:v){
		g[x.ff].push_back(x.ss);
		g[x.ss].push_back(x.ff);
	}

	for(int i = 0;i<=v.size();i++){
		for(int j = i+1;j<v.size();j++){
			if(v[i].ss>=v[j].ff){
				g[v[i].ss].push_back(v[j].ss);
				g[v[j].ss].push_back(v[i].ss);
			}
		}
	}
	 
	 int ans = bfs(1,n);
	 if(ans<1e9){
	 	cout<<ans<<endl;
	 }
	 else cout<<"-1"<<endl;
}
