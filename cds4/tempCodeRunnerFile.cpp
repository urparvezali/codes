#include <bits/stdc++.h>

int main()
{
	std::vector<int> numbers = {5, 10, 3, 8, 15, 6};

	if (!numbers.empty())
	{
		auto [maxElement] = std::max({numbers});
		std::cout << "Maximum element: " << maxElement << std::endl;
	}
	else
	{
		std::cout << "Vector is empty." << std::endl;
	}

	return 0;
}
