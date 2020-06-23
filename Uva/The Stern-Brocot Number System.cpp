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
ll  a,b;
void build(ll l1,ll l2, ll r1,ll r2){
	ll  root1 = l1+r1;
	ll  root2 = l2 + r2;
	ll temp = (root1*1000000000)/root2;
	ll res = (a*1000000000)/b;
	//dbg(temp,res);
	if(res == temp){
		return ;
	}
	if(temp >res){
		cout<<"L";
		build(l1,l2,root1,root2);
	}
	else {
		cout<<"R";
		build(root1,root2,r1,r2);
	}
}
int  main(){
	File_IO();
	while(cin>>a>>b){
		if(a==1&& b==1)return 0;

		build(0,1,1,0);
		cout<<endl;
	}
}