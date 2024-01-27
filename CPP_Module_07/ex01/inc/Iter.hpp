#pragma once

template<typename T, int N, void f(T)>
void	iter(T Array[N])
{
	for(int i = 0; i < N; i++)
	{
		f(Array[i]);
	}
}

