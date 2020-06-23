#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 25
#define mod  6
#define inf 1e9
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
char grid[mx][mx];
int n,m;
int dir_x[]={+1,+1,-1,-1,+2,+2,-2,-2};
int dir_y[]={+2,-2,+2,-2,+1,-1,+1,-1};
bool valid(int x, int y){
    if(x<0 || x>=n||y<0|| y>=m)return false;
    return true;

}
int bfs(int x, int y ){
    int dist[mx][mx];
    for(int i = 0;i<mx;i++)
        for(int j = 0; j<mx; j++)
            dist[i][j]=inf;
    queue<pair<int,int> > q;
    q.push({x,y});
    dist[x][y]=0;
    while(!q.empty()){
        pair<int,int> fnt = q.front();
        q.pop();
        
        for(int i = 0;i<8;i++){
            x = fnt.first+dir_x[i];
            y = fnt.second+dir_y[i];
            if(valid(x,y)&&dist[x][y]>dist[fnt.first][fnt.second]+1){
                dist[x][y] = dist[fnt.first][fnt.second]+1;
                q.push({x,y});
            }
        }
    }
    int ans = 0;
    for(int i = 0;i<n;i++){
            for(int j = 0;j <m; j++){
                if(grid[i][j]>='1'&&grid[i][j]<='9'){
                    if(dist[i][j]==inf)return inf;
                    int temp =grid[i][j]-'0';
                    ans += (dist[i][j]+temp-1)/temp;
                }
            }
        }
    return ans;
}
int main(){
    optimizar;
	File_IO();
    int t;
    cin>>t;
    for(int ts = 1; ts<= t; ts++){
        cin>>n>>m;
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                cin>>grid[i][j];
            }
        }
        int ans = inf ;
        for(int i = 0;i<n;i++){
            for(int j = 0; j<m;j++){
                ans = min(ans,bfs(i,j));
            }
        }
        cout<<"Case "<<ts<<": ";
        if(ans<inf)
            cout<<ans<<endl;
        else cout<<"-1"<<endl;

    }

}
