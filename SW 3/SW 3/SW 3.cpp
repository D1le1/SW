#include <iostream>
#include <fstream>
#include <string>

struct Product
{
	int index = 0;
	double cost = 0.0;
	std::string name = "Potato";
	int count = 0;
};

static std::string fileName = "../Text_Files/Product.txt";

#pragma region DescribeFunctions
Product* readProductFromFile();
int getCountOfRows();
#pragma endregion

int main()
{
	
}

#pragma region Functions
int getCountOfRows()
{
	std::ifstream file(fileName);
	std::string string;
	int size = 0;
	if (!file.is_open())
		return 0;
	while (std::getline(file, string))
		size++;
	file.close();
	return size;
}

Product* readProductFromFile()
{
	std::ifstream file(fileName);
	if (!file.is_open())
		return nullptr;
	int size = getCountOfRows();
	Product* products = new Product[size];
	int index = 0;
	while (!file.eof())
	{
		file >> products[index].index;
		file >> products[index].cost;
		file >> products[index].name;
		file >> products[index].count;
		index++;
	}
	file.close();
	return products;
}
#pragma endregion