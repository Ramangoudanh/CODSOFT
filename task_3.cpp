
#include <iostream>
using namespace std;

int boxes = 9;
class TicTacToe
{
    int data[3][3];

public:
    TicTacToe()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                data[i][j] = 0;
            }
        }
    }
    void Display()
    {
        cout << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "* * * * * * * * * * * * * * * * *\n    "
                 << i << "\t|   ";
            for (int j = 0; j < 3; j++)
            {
                cout << data[i][j] << "\t|   ";
            }
            cout << endl;
        }
        cout << "---------------------------------\n";
        cout << "| INDEX\t|   0\t|   1\t|   2   |\n";
        cout << "---------------------------------\n";
        cout << "------------Made By:Ramangouda N H\n";
    }
    bool takemove(int i, int j, char p)
    {
        if (data[i][j] == 0)
        {
            if (p == 1)
            {
                data[i][j] = 1;
                boxes--;
                return 1;
            }
            else if (p == 2)
            {
                data[i][j] = 2;
                boxes--;
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            cout << endl
                 << "Wrong Index!!!Enter Index Again:\n";
            return 0;
        }
    }
    bool check(int p)
    {
        if ((data[0][0] == p && data[1][1] == p && data[2][2] == p) || (data[0][2] == p && data[1][1] == p && data[2][0] == p) || (data[0][0] == p && data[1][0] == p && data[2][0] == p) || (data[0][0] == p && data[0][1] == p && data[0][2] == p) || (data[1][0] == p && data[1][1] == p && data[1][2] == p) || (data[2][0] == p && data[2][1] == p && data[2][2] == p) || (data[0][1] == p && data[1][1] == p && data[2][1] == p) || (data[0][2] == p && data[1][2] == p && data[2][2] == p))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

int main()
{
    int indexX{0}, indexY{0}, choice{0}, rtn{0};
    TicTacToe p;
    while (choice != -1)
    {
        rtn = 0;
        p.Display();
        cout << "\nPlayer 1 Turn:\nEnter Index:\n";
        while (rtn != 1)
        {
            cin >> indexX >> indexY;
            rtn = p.takemove(indexX, indexY, 1);
            p.Display();
        }
        rtn = 0;
        rtn = p.check(1);
        if (rtn == 1)
        {
            cout << endl
                 << "Player 1 wins!!!";
            break;
        }
        if (boxes == 0)
        {
            cout << endl
                 << "The Game is Draw!!!";
            break;
        }
        rtn = 0;
        cout << "\nPlayer 2 Turn:\nEnter Index:\n";
        while (rtn != 1)
        {
            cin >> indexX >> indexY;
            rtn = p.takemove(indexX, indexY, 2);
            p.Display();
        }
        rtn = 0;
        rtn = p.check(2);
        if (rtn == 1)
        {
            cout << endl
                 << "Player 2 wins!!!";
            break;
        }
        if (boxes == 0)
        {
            choice = -1;
        }
    }
    return 0;
}
