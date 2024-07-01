#include "pch.h"
#include "Engine.h"



// Lobby 입장

// 캐릭터 선택

// 필드입장 및 게임 종료




void PrintLobby()
{
	cout << "------------------------" << endl;
	cout << "로비에 입장했습니다." << endl;
	cout << "------------------------" << endl;

}



int main()
{
	PrintLobby();
	Engine gameEngine;

	gameEngine.JobChoice();




}
