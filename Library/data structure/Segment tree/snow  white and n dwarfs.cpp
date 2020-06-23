#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define dbg1(x) cout<< #x<<" = "<<x<<endl;
#define dbg2(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<" "<<#z <<" = "<<z<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define maxn 100005
#define mx 300005
#define mod  1000000007
#define sc1(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d %d",&a,&b)
void File_IO () {
  #ifndef ONLINE_JUDGE
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
int arr[mx];
std::vector<int> v[maxn];
void randomized(int a, int b){
	srand(time(NULL));
	for(int i = 1;i<=30;i++){
		int pick = a+rand()%(b-a+1);
		int val = arr[pick];
		int up = upper_bound(v[val].begin(),v[val].end(),b)-v[val].begin();
		int low = lower_bound(v[val].begin(),v[val].end(),a)-v[val].begin();
		if(up - low > (b-a+1)/2){
			printf("yes %d\n",val);
			return ;
		}
	}
	printf("no\n");
	return ;
}
int main(){
	File_IO();
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i  = 1;i<=n;i++)scanf("%d",&arr[i]),v[arr[i]].push_back(i);
	int q;
	scanf("%d",&q);
	int a, b;
	while(q--){
		scanf("%d %d",&a,&b);
		randomized(a,b);
	}
}