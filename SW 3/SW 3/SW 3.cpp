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


#pragma region DescribeFunctions
Product* readProductFromFile(std::string, int);
void writeProductInFile(std::string, Product*, int, int);
void writeProductInReverseOrder(std::string, Product*, int, int);
int getCountOfRows(std::string);
#pragma endregion

int main()
{
	int size = getCountOfRows("../Text_Files/Product.txt");
	Product* products = readProductFromFile("../Text_Files/Product.txt", size);
	writeProductInFile("../Text_Files/Products.txt",products,size,std::ios_base::out);
	writeProductInReverseOrder("../Text_Files/Products.txt", products, size, std::ios_base::app);
}

#pragma region Functions
int getCountOfRows(std::string fileName)
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

Product* readProductFromFile(std::string fileName, int size)
{
	std::ifstream file(fileName);
	if (!file.is_open())
		return nullptr;
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

void writeProductInFile(std::string fileName, Product* products, int size, int openMode)
{
	std::ofstream file(fileName, openMode);
	if (!file.is_open())
		return;
	for (int i = 0; i < size; i++)
	{
		file << products[i].index << " " << products[i].cost << " " << products[i].name << " " << products[i].count << std::endl;
	}
	file.close();
}

void writeProductInReverseOrder(std::string fileName, Product* products, int size, int openMode)
{
	std::ofstream file(fileName, openMode);
	if (!file.is_open())
		return;
	for (int i = size-1; i>=0; i--)
	{
		file << products[i].index << " " << products[i].cost << " " << products[i].name << " " << products[i].count << std::endl;
	}
	file.close();
}
#pragma endregion