#include <iostream>
#include <fstream>
using namespace std;

int main(void){
	double x0 = 0.5;
	double xs;
	int Nskip = 100; //Number of iterations to skip
	int Nend  = 200; //Number of total iterations
	double x[Nend-Nskip];
	ofstream out("output.dat");
	
	for(double r=0; r <= 4; r += 0.001){
	  xs=x0;
	   for(int i=1; i <= Nskip+1; i++)
		   xs = r*xs*(1-xs);
	   x[0]=xs;
	   for(int i=Nskip+2; i <= Nend; i++){
	   		   x[i-(Nskip+1)] = r*x[i-(Nskip+2)]*(1-x[i-(Nskip+2)]);
   	   }
   	   for(int i=0; i<(Nend-Nskip); i++){
	     out << r << "\t" << x[i] << endl;
	   }
	}

	out.close();
	return 0;
}
