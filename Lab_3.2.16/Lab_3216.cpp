#include <iostream>
#include <fstream>
#include <stdexcept>
#include <array>

class Matrix
{
private:
	std::array<double,4> values;

public:
	Matrix() = default;

	void loadFromFile(const std::string& filename) 
	{
		std::ifstream file(filename);
		if (!file.is_open()) { throw std::runtime_error("error trying to open file: " + filename + '\n'); }

		for(auto value : values)
		{
			if (!(file >> value)) { throw std::runtime_error("error reading from file\n"); }
		}

		file.close();
	}

	void writeToFile(const std::string& filename) 
	{
		std::ofstream file(filename);
		if (!file.is_open()) { throw std::runtime_error("error trying to open file: " + filename + '\n'); }

		for (auto value : values)
		{
			if (!(file << value)) { throw std::runtime_error("error writing from file\n"); }
		}

		file.close();
	}
};

int main()
{
	Matrix matrix;
	std::string loadFilename = "nonexistent_file.txt";
	std::string saveFilename = "protected_directory/matrix.txt";

	try
	{
		matrix.loadFromFile(loadFilename);
	}
	catch (std::runtime_error& e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		matrix.writeToFile(saveFilename);
	}
	catch (std::runtime_error& e)
	{
		std::cout << e.what() << '\n';
	}
}