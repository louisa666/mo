#include <iostream>
#include <math.h>

using namespace std;

int count = 0;
double eps = 0.01;

double calcy (double x)		//Функция подсчета "y" 
{

		double y = ((double)pow(x,2))-6.0*x;
		count++;
	return y;
} 

int main ()
{
double a, b, x1, x2, y1, y2;




/*cout<<"Please, enter the beginning of the segment"<<endl;
cin>>a;
cout<<"Please, enter the ending of the segment"<<endl;
cin>>b;*/
a = 0;
b = 5;
	x1 = (double)a + 0.382 *(b - a);
	x2 = (double)a + 0.618 * (b - a);
		
	y1 = (double)calcy (x1);
	y2 = (double)calcy(x2);
	
while ((double)abs(b-a)>=eps)		//Начинается цикл золотого сечения
{
	

	if (y1>y2)	
	{
		a = x1;
		x1 = x2;
		y1 = y2;
		x2 = (double)a + 0.618 *(b - a);
		y2 = (double)calcy(x2);
	}
	else if (y1<y2)
	{
		b = x2;
		x2 = x1;
		y2 = y1;
		x1 = (double)a + 0.382 * (b - a);
		y1 = (double)calcy(x1);
	}
	
}
cout<<"x1: "<<x1<<"\nx2: "<<x2<<"\ny1: "<<y1<<"\ny2: "<<y2<<" count: "<<count/2<<endl;
cout<<"\n\n\n";
double x = (a+b)/2;
cout<<"x: "<<x<<"\ny: "<<calcy(x);
return 0;
}
