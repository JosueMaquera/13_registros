#include<iostream>
#include<string>

using namespace std;

struct Correo {
    string usuario;
    string dominio;
};

struct ContactoEmail {
    string nombre;
    string sexo;
    int edad;
    Correo email;
};

void leerContacto(ContactoEmail &, string, string, int, Correo);
void leerCorreo(Correo &, string, string);
void imprimeContacto(ContactoEmail &);

int main() {

    int n,opcion, indice, edad;
    int i = 0;
    string nombre, sexo, usuario, dominio, contactoModificado;

    Correo email;
    ContactoEmail contacto, contactos[100];


    while (true) {

        cout << "\n----- MENU DE CONTACTOS -----\n";
        cout << "1. Agregar contacto\n";
        cout << "2. Modificar contacto\n";
        cout << "3. Mostrar lista de contactos\n";
        cout << "4. Mostrar contactos segun dominio\n";
        cout << "5. Eliminar contacto\n";
        cout << "6. Buscar contacto por correo\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1:
            cout << "Nombre: ";
            getline(cin, nombre);
            cout << "Sexo: ";
            getline(cin, sexo);
            cout << "Edad: ";
            cin >> edad;
            cin.ignore();
            cout << "Usuario: ";
            getline(cin, usuario);
            cout << "Dominio: ";
            getline(cin, dominio);
            
            leerCorreo(email, usuario, dominio);
            leerContacto(contacto, nombre, sexo, edad, email);

            contactos[i] = contacto;
            i += 1;
            
            break;
        
        case 2:
            cout << "Ingrese el nombre del contacto a modificar: ";
            getline(cin, contactoModificado);
            for (int j = 0; j < i; j++) {
                if (contactoModificado == contactos[j].nombre) {
                    cout << "Nombre: ";
                    getline(cin, nombre);
                    cout << "Sexo: ";
                    getline(cin, sexo);
                    cout << "Edad: ";
                    cin >> edad;
                    cin.ignore();
                    cout << "Usuario: ";
                    getline(cin, usuario);
                    cout << "Dominio: ";
                    getline(cin, dominio);

                    leerCorreo(email, usuario, dominio);
                    leerContacto(contacto, nombre, sexo, edad, email);

                    contactos[j] = contacto;
                    cout << "Contacto modificado" << endl;
                }
            }
            break;

        case 3:
            cout << "---------------------------------" << endl;
            for (int j = 0; j < i; j++) {
                cout << "Contacto #" << j + 1 << endl;
                imprimeContacto(contactos[j]);
                cout << "---------------------------------" << endl;
            }

            break;

        case 5:
            cout << "Ingrese el nombre del contacto a eliminar: ";
            getline(cin, contactoModificado);
            for (int j = 0; j < i; j++) {
                if (contactos[j].nombre == contactoModificado) {
                    for (int k = j; k < i - 1; k++) {
                        contactos[k] = contactos[k + 1];
                    }
                    i -= 1; 
                    cout << "Contacto eliminado" <<endl;
                    break; 
                }
            }
            break;

        case 0:
            return 0;

        default:
            cout << "INGRESE UNA DE LAS OPCIONES";
            break;
        }
    }
}

void leerContacto(ContactoEmail &contacto, string nombre, string sexo, int edad, Correo email) {
    contacto.nombre = nombre;
    contacto.sexo = sexo;
    contacto.edad = edad;
    contacto.email = email;
}

void leerCorreo(Correo &correo, string usuario, string dominio) {
    correo.usuario = usuario;
    correo.dominio = dominio;
}

void imprimeContacto(ContactoEmail &contacto) {
    cout << "Nombre: " << contacto.nombre << endl;
    cout << "Sexo: " << contacto.sexo << endl;
    cout << "Edad: " << contacto.edad << endl;
    cout << "Correo: " << contacto.email.usuario << "@" << contacto.email.dominio << endl;

}