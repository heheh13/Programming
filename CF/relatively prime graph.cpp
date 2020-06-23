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
int main(){
	File_IO();
	optimizar;
	int n,m;
	cin>>n>>m;
	if(n-1>m){
		cout<<"Impossible"<<endl;
		return 0;
	}
	int cnt = 0;
	std::vector<pair<int,int> > v;
	for(int j = 1;j<=n;j++){
		for(int k = j+1;k<=n;k++){
			if(__gcd(j,k)==1){
				//dbg(j,k);
				v.push_back({j,k});cnt++;
			}
			if(cnt == m){
				cout<<"Possible"<<endl;
				for(auto x:v)cout<<x.first<<" "<<x.second<<endl;
				return 0;
			}
		}
	}
	cout<<"Impossible"<<endl;
}