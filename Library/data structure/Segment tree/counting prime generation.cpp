#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define dbg1(x) cout<< #x<<" = "<<x<<endl;
#define dbg2(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<" "<<#z <<" = "<<z<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 104
#define mod  100000007
#define sc1(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d %d",&a,&b)
void File_IO () {
  #ifndef ONLINE_JUDGE
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
int main(){
	File_IO();
	srand(time(NULL));
	int t = 100;
	cout<<t<<endl;
	for(int ts = 1;ts<=t;ts++){
		int n = 1+rand()%10;
		int q = 1+rand()%10;
		cout<<n<<" "<<q<<endl;
		for(int i = 0;i<n;i++){
			cout<<1+rand()%mx<<" ";
		}
		cout<<endl;
		while(q--){
			int type  = rand()%2;
			if(type==1){
				int a = 1+rand()%n;
				int b = 1+rand()%n;
				if(a>b)swap(a,b);
				cout<<type<<" "<<a<<" "<<b<<endl;
			}
			else{
				int a = 1+rand()%n;
				int b = 1+rand()%n;
				if(a>b)swap(a,b);
				int val = 2+rand()%mx;
				cout<<"0 "<<a<<" "<<b<<" "<<val<<endl;
			}
		}
	}
}