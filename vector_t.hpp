#ifndef _VECTOR_T_HPP
#define _VECTOR_T_HPP

#include <cstdio>
#include <iostream>
#include <iomanip>

#include <cassert>

using namespace std;
namespace AED {

	template <class TDato>
	class vector_t{
	private:
		TDato*      v_;
		int     sz_;

	public:

		vector_t(void):
			v_(NULL),
			sz_(0) {}

		vector_t(int sz):
			v_(NULL),
			sz_(sz) {

			crea_vector();
		}

		vector_t(const vector_t& v):
		v_(NULL),
		sz_(v.sz_)
		{
		    crea_vector();
    
  		   for(int i = 0; i < sz_; i++)
          v_[i] = v.v_[i];
		}



		~vector_t(void){

			destruye_vector();
		}

		void resize(int sz)
		{
			destruye_vector();
			sz_ = sz;
			crea_vector();
		}

		int get_sz(void) const
		{
			return sz_;
		}

		virtual TDato get_v(int pos) const{
		
			assert((pos < sz_) && ((pos >= 0)));

			return v_[pos];
		}

		virtual TDato& get_set_v(int pos){

			assert((pos < sz_) && ((pos >= 0)));

			return v_[pos];
		}

		ostream& write(ostream& os) const{
	
			os << setw(5) <<  sz_ << endl;
			os << endl;

			for(int i = 0; i < sz_; i ++){
				v_[i].write(os);
				os << " ";
			}

			return os;
		}

		istream& read(istream& is){
	
			is >> sz_;

			resize(sz_);

			for(int i = 0; i < sz_; i ++)
			 	is >> v_[i];

			return is;
		}

	private:

		void crea_vector(void){
			v_ = new TDato
	[sz_];
		}

		void destruye_vector(void)
		{
			if (v_ != NULL){
				delete [] v_;
				v_ = NULL;
			}
		}

	};

	
	template <>
	ostream& vector_t<int>::write(ostream& os) const{

		os << setw(6) <<  sz_ << endl;

		for(int i = 0; i < sz_; i ++)
		 	os << setw(8) << fixed << setprecision(2) << v_[i] << " ";


		return os;
	}

	
}
#endif