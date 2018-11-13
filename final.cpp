/*Text based survival game.
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

void mainMenu();

int main(){
    int gameState = 0;
    while (true){
        if (gameState == 0){
            mainMenu();
        }
    }
}

void mainMenu(){
    string command;
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
    cout <<"NEW GAME       LOAD GAME        OPTIONS         HELP          EXIT" << endl;
    getline(cin, command);
}
