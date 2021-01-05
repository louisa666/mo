#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> ans;
int www;


int main ()
{
	
	int w[] = {0, 4, 7, 9};
	int cost[] = {0, 6, 11,15};
	int amount[] = {0, 3, 2, 1};
	int count = 3;
	int m = 15;
	// backpack
	int A[count+1][m+1];
	for(int i = 0;i<=m;i++)
	{ 
	
	  A[0][i] = 0;
 
	}
	for (int j = 0; j<=count;j++)
	{
	  A[j][0] = 0 ;
	}
	for ( int k = 1; k<=count;k++)
	{            
 	 for (int s = 1; s<= m;s++)  
 	 {     
	  	 A[k][s] = A[k][s-1]; 
 	
	     for (int l = 0; l <= min(amount[k],s / w[k]) ; l++)
	      {                     
			if (s>=w[k]*l)   
			{
				A[k][s] =  max(A[k][s], A[k - 1][s - l * w[k]] + cost[k] * l);	
			} 
				                                       
		  }
		  cout<<" k: "<<k<<" s: "<<s<<" ks: "<<A[k][s]<<endl;
		  
	  }
		
	 }
	 //Восстановление набора
	int change;
	int test1 = count;
	int test2 = m;
	while (A[test1][test2]!=0)
	{
		if (A[test1][test2] != A[test1-1][test2])
		{
			ans.push_back(test1);
			change = A[test1][test2] - cost[test1];
			while (A[test1][test2]!=change)
			{
				test2 --; 
			}
		}
		else
		{
			test1--;
		}
	}
	cout<<"\n";


   
   int amount_of_el[count];
   	   for (int zzz = 0; zzz<count;zzz++)
		{
			amount_of_el[zzz] = 0;
		}
 
		for (unsigned int yyy = 0; yyy<ans.size();yyy++)
		{
			amount_of_el[ans.at(yyy)-1]++;
		}

	   for (int zzz = 0; zzz<count;zzz++)
		{
			cout<<amount_of_el[zzz]<<" ";
		}
	return 0;
}

