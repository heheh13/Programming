#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 25
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
char grid[mx][mx];
bool valid(int r,int c){
	if(r<0 || r>=m ||c<0 ||c>=n)return false;
	return true;
}
bool visited[mx][mx];
int floodfil(int r,int c){
	if(!valid(r,c))return 0;
	if(grid[r][c]=='#')return 0;
	if(visited[r][c])return 0;
	visited[r][c]=1;
	int ans = 1;
	ans+=floodfil(r+1,c);
	ans+=floodfil(r-1,c);
	ans+=floodfil(r,c+1);
	ans+=floodfil(r,c-1);
	return ans;
}
int main(){
	File_IO();
	int t;
	cin>>t;
	int ts = 1;
	while(t--){
		memset(visited,0,sizeof(visited));
		cin>>n>>m;
		int x,y;
		for(int i  = 0;i<m;i++){
			for(int j =0;j<n;j++){
				cin>>grid[i][j];
				if(grid[i][j]=='@'){
					x=i,y=j;
				}
			}
		}
		//cout<<x<<y<<endl;
		cout<<"Case "<<ts++<<": "<<floodfil(x,y)<<endl;
	}
}