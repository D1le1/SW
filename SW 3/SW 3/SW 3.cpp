#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

struct Product
{
	int index = 0;
	double cost = 0.0;
	std::string name = "Potato";
	int count = 0;
};


#pragma region DescribeFunctions
Product* readProductFromFile(std::string, int&);
void writeProductInFile(std::string, Product*, int, int);
void writeProductInReverseOrder(std::string, Product*, int, int);
int getCountOfRows(std::string);
int getFileSize(std::string);
void sortProductByName(Product*, int);
#pragma endregion

int main()
{
	int size = 0;
	Product* products = readProductFromFile("../Text_Files/Product.txt", size);
	writeProductInFile("../Text_Files/Products.txt", products, size, std::ios_base::out);
	writeProductInReverseOrder("../Text_Files/Products.txt", products, size, std::ios_base::app);
	int fileSize = getFileSize("../Text_Files/Products.txt");
	std::cout << "File size = " << fileSize;
	products = readProductFromFile("../Text_Files/Products.txt", size);
	sortProductByName(products, size);
	writeProductInFile("../Text_Files/Products.txt", products, size, std::ios_base::out);
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

Product* readProductFromFile(std::string fileName, int& size)
{
	std::ifstream file(fileName);
	if (!file.is_open())
		return nullptr;
	size = getCountOfRows(fileName);
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

int getFileSize(std::string fileName)
{
	std::ifstream file(fileName);
	if (!file.is_open())
		return 0;
	int fileSize = 0;
	file.seekg(0, std::ios_base::end);
	fileSize=file.tellg();
	file.close();
	return fileSize;
}

bool compare(Product left, Product right)
{
	if (left.name < right.name)
		return 1;
	else
		return 0;
}

void sortProductByName(Product* products, int size)
{
	std::sort(products, products + size, compare);
}
#pragma endregion