# include <iostream>
# include "../inc/Base.hpp"
# include "../inc/A.hpp"
# include "../inc/B.hpp"
# include "../inc/C.hpp"
# include "../inc/func.hpp"

int	main(void)
{
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;

	base = generate();
	identify(base);
	identify(*base);
	delete base;
	base = generate();
	identify(base);
	identify(*base);
	delete base;
	base = generate();
	identify(base);
	identify(*base);
	delete base;
	base = generate();
	identify(base);
	identify(*base);
	delete base;
	base = generate();
	identify(base);
	identify(*base);
	delete base;
}