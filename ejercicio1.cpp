// Librerias 
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

// Namespaces
using namespace std;

// Crear clases contenidas
struct TPunto
{
    int x;
    int y;
};

// Creamos la clase contenedor
class CMapa
{
    string nombreArchivo;
    string ciudad;
    vector<TPunto> listaPuntos; // Relacion de 1 a muchos

public:

    // Declaracion de constructores
    CMapa ()
    {
        ciudad = "Lima";
        nombreArchivo = "datos.txt";
    }
    
    CMapa (string ciudad, string nombreArchivo)
    {
        this->ciudad = ciudad;
        this->nombreArchivo = nombreArchivo;
    }
    
    // Metodos de Procesamientos
    void agregarPunto(int x, int y)
    {
        listaPuntos.push_back({x,y});
        grabarArchivo();
    }
    
    void listarPuntos()
    {
        for (auto punto: listaPuntos)
            cout << "Punto  x, y = (" << punto.x << ", " << punto.y << ")" << endl;
    }
    
    void eliminarPuntoPorX(int x)
    {
        for (int i = listaPuntos.size() - 1; i >= 0; i--)
        {
            if (listaPuntos[i].x == x)
                listaPuntos.erase(listaPuntos.begin() + i);
        }
        grabarArchivo();
    }
    
    void grabarArchivo()
    {
        // Creando el archivo
        ofstream archivo(nombreArchivo);
        archivo << "posX, posY" << endl;
        for (auto punto: listaPuntos)
            archivo << punto.x << ", " << punto.y << endl;
        archivo.close();
    }
    
};

// Metodo menu
int menu()
{
    int opcion = 0;
    do
    {
        system ("clear");
        cout << "MENU" << endl;
        cout << string(4, '~') << endl << endl;
        
        cout << "1. Ingresar Puntos" << endl;
        cout << "2. Listar Puntos" << endl;
        cout << "3. Eliminar por Posicion X" << endl;
        
        cout << "0. Para salir" << endl << endl;
        cout << "Opcion : ";
        cin >> opcion;
    }
    while (opcion < 0 || opcion > 3);
    
    return opcion;
}

// Programa Principal
int main ()
{
    CMapa mapa;         // Mapa de Lima
    
    int opcion = 0;
    do
    {
        opcion = menu(); // Opcion del menu
        int x, y;
        
        // Creamos un switch de opciones
        switch(opcion)
        {
            case 1:     // Insertar Puntos
                system("clear");
                cout << "Ingrese el valor de X: "; cin >> x;
                cout << "Ingrese el valor de Y: "; cin >> y;
                mapa.agregarPunto(x, y);
                break;
            case 2:     // Listar Puntos
                system("clear");
                mapa.listarPuntos();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cin.get();
                break;
            case 3:     // Eliminar Puntos
                system("clear");
                cout << "Ingrese el X del punto a borrar : "; cin >> x;
                mapa.eliminarPuntoPorX(x);
                break;
        }
        
    }
    while (opcion != 0);
    
    return 0;
}