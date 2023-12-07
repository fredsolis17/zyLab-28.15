#include <iostream>
#include "PlaylistNode.h"

//GitHub Repository Link: 
//Team Members: Fred Solis III & Garrison Regala

using namespace std;

void PrintMenu(const string playlistTitle) {
    cout << playlistTitle << " PLAYLIST MENU" << endl;   // PLAYLIST MENU SECTION
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
}

PlaylistNode* ExecuteMenu(char option, string playlistTitle, PlaylistNode* headNode) {
   /* Type your code here */
   
}

int main() {
   /* Type your code here */
   
   return 0;
}
