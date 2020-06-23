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
bitset<mx>calc[mx],pep,check,test;
std::vector<int> g[mx];
bool visited[mx];
void dfs(int src,int par=0){
	calc[src]|=calc[par];
	if(pep[src])
		calc[src].set(src);
	if(visited[src])return;
	visited[src]=1;
	for(int i =0;i<g[src].size();i++){
		int x = g[src][i];
		dfs(x,src);
	}
}
int main(){
	optimizar;
	File_IO();
	int t ;
	cin>>t;
	for(int ts = 1;ts<=t; ts++){
		for(int i = 0;i<mx;i++){
			calc[i].reset();
			g[i].clear();
		}
		pep.reset();

		int n,m,k;
		cin>>k>>n>>m;
		int temp;
		for(int i = 1;i<=k;i++){
			cin>>temp;
			pep.set(temp);
		}
		for(int i = 0;i<m;i++){
			int a,b;
			cin>>a>>b;
			g[a].push_back(b);
		}
		for(int i =1;i<mx;i++){
			if(pep[i]){
				memset(visited,0,sizeof(visited));
				dfs(i);
			}
		}
		int cnt =0;
		for(int i =1;i<=n;i++){
			test = (calc[i]^pep);
			if(test == check)cnt++;
		}
		cout<<"Case "<<ts<<": "<<cnt<<endl;
	}
}