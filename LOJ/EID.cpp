#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 46341
#define mod  1000000007
#define sc1(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d %d",&a,&b)
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
#define MAXN 100005
typedef long long ll;
int check[101];
void seieve(){
	int n = 100;
	int sqr = 10;
	for(int i = 4;i<=n;i+=2)check[i]++;
	for(int i = 3;i<=sqr;i+=2){
		if(!check[i]){
			for(int j = i+i;j<=n;j+=i)
				check[j]++;
		}
	}
	for(int i = 1;i<=100;i++)cout<<check[i]<<endl;
}
int main(){
	File_IO();
	seieve();
}