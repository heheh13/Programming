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
struct mapmaker
{
	int base;
	int sz,dim;
	int L[11],U[11];
	
}mp[100];
std::map<string , int >name;
int  calc_adress( int id, int *idx,int dimen){
	///addres = c0+ c1i1 + c2i2;
	int c[dimen+1];
	c[dimen]= mp[id].sz;
	for(int i = dimen-1;i>0 ;i--){
		c [i]= c[i+1] * (mp[id].U[i+1]-mp[id].L[i+1] + 1);
		//cout<<c[i]<<endl;
	}
	c[0]=mp[id].base;
	for(int i = 1;i<=dimen;i++){
		c[0]-= c[i]*mp[id].L[i];
	}
	int addres = c[0];
	for(int i = 1;i<=dimen;i++){
		addres += c[i]*idx[i-1];
	}
	return addres;

}
int main(){
	File_IO();
	int n,r;
	while(cin>>n>>r){
		
		for(int i = 1;i<=n;i++){
			string temp;
			cin>>temp;
			name[temp]=i;
			cin>>mp[i].base>>mp[i].sz >> mp[i].dim; 
			for(int j = 1;j<=mp[i].dim;j++){
				cin>>mp[i].L[j];
				cin>>mp[i].U[j];
			}
		}
		while(r--){
			string line;
			cin>> line;
			int idx[11];
			int dimen = mp[name[line]].dim;
			for(int i = 0; i<dimen; i++)
			{
				cin>>idx[i];
			}
			int adress = calc_adress(name[line],idx,dimen);
			cout<<line<<"[";
			for(int i = 0;i<dimen-1;i++)
				cout<<idx[i]<<", ";
			cout<<idx[dimen-1]<<"] = "<<adress<<endl;
		}
	}
}