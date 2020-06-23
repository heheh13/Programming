#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 1100
#define mod  1000000007
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
bool check[mx];
std::vector<int> prime;
int par[mx];
int find_set(int n){
	if(par[n]==n)return n;
	return par[n]=find_set(par[n]);
}
// void union_set(int a, int b){
// 	dbg(a,b);
// 	a = find_set(a);
// 	cout<<a<<endl;
// 	par[a]=b;
// }
void seive(){
	for(int i = 3;i*i<=mx;i+=2){
		if(!check[i]){
			for(int j = i*i; j<mx;j+=2*i){
				check[j]=1;
			}
		}
	}
	prime.push_back(2);
	for(int i = 3;i<mx;i+=2) if(! check[i ]) prime.push_back(i);
}
std::map<int, int> mp;
int main(){
	File_IO();
	seive();
	int t;
	scanf("%d",&t);
	for(int ts = 1; ts<= t; ts++){
		int n,temp;
		scanf("%d",&n);
		std::vector<int> v;
		int one = 0;
		for(int i = 0;i<n;i++){
			scanf("%d",&temp);
			if(temp==1){
				one++;
				continue;
			}
			v.push_back(temp);
		}
		
		memset(par,0,sizeof(par));
		for(int i = 0;i<10;i++){
			for(int j = 0;j<v.size();j++){
				if(v[j]%prime[i]==0 ){
					par[prime[i]] = prime[i];
					if(par[v[j]]){
						int x = find_set(v[j]);
						//cout<<x<<" "<<v[j]<<prime[i]<<endl;
						par[find_set(v[j])] =prime[i];
					}
					else par[v[j]]=prime[i];

				}
				//cout<<par[v[j]]<<" ";
			}
			//cout<<endl;
		}
		mp.clear();
		// for(int i = 0;i<n;i++){
		//   	dbg(prime[i],par[prime[i]]);
		//  }
		for(int i = 0;i<prime.size();i++){
			if(par[prime[i]]){
				int x = find_set(par[prime[i]]);
				mp[x]++;
				par[i]=0;
			}
		}
		printf("Case %d: %d\n",ts,mp.size());
	}

}