#include <iostream>
#include <string>
#include <vector>

using namespace std;

 enum Tipos { Merlot,Cabernet,Malbet, Chardonnay,Sauvignon, Riesling,Rose,Merlot_Rose,Shiraz, Champagne};

struct Vinos{
    int id;
    int Cosecha;
    double PR_Venta;
    string nombre;
    Tipos tipo; // tinto,blanco  
    int botellas;
   
};
typedef Vinos vino;

vector<Vinos>lista_vinos; //una lista global 



Vinos llenandovino(){
    vino vinolleno;
    cout << "\n\tIngrese el codigo del vino:\n\t";cin>>vinolleno.id;cin.ignore();
    cout << "\n\tIngrese el nombre del vino\n\t"; getline(cin,vinolleno.nombre);
    cout << "\n\tIngrese el a\244o de la cosecha:\n\t"; cin>>vinolleno.Cosecha;
    cout << "\n\tIngrese la cantidad de botellas:\n\t"; cin>>vinolleno.botellas;

    /* pidiendo el tipo de vino*/
    
    bool continuar = true;
    char opcion = 0;
    do{
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

    cout << "\n\tIngrese el tipo de vino:\n\t";

    cin>>opcion;
    switch (opcion){
        case 'a':
        case 'A': vinolleno.tipo = Merlot;continuar = false; break;
        case 'b':
        case 'B': vinolleno.tipo = Cabernet;continuar = false; break;
        case 'c':
        case 'C': vinolleno.tipo = Malbet;continuar = false; break;
        case 'd':
        case 'D': vinolleno.tipo = Chardonnay;continuar = false; break;
        case 'e':
        case 'E': vinolleno.tipo = Sauvignon;continuar = false; break;
        case 'f':
        case 'F': vinolleno.tipo = Riesling;continuar = false; break;
        case 'g':
        case 'G': vinolleno.tipo = Rose;continuar = false; break;
        case 'h':
        case 'H': vinolleno.tipo = Merlot_Rose;continuar = false; break;
        case 'i':
        case 'I': vinolleno.tipo = Shiraz;continuar = false; break;
        case 'j':
        case 'J': vinolleno.tipo = Champagne;continuar = false; break;
  default: cout << "\tOpcion ingresada no valida\n";
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
        cout << "\nInventario vacio .....\n";
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

        cout << "\tPrecio por botella : $" << lista_vinos[i].PR_Venta;
    }
        cout << "\n=========================================================================\n";

}
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
            cout << "Ingrese el nuevo año de cosecha:"; cin>>cosecha;
            iter ->Cosecha = cosecha;
             break;
            case 4:
    do{
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

    cout << "\n\tIngrese el tipo de vino al cual desea actualizar:\n\t";

    cin>>tipo;
    switch (tipo){
        case 'a':
        case 'A': iter ->tipo = Merlot;continuar = false; break;
        case 'b':
        case 'B': iter ->tipo = Cabernet;continuar = false; break;
        case 'c':
        case 'C': iter ->tipo = Malbet;continuar = false; break;
        case 'd':
        case 'D': iter ->tipo = Chardonnay;continuar = false; break;
        case 'e':
        case 'E': iter ->tipo = Sauvignon;continuar = false; break;
        case 'f':
        case 'F': iter ->tipo = Riesling;continuar = false; break;
        case 'g':
        case 'G': iter ->tipo = Rose;continuar = false; break;
        case 'h':
        case 'H': iter ->tipo = Merlot_Rose;continuar = false; break;
        case 'i':
        case 'I': iter ->tipo = Shiraz;continuar = false; break;
        case 'j':
        case 'J': iter ->tipo = Champagne;continuar = false; break;
  default: cout << "\tOpcion ingresada no valida\n";
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

            default : cout << "opcion no valida ingrese otra" << endl; break;

 cout << "\t\nDato actualizado Exitozamente!!!\n";
        }
       

    }
        }
    }
    if(encontrado == false){
        cout << "\nEl codigo ingresado no pertenece a ningun producto dentro de este inventario";
       
    }
}
}
double CalcularGanancias(){
    double total = 0;
    if(!lista_vinos.empty()){
       for(int i=0;i<lista_vinos.size();i++){
            total+=(lista_vinos[i].PR_Venta * lista_vinos[i].botellas);
        }
    }
return total;

}

int main(){
    int opcion;
    bool status = true;
    while(status){
        cout << endl;
        cout << "\n\tInventario";
        cout << "\n\t1.Agregar Vino";
        cout << "\n\t2.Eliminar Vino";
        cout << "\n\t3.Mostrar Inventario";
        cout << "\n\t4.Actualizar informacion de un Vino";
        cout << "\n\t5.Calcular las ganancias de los vinos vendidos";
        cout << "\n\t6.Salir\n";

        cout << "\n\tIngrese la opcion que desea ejecutar:";cin>>opcion;
        
        switch(opcion){
            case 1 : AgregarInventarioVino(llenandovino()); break;
            case 2 : eliminarVino(); break;
            case 3 : mostrarInventario(); break;
            case 4 : ActualizarVino(); break;
            case 5 : cout<<"\n\tEl total de las ganancias es: $" <<CalcularGanancias(); break;
            case 6 : status = false ; break;
            default : cout << "\nOpcion infresada no valida";

        }

    }
}