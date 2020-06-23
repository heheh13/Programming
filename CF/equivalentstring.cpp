#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define dbg(x) cout<< #x<<" = "<<x<<endl;
#define debug(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 10005
#define mod  6
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
struct stringhash
{
	string line;
	std::vector<ull> hash,revhash,base;
	void make_hash(){
		hash.resize(line.size()+5);
		revhash.resize(line.size()+5);
		base.resize(line.size()+5);
		hash[0]=0,revhash[0]=0,base[0]=1;
		for(int i = 1;i<=line.size();i++){
			hash[i]=hash[i-1]*99571+line[i-1];
			base[i]=base[i-1]*99571;
		}
		for(int i = line.size();i>=1;i--){
			revhash[i]=revhash[i+1]*99571+line[i-1];
		}
	}
	ull get_hash(){
		return hash[line.size()];
	}
	ull get_hash(int i , int j){
		return hash[j]-hash[i-1]*base[j-i+1];
	}
	ull get_revhash(int i , int j ){
		return revhash[i]-revhash[j+1]*base[j-i+1];
	}
	
};
stringhash a1,a2,b1,b2;
int main(){
	File_IO();
	string x,y;
	cin>>x>>y;
	if(x==y){
		cout<<"YES"<<endl;
		return 0;
	}
	if(x.size()&1){
		cout<<"NO"<<endl;
		return 0;
	}
	int n = x.size();
	for(int i = 0;i<n/2;i++)a1.line+=x[i];
	for(int i = n/2;i<n;i++)a2.line+=x[i];
	for(int i = 0;i<n/2;i++)b1.line+=y[i];
	for(int i =n/2;i<n;i++)b2.line+=y[i];

	sort(a1.line.begin(),a1.line.end());
	sort(a2.line.begin(),a2.line.end());
	sort(b1.line.begin(),b1.line.end());
	sort(b2.line.begin(),b2.line.end());

	a1.make_hash();
	a2.make_hash();
	b1.make_hash();
	b2.make_hash();

	ull A1 = a1.get_hash(1,n/2);
	ull A2 = a2.get_hash(1,n/2);
	ull rA1= a1.get_revhash(1,n/2);
	ull rA2= a2.get_revhash(1,n/2);


	ull B1= b1.get_hash(1,n/2);
	ull B2 = b2.get_hash(1,n/2);
	ull rB1 = b1.get_revhash(1,n/2);
	ull rB2 = b2.get_revhash(1,n/2);
	/*debug (a1,b2);
	debug(a2,rb1);*/
	//a1 = b1 // a2 = b2
	///cout<<a1.line<<" "<<b1.line<<endl;
	if((A1 == B1 || A1==rB1 || rA1 == B1 || rA1==rB1) and (A2 == B2 || A2 == rB2 || rA2==B2 ||  rA2 == rB2)){
		cout<<"YES"<<endl;
		return 0;
	}
	if((A1 == B2 || A1==rB2 || rA1 == B2 || rA1==rB2) and (A2 == B1 || A2 == rB1 || rA2==B1 || rA2 == rB1)){
		cout<<"YES"<<endl;
		return 0;
	}
	cout<<"NO"<<endl;
}