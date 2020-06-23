#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 200005
#define mod  6
#define ff first
#define ss second
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
std::vector<pair<int,int> > v;
bool cmp(const pair<int,int> a, const pair<int,int> b){
	if(a.ff== b.ff){
		return a.ss>b.ss;
	}
	return a.ff<b.ff;
}
int  main(){
	File_IO();
	int t;
	cin>>t;
	bool first = false;
	while(t--){
		v.clear();
		if(first)cout<<endl;
		first = true;
		int m;
		cin>>m;
		int a,b;
		while(cin>>a>>b){
			if(a==0 && b==0)break;
			if(b<0)continue;
			v.push_back({a,b});
		}
		sort(v.begin(),v.end(),cmp);
		// for(auto x:v)cout<<x.ff<<" "<<x.ss<<endl;
		int cover = 0;
	    int pos = 0;
	    pair<int,int> now;
	    std::vector<pair<int,int> >ans;
		while(cover<m){
			now.ff=0;
			now.ss=0;
			while(v[pos].ff<=cover&&pos<v.size()){
				// dbg(v[pos].ff,v[pos].ss);
				if(v[pos].ss>now.ss){
					now.ss = v[pos].ss;
					now.ff = v[pos].ff;
				}
				pos++;
			}
			if(now.ss+1 == cover){
				break;
			}
			cover=now.ss+1;
			ans.push_back({now.ff,now.ss});
		}
		if(cover>=m){
			cout<<ans.size()<<endl;
			for(auto x:ans)cout<<x.ff<<" "<<x.ss<<endl;
		}
		else cout<<"0"<<endl;
	}
}