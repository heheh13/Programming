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
	bool isLeapYear(int year) {
		 if (year % 400 == 0) return true;
		 else if(year % 100 == 0) return false;
		 else if(year % 4 == 0) return true;
		 else return false;
	}
	int main(){
		File_IO();
		int t ;
		cin>>t;
		for(int ts = 1; ts<=t ;ts++) {
			printf("Case %d: ", ts);
			int d,m,y,q;
			cin>>d>>m>>y>>q;
			int cnt =0;
			if(d==29 && m==2){
				int n = 0;
				for(int i =y+4;i<=q;i+=4){
					if(isLeapYear(i))cnt++;
				}
				cout<<cnt<<endl;

			}
			else{
				cout<<q-y<<endl;
			}
		}
	}