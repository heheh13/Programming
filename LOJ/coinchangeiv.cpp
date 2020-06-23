#include<bits/stdc++.h>
#define mx 200000
using namespace std;
typedef long long ll;
std::vector<ll> arr,brr;
std::vector<ll > v,vv;
//unordered_map<ll,bool> m;
map<long long ,bool>m;
ll k,n,pt,p;
void backtrack(ll pos,ll sum)
{
	//cout<<sum<<" "<<pos<<" "<<arr[pos]<<endl;
	if(sum>k) return ;
	if(pos==arr.size()){
		v.push_back(sum);
		return;
	}
	backtrack(pos+1,sum+arr[pos]);
	backtrack(pos+1,sum+2*arr[pos]);
	backtrack(pos+1,sum);
}
void packtrack(ll pos,ll sum)
{
	if(sum>k) return ;
	if(pos==brr.size()){
		m[sum]=1;
		//vv.push_back(sum);
		return;
	}
	packtrack(pos+1,sum+brr[pos]);
	packtrack(pos+1,sum+2*brr[pos]);
	packtrack(pos+1,sum);
}
int main()  
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ll t;
	scanf("%lld",&t);
	for(ll ts =1;ts<=t;ts++){
		arr.clear();
		brr.clear();
		v.clear();
		m.clear();
		//ll n,k;
		scanf("%lld%lld",&n,&k);
		ll temp;
		for(ll i =0;i<n/2;i++)
		{
			scanf("%lld",&temp);
			arr.push_back(temp);
			//arr.push_back(temp);
		}
		for(ll i =0;i<n-n/2;i++){
			scanf("%lld",&temp);
			brr.push_back(temp);
			//brr.push_back(temp);
		}
		backtrack(0,0);
		packtrack(0,0);
	/*	for(int i =0;i<v.size();i++)
			cout<<v[i]<<" ";
		cout<<endl;
		for(int i =0;i<vv.size();i++)
			cout<<vv[i]<<" ";*/
		bool flag = true;
		for(int i =0;i<v.size();i++){
			if(m[k-v[i]]){
				flag  = false;
				break; 
			}
		}
		if(flag)
			printf("Case %lld: No\n",ts);
		else 
		printf("Case %lld: Yes\n",ts );

	}
}