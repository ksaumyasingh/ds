#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int i=2;
	while(i<n)
	{
		if(n%i==0)
			break;
		i++;
	}
	if(i==n)
		cout<<"prime";
	else
		cout<<"not prime";
	return 0;
}