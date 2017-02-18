#include <iostream>
using namespace std;
class Arreglo{
	int tamanio;
	int * elemento;
	public:
		void operator=(Arreglo);
		Arreglo(int);
		void mostrar();
		void cargar();
		int insercion();
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
void Arreglo::mostrar(){
	cout<<"El arreglo ordenado es: \n";
	for(int i=0;i<tamanio;i++)
	{
		cout<<elemento[i]<<" ";
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
void Arreglo::operator=(Arreglo A)
{
	this->tamanio=A.tamanio;
	for(int k=0;k<tamanio;k++)
	{
		elemento[k]=A.elemento[k];
	}
}
int Arreglo::insercion(){
	int i, a, temporal,op=0;
  for (i=1; i < tamanio; i++) {
    temporal = elemento[i];
    a = i-1;
    op++;
    while (a >= 0 && elemento[a] > temporal) {
      elemento[a + 1] = elemento[a];
      a--;
      if(a>=0)
      {
      op++;
  }
    }
    elemento[a+1] = temporal;
  }
  return op;
}
int main()
{
	int n,op;
	cout<<"de que tamaño es el arreglo?";
	cin>>n;
	Arreglo A(n),B(n);
	A.cargar();
	
	B=A;
	op=	B.burbuja();
	B.mostrar();
	cout<<"las operaciones realizadas en el metodo burbuja son "<<op<<"\n";
	
	B=A;
	op=	B.insercion();
	B.mostrar();
	cout<<"las operaciones realizadas en el metodo insercion son "<<op<<"\n";
}
