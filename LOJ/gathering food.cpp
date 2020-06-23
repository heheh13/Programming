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
int dir_x[]={+1, -1,  0, 0};
int dir_y[]={ 0,  0, +1, -1};
int n;
bool valid(int x,int y){
    if(x<0||x>=n || y<0 || y>=n)
        return false;
    return true;
}
int bfs(int x,int y,int dest){
    int dist[mx][mx];
    for(int i = 0;i<mx;i++){
        for(int j = 0;j<mx;j++){
            dist[i][j]=inf;
        }
    }
    queue<pair<int,int> >q;
    q.push({x,y});
    dist[x][y]=0;
    while(!q.empty()){
        int a1 = q.front().first;
        int a2 = q.front().second;
        if(grid[a1][a2]==dest){
            //cout<<grid[a1][a2]<<endl;
            grid[a1][a2]='.';
            return dist[a1][a2];
        }
        q.pop();
        for(int i = 0;i<4;i++){
            x = a1+dir_x[i];
            y = a2+dir_y[i];

            if(valid(x,y)&&(grid[x][y]!='#'&&grid[x][y]<=dest)){
                    if(dist[x][y]>dist[a1][a2]+1){
                        dist[x][y]=dist[a1][a2]+1;
                        q.push({x,y});
                    }

               }
        }
    }
    return inf;
}
struct  bal
{
    int val;
    int x,y ;
    
}k[30];
int main(){
	File_IO();
    int t;
    cin>>t;
    for(int ts = 1;ts<=t;ts++){
        
        cin>>n;
        map<int , pair<int,int> > mp;
        for(int i = 0;i<n;i++){
            for(int  j = 0;j<n;j++){
                cin>>grid[i][j];
                if(grid[i][j]>='A'&&grid[i][j]<='Z'){
                    mp[grid[i][j]]={i,j};
                }
            }
        }
        map<int , pair<int,int> > :: iterator it;
        int pos = 0;
        for(it = mp.begin();it!=mp.end();it++){
            k[pos].val = it->first;
            k[pos].x = it->second.first;
            k[pos].y = it->second.second;
            pos++;
        }
        int ans = 0;
        bool flag=true;
        for(int i = 0;i<pos-1;i++){
            int temp = bfs(k[i].x,k[i].y,k[i+1].val);
            if(temp<inf)
                ans+=temp;
            else{
                flag = false;
                break;
            } 
        }
        cout<<"Case "<<ts<<": ";
        if(flag)cout<<ans<<endl;
        else cout<<"Impossible"<<endl;

    }
}
