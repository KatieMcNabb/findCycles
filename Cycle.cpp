#include "Cycle.h"
#include <math.h>
#include <iostream>

using namespace std;

Cycle::Cycle()
{

for (int ii = 0; ii < 100; ii++)
	{
		for (int jj = 0; jj < 100; jj++)
		{

			next[ii][jj] = NULL;
		}

	}

  for (int ii = 0; ii < 100; ii++)
	{
		for (int jj = 0; jj < 100; jj++)
		{

			path[ii][jj] = 1000;
		}

	}

}

void Cycle::makeCycle(float myarray[100][100])
{


	for (int ii = 0; ii < 100; ii++)
	{
		for (int jj = 0; jj < 100; jj++)
		{
			if (myarray[ii][jj] == 0)
				continue;
			else
			   path[ii][jj] = log(myarray[ii][jj]);
		}

	}


}


void Cycle::floyd()
{
	
    for (int kk = 0; kk < 100; kk++)				//implentation floyd warshall with path reconstruction
	{												//source: http://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm
       for (int ii =0; ii < 100;ii++)
	   {
          for (int jj = 0; jj < 100; jj++)
		  {
				 if (path[ii][kk]*path[kk][jj] < path[ii][jj])
				 {  path[ii][jj] = path[ii][kk]*path[kk][jj];
					next[ii][jj] = kk;
				 }

		  }

	   }
	}





}

int Cycle::getPath(int i, int j)
{   

   cout<<"entered getpath"<<endl;
   
   int inter = next[i][j];

   if (inter == 0)
   {   cout<<"no edge between"<<endl;
	   return 0;
   }

   else if (path[i][j] == 1000)
	   return NULL;

   else
	{  cout<<inter<<endl;
	   return getPath(inter,i);
	}
}