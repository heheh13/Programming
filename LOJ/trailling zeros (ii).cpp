#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 46341
#define mod  1000000007
#define sc1(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d %d",&a,&b)
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
#define MAXN 100005
typedef long long ll;
bool check[mx];
std::vector<int > prime;
void seive(){
	int sqr = sqrt(mx);
	for(int i =4;i<mx;i+=2)
		check[i]=1;
	for(int  i =3;i<=sqr;i+=2){
		if(!check[i]){
			for(int j = i*i;j<mx;j+=2*i)
				check[j]=1;
		}
	}
	prime.push_back(2);
	for(int  i =3;i<=mx;i+=2)
		if(!check[i])
		prime.push_back(i);
	return ;
}
int zeros(int n){
	int sum =0;
	while(n){
		sum+=n/5;
		n/=5;
	}
	return sum;
}
int factor_5(int n){
	int five= 0,two = 0;
	int now = n;
	while(now%2==0){
		now/=2 ;
		two++;
	}
	now = n;
	while(now%5==0){
		now/=5;
		five++;
	}
	return min(two,five);
}
int main(){
	File_IO();
	int t;
	scanf("%d",&t);
	for(int ts = 1;ts<=t;ts++){
		int n,r,p,q;
		scanf("%d %d %d %d",&n,&r,&p,&q);
		ll p1 = zeros(n);
		ll p2 = zeros(r);
		ll p3 =zeros(n-r);
		ll p4 = factor_5(p)*q;
		ll ans = max(0LL,p1+p4-p2-p3);
		printf("Case %d: %lld\n",ts,ans );
	}

}