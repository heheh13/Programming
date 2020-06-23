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
vector<pair<int,int> > divs;
std::vector<int> divisors;
void find_divisors(int pos, int n){
	if(pos == divs.size()){
		divisors.push_back(n);
		return ;
	}
	int temp = 1;
	for(int i = 0;i<=divs[pos].second;i++){
		find_divisors(pos+1,n*temp);
		temp*=divs[pos].first;
	}
}
void factorize(int n){
	int sqr = sqrt(n);
	for(int i = 0;prime[i]<=sqr;i++){
		if(n%prime[i]==0){
			int cnt =0;
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
	File_IO();
	seive();
	int t;
	sc1(t);
	for(int ts = 1;ts<=t;ts++){
		int L , R;
		sc2(L,R);
		int now = L-R;
		int cnt = 0;
		
		divisors.clear();
		divs.clear();
		factorize(now);
		sort(divisors.begin(),divisors.end());
		printf("Case %d:",ts);
		bool flag = false;
		for(int i = 0;i<divisors.size();i++){
			if(divisors[i]>R)printf(" %d",divisors[i]),flag=true;
		}
		if(!flag)printf(" impossible");
		printf("\n");
	}
}