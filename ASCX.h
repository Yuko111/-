#ifndef _AssaultCube_H_
#define _AssaultCube_H_

#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>

// Ofsetler
#define LOCAL_PLAYER_ADR 0x509B74
#define HEALTH_OFFSET 0xF8
#define ARMOR_OFFSET 0xFC
#define AMMO_OFFSET 0x150
#define PLAYER_NAME_OFFSET 0x225


class ASCX {

public:
	
	ASCX();
	
	void displayMessage()const; // Karşılama Mesajı
	
	void PlayerInfos()const; // Karakter Bilgileri
	void SearchHandleAndProcID(); // Proccess İd al
	void Health();
	void ModHealth();
	void Ammo();
	void ModAmmo();
	void Armor();
	void ModArmor();
	~ASCX();
private:
	HWND hwnd;
	DWORD procID;
	HANDLE handle;
	int newHealth;
	int newAmmo;
	int newArmor;
	int *laddress;
	std::string *kname;
	int* kHP;
	int* kAP;
	int* kAM;
	int nHealth;
	int nArmor;
	int nAmmo;
	
};
