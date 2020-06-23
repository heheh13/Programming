#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 54721
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
std::vector<int > prime;
void seive(){
	int sqr = sqrt(mx);
	for(int i =4;i<mx;i+=2)
		check[i]=1;
	for(int i =3;i<=sqr;i+=2){
		if(!check[i]){
			for(int j = i*i;j<mx;j+=2*i)
				check[j]=1;
		}
	}
	prime.push_back(2);
	for(int i =3;i<=mx;i+=2)
		if(!check[i])
		prime.push_back(i);
	return ;
}
/*int phi(int n){
	int sqr = sqrt(n);

	int sum = n;
	for(int i =0;prime[i]<=sqr;i++){
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
bool cmp(const pair<int,int> &a,const pair<int,int>&b){
	if(a.first == b.first && a.second==b.second)return true;
	return false;
}
int main(){
	File_IO();
	seive();
	int n;
	while(scanf("%d",&n)&&n){
		factorize(n);
		int cnt = 0;
		std::vector<pair<ll,ll> > ans;
		for(int i = 0;i<divisors.size();i++){
			for(int j =0;j< divisors.size();j++){
				ll a = divisors[i];
				ll b = divisors[j];
				if(a*b/__gcd(a,b)==n){
					if(a>b)swap(a,b);
					ans .push_back({a,b});
				}
			}
		}
		sort(ans.begin(),ans.end());
		ans.resize(unique(ans.begin(),ans.end(),cmp)-ans.begin());
		printf("%d %d\n",n,ans.size());
		divisors.clear();
		divs.clear();
		ans.clear();
	}
}