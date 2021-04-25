#include <bits/stdc++.h>
using namespace std;

const int N = 9;
const int M = 9;
const int a_row = 5;
const int n_players = 2;
char marks[n_players] = {'B', 'W'};
char grid[N][M];


void print_grid()
{
    for (int i = 0; i< n_players; i++)
    {
        cout << "Player " << i+1 << ": " << marks[i] << "  ";
        if (i < n_players-1)
            cout << "vs  ";
    }
    cout << "\n";
    cout << "--";
    for (int i = 0; i < M; cout << "---", i++);
    cout << "--\n";
    for (int i = 0; i < N; i++)
    {
        cout << "|  ";
        for (int j = 0; j < M; j++)
            cout << grid[i][j] << "  ";
        cout << "|\n";
        cout << "--";
        for (int i = 0; i < M; cout << "---", i++);
        cout << "--\n";
    }
}

bool check_win()
{
    for(int i=0; i<N; i++)
        for(int j=0; j<=M-5; j++)
        {
            bool check=true;
            for(int l=1; l<a_row; l++)
                if(grid[i][j]!=grid[i][j+l]||grid[i][j]=='.')
                    check=false;
            if(check)
                return 1;
        }


    for(int j=0; j<M; j++)
        for(int i=0; i<=N-5; i++)
        {
            bool check=true;
            for(int l=1; l<a_row; l++)
                if(grid[i][j]!=grid[i+l][j]||grid[i][j]=='.')
                    check=false;
            if(check)
                return 1;
        }


    for(int i=0; i<=N-5; i++)
        for(int j=0; j<=M-5; j++)
        {
            bool check=true;
            for(int l=1; l<a_row; l++)
                if(grid[i][j]!=grid[i+l][j+l]||grid[i][j]=='.')
                    check=false;
            if(check)
                return 1;
        }


    for(int i=4; i<N; i++)
        for(int j=0; j<=M-5; j++)
        {
            bool check=true;
            for(int l=1; l<a_row; l++)
                if(grid[i][j]!=grid[i-l][j+l]||grid[i][j]=='.')
                    check=false;
            if(check)
                return 1;
        }
    return 0;
}

bool check_tie_player(char mark)
{
    for(int i=0; i<N; i++)
        for(int j=0; j<=M-5; j++)
        {
            bool check=true;
            for(int l=0; l<a_row; l++)
                if(grid[i][j+l]==mark)
                    check=false;
            if(check)
                return 0;
        }


    for(int j=0; j<M; j++)
        for(int i=0; i<=N-5; i++)
        {
            bool check=true;
            for(int l=0; l<a_row; l++)
                if(grid[i+l][j]==mark)
                    check=false;
            if(check)
                return 0;
        }


    for(int i=0; i<=N-5; i++)
        for(int j=0; j<=M-5; j++)
        {
            bool check=true;
            for(int l=0; l<a_row; l++)
                if(grid[i+l][j+l]==mark)
                    check=false;
            if(check)
                return 0;
        }


    for(int i=4; i<N; i++)
        for(int j=0; j<=M-5; j++)
        {
            bool check=true;
            for(int l=0; l<a_row; l++)
                if(grid[i-l][j+l]==mark)
                    check=false;
            if(check)
                return 0;
        }
    return 1;
}

bool check_tie()
{
    bool all_tie = true;
    for (int i = 0; i < n_players; i++)
        if (!check_tie_player(marks[i]))
            all_tie = false;
    return all_tie;
}

bool check_empty(int i, int j)
{
    return(grid[i][j]=='.');
}

bool check_valid_position(int i, int j)
{
    return(i<N&&i>=0&&j<M&&j>=0);
}

void set_cell(int i, int j, char mark)
{
    grid[i][j]=mark;
}

void grid_clear()
{
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            grid[i][j]='.';
}

void read_input(int &i, int &j)
{
    cout << "Enter the row index and column index: ";
    cin >> i >> j;
    while (!check_valid_position(i, j) || !check_empty(i, j))
    {
        cout << "Enter a valid row index and a valid column index: ";
        cin >> i >> j;
    }
}

void play_game()
{
    cout << "Gomoku Game!\n";
    cout << "Welcome...\n";
    cout << "============================\n";
    int player = 0;
    while (true)
    {

        print_grid();

        cout << "Player " << marks[player] << " is playing now\n";
        int i, j;
        read_input(i, j);

        set_cell(i, j, marks[player]);

        if (check_win())
        {

            print_grid();

            cout << "Congrats, Player " << marks[player] << " is won!\n";
            break;
        }

        if (check_tie())
        {

            print_grid();

            cout << "Woah! That's a tie!\n";
            break;
        }

        player = (player + 1) % n_players;
    }
}
int main()
{
    while (true)
    {
        grid_clear();
        play_game();
        char c;
        cout << "Play Again [Y/N] ";
        cin >> c;
        if (c != 'y' && c != 'Y')
            break;
    }
}
