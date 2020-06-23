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
int arr[27];
int main(){
	File_IO();
	int n;
	cin>>n;
	int a[n],b[n];
	for(int i =0;i<n;i++)cin>>a[i];
	for(int j=0;j<n;j++)cin>>b[j];
	sort(a,a+n);
	sort(b,b+n);
	stack<int>ax,bx;
	for(auto x:a)ax.push(x);
	for(auto x:b)bx.push(x);
	ll suma=0,sumb=0;
    bool turn =true;
	while(1){
		//debug(turn);
		int t1=-1,t2=-1;
		if(ax.empty()&&bx.empty()){
			//cout<<suma<<sumb<<endl;
			cout<<suma-sumb<<endl;
			return 0;
		}
		if(!ax.empty())t1=ax.top();
		if(!bx.empty())t2=bx.top();
		//dbg(t1,t2);
		if(turn){
			if(t1>t2){
				suma+=t1;
				ax.pop();
			}
			else{
				bx.pop();
			}
			//turn = false;
		}
		else{
			if(t2>t1){
				sumb+=t2;
				bx.pop();
			}
			else{
				ax.pop();
			}
			//turn = true;
		}
		turn=!turn;
		//debug(turn);
	}
}