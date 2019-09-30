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


	bool m_gameover = false;
	bool m_misssileSelect = true;
	bool m_target = false;
	bool m_missileLaunch = false;
	int m_selection;
	int m_chanceOfHit;
	int m_nuclear = 1;
	int m_ballistic = 20;
	int m_enemy = 10;
	int m_destroyed = 0;
	int m_disabled = 0;

	while (!m_gameover)
	{
		if (m_misssileSelect)
		{
			std::cout << "---------------------------\nYour home base is X:" << base.m_x << " Y:" << base.m_y <<
				"\nArmory:\nNuclear missile " << m_nuclear << "\nBallistic missile: " << m_ballistic
				<< "\n---------------------------\nNuclear Missile = 1 Ballistic Missiles= 2\n---------------------------\nSelect a Warhead: ";
			std::cin >> m_selection;
			std::cout << "---------------------------\n";
			if (m_selection == 1)
			{
				if (m_nuclear > 0)
				{
					std::cout << "You have selected the nuclear missile\n";
					bomb.payload = Warhead::Nuclear;
					m_target = true;
					m_nuclear--;
					m_misssileSelect = false;
				}
				else
				{
					std::cout << "You have no nuclear missile left\n";
					m_misssileSelect = true;
					m_target = false;
					m_missileLaunch = false;
				}
			}
			else if (m_selection == 2)
			{
				std::cout << "You have selected the ballistic missile\n";
				bomb.payload = Warhead::Explosive;
				m_ballistic--;
				m_target = true;
				m_misssileSelect = false;
			}
			else
			{
				std::cout << "You have no Ballistic missile left\n";
				m_misssileSelect = true;
				m_target = false;
				m_missileLaunch = false;
			}
		}
		if (m_target)
		{

			division.coordinates.m_x = rand() % 20 + 1;
			division.coordinates.m_y = rand() % 20 + 1;

			std::cout << "---------------------------\nScaning for targets...\n Found multiple contacts: " << m_enemy << "\n---------------------------\nTargeting enemy on X:" << division.coordinates.m_x << " Y:" << division.coordinates.m_y << " coordinates\n";
			std::cout << "You have found tank\nConfirm to launch missile?\nYes = 1 or No = 2\n---------------------------\n";
			std::cin >> m_selection;

			if (m_selection == 1)
			{
				std::cout << "---------------------------\nLaunching missile\n";
				m_missileLaunch = true;
				m_target = false;

			}
			else if (m_selection == 2)
			{
				std::cout << "Aborting missile launch";
				m_misssileSelect = true;
			}
			else
			{
				std::cout << "---------------------------\nYour selection is not vaild, canceling launch\n";
				if (bomb.payload == Warhead::Nuclear)
				{
					m_nuclear++;
				}
				else if (bomb.payload == Warhead::Explosive)
				{
					m_ballistic++;
				}

				m_misssileSelect = true;
				m_target = false;
			}
		}

		if (m_missileLaunch)
		{
			std::cout << "The missile has launched standby......\n";

			m_chanceOfHit = rand() % 10 + 1;

			if (bomb.payload == Warhead::Nuclear)
			{
				if (m_chanceOfHit >= 3)
				{
					std::cout << "The Nuclear Missile has splashed at the target and is destroyed\n";
					m_enemy--;
					m_destroyed++;
					m_misssileSelect = true;
				}
				else
				{
					std::cout << "The Nuclear Missile has failed to connect on target but the target is disabled\n";
					m_enemy--;
					m_disabled++;
					m_misssileSelect = true;
				}
			}
			if (bomb.payload == Warhead::Explosive)
			{
				if (m_chanceOfHit >= 5)
				{
					std::cout << "Ballistic missile has splashed at the target and is destroyed\n";
					m_enemy--;
					m_misssileSelect = true;
				}
				else
				{
					std::cout << "Ballistic missile has failed to connect on target\n";
					m_misssileSelect = true;
				}
			}

		}

	}
	
	bomb.update();


	system("PAUSE");
}