#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 100000
#define mod  6
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
std::vector<int> prime;
std::vector<int> v;
void bt(int pos, int sum,int cnt)
{
	if(pos>=prime.size()){
		if(sum==0){
			for(auto x:v)cout<<x<<" ";
				cout<<endl;
		}
		//v.clear();
		return ;
	}
	if(cnt==0&& sum==0){
		for(auto x:v)cout<<x<<" ";
			cout<<endl;
		//v.clear();
		return ;
	}
	if(cnt<0 || sum<0){
		//v.clear();
		return ;
	}
	bt(pos+1,sum,cnt);
	if(sum-prime[pos]>=0){
		v.push_back(prime[pos]);
		bt(pos+1,sum-prime[pos],cnt-1);
		
	}
}
int main(){
	File_IO();
	for(int i = 2;i<24;i++){
		bool flag=true;
		for(int j = 2;j<=sqrt(i);j++)
		{
			if(i%j==0){
				flag =false;break;
			}
		}
		if(flag)prime.push_back(i);
	}
	int num, cnt;
	std::vector<int> v;
	while(cin>>num>>cnt){
		bt(0,24,3);
	}
	
}
