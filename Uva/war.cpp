#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define dbg1(x) cout<< #x<<" = "<<x<<endl;
#define dbg2(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<" "<<#z <<" = "<<z<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 10005
#define mod  100000007
#define sci(a) scanf("%d",&a)
#define scii(a,b) scanf("%d %d",&a,&b)
#define sciii(a,b,c) scanf("%d %d %d",&a,&b,&c)
void File_IO () {
  #ifndef ONLINE_JUDGE
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
int par[mx];
std::set<int> lists[mx];
int find_par(int n){
	if(par[n]==n)return n;
	return par[n]=find_par(par[n]);
}

bool enemy(int a,int b){
	int x = find_par(a);
	int y= find_par(b);
	if(x == y)return false;
	for(auto xt :lists[x])if(find_par(xt)== y)return true;
	return false; 
}
void set_freind(int a,int b){
	int x = find_par(a);
	int y = find_par(b);
	if(x!=y){
		if(rand()%2)swap(x,y);
		for(auto xx:lists[x])lists[y].insert(find_par(xx));
		par[x]=y;
	}
}
bool friends(int a, int b){
	int x = find_par(a);
	int y = find_par(b);
	if(x==y) return true;
	return false;
}
void set_enemey(int a,int b){
	int x= find_par(a);
	int y = find_par(b);
	if(x==y)return ;
	//dbg2(x,y);
	lists[x].insert(b);
	lists[x].insert(find_par(b));
	lists[y].insert(a);
	lists[y].insert(find_par(a));
	for(auto xx:lists[y])set_freind(x,xx);
	for(auto xx:lists[x])set_freind(y,xx);
}
int main(){
	File_IO();
	///double t1 = clock();
	int n;
	//srand(5);
	sci(n);
	for(int i = 0;i<=n;i++)par[i]=i;
	int a,b,c;
	while(sciii(c,a,b)&&a+b+c){
		if(c==1){
			if(!enemy(a,b))set_freind(a,b);
			else printf("-1\n");
		}
		else if(c==2){
			if(!friends(a,b))set_enemey(a,b);
			else printf("-1\n");
		}
		else if(c == 3){
			if(friends(a,b)){
				printf("1\n");
			}
			else printf("0\n");
		}
		else {
			if(enemy(a,b))printf("1\n");
			else printf("0\n");
		}
	}
	// for(auto x:lists[find_par(42)]){
	// 	cout<<x<<endl;
	// // }
	// double t2 = clock();
	// cout<<(t2-t1)/CLOCKS_PER_SEC<<endl;
}