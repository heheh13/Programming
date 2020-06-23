#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define MAX 100005
#define mod  1000000007
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int  main(){
	File_IO();
	ll n;
	while(cin>>n){

	if(n == 1|| n==0){
		cout<<n<<" "<<"0"<<endl;
		//0return 0;
		continue;
	}
	ll x = sqrt(n);
	ll cnt = 0;
	int t = 100;
	ll num =n, maxi=0;
	int ans = 0;
	while(t--){
		maxi = 0;
		cnt = 0;
		while(x * x == n){
			cnt ++;
			n = x;
			x = sqrt(n);
			num = min(num,n);
		}
		 //num = n;
		ll temp;
		//cout<<cnt<<endl;
		 
		for(ll i = 1;i<=min(n,100000LL);i++){
			temp = n *i;
			ll x = sqrt(temp);
			ll cnttemp = 1;
			if(x * x == temp ){
				//cnttemp = 0;
				while(x*x == temp){
					cnttemp++;
					temp = x;
					x = sqrt(temp);
				}
				if(temp<num){
					num = temp;
					//dbg(num,n);
					//cout<<cnttemp<<endl;
					maxi = max(maxi,cnttemp);
				}
				// maxi = max(maxi,cnttemp);
				// num = min(num,temp);

			}
		}
		n = num;
		ans += cnt+maxi;
		cnt = 0;
		maxi = 0;
	}
	

	cout<<num<< " "<<ans<<endl;
	}
}