#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 10000005
#define mod  6
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
int main(int argc, char const *argv[])
{
	File_IO();
	int n,m;
	cin>>n>>m;
	char grid[n+1][m+1];
	bool flag = true;
	int r,c;
	for(int i  = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			cin>>grid[i][j];
			if(grid[i][j]=='B'&&flag){
				r = i;
				c=j;
				flag = false;
			}
		}
	}
	int ans = 0;
	std::vector<pair<int,int> > v;
	while(1){
		if(grid[r][c]=='B'){
			v.push_back({r,c});
			r++;
			c++;
			
		}
		else break;
	}
	int x = v.size()/2;
	cout<<v[x].first<<" "<<v[x].second<<endl;
}