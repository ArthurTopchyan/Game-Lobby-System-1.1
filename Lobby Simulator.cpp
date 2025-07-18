// Lobby Simulator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Follow the instructions from readme

#include <iostream>
#include <iostream>
#include <vector>
#include <string>
#include<thread>
#include<chrono>
#include <set>
using namespace std;

class Player
{
public:
    Player(const string& name, int level)
        : _name(name)
        , _level(level)
    {}

public:
    void ChangeLevel(int level)
    {
        _level = level;
    }

    bool operator < (const Player other) const
    {
        return _name < other._name;
    }

    string Name() const { return _name; }
    int Level() const { return _level; }

private:
    string _name;
    int _level;
};


class LOBBY
{
public:
    static const int MaxPlayersCount = 10;

public:
    void AddPlayer(const string& name, int level);
    void RemovePlayer(const string& name);
    int  PlayersCount();
    void PrintPlayers() const;

    //protected:
    //    int Player_Storage = 0; you can remove slashes from the protected and experement with it

private:
    set<Player> _players;

};


void LOBBY::AddPlayer(const string& name, int level)
{
    _players.emplace(name, level);
}

void LOBBY::RemovePlayer(const string& name)
{
    Player a(name, 0);
    auto it = _players.find(a);
    if (it != _players.end())
    {
        _players.erase(it);
    }
    else
    {
        cout << "No player " << name << endl;
    }
}

int LOBBY::PlayersCount()
{
    return _players.size();
}

void LOBBY::PrintPlayers() const
{
    for (auto it = _players.begin(); it != _players.end(); ++it)
    {
        cout << it->Name() << " ";
        cout << it->Level() << endl;
    }
}


int main()
{
    LOBBY lobby;
    while (true)
    {
        int t = 0;
        system("cls");
        cout << "Enter '1' if you want to add new player\n\n";
        cout << "Enter '2' if you want to remove player\n\n";
        cout << "Enter '3' if you want to count players\n\n";
        cout << "Enter '4' if you want to see all players\n\n";
        cin >> t;
        if (t == 1)
        {
            string name;
            int level;
            cout << "name?" << endl;  cin >> name;
            system("cls");
            cout << "level?" << endl;  cin >> level;
            system("cls");
            lobby.AddPlayer(name, level);
        }
        else if (t == 2)
        {
            string name;
            cout << "name?" << endl;  cin >> name;
            lobby.RemovePlayer(name);
            system("cls");

        }
        else if (t == 3)
        {
            int time;
            cout << "How much time do you want to Players count stay at the screen?(at seconds)\n";
            cin >> time;
            system("cls");
            cout << lobby.PlayersCount() << endl;
            this_thread::sleep_for(chrono::seconds(time));
            system("cls");
        }
        else if (t == 4)
        {
            int time;
            cout << "How much time do you want to Players count stay at the screen?(at seconds)\n";
            cin >> time;
            cout << lobby.PlayersCount() << endl;
            this_thread::sleep_for(chrono::seconds(time));
            system("cls");
            lobby.PrintPlayers();
        }
        else
        {
            cout << "Error 404 unknown operation\n";
        }
    }
}
