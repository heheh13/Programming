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
struct  team
{
	int id;
	char problem;
	string tim;
	string verdict;
	int score=0;
};
bool cmp (struct team a, struct team b){
	return a.tim<b.tim;
}
int T,p,s;
int score[151];
int ps[100];
bool check(){
	bool one=true,all=true,each=true,giveaway=true;
	for(int i = 1;i<=T;i++){
		if(score[i]<=0)one = false;
		if(score[i]==p)all = false;
	}
	for(int i = 1;i<=p;i++){
		if(ps[i]<=0)each = false;
		if(ps[i]==T) giveaway = false;
	}
	//cout<<one<<all<<each<<giveaway<<endl;
	return one&&all&&each&&giveaway;
}
bool resub[151][20];
int  main(){
	File_IO();
	optimizar;
	
	while(cin>>T>>p>>s){
		if(T+p+s==0)return 0;
		struct team t[5001];
		for(int i = 0;i<s;i++){
			cin>>t[i].id>>t[i].problem;
			char ch;
			cin>>t[i].tim;
			getline(cin,t[i].verdict);
		}
		sort(t,t+s,cmp);
		
		memset(ps,0,sizeof(ps));
		memset(score,0,sizeof(score));
		bool flag = false;
		string t1="",t2="";
		memset(resub,0,sizeof(resub));
		for(int i = 0;i<s;i++){
			if(t[i].verdict[1]=='Y'){
				if(!resub[t[i].id][t[i].problem-64]){
					resub[t[i].id][t[i].problem-64]=1;
					score[t[i].id]++;
					ps[t[i].problem-64]++;
				}
			}
			if(!check() && flag){
				t2 = t[i].tim;
				break;
			}

			if(check()&&!flag){
				t1=t[i].tim;
				flag = true;
			}
		}
		if(t1=="")t1="--:--:--";
		if(t2=="")t2="--:--:--";
		cout<<t1<<" "<<t2<<endl;
	}
}