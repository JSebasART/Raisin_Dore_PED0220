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
void mostrarlistadepedidos(vector <Vinos> listadevinos){
    if (listadevinos.size() == 0){
        cout << "\n\tLa lista esta vacia" << endl;
    }
    else{
        for (int i = 0; i < listadevinos.size(); i++){
            cout << "\n=========================================================================\n";
            cout << "\tCodigo: " << listadevinos[i].id << endl;
            cout << "\tNombre: " << listadevinos[i].nombre << endl;
            cout << "\tCosecha: " << listadevinos[i].Cosecha << endl;
            cout << "\tTipo: ";
           
            switch (listadevinos[i].tipo){
               case Merlot: cout << "Merlot" << endl; break;
               case Cabernet: cout << "Cabernet Sauvignon" << endl; break;
               case Malbet: cout << "Malbet" << endl; break;
               case Chardonnay: cout << "Chardonnay" << endl; break;
               case Sauvignon: cout << "Sauvignon Blanc" << endl; break;
               case Riesling: cout <<" Riesling" << endl; break;
               case Rose: cout << "Rose Pinot" << endl; break;
               case Merlot_Rose: cout << "Merlot Rose" << endl; break;
               case Shiraz: cout << "Shiraz" << endl; break;
               case Champagne: cout << "Champagne" << endl; break;
            }
            
            cout << "\tPrecio por botella: $" << listadevinos[i].PR_Venta;
            cout << "\n=========================================================================\n";
            cout << endl;
        }
    }
}

void Mostrapedidos(){
    queue <Pedido> aux = cola_pedidos;
    if (aux.empty()){
        cout << "\tCola de pedidos vacia" << endl;
    }
    else{
        while (!aux.empty()){
            Pedido aux1 = aux.front();
            cout << "\tNombre del cliente: " << aux1.nombre << endl;
            cout << "\tDUI: " << aux1.dui << endl;
            cout << "\tTotal del cliente: $" << aux1.total << endl;
            cout << "\tEstado del pedido: ";
            
            if (aux1.pagado == true){
                cout << "Cancelado" << endl;
            }
            else{
                cout << "Sin cancelar" << endl;
            }
            cout << "\tMostrando la descripcion de los productos: ";
            mostrarlistadepedidos (aux1.lista_de_compras);
            aux.pop();
            cout << "\n";
        }
    }
}

double CobrarClientes (vector <Vinos> list){
    double suma_total = 0;
    Vinos aux1;
    if (list.size() == 0){
        cout << "\tNo hay productos en la lista" << endl;
    }
    else{
        for (int i = 0; i < list.size() ; i++){
            suma_total += list[i].PR_Venta;
        }
    }
    return suma_total;
}

void borrarPorCodigo (vector <Vinos> &listaProductos, int codigo){
    Vinos aux;
    bool encontrado = false;

    if (listaProductos.empty()){
        cout << "\tNo hay productos en la lista" << endl;
        return;
    }
    else{
        for (int pos = 0; pos < listaProductos.size(); pos++){
            aux =listaProductos.at(pos);
             
            if (aux.id == codigo){
                encontrado = true;

                listaProductos.erase(listaProductos.begin() + pos);

                cout << "\tSe borro el producto correctamente" << endl;
                break;
            }
        }
        int codigo = aux.id;
        
        for (auto iter = lista_vinos.begin(); iter != lista_vinos.end(); ++iter){
            if (iter->id == codigo){
            iter->botellas += 1;
        }
    }
 
        if (encontrado == false){
            cout << "\tNo habia ningun producto con ese codigo" << endl;
        }
    }
}

void mostrarVino (Vinos a){
    cout << "\n=========================================================================\n";
    cout << "\tCodigo: " << a.id << endl;
    cout << "\tNombre: " << a.nombre << endl;
    cout << "\tCosecha: " << a.Cosecha << endl;
    cout << "\tTipo: ";

    switch (a.tipo){
        case Merlot: cout << "Merlot" << endl; break;
        case Cabernet: cout << "Cabernet Sauvignon" << endl; break;
        case Malbet: cout << "Malbet" << endl; break;
        case Chardonnay: cout << "Chardonnay" << endl; break;
        case Sauvignon: cout << "Sauvignon Blanc" << endl; break;
        case Riesling: cout << "Riesling" << endl; break;
        case Rose: cout << "Rose Pinot" << endl; break;
        case Merlot_Rose: cout << "Merlot Rose" << endl; break;
        case Shiraz: cout << "Shiraz" << endl; break;
        case Champagne: cout << "Champagne" << endl; break;
    }
    cout << "\tBotellas disponibles: " << a.botellas << endl;
    cout << "\tPrecio por botella: $" << a.PR_Venta;
    cout << "\n=========================================================================\n";
    cout << endl;
}

void modificarbotellas (Vinos aux){
    int codigo = aux.id;

    for (auto iter = lista_vinos.begin(); iter != lista_vinos.end(); ++iter){
        if (iter->id == codigo){
            iter->botellas -= 1;
        }
    }
}

void MostrarInventarioparaVenta (vector <Vinos> &Listadeclientes){
    int cont = 1, opcion;
    cout << "\t\n----Mostrando vinos disponibles en el inventario ----" << endl;
    for (int i = 0; i < lista_vinos.size(); i++){
        cout << "(" << cont << ")";
        mostrarVino (lista_vinos.at(i));
        cont++;
    }

    cout << "\n\tQue vinos desea adquirir? (Ingrese el numero ubicado en la parte superior): "; cin >> opcion; cin.ignore();
    Vinos Vinoseleccionado = lista_vinos.at(opcion - 1);
    modificarbotellas(Vinoseleccionado);
    Listadeclientes.push_back(Vinoseleccionado);
}

void llenandoPedido(){
    vector <Vinos> lista_compras;
    string nombre;
    Vinos aux;
    int dui, id; double total;
    pedido llenando;
    bool status = true;

    cout << "\tIngrese el nombre del cliente: "; getline (cin, llenando.nombre);
    cout << "\tIngrese el DUI del cliente: "; cin >> llenando.dui; cin.ignore();

    while(status){
        cout << "\n\t-------Carrito de compras ------" << endl;
        cout << "\t1. Agregar nuevo producto" << endl;
        cout << "\t2. Eliminar producto por codigo" << endl;
        cout << "\t3. Cobrar al cliente" << endl;
        cout << "\t4. Finalizar pedido" << endl;
        int opcion;
        cout << "\tIngrese la opcion que desea ejecutar: "; cin >> opcion; cin.ignore();

        switch (opcion){
            case 1: 
                MostrarInventarioparaVenta (lista_compras);
                cout << "\nVino agregado exitosamente!";
                break;
            case 2: 
                cout << "\n\tIngrese el codigo del producto que desea eliminar: "; cin >> id;
                borrarPorCodigo (lista_compras, id);
                break;
            case 3: 
                cout << "\tDescripcion del pedido: " << endl;
                for (int i = 0; i < lista_compras.size(); i++){
                    mostrarVino (lista_compras[i]);
                }
                total = CobrarClientes (lista_compras);
                cout << "\tTotal a pagar: $" << total << endl;
                llenando.pagado = true;
                cout << endl;
                break;
            case 4: status = false; break;
            default: cout << "\tOpcion ingresada no valida" << endl;
                break;
        }
    }
    llenando.lista_de_compras = lista_compras;
    // Agregando la lista de vinos al pedido

    llenando.total = total;

    cola_pedidos.push(llenando);
    // Agregando el pedido a la cola

    lista_compras.clear();
}

//menu de pedidos
void pedidos(){
   int opcion,x=1;
    bool status = true;
    while (status){
        if(x==1){
          menu_pedidos();
        }else{
          menu_pedidos("\tNo hay vinos en el inventario...\nIngrese una opcion:");
        }
        cin >> opcion; cin.ignore(); cout << "\n";
        switch (opcion){
            case 1:
                if (lista_vinos.empty()){
                  x=0;
                }
                else{
                    llenandoPedido();
                }
                break;
            case 2: Mostrapedidos(); break;
            case 3: status = false; break;
            default: menu_pedidos("Porfavor seleccione una opcion correcta:");
        }
    }
}

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
