#include <iostream>
#include <vector>

int main() {
	std::vector<int> vec;
	std::vector<int> vec1{ 1,2,3,4,5,6,7,8,9 };
	std::vector<int> vec2( 10);
	std::vector<int> vec3(5,1);

	print(vec1);

}

void print(const std::vector<int> arr)
{
	for (const auto& elem:arr)
	{

	}
}