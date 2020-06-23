#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 505
#define mod  6
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int dir_x[]={ +1, -1,  0, 0};
int dir_y[]={  0,  0, +1, -1};
char grid[mx][mx];
int visited[mx][mx];
int n,m;
bool valid(int x,int y){
	if(x<0 || x>=n || y<0 ||y>=m)return 0;
	return 1;
}
int  dfs(int x,int y,int region){
	if(visited[x][y]) return 0;
	visited[x][y]=region;
	int cnt  = (grid[x][y]=='C');
	for(int i = 0;i<4;i++){
		int px = x+dir_x[i];
		int py = y+dir_y[i];
		if(valid(px,py)&&grid[px][py]!='#'){
			cnt += dfs(px,py,region);
		}
	}
	return cnt;
}
int main(){
	File_IO();
	optimizar;
	int t;
	cin>>t;
	for(int ts = 1;ts<=t;ts++){
		memset(visited,0,sizeof(visited));
		int Q;
		cin>>n>>m>>Q;
		for(int i  = 0;i<n;i++){
			for(int j = 0;j<m;j++){
				cin>>grid[i][j];
			}
		}
		int region =1;
		int ans [25000];
		for(int i = 0;i<n;i++){
			for(int j = 0;j<m;j++){
				if(!visited[i][j]&&grid[i][j]!='#'){
					ans[region]=dfs(i,j,region);
					region ++;
				}
			}
		}
		cout<<"Case "<<ts<<":"<<endl;
		while(Q--){
			int a,b;
			cin>>a>>b;
			cout<<ans[visited[a-1][b-1]]<<endl;
		}
	}
}