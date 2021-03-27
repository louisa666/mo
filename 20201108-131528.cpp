#include <iostream>
#include <math.h>
#define eps 0.00001
using namespace std;
int count1 = 0;
int count2 = 0;

double func (double x, double y)
{
	
	double z = x*x - 4.0*x + y*y + 8.0*y;
	return z;
}

void inner (double x, double a, double b,double *my, double *mz)
{
	
	double ia = a, ib = b, z1, z2;
	
	double y1 = (double)ia + 0.382 *(ib - ia);
	double y2 = (double)ia + 0.618 *(ib - ia);
	z1 = func(x,y1);
	count1++;
	z2 = func(x,y2);
	count1++;
	while ((double)abs(ia-ib)>=eps)
	{
		if(z1 > z2)
		{
			ia = y1;
			y1 = y2;
			y2 = (double)ia + 0.618 *(ib - ia);
			z1 = z2;
			z2 = func (x,y2);
			count1++;
	
		}
		else if (z1 < z2)
		{
			ib = y2;
			y2 = y1;
			y1 = (double)ia + 0.382 *(ib - ia);
			z2 = z1;
			z1 = func (x,y1);
			count1++;
		}
		
	}
	
    *my = (ia + ib)/2.0;
    *mz = func(x,*my);
  
    
	
}

void outer (double a, double b, double *mx, double *my, double *mz)
{
	
	double oa = a, ob = b;
	double x1 = (double)oa + 0.382 *(ob - oa);
	
	inner(x1, a, b, my, mz);
	count2++;
	double my1 = *my;
	double mz1 = *mz;
	
	double x2 = (double)oa + 0.618 * (ob - oa);
	
	inner(x2, a, b, my, mz);
	count2++;
	double my2 = *my;
	double mz2 = *mz;
	
while ((double)abs(oa-ob)>=eps)
{
   if(mz1 > mz2)
   {
     oa = x1;
     x1 = x2;
     
     my1 = my2;
     mz1 = mz2;
     *mx = x2;
     x2 = (double)oa + 0.618 * (ob - oa);
     inner(x2,a,b,my,mz);
	 cout<<" mx "<<*mx<<" my "<<*my<<" mz "<<*mz<<endl;
     my2 = *my;
     mz2 = *mz;
     count2++;
   
   }

   else if (mz1 < mz2)
   {
	   ob = x2;
	   x2 = x1;
	   
	   my2 = my1;
	   mz2 = mz1;
	    *mx = x1;
	   x1 = (double)oa + 0.382 *(ob - oa);
	   inner (x1,a,b,my,mz);
	   cout<<" mx "<<*mx<<" my "<<*my<<" mz "<<*mz<<endl;
	   my1 = *my;
	   mz1 = *mz;
	   count2++;
	  

   }

}
	
	
}
int main ()
{
	double a = 10;
	double b = -10;
	double mx = 0, my = 0, mz = 0;
	outer (a, b, &mx, &my, &mz);
	cout<<"min x: "<<mx<<" min y: "<<my<<" min z: "<<func(mx,my)<<endl;
	cout<<" count z "<<count1<<" count inner "<<count2<<endl;
	return 0;
}
