#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 46341
#define mod  1000000007
#define sc1(a) scanf("%d",&a)
#define sc2(a,b) scanf("%lld %lld",&a,&b)
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
#define MAXN 100005
typedef long long ll;
int main(){
	File_IO();
	int t;
	scanf("%d",&t);
	for(int ts = 1;ts<=t;ts++){
		ll ab ;
		scanf("%lld",&ab);
		ll low = 0 ,high = ab;
		printf("Case %d:",ts );
		std::vector<ll > v;
		while(low<=high){
			ll mid = (high+low)/2;
			ll now = mid + ab;
			if(now - now/10 == ab){
				v.push_back(now);
				high = mid-1;
			}
			else if(now - now/10 < ab) low = mid+1;
			else high = mid-1;
		}
		std::vector<ll> ans;
		for(int i = 0;i<v.size();i++){
			for(int j = 0;j<=9;j++){
				ll now = v[i]+j;
				if(now-now/10 == ab)ans.push_back(now);
			}
			for(int j = 9;j>=0;j--){
				ll now = v[i]+j;
				if(now-now/10 == ab)ans.push_back(now);
			}
		}
		sort(ans.begin(),ans.end());
		ans.resize(unique(ans.begin(),ans.end() ) - ans.begin());
		for(int i = 0;i<ans.size();i++)printf(" %lld",ans[i] );
		printf("\n");
	}
	
}