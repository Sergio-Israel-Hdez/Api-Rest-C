//
// Created by sergio on 09-17-23.
//

#ifndef FIRSTAPIREST_USUARIOBE_H
#define FIRSTAPIREST_USUARIOBE_H
#include <string>
#include <list>
using namespace std;
class UsuarioBE {
public:
    string Nombre;
    string Apellido;
    string Email;

    list<UsuarioBE> GetDefaultList(){
        list<UsuarioBE> lstUsuarios;
        for (int i = 1; i <= 60000; ++i) {
            UsuarioBE usuario;
            usuario.Nombre = "sergio"+to_string(i);
            usuario.Apellido = "flores"+ to_string(i);
            usuario.Email = "sergio@mail.com";
            lstUsuarios.push_back(usuario);
        }
        return  lstUsuarios;
    }
};


#endif //FIRSTAPIREST_USUARIOBE_H
