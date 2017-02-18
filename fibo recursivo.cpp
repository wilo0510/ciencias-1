#include<iostream>
using namespace std;
int fibo(int n,int &op)
{
	int n_2,n_1,op1,op2;
	if(n==0|| n == 1)
	{
		op=0;
	return n;
	
}
	else
	{
	n_2=fibo(n-2,op2);
	n_1=fibo(n-1,op1);
	op=op1+op2+1;
	return n_2+n_1;
}
}
int main()
{
	int num,op;
	cout<<"Ingrese la posicion de la serie fibonacci que desea ver \n";
	cin>>num;
	cout<<"El valor correspondiente a esa posicion es "<<fibo(num,op);
	cout<<" Se realizaron "<<op<<" operaciones modulo";
}

