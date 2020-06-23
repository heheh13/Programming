#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define dbg1(x) cout<< #x<<" = "<<x<<endl;
#define dbg2(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<" "<<#z <<" = "<<z<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 50005
#define mod  100000007
#define sc1(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d %d",&a,&b)
void File_IO () {
  #ifndef ONLINE_JUDGE
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
std::map<pair<ll,ll> , ll> mp;
int  main(){
	#ifndef ONLINE_JUDGE
	read();
	write();
	double t1 = clock();
	#endif
	optimizar;
	ll n;
	cin>>n;
	ll arr[n+1],brr[n+1];
	for(ll i = 0;i<n;i++)cin>>arr[i];
	for(ll i = 0;i<n;i++)cin>>brr[i];
	ll ans = 0,cnt = 0;
	for(ll i = 0;i<n;i++){
		if(arr[i]==0 && brr[i]==0)cnt++;
		if(arr[i]==0)continue;
		int g = __gcd(brr[i],arr[i]);
		mp[{brr[i]/g,arr[i]/g}]++;
		//double help = -(double)brr[i]/(double)arr[i];
		// int nxt = 0;
		// while(help-(ll)help != 0&& nxt<8)help*=10,nxt++;
		// mp[(ll)help]++;
	}
	for(auto x:mp)ans = max(ans,x.second);
	cout<<ans+cnt<<endl;
	#ifndef ONLINE_JUDGE
	double t2 = clock();
	printf("%.10lf\n", (t2-t1));
	#endif
	return 0;
}