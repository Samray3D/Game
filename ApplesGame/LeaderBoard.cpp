#include "LeaderBoard.h"
#include <cstdlib>
#include <ctime>
#include <iostream>


namespace ApplesGame
{
	void InitLeaderboard(std::vector<Record>& leaderboard)
	{
		leaderboard.clear();

		leaderboard.push_back({ "Alice", 100 });
		leaderboard.push_back({ "Bob", 85 });
		leaderboard.push_back({ "Carol", 60 });
		leaderboard.push_back({ "Dave", 40 });
		
	}

	void AddRecord(std::vector<Record>& leaderboard, const std::string& name, int score)
	{
		leaderboard.push_back({ name, score });
	}

	void SortLeaderboard(std::vector<Record>& leaderboard)
	{
		for (int i = 0; i < leaderboard.size() - 1 ; ++i)
			for (int j = 0; j < leaderboard.size() - i - 1; ++j)
				if (leaderboard[j].score < leaderboard[j + 1].score)
				{
					Record temp = leaderboard[j];
					leaderboard[j] = leaderboard[j + 1];
					leaderboard[j + 1] = temp;
				}
	}

	void UpdatePlayerName(std::vector<Record>& leaderboard, const std::string& oldName, const std::string& newName)
	{
		for (int i = 0; i < leaderboard.size(); ++i)
		{
			if (leaderboard[i].name == oldName)
			{
				leaderboard[i].name = newName;
				break;
			}
		}
	}

	void PrintLeaderboard(std::vector<Record>& leaderboard)
	{
		for (int i = 0; i < leaderboard.size(); ++i)
		{
			std::cout << i + 1 << ". " << leaderboard[i].name << " " << leaderboard[i].score << std::endl;
		}
	}

	void UpdateRecordScore(std::vector<Record>& leaderboard, const std::string& name, int newScore)
	{
		for (int i = 0; i < leaderboard.size(); ++i)
		{
			if (leaderboard[i].name == name)
			{
				leaderboard[i].score = newScore;
				return;
			}

		}
		leaderboard.push_back({ name, newScore });
	}
}
