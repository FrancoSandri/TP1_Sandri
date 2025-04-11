#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 

using namespace std;

class EntidadOrganizativa{
private:
    string nombre;
    vector<EntidadOrganizativa*> subentidades;

public:
    EntidadOrganizativa(string nombre);
    virtual ~EntidadOrganizativa();

    void agregarSubentidad(EntidadOrganizativa* subentidad);
    int contarSubentidades();
    string getNombre() const;
    
};

class Empleado{
    private:
        string nombre;
        string puesto;
        int antiguedad;
        float salario;
    public:
        Empleado(string nombre, string puesto, int antiguedad, float salario);
        ~Empleado();

        string getNombre() const;
        string getPuesto() const;
        int getAntiguedad();
        bool updateSalario(float nuevoSalario);
        float getSalario();
};

class Manager: public Empleado{
    private:
        float bono;
        string level;
    public:
        Manager(string nombre, string puesto, int antiguedad, float salario, float bono, string level);
        bool updateBono(float nuevoBono);
        float getBono();
        bool setLevel(string nuevoLevel);
};

class GerenteBajo: public Manager{
    using Manager::Manager;
};

class LiderEquipo: public Manager{
    using Manager::Manager;
};

class GerenteAlto: public Manager{
    using Manager::Manager;
};

class GerenteMedio: public Manager{
    using Manager::Manager;
};

class Departamento: public Empleado{
    private:
        string nombre;
        string ubicacion;
        vector <Empleado*> empleados;
        int cantEmpleadosDepts;
    public: 
        Departamento(string nombre, string ubicacion, int cantEmpleadosDepts);
        ~Departamento();

        string getNombre();
        string getUbicacion();
        int contarEmpleados();
        vector<Empleado*> getEmployees();
        bool contratarEmpleado(Empleado* empleado);
        bool despedirEmpleado(Empleado* empleado);
       
};

class Empresa: public EntidadOrganizativa, public Departamento{
    private:
        string direccion;
        vector<Departamento*> departamentos;
    public:
        Empresa(string nombre, string ubicacion, int cantEmpleadosDepts, string direccion);
        ~Empresa();

        string getDireccion();
        Departamento* getDepByName(string nombre);
        vector<string> getDepNames();
        void agregarDepartamento(Departamento* departamento);

};

class CentralRegional:public EntidadOrganizativa{
    private:
        vector<string> paises;
        int cantEmpleados;
        vector<GerenteAlto*> gerentesAlto;
        vector<GerenteMedio*> gerentesMedio;
        vector<Empresa*> empresas;
    public:
        CentralRegional(string nombre, vector<string> paises, int cantEmpleados);
        ~CentralRegional();

        vector<string> getPaises();
        int getCantEmpleados();
        string getEmpNames();
        vector<GerenteAlto*> getGerenteAlto();
        vector<GerenteMedio*> getGerenteMedio();

        void agregarEmpresa(Empresa* empresa);
        void agregarGerenteAlto(GerenteAlto* gerente);
        void agregarGerenteMedio(GerenteMedio* gerente);

};