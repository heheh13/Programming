#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define MAX 93000
#define mod  1000000007
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
// ll sum_of_div(ll n){
// 	ll sum = 0;
// 	for(ll  i = 1;i*i<=n;i++){
// 		if(n%i==0){
// 			if(n/i==i){
// 				sum+=i;
// 				continue;
// 			}
// 			sum+= (i+n/i);
// 		}
// 	}
// 	return sum;
// }
// bool isprime(ll n){
// 	for(ll i = 2;i*i<=n;i++){
// 		if(n%i==0)return false;
// 	}
// 	return true;

// }
// ll main(){
// 	File_IO();
// 	ll k;
// 	cin>>k;
// 	ll n;
// 	while(k--){
// 		cin>>n;
// 		//cout<<"1\n"<<n<<endl;

// 		for(ll i  = 1;i<=1;i++){
// 			ll temp = pow(n,i);
// 			cout<<temp<<" ";
// 			ll hell = sum_of_div(temp);
// 			if(isprime(temp)){
// 				cout<<"prime ";
// 			}
// 			if(ceil(log2(hell))== (ll)log2(hell)){
// 				cout<<(ll)log2(hell)<<endl;
// 			} 
// 		}
// 		cout<<endl;

// 	}
// }
ll isprime(ll n){
	if(n<2)return false;
	for(ll i = 2; i*i <=n; i++){
		if( n % i == 0) return false;
	}
	return true;
}
int  main(){
	File_IO();
	ll t;
	while(cin>>t){
		ll n;
		ll maxi = 0;
		for(ll i = 0;i<t;i++){
			cin>> n;
			if(ceil(log2(n+1)) == (ll) log2(n+1) && isprime(n)){
				maxi = max(maxi , (ll)(log2(n+1)));
			}
		}
		if(maxi){
			cout<<maxi<<endl;
		}
		else cout<<"NO"<<endl;
	}
}