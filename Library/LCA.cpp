#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define dbg1(x) cout<< #x<<" = "<<x<<endl;
#define dbg2(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<" "<<#z <<" = "<<z<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 50005
#define mod  100000007
#define sc1(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d %d",&a,&b)

/*#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")*/
void File_IO () {
  #ifndef ONLINE_JUDGE
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
std::vector<int> g[mx];

int par[mx],sp[mx][25],lvl[mx];

void dfs(int src , int p , int depth){
	par[src]=p;
	lvl[src]=depth;
	for(auto x:g[src]){
		if(x==p)continue;
		dfs(x,src,depth+1);
	}
}


void sparse_table(int n){
	memset(sp,-1,sizeof(sp));
	for(int i = 0;i<n;i++)sp[i][0]=par[i];
	for(int j = 1;(1<<j)< n; j++){
		for(int i = 0;i<n;i++){
			if(sp[i][j-1]!=-1){
				sp[i][j] = sp[sp[i][j-1]][j-1];
			}
		}
	}
}

int find_lca(int n , int p , int q){
	if(lvl[p]<lvl[q])swap(p,q);
	int log = 1;
	while(1){
		int next = log+1;
		if((1<<next) > lvl[p])break;
		log++;
	}

	for(int i = log; i >= 0; i--){
		if(lvl[p]-(1<<i) >= lvl[q])
			p= sp[p][i];
	}

	if(p==q)return p;

	for(int  i = log ; i >= 0; i--){
		if(sp[p][i] !=-1 && sp[p][i] !=sp[q][i]){
			p = sp[p][i] , q = sp[q][i];
		}
	}
	return par[p];
}

int main(){
	File_IO();
	int n,m;
	cin>>n>>m;
	for (int i = 0;i<m;i++){
		int a, b;
		cin>>a>>b;
		a--,b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1,1,0);
	sparse_table(n);
	int a, b;
	cin>>a>>b;

	cout<<find_lca(n,a-1,b-1)<<endl;
}