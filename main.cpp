#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <ctype.h>
#include "menu.h"

using namespace std;

//variables globales--------
enum Tipos { Merlot,Cabernet,Malbet, Chardonnay,Sauvignon, Riesling,Rose,Merlot_Rose,Shiraz, Champagne};

struct Vinos{//stuct de Vinos
  int id;
  int Cosecha;
  double PR_Venta;
  string nombre;
  Tipos tipo;
  int botellas; 
};
typedef Vinos vino;

struct Pedido{//struct de pedidos
    int dui;
    string nombre;
    double total;
    bool pagado = false;
    vector <Vinos> lista_de_compras;
};
typedef Pedido pedido;

vector<Vinos>lista_vinos;
queue <Pedido> cola_pedidos; 

//variables globales--------

// Aqui todos los metodos de clientes

//menu de clientes
void clientes(){

}
// Aqui todos los metodos de inventario_de_vinos

// Aqui todos los metodos de pedidos

// Aqui todos los metodos de estadisticas

//menu de estadisticas
void estadisticas(){

}


int main()
{
   for(;;){
     int opt;
      menu();
      cin>>opt;
      switch(opt){
        case 1:
          clientes();
        break;
        case 2:
          pedidos();
        break;
        case 3:
          inventario();
        break;
        case 4:
          estadisticas();
        break;
        default:
          menu("Ingrese una opcion correcta:");
        break;
      }
   }
    
}
