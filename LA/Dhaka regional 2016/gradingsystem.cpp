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
int power(int base,int power){
	int sum=1;
	for(int i = 0;i<power;i++)sum*=base;
		return sum;
}
int anytodec(int base,int st,string line){
	int sum=0,x=line.size()-st-1;
	for(int i = st;i<line.size();i++){
		int a = line[i]-48;
		if(a>=10&&a<49)a-=7;
		else if(a>=49)a-=39;
		sum+=a*power(base,x--);
	}
	return sum;
}
pair<int,int>   calc(string ans,int current){

		if(ans=="i"){
			return {current,0};
		}
		if(ans=="i++"){
			return {current,1};
		}
		if(ans=="++i"){
			return {current+1,0};
		}
		if(ans=="i--"){
			return {current,-1};
		}
		if(ans == "--i"){
			return {current-1,0};
		}

}
int main(){
	File_IO();
	string line;
	int value;
	while(cin>>line>>value){
		if(line=="0"&&value==0)return 0;
		int num ;
		if(line[1]=='x') num = anytodec(16,2,line); 
		else if(line[0]=='0') num = anytodec(8,1,line);
		else num = anytodec(10,0,line);
		int cnt = 0;
		int current = num;
		while(value--){
			string ans;
			int  val;
			cin>>ans>>val;
			pair<int,int> res = calc(ans,current);
			if(val == res.first){
				cnt++;
				current=res.first+res.second;
			}
			else{
				current = val+res.second;
			}
		}
		cout<<cnt<<endl;
	}

}