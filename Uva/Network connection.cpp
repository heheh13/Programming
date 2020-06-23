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
int par[mx];
void make_set(int n){
	par[n]=n;
}
int find_set(int n){
	if(par[n]==n)return n;
	return par[n]=find_set(par[n]);
}
void union_set(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if(a!=b){
		if(rand()%2)swap(a,b);
		par[b]=a;
	}
}

int main(){
	File_IO();
	int t;
	scanf("%d ",&t);
	bool first = false;
	///for(int ts = 1;ts<=t;ts++){
		int n;
		char str[100],ch;
		int a,b;
		int s= 0,us=0;
		while(gets(str)){
			if(str[0]=='\0')continue;
			///puts(str);
			if(str[0]=='c'||str[0]=='q')sscanf(str,"%c %d %d",&ch,&a,&b);
			else{
				if(first)printf("%d,%d\n\n",s,us ) , s= 0, us = 0;
				first = true;
				sscanf(str,"%d",&n);
				for(int i = 0;i<=n;i++)make_set(i);
			}
			if(str[0]=='c')union_set(a,b);
			if(str[0]=='q'){
				if(find_set(a)==find_set(b))s++;
				else us++;
			}
		}
		printf("%d,%d\n",s,us);
	//}
}