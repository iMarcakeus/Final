/*Text based survival game.
 *@Last Update: 11/27/2018 | 12:26 PM
 *@Updated By: Marcus Coleman
 ========================================================================================================================================
 Item Code Index (this number starts after the Health, Hunger, Stamina, and Round data, index starts at 0 because inventory is an array):
 (maybe? maybe not)
 0 - Wood
 1 - Stick
 2 - Chops
 3 - Rocks
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

void saveGame(int health, int hunger, int stamina, int round, int inventory[5]);
void newGame();
void createSave();
void loadGame();
int runGame(string fileName);
int ingame(int health, int hunger, int stamina, int round, int inventory[5]);
void options();
void help();
int tutorial();

int main(){
    system("CLS");
    char command;
    cout <<"      #######                                                                  " << endl;
    cout <<"    /       ###                                      #                         " << endl;
    cout <<"   /         ##                                     ###                        " << endl;
    cout <<"   ##        #                          ##           #  ##                     " << endl;
    cout <<"    ###                                 ##              ##                     " << endl;
    cout <<"   ## ###       ##   ####    ###  /###   ##    ### ###   ##    ###      /##    " << endl;
    cout <<"    ### ###      ##    ###  / ###/ #### / ##    ### ###   ##    ###    / ###   " << endl;
    cout <<"      ### ###    ##     ###/   ##   ###/  ##     ### ##   ##     ###  /   ###  " << endl;
    cout <<"        ### /##  ##      ##    ##         ##      ## ##   ##      ## ##    ### " << endl;
    cout <<"          #/ /## ##      ##    ##         ##      ## ##   ##      ## ########  " << endl;
    cout <<"           #/ ## ##      ##    ##         ##      ## ##   ##      ## #######   " << endl;
    cout <<"            # /  ##      ##    ##         ##      ## ##   ##      ## ##        " << endl;
    cout <<"  /##        /   ##      /#    ##         ##      /  ##   ##      /  ####    / " << endl;
    cout <<" /  ########/     ######/ ##   ###         ######/   ### / ######/    ######/  " << endl;
    cout <<"/     #####        #####   ##   ###         #####     ##/   #####      #####   " << endl;
    cout <<"|                                                                              " << endl;
    cout <<" )                                                                            " << endl;
    cout <<"A - NEW GAME     B - LOAD GAME     C - OPTIONS     D - HELP     E - EXIT" << endl;
    cout <<"                 (coming soon)     (coming soon)" << endl;
    cin >> command;
    switch(command){
    case 'A':
    case 'a':
        newGame();
        return 0;
    case 'B':
    case 'b':
        loadGame();
        return 0;
    case 'C':
    case 'c':
        options();
        return 0;
    case 'D':
    case 'd':
        help();
        return 0;
    case 'E':
    case 'e':
        return 0;
    default:
        cout << "Invalid Option! Try again.\n";
        cin >> command;
        system("CLS");
    }
}

void newGame(){
    system("CLS");
    cout << "Welcome survivor! Your goal in this game is to make it as many rounds as you can.\n";
    cout << "You will be attacked, and every new zone you enter shall bring harder enemies,\n";
    cout << "But better loot! Good luck...\n";
    createSave();
}

void loadGame(){
    cout << "What's the name of the saved file you would like to load? ";
    string fileName;
    cin.clear();
    cin.ignore();
    getline(cin, fileName);
    fileName = ".\\saves\\" + fileName + ".txt";
    runGame(fileName);
}

void options(){
    cout << "Coming soon!";
    system("pause");
    main();
}

void help(){
    system("CLS");
    cout << "This is the help menu. Here you will find a list of useful tips and information on the game.\n";
    cout << "Leaving this menu will return you to the home screen.\n";
    cout << "=============================================================================================\n";
    cout << "\"Survive\" is a Text-Based survival game coded for new programmers, by new programmers.\n";
    cout << "This game was written in C++ using relatively simple coding methods. This makes the playstyle\n";
    cout << "more difficult to users, as improper inputs will make you have to try again!\n";
    cout << "This can be frustrating, but easy to learn. Inputting correct keys for correct options\n";
    cout << "This is the most common Error, and to fix it, simply pay close attention to your input,\n";
    cout << "and do it right!\n=========================================================================================================\n";
    cout <<  "For more help, check the README file. If your problem persists, check our GitHub at:\nhttps://github.com/iMarcakeus\n";
    system("pause");
    main();
}

void createSave(){
    string fileName;
    cout << "What would you like to name your save? ";
    cin.clear();
    cin.ignore();
    getline(cin, fileName);
    fileName = ".\\saves\\" + fileName + ".txt";
    ofstream save(fileName.c_str());
    save << "100\n50\n5\n0\n0\n0\n0\n0\n0";
    save.close();
    runGame(fileName);
}

void saveGame(int health, int hunger, int stamina, int round, int inventory[5]){
    string fileName;
    cout << "What would you like to name your save? ";
    cin.clear();
    cin.ignore();
    getline(cin, fileName);
    fileName = ".\\saves\\" + fileName + ".txt";
    ofstream save(fileName.c_str());
    save << health << "\n" << hunger << "\n" << stamina << "\n" << round << "\n";
    for(int i=0; i<5; i++){
        save << inventory[i] << endl;
    }
    save.close();
    runGame(fileName);
}

int runGame(string fileName){
    int health, hunger, stamina, round;
    int inventory[5];
    ifstream save(fileName.c_str());
    save >> health;
    save >> hunger;
    save >> stamina;
    save >> round;
    for(int i=0; i<5; i++){
        save >> inventory[i];
    }
    cout << "|  Stats   |\tHealth: " << health << "\tHunger: " << hunger << "\tStamina: " << stamina << "\tRound: " << round << endl;
    cout << "Ready to continue? [Y/N] ";
    char ready;
    cin >> ready;
    if(cin.fail()){
        cin.clear();
        cin.ignore(200, '\n');
        cout << "Invalid Option.\nReady to continue? [Y/N] ";
        cin >> ready;
    }
    switch(ready){
    case 'Y':
    case 'y':
        ingame(health, hunger, stamina, round, inventory);
    default:
        main();
        return 0;
    }
}

int tutorial(){
    int n;
    cout << "Welcome to the tutorial round 0! To skip this, press 1 now. To continue, press any other key.\n";
    cin >> n;
    if(cin.fail()){
        cin.clear();
        cin.ignore(200, '\n');
        return 1;
    }
    //create tutorial here?
    return 1;
}

int ingame(int health, int hunger, int stamina, int round, int inventory[5]){
    while(health > 0){
        system("CLS");
        srand(time(NULL));
        int trees, rocks, sheep = 0;
        for(int i=0; i<5; i++){
            cout << inventory[i] << endl;
        }
        while(round == 0){
            round = tutorial();
        }
        trees = rand()%round+2;
        rocks = rand()%round+3;
        sheep = rand()%round;
        cout << "Welcome to round " << round << "!\n";
        cout << "You were fortunate to find: " << trees << " trees, " << rocks << " rocks, and " << sheep << " sheep. Who knows what else we will find?\n";
        for(int i=stamina; i>0; i--){
            if(health == 0){
                break;
            }
            char choice;
            cout << "You have " << i << " stamina left.\n";
            cout << "What should we do?\n";
            cout << "A - Explore     B - Eat     C - Hunt     D - Save Game     E - Exit to Main Menu" << endl;
            cin >> choice;
            switch(choice){
            case 'A':
            case 'a':
                health = 0;
                //explore(); || Finds monsters, tools at higher levels, and more. Uses stamina based on what you pick up? or uses stamina to explore.
            case 'B':
            case 'b':
                //eat();
                //restores HEALTH and HUNGER but not STAMINA.
                break;
            case 'C':
            case 'c':
                //hunt(); || IDEAS: Using tools to hunt: Knife, Fists, etc? Guns may be too intricate to implement,
                //worse weapons use more of your stamina and give less food in return. Food will come cooked because cooking food
                //will be a hard mechanic to implement?
                break;
            case 'D':
            case 'd':
                saveGame(health, hunger, stamina, round, inventory);
                break;
            case 'E':
            case 'e':
                main();
                return 0;
            default:
                cout << "Invalid option! Please try again.\n";
                i += 1;
            }
        }
        round += 1;
    }
    cout << "You have died! You survived to round " << round << ".\n";
    system("PAUSE");
    main();
}
