/*

		 parent string p.length  = m
		 checking_for_string c.length = n

		 time to find an occurrence of n in m

		 idea compute the hash of string of length n of all n length consequtive substrings in the parent string

		 check for occurrence of strinc c in it 

		 hash value computation can be done in time O(N)because each transitioning between consequtive substrings only requires computation for the change in one character at a time. which can be done in constant time.

		 So O(n) - initial hash + n-m O(1)   O(M)

		 hash of string c is O(N)

		 So O(M+N)

*/



#include <iostream>
#include <iomanip>
#include <functional>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include<math.h>
using namespace std;


int Pattern_Matching(string par,string ch)
{
		//characters are mapped to 0 to 255
		//so every character is represented in base 256
		//hash value = representation in base 256 mod prime 23
	int r = 256,pl,cl,flag = 0,cnt=0;
	int temp = 0;
	//prime divisor
	int p = 23;
	int chk_hash = 0;
	pl = par.length();
	cl = ch.length();
	int h = pow(r,cl-1);

	cout<<pl <<" " <<cl<<"  " <<h<<"\n";
	
	vector<int> parent(pl,0),check(cl,0);
	for(int i=0;i<pl;i++)
		parent[i] =  (int) par[i];

	for(int i=0;i<cl;i++)
		check[i] = (int) ch[i];

	//vector <int>hashed_values (pl - cl + 1,0);
	//vector <bool> present(pl - cl + 1,false);



	for(int i=0;i<cl;i++)
	{
		temp = (r*temp + check[i])%p;
	}
	chk_hash = temp;
	temp = 0;
	for(int i=0;i<cl;i++)
	{
		temp = (r*temp + parent[i])%p;
		cout<<temp<<"\n";
	}
	//hashed_values[0] = temp;
	int tmp1,tmp2;
	tmp1 =temp;
	
	if(temp = chk_hash)
	{
		for(int j =0;j<cl;j++)
			{
				if(par[j]!=ch[j])
				{
					flag = 1;
					break;
				}
			}
		if (flag == 0)
		{
			cout<<"subsequence starting at "<<0<<"\n";
			//present[i] = true;
			cnt++;
		}		
		flag =0;
	}
	

	for(int i=1;i<pl - cl+1 ;i++)
	{
		flag = 0;
		//hashed_values[i] = (hashed_values[i-1] - (h*parent[i-1]%p)*r + parent[cl+i-1])%p;
		tmp1 = ((tmp1 - h*parent[i-1])*r + parent[cl+i-1])%p;
		if (tmp1<0)
			tmp1 = tmp1 +p;
		//if(hashed_values[i] == chk_hash)
		cout<<chk_hash<<"   "<<tmp1<<"\n";
		
		if(tmp1 == chk_hash)
		{
			for(int j =0;j<cl;j++)
			{
				if(par[i+j]!=ch[j])
				{
					flag = 1;
					break;
				}
			}
		if (flag == 0)
		{
			cout<<"subsequence starting at "<<i<<"\n";
			//present[i] = true;
			cnt++;
			}		
		}
	}
	//return present;
	return cnt;

}
int main()
{
	//vector<bool> ans;
	string parent,check;
	int cnt=0;
	cout<<"enter parent string"<<"\n";
	getline(cin,parent);
	cout<<"enter check string"<<"\n";
	getline(cin,check);

	//ans = Pattern_Matching(parent,check);
	cnt = Pattern_Matching(parent,check);
	/*for(int i=0;i<ans.size();i++)
	{
		if(ans[i] == true)
		{
			cout<<"subsequence starting at "<<i<<"\n";
			cnt++;
		}
	}
	*/
	cout<<" number of occurrences "<<cnt<<"\n";

	return 0;

}

