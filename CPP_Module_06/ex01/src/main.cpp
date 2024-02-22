# include <iostream>
# include <string>
# include "../inc/Data.hpp"
# include "../inc/Serializer.hpp"


int	main(void)
{
	uintptr_t raw;
	Data ptr;
	ptr.setChar(42);
	ptr.setInt(42);
	ptr.setFloat(42.0f);
	ptr.setDouble(42);
	
	raw = Serializer::serialize(&ptr);
	Data *out = Serializer::deserialize(raw);
	std::cout << out->getChar() << std::endl;
	std::cout << out->getInt() << std::endl;
	std::cout << out->getFloat() << std::endl;
	std::cout << out->getDouble() << std::endl;		
}
