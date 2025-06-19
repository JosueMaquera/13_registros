#include <iostream>
#include <string>

using namespace std;

struct Empleado {
    int numeroEmpleado;
    string nombre;
    float ventas[12];
    float salario;
    float ventasTotales;
};

int main() {
    int cantidadEmpleados;
    int indiceMayorVentas = 0;
    float mayorVentas;

    Empleado empleados[100];

    cout << "Ingresa el numero de empleados a registrar: ";
    cin >> cantidadEmpleados;

    for (int i = 0; i < cantidadEmpleados; i++) {
        cout << "\nIngrese los datos del empleado #" << i + 1 << endl;

        cout << "Numero de empleado: ";
        cin >> empleados[i].numeroEmpleado;
        cin.ignore();

        cout << "Nombre: ";
        getline(cin, empleados[i].nombre);

        empleados[i].ventasTotales = 0;

        cout << "Ingrese las ventas de los 12 meses:\n";
        for (int j = 0; j < 12; j++) {
            cout << "Mes " << j + 1 << ": ";
            cin >> empleados[i].ventas[j];
            empleados[i].ventasTotales += empleados[i].ventas[j];
        }

        cout << "Salario: ";
        cin >> empleados[i].salario;
    }

    mayorVentas = empleados[0].ventasTotales;

    for (int i = 0; i < cantidadEmpleados; i++) {
        if (empleados[i].ventasTotales > mayorVentas) {
            mayorVentas = empleados[i].ventasTotales;
            indiceMayorVentas = i;
        }
        
        cout << "\n-------- Empleado #" << i + 1 << " ----------" << endl;
        cout << "Numero de empleado: " << empleados[i].numeroEmpleado << endl;
        cout << "Nombre: " << empleados[i].nombre << endl;
        cout << "Ventas mensuales: ";
        for (int j = 0; j < 12; j++) {
            cout << empleados[i].ventas[j] << " ";
        }
        cout << "\nVentas totales: " << empleados[i].ventasTotales << endl;
        cout << "Salario: " << empleados[i].salario << endl;
    }

    cout << "\n-----------------------------------------" << endl;
    cout << "Empleado con mayor ventas anuales:" << endl;
    cout << "Numero de empleado: " << empleados[indiceMayorVentas].numeroEmpleado << endl;
    cout << "Nombre: " << empleados[indiceMayorVentas].nombre << endl;
    cout << "Ventas totales: " << empleados[indiceMayorVentas].ventasTotales << endl;

    return 0;
}

