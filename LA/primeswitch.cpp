#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 1010
#define mod  6
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int arr[mx];
int n,p;
bitset<mx> light;
int maxi = 0;
int track ;
void bt(int pos,string line){
	if(pos>=track){
		//cout<<line<<endl;
		bitset<mx>b;
		string help;
		//bitset<mx>b;
		for(int i = 0;i<line.size();i++){
			if(line[i]==':'){
				int num = stoi(help);
				for(int j = num;j<=n;j+=num)b.flip(j);
				help="";
			}else help+=line[i];
		}
		bitset<mx>nb;
		
		for(int i = track;i<p;i++){
			nb=b;
			for(int j = arr[i];j<=n;j+=arr[i])nb.flip(j);
			if(nb.count()>b.count()){
				b= nb;
			}
		}
		if(b.count()>maxi){
			maxi =b.count();
			light=b;
		}
		return;
	}
	bt(pos+1,line);
	string x =to_string(arr[pos])+":";
	bt(pos+1,line+x);

}

int main(){
	File_IO();
	int t;
	cin>>t;
	for(int ts = 1; ts <= t; ts++){
		cin>>n>>p;
		for(int i = 0; i<p; i++){
			cin>>arr[i];
		}
		sort(arr,arr+p);
		track = 0;
		for(int i = 0;i<p;i++)if(arr[i]<=sqrt(n))track++;
		maxi = 0;
		bt(0,"");
		
		cout<<"Case #"<<ts<<": ";
		cout<<light.count()<<endl;
	}
}