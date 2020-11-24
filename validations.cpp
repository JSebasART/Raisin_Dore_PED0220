#include <iostream> 
#include <string>

using  namespace std;

int cinint(){
  int a;
  cin>>a;
  while(1){
    if(cin.fail()){
      cout<<"\tIngrese un valor valido: ";
      cin.clear();
      cin.ignore();
      cin>>a;
    }
    if(!cin.fail()) {
      if(a>=0){
        break;
      }
    }
  }
  return a;
}

double cindouble(){
  double a;
  cin>>a;
  while(1){
    if(cin.fail()){
      cout<<"\tIngrese un valor valido: ";
      cin.clear();
      cin.ignore();
      cin>>a;
    }
    if(!cin.fail()) {
      if(a>=0){
        break;
      }
    }
  }
  return a;
}

void wait(){
  string a="";
  cout<<"\ningrese cualquier tecla para continuar...";
  cin>>a;
  while(1){
    if(cin.fail())
  {
    break;
  }
  if(!cin.fail())
    break;
  }
}