#include <iostream>
using namespace std;
class Arreglo {
	int tamanio;
	int *elemento;
	
	public:
		Arreglo(int);
		void mostrar();
		void cargar();
		int burbuja();
		int insercion();
		int shellsortv3();			
		void operator=(Arreglo);
};

Arreglo::Arreglo(int tamanio){
	this->tamanio=tamanio;
	elemento=new int[tamanio];
}
void Arreglo::cargar(){	
int num;
for (int i=0;i<tamanio;i++){

	cout<<"Ingresa el elemento "<<i+1<<" : ";
	cin>>num;
	elemento[i]=num;
}
}
int Arreglo::burbuja(){
int i, j,aux,op=0;
for (i=0;i<tamanio-1;i++)
	for (j=i+1;j<tamanio;j++){	
	op++;	
		if (elemento[i]>elemento[j]){
			aux=elemento[i];
			elemento[i]=elemento[j];
			elemento[j]=aux;	
}
		}
		return op;
}


int Arreglo::insercion(){
	int aux,a,op=0;
	for (int k=1;k<tamanio;k++){
		aux=elemento[k];
		a=k-1;
		op++;
		while (a>=0 && elemento [a]>aux){
			elemento[a+1]=elemento[a];
			a--;
			if (a>=0)
			op++;
		}
		elemento[a+1]=aux;
			
	}
return op;
}

int Arreglo::shellsortv3()
{
	int j,tamano;
	int op=0;
	for (int gap = tamano / 2; gap > 0; gap /= 2)
	{
		cout << "divisor : " << gap << endl;
		for (int i = gap; i < tamano; ++i)
		{
			int temp = elemento[i];
			op++;
			for (j = i; j >= gap && temp < elemento[j - gap]; j -= gap)
			{
				cout << endl << "Cambiar elemento " << elemento[j - gap] << " por " << elemento[j] << endl;
				elemento[j] = elemento[j - gap];
				mostrar();
			}
			elemento[j] = temp;
		}
	}
}



void Arreglo::mostrar(){
	cout<<"El arreglo ordenado es: ";
	for (int j=0;j<tamanio;j++)
		if (j<tamanio-1)
		cout<<elemento[j]<<"-";
		else 
		cout<<elemento[j];
	cout<<"\n";	
}

void Arreglo::operator= (Arreglo A){
	this->tamanio=A.tamanio;
	for (int k=0;k<tamanio;k++)
		elemento[k]=A.elemento[k];
	
	
}


int main (){
int n;
cout <<"De que tamanio es el arreglo?\n";
cin>>n;
Arreglo A(n),B(n);	
A.cargar();
B=A;

int operaciones =B.burbuja();
cout <<"METODO BURBUJA"<<"\n \n";
B.mostrar();
cout <<"cantidad de operaciones realizadas en burbuja "<<operaciones<<"\n \n";
B=A;
cout <<"METODO INSERCION"<<"\n \n";
operaciones =B.insercion();
B.mostrar(); 
cout <<"cantidad de operaciones realizadas en Insercion "<<operaciones;

B=A;
cout <<"METODO SHELL"<<"\n \n";
operaciones =B.shellsortv3();
B.mostrar(); 
cout <<"cantidad de operaciones realizadas en Insercion "<<operaciones;

}
