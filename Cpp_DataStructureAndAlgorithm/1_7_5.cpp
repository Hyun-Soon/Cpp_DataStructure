//카드 게임 시뮬레이션
#include <iostream>
#include <sstream>
#include <array>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>

struct card
{
	int number;

	enum suit
	{
		HEART,
		SPADE,
		CLUB,
		DIAMOND,
	} suit;

	std::string to_string() const
	{
		std::ostringstream os;

		if (number > 1 && number <= 10)
			os << number;
		else
		{
			switch (number)
			{
			case 1:
				os << "Ace";
				break;
			case 11:
				os << "Jack";
				break;
			case 12:
				os << "Queen";
			case 13:
				os << "King";
				break;
			default:
				return "Invalid card";

			}
		}

		os << " of ";

		switch (suit)
		{
		case HEART:
			os << "hearts";
			break;
		case SPADE:
			os << "spade";
			break;
		case CLUB:
			os << "clubs";
			break;
		case DIAMOND:
			os << "diamonds";
			break;
		}

		return os.str();
	}
	
};

struct game 
{
	std::array<card, 52> deck;
	std::vector<card> player1, player2, player3, player4;

	void buildDeck()
	{
		for (int i = 0; i < 13; ++i)
			deck[i] = card{ i+1 , card::HEART};
		for (int i = 0; i < 13; ++i)
			deck[i] = card{ i + 1, card::SPADE };
		for (int i = 0; i < 13; ++i)
			deck[i] = card{ i + 1, card::CLUB };
		for (int i = 0; i < 13; ++i)
			deck[i] = card{ i + 1, card::DIAMOND };
	}

	void dealCards()
	{
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::shuffle(deck.begin(), deck.end(), std::default_random_engine(seed));
		player1 = { deck.begin(), deck.begin() + 13 };
		player2 = { deck.begin() + 13, deck.begin() + 26};
		player3 = { deck.begin() + 26, deck.begin() + 39 };
		player4 = { deck.begin() + 39, deck.end() };
	}
};