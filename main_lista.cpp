#include "dll_node_t.hpp"
#include "dll_t.hpp"
#include "vector_t.hpp"
#include "stack_l_t.hpp"
#include "queue_l_t.hpp"
#include <iostream>


int main(void){

  //LISTA

AED::dll_t<int> lista_1;
AED::dll_t<int> lista_2;


for (int i = 0; i < 10; i++){
  lista_1.insert_tail(new AED::dll_node_t<int>(i));
}
cout << "------------------Lista1--------------------" << endl;
cout << "--->";
lista_1.write(cout);
cout << endl << endl;

for (int i = 0; i < 10; i++){
  lista_2.insert_tail(new AED::dll_node_t<int>(i));
}
cout << "----------------Lista2----------------------" << endl;
cout << "--->";
    lista_2.write(cout);
      cout << endl << endl;


lista_1.insert_middle(new AED::dll_node_t<int>(11));
cout << "--->";
lista_1.write(cout);
cout << endl;

AED::dll_t<int> lista_3;
lista_3.merge(lista_2, lista_1);
cout << "-------Lista3---MERGE-----" << endl;
cout << "--->";
lista_3.write(cout);
cout << endl;


AED::dll_t<int> lista_4;
for (int i = 0; i < 5; i++){
  lista_4.insert_tail(new AED::dll_node_t<int>(i));
}
  lista_4.insert_middle(new AED::dll_node_t<int>(1));

//cout << "----------------Lista4-----------------------" << endl;
//cout << "--->";
//lista_4.write(cout);
cout << endl << endl;


//lista_3.merge(lista_1, lista_4);








    return 0;
}

