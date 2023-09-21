
// Implementation of 3-dimensional vector class

#include "Vec3.h"

// Public Methods //
template <typename T>
	requires arithmetic<T>
Vec3<T>::Vec3() 
	: m_Values{0, 0, 0}
{}

template <typename T>
	requires arithmetic<T>
Vec3<T>::Vec3(T in_num1, T in_num2, T in_num3)
	: m_Values{ in_num1, in_num2, in_num3 }
{}

// Private Methods //