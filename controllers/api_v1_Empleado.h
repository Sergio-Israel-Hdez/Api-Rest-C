//
// Created by sergio on 11-04-23.
//

#ifndef FIRSTAPIREST_API_V1_EMPLEADO_H
#define FIRSTAPIREST_API_V1_EMPLEADO_H
#include <drogon/HttpController.h>

using namespace drogon;

class Empleado: public drogon::HttpController<Empleado>{
public:
    METHOD_LIST_BEGIN
        METHOD_ADD(Empleado::GetEmpleados,"/GetEmpleados",Get);
    METHOD_LIST_END

    void GetEmpleados(const HttpRequestPtr &req,std::function<void(const HttpResponsePtr &)> &&callback);
    void SaveEmpleado(const HttpRequestPtr &req,std::function<void(const HttpResponsePtr &)> &&callback);

};


#endif //FIRSTAPIREST_API_V1_EMPLEADO_H
