#include <iostream>
#include "PlaylistNode.h"

//GitHub Repository Link: 
//Team Members: Fred Solis III & Garrison Regala

using namespace std;

void PrintMenu(const string& playlistTitle) {
   cout << playlistTitle << " PLAYLIST MENU" << endl;
   cout << "a - Add song" << endl;
   cout << "d - Remove song" << endl;
   cout << "c - Change position of song" << endl;
   cout << "s - Output songs by specific artist" << endl;
   cout << "t - Output total time of playlist (in seconds)" << endl;
   cout << "o - Output full playlist" << endl;
   cout << "q - Quit" << endl;
   cout << endl;
}

PlaylistNode* ExecuteMenu(char option, const string& playlistTitle, PlaylistNode* headNode) {
   switch (option) {
      case 'a': {
         cout << "ADD SONG" << endl;
         string uniqueID, songName, artistName;
         int songLength;
   
         cout << "Enter song's unique ID:" << endl;
         getline(cin, uniqueID);

         cout << "Enter song's name:" << endl;
         getline(cin, songName);

         cout << "Enter artist's name:" << endl;
         getline(cin, artistName);

         cout << "Enter song's length (in seconds):" << endl;
         cout << endl;
         cin >> songLength;
         cin.ignore();

         PlaylistNode* newNode = new PlaylistNode(uniqueID, songName, artistName, songLength);
         if (headNode == nullptr) {
            headNode = newNode;
            } else {
               PlaylistNode* current = headNode;
               while (current->GetNext() != nullptr) {
                  current = current->GetNext();
               }
                  
                current->InsertAfter(newNode);
            }

            break;
      }

int main() {
   /* Type your code here */
   
   return 0;
}
