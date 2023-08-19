#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
//Trabajo realizado por Lucas Marchese (Lukjjz)
int main() {
	
	//definimos variables int
    int parametroMinimo, parametroMaximo, intentosRestantes, numRandom, numeroUsuario;
    
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
        cout << "Ingrese el parametro inicial (0 - 999): ";
        cin >> parametroMinimo;

        cout << "Ingrese el ultimo parametro (0 - 999): ";
        cin >> parametroMaximo;

    } while (parametroMinimo < 0 || parametroMinimo > 999 || parametroMaximo < 0 || parametroMaximo > 999 || parametroMinimo >= parametroMaximo);

    // Solicitamos ingreso de los intentos con los que desea jugar
    cout << "Ingrese la cantidad maxima de intentos: ";
    cin >> intentosRestantes;

    cout << endl << "Has ingresado los parametros " << parametroMinimo << " y " << parametroMaximo << " con " << intentosRestantes << " intentos para poder adivinar" << endl << endl << endl << endl;

    srand(static_cast<unsigned int>(time(0)));
	
	//generacion del numero random por parte del juego
    numRandom = parametroMinimo + (rand() % (parametroMaximo - parametroMinimo + 1));

	//variable int contador de intentos utilizados
	int intentosUtilizados = 0;

    do {
        cout << endl<<endl<<endl<< "Prueba tu suerte, tira un numero y acierta!: ";
        cin >> numeroUsuario;
		
		//verificacion que el numero ingresado este dentro de los parametros previamente fijados
        if (numeroUsuario < parametroMinimo || numeroUsuario > parametroMaximo) {
            cout << "El numero ingresado esta fuera de los parametros. Ingresa un numero valido." << endl;
        } else {
        	//decrece los intentos restantes, aumentamos los gastados.
            intentosRestantes--;
            intentosUtilizados++;
			
			//si gana
            if (numeroUsuario == numRandom) {
                cout << endl << endl << "¡Has adivinado! Felicitaciones." << endl << endl;
                break;
            //si se queda sin intentos
            } else if (intentosRestantes == 0) {
                cout << endl << endl << "Se acabaron los intentos." << endl << "El numero era: " << numRandom << endl << endl;
                cout << endl << endl << "GAME OVER GAME OVER GAME OVER GAME OVER GAME OVER" << endl<< "GAME OVER GAME OVER GAME OVER GAME OVER GAME OVER" << endl<< "GAME OVER GAME OVER GAME OVER GAME OVER GAME OVER" << endl<< "GAME OVER GAME OVER GAME OVER GAME OVER GAME OVER" << endl<< "GAME OVER GAME OVER GAME OVER GAME OVER GAME OVER" << endl<< "GAME OVER GAME OVER GAME OVER GAME OVER GAME OVER" << endl<< "GAME OVER GAME OVER GAME OVER GAME OVER GAME OVER" << endl<< "GAME OVER GAME OVER GAME OVER GAME OVER GAME OVER" << endl<< "GAME OVER GAME OVER GAME OVER GAME OVER GAME OVER" << endl<< "GAME OVER GAME OVER GAME OVER GAME OVER GAME OVER" << endl<< "GAME OVER GAME OVER GAME OVER GAME OVER GAME OVER" << endl<< "GAME OVER GAME OVER GAME OVER GAME OVER GAME OVER" << endl<< "GAME OVER GAME OVER GAME OVER GAME OVER GAME OVER" << endl<< "GAME OVER GAME OVER GAME OVER GAME OVER GAME OVER" << endl<< "GAME OVER GAME OVER GAME OVER GAME OVER GAME OVER" << endl;
                break;
            } else {
            	//Pistas de cercania 
                if (numeroUsuario < numRandom) {
                    cout <<endl<< "****** Tu numero es menor que mi numero. ******" << endl;
                } else {
                    cout << endl<<  "****** Tu numero es mayor que mi numero. ******" << endl;
                }
                //Mensaje de aliento e informativo sobre su estado de juego.
                cout << endl << "Has utilizado: " << intentosUtilizados << " intentos." << " Intentos restantes: " << intentosRestantes << ". Vuelve a intentarlo, tu puedes!"<< endl << endl;
            }
        }
    } while (intentosRestantes > 0);

    system("pause");
    return 0;
}



