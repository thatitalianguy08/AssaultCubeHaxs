#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>

DWORD pid;
DWORD Ammo = 0x00834C68;
DWORD Health = 0x00834C14;
int desAMMO = 999999;
int desHealth = 999999;
int ammoValue;
int healthValue;

//Function to load the cmd thingy 
int loadFrame()
{
	std::cout << R"(    _                        _ _      ____      _            _   _            
   / \   ___ ___  __ _ _   _| | |_   / ___|   _| |__   ___  | | | | __ ___  __
  / _ \ / __/ __|/ _` | | | | | __| | |  | | | | '_ \ / _ \ | |_| |/ _` \ \/ /
 / ___ \\__ \__ \ (_| | |_| | | |_  | |__| |_| | |_) |  __/ |  _  | (_| |>  < 
/_/   \_\___/___/\__,_|\__,_|_|\__|  \____\__,_|_.__/ \___| |_| |_|\__,_/_/\_\)" << '\n';

	std::cout << "" << std::endl;
	std::cout << "Version >> 0.0.1" << std::endl;
	std::cout << "" << std::endl;
	std::cout << R"(Github >> https://github.com/ChromatiKa/AssaultCubeHax)" << std::endl;
	return 0;


}

int main()
{	

	loadFrame();
	//Find the window's name
	HWND hWnd = FindWindowA(0, ("AssaultCube"));

	//No damn clue what this does!
	GetWindowThreadProcessId(hWnd, &pid);

	//Open the process
	HANDLE pHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	
	//Read the damn memory (Ammo)
	ReadProcessMemory(pHandle, (void*)Ammo, &ammoValue, sizeof(ammoValue), 0);

	//Read the damn memory (HP)
	ReadProcessMemory(pHandle, (void*)Health, &healthValue, sizeof(healthValue), 0);


	

	while (true) {
		//Write the actual memory!!! (Ammo)
		WriteProcessMemory(pHandle, (LPVOID)Ammo, &desAMMO, sizeof(int), 0);
		//Write memory for health!!!
		WriteProcessMemory(pHandle, (LPVOID)Health, &desHealth, sizeof(int), 0);
	}
	
	

}





