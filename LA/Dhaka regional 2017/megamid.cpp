#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 100000
#define mod  6
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
int main(){
	File_IO();
	int t;
	scanf("%d",&t);
	for(int  ts =1;ts<=t;ts++){
		printf("Case %d: ",ts);
		ll e,p,k,r;
		scanf("%lld%lld%lld%lld",&e,&p,&k,&r);
		if(e<=p*k){
			ll temp = (e+p-1)/p;
			printf("%lld\n",temp);
			continue;
		}
		if(e>p*k && r>=p*k)
		{
			puts("-1");
			continue;
		}
		ll x = p*k;
		ll dif = x-r;
		ll ans = 0;
		if(dif>0){
			ll val = (e-x)/dif;
			// if(val<=0){
			// 	ans = (e+p-1)/p;
			// 	printf("%lld\n",ans);
			// 	continue;
			// }
			ans+=val*k;
			ll current=(val*dif);
			while(1){
				if(current+x>=e){
					ans +=(e-current+p-1)/p;
					//debug(ans);
					break;
				}
				else{
					ans+=k;
					current+=dif;
				}
			}
		}
		else{
			ans = (e+p-1)/p;
		}
		printf("%lld\n",ans);

	}
}





