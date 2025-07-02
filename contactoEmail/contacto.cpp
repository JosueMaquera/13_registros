#include <iostream>
#include "contacto.h"

void leerCorreo(Correo &correo, string usuario, string dominio) {
    correo.usuario = usuario;
    correo.dominio = dominio;
}

void leerContacto(ContactoEmail &contacto, string nombre, string sexo, int edad, Correo email) {
    contacto.nombre = nombre;
    contacto.sexo = sexo;
    contacto.edad = edad;
    contacto.email = email;
}

void imprimeContacto(ContactoEmail &contacto) {
    cout << "Nombre: " << contacto.nombre << endl;
    cout << "Sexo: " << contacto.sexo << endl;
    cout << "Edad: " << contacto.edad << endl;
    cout << "Correo: " << contacto.email.usuario << "@" << contacto.email.dominio << endl;
}
