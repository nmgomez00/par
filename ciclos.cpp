#include<iostream>
using namespace std;
void f();
int main(){

    int numero;
    cout<<"Ingrese un numero: ";
    cin>>numero;
    for(int iterador = 0; iterador<=numero;iterador++){
        if(iterador%2 == 0){
            cout<<iterador<<endl;
        }
    }
    f();
    return 0;
}

void f(){
    while(true){
        main();
    }
}
