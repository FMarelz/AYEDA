#ifndef _DLL_T_HPP
#define _DLL_T_HPP


#include <cassert>
#include <iostream>
#include <cstdio>

#include "dll_node_t.hpp"

using namespace std;

namespace AED {

    template <class TDato>
    class dll_t {
    private:
        dll_node_t<TDato>* head_;
        dll_node_t<TDato>* tail_;

        int sz_;

    public:
        dll_t(void);
        virtual ~dll_t(void); 

	    void insert_tail(dll_node_t<TDato>*);
        void insert_head(dll_node_t<TDato>*);

        dll_node_t<TDato>* extract_tail(void);
        dll_node_t<TDato>* extract_head(void);

        dll_node_t<TDato>* get_tail(void);
        dll_node_t<TDato>* get_head(void);

        void insert_middle(dll_node_t<TDato>* node);
        void merge(const dll_t<TDato>& L1,const dll_t<TDato>& L2);

        bool empty(void);

        void remove(dll_node_t<TDato>*);

        int get_size(void);

        ostream& write(ostream& os);
    };


    template <class TDato>
    dll_t<TDato>::dll_t(void) :
    head_(NULL),
    tail_(NULL),
    sz_(0) {
    }

    template <class TDato>
    dll_t<TDato>::~dll_t(void) {

        dll_node_t<TDato>* aux = NULL;

        while (head_ != NULL) {
            aux = head_;
            head_ = head_->get_next();
            delete aux;
            aux = NULL;
        }
        sz_ = 0;
        head_ = NULL;
        tail_ = NULL;
    }

    template <class TDato>
    bool dll_t<TDato>::empty(void) {

	if (head_ == NULL){

	   assert(tail_ == NULL);
	   assert(sz_ == 0);

	   return true;
	} else 
	   return false;
    }

    template <class TDato>
    void dll_t<TDato>::insert_head(dll_node_t<TDato>* nodo) {

        assert(nodo != NULL);

        if (empty()) {
            head_ = nodo;
            tail_ = head_;
        } else {
            head_->set_prev(nodo);
            nodo->set_next(head_);
            head_ = nodo;
        }

        sz_++;
    }

    template <class TDato>
    void dll_t<TDato>::insert_tail(dll_node_t<TDato>* nodo) {

        assert(nodo != NULL);

        if (empty()) {
            head_ = nodo;
            tail_ = head_;
        } else {
            tail_->set_next(nodo);
            nodo->set_prev(tail_);
            tail_ = nodo;
        }

        sz_++;
    }

    template <class TDato>
    dll_node_t<TDato>* dll_t<TDato>::extract_tail(void) {

        assert(!empty());

        dll_node_t<TDato>* aux = tail_;

        tail_ = tail_->get_prev();

        if (tail_ != NULL)
            tail_->set_next(NULL);
        else
            head_ = NULL;

        sz_--;

	aux->set_next(NULL);
	aux->set_prev(NULL);

        return aux;
    }

    template <class TDato>
    dll_node_t<TDato>* dll_t<TDato>::extract_head(void) {

        assert(!empty());

        dll_node_t<TDato>* aux = head_;

        head_ = head_->get_next();

        if (head_)
            head_->set_prev(NULL);
        else
            tail_ = NULL;

        sz_--;

	aux->set_next(NULL);
	aux->set_prev(NULL);

        return aux;
    }

    template <class TDato>
    dll_node_t<TDato>* dll_t<TDato>::get_head(void) {
	return head_;
    }

    template <class TDato>
    dll_node_t<TDato>* dll_t<TDato>::get_tail(void) {
	return tail_;
    }

    template <class TDato>
    ostream& dll_t<TDato>::write(ostream& os) {
		
        dll_node_t<TDato>* aux = head_;

        while (aux != NULL) {
            aux->write(os);
            aux = aux->get_next();
        }

	return os;
    }

    template <class TDato>
    void dll_t<TDato>::remove(dll_node_t<TDato>* nodo) {
			
        assert(nodo != NULL);

        if (nodo->get_prev() != NULL)
            nodo->get_prev()->set_next(nodo->get_next());
        else
            head_ = nodo->get_next();

        if (nodo->get_next() != NULL)
            nodo->get_next()->set_prev(nodo->get_prev());
        else
            tail_ = nodo->get_prev();

	delete nodo;

        sz_--;

    }



    //modificacion
    template<class TDato>
     void dll_t<TDato>::insert_middle(dll_node_t<TDato>* node){

          assert(node != NULL);

          dll_node_t<TDato>* aux = head_;
          
         for(int i = 0; i < sz_/2 -1 ; i++){
            aux = aux -> get_next();
         }  

         dll_node_t<TDato>* aux2 = aux -> get_next();
            aux -> set_next(node);          
            node ->set_prev(aux)  ;
            node -> set_next(aux2);
            aux2 -> set_prev(node);

            sz_++;
     }


        
    template <class TDato>
    int dll_t<TDato>::get_size(void) {
        return sz_;
    }	

    template<class TDato>
    void dll_t<TDato>::merge(const dll_t<TDato>& L1, const dll_t<TDato>& L2 ){

        dll_node_t<TDato>* L1_h = L1.head_;
        dll_node_t<TDato>* L2_h = L2.head_;

       while((L1_h != NULL) && (L2_h != NULL)) {

           const TDato& L1_d = L1_h -> get_data();
           const TDato& L2_d = L2_h -> get_data();

            if(L1_d < L2_d){
                insert_tail(new dll_node_t<TDato>(L1_d));
                L1_h =  L1_h ->get_next();

            }if (L2_d < L1_d){

                insert_tail(new dll_node_t<TDato>(L2_d));
                L2_h = L2_h -> get_next();
            }
        }

        while(L1_h != NULL){
              insert_tail(new dll_node_t<TDato>(L1_h->get_data()));
                  L1_h = L1_h->get_next();
        }   

          while(L2_h != NULL){
              insert_tail(new dll_node_t<TDato>(L2_h->get_data()));
                  L2_h = L2_h->get_next();
        }   


    }

    






//template<class T>
//void dll_t<T>::new_method(dll_t<T>& L1){

  //  if(!L1.empty()){

    //    dll_node_t<T>* aux = L1.get_head();
      //    T L1_data = aux -> get_data();

        //insert_head(new dll_node_t<T>(L1_data));
//                        dll_node_t<T>* aux_3 = aux;


//while((aux_3 -> get_next()) !=NULL ){

  //       dll_node_t<T>* aux_2 = L1.get_head();
    //     aux_2 = aux_2 ->get_next();
      //   aux_2 = aux_2 ->get_next();
  //   const T& L2_data = aux -> get_data();
        // L1_data = aux_2 -> get_data();
        // insert_tail(new dll_node_t<T>(L1_data));
          //      dll_node_t<T>* aux_3 = aux_2;
        //if((aux_3 -> get_next()) != NULL){
          //  aux_3 = aux_3 -> get_next();
        //}
    

}
#endif