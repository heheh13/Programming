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
				sp[i][j] = max(sp[i][j-1], sp[i+temp][j-1]);
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
		return max(sp[L][need], sp[R-(1<<need)+1][need]);
	}
	
}tables[5];
int  current_state[5];
bool valid (int L, int R, int m,int k ){
	int sum = 0;
	for(int i = 0;i<m;i++){
		current_state[i] = tables[i].minimum_query(L,R);
		sum+=current_state[i];
	}
	return (sum<=k);
}
int main(){
	File_IO();
	int  n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	int arr[5][n];
	for(int i = 0;i<n;i++){
		int temp;
		for(int j = 0;j<m;j++){
			scanf("%d",&temp);
			arr[j][i]=temp;
		}
	}
	for(int i = 0;i<m;i++)tables[i].build(n,arr[i]);
	int need[5];
	memset(need,0,sizeof(need));
	int now[5];
	memset(now,0,sizeof(now));
	int ans = 0,help = 0;
	for(int i = 0;i<n;i++){
		int low = 1, high = n-i;
		int mid ;
		while(low<=high){
			mid = (high+low)/2;
			if(valid(i,i+mid-1,m,k)){
				///save current state
				help = mid;
				for(int j = 0;j<m;j++)now[j]=current_state[j];
				low = mid+1;
			}
			else{
				high = mid-1;
			}
		}
		if(help>ans){
			ans = help;
			for(int j = 0;j<m;j++)need[j]=now[j];
		}
	}
	for(int i = 0;i<m;i++)printf("%d ", need[i]);
}