#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 100001000
#define mod  4294967296
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef unsigned ll;
typedef unsigned long long ull;
#define MAX 100001000
#define LMT 10000
unsigned flag[500+MAX>>6];
#define ifc(n) (flag[n>>6]&(1<<((n>>1)&31)))
#define isc(n) (flag[n>>6]|=(1<<((n>>1)&31)))
int idx;
int prime[5761519];
void sieve() {
    unsigned i, j, k;
    for(i=3; i<LMT; i+=2)
        if(!ifc(i))
            for(j=i*i, k=i<<1; j<MAX; j+=k)
                isc(j);
    prime[idx++] = 2;
    for(i = 3;i<=MAX;i+=2)if(!ifc(i))prime[idx++]=i;
}
unsigned ans[5761519];
int main(){
	optimizar;
	File_IO();
	//double c1 = clock();
	sieve();
	ans[0]=1;
	int x = 1;
	for(int i = 0 ;i<idx;i++){
		ans[x]= (ll)ans[x-1] *  (ll)prime[i];
		ans[x]%=mod;
		x++;
	}
	

	int t ;
	cin>>t;
	for(int ts = 1;ts<=t ;ts++){
		ll hell=1;
		int n;
		cin>>n;
		int sqr = sqrt(n);
		for(int i = 0;prime[i]<= sqr;i++){
			long long num = prime[i];
			while((long long)num *(long long) prime[i] <= n){
				num*=prime[i];
			}
			hell *= num/prime[i];
			hell %= mod;
		}
		int  low = upper_bound(prime,prime+idx,n)-prime;
		ll help = ans[low];
		hell = (hell%mod * help %mod)%mod;
		cout<<"Case "<<ts<<": "<<hell<<endl;
	}

	//double c2 = clock();
	//cout<<(c2-c1)/CLOCKS_PER_SEC<<endl;
}