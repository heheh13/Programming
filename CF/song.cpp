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
bool cmp(pair<ll ,ll > &a, pair<ll ,ll > &b){
	ll  x = a.first-a.second;
	ll  y = b.first-b.second;
	return x<y;
}
int  main(){
	File_IO();
	optimizar;
	ll  n,m;
	cin>>n>>m;
	std::vector<pair<ll ,ll > > v;
	ll  a ,b;
	ll  sum = 0;
	for(ll  i =0;i<n;i++){
		cin>>a>>b;
		sum+=b;
		v.push_back({a,b});
	}
	if(sum>m){
		cout<<"-1"<<endl;
		return 0;
	}
	sort(v.rbegin(),v.rend(),cmp);
	priority_queue<ll >s;
	sum = 0;
	ll  cnt = 0;
	for(auto x:v){
		//dbg(x.first,x.second);
		if(sum+x.first<=m){
			sum+=x.first;
			s.push((x.first-x.second));
		}
		else{
			s.push((x.first-x.second));
			while(sum+x.first>=m){
				cnt++;
				//debug(s.top());
				sum-=-s.top();
				s.pop();
			}
			sum+=x.first;
		}
	}
	cout<<cnt<<endl;
	
}