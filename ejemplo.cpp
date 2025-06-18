#include<iostream>
#include<string>

using namespace std;

struct EMP {
    int numero_empleado;
    string nombre;
    float ventas[12];
    float salario;
};

int main () {
    
    int cantidad_empleados;
    EMP empleados[100];

    cout << "Ingresa el numero de empleados a registrar: ";
    cin >> cantidad_empleados;

    for (int i = 0; i < cantidad_empleados; i++) {

        cout << "Ingrese su numero de empleado: ";
        cin >> empleados[i].numero_empleado;
        cin.ignore();
        cout << "Ingrese su nombre: ";
        getline(cin, empleados[i].nombre);
        
        cout << "Ingrese sus ventas: " << endl;

        for (int j = 0; j < 12; j++) {
            cin >> empleados[i].ventas[j];
        }
        cout << "Ingrese su salario: ";
        cin >> empleados[i].salario;
    }
}
