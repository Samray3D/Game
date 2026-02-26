#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include <string>
#include <vector>


namespace ApplesGame
{
	struct Record
	{
		std::string name;
		int score;
	};

	struct Game;

	void InitLeaderboard(std::vector<Record>& leaderboard); 
	void AddRecord(std::vector<Record>& leaderboard, const std::string& name, int score); //add player
	void SortLeaderboard(std::vector<Record>& leaderboard);
	void UpdatePlayerName(std::vector<Record>& leaderboard, const std::string& oldName, const std::string& newName); //upd name before start
	void PrintLeaderboard(std::vector<Record>& leaderboard);
	void UpdateRecordScore(std::vector<Record>& leaderboard, const std::string& name, int newScore);

}
