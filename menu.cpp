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
		void shellsortv3();			
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

void Arreglo::shellsortv3()
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
	cout<<"El arreglo es: ";
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
	char opcion,opcionBuscar,opcionOrdenar;
	 
	cout<<"--Bienvenido"<<"\n";
	cout <<"De que tamanio es el arreglo?\n";
	cin>>n;	
	Arreglo A(n),B(n);
	do{
	
	
	cout<<"\t\t\tQue desea hacer con el arreglo?: \n\n";
    cout<<"(C)argar\n";
    cout<<"(M)ostrar\n";
    cout<<"(B)uscar\n";
    cout<<"(O)rdenar\n";
    cout<<"(T)erminar\n";
    cin>>opcion;
 
switch(opcion)
{
case 'C':
	A.cargar();
	B=A;
	break;
case 'M':
	B.mostrar();
	break;
case 'B':
	do{
	
	cout<<"\t\t\tComo desea buscar el dato ? \n\n";
    cout<<"(S)ecuencial\n";
    cout<<"Binario (I)terativo\n";
    cout<<"(B)inario Recursivo\n";
    cout<<"(R)egresar\n";
    cin>>opcionBuscar;
    switch(opcionBuscar)
    {
    	case 'S':
    		break;
    	case 'I':
    		break;
    	case 'B':
    		break;
    	case 'R':
    		break;
    	default: cout<<"El valor ingresado no esta en el menu"<<endl;
	}
    
	}while(opcionBuscar!='R');
		break;
	case 'O':
		do{
		
		cout<<"\t\t\tComo desea organizar el vector ? \n\n";
	    cout<<"(B)urbuja\n";
	    cout<<"(I)nsercion\n";
	    cout<<"(S)hell\n";
	    cout<<"(Q)uicksort\n";
	    cout<<"(M)ergesort\n";
	    cout<<"(C)ubetas\n";
	    cout<<"(R)egresar\n";
	    cin>>opcionOrdenar;
	    switch(opcionOrdenar)
	    {
	    	case 'B':
	    		break;
	    	case 'I':
	    		break;
	    	case 'S':
	    		break;
	    	case '1':
	    		break;
	    	case 'M':
	    		break;
			case 'C':
	    		break;	
	    	default: cout<<"El valor ingresado no esta en el menu"<<endl;
		}
	    
		}while(opcionOrdenar!='R');
		break;
		
default: cout<<"El valor ingresado no esta en el menu"<<endl;
}


}while (opcion!='T');

}/*
int operaciones =B.burbuja();
cout <<"METODO BURBUJA"<<"\n \n";
B.mostrar();
cout <<"cantidad de operaciones realizadas en burbuja "<<operaciones<<"\n \n";
B=A;
cout <<"METODO INSERCION"<<"\n \n";
operaciones =B.insercion();
B.mostrar(); 
cout <<"cantidad de operaciones realizadas en Insercion "<<operaciones<<"\n \n";
B=A;
cout <<"METODO SHELL"<<"\n \n";
B.shellsortv3();
B.mostrar();
cout <<"cantidad de operaciones realizadas en Metodo SHEll "<<operaciones;
}*/
