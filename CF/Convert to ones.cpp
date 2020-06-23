
#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define mx 100000
#define mod  6
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
int  main(){
	File_IO();
	ll n,x,y;
	cin>>n>>x>>y;
	string line;
	char temp;
	cin>>temp;
	line+=temp;
	for(ll i =1;i<n;i++){
		cin>>temp;
		if(line.back()==temp)continue;
		else line+=temp;
	}
	///cout<<line<<endl;
	ll one=0 ,zero=0;
	for(ll i = 0;i<line.size();i++){
		if(line[i]=='0')zero ++;
		else{
			one++;
		}
	}
	if(line[0]=='1')one--;
	if(line[line.size()-1]=='1')one--;
	ll ans =0;
	ans =min((zero*y),(one*x + y));
	cout<<max(0ll,ans)<<endl;
}