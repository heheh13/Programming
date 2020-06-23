#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 10005
#define mod  6
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
map<int,int>mp;
bool cmp(pair<int,int> &a, pair<int,int> &b){
	if(a.first==b.first)return a.second<b.second;
	return a.first>b.first;
}
int main(){
	File_IO();
	int n;
	cin>>n;
	int seg = sqrt(n);
	std::vector<int > v[mx];
	int cnt =0;
	int x=0;
	for(int i = 1;i<=n;i++){
		cnt++;
		v[x].push_back(i);
		if(cnt == seg){
			cnt=0;
			x++;
		}
	}
	for(int i = 0;i<=seg+1;i++){
		for(int j = v[i].size()-1;j>=0;j--)cout<<v[i][j]<<" ";
			//cout<<endl;
	}
}