#include "ejercicio1.h"

//Entidad Organizativa

EntidadOrganizativa::EntidadOrganizativa(string nombre):nombre(nombre){};

EntidadOrganizativa::~EntidadOrganizativa(){
    for (auto subentidad : subentidades) {
        delete subentidad;
    }
    subentidades.clear();
};

void EntidadOrganizativa::agregarSubentidad(EntidadOrganizativa* subentidad){
    subentidades.push_back(subentidad);
};

int EntidadOrganizativa::contarSubentidades(){
    return subentidades.size();
};

string EntidadOrganizativa::getNombre() const{
    return nombre;
};

//Empleado

Empleado::Empleado(string nombre, string puesto, int antiguedad, float salario):
    nombre(nombre), puesto(puesto), antiguedad(antiguedad), salario(salario){};

Empleado::~Empleado(){};

int Empleado::getAntiguedad(){
    return antiguedad;
};

bool Empleado::updateSalario(float nuevoSalario){
    if(nuevoSalario > 0){
        salario = nuevoSalario;
        return true;
    };
    return false;
};

float Empleado::getSalario(){
    return salario;
};

string Empleado::getNombre() const{
    return nombre;
};

string Empleado::getPuesto() const{
    return puesto;
};

//Manager

Manager::Manager(string nombre, string puesto, int antiguedad, float salario, float bono, string level):
    Empleado(nombre, puesto, antiguedad, salario), bono(bono), level(level){};

bool Manager::updateBono(float nuevoBono){
    if(nuevoBono > 0){
        bono = nuevoBono;
        return true;
    }
    return false;
};

float Manager::getBono(){
    return bono;
};

bool Manager::setLevel(string nuevoLevel){
    if(!nuevoLevel.empty()){
        level = nuevoLevel;
        return true;
    };
    return false;
};

//Departamento

Departamento::Departamento(string nombre, string ubicacion, int cantEmpleadosDepts):
    Empleado("","",0,0),nombre(nombre), ubicacion(ubicacion), cantEmpleadosDepts(cantEmpleadosDepts){};

Departamento::~Departamento(){
    for (auto e : empleados) {
        delete e;
    }
    empleados.clear();
};

string Departamento::getNombre(){
    return nombre;
};

string Departamento::getUbicacion(){
    return ubicacion;
};

int Departamento::contarEmpleados(){
    return empleados.size();
};

vector<Empleado*> Departamento::getEmployees(){
    return empleados;
};

bool Departamento::contratarEmpleado(Empleado* empleado){
    if(empleados.size() < static_cast<size_t>(cantEmpleadosDepts)){
        empleados.push_back(empleado);
        return true;
    };
    return false;
};

bool Departamento::despedirEmpleado(Empleado* empleado){
    auto it = find(empleados.begin(), empleados.end(), empleado);
    if(it != empleados.end()){
        empleados.erase(it);
        return true;
    };
    return false;
};

//Empresa

Empresa::Empresa(string nombre, string ubicacion, int cantEmpleadosDepts, string direccion)
    : EntidadOrganizativa(nombre), Departamento(nombre, ubicacion, cantEmpleadosDepts), direccion(direccion) {}


Empresa::~Empresa(){
    for (auto d : departamentos) {
        delete d;
    }
    departamentos.clear();
};

string Empresa::getDireccion(){
    return direccion;
};

Departamento* Empresa::getDepByName(string nombre){
    for (auto d : departamentos) {
        if (d->getNombre() == nombre) return d;
    }
    return nullptr;
};

vector<string> Empresa::getDepNames(){
    vector<string> depNames;
    for (auto d : departamentos) {
        depNames.push_back(d->getNombre());
    }
    return depNames;
};

void Empresa::agregarDepartamento(Departamento* departamento) {
    departamentos.push_back(departamento);
}

//Central Regional

CentralRegional::CentralRegional(string nombre, vector<string> paises, int cantEmpleados):
    EntidadOrganizativa(nombre), paises(paises), cantEmpleados(cantEmpleados){};

    CentralRegional::~CentralRegional() {
        for (auto g : gerentesAlto) delete g;
        for (auto g : gerentesMedio) delete g;
        for (auto e : empresas) delete e;
        gerentesAlto.clear();
        gerentesMedio.clear();
        empresas.clear();
    }

vector<string> CentralRegional::getPaises(){
    return paises;
};

int CentralRegional::getCantEmpleados(){
    return cantEmpleados;
};

string CentralRegional::getEmpNames() {
    string nombres;
    for (Empresa* empresa : empresas) {
        vector<string> nombresDeptos = empresa->getDepNames();
        for (const string& nombreDep : nombresDeptos) {
            Departamento* dep = empresa->getDepByName(nombreDep);
            if (dep) {
                vector<Empleado*> empleados = dep->getEmployees();
                for (Empleado* e : empleados) {
                    nombres += e->getNombre() + " ";
                }
            }
        }
    }
    return nombres;
}

vector<GerenteAlto*> CentralRegional::getGerenteAlto(){
    return gerentesAlto;
}

vector<GerenteMedio*> CentralRegional::getGerenteMedio(){
    return gerentesMedio;
}

void CentralRegional::agregarEmpresa(Empresa* empresa) {
    empresas.push_back(empresa);
    agregarSubentidad(empresa);
}

void CentralRegional::agregarGerenteAlto(GerenteAlto* g) {
    if (gerentesAlto.size() < 5) gerentesAlto.push_back(g);
}

void CentralRegional::agregarGerenteMedio(GerenteMedio* g) {
    if (gerentesMedio.size() < 20) gerentesMedio.push_back(g);
}

int main() {
    // Crear empleados
    Empleado* emp1 = new Empleado("Juan", "Analista", 2, 50000);
    Empleado* emp2 = new Empleado("Lucia", "Desarrollador", 3, 55000);

    // Crear managers
    GerenteBajo* gerenteBajo = new GerenteBajo("Carlos", "Jefe de Sector", 4, 60000, 3000, "Junior");
    LiderEquipo* liderEquipo = new LiderEquipo("Mariana", "Lider de Proyecto", 5, 65000, 4000, "Medio");
    GerenteAlto* gerenteAlto1 = new GerenteAlto("Roberto", "Director", 8, 90000, 8000, "Senior");
    GerenteMedio* gerenteMedio1 = new GerenteMedio("Ana", "Subdirectora", 6, 80000, 6000, "Senior");

    // Crear departamentos
    Departamento* depto1 = new Departamento("Sistemas", "Buenos Aires", 5);
    Departamento* depto2 = new Departamento("RRHH", "Córdoba", 3);

    // Contratar empleados
    depto1->contratarEmpleado(emp1);
    depto1->contratarEmpleado(emp2);
    depto1->contratarEmpleado(gerenteBajo);
    depto1->contratarEmpleado(liderEquipo);

    depto2->contratarEmpleado(gerenteAlto1);
    depto2->contratarEmpleado(gerenteMedio1);

    // Crear empresa y agregar departamentos
    Empresa* empresa1 = new Empresa("TechCorp", "Buenos Aires", 10, "Av. Siempre Viva 123");
    empresa1->agregarDepartamento(depto1);
    empresa1->agregarDepartamento(depto2);

    // Crear central regional
    vector<string> paises = {"Argentina", "Uruguay"};
    CentralRegional* central = new CentralRegional("Cono Sur", paises, 6);
    central->agregarEmpresa(empresa1);
    central->agregarGerenteAlto(gerenteAlto1);
    central->agregarGerenteMedio(gerenteMedio1);

    // Mostrar datos
    cout << "Central: " << central->getNombre() << std::endl;
    cout << "Paises: ";
    for (const auto& pais : central->getPaises()) {
        cout << pais << " ";
    }
    cout << endl;

    cout << "Cantidad de empleados en la central: " << central->getCantEmpleados() << endl;
    cout << "Empleados en empresas: " << central->getEmpNames() << endl;

    cout << "Gerentes Alto: ";
    for (auto* g : central->getGerenteAlto()) {
        cout << g->getNombre() << " ";
    }
    cout << endl;

    cout << "Gerentes Medio: ";
    for (auto* g : central->getGerenteMedio()) {
        cout << g->getNombre() << " ";
    }
    cout << endl;

    cout << "Departamentos en empresa: ";
    for (const auto& depName : empresa1->getDepNames()) {
        cout << depName << " ";
    }
    cout << endl;

    cout << "Ubicación de departamento 'Sistemas': " << empresa1->getDepByName("Sistemas")->getUbicacion() << endl;

    return 0;
}