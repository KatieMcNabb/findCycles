#include "Socket.h"
#include "Cycle.h"
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
float myarray[100][100];

int main() {
	int ii = 0;
	int jj =0;
	int count = 0;


	try{
    SocketClient s("algorithmics.bu.edu", 8001);
	s.SendLine("KatherineMcnabb 589a88725633bd1f getAllRates");

	while (count<10000) 
	{
	
		

		string l = s.ReceiveLine();
		double buf; // Have a buffer string
		stringstream ss(l); // Insert the string into a stream


		while (ss >> buf)
		{	//start while
			
			            
						myarray[ii][jj] = buf;

						jj++;
						count++;
						if (jj == 100)
						{	ii++;
							jj = 0;
						}


		}
    }


  } 
  catch (const char* s) {
    cerr << s << endl;
  } 
  catch (std::string s) {
    cerr << s << endl;
  } 
  catch (...) {
    cerr << "unhandled exception\n";
  }

  //begin floyd warshall
  Cycle myCycle;
  myCycle.makeCycle(myarray);
  myCycle.floyd();
  float myWeight = 0;
  int index1 = 0;
  int index2 = 0;

 	for (int ii = 0; ii < 100; ii++)
	{
		for (int jj = 0; jj < 100; jj++)
		{
			if (myCycle.path[ii][jj] < myWeight)
			{	myWeight = myCycle.path[ii][jj];
			    cout<<"new low weight is "<<myWeight<<endl;
			    index1 = ii;
				index2 = jj;
			}

		}

	}

	cout<<"before run getpath index is "<<index1<<endl;
	cout<<"before run getpath index is "<<index2<<endl;
	myCycle.getPath(index1,index2);

  return 0;


}