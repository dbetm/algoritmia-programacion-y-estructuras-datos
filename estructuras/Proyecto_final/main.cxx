#include "header.h"
#include "persona.cxx"
#include "hash.cpp"
#include "validator.cpp"

void menu();
int menuOp();
long long int hashing(long int);
int valida();

int main(int argc, char const *argv[]) {
    Cliente A[100];
    Nodo *Aux;
    string nombre;
    string apellido;
    int edad;
    unsigned int clabe;
    bool opt = true; //para controlar el ciclo do-while
    int opcion, index, optTrans; //optTrans = elegir la opción de la transacción
    double monto; //para las transacciones

    do {
        system("clear");
        menu();
        opcion = valida();

        switch(opcion) {
            case 1:
                do {
                    system("clear");
                    cout << "\n\tAGREGANDO NUEVO CLIENTE\n" << endl;
                    cout << "\nClabe de 4 dígitos: ";
                    do {
                        clabe = valida();
                        if(clabe < 1000 or clabe > 9999) {
                            system("clear");
                            cout << "\n\tAGREGANDO NUEVO CLIENTE\n" << endl;
                            cout << "!La clabe debe tener 4 digítos!" << endl;
                            cout << "\nClabe de 4 dígitos: ";
                        }
                    } while(clabe < 1000 or clabe > 9999);

                    index = hashing(clabe);

                    Aux = A[index].buscarCliente(clabe);
                    if(Aux != NULL) {
                        system("clear");
                        cout << "\n\tAGREGANDO NUEVO CLIENTE" << endl;
                        cout << "\nClabe de 4 dígitos: " << clabe << endl;
                        cout << "ERROR: Clabe en uso." << endl;
                        cout << "Enter para continuar...";
                        cin.get();
                    }
                    else {
                        system("clear");
                        cout << "\n\tAGREGANDO NUEVO CLIENTE\n" << endl;
                        cout << "\nClabe de 4 dígitos: " << clabe << endl;
                    }
                } while(Aux != NULL);

                cout << "Nombre: ";
                getline(cin, nombre, '\n');

                cout << "Apellido: ";
                getline(cin, apellido, '\n');

                cout << "Edad: ";
                edad = valida();

                A[index].insertarDatos(nombre, clabe, apellido, edad);
                break;
            case 2:
                system("clear");
                cout << "\tREGISTROS" << endl;
                numerador = 1;
                for (int i = 0; i < 100; i++) {
                    A[i].mostrarRegistros();
                }
                if(numerador == 1) cout << "\nTodavía no hay registros.\n" << endl;
                break;
            case 3:
                cout << "Ingrese la clabe del cliente: ";
                clabe = valida();
                cout << endl;
                index = hashing(clabe);
                A[index].buscarCliente(clabe);
                cout << endl;
                break;
            case 4:
                cout << "Ingrese la clabe del cliente: ";
                clabe = valida();
                index = hashing(clabe);
                A[index].eliminarCliente(clabe);
                break;
            case 5:
                cout << "Ingrese la clabe del cliente: ";
                clabe = valida();
                index = hashing(clabe);
                A[index].actualizarDatos(clabe);
                break;
            case 6:
                system("clear");
                cout << "\n\tTRANSACCIONES BANCARIAS\n" << endl;
                cout << "\nPara continuar ingrese su clabe ->> ";
                clabe = valida();
                index = hashing(clabe);
                Aux = A[index].buscarCliente(clabe);
                if(Aux != NULL) {
                    do {
                        system("clear");
                        optTrans = menuOp();
                        if(optTrans == 1) {
                            cout << "Ingresa la cantidad a depositar: ";
                            monto = valida();
                            A[index].depositar(monto, Aux);
                        }
                        else if(optTrans == 2) {
                            cout << "Ingresa la cantidad a retirar: ";
                            monto = valida();
                            A[index].retirar(monto, Aux);
                        }
                        else if(optTrans == 3) {
                            cout << "Su saldo actual es de: $" << A[index].consultaSaldo(Aux) << endl << endl;
                        }
                        else if(optTrans == 4){
                            break;
                        }
                        else {
                            cout << "Opción no válida" << endl;
                        }
                        cout << "Presione una tecla para continuar...";
                        cin.get();
                    } while(true);
                }
                break;
            case 7:
                opt = false;
                break;
            default:
                cout << "Opción no válida" << endl;
        }
        cout << "Presione una tecla para continuar...";
        cin.get();
    } while(opt);
    cout << endl;
    return 0;
}

void menu() {
    cout << "\n\tMENÚ PRINCIPAL" << endl;
    cout << "1. Agregar nuevo registro." << endl;
    cout << "2. Ver registros." << endl;
    cout << "3. Buscar cliente." << endl;
    cout << "4. Eliminar cliente." << endl;
    cout << "5. Editar datos del cliente" << endl;
    cout << "6. Transacciones bancarias" << endl;
    cout << "7. Salir." << endl;
    cout << "\n>>> ";
}

int menuOp() {
    int opcion;
    cout << "\n\tOPERACIONES DISPONIBLES\n" << endl;
    cout << "1. Depósito." << endl;
    cout << "2. Retiro." << endl;
    cout << "3. Consultar saldo actual." << endl;
    cout << "4. Volver al menú principal." << endl;
    cout << "\n>>> ";
    opcion = valida();
    return opcion;
}
