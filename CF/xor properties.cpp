
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
int arr[32];
int main(){
	File_IO();
	int n ;
	cin>>n;
	//cout<<(1>>1)<<endl;
	int temp;
	int bit = 0;
	for(int i = 0;i<n;i++){
		cin>>temp;
		bit|=(1<<temp);
	}
	cout<<bit<<endl;
	while(bit){
	cout<<bit%2<<endl;		bit/=2;
	}
}