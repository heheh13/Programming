#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define dbg1(x) cout<< #x<<" = "<<x<<endl;
#define dbg2(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<" "<<#z <<" = "<<z<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 10004
#define mod  100000007
#define sc1(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d %d",&a,&b)

#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
void File_IO () {
  #ifndef ONLINE_JUDGE
  read();write();
  #endif
}
using namespace std;
#define ss second
#define ff first
typedef long long ll;
vector<int> g[mx];
std::vector<int> AP;
bool visited[mx];
int t = 0;
int low [mx],d[mx];
int root = 1;
int arti[mx];
void find_articulation_point(int src, int par){
	//if(!g[src].size()){arti [src]=1;return ;}
	t++;
	low[src] = d[src] =t;
	visited[src]=1;
	int child = 0;
	for(auto x:g[src]){
		if(x == par)continue;
		if(visited[x]){
			//back edge
			low[src] = min(low[src],d[x]);
		}

		if(!visited[x]){
			find_articulation_point(x,src);
			//dbg2(src,x)
			low [src] = min(low[src],low[x]);
			if(d[src]<=low[x] && src !=root){
				arti[src]=1;
			}
			child++;
		}
		if(src == root && child>1)arti[src]=1;
	}
}
int main(){
	File_IO();
	int tc;
	scanf("%d",&tc);
	int n,m;
	for(int ts =1 ;ts<=tc;ts++){
		scanf("%d %d",&n,&m);
		
		int a, b;
		for(int i = 0;i<m;i++){
			scanf("%d %d",&a, &b);
			g[a].push_back(b);
			g[b].push_back(a);
		}
		memset(visited,0,sizeof(visited));
		memset(low,0,sizeof(low));
		memset(d,0,sizeof(d));
		memset(arti,0,sizeof(arti));
		t = 0;
		for(int i = 0;i<n;i++){
			if(!visited[i])
			root = i,find_articulation_point(i,-1);

		}
		int cnt = 0;
		for(int i = 0;i<n;i++)cnt+=arti[i];
		if(cnt)
		printf("Case %d: %d\n",ts,n-cnt-1);
		else printf("Case %d : 0\n",ts );
		for(int i = 0;i<n;i++)g[i].clear();
	}
}