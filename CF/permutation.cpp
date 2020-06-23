			#include<bits/stdc++.h>
			#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
			#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
			#define debug(x) cout<< #x<<" = "<<x<<endl;
			#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
			#define mx 100000
			#define mod  6
			void File_IO () {
			  #ifndef ONLINE_JUDGE 
			  read();write();
			  #endif
			}
			using namespace std;
			typedef long long ll;
			int  main(){
				File_IO();
				ll n,d;
				cin>>n>>d;
				ll arr[n+2];
				map<ll,ll>val;
				for(ll i = 1;i<=n;i++){
					cin>>arr[i];
					val[arr[i]]=1;
				}
				map<ll,ll>mp;
				arr[0]=-1e15;
				arr[n+1]=1e15;
				for(ll i = 1;i<=n;i++){
					ll a= arr[i]+d;
					ll b = arr[i]-d;
					if(a+d<=arr[i+1])mp[a]=1;
					if(b-d>=arr[i-1])mp[b]=1;
				}
				ll cnt  = 0;
				for(auto x:mp){
					if(val[x.first])cnt++;

				}
				cout<<mp.size()-cnt<<endl;

			}