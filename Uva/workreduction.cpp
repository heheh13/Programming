#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 200005
#define mod  6
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
struct agency
{
	string name;
	int cost;
	
}xp[105];
bool cmp (struct agency a, struct agency b){
	if(a.cost==b.cost){
		return a.name<b.name;
	}
	return a.cost<b.cost;
}

int calc(int a,int b,int n,int m){
	int ans = 0;
	int c1,c2;
	int havetoreduce = n-m;
	int now = 0;
	while(1){
		dbg(now,n);
		if(now==havetoreduce)break;
		c1 = ((n-1)/2)*a;
		c2 = b;
		if((now + (n-1)/2)<havetoreduce){			
			ans+=min(c1,c2);
			now += (n-1)/2;
			n=(n+1)/2;
		}
		else{
			ans += (havetoreduce-now)*a;
			now += (havetoreduce-now);
			n -= (havetoreduce-now);
		} 
		
	}
	return ans;
}
int  main(){
	//optimizar;
	File_IO();
	int t;
	cin>>t;
	for(int ts = 1;ts<=t;ts++){
		int n,m,L;
		
		cin>>n>>m>>L;
		for(int i = 0;i<L;i++){
			string line;
			char ch;
			getchar();
			while(ch=getchar()){
				if(ch == ':')
					break;
				line+=ch;
			}
			int a,b;
			cin>>a>>ch>>b;
			xp[i].name = line;
			xp[i].cost=calc(a,b,n,m);
		}
		sort(xp,xp+L,cmp);
		cout<<"Case "<<ts<<endl;
		for(int i = 0;i<L;i++)
			cout<< xp[i].name<<" "<<xp[i].cost<<endl;
	}
}