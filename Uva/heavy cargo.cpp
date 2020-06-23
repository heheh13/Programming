#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 200005
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
std::vector<pair<int,int> > g[mx];
int mini ;
void  dfs(int src, int dest , int par=-1){
    if(src == dest)return ;
    for(auto x:g[src]){
        if(x == src) continue;
        dfs(x.first, dest, src);
    }
}
int main(){
    File_IO();
    int n,m;
    while(cin>>n>>m && n+m){
        map<string,int> mp;
        string a,b;
        int cst;
        int pos = 0;
        for(int i = 0;i<m;i++){
            cin>>a>>b>>cst;
            if(!mp[a])mp[a]=++pos;
            if(!mp[b])mp[b]=++pos;
            g[mp[a]].push_back({mp[b],cst});
            g[mp[b]].push_back({mp[b],cst});
        }
        cin>>a>>b;
        int ans = 0;
        for(auto x:g[mp[a]]){
            ans = max(ans,dfs(src,mp[a]));
        }
        cout<<ans<<endl;
    }
}