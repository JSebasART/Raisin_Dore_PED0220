#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

enum Tipos {Merlot, Cabernet, Malbet, Chardonnay, Sauvignon, Riesling, Rose, Merlot_Rose, Shiraz, Champagne};

struct Vinos{
    int id;
    int Cosecha;
    double PR_Venta;
    string nombre;
    Tipos tipo; // tinto,blanco, rosa
    int botellas;
};
typedef Vinos vino;

struct Pedido{
    int dui;
    string nombre;
    int total;
    bool pagado = false;
    vector <Vinos> lista_de_compras;
};
typedef Pedido pedido;

vector <Vinos> lista_vinos; // lista global 
queue <Pedido> cola_pedidos;

Vinos llenandovino(){
    vino vinolleno;
    cout << "\n\tCodigo del vino: "; cin >> vinolleno.id; cin.ignore();
    cout << "\n\tNombre del vino: "; getline (cin, vinolleno.nombre);
    cout << "\n\tA\244o de la cosecha: "; cin >> vinolleno.Cosecha; cin.ignore();
    cout << "\n\tIngrese la cantidad de botellas: "; cin >> vinolleno.botellas;

    /* Pidiendo el tipo de vino */
    
    bool continuar = true;
    char opcion = 0;
    do{
        cout << "\n\tTipo de vino:\t";
        cout << "\n\t-----------VINOS TINTOS----------\t";
        cout << "\n\tA -- Merlot\t";
        cout << "\n\tB -- Cabernet Sauvignon\t";
        cout << "\n\tC -- Malbec\t";
        cout << "\n\t-----------VINOS BLANCOS----------\t";
        cout << "\n\tD -- Chardonnay\t";
        cout << "\n\tE -- Sauvignon Blanc\t";
        cout << "\n\tF -- Riesling\t";
        cout << "\n\t-----------VINOS ROSAS----------\t";
        cout << "\n\tG -- Rose Pinot\t";
        cout << "\n\tH -- Merlot Rose\t";
        cout << "\n\t-----------VINOS ESPUMADOS----------\t";
        cout << "\n\tI -- Shiraz\t";
        cout << "\n\tJ -- Champagne\t";
        cout << "\n\tIngrese el tipo de vino: "; cin>>opcion; cin.ignore();
        
        switch (opcion){
            case 'a':
            case 'A': vinolleno.tipo = Merlot; continuar = false; break;
            case 'b':
            case 'B': vinolleno.tipo = Cabernet; continuar = false; break;
            case 'c':
            case 'C': vinolleno.tipo = Malbet; continuar = false; break;
            case 'd':
            case 'D': vinolleno.tipo = Chardonnay; continuar = false; break;
            case 'e':
            case 'E': vinolleno.tipo = Sauvignon; continuar = false; break;
            case 'f':
            case 'F': vinolleno.tipo = Riesling; continuar = false; break;
            case 'g':
            case 'G': vinolleno.tipo = Rose; continuar = false; break;
            case 'h':
            case 'H': vinolleno.tipo = Merlot_Rose; continuar = false; break;
            case 'i':
            case 'I': vinolleno.tipo = Shiraz; continuar = false; break;
            case 'j':
            case 'J': vinolleno.tipo = Champagne; continuar = false; break;
            default: cout << "\tOpcion ingresada no valida\n";
        }
    } while (continuar);
    
    cout << "\n\tIngrese el costo por unidad: $"; cin >> vinolleno.PR_Venta;
    
    return vinolleno;
}

void AgregarInventarioVino( Vinos vino){
      lista_vinos.push_back(vino);
}

void mostrarInventario(){
    if (lista_vinos.empty()){
        cout << "\nInventario vacio...\n";
    }
    else{
        for (int i =0; i < lista_vinos.size(); i++){
            cout << "\n=========================================================================\n";
            cout << "\tCodigo: " << lista_vinos[i].id << endl;;
            cout << "\tNombre: " << lista_vinos[i].nombre << endl;
            cout << "\tCosecha: " << lista_vinos[i].Cosecha << endl;
            cout << "\tCantidad de botellas disponibles: " << lista_vinos[i].botellas << endl;
            cout << "\tTipo: ";
            
            switch (lista_vinos[i].tipo){
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
            cout << "\tPrecio por botella: $" << lista_vinos[i].PR_Venta;
        }
        cout << "\n=========================================================================\n";
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
    cout << "\tPrecio por botella: $" << a.PR_Venta;
    cout << "\n=========================================================================\n";
    cout << endl;
}

Vinos BuscarVino(){
    int codigo;
    Vinos aux;
    bool encontrado = false;
    cout << "\nIngrese el codigo del vino que desea agregar al carrito del cliente: "; cin >> codigo; cin.ignore();
    
    for (int i = 0; i < lista_vinos.size(); i++){
        if (lista_vinos[i].id == codigo){
            encontrado = true;
            aux = lista_vinos[i];
        }
    }
    return aux;
}

void eliminarVino(){
    int codigo;
    bool encontrado = false;
    cout << "\nIngrese el codigo del vino que desea eliminar: "; cin >> codigo; cin.ignore();
    
    for (auto iter = lista_vinos.begin(); iter != lista_vinos.end(); ++iter){
        if (iter->id == codigo){
            encontrado = true;
            iter = lista_vinos.erase(iter);
            cout << "\t\nVino eliminado exitosamente\n";
            break;
        }
    }
    if (encontrado == false){
        cout << "\nEl codigo ingresado no pertenece a ningun producto dentro de este inventario";
    }
}

void ActualizarVino(){
    int codigo;
    bool encontrado = false;
    bool status = true;
    bool continuar = true;

    if (lista_vinos.empty()){
        cout << "\nInventario vacio...";
    }
    else{
        cout << "\nIngrese codigo del vino a modificar: "; cin >> codigo; cin.ignore();
        for (auto iter = lista_vinos.begin(); iter != lista_vinos.end(); ++iter){
            if (iter->id == codigo){
                bool encontrado = true;
                int id, cosecha, botellas, opcion; double Pr_Venta; char tipo = 0; string nombre;
                
                while(status){
                    cout <<"\t\nElija el dato que desea modificar: \t";
                    cout <<"\t\n1. Codigo";
                    cout <<"\t\n2. Nombre";
                    cout <<"\t\n3. Cosecha";
                    cout <<"\t\n4. Tipo";
                    cout <<"\t\n5. Precio de venta";
                    cout <<"\t\n6. Cantidad de botellas disponibles";
                    cout <<"\t\n7. Regresar";
                    cout <<"\t\nOpcion elegida: "; cin >> opcion; cin.ignore();
                    
                    switch (opcion){
                        case 1:
                            cout << "Ingrese el codigo actualizado: "; cin >> id;
                            iter->id = id;
                            break;
                        case 2:
                            cout << "Ingrese el nuevo nombre: "; getline (cin, nombre);
                            iter->nombre = nombre;
                            break;
                        case 3:
                            cout << "Ingrese el nuevo año de cosecha: "; cin >> cosecha;
                            iter ->Cosecha = cosecha;
                            break;
                        case 4:
                            do{
                                cout << "\n\tTipo de vino:\t";
                                cout << "\n\t-----------VINOS TINTOS----------\t";
                                cout << "\n\tA -- Merlot\t";
                                cout << "\n\tB -- Cabernet Sauvignon\t";
                                cout << "\n\tC -- Malbec\t";
                                cout << "\n\t-----------VINOS BLANCOS----------\t";
                                cout << "\n\tD -- Chardonnay\t";
                                cout << "\n\tE -- Sauvignon Blanc\t";
                                cout << "\n\tF -- Riesling\t";
                                cout << "\n\t-----------VINOS ROSAS----------\t";
                                cout << "\n\tG -- Rose Pinot\t";
                                cout << "\n\tH -- Merlot Rose\t";
                                cout << "\n\t-----------VINOS ESPUMADOS----------\t";
                                cout << "\n\tI -- Shiraz\t";
                                cout << "\n\tJ -- Champagne\t";
                                cout << "\n\tIngrese el tipo de vino al cual desea actualizar: "; cin >> tipo; cin.ignore();
                                
                                switch (tipo){
                                    case 'a':
                                    case 'A': iter->tipo = Merlot; continuar = false; break;
                                    case 'b':
                                    case 'B': iter->tipo = Cabernet; continuar = false; break;
                                    case 'c':
                                    case 'C': iter->tipo = Malbet; continuar = false; break;
                                    case 'd':
                                    case 'D': iter->tipo = Chardonnay; continuar = false; break;
                                    case 'e':
                                    case 'E': iter->tipo = Sauvignon; continuar = false; break;
                                    case 'f':
                                    case 'F': iter->tipo = Riesling; continuar = false; break;
                                    case 'g':
                                    case 'G': iter->tipo = Rose; continuar = false; break;
                                    case 'h':
                                    case 'H': iter->tipo = Merlot_Rose; continuar = false; break;
                                    case 'i':
                                    case 'I': iter->tipo = Shiraz; continuar = false; break;
                                    case 'j':
                                    case 'J': iter->tipo = Champagne; continuar = false; break;
                                    default: cout << "\tOpcion ingresada no valida\n";
                                }
                            } while (continuar);
                            break;
                        case 5:
                            cout << "Ingrese el nuevo precio de venta: $"; cin >> Pr_Venta;
                            iter ->PR_Venta = Pr_Venta; 
                            break;
                        case 6: 
                            cout << "Ingrese la cantidad de botellas disponibles actualmente: "; cin >> botellas;
                            iter ->botellas = botellas; 
                            break;
                        case 7: 
                            status = false; break;
                        default: cout << "Opcion no valida, ingrese otra" << endl; break;
                        cout << "\t\nDato actualizado exitosamente!\n";
                    }
                }
            }
        }
        if(encontrado == false){
            cout << "\nEl codigo ingresado no pertenece a ningun producto dentro de este inventario";
        }
    }
}

void borrarPorCodigo (vector <Vinos> &listaProductos, int codigo){
    Vinos aux;
    bool encontrado = false;

    if (listaProductos.empty()){
        cout << "No hay productos en la lista" << endl;
        return;
    }
    else{
        for (int pos = 0; pos < listaProductos.size(); pos++){
            aux =listaProductos.at(pos);
             
            if (aux.id== codigo){
                encontrado = true;

                listaProductos.erase(listaProductos.begin() + pos);

                cout << "Se borro el producto correctamente" << endl;
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
            cout << "No habia ningun producto con ese nombre" << endl;
        }
    }
}

void mostrarlistadepedidos(vector<Vinos>listadevinos){
    if (listadevinos.size() == 0){
        cout << "\nLa lista esta vacia" << endl;
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
        cout << "Cola de pedidos vacia" << endl;
    }
    else{
        while (!aux.empty()){
            Pedido aux1 = aux.front();
            cout << "Nombre del cliente: " << aux1.nombre << endl;
            cout << "DUI: " << aux1.dui << endl;
            cout << "Total del cliente: $" << aux1.pagado<< endl;
            cout << "Estado del pedido: ";
            
            if (aux1.pagado == true){
                cout << "Cancelado" << endl;
            }
            else{
                cout << "Sin cancelar" << endl;
            }
            cout << "Mostrando la descripcion de los productos: ";
            mostrarlistadepedidos (aux1.lista_de_compras);
        }
    }
}

double CobrarClientes (vector <Vinos> list){
    double suma_total = 0;
    Vinos aux1;
    if (list.size() == 0){
        cout << "No hay productos en la lista" << endl;
    }
    else{
        for(int i = 0; i < list.size() ; i ++){
            suma_total += list[i].PR_Venta;
        }
    }
    return suma_total;
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

    cout << "\n\tIngrese el nombre del cliente: "; getline (cin, llenando.nombre);
    cout << "\n\tIngrese el DUI del cliente: "; cin >> llenando.dui; cin.ignore();

    while(status){
        cout << "\n\t-------Carrito de compras ------" << endl;
        cout << "\n\t1. Agregar nuevo producto" << endl;
        cout << "\n\t2. Eliminar producto por codigo" << endl;
        cout << "\n\t3. Cobrar al cliente" << endl;
        cout << "\n\t4. Finalizar pedido" << endl;
        int opcion;
        cout << "\n\tIngrese la opcion que desea ejecutar: "; cin >> opcion; cin.ignore();
    
        switch (opcion){
            case 1: 
                MostrarInventarioparaVenta (lista_compras);
                break;
            case 2: 
                cout << "\n\tIngrese el codigo del producto que desea eliminar: "; cin >> id;
                borrarPorCodigo (lista_compras,id);
                break;
            case 3: 
                cout << "\n\tDescripcion del pedido: " << endl;
                for (int i = 0; i < lista_compras.size(); i++){
                    mostrarVino (lista_compras[i]);
                }
                total = CobrarClientes (lista_compras);
                llenando.total = total;
                cout << "\n\tTotal a pagar: $" << total << endl;
                llenando.pagado = true;
                cout << endl;
                break;
            case 4: status = false; break;
            default: cout << "Opcion ingresada no valida" << endl;
                break;
        }
    }
    llenando.lista_de_compras = lista_compras;
    // Agregando la lista de vinos al pedido

    cola_pedidos.push(llenando);
    // Agregando el pedido a la cola

    lista_compras.clear();
}


void menuInventraio(){
    int opcion;
    bool status = true;
    while (status){
        cout << endl;
        cout << "\n\t --------Inventario--------";
        cout << "\n\t1. Agregar Vino";
        cout << "\n\t2. Eliminar Vino";
        cout << "\n\t3. Mostrar Inventario";
        cout << "\n\t4. Actualizar informacion de un Vino"; 
        cout << "\n\t5. Salir";
        cout << "\n\tIngrese la opcion que desea ejecutar: "; cin >> opcion; cin.ignore();
        
        switch (opcion){
            case 1: AgregarInventarioVino (llenandovino()); break;
            case 2: eliminarVino(); break;
            case 3: mostrarInventario(); break;
            case 4: ActualizarVino(); break;
            case 5:  status = false; break;
            default: cout << "\nOpcion ingresada no valida";
        }
    }
}

void menuPedidos(){
    int opcion;
    bool status = true;
    while (status){
        cout << endl;
        cout << "\n\t --------Pedidos--------";
        cout << "\n\t1.Agregar Pedido";
        cout << "\n\t2.Mostrar Pedidos"; 
        cout << "\n\t3.Regresar";
        cout << "\n\tIngrese la opcion que desea ejecutar: "; cin >> opcion; cin.ignore();
        
        switch (opcion){
            case 1: llenandoPedido(); break;
            case 2: Mostrapedidos(); break;
            case 3: status = false; break;
            default: cout << "\nOpcion ingresada no valida";
        }
    }
}


int main(){
    int opcion;
    bool status = true;
    while (status){
        cout << endl;
        cout << "\n\t **** Bienvenido a Raisin Dore ****";
        cout << "\n\tComo podemos ayudarte?" << endl;
        cout << "\n\t1. Realizar Pedidos";
        cout << "\n\t2. Administrar Inventario"; 
        //  calcular ganacias (aqui va esa opcion)
        cout << "\n\t3. Salir";
        cout << "\n\tIngrese la opcion que desea ejecutar: "; cin >> opcion; cin.ignore();
        
        switch (opcion){
            case 1: menuPedidos(); break;
            case 2: menuInventraio(); break;
            case 3: status = false; break;
            default: cout << "\nOpcion ingresada no valida";
        }
    }
}
