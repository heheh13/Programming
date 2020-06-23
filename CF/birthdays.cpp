#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 1005
#define mod  6
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
struct person
{
	string name;
	int date,month,year;
	
}a[mx];
bool cmp(struct person x , struct person y){
	if(x.year==y.year&& x.month == y.month){
		return x.date <y.date;
	}
	if(x.year==y.year)return x.month<y.month;
	return x.year<y.year;
}
int main(){
	File_IO();
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>a[i].name>>a[i].date>>a[i].month>> a[i].year;
	}
	sort(a,a+n,cmp);
	cout<<a[n-1].name<<endl;
	cout<<a[0].name<<endl;
}