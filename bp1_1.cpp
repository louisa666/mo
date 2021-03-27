#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int www;


int main ()
{
	int diff;
	
	int M[] = {4, 7, 9};
	int cost[] = {6, 11,15};
	int count = 3;
	int m = 300000;
	int max_i;
	int arr_max_element[m][count];
	
	for (int m0 = 0; m0 <= m; m0++)
	{
		for (int c0 = 0; c0 <= count; c0 ++ )
		{
			arr_max_element[m0][c0] = 0;
		}
		
	}
	int dp [m+1];
	dp[0] = 0;
	
	for (int w = 1; w <= m; w++)
	{
		max_i = -1;
		dp[w] = dp[w-1];
		for (int i = 0; i < count; i++)
		{
			if (M[i] <= w)
			{
				diff = dp[w];
				dp[w] = max(dp[w], dp[w - M[i]] + cost[i]);
				if (diff != dp[w])
				{
					max_i = i;
				}
				
			}
		}
		 if (max_i!= -1 && (w - M[max_i])>=0)
		 {
			 www = w;
		 for ( int j = 0; j < count; j++)
			{
				arr_max_element[w][j] = max_i;
				//cout<<dp[w]<<" "<<max_i<<endl;
			}

			
			
		}
	}
	cout<<dp[m]<<"\n";

	int k = 0;
	
	int amount[count];
	for (int s = 0; s < count; s++)
	{
		amount[s] = 0;
	}
	
	int musa;
	
	int max_m = www;
	while (max_m != 0)
	{
		musa = arr_max_element[max_m][k];
		amount[musa] = amount[musa] + 1;
		
		max_m = max_m - M[arr_max_element[max_m][k]];
	}

	for (int h = 0; h < count; h++)
	{
		cout<<amount[h]<<" ";
	}
		cout<<"\n";
	



	return 0;
}






