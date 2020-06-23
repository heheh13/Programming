#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 3162777
#define mod  6
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
bool check[mx];
std::vector<ll > prime;
void seive(){
	ll sqr = sqrt(mx);
	for(ll i =4;i<mx;i+=2)
		check[i]=1;
	for(ll i =3;i<=sqr;i+=2){
		if(!check[i]){
			for(ll j = i*i;j<mx;j+=2*i)
				check[j]=1;
		}
	}
	prime.push_back(2);
	for(ll i =3;i<=mx;i+=2)
		if(!check[i])
		prime.push_back(i);
	return ;
}
/*ll phi(ll n){
	ll sqr = sqrt(n);

	ll sum = n;
	for(ll i =0;prime[i]<=sqr;i++){
		if(n%prime[i]==0){
			while(n%prime[i]==0){
				n/=prime[i];
			}
			sqr=sqrt(n);
			sum-=sum/prime[i];
		}
	}
	if(n!=1) 
		sum-=sum/n;
	return sum;
}*/
vector<pair<ll,ll> > divs;
std::vector<ll> divisors;
void find_divisors(ll pos, ll n){
	if(pos == divs.size()){
		divisors.push_back(n);
		return ;
	}
	ll temp = 1;
	for(ll i = 0;i<=divs[pos].second;i++){
		find_divisors(pos+1,n*temp);
		temp*=divs[pos].first;
	}
}
void factorize(ll n){
	ll sqr = sqrt(n);
	for(ll i = 0;prime[i]<=sqr;i++){
		if(n%prime[i]==0){
			ll cnt =0;
			while(n%prime[i]==0){
				n/=prime[i];
				cnt++;
			}
			divs.push_back({prime[i],cnt});
		}
	}
	if(n!=1){
		divs.push_back({n,1});
	}
	find_divisors(0,1);
}
int main(){
	//optimizar;
	File_IO();
	seive();
	ll n;
	// while(scanf("%lld",&n)&&n){
	// 	factorize(n);
	// 	ll ans = 0;
	// 	divisors.erase(divisors.begin()+0);
	// 	for(auto x:divisors){
	// 		ll temp = n;
	// 		if(temp%x==0){

	// 			while(temp %x ==0){
	// 				temp/=x;
	// 				ans++;
	// 			}
	// 		}
	// 	}
	// 	printf("%lld %lld\n",n,ans);
	// 	//cout<<n<<" "<<ans<<endl;
	// 	divisors.clear();
	// 	divs.clear();

	// }
}