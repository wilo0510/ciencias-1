#include <iostream>
using namespace std;
class Arreglo{
	int tamanio;
	int * elemento;
	public:
		Arreglo(int);
		void mostrar();
		void cargar();
		int insercion();
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
int Arreglo::insercion(){
	int i, a, temporal;
  for (i=1; i < tamanio; i++) {
    temporal = elemento[i];
    a = i-1;
    while (a >= 0 && elemento[a] > temporal) {
      elemento[a + 1] = elemento[a];
      a--;
    }
    elemento[a+1] = temporal;
  }
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
	op=	A.insercion();
	A.mostrar();
	cout<<"las operaciones realizadas son "<<op;
}
