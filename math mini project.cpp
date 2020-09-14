#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

 double df(double x0, double y0)  // 	creat a function to calculate f(x,y)
 {
 	double a ;
	     a = pow (x0,2)*9 - 4*x0 +5 ;
 	return a;
 }
 
 	  double df1(double x)  // 	creat a function to calculate f(x,y) to use it for the error calculation 
 {
 	double b ;
	     b = pow (x,3)*3- pow (x,2)*2 + 5*x + 10 ;
 	return b;
 }
 
 
int main()
{
	
	cout<<"\n\n \t\t this program is made to solve an ODE using Runge-Kutta 3rd method \n"<<endl;  
	cout<<"\t\t **************************************************************************\n\n";
	cout<<"\t\t\t\t our problem is => dy/dx= 9(x^2) - 4x +5 "<<endl;  // the problem we want to solve 
	cout<<"\t\t\t\t with initial condition : y(-1)=0, n=300, h=0.01 "<<endl; // the given initial condition, step size and the number of iterations 
	cout<<"\t\t\t after solving the ODE normally we got the following solution :\n";
	cout<<"\t\t\t\t\t y =3(x^3) - 2(x^2) + 5x + 10\n\n ";
	cout<<"\t\t\t\t **********************************************\n\n";
	
	float h = 0.01;  // step size
	double x0 = -1;  // initial conditon for x
	double y0 = 0;  //  initial condition for y
	double x = 2;   // the number we will stop in after 300 iterations 
	double k1,k2,k3,y,z; // variables to store k1, k2, k3 in and y is for the new y 
	double X; // variable for the real value for the last iteration 
	double E; // variable to calculate the error
	cout<<"---------------------------------------------------------------------------------------------------------------------\n";
	cout<<"x0"<<setw(19)<<"y0"<<setw(19)<<"dy/dx"<<setw(19)<<"k1"<<setw(19)<<"k2"<<setw(19)<<"k3"<<setw(19)<<setw(16)<<"y_new\n";   
	cout<<"---------------------------------------------------------------------------------------------------------------------\n";
	
	while (x0<x) //the condition to perform 300 iterations 
	{
	    k1=df(x0,y0); 
	    k2=df(x0+0.5*h,y0+0.5*k1*h); 
	    k3=df(x0+h,y0-k1*h+2*k2*h);
	    
	    z = 0.1666666667*(k1 + 4*k2 +k3)*h;
	    
	    y = y0 + z; // to calculate the new y
	    
	    cout<<x0<<setw(19)<<y0<<setw(19)<<df(x0,y0)<<setw(19)<<k1<<setw(19)<<k2<<setw(19)<<k3<<setw(19)<<setw(16)<<y<<endl<<endl;
	    y0=y;  // store the new y in y0 to use it for the calculations in the next iteration 
	    x0=x0+h; // add the step size to the previous x0
	}
	
        X = df1(2);
        E = ((y-X)/X)*100;
        
        cout <<"\t\t the percentage error for the last iteration is: "<<E<<"%"<<endl<<endl;

	return 0;
		
}








