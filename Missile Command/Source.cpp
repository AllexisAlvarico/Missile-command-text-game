#include <iostream>
#include <ctime>
/// <summary>
/// Name: Allexis Alvarico
/// ID: c00242855
/// Date: 24/9/19
/// -----------------------------------
/// Summary:
/// Create a missile command text base game
/// without using classes but structs
/// --------------------------------------
/// Taken time: 6hrs
/// -------------------------------------
/// Known bugs:
/// </summary>


/// <summary>
/// The coordinate of the x and y
/// </summary>
typedef struct Position
{
	int m_x;
	int m_y;

}Coordinates;

/// <summary>
/// Enums for the warhead where theres two warhead ballistic and nuclear
/// </summary>
enum Warhead { Ballistic, Nuclear};

/// <summary>
/// To get the enemy's position
/// </summary>
typedef struct Enemy
{
	Coordinates coordinates; 

}Target;

/// <summary>
/// The object of the structs and the update function
/// </summary>
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

	/// <summary>
	/// updates the coordinates
	/// </summary>
	void update()
	{
		coordinates.m_x += 1;
		coordinates.m_y += 2;
	}

};

int main()
{

	
	
	srand(time(NULL)); // randon generator

	Position base; // the object

	base.m_x = rand() % 20 + 1; // the random x coord for the base
	base.m_y = rand() % 20 + 1; // the random y coord for the base

	missileCommand m_bomb; // the object of the missile struct

	Enemy m_tank; // the enemy tanks object


	bool m_gameover = false; // when the game is on play
	bool m_misssileSelect = true; // selection of warheads
	bool m_target = false; // lockon target
	bool m_missileLaunch = false; // the launching of the missile
	int m_selection; // user input 
	int m_chanceOfHit; // the chance of the warhead hitting the target
	int m_nuclear = 8; // the amount of nukes
	int m_ballistic = 15; // the amount of ballistic
	int m_enemy = 15; // the amount of enemy 
	int m_destroyed = 0; // the destroyed amount of enemy or score

	while (!m_gameover) // if the game is not over
	{
		if (m_misssileSelect) // if selecting a missile
		{
			std::cout << "---------------------------\nYour home base is X:" << base.m_x << " Y:" << base.m_y <<
				"\nArmory:\nNuclear missile " << m_nuclear << "\nBallistic missile: " << m_ballistic
				<< "\n---------------------------\nNuclear Missile = 1 Ballistic Missiles= 2\n---------------------------\nSelect a Warhead: "; //display
			std::cin >> m_selection; // user input
			std::cout << "---------------------------\n"; //display 
			if (m_selection == 1) // if 1
			{
				if (m_nuclear > 0) // if theres is nuke left
				{
					std::cout << "You have selected the nuclear missile\n"; // display
					m_bomb.payload = Warhead::Nuclear; // set the warhead 
					m_target = true; // go to the target
					m_nuclear--; // deduct a missile
					m_misssileSelect = false; // it sets it
				}
				else
				{
					std::cout << "You have no nuclear missile left\n";// display 
					m_misssileSelect = true; // reset the seletion
					m_target = false; // it sets it 
					m_missileLaunch = false; // it sets it
				}
			}
			else if (m_selection == 2) // if 2
			{
				if (m_ballistic > 0) // if there's ballistic missile
				{
					std::cout << "You have selected the ballistic missile\n"; //display
					m_bomb.payload = Warhead::Ballistic; // sets the warhead
					m_ballistic--; // deduct
					m_target = true; // go to the target 
					m_misssileSelect = false; // set it 
				}
				else
				{
					std::cout << "You have no Ballistic missile left\n"; // display 
					m_misssileSelect = true; // reset the selection 
					m_target = false; // it sets it
					m_missileLaunch = false;// it sets it
				}
			}

			if (m_nuclear <= 0 && m_ballistic <= 0) // if no warheads
			{
				std::cout << "You have no longer have the ability to defend your base\n"; // display
				m_gameover = true;
				break;
			}
		}
		if (m_target) // if true
		{

			m_tank.coordinates.m_x = rand() % 20 + 1; // sets a random X value for the enemy
			m_tank.coordinates.m_y = rand() % 20 + 1; // sets a random Y value for the enemy

			std::cout << "---------------------------\nScaning for targets...\nFound multiple contacts: " << m_enemy << "\n---------------------------\nTargeting enemy on X:" << m_tank.coordinates.m_x << " Y:" << m_tank.coordinates.m_y << " coordinates\n";
			std::cout << "You have found tank\nConfirm to launch missile?\nYes = 1 or No = 2\n---------------------------\n"; // display
			std::cin >> m_selection; // user input

			if (m_selection == 1) // if 1
			{
				std::cout << "---------------------------\nLaunching missile\n"; //display
				m_missileLaunch = true; // set it fire
				m_target = false; // set it

			}
			else if (m_selection == 2)
			{
				std::cout << "---------------------------\nAborting missile launch\n";
				m_misssileSelect = true; // reset the selection
			}
			else
			{
				std::cout << "---------------------------\nYour selection is not vaild, canceling launch\n"; // display
				if (m_bomb.payload == Warhead::Nuclear)
				{
					m_nuclear++; // add one again
				}
				else if (m_bomb.payload == Warhead::Ballistic)
				{
					m_ballistic++; // add one again
				}

				m_misssileSelect = true; // go back to the selection
				m_target = false; // set it
			}
		}

		if (m_missileLaunch) // if the missile launched
		{
			std::cout << "The missile has launched standby......\n"; // display

			m_chanceOfHit = rand() % 10 + 1; // random chance of hitting

			if (m_bomb.payload == Warhead::Nuclear) // if warhead 
			{
				if (m_chanceOfHit >= 3) // chance
				{
					std::cout << "The Nuclear Missile has splashed at the target and is destroyed\n"; // display
					m_enemy--; // deduct enemy
					m_destroyed++; // plus one
					m_misssileSelect = true; // go back to the selection
				}
				else
				{
					std::cout << "The Nuclear Missile has failed to calulate on target position.....\nAborting launch\n";//display
					m_nuclear++; // get back the missile
					m_misssileSelect = true; // go back to the missile selection
				}
				std::cout << "---------------------------\nEnemy left : " << m_enemy << "\nEnemy destroyed: " << m_destroyed << "\n"; //display
			}
			if (m_bomb.payload == Warhead::Ballistic) // if
			{
				if (m_chanceOfHit >= 5) // chances of hit
				{
					std::cout << "Ballistic missile has splashed at the target and is destroyed\n"; // display
					m_enemy--; // deduct enemy
					m_destroyed++; // plus one
					m_misssileSelect = true; // go back to the selection
				}
				else
				{
					std::cout << "Ballistic missile has failed to calulate on target position.....\nAborting launch\n"; //display
					m_ballistic++; // add back the missile
					m_misssileSelect = true; // go back to the selection
				}
			std::cout << "---------------------------\nEnemy left : " << m_enemy << "\n Enemy destroyed : " << m_destroyed << "\n"; // display
			}

		}

		if (m_enemy <= 0) // if 0
		{
			std::cout << "---------------------------\nyou successfully defended your base!!!!\n"; //display
			m_gameover = true; // you won the game
		}

	}
	system("PAUSE");
}