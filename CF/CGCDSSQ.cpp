#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 100001000
#define mod  1000
#define MAXN 100005
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
struct  Sparse_Table
{
	int sp[MAXN][25];
	////int n,k;
	int arr[MAXN];
	void build (int n,int arr[]){
		int k = log2(n)+1;
		for(int i = 0;i<n;i++)sp[i][0]=arr[i];

		for(int j = 1;j<=k;j++){
			int lim = 1<<j;
			for(int i = 0; i+lim <= n; i++){
				int temp = 1<<(j-1);
				sp[i][j] = __gcd(sp[i][j-1], sp[i+temp][j-1]);
			}
		}
	}
	int sum_query(int L , int R,int n){
		int sum = 0,k = log2(n);
		for(int j  = k;j>=0;j--){
			if((1<<j)<=R-L+1){
				sum+=sp[L][j];
				L += (1<<j);
			}
		}
		return sum;
	}
	int minimum_query(int L , int R){
		int need = log2(R-L+1);
		return __gcd(sp[L][need], sp[R-(1<<need)+1][need]);
	}
	
}table;
std::map<int , ll> mp;
int main(){
	File_IO();
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i = 0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	table.build(n,arr);
	for(int i = 0;i<n;i++){
		int L = i;
		while(L<n){
			int now=0;
			int g = table.minimum_query(i,L);
			int low , high, mid;
			low = 1 , high = n-L;
			while(low<=high){
				mid = (high+low)/2;
				if(g == table.minimum_query(i,L+mid-1)){
					now = mid;
					low = mid+1;
				}
				else{
					high = mid-1;
				}
			}
			mp[g]+=now;
			if(now == 0)L+=1;
			else L+=now;
			
		}
	}
	//for(auto x:mp)cout<<x.first<<" "<<x.second<<endl;
	int q,x;
	scanf("%d",&q);
	while(q--){
		scanf("%d",&x);
		printf("%lld\n",mp[x]);
	}
}