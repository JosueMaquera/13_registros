#ifndef CONTACTO_H
#define CONTACTO_H

#include <string>
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

void leerCorreo(Correo &correo, string usuario, string dominio);
void leerContacto(ContactoEmail &contacto, string nombre, string sexo, int edad, Correo email);
void imprimeContacto(ContactoEmail &contacto);

#endif
