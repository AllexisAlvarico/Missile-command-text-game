#include <iostream>
#include <ctime>



typedef struct Position
{
	int m_x;
	int m_y;

	void print()
	{
		std::cout << m_x << m_y << std::endl;
	}



}Coordinates;


enum Warhead { Explosive, Nuclear, Failure, Destroyed };

typedef struct Enemy
{
	Coordinates coordinates;

}Target;

struct missileCommand
{
	Warhead payload;

	Coordinates coordinates;

	Target target;

	bool m_armed;


	//void arm()
	//{
	//	if (arm)
	//	{
	//		m_armed = false;
	//	}
	//	else
	//	{
	//		m_armed = true;
	//	}
	//}


	void update()
	{
		coordinates.m_x += 1;
		coordinates.m_y += 2;
	}

};

int main()
{


	
	srand(time(NULL));

	Position base;

	base.m_x = rand() % 20 + 1;
	base.m_y = rand() % 20 + 1;

	missileCommand bomb;

	Enemy division;

	division.coordinates.m_x = rand() % 20 + 1;
	division.coordinates.m_y = rand() % 20 + 1;

	bool m_gameover = false;
	bool m_misssileSelect = true;
	int m_selection;
	int m_nuke = 1;
	int m_bomb = 2;

	while (!m_gameover)
	{
		if (m_misssileSelect)
		{
			std::cout << "Your home base is X:" << base.m_x << " Y:" << base.m_y << "\n";
			std::cout << "Nuke = 1\nBomb = 2\nSelect a Warhead: ";
			std::cin >> m_selection;
			if (m_selection == m_nuke)
			{
				std::cout << "You have selected the Nuke\n";
				bomb.payload = Warhead::Nuclear;
				m_misssileSelect = false;
				break;
			}
			else if (m_selection == m_bomb)
			{
				std::cout << "You have selected the Bomb\n";
				bomb.payload = Warhead::Explosive;
				m_misssileSelect = false;
				break;
			}
			else
			{
				std::cout << "The missile you selected is not in the armorary\n";
			}
		}	
	}


	std::cout << "Looking for targets: ";

	std::cout << "Select the Coordinates: ";

	std::cout << "You have hit the target!! ";

	std::cout << "You have destroyed the target";

	std::cout << "You have missed the target!! ";
	
	bomb.update();


	system("PAUSE");
}