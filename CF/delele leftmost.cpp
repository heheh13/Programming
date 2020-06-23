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
int arr[32];
map<int,int> mp;
bool mark[mx];
int main(int argc, char const *argv[])
{
	File_IO();
	for(int i = 0;i<=30;i++){
		arr[i]=pow(2,i);
	}

	int n;
	cin>>n;
	
	int temp[n];
	for(int i = 0;i<n;i++){
		cin>>temp[i];
		mp[temp[i]]++;
	}
	int cnt =n;
	for(int i =0;i<n;i++){
		for(int j = 0;j<=30;j++){
			int val = (arr[j]-temp[i]);
			if(val == temp[i]){
				if(mp[val]>1){
					cnt--;
					break;
				}
			}
			else if(mp[val]){
				cnt--;
				break;
			}
		}
	}
	cout<<cnt<<endl;

}