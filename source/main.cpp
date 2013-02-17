#include <iostream>
#include "types\std_types.h"
#include "types\array.h"

using namespace mfe;

int main(int argc, char** argv)
{
	Array<INT> arr;
	for (INT i = 0; i < 100; i++)
		arr[i] = i;

	for (INT i = 0; i < arr.GetSize(); i++)
		std::cout << arr[i] << " ";

	return 0;
}