
//Mosiuoa Liefo 1923875 end assessment for DSA
#include <bits/stdc++.h>
using namespace std;

//declaring functions
string word_select();
void gametitle();
void show_lose(int lose);
void show_progression(vector<char> incorrect, string answer);
void end_game(string answer, string secretword);

//defining functions
string word_select()
{
    srand ( time(NULL) );

    string wordsArray[8] = {"motoho", "mahleu", "moroko", "moroho","mokopu","lehapu","papa","senkhoane"};
    int RanIndex = rand() % 8;
    return wordsArray[RanIndex];
}

void gametitle()
{
    cout << "Author: MOSIUOA LIEFO 1923875 April 2022                           " <<endl<<endl<<endl;
    cout << "_________________________________________________________________  " <<endl;
    cout << "             WELCOME TO SESOTHO WORDS HANGMAN GAME...!             " <<endl;
    cout << "_________________________________________________________________  " <<endl;
    cout << "               LETTERS TO BE GUESSED ARE FOOD NAMES                " <<endl;
    cout << "_________________________________________________________________  " <<endl;
}

void show_lose(int lose)
{
    if(lose==1)
    {
        cout << " ******************* \n";
        cout << "          ______     \n";
        cout << "         |           \n";
        cout << "         |           \n";
        cout << "         |            \n";
        cout << "         |            \n";
        cout << "         |            \n";
        cout << " ******************* \n";
    }
    else if(lose==2)
    {
         cout << " ******************* \n";
        cout << "          ______          \n";
        cout << "         |  O         \n";
        cout << "         |            \n";
        cout << "         |            \n";
        cout << "         |            \n";
        cout << "         |            \n";
        cout << " ******************* \n";
    }
    else if(lose==3)
    {
         cout << " ******************* \n";
        cout << "          ______          \n";
        cout << "         |  O         \n";
        cout << "         |  |          \n";
        cout << "         |            \n";
        cout << "         |            \n";
        cout << "         |            \n";
        cout << " ******************* \n";

    }
    else if(lose==4)
    {
        cout << " ******************* \n";
        cout << "          ______          \n";
        cout << "         |  O         \n";
        cout << "         | /|          \n";
        cout << "         |           \n";
        cout << "         |            \n";
        cout << "         |            \n";
        cout << " ******************* \n";

    }
    else if(lose==5)
    {
       cout << " ******************* \n";
        cout << "          ______          \n";
        cout << "         |  O         \n";
        cout << "         | /|\\          \n";
        cout << "         |           \n";
        cout << "         |            \n";
        cout << "         |            \n";
        cout << " ******************* \n";


    }
    else if(lose==6)
    {
        cout << " ******************* \n";
        cout << "          ______          \n";
        cout << "         |  O         \n";
        cout << "         | /|\\          \n";
        cout << "         | /         \n";
        cout << "         |            \n";
        cout << "         |            \n";
        cout << " ******************* \n";

    }
    else if(lose==7)
    {
        cout << " ******************* \n";
        cout << "          ______          \n";
        cout << "         |  O         \n";
        cout << "         | /|\\          \n";
        cout << "         | / \\        \n";
        cout << "         |            \n";
        cout << "         |            \n";
        cout << " ******************* \n";

    }
    else if(lose==8)
    {
         cout << " ******************* \n";
        cout << "          ______          \n";
        cout << "         |  @         \n";
        cout << "         | /|\\          \n";
        cout << "         | / \\        \n";
        cout << "         |            \n";
        cout << "         |            \n";
        cout << " ******************* \n"<<endl<<endl;

    }
}

void show_progression(vector<char> incorrect, string answer)
{

   for(int i=0;i < incorrect.size(); i++)
    {
        cout << " " <<incorrect[i] << " ";
    }
    cout << "\n\n HIDDEN WORD JUST BELOW, LONGEST LENTH IS 11 CHARACTERS: \n";

    for(int i = 0; i < answer.length(); i++)
    {
        cout << answer[i] << "*";
    }

}

void end_game(string answer, string secretword)
{
    if(answer == secretword)
    {
            cout << "DEAR PLAYER YOU SUCCESSFULLY GUSSED THE CORRECT WORD, YOU WON.\n";
            cout << "YOU GUSSED: " << answer <<"\n";
            cout << "HIDDEN WORD: " << secretword <<"\n";
            cout << "*******************************************";
            cout << "          GOOD WORK. KEEP IT UP          \n";
            cout << "*******************************************";
    }
    else
    {
            cout << "___________________________________________"<<endl;
            cout << "GAME OVER. YOU LOST THE GAME!  \n";
            cout << "___________________________________________"<<endl<<endl;
            cout << "YOU GUSSED: " << answer <<"\n"<<endl;
            cout << "WORD IS: " << secretword << "\n\n";

    }
}


int main()
{
   gametitle();

    string secretword=word_select();
    string answer="______";

    int lose= 0;
    vector<char> incorrect;
    bool guess=false;
    char letter;

    while(answer!=secretword && lose < 8)
        {
            show_lose(lose);
            show_progression(incorrect, answer);
            cout << "\n";

            cout <<  "*****************************************************************"<<endl;
            cout <<  "\n           DEAR PLAYER, YOU MAY ENTER YOUR WORD BELOW:         "<<endl;
            cout <<  "*****************************************************************"<<endl;

            cin >>letter;


            for(int i = 0; i < secretword.length(); i++)//using a liner search, uses inserted letter and searches from start of word to end
            {
                if(letter == secretword[i]) //Searching a secrete word from the array list
                {
                    answer[i] = letter;
                    guess = true;
                }
            }
            if(guess)
            {
                cout <<"\n";
                cout <<"\nRIGHT GUESS\n";
            }
            else
            {
              cout <<"\nWRONG GUESS!\n";
              incorrect.push_back(letter);
             lose++;
            }
            guess= false;
        }
        show_lose(lose);
        end_game(answer, secretword);


    return 0;
}

