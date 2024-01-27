#pragma once
# include <string>

template <typename T>
T	min(T value1, T value2)
{
	return (value1 < value2 ? value1 : value2);
}