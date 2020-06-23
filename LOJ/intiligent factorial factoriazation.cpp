#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 115
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

int main(){
	File_IO();
	seive();
	int t;
	sc1(t);
	for(int ts = 1;ts<=t ;ts++){
		int n;
		sc1(n);
		printf("Case %d: %d =",ts,n);
		for(int i = 0;prime[i]<=n;i++){
			int now = n;
			int cnt = 0;
			while(now){
				cnt+=now/prime[i];
				now/=prime[i];
			}
			if(prime[i+1]>n)
				printf(" %d (%d)",prime[i],cnt);
			else printf(" %d (%d) *",prime[i],cnt);
		}
		printf("\n");
	}
}