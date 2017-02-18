#include<iostream>
using namespace std;
class Arreglo{
	int tamanio;
	int * elemento;
	public:
		Arreglo(int);
		void mostrar();
		void cargar();
		int burbuja();
};
Arreglo::Arreglo(int tamanio)
{
	this->tamanio=tamanio;
	elemento=new int[tamanio];
}
void Arreglo::cargar(){
	int numero;
	for(int i=0;i<tamanio;i++)
	{
	
		cout<<"Ingrese la posicion "<<(i+1)<<" del arreglo : \n";
		cin>>numero;
		elemento[i]=numero;
	}
}
int Arreglo::burbuja(){
	int i,j,aux,op=0;
	for(i=0;i<tamanio-1;i++)
	{
		for(j=i+1;j<tamanio;j++)
		{
			op++;
			if(elemento[i]>elemento[j])
			{
				
				aux=elemento[i];
				elemento[i]=elemento[j];
				elemento[j]=aux;
			}
		}
	}
	return op;	
}
void Arreglo::mostrar(){
	cout<<"El arreglo ordenado es: \n";
	for(int i=0;i<tamanio;i++)
	{
		cout<<elemento[i]<<" ";
	}
}
int main()
{
	int n,op;
	cout<<"de que tamaño es el arreglo?";
	cin>>n;
	Arreglo A(n);
	A.cargar();
	op=	A.burbuja();
	A.mostrar();
	cout<<"las operaciones realizadas son "<<op;
}
