#include <iostream> 
#include <vector> 
#include <stdlib.h>
#include <string>

using namespace std;

//Main menu Script(Just text)
void menu(string extra=""){
  printf("\033c");
  cout << endl;
  cout << "\n\tMenu Principal";
  cout << "\n\t1.Manejo de clientes";  
  cout << "\n\t2.Manejo de pedidos";
  cout << "\n\t3.Manejo de Inventario";
  cout << "\n\t4.Informacion de ganancias";
  cout << "\n\t5.Salir\n";
  if(extra==""){
   cout << "\n\tIngrese la opcion que desea ejecutar:";
  }else{cout << "\n\t"<<extra<<":";}
}


//Wines menu Script(Just text)
void menu_vinos(string extra= ""){
   printf("\033c");
   cout << endl;
   cout << "\n\tInventario";
   cout << "\n\t1.Agregar Vino";  
   cout << "\n\t2.Eliminar Vino";
   cout << "\n\t3.Mostrar Inventario";
   cout << "\n\t4.Actualizar informacion de un Vino";
   cout << "\n\t5.Salir\n";
}

void menu_pedidos(string extra=""){
  printf("\033c");
  cout << "\n\t --------Pedidos--------";
  cout << "\n\t1.Agregar Pedido";
  cout << "\n\t2.Mostrar Pedidos"; 
  cout << "\n\t3.Regresar";
  if(extra==""){
    cout << "\n\tIngrese la opcion que desea ejecutar:";
  }else{          cout << "\n\t"<<extra<<":";
  }
}
void menu_tipos_vinos(string extra=""){
  printf("\033c");
  cout << "\n\tTipo de vino :\n\t";
    cout << "\n\t-----------VINOS TINTOS----------\n\t";
    cout << "\n\tA -- Merlot\n\t";
    cout << "\n\tB -- Cabernet Sauvignon\n\t";
    cout << "\n\tC -- Malbec\n\t";
    cout << "\n\t-----------VINOS BLANCOS----------\n\t";
    cout << "\n\tD-- Chardonnay\n\t";
    cout << "\n\tE-- Sauvignon Blanc\n\t";
    cout << "\n\tF-- Riesling\n\t";
    cout << "\n\t-----------VINOS ROSAS----------\n\t";
    cout << "\n\tG-- Rose Pinot\n\t";
    cout << "\n\tH-- Merlot Rose\n\t";
    cout << "\n\t-----------VINOS ESPUMADOS----------\n\t";
    cout << "\n\tI-- Shiraz\n\t";
    cout << "\n\tJ-- Champagne\n\t";
    if(extra==""){
    cout << "\n\tIngrese el tipo de vino:\n\t";
    }else{          cout << "\n\t"<<extra<<":";
    }
}
