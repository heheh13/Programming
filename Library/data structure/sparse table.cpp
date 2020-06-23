#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 100001000
#define mod  1000
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
#define MAXN 100005


int sp[MAXN][25];
int n,k;
int arr[MAXN];
int f ( int a , int b){
	//return a+b;
	return max(a,b);
}
void sparse_table(){
	k = log2(n)+1;
	for(int i = 0;i<n;i++)sp[i][0]=arr[i];

	for(int j = 1;j<=k;j++){
		int lim = 1<<j;
		for(int i = 0; i+lim <= n; i++){
			int temp = 1<<(j-1);
			sp[i][j] = max(sp[i][j-1], sp[i+temp][j-1]);
		}
	}
}
int sum_query(int L , int R){
	int sum = 0;
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
int main(){
	File_IO();
	//double c1 = clock();
	scanf("%d",&n);
	int q;
	scanf("%d",&q);
	for(int i = 0;i<n;i++)scanf("%d",&arr[i]);
	sparse_table();
	int cnt = 0;
	while(q--){
		int a,b;
		scanf("%d %d",&a,&b);
		a--,b--;
		int height = arr[a];
		if(a>b)swap(a,b);
		//dbg(a,b);
		if(a==b){
			cnt++;continue;
		}
		int temp = minimum_query(a,b-1);
		//cout<<temp<<endl;
		if(temp<=height) cnt++;
	}
	printf("%d\n",cnt );

	//double c2 = clock();
	//printf("%.10lf\n",(c2-c1)/CLOCKS_PER_SEC);
	string line = "leaf";
        sort(line.begin(),line.end());
        do{
        	cout<<line<<endl;
        }while(next_permutation(line.begin(),line.end()));
}
