#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define dbg1(x) cout<< #x<<" = "<<x<<endl;
#define dbg2(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<" "<<#z <<" = "<<z<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 200005
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
void find_articulation_point(int src, int par){
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
				AP.push_back(src);

			}
			child++;
		}
		if(src == root && child>1)AP.push_back(src);
	}
}
int main(){
	File_IO();
	int n,m;
	scanf("%d %d",&n,&m);
	int a, b;
	for(int i = 0;i<m;i++){
		scanf("%d %d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	find_articulation_point(root,-1);
	for(auto x:AP)cout<<x<<endl;
}