#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 32000
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
std::vector< int > prime;
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
std::vector<int> v;
int facotize(int num){
	int sqr = sqrt(num);
	int res = 1;
	for(int i = 0;prime[i]<=sqr;i++){
		int cnt = 0;
		int temp = 1;
		int now =1;
		if(num%prime[i]==0){
			while(num%prime[i]==0){
				num/=prime[i];
				now *=prime[i];
				temp+=now;
			}
			res *= temp;
		}
	}
	if(num!=1){
		res *= (1+num);
	}
	return res;
}
ll cum[10000001];
int main(){
	File_IO();
	optimizar;
	seive();
	for(int i =1;prime[i]*2<=1e7;i++){
		int temp = prime[i];
		while(temp*2<=1e7){
			temp*=2;
			v.push_back(temp);
		}
	}
	sort(v.begin(),v.end());
	for(int i = 0;i<v.size();i++){
		cum[v[i]] = facotize(v[i]) - v[i]*2;
	}
	for(int i = 1;i<=1e7;i++){
		cum [i] = cum[i-1]+cum[i];
	}
	for(int i = 0;prime[i]<=2047;i++){
		cout<<prime[i]<<endl;
	}
	int n;
	while(cin>>n&&n){
		cout<<n<<" "<<cum[n]<<endl;
	}
}
