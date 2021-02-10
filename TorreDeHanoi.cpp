#include <iostream>

using namespace std;

//Declaración de los métodos
void comenzar(int[], int[], int[]);
void mostrarPila(int[], int[], int[]);
void menu(int[], int[], int[]);
void apilarA(int, int[]);
void apilarB(int, int[]);
void apilarC(int, int[]);
void desapilarA(int[]);
void desapilarB(int[]);
void desapilarC(int[]);
int consultarCimaA(int[]);
int consultarCimaB(int[]);
int consultarCimaC(int[]);

//Declaración de las variables globales.
int numDiscos, indiceCimaA, indiceCimaB, indiceCimaC;

int main(){
	int i = 0;
	cout<<"Ingrese el numero de discos con los que se jugara: ";
	cin>>numDiscos;
	int pilaA[numDiscos];
	int pilaB[numDiscos];
	int pilaC[numDiscos];
	
	comenzar(pilaA, pilaB, pilaC);
	mostrarPila(pilaA, pilaB, pilaC);
	
	do{
		menu(pilaA, pilaB, pilaC);
		i++;
	}while(i < 7);
	
	return 0;
}

void menu(int pilaA[], int pilaB[], int pilaC[]){
	int opcionDesapilar, opcionApilar;
	int e = 0;
	cout<<"Escoja la varilla a la que se le desapilara un disco: \n 1. A \n 2. B \n 3. C"<<endl;
	cin>>opcionDesapilar;
	cout<<"Escoja la varilla a la que se apilara un disco: \n 1. A \n 2. B \n 3. C"<<endl;
	cin>>opcionApilar;
	
	switch(opcionDesapilar){
		case 1:
			e = consultarCimaA(pilaA);
			break;
		case 2:
			e = consultarCimaB(pilaB);
			break;
		case 3: 
			e = consultarCimaC(pilaC);
			break;
	}
	
	switch(opcionApilar){
		case 1:
			apilarA(e, pilaA);
			break;
		case 2:
			apilarB(e, pilaB);
			break;
		case 3:
			apilarC(e, pilaC);
			break;
	}
	
	switch(opcionDesapilar){
		case 1:
			
			desapilarA(pilaA);
			break;
		case 2:
			desapilarB(pilaB);
			break;
		case 3: 
			desapilarC(pilaC);
			break;
	}
	
	mostrarPila(pilaA, pilaB, pilaC);
	
}

void comenzar(int pilaA[], int pilaB[], int pilaC[]){
	
	int num = numDiscos; //Esta varibale sirve como auxiliar para rellenar la pila A.
	
	for(int i = 0; i < numDiscos; i++){
		pilaA[i] = num;
		num = num - 1;
		pilaB[i] = numDiscos+1;
		pilaC[i] = numDiscos+1;
	}
	
	indiceCimaA = numDiscos;
	indiceCimaB = 0;
	indiceCimaC = 0;
}

void mostrarPila(int pilaA[], int pilaB[], int pilaC[]){
	for(int i = 0; i < indiceCimaA; i++){
		cout<<pilaA[i]<<" ";
	}
	
	cout<<endl;
	
	for(int i = 0; i < indiceCimaB; i++){
		cout<<pilaB[i]<<" ";
	}
	
	cout<<endl;
	
	for(int i = 0; i < indiceCimaC; i++){
		cout<<pilaC[i]<<" ";
	}
	
	cout<<"Cima A: "<<indiceCimaA<<endl;
	cout<<"Cima B: "<<indiceCimaB<<endl;
	cout<<"Cima C: "<<indiceCimaC<<endl;
}

void apilarA(int e, int p[]){
		if(indiceCimaA == numDiscos){
			cout<<"Espacio insuficiente"<<endl;
		}else{
			p[indiceCimaA] = e;
			indiceCimaA = indiceCimaA+1;
			/*
			if(p[indiceCimaA] < e){
				cout<<"El movimiento es incorrecto"<<endl;
			}else{
				p[indiceCimaA] = e;
				indiceCimaA = indiceCimaA+1;
			}*/
		}
}

void apilarB(int e, int p[]){
		if(indiceCimaB == numDiscos){
			cout<<"Espacio insuficiente"<<endl;
		}else{
			p[indiceCimaB] = e;
			indiceCimaB = indiceCimaB+1;
			/*if(p[indiceCimaB] < e){
				cout<<"El movimiento es incorrecto"<<endl;
			}else{
				p[indiceCimaB] = e;
				indiceCimaB = indiceCimaB+1;
			}*/
		}
}

void apilarC(int e, int p[]){
		if(indiceCimaC == numDiscos){
			cout<<"Espacio insuficiente"<<endl;
		}else{
			p[indiceCimaC] = e;
			indiceCimaC = indiceCimaC+1;
			/*
			if(p[indiceCimaC] < e){
				cout<<"El movimiento es incorrecto"<<endl;
			}else{
				p[indiceCimaC] = e;
				indiceCimaC = indiceCimaC+1;
			}*/
		}
}

void desapilarA(int p[]){
	if(indiceCimaA == 0){
		cout<<"Pila vacia"<<endl;
	}else{
		indiceCimaA = indiceCimaA-1;
	}
}

void desapilarB(int p[]){
	if(indiceCimaB == 0){
		cout<<"Pila vacia"<<endl;
	}else{
		indiceCimaB = indiceCimaB-1;
	}
}

void desapilarC(int p[]){
	if(indiceCimaC == 0){
		cout<<"Pila vacia"<<endl;
	}else{
		indiceCimaC = indiceCimaC-1;
	}
}

int consultarCimaA(int p[]){
	int e;
	if(indiceCimaA == 0){
		cout<<"Pila vacia"<<endl;
	}else{
		cout<<"indice cima A: "<<indiceCimaA<<endl;
		e = p[indiceCimaA-1];
	}
	
	return e;
}

int consultarCimaB(int p[]){
	int e;
	if(indiceCimaB == 0){
		cout<<"Pila vacia"<<endl;
	}else{
		e = p[indiceCimaB-1];
	}
	
	return e;
}

int consultarCimaC(int p[]){
	int e;
	if(indiceCimaC == 0){
		cout<<"Pila vacia"<<endl;
	}else{
		e = p[indiceCimaC-1];
	}
	
	return e;
}
