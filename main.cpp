#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <ctype.h>
#include "menu.h"

using namespace std;

//variables globales--------
enum Tipos { Merlot,Cabernet,Malbet, Chardonnay,Sauvignon, Riesling,Rose,Merlot_Rose,Shiraz, Champagne};
struct Clientes{//stuct de Vinos
  int id_cliente;
  string nombre;
  string apellido;
  int dui; 
};
typedef Clientes cliente;


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
vector<Clientes>lista_clientes;
queue <Pedido> cola_pedidos; 

void wait(){
  string a="";
  cin>>a;
  while(1){
    if(cin.fail())
  {}
  if(!cin.fail())
  break;
  }
}
//variables globales--------

// Aqui todos los metodos de clientes
void Agregarcliente(){
  cliente actual;
    printf("\033c");
  cout << "\n\tIngrese el ID del cliente:\n\t";cin>>actual.id_cliente;cin.ignore();
  cout << "\n\tIngrese el nombre del cliente\n\t"; getline(cin,actual.nombre);
  cout << "\n\tIngrese el apellido del cliente\n\t"; getline(cin,actual.apellido);
  cout << "\n\tIngrese el numero de DUI del cliente\n\t"; cin>>actual.dui;cin.ignore();

  lista_clientes.push_back(actual);
  actual={};
}

void Eliminarcliente(){
    printf("\033c");
  int id;
  cout << "\n\tIngrese el ID del cliente a eliminar:\n\t";cin>>id;cin.ignore();
  for(int i=0;i<lista_clientes.size();i++){
    if(lista_clientes[i].id_cliente==id){
      lista_clientes.erase(lista_clientes.begin()+i);
    }
  }
}

void Mostrarclientes(bool waits=true){
  printf("\033c");
  cout<<"\n\tid_cliente\tNombre y apellido\tN0 de DUI\n\t";
  for(int i=0;i<lista_clientes.size();i++){
    cout<<"\n"<<i+1<<".\t"<<lista_clientes[i].id_cliente<<"\t\t"<<lista_clientes[i].nombre<<" "<<lista_clientes[i].apellido<<"\t\t\t"<<lista_clientes[i].dui;
  }
  if(waits){
    cout<<"\nPresione cualquier tecla para continuar...";
    wait();
  }else{

  }
}

void Modificarcliente(){
  int cliente,opcion,dui;
  string name;
  printf("\033c");
  Mostrarclientes(false);
  cout<<"\nIngrese el cliente de quien desea modificar informacion... ";
  cin>>cliente;cliente--;
  printf("\033c");
  cout << endl;
  cout << "\n\tQue dato desea modificar";
  cout << "\n\t1.DUI";
  cout << "\n\t2.Nombre";
  cout << "\n\t3.Apellido"; 
  cout << "\n\n\tIngrese una opcion: "; 
  cin>>opcion;
  cin.ignore();
        
        switch(opcion){
            case 1 :
              cout<<"Ingrese el nuevo numero de DUI:";
              cin>>dui;cin.ignore();
              lista_clientes[cliente].dui=dui;
            break;
            case 2 :
              cout<<"Ingrese el nuevo Nombre:";
              getline(cin,name);
              lista_clientes[cliente].nombre=name; 
            break;
            case 3 :
              cout<<"Ingrese el nuevo Apellido:";
              getline(cin,name);
              lista_clientes[cliente].apellido=name; 
            break;
        }
}
//menu de clientes
void clientes(){
    int opcion;
    bool status = true;
    while(status){
        menu_clientes();
        cin>>opcion;
        
        switch(opcion){
            case 1 : Agregarcliente(); break;
            case 2 :if(lista_clientes.empty()){menu_clientes("No hay clientes a eliminar");}else{Eliminarcliente();}; break;
            case 3 : Mostrarclientes(); break;
            case 4 : Modificarcliente(); break;
            case 5 :  status = false ;break;
            default : 
            menu_clientes("Ingrese una opcion correcta:");
            break;

        }
    }  
}
// Aqui todos los metodos de inventario_de_vinos
Vinos llenandovino(){
    vino vinolleno;
    cout << "\n\tIngrese el codigo del vino:\n\t";cin>>vinolleno.id;cin.ignore();
    cout << "\n\tIngrese el nombre del vino\n\t"; getline(cin,vinolleno.nombre);
    cout << "\n\tIngrese el a\244o de la cosecha:\n\t"; cin>>vinolleno.Cosecha;
    cout << "\n\tIngrese la cantidad de botellas:\n\t"; cin>>vinolleno.botellas;

    /* pediendo el tipo de vino*/
    
    bool continuar = true;
    char opcion = 0;
    do{
    menu_tipos_vinos();
    cin>>opcion;
    opcion=toupper(opcion);
    switch (opcion){
        case 'A': vinolleno.tipo = Merlot;continuar = false; break;
        case 'B': vinolleno.tipo = Cabernet;continuar = false; break;
        case 'C': vinolleno.tipo = Malbet;continuar = false; break;
        case 'D': vinolleno.tipo = Chardonnay;continuar = false; break;
        case 'E': vinolleno.tipo = Sauvignon;continuar = false; break;
        case 'F': vinolleno.tipo = Riesling;continuar = false; break;
        case 'G': vinolleno.tipo = Rose;continuar = false; break;
        case 'H': vinolleno.tipo = Merlot_Rose;continuar = false; break;
        case 'I': vinolleno.tipo = Shiraz;continuar = false; break;
        case 'J': vinolleno.tipo = Champagne;continuar = false; break;
        default:menu_tipos_vinos("\tOpcion ingresada no valida\n");
    }
    }while(continuar);

   cout << "\n\tIngrese el costo por unidad:\n\t";cin>>vinolleno.PR_Venta;
    return vinolleno;
}
void AgregarInventarioVino( Vinos vino){
      lista_vinos.push_back(vino);
}
void mostrarInventario(){

    if(lista_vinos.empty()){
        cout << "\nInventario vacio ...\n";
    }else{

    for(int i =0;i < lista_vinos.size();i++){
        cout << "\n=========================================================================\n";
        cout << "\tCodigo:" << lista_vinos[i].id << endl;;
        cout << "\tNombre:" << lista_vinos[i].nombre << endl;
        cout << "\tCosecha:" << lista_vinos[i].Cosecha << endl;
       cout << "\tCantidad de botellas disponibles:"<< lista_vinos[i].botellas << endl;
        cout << "\tTipo:";

        switch (lista_vinos[i].tipo){
        case Merlot :cout << "Merlot" << endl; break;
        case Cabernet : cout << "Cabernet Sauvignon" << endl; break;
        case Malbet : cout << " Malbet" << endl; break;
        case Chardonnay : cout << "Chardonnay" << endl;; break;
        case Sauvignon :cout << "Sauvignon Blanc" << endl;break;
        case Riesling : cout <<" Riesling" << endl; break;
        case Rose : cout << "Rose Pinot" << endl; break;
        case Merlot_Rose : cout << "Merlot Rose" << endl; break;
        case Shiraz: cout << "Shiraz" << endl; break;
        case Champagne : cout << "Champagne"; break;
        }

        cout << "\tPrecio por botella: $" << lista_vinos[i].PR_Venta;
    }
        cout << "\n=========================================================================\n";
        
        

  }
  wait();
}
void eliminarVino(){
     int codigo;
     bool encontrado = false;
     cout << "\n Ingrese el codigo del vino que desea eliminar:";
     cin >> codigo;
    
    for(auto iter = lista_vinos.begin(); iter != lista_vinos.end(); ++iter){
        if(iter->id == codigo){
            encontrado = true;
            iter = lista_vinos.erase(iter);
            cout << "\t\nVino eliminado exitosamente.\n";
            break;
        }
    }

    if(encontrado == false){
        cout << "\nEl codigo ingresado no pertenece a ningun producto dentro de este inventario";
    }
}
void ActualizarVino(){
    int codigo;
    bool encontrado = false;
     bool status = true;
     bool continuar = true;

     if(lista_vinos.empty()){
         cout << "\nInventario vacio.....";
     }else{

    cout << "\nIngrese codigo del vino a modificar:"; cin>>codigo;

    for(auto iter = lista_vinos.begin(); iter != lista_vinos.end(); ++iter){
        if(iter->id == codigo){

             bool encontrado = true;
             int id,cosecha, botellas, opcion; double Pr_Venta;char tipo = 0; string nombre;

   
    while(status){
        printf("\033c");
        cout <<"\t\n Elija el dato que desea modificar:\t\n";
        cout <<"\t\n 1.Codigo";
        cout <<"\t\n 2.Nombre";
        cout <<"\t\n 3.Cosecha";
        cout <<"\t\n 4.Tipo";
        cout <<"\t\n 5.Precio de venta";
        cout <<"\t\n 6.Cantidad de botellas disponibles";
        cout <<"\t\n 7.Regresar";
        cout <<"\t\n Opcion elegida:";
        cin>>opcion;cin.ignore();
        switch(opcion){
            case 1:
            cout << "Ingrese el codigo actualizado:"; cin>>id;
              iter->id = id;
            break;
            case 2:
            cout << "Ingrese el nuevo nombre:"; getline(cin,nombre);
            iter->nombre = nombre; 
            break;
            case 3:
            cout << "Ingrese el nuevo a\244o de cosecha:"; cin>>cosecha;
            iter ->Cosecha = cosecha;
             break;
            case 4:
    do{
    menu_tipos_vinos();
    cin>>opcion;
    opcion=toupper(opcion);
    switch (tipo){
        case 'A': iter ->tipo = Merlot;continuar = false; break;
        case 'B': iter ->tipo = Cabernet;continuar = false; break;
        case 'C': iter ->tipo = Malbet;continuar = false; break;
        case 'D': iter ->tipo = Chardonnay;continuar = false; break;
        case 'E': iter ->tipo = Sauvignon;continuar = false; break;
        case 'F': iter ->tipo = Riesling;continuar = false; break;
        case 'G': iter ->tipo = Rose;continuar = false; break;
        case 'H': iter ->tipo = Merlot_Rose;continuar = false; break;
        case 'I': iter ->tipo = Shiraz;continuar = false; break;
        case 'J': iter ->tipo = Champagne;continuar = false; break;
        default:menu_tipos_vinos("\tOpcion ingresada no valida\n");
    }
    }while(continuar);

             break;

            case 5: 
            cout << "Ingrese el nuevo precio de venta:"; cin>>Pr_Venta;
            iter ->PR_Venta = Pr_Venta; 
            break;

             case 6: 
            cout << "Ingrese la cantidad de botellas disponibles actualmente:"; cin>>botellas;
            iter ->botellas = botellas; 
            break;
             case 7: 
               status = false ; break;
            break;

            default : cout << "Opcion no valida, ingrese otra" << endl; break;
            cout << "\t\nDato actualizado exitosamente!!!\n";
        }
    }
        }
    }
    if(encontrado == false){
        cout << "\nEl codigo ingresado no pertenece a ningun producto dentro de este inventario";
       
    }
  }
}
//menu de inventario
void inventario(){
    int opcion;
    bool status = true;
    while(status){
        menu_vinos();
        //mostrarInventario();
        cin>>opcion;
        
        switch(opcion){
            case 1 : AgregarInventarioVino(llenandovino()); break;
            case 2 : eliminarVino(); break;
            case 3 : mostrarInventario(); break;
            case 4 : ActualizarVino(); break;
            case 5 :  status = false ;break;
            default : 
            menu_vinos("Ingrese una opcion correcta:");
            //mostrarInventario();
            break;

        }
    }
}
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
            default: menu_pedidos("Por favor, seleccione una opcion correcta:");
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
