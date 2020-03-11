#ifndef _STACK_L_T_HPP
#define _STACK_L_T_HPP


#include <iostream>
#include <iomanip>
#include <cassert>

#include "dll_t.hpp"

using namespace std;

namespace AED {

	template <class TDato>
	class stack_l_t{
	private:

		dll_t<TDato>    l_;

	public:	
		stack_l_t(void):
		l_() {}

		~stack_l_t(void) {}

		bool empty(void){
			return l_.empty();
		}

		TDato top(void){

			assert(!empty());
			
			dll_node_t<TDato>* node = l_.get_head();
			TDato data = node->get_data();
			return (data);
		}

		void pop(void){
			assert(!empty());			

			dll_node_t<TDato>* node = l_.extract_head();
			delete node;
		}

		void push(TDato dato){

			dll_node_t<TDato>* node = new dll_node_t<TDato>(dato);
			l_.insert_head(node);
		}

		ostream& write(ostream& os){
			
			dll_node_t<TDato>* aux = l_.get_head();

			while(aux != NULL){
				cout << " │ " << setw(2)<< aux->get_data() << "  │" << endl;
				aux = aux->get_next();
			}

			cout << " └─────┘" << endl; 
		}

	};
}
#endif