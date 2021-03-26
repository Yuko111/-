#include "AssaultCube.h"
#include <stdexcept>


ASCX::ASCX() {

	
}


void ASCX::SearchHandleAndProcID() {

	hwnd = FindWindowA(NULL, "AssaultCube"); //Pencere ismi bul

	if (!hwnd)
		throw std::runtime_error("Oyun Bulunamadı !");
	else {
		DWORD drm = GetWindowThreadProcessId(hwnd, &procID); // Pencere isminin işlem kimliğini al
		if (!drm)
			throw std::runtime_error("AssaultCube işlem kimliği bulunamadı !");
		else {
			std::cerr << "Erişim Sağlandı." << std::endl;

			handle = OpenProcess(PROCESS_ALL_ACCESS, NULL, procID); // Tüm yetkilerle aç
		}

	}

}



void ASCX::PlayerInfos()const {

	ReadProcessMemory(handle, (LPVOID*)LOCAL_PLAYER_ADR, laddress, sizeof(laddress), NULL); // local player addr oku.  *LpNumberofthebytesread (NULL) yazılarak parametre göz ardı edildi.
	ReadProcessMemory(handle, (LPVOID*)(&laddress + PLAYER_NAME_OFFSET), kname, sizeof(kname), NULL); // Local player adresten player name offset kadar uzaklıktaki veriyi oku.
	std::cout << "Name:" << *kname << std::endl;
	ReadProcessMemory(handle, (LPVOID*)LOCAL_PLAYER_ADR, laddress, sizeof(laddress), NULL);
	ReadProcessMemory(handle, (LPVOID*)(laddress + HEALTH_OFFSET), kHP, sizeof(kHP), NULL); 
	std::cout << "Health:" << *kHP << std::endl;
	ReadProcessMemory(handle, (LPVOID*)LOCAL_PLAYER_ADR, laddress, sizeof(laddress), NULL);
	ReadProcessMemory(handle, (LPVOID*)(laddress + ARMOR_OFFSET), kAP, sizeof(kAP), NULL);
	std::cout << "Armor:" << *kAP << std::endl;
	ReadProcessMemory(handle, (LPVOID*)LOCAL_PLAYER_ADR, laddress, sizeof(laddress), NULL);
	ReadProcessMemory(handle, (LPVOID*)(laddress + AMMO_OFFSET), kAM, sizeof(kAM), NULL);
	std::cout << "Ammo:" << *kAM << std::endl;
}




void ASCX::Health() {

	ReadProcessMemory(handle, (LPVOID*)LOCAL_PLAYER_ADR, laddress, sizeof(laddress), NULL); // soldakini sağdakine ata.
	nHealth = 100;
	WriteProcessMemory(handle, (LPVOID*)(laddress + HEALTH_OFFSET), &nHealth, sizeof(nHealth), NULL);  // sağdakini soldaki ile değiştir.

}

void ASCX::ModHealth() {
	ReadProcessMemory(handle, (LPVOID*)LOCAL_PLAYER_ADR, laddress, sizeof(laddress), NULL);
	newHealth = 9999;

	WriteProcessMemory(handle, (LPVOID*)(laddress + HEALTH_OFFSET), &newHealth, sizeof(newHealth), NULL);
}

void ASCX::Armor() {

	ReadProcessMemory(handle, (LPVOID*)LOCAL_PLAYER_ADR, laddress, sizeof(laddress), NULL);
	WriteProcessMemory(handle, (LPVOID*)(laddress + ARMOR_OFFSET), &nArmor, sizeof(nArmor),NULL);

}

void ASCX::ModArmor() {

	ReadProcessMemory(handle, (LPVOID*)LOCAL_PLAYER_ADR, laddress, sizeof(laddress), NULL);
	WriteProcessMemory(handle, (LPVOID*)(laddress + ARMOR_OFFSET), &newArmor, sizeof(newArmor), NULL);

}

void ASCX::Ammo() {

	ReadProcessMemory(handle, (LPVOID*)LOCAL_PLAYER_ADR, laddress, sizeof(laddress), NULL);
	WriteProcessMemory(handle, (LPVOID*)(laddress + AMMO_OFFSET), &nAmmo, sizeof(nAmmo), NULL);

}

void ASCX::ModAmmo() {
	ReadProcessMemory(handle, (LPVOID*)LOCAL_PLAYER_ADR, laddress, sizeof(laddress), NULL);
	WriteProcessMemory(handle, (LPVOID*)(laddress + AMMO_OFFSET), &newAmmo, sizeof(newAmmo), NULL);
}


void ASCX::displayMessage()const {

	std::cerr << "Welcome To First Trainer !!! " << std::endl;

}

ASCX::~ASCX() {
	delete laddress;
	delete kHP;
	delete kAP;
	delete kAM;
	delete kname;
}
