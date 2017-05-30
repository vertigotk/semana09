#include <iostream>
#include <vector>
#include<string>
#include<cstdlib>

//names spaces
using namespace std;

//Crear clases
struct TLlanta
{
  string marca;
  string perfiles;
  float radio;
  float espesor;
};

struct TMotor
{
 string marca;
 string modelo;
 float cilindrada;
 float potencia;
 float rpm;
    
};

struct TTimon
{
    string marca;
    string modelo;
    float radio;
};

struct TAsiento
{
    string material;
    string color;
};

class CAuto
{
    TMotor motor; //Relacion con ocurrencia 1 a 1
    TTimon timon; //Relaciion 1 a 1
    vector<TLlanta> listaLlantas; //Relacion uno a muchos
    vector<TAsiento> listaAsientos;//Relacion de uno a muchos

public:
   CAuto()
   {   //Crea cuatro llantas 
       for(int i=0; i < 4; i++)
            listaLlantas.push_back({"Dunlop", "60", 17, 10});
        //Crear 5 Asiento    
        for(int i=0; i<5; i ++)
        listaAsientos.push_back({"Cuero","Negro"});
        
        //TIMON
        timon.marca= "Mono";
        timon.modelo= "Deportivo";
        
        //Definimos el Motor
        motor.marca = " Roll Royce";
        motor.modelo = "V8";
        motor.rpm = 6000;
        motor.potencia = 300;
        motor.cilindrada = 400;
            
   }
   
   CAuto(int nLlantas, int nAsientos,TTimon timon, TMotor motor)
   {
       //Crea cuatro llantas 
       for(int i=0; i < nLlantas; i++)
            listaLlantas.push_back({"Dunlop", "60", 17, 10});
        //Crear 5 Asiento    
        for(int i=0; i< nAsientos; i ++)
        listaAsientos.push_back({"Cuero","Negro"});
        
        //Timon
        this->timon = timon;
        
        //Definimos el Motor
        this->motor = motor;
   }
   
};

//Programa principal
int main()
{
    CAuto estandar;     //4 ruedas, 5 asientos, timon , motor
    TTimon timon;
    timon.marca = "Pegaso";
    timon.modelo = "Deportivo";
    
    TMotor motor;
    motor.marca = "Ferrari";
    motor.modelo = "VB";
    motor.rpm = 6000;
    motor.potencia = 500;
    motor.cilindrada = 6000;
    
    CAuto personalizada (4, 2, timon, motor);
    
    
    
    return 0;
}