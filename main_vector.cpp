#include "vector_t.hpp"

#include <iostream>

using namespace std;

int main(void){

AED::vector_t<int> v1(10);
AED::vector_t<int> v2(v1);


    v1.write(cout);
    cout << endl;
    v2.write(cout);

    return 0;
}




