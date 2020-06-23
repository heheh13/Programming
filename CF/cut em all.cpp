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
std::vector<int >g[mx];
bool visited[mx];
int tr ;
int  dfs(int src,int par=-1){
	/*if(visited[src])return 0;
	visited[src]=1;*/
	int cnt = 1;
	for(auto x:g[src]){
		if(x==par)continue;
		cnt+=dfs(x,src);
	}
	if(cnt%2==0){
		tr++;
		return 0;
	}
	return cnt;
}
int main(){
	File_IO();
	int n;
	cin>>n;
	int a,b;
	for(int i = 1;i<n;i++){
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int ans = dfs(1);
	if(ans ==0)cout<<tr-1<<endl;
	else cout<<"-1"<<endl;
}