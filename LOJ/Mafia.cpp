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
std::vector<int> v[mx];
int mafia[mx];
int visted[mx];
int cost ;
int dfs(int src){
	if(visted[src])return 0;
	visted[src]=1;
	int cnt = mafia[src];
	for(int i = 0;i<v[src].size();i++){
		cnt+= dfs(v[src][i]);
	}
	cost+=abs(cnt-1);
	return cnt-1;
}
int main(){
	optimizar;
	File_IO();
	int t;
	cin>>t;
	int n;
	for(int ts = 1;ts<=t;ts++){	
		for(int i=0;i<mx;i++)v[i].clear();
		cin>>n;
		for(int i = 1;i<=n;i++){
			int city,adj;
			cin>>city>>mafia[i]>>adj;
			int temp;
			for(int j = 0;j<adj;j++){
				cin>>temp;
				v[city].push_back(temp);
				v[temp].push_back(city);
			}
		}
		memset(visted,0,sizeof(visted));
		cost=0;
		dfs(1);
		cout<<"Case "<<ts<<": ";
		cout<<cost<<endl;
	}
}