// 23K-0583, 23K-0622, 23K-0674
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <random>
using namespace std;

class User;

class UserDataAccess
{
public:
    virtual void displayInfo() const = 0;
};

class User : public UserDataAccess
{
protected:
    string username;
    string password;

public:
    User(string username, string password) : username(username), password(password) {}

    inline string getUsername() const
    {
        return username;
    }

    inline bool authenticate(string username, string password) const
    {
        return (this->username == username && this->password == password);
    }
};

class Schedule
{
private:
    string country;
    string stadium;
    int flag = 1;

public:
    Schedule() {}
    void ScheduleMatch()
    {

        char choice;
        int c1, c2;
        cout << "Welcome to WicketWise, the best cricket management system!!\nDo you want to schedule a match?(y/n):";
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            cout << "Where do want the match to be held?\n1. England\n2. Australia\n3. UAE\n4. India\n5. Pakistan\nEnter your choice: ";
            cin >> c1;
            switch (c1)
            {
            case 1:
                cout << "Which stadium?\n1. Lord's Stadium\n2. Old Trafford Stadium\n3. Cardiff Wales Stadium\nEnter your choice:";
                cin >> c2;
                if (c2 == 1)
                {
                    country = "England";
                    stadium = "Lord's Stadium";
                }
                else if (c2 == 2)
                {
                    country = "England";
                    stadium = "Old Trafford Stadium";
                }
                else if (c2 == 3)
                {
                    country = "England";
                    stadium = "Cardiff Wales Stadium";
                }
                else
                {
                    cout << "Invalid Input:" << endl;
                    cout << "Existing now..";
                    exit(0);
                }
                break;

            case 2:
                cout << "Which stadium?\n1. Melbourne Cricket Ground\n2. Sydney Cricket Ground\n3. Perth Stadium\nEnter your choice:";
                cin >> c2;
                if (c2 == 1)
                {
                    country = "Australia";
                    stadium = "Melbourne Cricket Ground";
                }
                else if (c2 == 2)
                {
                    country = "Australia";
                    stadium = "Sydney Cricket Ground";
                }
                else if (c2 == 3)
                {
                    country = "Australia";
                    stadium = "Perth Stadium";
                }
                else
                {
                    cout << "Invalid Input:" << endl;
                    cout << "Existing now..";
                    exit(0);
                }
                break;

            case 3:
                cout << "Which stadium?\n1. Dubai International Cricket Stadium\n2. Sharjah Crikcet Stadium\n3. Sheikh Zayed Cricket Stadium\nEnter your choice:";
                cin >> c2;
                if (c2 == 1)
                {
                    country = "UAE";
                    stadium = "Dubai International Cricket Stadium";
                }
                else if (c2 == 2)
                {
                    country = "UAE";
                    stadium = "Sharjah Crikcet Stadium";
                }
                else if (c2 == 3)
                {
                    country = "UAE";
                    stadium = "Sheikh Zayed Cricket Stadium";
                }
                else
                {
                    cout << "Invalid Input:" << endl;
                    cout << "Existing now..";
                    exit(0);
                }
                break;

            case 4:
                cout << "Which stadium?\n1. Eden Gardens\n2. Narendra Modi Stadium\n3. Rajiv Gandhi Stadium\nEnter your choice:";
                cin >> c2;
                if (c2 == 1)
                {
                    country = "India";
                    stadium = "Eden Gardens";
                }
                else if (c2 == 2)
                {
                    country = "India";
                    stadium = "Narendra Modi Stadium";
                }
                else if (c2 == 3)
                {
                    country = "India";
                    stadium = "Rajiv Gandhi Stadium";
                }
                else
                {
                    cout << "Invalid Input:" << endl;
                    cout << "Existing now..";
                    exit(0);
                }
                break;

            case 5:
                cout << "Which stadium?\n1. Gaddafi Stadium\n2. National Stadium\n3. Rawalpindi Cricket Stadium\nEnter your choice:";
                cin >> c2;
                if (c2 == 1)
                {
                    country = "Pakistan";
                    stadium = "Gaddafi Stadium";
                }
                else if (c2 == 2)
                {
                    country = "Pakistan";
                    stadium = "National Stadium";
                }
                else if (c2 == 3)
                {
                    country = "Pakistan";
                    stadium = "Rawalpindi Cricket Stadium";
                }
                else
                {
                    cout << "Invalid Input:" << endl;
                    cout << "Existing now..";
                    exit(0);
                }
                break;

            default:
                cout << "Invalid Input:" << endl;
                cout << "Existing now..";
                exit(0);
                ;
            }
        }
        else if (choice == 'N' || choice == 'n')
        {
            flag = 0;
            cout << "Existing now..";
            exit(0);
        }
        else
        {
            cout << "Invalid Input" << endl;
            cout << "Existing now..";
            exit(0);
        }
    }
    void displaySchedule()
    {
        if (flag == 1)
        {
            cout << "Match Scheduled at " << stadium << " in " << country << "." << endl;
            random_device rd;
            mt19937 gen(rd());

            int min = 5;
            int max = 12;
            uniform_int_distribution<> distrib(min, max);

            int month = distrib(gen);
            max = 30;
            min = 1;
            uniform_int_distribution<> distrib1(min, max);
            int day = distrib1(gen);
            cout << "Date for match: " << day << "/" << month << "/" << 2024 << "." << endl;
        }
        else
        {
            cout << "No match has been scheduled" << endl;
        }
    }
};
class Team;
class Player : public User
{
private:
    string team;
    int matchesPlayed;
    int runsScored;
    static int totalPlayers;
    int totalRuns;
    float avg;
    int balls;
    int WicketsTaken;

public:
    Player(string username, string password, string team)
        : User(username, password), team(team), balls(0), WicketsTaken(0), matchesPlayed(0), runsScored(0)
    {
        totalPlayers++;
    }

    void displayInfo() const override
    {
        cout << "Username: " << username << endl;
        cout << "Team: " << team << endl;
        cout << "Matches Played: " << matchesPlayed << endl;
        cout << "Runs Scored: " << runsScored << endl;
        cout << "Wickets Taken : " << WicketsTaken << endl;
        cout << "Average: " << avg << endl;
        cout << "Total Balls: " << balls << endl;
    }
    void updateStats(int runs, int b, int wt)
    {
        matchesPlayed++;
        runsScored += runs;
        if (balls > 120)
        {
            cout << "Its a T20 match . cant be more than 120 balls" << endl;
        }
        else
        {
            balls += balls + b;
        }
        WicketsTaken += wt;
    }

    static inline int getTotalPlayers()
    {
        return totalPlayers;
    }
    int gettotalballs()
    {
        return balls;
    }
    float getAvg()
    {
        return runsScored / matchesPlayed;
    }

    friend ostream &operator<<(ostream &os, const Player &player);
    friend istream &operator>>(istream &is, Player &player);
    friend class Team;
};

int Player::totalPlayers = 0;

ostream &operator<<(ostream &os, const Player &player)
{
    os << "Username: " << player.username << endl;
    os << "Team: " << player.team << endl;
    os << "Matches Played: " << player.matchesPlayed << endl;
    os << "Runs Scored: " << player.runsScored << endl;
    return os;
}

istream &operator>>(istream &is, Player &player)
{
    is >> player.username >> player.team >> player.matchesPlayed >> player.runsScored;
    return is;
}

class Admin : public User
{
public:
    Admin(string username, string password) : User(username, password)
    {
    }

    void displayInfo() const override
    {
        cout << "Admin Username: " << username << endl;
    }
    void askForPassword(string u, string p)
    {
        if (u == username && p == password)
        {
            cout << "Login Successful" << endl;
        }
        else
        {
            cout << "Login Failed" << endl;
            exit(0);
        }
    }
    friend void accessPlayerData(const Admin &admin, const Player &player);
};

void accessPlayerData(const Admin &admin, const Player &player)
{
    cout << "Admin " << admin.getUsername() << " accessed player " << player.getUsername() << "'s data." << endl;
}

class Team
{
private:
    Player *players[11];
    int playerCount;
    int totalRuns;

public:
    Team() : playerCount(0), totalRuns(0)
    {
    }

    // Add a new player
    void addPlayer(Player *player)
    {
        if (playerCount < 12)
        {
            players[playerCount++] = player;
        }
        else
        {
            cout << "Maximum player limit reached!" << endl;
        }
    }
    void totalRunsScored(int *runs, int extras)
    {
        totalRuns = 0;
        for (int i = 0; i < 11; i++)
        {
            totalRuns = totalRuns + runs[i];
        }
        totalRuns = totalRuns + extras;
    }
    int GetTotalRuns()
    {
        return totalRuns;
    }
    void displayTotalRuns()
    {
        cout << "Team " << players[0]->team << " Scored:" << totalRuns << endl;
    }
    void getMaxOfBatsman(int *runs)
    {
        int max = runs[0];
        for (int i = 1; i < 11; i++)
        {
            if (runs[i] > max)
            {
                max = runs[i];
            }
        }
        cout << "Team " << players[0]->team << endl
             << "Max Batsman Score:" << max << endl;
    }

    void getMinOfBatsman(int *runs)
    {
        int min = runs[0];
        for (int i = 1; i < 12; i++)
        {
            if (runs[i] < min)
            {
                min = runs[i];
            }
        }
        cout << "Team " << players[0]->team << endl
             << "Min Batsman Score:" << min << endl;
    }
    int operator+(Team &other)
    {
        return totalRuns + other.totalRuns;
    }

    void displayPlayers() const
    {
        for (int i = 0; i < playerCount; i++)
        {
            cout << *players[i] << endl;
        }
    }

    void saveToFile(string filename) const
    {
        ofstream file(filename);
        if (file.is_open())
        {
            for (int i = 0; i < playerCount; i++)
            {
                file << *players[i] << endl;
            }
            file.close();
            cout << "Player data saved to " << filename << endl;
        }
        else
        {
            cout << "Unable to open file for writing: " << filename << endl;
        }
    }
    void predictMatchOutcome()
    {
        if (totalRuns > 190)
        {
            cout << "Team Dream 11 winning chances = 65%" << endl;
        }
        else if (totalRuns > 220)
        {
            cout << "Team Dream 11 winning chances = 85%" << endl;
        }
        else
        {
            cout << "Team Dream 11 winning chances = 35%" << endl;
        }
    }
};

int main()
{
    string u, p;
    Admin admin("FASTIAN", "SHIK-SHAK-SHOK");
    cout << "Enter your username " << endl;
    cin >> u;
    cout << "Enter your password " << endl;
    cin >> p;
    admin.askForPassword(u, p);

    Schedule match;
    match.ScheduleMatch();
    match.displaySchedule();

    Team teamA, teamB;

    Player player1A("Suryakumar Yadav", "password1A", "Dream 11");
    Player player2A("Phil Salt", "password2A", "Dream 11");
    Player player3A("Babar Azam", "password3A", "Dream 11");
    Player player4A("Mohd. Rizwan", "password4A", "Dream 11");
    Player player5A("Travis Head", "password5A", "Dream 11");
    Player player6A("Kusal Mendis", "password6A", "Dream 11");
    Player player7A("Adil Rashid", "password7A", "Dream 11");
    Player player8A("Shaheen Afridi", "password8A", "Dream 11");
    Player player9A("Keshav Maharaj", "password9A", "Dream 11");
    Player player10A("Mustafizur Rahman", "password10A", "Dream 11");
    Player player11A("Joshua Little", "password11A", "Dream 11");

    Player player1B("Virat Kohli", "password1B", "Hall of Fame");
    Player player2B("Kevin Pietersen", "password2B", "Hall of Fame");
    Player player3B("Eion Morgan", "password3B", "Hall of Fame");
    Player player4B("Brendon McCullum", "password4B", "Hall of Fame");
    Player player5B("Glenn Maxwell", "password5B", "Hall of Fame");
    Player player6B("Kumar Sangakkara", "password6B", "Hall of Fame");
    Player player7B("Shahid Afridi", "password7B", "Hall of Fame");
    Player player8B("Sunil Narine", "password8B", "Hall of Fame");
    Player player9B("Jasprit Bumrah", "password9B", "Hall of Fame");
    Player player10B("Mohd. Amir", "password10B", "Hall of Fame");
    Player player11B("Mitchell Starc", "password11B", "Hall of Fame");

    teamA.addPlayer(&player1A);
    teamA.addPlayer(&player2A);
    teamA.addPlayer(&player3A);
    teamA.addPlayer(&player4A);
    teamA.addPlayer(&player5A);
    teamA.addPlayer(&player6A);
    teamA.addPlayer(&player7A);
    teamA.addPlayer(&player8A);
    teamA.addPlayer(&player9A);
    teamA.addPlayer(&player10A);
    teamA.addPlayer(&player11A);

    teamB.addPlayer(&player1B);
    teamB.addPlayer(&player2B);
    teamB.addPlayer(&player3B);
    teamB.addPlayer(&player4B);
    teamB.addPlayer(&player5B);
    teamB.addPlayer(&player6B);
    teamB.addPlayer(&player7B);
    teamB.addPlayer(&player8B);
    teamB.addPlayer(&player9B);
    teamB.addPlayer(&player10B);
    teamB.addPlayer(&player11B);

    int runsA[11], runsB[11], ballsA[11], ballsB[11], wicketsA[11], wicketsB[11];
    for (int i = 0; i < 11; i++)
    {
        try
        {
            cout << "Batsman No. " << i + 1 << endl;
            cout << "Enter Runs of Dream 11 " << endl;
            cin >> runsA[i];
            cout << "Enter balls " << endl;
            cin >> ballsA[i];
            if (runsA[i] < 0 || ballsA[i] < 0)
            {
                throw 1;
            }
        }
        catch (...)
        {
            cout << "Invalid Input" << endl;
            i--;
        }
    }
    for (int i = 0; i < 11; i++)
    {
        try
        {
            cout << "Batsman No. " << i + 1 << endl;
            cout << "Enter Runs of HAll of fame 11 " << endl;
            cin >> runsB[i];
            cout << "Enter balls " << endl;
            cin >> ballsB[i];
            if (runsB[i] < 0 || ballsB[i] < 0)
            {
                throw 1;
            }
        }
        catch (...)
        {
            cout << "Invalid Input" << endl;
            i--;
        }
    }

    int ExtrasA, ExtrasB;
    cout << "Enter Extras of Dream 11" << endl;
    cin >> ExtrasA;
    cout << "Enter Extras of Hall of Fame" << endl;
    cin >> ExtrasB;
    if (ExtrasA < 0 || ExtrasB < 0)
    {
        cout << "Invalid Input" << endl;
    }
    for (int i = 0; i < 11; i++)
    {
        try
        {
            cout << "Bowler No. " << i + 1 << endl;
            cout << "Enter wickets of Dream 11 " << endl;
            cin >> wicketsA[i];
            if (wicketsA[i] < 0)
            {
                throw 1;
            }
        }
        catch (...)
        {
            cout << "Invalid Input" << endl;
            i--;
        }
    }
    for (int i = 0; i < 11; i++)
    {
        try
        {
            cout << "Bowler No. " << i + 1 << endl;
            cout << "Enter wickets of Hall of Fame 11 " << endl;
            cin >> wicketsB[i];
            if (wicketsB[i] < 0)
            {
                throw 1;
            }
        }
        catch (...)
        {
            cout << "Invalid Input" << endl;
            i--;
        }
    }
    player1A.updateStats(runsA[0], ballsA[0], wicketsA[0]);
    player2A.updateStats(runsA[1], ballsA[1], wicketsA[1]);
    player3A.updateStats(runsA[2], ballsA[2], wicketsA[2]);
    player4A.updateStats(runsA[3], ballsA[3], wicketsA[3]);
    player5A.updateStats(runsA[4], ballsA[4], wicketsA[4]);
    player6A.updateStats(runsA[5], ballsA[5], wicketsA[5]);
    player7A.updateStats(runsA[6], ballsA[6], wicketsA[6]);
    player8A.updateStats(runsA[7], ballsA[7], wicketsA[7]);
    player9A.updateStats(runsA[8], ballsA[8], wicketsA[8]);
    player10A.updateStats(runsA[9], ballsA[9], wicketsA[9]);
    player11A.updateStats(runsA[10], ballsA[10], wicketsA[10]);

    player1B.updateStats(runsB[0], ballsB[0], wicketsB[0]);
    player2B.updateStats(runsB[1], ballsB[1], wicketsB[1]);
    player3B.updateStats(runsB[2], ballsB[2], wicketsB[2]);
    player4B.updateStats(runsB[3], ballsB[3], wicketsB[3]);
    player5B.updateStats(runsB[4], ballsB[4], wicketsB[4]);
    player6B.updateStats(runsB[5], ballsB[5], wicketsB[5]);
    player7B.updateStats(runsB[6], ballsB[6], wicketsB[6]);
    player8B.updateStats(runsB[7], ballsB[7], wicketsB[7]);
    player9B.updateStats(runsB[8], ballsB[8], wicketsB[8]);
    player10B.updateStats(runsB[9], ballsB[9], wicketsB[9]);
    player11B.updateStats(runsB[10], ballsB[10], wicketsB[10]);

    teamA.totalRunsScored(&runsA[0], ExtrasA);
    teamB.totalRunsScored(&runsB[0], ExtrasB);

    teamA.displayTotalRuns();
    teamA.predictMatchOutcome();
    cout << "ScoreCard:" << endl;
    teamA.displayTotalRuns();
    teamB.displayTotalRuns();

    if (teamA.GetTotalRuns() > teamB.GetTotalRuns())
    {
        cout << "Dream 11 wins the match." << endl;
    }
    else if (teamA.GetTotalRuns() < teamB.GetTotalRuns())
    {
        cout << "Hall of Fame wins match." << endl;
    }
    else
    {
        cout << "ITS A TIE" << endl;
    }

    teamA.getMaxOfBatsman(runsA);
    teamA.getMinOfBatsman(runsA);
    teamB.getMaxOfBatsman(runsB);
    teamB.getMinOfBatsman(runsB);

    int total = teamA + teamB;
    int totalExtras = ExtrasA + ExtrasB;
    cout << "Total Runs(both teams):" << total << endl;
    cout << "Total Extras in match(both teams):" << totalExtras << endl;
    cout << "All Players' Info:" << endl;
    teamA.displayPlayers();
    teamB.displayPlayers();
    cout << endl;
    accessPlayerData(admin, player1A);
    teamA.saveToFile("player_backupA.txt");
    teamB.saveToFile("player_backupB.txt");

    return 0;
}
