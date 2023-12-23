#include "api_v1_Usuario.h"
#include <string>
#include <list>
#include <json/json.h>
#include "models/UsuarioBE.h"
using namespace std;
using namespace api::v1;

list<UsuarioBE> lstTempUsuarios;

// Add definition of your processing function here
void Usuario::GetUsuario(const drogon::HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) {
    UsuarioBE usuarioBe;
    list<UsuarioBE> lstUsuarios;
    lstUsuarios = usuarioBe.GetDefaultList();


    Json::Value jsonUsuarios(Json::arrayValue);
    for(const UsuarioBE& usuario : lstUsuarios){
        Json::Value jsonUsuario;
        jsonUsuario["Nombre"] = usuario.Nombre;
        jsonUsuario["Apellido"] = usuario.Apellido;
        jsonUsuario["Email"] = usuario.Email;
        jsonUsuarios.append(jsonUsuario);
    }

    auto response = HttpResponse::newHttpJsonResponse(jsonUsuarios);
    callback(response);
}
void  Usuario::SaveUsuario(const drogon::HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) {
    Json::Value jsonResponse;
    Json::Value usuariosArray(Json::arrayValue);

    auto jsonArray = req->getJsonObject();
    if (jsonArray) {
        for (const auto &jsonObj : *jsonArray) {
            if (jsonObj.isMember("Nombre") && jsonObj.isMember("Apellido") && jsonObj.isMember("Email")) {
                // Obtener los valores de los campos
                string nombre = jsonObj["Nombre"].asString();
                string apellido = jsonObj["Apellido"].asString();
                string email = jsonObj["Email"].asString();

                UsuarioBE usuario;
                usuario.Nombre = nombre;
                usuario.Apellido = apellido;
                usuario.Email = email;
                lstTempUsuarios.push_back(usuario);

                Json::Value jsonUsuario;
                jsonUsuario["Nombre"] = nombre;
                jsonUsuario["Apellido"] = apellido;
                jsonUsuario["Email"] = email;

                usuariosArray.append(jsonUsuario);
            }
        }
    }
    jsonResponse["Usuarios"] = usuariosArray;
    // Crear una respuesta JSON con el arreglo de usuarios ingresados
    auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
    callback(response);
}
void  Usuario::GetTempUsuarios(const drogon::HttpRequestPtr &req,
                               std::function<void(const HttpResponsePtr &)> &&callback) {
    Json::Value jsonUsuarios(Json::arrayValue);
    for(const UsuarioBE& usuario : lstTempUsuarios){
        Json::Value jsonUsuario;
        jsonUsuario["Nombre"] = usuario.Nombre;
        jsonUsuario["Apellido"] = usuario.Apellido;
        jsonUsuario["Email"] = usuario.Email;
        jsonUsuarios.append(jsonUsuario);
    }

    auto response = HttpResponse::newHttpJsonResponse(jsonUsuarios);
    callback(response);
}