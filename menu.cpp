#include <iostream>
using namespace std;
class Arreglo {
	int tamanio;
	int *elemento;
	
	public:
		Arreglo(int);
		int busquedaSecuencial(int);
		int busquedaBinariaI(int);
		int buscarBinarioR(int,int,int);
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
int Arreglo::busquedaBinariaI(int numeroBusqueda)
{
	int primero = 0;
    int mitad;
    int ultimo = tamanio - 1;
 	bool validacion;
    while (primero <= ultimo) {
        mitad = (primero + ultimo) / 2;
 
        if (numeroBusqueda == elemento[mitad]) {
            cout << "Se encuentra en la posicion " << mitad + 1 << endl;
            validacion=true;
			primero=ultimo+1;//para que se acabe el while
        } else {
            if (elemento[mitad] > numeroBusqueda) {
                ultimo = mitad - 1;
            } else {
            	if(elemento[mitad] < numeroBusqueda)
            	{
                	primero = mitad + 1;
                }
                
            }
        }
        if(primero==ultimo)
        {
        	cout<<"No se encontro el dato en el arreglo \n";
		}
        
        
    }
    
    
	
 } 
int Arreglo::busquedaSecuencial(int numeroBusqueda)
{
	int i=0,aux=0,operacion=0;
	do
	{
		operacion++;
		if(elemento[i]==numeroBusqueda)
		{
			cout<<"El elemento se encuentra ubicado en la posicion "<<i+1<<" del arreglo \n";
			aux=1;
		}
		i++;
	}while(aux==0 && i<tamanio);
	if(aux==0)
	{
	cout<<"No se encontro el elemento en el arreglo \n";	
	}
	return operacion;
	
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
int Arreglo::buscarBinarioR(int izq,int der,int numeroBusqueda) 
{ 
		int op=0;
	//se encuentra la mitad del vector o intervalo 
	int mitad =(int)((izq+der)/2);
	//se verifica si el numero no esta en el arreglo
	op++;
	if((izq==der && elemento[mitad]!=numeroBusqueda) || elemento[der]<numeroBusqueda || elemento[izq]>numeroBusqueda)
	{
		cout<<"No se encuentra el dato en el arreglo \n";
		return op;
	}
	//caso-base de la recursividad -cuando se encuentra el dato buscado en el arreglo
	op++;
	if(elemento[mitad] == numeroBusqueda)
	{
		cout<<"El dato se encuentra en la posicion "<<mitad<<"\n";
		return op;
	}
	else
	{
		//verifica si el dato esta a la izquierda
		if(elemento[mitad]>numeroBusqueda)
		{
			return buscarBinarioR( izq , mitad-1 , numeroBusqueda);
		}else{
			return buscarBinarioR( mitad+1 , der ,numeroBusqueda);
		}
	}
	
} 

int main (){
	int n,validacionArreglo=0,numeroBuscado;
	char opcion,opcionBuscar,opcionOrdenar;
	 
	cout<<"--Bienvenido"<<"\n";
	cout <<"De que tamanio es el arreglo?\n";
	cin>>n;	
	Arreglo A(n),B(n),copia(n);
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
	validacionArreglo=1;
	break;
case 'M':
	if(validacionArreglo!=0)
	B.mostrar();
	else
	cout<<"POR FAVOR CARGUE PRIMERO EL ARREGLO\n";
	break;
case 'B':
	if(validacionArreglo!=0)
	{
	
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
	    		cout<<"POR FAVOR INGRESE EL DATO A BUSCAR EN EL ARREGLO: \n";
				cin>>numeroBuscado;
				cout<<"En la Busqueda Secuencial se realizaron "<<B.busquedaSecuencial(numeroBuscado)<<" operaciones fundamentales \n";
	    		break;
	    	case 'I':
	    		copia=B;
	    		copia.burbuja();
	    		cout<<"POR FAVOR INGRESE EL DATO A BUSCAR EN EL ARREGLO: \n";
				cin>>numeroBuscado;
				cout<<"En la Busqueda Binaria se realizaron "<<copia.busquedaBinariaI(numeroBuscado)<<" operaciones fundamentales \n";
	    		break;
	    	case 'B':
	    		copia=B;
	    		copia.burbuja();
	    		cout<<"POR FAVOR INGRESE EL DATO A BUSCAR EN EL ARREGLO: \n";
				cin>>numeroBuscado;
				cout<<"En la Busqueda Binaria se realizaron "<<copia.buscarBinarioR(0,n,numeroBuscado)<<" operaciones fundamentales \n";
	    		break;
	    	case 'R':
	    		break;
	    	default: cout<<"El valor ingresado no esta en el menu"<<endl;
		}
	    
		}while(opcionBuscar!='R');
	}
	else
	cout<<"POR FAVOR CARGUE PRIMERO EL ARREGLO"<<"\n";

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

}
				
	
	
	//op=	A.insercion();
	//A.mostrar();
	//cout<<"las operaciones realizadas son "<<op;
