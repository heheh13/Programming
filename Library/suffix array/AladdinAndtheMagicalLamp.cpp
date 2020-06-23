#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 40004
#define mod  6
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC optimize("unroll-loops")
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
stringhash x;
int sz;
bool cmp(int id1 , int id2){
	int low = 0 , high = sz;
	int mid;
	int ans=0;
	while(low<=high){
		mid = (high+low)/2;
		ull hash1  = x.get_hash(id1,id1+mid-1);
		ull hash2 = x.get_hash(id2,id2+mid-1);
		//cout<<hash1<<" "<< hash2<<" "<<mid<<endl;
		if(hash1==hash2){
			ans = mid;
			low = mid+1;
		}
		else {
			high = mid-1;
		}
	}
	//cout<<x.line[id1+ans-1]<<" "<<x.line[id2+ans-1]<<endl;
	return x.line[id1+ans-1]<x.line[id2+ans-1];
}
int find_lcp(int id1 , int id2){
	int low = 0 , high = sz;
	int mid;
	int ans=0;
	while(low<=high){
		mid = (high+low)/2;
		ull hash1  = x.get_hash(id1,id1+mid-1);
		ull hash2 = x.get_hash(id2,id2+mid-1);
		//cout<<hash1<<" "<< hash2<<" "<<mid<<endl;
		if(hash1==hash2){
			ans = mid;
			low = mid+1;
		}
		else {
			high = mid-1;
		}
	}
	
	return ans;
}
int main(){
	File_IO();
	int t;
	cin>>t;
	for(int ts = 1;ts<=t;ts++){
		string line;
		x.line.clear();
		int id1,id2,id3;
		cin>>line;
		x.line+=line+'#';
		id1 = x.line.size();
		cin>>line;
		x.line+=line+'$';
		id2 = x.line.size();
		cin>>line;
		x.line+=line+'%';
		id3 = x.line.size();
		//cout<<x.line<<endl;


		x.make_hash();
		sz = x.line.size();
		std::vector<int> idx;
		for(int i = 1;i<=x.line.size();i++)idx.push_back(i);
		sort(idx.begin(),idx.end(),cmp);

		for(int i = 0;i<idx.size();i++){
			for(int j = idx[i]-1;j<sz;j++){
				cout<<x.line[j];
			}
			cout<<endl;
		}
		cout<<id1<<" "<<id2<<" "<<id3<<endl;
		int ans = 0;
		int f1=0,f2=0,f3=0;
		std::vector<pair<int,int> > v;
		//int lcp[sz+5],id[sz+5];
		int id ;
		
		for(int i = 1;i<sz;i++){
			int lcp =find_lcp(idx[i],idx[i-1]);
			if(idx[i]<=id1)f1++,id = 1;
			else if(idx[i]<=id2)f2++,id  = 2;
			else f3++,id = 3;
			v.push_back({lcp,id});
			while(f1>0 && f2>0 && f3>0 && v.size()){
				if(v[0].second==1)f1--;
				else if(v[0].second==2)f2--;
				else f3--;
				v.erase(v.begin()+0);
				int temp = 1e9;
				for(int i = 0;i<v.size();i++)temp = min(temp,v[i].first);
					ans = max(ans,temp);
			}

		}
		cout<<"Case "<<ts<<": "<<ans<<endl;
		line.clear();

	}
}