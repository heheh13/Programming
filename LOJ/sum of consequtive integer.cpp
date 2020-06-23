#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 100001000
#define mod  1000
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MAX 10000100
unsigned flag[500+MAX>>6];
#define ifc(n) (flag[n>>6]&(1<<((n>>1)&31)))
#define isc(n) (flag[n>>6]|=(1<<((n>>1)&31)))
int idx;
int prime[664585];
void sieve() {
    unsigned i, j, k;
    unsigned LMT = sqrt(MAX);
    for(i=3; i<LMT; i+=2)
        if(!ifc(i))
            for(j=i*i, k=i<<1; j<MAX; j+=k)
                isc(j);
    prime[idx++] = 2;
    for(i = 3;i<=MAX;i+=2)if(!ifc(i))prime[idx++]=i;
}
std::vector<pair<int,int> > fact;
ll find_divisors(int pos,  ll num){
	if(pos>=fact.size()){
		if(num&1)return 1;
		return 0;
	}
	int ans = 0;
	ll temp = 1;
	for(int i = 0;i<=fact[pos].second;i++){
		ans+=find_divisors(pos+1,temp*num);
		temp*=fact[pos].first;
	}
	return ans;
}
int factorize(ll n){
	int sqr = sqrt(n);
	for(int i  = 0;prime[i]<=sqr;i++){
		if(n%prime[i]==0){
			int cnt = 0;
			while(n%prime[i]==0){
				n/=prime[i];
				cnt++;
			}
			fact.push_back({prime[i],cnt});
		}
		sqr = sqrt(n);
	}
	if(n!=1)fact.push_back({n,1});
	//for(auto x:fact)cout<<x.first<<" "<<x.second<<endl;
	return find_divisors(0,1);
}
int main(){
	File_IO();
	sieve();
	int t;
	scanf("%d",&t);
	for(int ts = 1;ts<=t;ts++){
		ll n;
		scanf("%lld",&n);
		printf("Case %d: %d\n",ts,factorize(n)-1);
		fact.clear();
	}
}