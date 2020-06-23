#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 200005
#define mod  6
#define inf 1e9
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
std::vector<int > prime;
int s,t;
int dp[mx];
bool found;
int steps;
int dfs(int num){
	if(!found && steps>100000){
		return inf;
	}
	steps++;
	if (num == t){
		found = true;
		return 0;
	} 
	if(num>t)return inf;
	if(dp[num]!=inf)return dp[num];
	std::vector<int> factor;
	int temp = num;
	for(int i = 0;prime[i]*prime[i]<=temp;i++){
		if(temp % prime[i] == 0){
			while(temp % prime[i] == 0){
				temp/=prime[i];
			}
			factor.push_back(prime[i]);
		}
	}
	if(temp!=1)factor.push_back(temp);
	if((factor.size()>0) && factor[factor.size()-1]==num) factor.pop_back();
	int ans = inf;
	for(int i = 0;i<factor.size();i++){
		ans = min(ans,dfs(num+factor[i])+1);
	}
	return dp[num]=min(dp[num],ans);
}
int main(){
	optimizar;
	File_IO();
	for(int i = 2;i<9000;i++){
		bool flag =true;
		for(int j = 2;j*j<=i;j++){
			if(i%j==0){
				flag = false;
				break;
			}
		}
		if(flag)prime.push_back(i);
	}
	int tc ;
	cin>>tc;
	for(int ts = 1;ts<=tc;ts++){
		cin>>s>>t;
		for(int i  =0;i<mx;i++)dp[i]=inf;
		found = false;
		steps = 0;
		int ans = dfs(s);
		cout<<"Case "<<ts<<": ";
		if(ans <inf)cout<<ans<<endl;
		else cout<<"-1"<<endl;
	}
}