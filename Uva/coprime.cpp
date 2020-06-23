#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 1000006
#define mod  1000000007
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int gcd[101][101];
void gcd_gen(){
	for(int i = 1;i<=100;i++){
		for(int j = 1;j<=100;j++){
			gcd[i][j] = __gcd(i,j);
		}
	}
}
int arr[100];
void bt(int n , int m,int prev ,int pos, int sum){
	if(sum>n)return ;
	if(pos>=m){
		 if(sum ==n ){
			printf("%d",arr[0]);
			for(int i  = 1;i<m;i++)printf(" %d",arr[i] );
				printf("\n");
		}
		return ;
	}
	for(int i = prev;i<=n-m+1;i++){
		arr[pos]=i;
		bool flag = true;
		for(int j =0;j<=pos-1;j++){
			if(gcd[arr[pos]][arr[j]]!=1){
				flag = false;
				break;
			}
		}
		if(flag)
		bt(n,m,i,pos+1,sum+i);
	}
}
int  main(){
	File_IO();
	gcd_gen();
	int n,m;
	int t;
	scanf("%d",&t);
	for(int ts = 1;ts<=t;ts++){
		scanf("%d %d",&n,&m);
		printf("Case %d:\n",ts);
		bt(n,m,1,0,0);	
	}
}