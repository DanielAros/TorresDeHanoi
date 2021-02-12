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
bool esPilaVaciaA();
bool esPilaVaciaB();
bool esPilaVaciaC();

//Declaración de las variables globales.
int numDiscos, indiceCimaA, indiceCimaB, indiceCimaC, opcionDesapilar, opcionApilar;
bool finalizarJuego = false, pilaDesapilada = true, movimientoCorrecto = true;

int main(){
	//Reglas del juego
	cout<<"REGLAS DEL JUEGO:\n"<<"1.Puedes mover solamente un disco a la vez. \n2.Ningun disco puede estar encima de un disco mas pequeno."<<endl;
	cout<<"\nIngrese el numero de discos con los que se jugara: ";
	cin>>numDiscos;
	
	//Creación de las pilas. Representan las varillas A,B,C.
	int pilaA[numDiscos];
	int pilaB[numDiscos];
	int pilaC[numDiscos];
	
	comenzar(pilaA, pilaB, pilaC);//En este método se le asignan los valores a las pilas. 
	do{
		menu(pilaA, pilaB, pilaC);
	}while(finalizarJuego == false);
	
	return 0;
}

void comenzar(int pilaA[], int pilaB[], int pilaC[]){
	
	int num = numDiscos; //Esta varibale sirve como auxiliar para rellenar la pila A.
	
	for(int i = 0; i < numDiscos; i++){
		pilaA[i] = num;//En la posicion cero de la pilaA que es la inicial se tendra el numero mayor de disco
		num = num - 1;
		pilaB[i] = 0;//La pila A y B se llenan con un valor cero ya que estaran vacias.
		pilaC[i] = 0;
	}
	
	//Se inician los indices de la cima de cada pila, las pilas A,B tendran indices 
	indiceCimaA = numDiscos;
	indiceCimaB = 0;
	indiceCimaC = 0;
}

void menu(int pilaA[], int pilaB[], int pilaC[]){
	int e;
	pilaDesapilada = true;
	movimientoCorrecto = true;
	
	system("cls");
	mostrarPila(pilaA, pilaB, pilaC);//Método que muestra en consola las pilas.
	cout<<"Escoja la varilla a la que se le desapilara un disco: \n 1. A \n 2. B \n 3. C"<<endl;
	cin>>opcionDesapilar;
	cout<<"Escoja la varilla a la que se apilara un disco: \n 1. A \n 2. B \n 3. C"<<endl;
	cin>>opcionApilar;
	
	switch(opcionDesapilar){//De acuerdo a la opcion elegida para desapilar, se recoge el elemento que esta en la cima y posteriormente se desapila el elemento. 
		case 1:
			e = consultarCimaA(pilaA);
			desapilarA(pilaA);
			break;
		case 2:
			e = consultarCimaB(pilaB);
			desapilarB(pilaB);
			break;
		case 3: 
			e = consultarCimaC(pilaC);
			desapilarC(pilaC);
			break;
	}
	
	//De acuerdo a la opcion elegida para apilar, se pasara el elemento que se recogio de desapilar y se le pasa como paramentro junto a la pila correspondiente.
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
	
	//Si se apila un elemento en una pila llena, entonces el elemento desapilado de la pila a despilar se devuelve a su lugar. 
	if(movimientoCorrecto == false){
		if(opcionDesapilar == 1){
			apilarA(e, pilaA);
		}else if(opcionDesapilar == 2){
			apilarB(e, pilaB);
		}else{
			apilarC(e, pilaC);
		}
	}
	
	mostrarPila(pilaA, pilaB, pilaC);//Se muestra las pilas ya modificadas.
	int op;
	cout<<"Desea terminar el juego: 1.Si 2.No: ";
	cin>>op;
	
	if(op == 1){
		finalizarJuego = true;
	}
}

void mostrarPila(int pilaA[], int pilaB[], int pilaC[]){
	int aux = numDiscos-1;//Esta variable es auxiliar para mostrar ascendentemente los valores que almacena cada posicion de la pila.
	cout<<"A"<<" B"<<" C"<<endl;
	for(int i = 0; i < numDiscos; i++){
		cout<<pilaA[aux]<<" "<<pilaB[aux]<<" "<<pilaC[aux]<<endl;
		aux = aux-1;
	}
}

void apilarA(int e, int p[]){
	if(indiceCimaA == numDiscos){
		cout<<"Espacio insuficiente"<<endl;
	}else{
		if(pilaDesapilada){ //Si la pila en la que se desapilo el elemento no se encuentra llena o vacia se procede a apilar, de lo contrario no se apila.
			if(p[indiceCimaA-1] < e){
				if(esPilaVaciaA()){
					p[indiceCimaA] = e;
					indiceCimaA = indiceCimaA+1;
				}else{
					cout<<"El movimiento es incorrecto"<<endl;
					movimientoCorrecto = false;
				}
			}else{
				p[indiceCimaA] = e;
				indiceCimaA = indiceCimaA+1;
			}
		}
	}
}

void apilarB(int e, int p[]){
	if(indiceCimaB == numDiscos){
		cout<<"Espacio insuficiente"<<endl;
	}else{
		if(pilaDesapilada){//Si la pila en la que se desapilo el elemento no se encuentra llena o vacia se procede a apilar, de lo contrario no se apila.
			if((p[indiceCimaB-1] < e)){
				if(esPilaVaciaB()){
					p[indiceCimaB] = e;
					indiceCimaB = indiceCimaB+1;
				}else{
					cout<<"El movimiento es incorrecto"<<endl;
					movimientoCorrecto = false;
				}
			}else{
				p[indiceCimaB] = e;
				indiceCimaB = indiceCimaB+1;
			}
		}
	}
}

void apilarC(int e, int p[]){
	if(indiceCimaC == numDiscos){
		cout<<"Espacio insuficiente"<<endl;
	}else{
		if(pilaDesapilada){//Si la pila en la que se desapilo el elemento no se encuentra llena o vacia se procede a apilar, de lo contrario no se apila.
			if(p[indiceCimaC-1] < e){
				if(esPilaVaciaC()){
					p[indiceCimaC] = e;
					indiceCimaC = indiceCimaC+1;
				}else{
					cout<<"El movimiento es incorrecto"<<endl;
					movimientoCorrecto = false;
				}
			}else{
				p[indiceCimaC] = e;
				indiceCimaC = indiceCimaC+1;
			}
		}
	}
}

void desapilarA(int p[]){
	if(esPilaVaciaA()){
		cout<<"Pila vacia"<<endl;
		pilaDesapilada = false;
	}else{
		p[indiceCimaA-1] = 0;
		indiceCimaA = indiceCimaA-1;
	}
}

void desapilarB(int p[]){
	if(esPilaVaciaB()){
		cout<<"Pila vacia"<<endl;
		pilaDesapilada = false;
	}else{
		p[indiceCimaB-1] = 0;
		indiceCimaB = indiceCimaB-1;
	}
}

void desapilarC(int p[]){
	if(esPilaVaciaC()){
		cout<<"Pila vacia"<<endl;
		pilaDesapilada = false;
	}else{
		p[indiceCimaC-1] = 0;
		indiceCimaC = indiceCimaC-1;
	}
}

int consultarCimaA(int p[]){
	int e;
	if(esPilaVaciaA()){
		cout<<"Pila vacia"<<endl;
	}else{
		e = p[indiceCimaA-1];
	}
	return e;
}

int consultarCimaB(int p[]){
	int e;
	if(esPilaVaciaB()){
		cout<<"Pila vacia"<<endl;
	}else{
		e = p[indiceCimaB-1];
	}	
	return e;
}

int consultarCimaC(int p[]){
	int e;
	if(esPilaVaciaC()){
		cout<<"Pila vacia"<<endl;
	}else{
		e = p[indiceCimaC-1];
	}
	return e;
}

bool esPilaVaciaA(){
	
	return indiceCimaA == 0;
}

bool esPilaVaciaB(){
	
	return indiceCimaB == 0;
}

bool esPilaVaciaC(){
	
	return indiceCimaC == 0;
}
