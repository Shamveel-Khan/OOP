#include <iostream>
using namespace std;

class Level
{
    string name;
    int difficulty;

public:
    Level(string n, int d) : name(n), difficulty(d) {}
    void display()
    {
        cout << "Level: " << name << endl;
        cout << "Difficulty: " << difficulty << endl;
    }
};

class VideoGame
{
    string title;
    string genre;
    int numberOfLevels;
    Level **levels;

public:
    VideoGame(string t, string g, int num) : title(t), genre(g), numberOfLevels(num)
    {
        levels = new Level *[num];
    }
    ~VideoGame() { delete[] levels; }
    void addLevel(Level *l, int index)
    {
        if (index < numberOfLevels)
            levels[index] = l;
    }
    void display()
    {
        cout << "\n\n......VIDEO GAME......\n";
        cout << "Title: " << title << endl;
        cout << "Genre: " << genre << endl;
        cout << "Number of Levels: " << numberOfLevels << endl;
        cout << "\n...LEVELS...\n";
        for (int i = 0; i < numberOfLevels; i++)
        {
            cout << "\nLevel # " << i + 1 << endl;
            levels[i]->display();
        }
    }
};

int main()
{
    VideoGame game("Shadow Realm", "RPG", 3);
    Level l1("level#1", 5);
    Level l2("level sabke niklenge", 7);
    Level l3("pr niklenge uske jo khra rahega", 10);

    game.addLevel(&l1, 0);
    game.addLevel(&l2, 1);
    game.addLevel(&l3, 2);

    game.display();

    return 0;
}
