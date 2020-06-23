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
	int n;
	cin>>n;
	string a,b;
	cin>>a>>b;
	std::vector<int> v;
	for(int i  = 0;i<b.size();i++){
		if(a[i]==b[i])continue;
		else{
			char ch = b[i];

			//find b[i] and swap until the meet to i ;
			//bool found = false;
			for(int j = i;j<a.size();j++){
				//cout<<"i";
				if(ch==a[j]){
				//	found = true;
					int p=j;
					while(1){
						if(a[i]==ch)
							break;
						swap(a[p],a[p-1]);
						v.push_back(p);
						p--;

					}
					break;
				}
			}
			//if(!found)break;
		}
	}
	if(a==b){	
		cout<<v.size()<<endl;
		for(auto x:v)cout<<x<<" ";
	}
	else cout<<"-1"<<endl;
}