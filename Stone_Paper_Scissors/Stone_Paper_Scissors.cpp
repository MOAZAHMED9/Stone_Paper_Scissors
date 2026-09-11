#include <iostream>
#include<string>
#include<stdlib.h>
#include<ctime>
using namespace std;

enum enchoic { stone = 1, paper, Scissors };
enum enwinner { player = 1, computer, draw };

struct stround
{

    int raundd;
    enchoic player1choice;
    enchoic computerchoice;
    enwinner winner;
    string nameroundwinner;


};

struct stresult
{
    short gameround;
    short playerwontime;
    short computerwontime;
    short drawtime;

    enwinner gamewinner;
    string namewinner;

};

int randnum(int from, int to)
{

    return rand() % (to - from + 1) + from;
}


int gertlengthgame()
{
    cout << "how many raund \n";
    int length;
    cin >> length;
    return length;

}


enchoic player1choice1()
{
    cout << "stone=1 , paper=2 , Scissors=3 \n";
    int num;
    cin >> num;
    return (enchoic)num;

}

enchoic computerchoice1()
{


    return (enchoic)randnum(1, 3);

}

enwinner roundwinner1(stround roundinfo)
{
    if (roundinfo.player1choice == roundinfo.computerchoice)
        return enwinner::draw;


    switch (roundinfo.player1choice)
    {

    case enchoic::stone:
        if (roundinfo.computerchoice == enchoic::paper)
        {
            return enwinner::computer;
        }
        break;


    case enchoic::paper:
        if (roundinfo.computerchoice == enchoic::Scissors)
        {
            return enwinner::computer;
        }
        break;


    case enchoic::Scissors:
        if (roundinfo.computerchoice == enchoic::stone)
        {
            return enwinner::computer;
        }
        break;


    }

    return enwinner::player;
}

string getname(enwinner winner)                              //***
{
    string arr[] = { "player","computer","draw" };
    return arr[winner - 1];

}


string namechoice(enchoic choice)
{
    string arr[] = { "stone", "paper","Scissors" };
    return arr[choice - 1];

}

void printresultround(stround roundinfo)
{
    cout << "_____________________ round [" << roundinfo.raundd << "]________________________\n\n";
    cout << "player choice   :   " << namechoice(roundinfo.player1choice) << endl;
    cout << "computer choice :   " << namechoice(roundinfo.computerchoice) << endl;
    cout << "round winner is :   " << roundinfo.nameroundwinner << endl;            //*****
    cout << "__________________________________________________________\n";


}

stresult fillgameresult(int length, short playerwontime, short computerwontime, short drawtime)
{
    stresult resultinfo;
    resultinfo.playerwontime = playerwontime;
    resultinfo.computerwontime = computerwontime;
    resultinfo.gameround = length;
    resultinfo.drawtime = drawtime;

    if (playerwontime > computerwontime)
        resultinfo.gamewinner = enwinner::player;
    else if (computerwontime > playerwontime)
        resultinfo.gamewinner = enwinner::computer;
    else
        resultinfo.gamewinner = enwinner::draw;

    resultinfo.namewinner = getname(resultinfo.gamewinner);

    return resultinfo;
}


stresult playgame(int length)
{
    stround roundinfo;
    short playerwontime = 0, computerwontime = 0, drawtime = 0;
    for (int i = 1; i <= length; i++)
    {
        cout << "round [" << i << "] begins\n";
        roundinfo.raundd = i;

        roundinfo.player1choice = player1choice1();
        roundinfo.computerchoice = computerchoice1();
        // roundinfo.nameroundwinner=roundwinner1(roundinfo);
        roundinfo.winner = roundwinner1(roundinfo);
        roundinfo.nameroundwinner = getname(roundinfo.winner);         //***     //*****

        printresultround(roundinfo);

        if (roundinfo.winner == enwinner::player)
            playerwontime++;
        else if (roundinfo.winner == enwinner::computer)
            computerwontime++;
        else
            drawtime++;



    }

    return fillgameresult(length, playerwontime, computerwontime, drawtime);


}


void showgameover()
{
    cout << "__________________________________________________________\n\n";
    cout << "\t\t\t GAME OVER \n";
    cout << "__________________________________________________________\n";
    cout << "______________________[ game result ]_____________________\n\n";

}


void gameresults(stresult resultinfo)
{
    cout << "Player Wins:   " << resultinfo.playerwontime << endl;
    cout << "Computer Wins: " << resultinfo.computerwontime << endl;
    cout << "Draws:         " << resultinfo.drawtime << endl;
    cout << "Overall Winner: " << resultinfo.namewinner << endl;
}



void startgame()
{
    char y = 'y';
    while (y == 'Y' || y == 'y')
    {
        system("cls");
        stresult resultgame = playgame(gertlengthgame());

        showgameover();
        gameresults(resultgame);

        cout << "\t\t\t\ndo you want play again (Y::O) ?\n";
        cin >> y;
    }
}


int main()
{
    srand(time(0));
    startgame();

}


