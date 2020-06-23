#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int n,p;
	cin>>n>>p;
	map<string,int>mp;
	int cnt =1;
	mp["Erdos"]=1;
	for(int i =0;i<n;i++)
	{
		string line;
		getline(cin,line);

		string temp ;
		for(int j =0;j<line.size()&&line[j]!=':';j++)
		{
			if(line[j]>=65&&line[j]<=122)
				temp+=line[j];
			if(line[j+1]==','||line[j+1]==':'){

				if(mp[temp])
					continue;
				else mp[temp]=++cnt;
				cout<<temp<<endl;
				temp ="";

			}
		}

	}
	map<string,int> ::iterator it;
	for(it = mp.begin();it!=mp.end();it++)
		cout<<it->first<<endl;
}