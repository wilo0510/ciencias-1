#include <iostream>
#include <stdlib.h>

using namespace std;

int fibo_iterativo (int n,int &op)
{
				  op=0;
				  int i = 0;
				  int j = 1;
	
				  for (int k = 1; k < n; k++)
				  {	
					int t;
					op++;
					t = i + j;
					i = j;
					j = t;
				  }

	return j;
	
}
int main()
{
	int num,op;
	cout<<"Ingrese la posicion de la serie fibonacci que desea ver \n";
	cin>>num;
	cout<<"El valor correspondiente a esa posicion es "<<fibo_iterativo(num,op);
	cout<<" Se realizaron "<<op<<" operaciones modulo";
}
