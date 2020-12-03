#include <iostream>

int main(int argc, char* argv[])
{

	if (argc > 2)
	{
		std::cout << "one word!\n";
		return 0;
	}

	
	char* _z = argv[1];
	int _letterCount = 0;
	
	while (*_z != '\0')
	{
		_letterCount++;
		_z++;  
	}

	std::cout << "amount of letters: " << _letterCount << std::endl;

	int r = _letterCount - 1; 
	int l = 0;

	if (_letterCount % 2 == 0)
	{
		while ( l < r )
		{ 
			std::cout << argv[1][l] << "  " << argv[1][r] << std::endl;


			if (argv[1][l] != argv[1][r])
			{
				std::cout << "it's not a palindrome\n";
				return 0;
			}

			r--;
			l++;
		}
	}
	else
	{
		while ( l < _letterCount / 2 )
		{ 
			std::cout << argv[1][l] << "  " << argv[1][r] << std::endl;


			if (argv[1][l] != argv[1][r])
			{
				std::cout << "it's not a palindrome\n";
				return 0;
			}

			r--;
			l++;
		}
	}
	

	std::cout << "IT'S A PALINDROME\n";
	return 0;

}
