#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 10000005
#define mod  6
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
string add(string a, string b)
{
	//cout<<a<<" g "<<b<<endl;
	int res = a.size();
	int ret = b.size();
	if(res<ret)
	{
		string hx;
		for(int i =0;i<ret-res;i++)
			hx+='0';
		hx+=a;
		a=hx;
	}
	if(res>ret)
	{
		string hx;
		for(int i =0;i<res-ret;i++)
		{
			hx+='0';
		}
		hx+=b;
		b=hx;
	}
	int carry=0;
	string ans;
	for(int i =a.size()-1;i>=0;i--)
	{
		int temp= (a[i]-'0')+(b[i]-'0');
		if(temp+carry<10)
		{
			ans+=temp+carry+'0';
			carry=0;
		}
		else
		{
			int hex=temp+carry;
			ans+=(hex%10)+'0';
			hex/=10;
			carry=hex;
		}
	}
	if(carry>0)
		ans+=carry+'0';
	reverse(ans.begin(),ans.end());
	//cout<<ans<<endl;
	return ans;

}

int main(){
	File_IO();
	int t;
	cin>>t;
	for(int ts = 1;ts<=t;ts++){
		string line;
		cin>>line;
		bool nine = true;
		for(int i =0;i<line.size();i++)if(line[i]!='9')nine =false;
		if(nine){
			string ans = "1";
			for(int i = 0;i<line.size()-1;i++)ans+='0';
			ans+="1";
			cout<<"Case "<<ts<<": "<<ans<<endl;
			continue;
		}
		int len = (line.size()-1)/2;
		string hell,res,current,ret;

		for(int i=0;i<=len;i++)hell+=line[i];
		current = ret=hell;
		reverse(ret.begin(),ret.end());
		if(line.size()&1)
	    ret.erase(ret.begin()+0);
		current+=ret;

		res=hell = add(hell,"1");
	    reverse(res.begin(),res.end());
	    if(line.size()&1)
	    res.erase(res.begin()+0);
		//dbg(hell,res);
	    hell+=res;
	   // cout<<current<<endl;
	    if(current>line)hell =current;
	    cout<<"Case "<<ts<<": "<<hell<<endl;
	}
}