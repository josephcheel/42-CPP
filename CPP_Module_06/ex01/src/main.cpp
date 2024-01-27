# include <iostream>
# include <string>
# include "../inc/Data.hpp"
# include "../inc/Serializer.hpp"


int	main(void)
{
	uintptr_t raw;
	Data ptr;
	ptr.c = 42;
	ptr.i = 42;
	ptr.f = 42.0f;
	ptr.d = 42;
	
	raw = Serializer::serialize(&ptr);
	Data *out = Serializer::deserialize(raw);
	std::cout << out->c << std::endl;
	std::cout << out->i << std::endl;
	std::cout << out->f << std::endl;
	std::cout << out->d << std::endl;		
}
