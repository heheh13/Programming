#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 10000000
#define mod  6
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
std::vector<int> prime;
bool check[mx];
void seive(){
	int sqr = sqrt(mx);
	for(int i = 4;i<mx;i+=2)check[i]=1;
	for(int i = 3;i<=sqrt(mx);i+=2)
		if(!check[i])
			for(int j = i*i;j<mx;j+=2*i)check[j]=1;
	prime.push_back(2);
	for(int i = 3;i<mx;i+=2)if(!check[i])prime.push_back(i);
}
std::vector<int > res;
void factor(int n){
	int sqr =sqrt(n);
	for(int i = 0;prime[i]<=sqr;i++){
		if(n%prime[i]==0){
			while(n%prime[i]==0){
				n/=prime[i];
				res.push_back(prime[i]);
			}
		}
		sqr = sqrt(n);
	}
	if(n!=1)res.push_back(n);
}
map<int,int> mp[mx];
int bt(int pos,int num){
	if(mp[pos][num])return mp[pos][num];
	if(pos>=res.size()){
		cout<<num<<endl;
		return 0;
	}
	mp[pos][num]=bt(pos+1,num*res[pos]);
 	mp[pos][num]=bt(pos+1,num);
	
}
int main(){
	File_IO();
	seive();
	//for(int i = 0;i<10;i++)cout<<prime[i]<<" ";
	factor(20);
	bt(0,1);
}