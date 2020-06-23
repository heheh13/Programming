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
	std::vector<int > v;
	int cnt = 0;
	int last = -1;
	int temp;
	for(int i = 0;i<n;i++){
		cin>>temp;
		if(temp<=last){
			v.push_back(cnt);
			cnt=0;
		}
		cnt++;
		last = temp;
	}
	v.push_back(cnt);
	cout<<v.size()<<endl;
	for(int i = 0;i<v.size();i++)cout<<v[i]<<" ";

}
