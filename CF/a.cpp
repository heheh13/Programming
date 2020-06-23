
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
int main(){
	File_IO();
	int a,b,x;
	cin>>a>>b>>x;
	int last = a>b?0:1;
	string line;
	while(x--){
		//dbg(x,last);
		line+='0'+last;
		if(last)b--;
		else a--;
		last=!last;
	}
	//cout<<line<<endl;
	if(!last){
		while(b--)line+="1";
		while(a--)line+="0";
	}
	else{
		while(a--)line+="0";
		while(b--)line+="1";
	}
	cout<<line<<endl;
}


