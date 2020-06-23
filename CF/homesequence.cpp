#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 100000
#define mod  6
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
int main(){
	File_IO();
	ll n,k,s;
	cin>>n>>k>>s;	
	ll have = (s+k-1)/k;
	//debug(have);
	if(n<=have || s<k){
		cout<<"NO"<<endl;
		return 0;
	}
	have=s/k;
	cout<<"YES"<<endl;
	ll current = 1;
	ll rem = s - have*k;
	ll hv = have,ev=have+1;
	//if(rem)have++,rem--;
	ll next ;
	for(int i = 0;i<k;i++){
		if(rem<=0){
			have=hv;
		}
		else{
			have = ev;
			rem--;
		}
		if(i&1){
			//dbg(next,have);
			current = next-have;
			cout<<current<<" ";
		}
		else{
			next = current+have;
			cout<<next<<" ";
		}
	}
}