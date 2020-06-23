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
	for(int  i =3;i<mx;i+=2)
		if(!check[i])
		prime.push_back(i);
	return ;
}
int dp[100005][101];
int phi(int n, int k){

	if(n<100005 && k<100)
		if(dp[n][k]!=-1)return dp[n][k];
	if(k==0)return n-n/2;
	if(n<100005 && k<100)
		return dp[n][k]= phi(n,k-1) - phi(n/prime[k],k-1);
	return phi(n,k-1) - phi(n/prime[k],k-1);
}

int main(){
	File_IO();
	seive();
	memset(dp,-1,sizeof(dp));

	int t;
	scanf("%d",&t);
	for(int ts = 1;ts<=t ;ts++){
		int a, b;	
		scanf("%d %d",&a,&b);
		if(a>b)swap(a,b);
		int k = lower_bound(prime.begin(),prime.end(),sqrt(a-1))-prime.begin();
		int v1,v2;
		if(a-1<2)v1 = 0;
		else v1 = phi(a-1,k)+k;
		k = lower_bound(prime.begin(),prime.end(),sqrt(b))-prime.begin();
		if(b<2)v2 = 0;
		else  v2 = phi(b,k)+k;
		//dbg(v2,v1);
		printf("Case %d: %d\n",ts,v2-v1);
	}
}