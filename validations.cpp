#include <iostream> 
#include <string>

using  namespace std;

int cinnumber(){
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