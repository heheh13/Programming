#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 10005
#define inf 1e17
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
ll n,m;
priority_queue<ll>pq[mx];
priority_queue<pair<ll,ll> > mvp;
ll max_size(){
	ll maxi = 0;
	for(ll i = 2;i<=m;i++){
		maxi = max(maxi,(ll)pq[i].size());
	}
	if(maxi>0)
	for(ll i = 2;i<=m;i++)if(pq[i].size()==maxi)mvp.push({pq[i].top(),i});
	return maxi;
}
ll dp[mx][mx];
int s(){
	ll maxi=maxsize();
	if(maxi==0)return inf;
	ll help = mvp.top().first;
	mvp.pop();
	return help;
}
int f(){
	for(int i = 2;i<=m;i++){
		int val = 0
	}
	return min;
}
int call (int me, int st){
	if(me>st){
		return 0;
	}
	int a = f()+call(me+1,st);
	int b = s()+call(me+1,st-1);
}
int  main(){
	File_IO();
	
	cin>>n>>m;
	ll vote,cost;
	for(ll i = 0;i<n;i++){
		cin>>vote>>cost;
		pq[vote].push(-1*cost);
	}
	ll maxi = max_size();
	if(pq[1].size()>maxi){
		cout<<"0"<<endl;
		return 0;
	}
}