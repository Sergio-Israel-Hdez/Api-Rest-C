//
// Created by sergio on 11-04-23.
//
#include "api_v1_Usuario.h"
#include <string>
#include <list>
#include <json/json.h>
#include "api_v1_Empleado.h"
#include "models/EmpleadoBE.h"

using namespace std;
using namespace api::v1;

list<EmpleadoBE> lstTempEmpleado;

void Empleado::GetEmpleados(const drogon::HttpRequestPtr &req,
                            std::function<void(const HttpResponsePtr &)> &&callback) {
    EmpleadoBE empleadoBe;
    list<EmpleadoBE> lstEmpleados;
    lstEmpleados = empleadoBe.GetDefaultList();

    Json::Value jsonEmpleados(Json::arrayValue);
    for (const EmpleadoBE& empleado:lstEmpleados) {
        Json::Value jsonEmpleado;
        jsonEmpleado["Nombre"] = empleado.Nombre;
        jsonEmpleado["Email"] = empleado.Email;
        jsonEmpleados.append(jsonEmpleado);
    }
    auto response = HttpResponse::newHttpJsonResponse(jsonEmpleados);
    callback(response);
}

