#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 105
#define mod  6
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int n,m;
int grid[mx][mx];
bool visited[mx][mx];
int dirx[4]={-1,1,0,0};
int diry[4]={0,0,-1,1};
int ans = 0;
bool valid(int r,int c){
	if(r<0 || c<0)return 0;
	if(r>=n ||c>=m)return 0;
	return 1;
}
int maxi = 0;
int dp[mx][mx];
int bt(int row, int col,int cnt){
	///if there is no way
	//if(dp[row][col])return dp[row][col];
	if(!valid(row,col))return cnt;
	if(visited[row][col])return cnt;
	for(int i =0;i<4;i++){
		int r = row+dirx[i];
		int c = col + diry[i];
		if(grid[row][col]>grid[r][c]){
			visited[row][col]=1;
			bt(r,c,cnt+1);
			visited[row][col]=0;
		}
	}
	return maxi = max(maxi,cnt);
}
int main(){
	File_IO();
	int t;
	cin>>t;
	while(t--){
		string line;
		cin>>line;
		cin>>n>>m;
		for(int i = 0;i<n;i++){
			for(int j = 0;j<m;j++)cin>>grid[i][j];
		}
		ans = 0;
		memset(dp,0,sizeof(dp));
		for(int i  = 0;i<n;i++){
			
			for(int j = 0;j<m;j++){
				maxi =0;
				dp[i][j]=bt(i,j,1);
				///debug(dp[i][j]);
				ans = max(ans,dp[i][j]);
			}
		}
		cout<<line<<": "<<ans<<endl;
	}

}