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
	int n,m;
	cin>>n>>m;
	std::vector<pair<int,int> > v;
	int a,b;
	for(int i  = 0;i<n;i++){
		cin>>a>>b;
		if(a>b)swap(a,b);
		v.push_back({a,b});
	}
	std::vector<int > num;
	for(int i = 1;i<=m;i++){
		bool flag = true;
		for(int j =0;j<n;j++){
			if(i>=v[j].first && i<=v[j].second){
				flag = false;
				break;
			}
		}
		if(flag)num.push_back(i);
	}
	cout<<num.size()<<endl;
	for(auto x: num)cout<<x<<" ";
}