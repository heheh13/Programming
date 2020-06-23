#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 300005
#define mod  998244353
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
std::vector<ll > g[mx];
ll  visited[mx];
ll  one ;
ll  two;
bool bicolor;
bool dfs(ll  src,ll  color){
	if(visited[src])return 1;
	visited[src]=color;
	if(color == 1)one++;
	else two++;
	for(auto x:g[src]){
		if(visited[x] == visited [ src]) {
			bicolor = false;
			return 1;
		}
		dfs(x,-color);
	}
	return 1;
}
ll pow_two[mx];
int  main(){
	File_IO();
	optimizar;
	ll  t;
	
	pow_two[0]=1;
	for(ll  i = 1;i<mx;i++){
		pow_two [i] = (pow_two[i-1] * 2)%mod;
	}
	cin>>t;
	while(t--){
		ll  n,m;

		cin>>n>>m;
		ll  a,b;
		for(ll  i= 0;i<=n;i++)g[i].clear(),visited[i]=0;
		for(ll  i = 0;i<m;i++){
			cin>>a>>b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		ll ans = 1;
		bool flag = true;
		for(ll  i = 1;i<=n;i++){
			if(!visited[i]){
				one = 0, two = 0;
				bicolor = true;
				dfs(i,1);
				flag &=bicolor;
				ans *= (pow_two[one] %mod + pow_two[two] %mod)%mod;
				ans%=mod;
			}
		}
		if(flag)
		cout<<ans%mod<<endl;
		else cout<<"0"<<endl;

	}
}
