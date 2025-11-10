#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

class InvalidTowerException : public std::exception {
public:
	const char* what() const noexcept override {
		return "Input Error: Tower must be in the range 1-3.";
	}
};

class IllegalMoveException : public std::exception {
public:
	const char* what() const noexcept override {
		return "Move Error: Cannot place a larger disk onto a smaller disk.";
	}
};

class EmptyTowerException : public std::exception {
public:
	const char* what() const noexcept override {
		return "Move Error: Source tower is empty.";
	}
};

class Node
{
public:
	int data;
	Node* next;

	Node(int data, Node* next)
	{
		this->data = data;
		this->next = next;
	}

	Node(int data)
	{
		this->data = data;
		next = nullptr;
	}
};

class Stack
{
public:
	Node* head;
	int length;

private:
	std::string name;

public:
	Stack(std::string name)
	{
		this->name = name;
		head = nullptr;
		length = 0;
	}

	~Stack()
	{
		Node* current = head;
		while (current != nullptr)
		{
			Node* temp = current;
			current = current->next;
			delete temp;
		}
	}

	void Push(int data)
	{
		if (IsEmpty()) { head = new Node(data); }
		else { head = new Node(data, head); }
		length++;
	}

	int Pop()
	{
		if (IsEmpty()) { return 0; }

		int erasedData = head->data;
		Node* nodeToDelete = head;

		if (length == 1) { head = nullptr; }
		else { head = head->next; }

		delete nodeToDelete;
		length--;

		return erasedData;
	}

	int Peek()
	{
		if (IsEmpty()) { return 0; }
		else { return head->data; }
	}

	void SimplePrint()
	{
		if (IsEmpty())
		{
			std::cout << "empty;" << std::endl;
		}
		else
		{
			Node* current = head;
			while (current != nullptr)
			{
				std::cout << current->data << " ";
				current = current->next;
			}
			std::cout << ";" << std::endl;
		}
	}

	bool IsEmpty()
	{
		if (length == 0) { return true; }
		else { return false; }
	}
};

class Tower
{
public:
	Stack* disks;
	std::string name;

	Tower(std::string name, int number)
	{
		this->name = name;
		disks = new Stack(name);
		for (int i = 0; i < number; i++)
		{
			disks->Push(number - i);
		}
	}

	Tower(std::string name)
	{
		this->name = name;
		disks = new Stack(name);
	}

	~Tower()
	{
		delete disks;
	}

	void Move(Tower* tower)
	{
		if (disks->IsEmpty())
		{
			throw EmptyTowerException();
		}

		if (Get() > tower->Get() && tower->Get() != 0)
		{
			throw IllegalMoveException();
		}

		tower->disks->Push(disks->Pop());
	}

	int Get()
	{
		return disks->Peek();
	}
};

class Game
{
public:
	Tower* tower1;
	Tower* tower2;
	Tower* tower3;
	int diskNumber;

public:
	Game()
	{
		tower1 = nullptr;
		tower2 = nullptr;
		tower3 = nullptr;
		diskNumber = 0;
	}

	~Game()
	{
		delete tower1;
		delete tower2;
		delete tower3;
	}

	Tower* GetTower(int id) {
		switch (id) {
		case 1: return tower1;
		case 2: return tower2;
		case 3: return tower3;
		default:
			throw InvalidTowerException();
		}
	}

	void PrintTowersSimple()
	{
		std::cout << "  " << tower1->name << ": ";
		tower1->disks->SimplePrint();
		std::cout << "  " << tower2->name << ": ";
		tower2->disks->SimplePrint();
		std::cout << "  " << tower3->name << ": ";
		tower3->disks->SimplePrint();
		std::cout << "---------------------------------" << std::endl;
	}

	bool Win()
	{
		if (tower3->disks == nullptr) { return false; }
		if (tower3->Get() == 1 && tower3->disks->length == diskNumber)
		{
			return true;
		}
		return false;
	}

	void Play(Tower* towerA, Tower* towerB)
	{
		towerA->Move(towerB);
		std::cout << "Move " << towerA->name << " -> " << towerB->name << std::endl;
		PrintTowersSimple();
	}

	void DemonstrateSolution()
	{
		std::cout << "--- Demonstrating 3-Disk Solution (7 moves) ---" << std::endl;
		delete tower1;
		delete tower2;
		delete tower3;

		tower1 = new Tower("Tower 1", 3);
		tower2 = new Tower("Tower 2");
		tower3 = new Tower("Tower 3");
		diskNumber = 3;

		std::cout << "Initial state:" << std::endl;
		PrintTowersSimple();

		Play(tower1, tower3);
		Play(tower1, tower2);
		Play(tower3, tower2);
		Play(tower1, tower3);
		Play(tower2, tower1);
		Play(tower2, tower3);
		Play(tower1, tower3);

		std::cout << "--- Solution Complete ---" << std::endl;

		std::cout << "\nNow, you play." << std::endl;
		std::cout << "Press Enter To Start..." << std::endl;

		std::cin.ignore(1024, '\n');
	}

	void Start()
	{
		std::cout << "\nWelcome To The Tower Of Hanoi Game\n" << std::endl;

		DemonstrateSolution();
		GameLoop();
	}

	void GameLoop()
	{
		std::cout << "Enter The Number Of Disks: ";
		std::cin >> diskNumber;
		std::cin.ignore(1024, '\n');

		delete tower1;
		delete tower2;
		delete tower3;

		tower1 = new Tower("Tower 1", diskNumber);
		tower2 = new Tower("Tower 2");
		tower3 = new Tower("Tower 3");

		std::cout << "\nStarting manual game:" << std::endl;
		PrintTowersSimple();

		int fromId = 0;
		int toId = 0;
		do
		{
			std::cout << "Enter move (from to, e.g., 1 2. Enter 0 0 to exit): ";

			if (!(std::cin >> fromId >> toId)) {
				std::cin.clear();
				std::cin.ignore(1024, '\n');
				std::cerr << "Invalid input. Please enter two numbers." << std::endl;
				continue;
			}

			if (fromId == 0 || toId == 0) { break; }

			try
			{
				if (fromId == toId) {
					std::cout << "Empty move (e.g., 11). No change." << std::endl;
					continue;
				}

				Tower* fromTower = GetTower(fromId);
				Tower* toTower = GetTower(toId);

				Play(fromTower, toTower);

				if (Win())
				{
					std::cout << "******************" << std::endl;
					std::cout << "!!! YOU WON! !!!" << std::endl;
					std::cout << "******************" << std::endl;
					break;
				}
			}
			catch (const std::exception& e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
				std::cout << "Please try a different move." << std::endl;
			}

		} while (fromId != 0 && toId != 0);

		std::cout << "Thanks For Playing!" << std::endl;
	}
};

int main()
{
	Game game;
	game.Start();
	return 0;
}