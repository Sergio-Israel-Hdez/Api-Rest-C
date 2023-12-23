//
// Created by sergio on 11-04-23.
//

#ifndef FIRSTAPIREST_EMPLEADOBE_H
#define FIRSTAPIREST_EMPLEADOBE_H
#include <string>
#include <list>
using namespace std;

class EmpleadoBE {
public:
    string Nombre;
    string Email;

    list<EmpleadoBE> GetDefaultList(){
        list<EmpleadoBE> lstUsuarios;
        for (int i = 1; i <= 60000; ++i) {
            EmpleadoBE usuario;
            usuario.Nombre = "sergio"+to_string(i);
            usuario.Email = "sergio@mail.com";
            lstUsuarios.push_back(usuario);
        }
        return  lstUsuarios;
    }
private:
};


#endif //FIRSTAPIREST_EMPLEADOBE_H
