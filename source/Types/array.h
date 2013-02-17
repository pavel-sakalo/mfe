#ifndef MFE_TYPES_ARRAY_H_
#define MFE_TYPES_ARRAY_H_

#include "std_types.h"

namespace mfe
{

	template <class T> 
	class Array 
	{
		T					*buffer;;
		INT					current_size;
		INT					mem_allocated;

		static const INT	default_array_size = 10;

	public:
		Array();
		Array(const INT len);
		~Array();

		VOID				PushBack(const T var);
		INT					GetSize() { return current_size; }
		Array&				operator = (const Array &x); 
		T&					operator [] (const INT i) { return buffer[i]; }
	};

}

#endif // MFE_TYPES_ARRAY_H_