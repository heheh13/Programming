#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define dbg1(x) cout<< #x<<" = "<<x<<endl;
#define dbg2(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<" "<<#z <<" = "<<z<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 1004
#define mod  100000007
#define sc1(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d %d",&a,&b)
void File_IO () {
  #ifndef ONLINE_JUDGE
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
#define maxn 1000000
int arr[mx],tree[4*mx],lazy[4*mx];
bitset<maxn> check;
void seive(){
	check[1]=1;
	int sqr = sqrt(maxn);
	for(int  i = 4;i<maxn;i+=2)check[i]=1;
	for(int i = 3;i<=sqr;i+=2){
		if(!check[i]){
			for(int j = i*i ;j<maxn;j+=2*i){
				check[j]=1;
			}
		}
	}
}
int main(){
	File_IO();
	seive();
	int t;
	cin>>t;
	for(int ts = 1;ts<=t;ts++){
		printf("Case %d:\n",ts);
		int n,q;
		cin>>n>>q;
		//dbg2(n,q);
		for(int i = 1;i<=n;i++)cin>>arr[i];
		while(q--){
			int type,a,b,val;
			cin>>type;
			if(type==1){
				cin>>a>>b;
				int cnt = 0;
				for(int i = a;i<=b;i++){
					if(!check[arr[i]])cnt++;
				}
				cout<<cnt<<endl;
			}
			else{
				cin>>a>>b>>val;
				for(int i = a;i<=b;i++){
					arr[i]=val;
				}
			}
		}
	}
}
