#ifndef _DLL_NODE_T_HPP
#define _DLL_NODE_T_HPP


#include <cassert>
#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

namespace AED {

    template <class TDato>
    class dll_node_t {
    private:

        dll_node_t<TDato>* next_;
        dll_node_t<TDato>* prev_;

	TDato              data_;

    public:
        dll_node_t();
	dll_node_t(const TDato& data);
	

        virtual ~dll_node_t(void);

	void set_next(dll_node_t<TDato>*);
	void set_prev(dll_node_t<TDato>*);

	dll_node_t<TDato>* get_next(void) const;
	dll_node_t<TDato>* get_prev(void) const;

	void set_data(const TDato& data);
	TDato get_data(void) const;

	ostream& write(ostream& os) const;
    };


template <class TDato>
dll_node_t<TDato>::dll_node_t() :
next_(NULL),
prev_(NULL),
data_()
{
}

template <class TDato>
dll_node_t<TDato>::dll_node_t(const TDato& data) :
next_(NULL),
prev_(NULL),
data_(data) 
{}

template <class TDato>
dll_node_t<TDato>::~dll_node_t(void) {
prev_ = NULL;
next_ = NULL;
}

template <class TDato>
void dll_node_t<TDato>::set_next(dll_node_t<TDato>* next)
{
	next_ = next;
}

template <class TDato>
dll_node_t<TDato>* dll_node_t<TDato>::get_next(void) const
{
	return next_;
}

template <class TDato>
void dll_node_t<TDato>::set_prev(dll_node_t<TDato>* prev)
{
	prev_ = prev;
}

template <class TDato>
dll_node_t<TDato>* dll_node_t<TDato>::get_prev(void) const
{
	return prev_;
}

template <class TDato>
void dll_node_t<TDato>::set_data(const TDato& data)
{
	data_ = data;
}

template <class TDato>
TDato dll_node_t<TDato>::get_data(void) const
{
	return data_;
}

template <class TDato>
ostream& dll_node_t<TDato>::write(ostream& os) const
{
	os << data_<< setw(3);
	return os;
}

}
#endif
