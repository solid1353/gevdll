#pragma once

#include <stdio.h>
#include <windows.h>
#include "Vector3.h"
#include "ccBattleInputs.h"

using namespace std;

enum Players
{
	Player1, //0
	Player2, //1
	Player1_Support1, //so on
	Player1_Support2,
	Player2_Support1,
	Player2_Support2,
};

namespace moddingApi
{
	class ccPlayer
	{
	public:
		static uintptr_t plMain[6];
		static int plMainId[6];
		// static vector<string> matchup;
		static void Start();
		static void Loop();

		static void InitializeCharacter(int c, int plNum);
		static void DeleteCharacter(int c, int plNum);
		static void DoCharacterLoop(int c, int plNum);

		static void GetGamepadState(int n, std::vector<bool> inputs);

		static uintptr_t GetPlayerStatus(int player);
		static uintptr_t GetPlayerInfo(int n);
		static uintptr_t GetSystemInfo();
		static uintptr_t GetPlayerLSCostPointer(uintptr_t p);
		static void SetPlayerLSCost(uintptr_t p, float value);
		static int GetPlayerStatusNumber(uintptr_t s);
		static int GetPlayerInfoNumber(uintptr_t s);

		static uintptr_t GetStormPointer(int n);
		static float GetStormGauge(int n);
		static void SetStormGauge(int n, float value);
		static uintptr_t GetMatchPointer();
		static int GetMatchCount();
		static void SetMatchCount(int value);

		static int* GetPlayerIntPointer(uintptr_t p, uintptr_t s, char* prop);
		static int GetPlayerIntProperty(uintptr_t p, uintptr_t s, char* prop);
		static void SetPlayerIntProperty(uintptr_t p, uintptr_t s, char* prop, int value);
		static void SetPlayerStatePropertyEasy(uintptr_t p, uintptr_t s, char* prop);
		static void SetPlayerStateProperty(uintptr_t p, uintptr_t s, int prop);

		static float* GetPlayerFloatPointer(uintptr_t p, uintptr_t s, char* prop);
		static float GetPlayerFloatProperty(uintptr_t p, uintptr_t s, char* prop);
		static void SetPlayerFloatProperty(uintptr_t p, uintptr_t s, char* prop, float value);

		static Vector3 GetPlayerPosition(uintptr_t p, uintptr_t s);
		static float GetPlayerDistance(uintptr_t p, uintptr_t s, uintptr_t ep, uintptr_t es);

		static string charcode2str(int charcode);
		static int Timer(int timeAmt);
		static void SetTimerValue(int timerValue, int maxTimer, bool value);

		// Placeholders, change order when functions are done
		static int GetCanDoJutsuChakra(uintptr_t p, uintptr_t s);
		static int GetAwakenedState(uintptr_t p, uintptr_t s);

		static void InitializePlayer(Players player);
		static void disable_armor_break(uintptr_t player_info, uintptr_t player_status);
		static void perfect_cancel(uintptr_t player_info, uintptr_t player_status);
		static void disable_storm_gauge(Players player);
		static void main_loop(Players player);
	private:
		//int prevFrame = 0;
		//int prevBattle = 0;
		static vector<uintptr_t> memcpy_verify(vector<uintptr_t> ptrs, vector<uintptr_t> offsets, size_t size);
		static int LoopForNum(int loopAmt, uintptr_t compare, uintptr_t(*f)(int));
		static constexpr unsigned int str2int(const char* str, int h);
	};
}