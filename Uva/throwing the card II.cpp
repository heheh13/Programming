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
int main(){
	File_IO();
/*	for(int n = 2;n<=1000;n++){
		queue<int>q;

		for(int i = 1;i<=n;i++){
			q.push(i);
		}
		//cout<<q.size()<<endl;
		while(1){
			if(q.size()==1){
				cout<<q.front()<<" =  "<<n-1<<" "<<log2(n-1)<<endl;
				q.pop();
				break;
			}
			else{
				q.pop();
				q.push(q.front());
				q.pop();
			}
		}
	}*/
	ll n;
	while(cin>>n&&n){
		if(n==1){
			cout<<"1"<<endl;
			continue;
		}

		ll low = log2(n-1);
		//cout<<low<<endl;
		ll num = pow(2,low);
		//cout<<num<<endl;
		ll ans =2+((n-1)-num)*2;
		cout<<ans<<endl;
	}
}