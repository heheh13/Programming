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
map<char,bool> mp;

int main(int argc, char const *argv[])
{
	File_IO();
	string line ;
	cin>>line;
	char vowel[] ={'a','e','i','o','u'};
	for(int i = 0;i<6;i++)
		mp[vowel[i]]=1;
	bool flag = false;
	for(int i = 0;i<line.size();i++){
		if(line[i]=='n')continue;
		if(mp[line[i]])continue;
		if(!mp[line[i+1]]||i+1==line.size())flag = true;
	}
	if(flag)cout<<"NO"<<endl;
	else cout<<"YES"<<endl;

}