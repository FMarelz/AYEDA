#ifndef _QUEUE_L_HPP
#define _QUEUE_L_HPP

#include <iostream>
#include <iomanip>
#include <cassert>

#include "dll_t.hpp"

using namespace std;

namespace AED {

	template <class TDato>
	class queue_l_t{
	private:

		dll_t<TDato>    l_;

	public:	
		queue_l_t(void):
		l_() {}

		~queue_l_t(void) {}

		bool empty(void){
			return l_.empty();
		}

		int size(void){
			return l_.get_size();		
		}

		TDato front(void){

			assert(!empty());
			
			dll_node_t<TDato>* node = l_.get_tail();
			TDato data = node->get_data();
			return (data);
		}

		TDato back(void){

			assert(!empty());
			
			dll_node_t<TDato>* node = l_.get_head();
			TDato data = node->get_data();
			return (data);
		}

		void pop(void){
			assert(!empty());			

			dll_node_t<TDato>* node = l_.extract_tail();
			delete node;
		}

		void push(TDato dato){

			dll_node_t<TDato>* node = new dll_node_t<TDato>(dato);
			l_.insert_head(node);
		}

		ostream& write(ostream& os){
			

			dll_node_t<TDato>* aux = l_.get_head();

			while(aux != NULL){
				os << setw(4)<< aux->get_data();
				aux = aux->get_next();
			}

			os << endl;			

			return os;
		}

	};
}

#endif