#include <iostream>
#include <stdexcept>
#include <array>
#include <string>
#include <sstream>

class IpAddress
{
private:
	std::array<int, 4> octets;
	std::string type;

	int check(std::stringstream& ss)
	{
		std::string octet{};

		if (!std::getline(ss, octet, '.'))
		{
			throw std::invalid_argument(type + ": invalid input, ip address has less than four octets");
		}

		if (octet.empty())
		{
			throw std::invalid_argument(type + ": invalid input, the octet is empty");
		}

		for (auto character : octet)
		{
			if (!std::isdigit(character))
			{
				throw std::invalid_argument(type + ": invalid input, character " + std::string(1, character) + " is not a digit");
			}
		}

		int octetValue = std::stoi(octet);
		if (octetValue < 0 || octetValue > 255)
		{
			throw std::invalid_argument(type + ": invalid input, the octet is out of the valid range: 0-255");
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
	IpAddress(const std::string& ipAddress, const std::string& ipType) : type(ipType)
	{
		std::stringstream ss(ipAddress);

		for (size_t i = 0; i < 4; i++)
		{
			octets[i] = check(ss);
		}

		char excess{};

		if (ss >> excess) { throw std::invalid_argument(type + ": invalid input, ip address has more than four octets"); }
	}

	void printSubnet(const int subnetMask)
	{
		if (subnetMask > 256)
		{
			throw std::invalid_argument(type + ": invalid input, subnet is out of range");
		}

		if (!isPowerOfTwo(subnetMask))
		{
			throw std::invalid_argument(type + ": invalid input, subnet is not a power of two");
		}

		int subnet = octets[3] & (256 - subnetMask);

		std::cout << octets[0] << '.' << octets[1] << '.' << octets[2] << '.' << subnet;
	}

	std::string getAddress()
	{
		std::string ipAddress{};

		ipAddress = std::to_string(octets[0]) + '.' + std::to_string(octets[1]) + '.' + 
			std::to_string(octets[2]) + '.' + std::to_string(octets[3]);

		return ipAddress;
	}
};

class IpHeader 
{
private:
	std::string inputSource;
	std::string inputDestination;
	IpAddress sourceIp;
	IpAddress destinationIp;

public:
	IpHeader(const std::string& source, const std::string& destination)
		: inputSource(source), inputDestination(destination),
		sourceIp(source, "source"), destinationIp(destination, "destination") {}
};

int main()
{
	std::cout << "input a source and destination address: ";
	std::string source{};
	std::string destination{};
	std::cin >> source >> destination;

	try
	{
		IpHeader ipHeader(source, destination);
		std::cout << "Ip header succesfully created!";
	}
	catch (std::invalid_argument& e) { std::cout << e.what(); }
}