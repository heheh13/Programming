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
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
typedef long long ll;
typedef unsigned long long ull;
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
	optimizar;
	string a,b;
	cin>>a>>b;
	x.line+=a;
	x.line+=b;
	x.make_hash();
	sz = x.line.size();
	std::vector<int> idx;
	for(int i = 1;i<=x.line.size();i++)idx.push_back(i);
	sort(idx.begin(),idx.end(),cmp);
	// find lcp array
	int maxi = 0;
 	for(int i = 1;i<idx.size();i++){
 		maxi = max(maxi,find_lcp(idx[i],idx[i-1]));
 	}
 	cout<<maxi<<endl;
}