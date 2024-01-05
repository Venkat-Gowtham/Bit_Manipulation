#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n;
	cin>>t>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	vector<vector<int>>pre(n,vector<int>(32,0));
	for(int i=0;i<n;i++)
	{
		for(int j=31;j>=0;j--)
		{
			pre[i][j]=((arr[i]>>j)&1);
			if(i>0)
			{
				pre[i][j]+=pre[i-1][j];
			}
		}
	}
	for(int k=0;k<t;k++)
	{
		int l,r;
		cin>>l>>r;
		int x=r-l+1;
		if(l==0)
		{
			int res=0;
			for(int i=31;i>=0;i--)
			{
				if(pre[r][i]%2)res+=1<<i;
			}
			cout<<res<<endl;
		}
		else
		{	int res=0;
			for(int i=31;i>=0;i--)
			{
				int val=pre[r][i]-pre[l-1][i];
				if(val%2)res+=1<<i;
			}
			cout<<res<<endl;
		}
	}
}
