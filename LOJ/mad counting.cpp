#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 1000006
#define mod  1000000007
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
map<int,int> mp;
int main(){
 
    File_IO();
    int t;
    scanf("%d", &t);
    for(int ts = 1; ts <= t; ts++){
        int n,temp;
        scanf("%d", &n);
        mp.clear();
        for(int i = 0; i < n ;i++){
            scanf("%d ",&temp);
            mp[temp]++;
        }
        int ans = 0;
        for(auto x:mp){
            ans += (x.first+1) * ((x.second + x.first)/ (x.first+1));
        }
        printf("Case %d: %d\n", ts, ans);
    }
 
}