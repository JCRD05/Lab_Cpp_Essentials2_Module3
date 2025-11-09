#include <iostream>
#include <array>
#include <string>
#include <sstream>

class IpAddress
{
private:
	std::array<int, 4> octets;

	int parse(std::stringstream& ss)
	{
		std::string octet{};

		if (!std::getline(ss, octet, '.'))
		{
			throw std::invalid_argument("invalid input, ip address has less than four octets");
		}

		if (octet.empty())
		{
			throw std::invalid_argument("invalid input, the octet is empty");
		}

		for (auto character : octet)
		{
			if (!std::isdigit(character)) 
			{ 
				throw std::invalid_argument("invalid input, character " + std::string(1,character) + " is not a digit");
			}
		}

		int octetValue = std::stoi(octet);
		if (octetValue < 0 || octetValue > 255)
		{
			throw std::invalid_argument("invalid input, the octet is out of the valid range: 0-255");
		}

		return octetValue;
	}

	bool isPowerOfTwo(int n) 
	{
		if (n <= 0) 
		{
			return false;
		}
		// Check if n has only one bit set.
		return (n & (n - 1)) == 0;
	}

public:
	IpAddress(const std::string& ipAddress)
	{
		std::stringstream ss(ipAddress);

		for (size_t i = 0; i < 4; i++)
		{
			octets[i] = parse(ss);
		}

		char excess{};

		if (ss >> excess) { throw std::invalid_argument("invalid input, ip address has more than four octets"); }
	}

	void printSubnet(const int subnetMask)
	{
		if(subnetMask > 256)
		{
			throw std::invalid_argument("invalid input, subnest is out of range");
		}

		if(!isPowerOfTwo(subnetMask))
		{
			throw std::invalid_argument("invalid input, subnet is not a power of two");
		}

		int subnet = octets[3] & (256 - subnetMask);

		std::cout << octets[0] << '.' << octets[1] << '.' << octets[2] << '.' << subnet;
	}
};

int main()
{
	std::string ipAddress{};
	std::cin >> ipAddress;

	int subnetMask{};
	std::cin >> subnetMask;
	try
	{
		IpAddress ip1(ipAddress);
		ip1.printSubnet(subnetMask);
	}
	catch (const std::invalid_argument& e) { std::cout << e.what(); }
}