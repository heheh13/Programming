#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 100110
#define mod  6
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
bool check[mx];
std::vector<int > prime;
void seive(){
	check[0]=1;
	int sqr = sqrt(mx);
	for(int i = 4;i<mx;i+=2)check[i]=1;
	for(int i = 3;i<=sqr;i+=2)
		if(!check[i])
			for(int j = i*i;j<mx;j+=2*i)
				check[j]=1;
	prime.push_back(2);
	for(int i = 3;i<mx;i+=2)if(!check[i])prime.push_back(i);
}
int main(){
	File_IO();
	seive();
	string line;
	while(cin>>line){
		int sum =0;
		for(int i  = 0;i<line.size();i++){
			sum+=line[i]-'0';
		}
		if(sum==0)return 0;
		int maxi = 0;
		for(int i = 0;i<line.size();i++){
			sum = 0;
			for(int j = i;j<line.size();j++){
				sum  =sum*10+ line[j]-48;
				debug(sum);
				if(sum>=100000)break;
				if(!check[sum])maxi = max(maxi,sum);
			}
		}
		cout<<maxi<<endl;
	}
	
}