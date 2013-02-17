#include "array.h"

using namespace mfe;

template <class T> 
Array<T>::Array() 
{
	buffer = (T*)malloc(default_array_size * sizeof(T));
	mem_allocated = default_array_size * sizeof(T);
	current_size = 0;
}

template <class T> 
Array<T>::Array(const INT len) 
{
	buffer = (T*)malloc(len * sizeof(T));
	mem_allocated = len * sizeof(T);
	current_size = 0;
}

template <class T> 
Array<T>::~Array() 
{
	assert(free(buffer));
	mem_allocated = 0;
	current_size = 0;	
}

template <class T> 
VOID Array<T>::PushBack(const T value) 
{
	current_size++;
	if (current_size > mem_allocated / sizeof(T)) 
	{
		mem_allocated *= 2;
		buffer = (T*)realloc(buffer, mem_allocated);
		assert(buffer);
	}
	buffer[current_size - 1] = value;
}

template <class T> 
Array<T>& Array<T>::operator = (const Array &value) 
{
	size = 0;
	for(INT i = 0; i < value.current_size; i++) 
		this.PushBack(value[i]);
	return this;
}

