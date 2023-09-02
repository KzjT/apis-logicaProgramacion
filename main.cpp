#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale.h>
#include <set>

using namespace std;
//Trabajo realizado por Lucas Marchese (Lukjjz)


bool numeroExistente(int numero, int *array, int longitud) {
    for (int i = 0; i < longitud; i++) {
        if (array[i] == numero) {
            return true; // El número ya existe en el array
        }
    }
    return false; // El número no existe en el array
}

//funcion para mostrar numeros ingresados de forma dinamica
/*
void mostrarNumerosIngresados(const int *array, int longitud) {
	
    cout <<endl<< "-Números ingresados hasta ahora: ";
    for (int i = 0; i < longitud; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

*/

//funcion para desplegar asteriscos como separadores
void imprimirLineaAsteriscos(int longitud) {
    for (int i = 0; i < longitud; i++) {
        cout << "*";
    }
    cout << endl;
}


void imprimirLineaError(int longitud) {
    for (int i = 0; i < longitud; i++) {
        cout << "#";
    }
    cout << endl;
}


void ordenarNumerosUsuario(int *array, int longitud) {
    for (int i = 0; i < longitud - 1; i++) {
        for (int j = 0; j < longitud - i - 1; j++) {
            if (array[j] > array[j + 1]) {
            	
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}



int main() {
	setlocale(LC_ALL,"");
	
	//definimos variables int
    int parametroMinimo, parametroMaximo, intentosRestantes, numRandom, numeroUsuario;
    const int maxIntentos = 250;
    int numerosUsuarioContainer[maxIntentos];
    int numerosUsuarioContainerLength = 0;

    //variables string
    string name;
    
	//solicitamos ingresar nombre
    cout << "Ingresa tu nombre: ";
    cin >> name;
    
    //mensaje de bienvenida  
    cout << "Bienvenido al juego de Akinator numerico. Un gusto jugar contigo " << name<< endl << endl;
    

 do {
        cout << "A continuacion ingresa los parametros y cantidad de intentos que tendras para jugar conmigo" << endl << endl;

        // Solicitamos parametros minimo y maximo
        cout << "Ingrese el parametro inicial (1 - 999): ";
        cin >> parametroMinimo;

        cout << "Ingrese el ultimo parametro (1 - 999): ";
        cin >> parametroMaximo;

    } while (parametroMinimo < 1 || parametroMinimo > 999 || parametroMaximo < 1 || parametroMaximo > 999 || parametroMinimo >= parametroMaximo);

    // Solicitamos ingreso de los intentos con los que desea jugar
    
	
    

    // Solicitamos ingreso de los intentos con los que desea jugar
    do {
        cout << "Ingrese la cantidad maxima de intentos (hasta 250): ";
        cin >> intentosRestantes;
        
        if (intentosRestantes <= 0 || intentosRestantes > maxIntentos) {
            cout << "Ingrese un valor válido entre 1 y " << maxIntentos << "." << endl;
        }
    } while (intentosRestantes <= 0 || intentosRestantes > maxIntentos);	
    cout << endl << "Has ingresado los parametros " << parametroMinimo << " y " << parametroMaximo << " con " << intentosRestantes << " intentos para poder adivinar" << endl << endl << endl << endl;

    srand(time(0));
	
	//generacion del numero random por parte del juego
    numRandom = parametroMinimo + (rand() % (parametroMaximo - parametroMinimo + 1));

	//variable int contador de intentos utilizados
	int intentosUtilizados = 0;
	
	


    do {
    	imprimirLineaAsteriscos(50);
        cout << "Prueba tu suerte, tira un numero y acierta!: ";
        cin >> numeroUsuario;
        imprimirLineaAsteriscos(50);


		
		//verificacion que el numero ingresado este dentro de los parametros previamente fijados
        if (numeroUsuario < parametroMinimo || numeroUsuario > parametroMaximo ) {
             imprimirLineaError(100);
              imprimirLineaError(100);
               imprimirLineaError(100);
            cout << "[X] Error: El numero ingresado esta fuera de los parametros. Ingresa un numero valido." << endl;
             imprimirLineaError(100);
              imprimirLineaError(100);
               imprimirLineaError(100);
               
			//verificacion del numero ingresado por el usuario aplicando la funcion NumeroExistente
        } else if (numeroExistente(numeroUsuario, numerosUsuarioContainer, numerosUsuarioContainerLength)) {
             imprimirLineaError(100);
              imprimirLineaError(100);
               imprimirLineaError(100);
            cout << "[X] Error: El numero ya ha sido ingresado anteriormente. Ingresa un numero nuevo." << endl;
             imprimirLineaError(100);
              imprimirLineaError(100);
               imprimirLineaError(100);
               
        } else {
        	//agregamos numero al array
            numerosUsuarioContainer[numerosUsuarioContainerLength] = numeroUsuario;
            numerosUsuarioContainerLength++;
            

          ordenarNumerosUsuario(numerosUsuarioContainer, numerosUsuarioContainerLength);
			cout << "-Números Utilizados: ";
			for (int i = 0; i < numerosUsuarioContainerLength; i++) {
    		cout << numerosUsuarioContainer[i] << " ";
			}
			
 
 
        	//decrece los intentos restantes, aumentamos los gastados.
            intentosRestantes--;
            intentosUtilizados++;
			
			//si gana
            if (numeroUsuario == numRandom) {
                cout << endl << endl << "¡Has adivinado! Felicitaciones." << endl << endl;
                break;
            //si se queda sin intentos
            } else if (intentosRestantes == 0) {
                            imprimirLineaError(100);
              imprimirLineaError(100);
               imprimirLineaError(100);             imprimirLineaError(100);
              imprimirLineaError(100);
               imprimirLineaError(100);             imprimirLineaError(100);
              imprimirLineaError(100);
               imprimirLineaError(100); // Imprime una línea de asteriscos como separador
                cout << "GAME OVER GAME OVER GAME OVER GAME OVER GAME OVER" << endl
                    << "GAME OVER GAME OVER GAME OVER GAME OVER GAME OVER" << endl
                    << "GAME OVER GAME OVER GAME OVER GAME OVER GAME OVER" <<endl 
                   	<< "GAME OVER GAME OVER GAME OVER GAME OVER GAME OVER" << endl
                    << "GAME OVER GAME OVER GAME OVER GAME OVER GAME OVER" << endl
                    << "GAME OVER GAME OVER GAME OVER GAME OVER GAME OVER" << endl
                    << "GAME OVER GAME OVER GAME OVER GAME OVER GAME OVER" << endl
                    << "GAME OVER GAME OVER GAME OVER GAME OVER GAME OVER" << endl << "GAME OVER GAME OVER GAME OVER GAME OVER GAME OVER" << endl
                    << "GAME OVER GAME OVER GAME OVER GAME OVER GAME OVER" << endl << "GAME OVER GAME OVER GAME OVER GAME OVER GAME OVER" << endl
                    << "GAME OVER GAME OVER GAME OVER GAME OVER GAME OVER" << endl << "GAME OVER GAME OVER GAME OVER GAME OVER GAME OVER" << endl
                    << "GAME OVER GAME OVER GAME OVER GAME OVER GAME OVER" << endl << "GAME OVER GAME OVER GAME OVER GAME OVER GAME OVER" << endl;
               imprimirLineaError(100);
              imprimirLineaError(100);
               imprimirLineaError(100); 
              imprimirLineaError(100);
               imprimirLineaError(100); 
              imprimirLineaError(100);
               imprimirLineaError(100);
              imprimirLineaError(100);
     
                break;
            } else {
            	//Pistas de cercania 
                if (numeroUsuario < numRandom) {
                    cout <<endl<< "-Tu numero es menor que mi numero. " << endl;
                } else {
                    cout << endl<<  "-Tu numero es mayor que mi numero. " << endl;
                }
                //Mensaje de aliento e informativo sobre su estado de juego.
                cout << endl << "-Has utilizado: " << intentosUtilizados << " intentos." << " Intentos restantes: " << intentosRestantes <<endl<< endl << endl;
            }
        }
    } while (intentosRestantes > 0);
 
    system("pause");
    return 0;
}


