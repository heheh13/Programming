#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 100010
#define mod  6
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
int main(){
	optimizar;
	File_IO();
	int t;
	cin>>t;
	map<char,char> mp;
	mp['(']=')';
	mp['{']='}';
	mp['[']=']';
	mp['<']='>';
	for(int ts = 1;ts<=t;ts++){
		cout<<"Case "<<ts<<":\n";
		string line ;
		cin>>line;
		stack<pair<char,int> > st;
		int track[mx];
		memset(track,0,sizeof(track));
		for(int i = 0;i<line.size();i++){
			if(line[i]=='<'||line[i]=='('||line[i]=='{'||line[i]=='['){
				st.push({line[i],i});
			}
			else{
				if(st.size()>=1){

					char ff = st.top().first;
					int sc = st.top().second;
					///dbg(ff,sc);
					if(mp[ff]==line[i]){
						track[i]=0;
						track[sc]=i;
						st.pop();
					}
					else{
						 while(!st.empty()){
						 	st.pop();
						}
						track[i]=0;
						track[sc]=0;
					}
				}
			}
		}
		std::vector<int > v;
		int dp[mx];
		memset(dp,0,sizeof(dp));
		//for(int i = 0;i<line.size();i++)cout<<track[i]<<" ";
		for(int i = line.size()-1;i>=0;i--){
			if(track[i]==0)v.push_back(0);
			else{
				int cnt = 0;
				int x = i;
				// while(track[x]>0){
				// 	//debug(x);

				// 	//return 0;
				// 	cnt+=(track[x]-x+1);
				// 	x = track[x]+1;
				// }
				dp[x]=dp[track[x]+1]+track[x]-x+1;
				cnt = dp[x];
				v.push_back(cnt);

			}
		}
		
		for(int i = v.size()-1;i>=0;i--)cout<<v[i]<<"\n";
	}
}