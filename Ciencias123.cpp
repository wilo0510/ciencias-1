#include <iostream>
#include <iterator>
#include <algorithm>
#include <functional>
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
		void merge(int*,int*,int,int,int);
		void mergesort(int *a, int*b, int low, int high);
		void quicksort(int A[] ,int b,int c);
		void operator=(Arreglo);
		void Menuordenamiento();
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
void Arreglo::mergesort(int *a, int*b, int low, int high)
{
    int pivot;
    if(low<high)
    {
        pivot=(low+high)/2;
        mergesort(a,b,low,pivot);
        mergesort(a,b,pivot+1,high);
        merge(a,b,low,pivot,high);
    }
}
void Arreglo::merge(int *a, int *b, int low, int pivot, int high)
{
    int h,i,j,k;
    h=low;
    i=low;
    j=pivot+1;
 
    while((h<=pivot)&&(j<=high))
    {
        if(a[h]<=a[j])
        {
            b[i]=a[h];
            h++;
        }
        else
        {
            b[i]=a[j];
            j++;
        }
        i++;
    }
    if(h>pivot)
    {
        for(k=j; k<=high; k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    else
    {
        for(k=h; k<=pivot; k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    for(k=low; k<=high; k++) a[k]=b[k];
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
			}
			elemento[j] = temp;
			op++;
		}
	}
	return op;
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

void Arreglo::quicksort(int A[],int izq, int der )
{ 
int i, j, x , aux; 
i = izq; 
j = der; 
x = A[(izq + der) /2]; 
    do{ 
        while( (A[i] < x) && (j <= der) )
        { 
            i++;
        } 
 
        while( (x < A[j]) && (j > izq) )
        { 
            j--;
        } 
 
        if( i <= j )
        { 
            aux = A[i]; A[i] = A[j]; A[j] = aux; 
            i++;  j--; 
        }
         
    }while( i <= j ); 
 
    if( izq < j ) 
        quicksort( A, izq, j ); 
    if( i < der ) 
        quicksort( A, i, der ); 
}


int main (){
	int n;
	char a,t;
	cout <<"De que tamanio es el arreglo?\n";
	cin>>n;
	Arreglo A(n),B(n);
	do{
	
	
	
	
    cout<<"\t\t\tElija una opcion para ejecutar\n\n";
    cout<<"(C)argar\n";
    cout<<"(M)ostrar\n";
    cout<<"(B)uscar\n";
    cout<<"(O)rdenar\n";
    cout<<"(T)erminar\n";
    cin>>a;
 
switch(a)
{
case 'c':
{
	A.cargar();
	B=A;
	
	
	}
	break;
case 'm':{
	B.mostrar();
	break;
}

case 'o':{
		char opcion1;
cout<<"\t\t\tElija una opcion para ejecutar\n\n";
    cout<<"(B)urbuja\n";
    cout<<"(I)inserciom\n";
    cout<<"(S)hell\n";
    cout<<"(Q)uick sort\n";
    cout<<"(M)erge sort\n";
    cout<<"(C)ubetas\n";
cin>>opcion1;	
switch(opcion1)
{
case 'b':
{
int operaciones =B.burbuja();
cout <<"METODO BURBUJA"<<"\n \n";
B.mostrar();
cout <<"cantidad de operaciones realizadas en burbuja "<<operaciones<<"\n \n";
B=A;
	}
	break;
case 'i':{
cout <<"METODO INSERCION"<<"\n \n";
int operaciones =B.insercion();
B.mostrar(); 
cout <<"cantidad de operaciones realizadas en Insercion "<<operaciones<<"\n \n";

B=A;
	
}
break;
case 's':{
cout <<"METODO SHELL"<<"\n \n";
int operaciones =B.shellsortv3();
B.mostrar();
cout <<"cantidad de operaciones realizadas en Shell "<<operaciones<<"\n \n";

B=A;	
}
break;

case 'q':{
cout <<"METODO QUICK SORT"<<"\n \n";
//quicksort(B,0,n-1);

B=A;	
}
break;



case 'm':{
cout <<"METODO MERGE SORT"<<"\n \n";
    int num;
 
    num = sizeof(A)/sizeof(int);
    cout<<num;

B=A;	
}
break;
default: cout<<"El valor ingresado no esta en el menu"<<endl;}
	
	
	
	break;
}


default: cout<<"El valor ingresado no esta en el menu"<<endl;
}
}while (a!=t);

}



