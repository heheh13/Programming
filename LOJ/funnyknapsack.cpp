#include<bits/stdc++.h>
#define mx 200000
using namespace std;
typedef long long ll;
ll fence [mx];
ll arr[mx],brr[mx];
std::vector<ll > v,vv;
ll w,n,pt,p;
void backtrack(ll pos,ll sum)
{
	if(sum>w) return ;
	if(pos==pt){
		v.push_back(sum);
		return;
	}
	backtrack(pos+1,sum+arr[pos]);
	backtrack(pos+1,sum);
}
void packtrack(ll pos,ll sum)
{
	if(sum>w) return ;
	if(pos==p){
		vv.push_back(sum);
		return;
	}
	packtrack(pos+1,sum+brr[pos]);
	packtrack(pos+1,sum);
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ll t;
	scanf("%lld",&t);
	for(ll ts =1 ;ts<=t;ts++){
		v.clear();
		vv.clear();
		//ll n,w;
		cin>>n>>w;
		pt = n/2;
		for(ll  i =0;i<pt;i++)
			scanf("%lld",&arr[i]);
		p = n-pt;
		for(ll i =0;i<p;i++)
			scanf("%lld",&brr[i]);
		//cout<<p<<endl;
		backtrack(0,0);
		packtrack(0,0);
		sort(vv.begin(),vv.end());

		ll ans =0;
		for(ll i =0;i<v.size();i++){
			ll x = upper_bound(vv.begin(),vv.end(),w-v[i])-vv.begin();
			ans+=x;
		}
		printf("Case %lld: %lld\n",ts,ans);

	}
}