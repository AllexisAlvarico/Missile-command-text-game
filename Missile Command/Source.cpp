#include <iostream>



struct missileCommand
{
	Warhead payload;

	Coordinates coordinates;

	Target target;

	bool m_armed;

	void arm()
	{
		if (arm)
		{
			m_armed = false;
		}
		else
		{
			m_armed = true;
		}
	}


	void update()
	{
		//coordinates.x =
	}

};


struct Position
{
	int m_x;
	int m_y;

	void print()
	{
		std::cout << m_x << m_y << std::endl;
	}

}Coordinates;


enum Warhead { Explosive, Nuclear };


struct Enemy
{

	
}; /*Target;*/



int main()
{

	std::cout << "Select a Warhead: ";

	std::cout << "Looking for targets: ";

	std::cout << "Select the Coordinates: ";

	std::cout << "You have hit the target!! ";

	std::cout << "You have missed the target!! ";







	system("PAUSE");
}