#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll power (ll base, ll p){
	ll sum=1;
	for(int i =0;i<p;i++)
		sum*=base;
	return sum;
}
ll equivalentdecimal(string number,ll base){
	ll p = number.size()-1;
	ll sum =0;
	for(ll i =0;i<number.size();i++)
	{
		ll temp ;
		if(number[i]<=57)
			temp=number[i]-48;
		else temp = number[i]-55;
		sum += temp * power(base,p--);
	}
	return sum;
}
string decilamtoanybase(ll num,ll base){
	string res ;
		while(num){
			int t = num%base;
			if(t<=9)
				res+=t+48;
			else res+=t+55;
			num/=base;
		}
		reverse(res.begin(),res.end());
		if(res=="")
			res+=48;
		//cout<<res<<endl;
		return res;

}
int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	ll base,target;
	ll maxi =0;
	string number;
	while(cin>>number>>base>>target){
		bool flag = false;
		for(int i=0;i<number.size();i++){

			if(number[i]=='0'&&!flag)
				continue;
			else flag=1;
		}
		if(number=="")
			number+=48;

		maxi=0;
		for(ll i =0;i<number.size();i++){
			ll temp ;
			if(number[i]<=57)
				temp=number[i]-48;
			else temp = number[i]-55;
			maxi = max(maxi,temp);
		}
		if(maxi>=base)
		{
			cout<<"  ERROR"<<endl;
			continue;
		}

		ll num = equivalentdecimal(number,base);
		string res = decilamtoanybase(num,target);
		if(res.size()>7){
			cout<<"  ERROR"<<endl;
			continue;
		}
		for(int  i = res.size();i<7;i++)
			cout<<" ";
		
		cout<<res<<endl;
	}

}