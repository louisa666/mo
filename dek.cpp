#include <iostream>
using namespace std;


int len = 0;
int min_e; 
int main ()
{
	
	int p = 5;
	int w_l[p][p] = {{0,25,15,7,2},{25,0,6,10000,10000},{15,6,0,4,10000},{7,10000,4,0,3},{2,10000,10000,3,0}};
	
	int arr[p][p+1];
	
	int point [p];
	bool in [p];
	int el = 0;

 
 for (int musa = 0; musa < p; musa++)			//цикл, где меняются вершины 
 {		
	 	for (int i = 0;i < p; i++)
		{
			in[i] = false;
		}
		len = 0;
		el = 0;
		
		
		int curr = musa;
	 	point [0] = musa;
		in [musa] = true;
		//min_e = w_l[musa][0];
		
	for (int j = 1; j < p; j++)
	{
		int z = 0;
		while (in[z])
		{
			z++;
			min_e = w_l[curr][z];
		}
		if (in[z] == false)
		{
			min_e = w_l[curr][z];
		}
		
		for (int k = 0; k < p;k++)
		{
			if ((min_e > w_l[curr][k]) && in[k]==false && w_l[curr][k]!=0)
			{
				point [j] = k;
				el = k;
				min_e = w_l[curr][k];
			}
			else if(min_e == w_l[curr][k] && in[k]==false && w_l[curr][k]!=0)
			{
				point [j] = k;
				el = k;
			}
			//cout<<curr<<" "<<min_e<<endl;
		}
		
		curr = el;
		in [el] = true;
		len+=min_e;
	}
	
	//вывод
	
	cout<<"\nlen: "<<len<<endl;
	cout<<"way: ";
	for (int s = 0; s< p; s++)
	{
		cout<<point[s]<<" ";
	}
	

		for (int a = 0; a < p; a++)
		{
			arr[musa][a] = point[a]; 
		}
		arr[musa][p] = len;
}
		int musa2 = 0;
		int end_m = arr[0][p];
		for (int b = 0; b < p;b++)
		{
			if (end_m > arr[b][p])
			{
				end_m = arr[b][p];
				musa2 = b;
			}
		}
			
		cout<<"\n\n\nlast answer: "<<arr[musa2][p]<<"\n";	
		for (int o = 0; o< p; o++)
		{
			cout<<arr[musa2][o]<<" ";
		}
		
	return 0;
}
