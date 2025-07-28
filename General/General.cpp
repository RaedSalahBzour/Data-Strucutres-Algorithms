#include <iostream>
std::string reverseString(std::string word)
{
    std::string reversed = "";
	for (size_t i = 0; i < word.length(); i++)
	{
		reversed = word[i] + reversed;
	}return reversed;
}
int main()
{
	std::cout << reverseString("raed") << std::endl;
	std::cin.get();
	
}
