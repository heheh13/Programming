#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 1000006
#define mod  1000000007
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
	int j,k;
	string line;
	int ts = 1;
	while(cin>>j){
		if(j==-1)return 0;
		cin>>line;
		double num =0;
		for(int i = 2;i<line.size();i++){
			num = num*10 + line[i]-48;
		}
		k = line.size()-2 - j;
		//cout<<k<<endl;
		//cout<<num<<endl;
		ll repeat = 0;
		for(int i = k+2;i<line.size();i++){
			repeat = repeat* 10 + line[i]-'0';
		}
		num/=pow(10,k+j);
		//cout<<num<<endl;
		ll dom = pow(10,k+j)-pow(10,k);
		if(dom==0)dom =pow(10,k+j) ;
		//cout<<dom<<endl;
		ll low = dom * num;
		ll high = dom *(num + (1.00/pow(10,k+j))); 
		//cout<<low<<" "<<high<<endl;
		//cout<<dom<<endl;
		double eps = 10000;
		ll v1,v2;
		for (ll i = low ;i<=high;i++){
			ll x = __gcd(i,dom);
			ll num1 = i/x;
			ll num2 = dom/x;
			//dbg(num2,num1);
			double temp = (1.00*num1)/(1.00*num2);
			double hex = abs(num-temp);
			//cout<<temp<<endl;
			if(hex<eps){
				v1 = num1;
				v2 = num2;
				eps = hex;
			}
			
		}
		cout<<"Case "<<ts++<<": ";
		cout<<v1<<"/"<<v2<<endl;
	}

		
}
