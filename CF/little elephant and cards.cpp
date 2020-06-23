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
map<int,int>mp;
std::vector<int> can;
int main(){
	File_IO();
	int n,a,b;
	scanf("%d",&n);
	std::vector<pair<int,int> > v;
	for(int i = 0;i<n;i++){
		scanf("%d%d",&a,&b);
		v.push_back({a,b});
		mp[a]++;
		mp[b]++;
	}
	int t = (n+1)/2;
	for(auto x:mp) if(x.second>=t) can.push_back(x.first);
	int move,dove,mini=1e9;
	for(int i = 0;i<can.size();i++){
		move=0;
		dove=0;
		//debug(can[i]);
		int ordered =0;
		for(int j = 0;j<v.size();j++){
			
			if(v[j].first==can[i]){
				ordered++;
				continue;
			}
			if(v[j].second==can[i])move++;
		}
		//dbg(t,ordered);
		int need = t-ordered;
		if(need>move){
			continue;
		}
		if(need<0)need=0;
		mini = min(mini,need);
	}
	if(mini<1e9)
		printf("%d\n",mini);
	else printf("-1\n");

}