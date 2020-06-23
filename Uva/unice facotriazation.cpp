#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 200005
#define mod  6
void File_IO () {
  #ifndef ONLINE_JUDGE
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int value[mx];
std::vector<int> divs;
std::vector<int > ans[mx];
int track;
void dfs(int pos,int n,int i){
	//debug(n);
	if(n==1){
		for(int j = 0;j<pos;j++){
			ans[track].push_back(value[j]);
		}
		track++;
		return ;
	}
	for(;i<divs.size();i++){
		if(n%divs[i]==0){
			value[pos]=divs[i];
			dfs(pos+1,n/divs[i],i);

		}
	}
}
int main(){
	optimizar;
	File_IO();
	int n;
	while(cin>>n&&n){
		divs.clear();
		for(int i = 0;i<mx;i++)ans[i].clear();
		for(int i = 2;i*i<=n;i++){
			if(n%i==0){
				if(n/i==i)divs.push_back(i);
				else{
					divs.push_back(i);
					divs.push_back(n/i);
				}
			}
		}
		sort(divs.begin(),divs.end());
		track = 0;
		dfs(0,n,0);
		if(n==1)track=0;
		cout<<track<<endl;
		for(int i = 0;i<track;i++){
			cout<<ans[i][0];
			for(int j = 1;j<ans[i].size();j++){
				cout<<" "<<ans[i][j];
			}
			cout<<endl;
		}
	}
}
