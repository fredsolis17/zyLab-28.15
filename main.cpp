#include <iostream>
#include "PlaylistNode.h"

//GitHub Repository Link: 
//Team Members: Fred Solis III & Garrison Regala
// DO NOT NEED TO DO STEP 9

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

      case 'd': {
         cout << "REMOVE SONG" << endl;
         string uniqueID;
         
         cout << "Enter song's unique ID:" << endl;
         getline(cin, uniqueID);

         PlaylistNode* current = headNode;
         PlaylistNode* previous = nullptr;

         while (current != nullptr && current->GetID() != uniqueID) {
            previous = current;
            current = current->GetNext();
         }
            
         if (current == nullptr) {
            cout << "Song with ID \"" << uniqueID << "\" not found." << endl;
         
         } else {  
            if (previous != nullptr) {
               previous->SetNext(current->GetNext());
            
            } else {
               headNode = current->GetNext();
            }
            
            cout << "\"" << current->GetSongName() << "\" removed." << endl;
            cout << endl;
            delete current;
         }
         
            break;
      } 

      case 's': {
         cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
         string artistName;
         cout << "Enter artist's name:" << endl;
         cout << endl;
         getline(cin, artistName);
         
         if (headNode == nullptr) {
            cout << "Playlist is empty" << endl;
         } else {
            int position = 1;
            PlaylistNode* current = headNode;
            
            while (current != nullptr) {
               if (current->GetArtistName() == artistName) {
                  cout << position << "." << endl;
                  current->PrintPlaylistNode();
                  cout << endl;
               }
               
               current = current->GetNext();
               position++;
            }
            
            if (position == 1) {
               cout << "No songs found for artist \"" << artistName << "\"" << endl;
            }
         }
               
         break;
      }

      case 't': {
         cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;

         int totalTime = 0;
         PlaylistNode* current = headNode;

         while (current != nullptr) {
            
            totalTime += current->GetSongLength();
            current = current->GetNext();
         }
         
         cout << "Total time: " << totalTime << " seconds" << endl;
         cout << endl;
         break;
      }

      case 'o': {
         cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
         
         if (headNode == nullptr) {
            cout << "Playlist is empty" << endl;
            cout << endl;
         } else {
            int position = 1;
            PlaylistNode* current = headNode;
   
            while (current != nullptr) {
               cout << position << "." << endl;
               current->PrintPlaylistNode();
               cout << endl;

               current = current->GetNext();
               position++;
            }
         }   

         break;
      }
      
      case 'q':
      
            
      break;

      default:
         cout << "Invalid option. Please try again." << endl;
   }

   return headNode;
}

int main() {
   string playlistTitle;

   cout << "Enter playlist's title:" << endl;
   cout << endl;
   getline(cin, playlistTitle);

   PlaylistNode* headNode = nullptr;

   char option;
   do {
      PrintMenu(playlistTitle);
      cout << "Choose an option:" << endl;
      cin >> option;
      cin.ignore();
      headNode = ExecuteMenu(option, playlistTitle, headNode);
      
   } while (option != 'q');
   PlaylistNode* current = headNode;
   
   while (current != nullptr) {
      PlaylistNode* temp = current;
      current = current->GetNext();
      delete temp;
   }
   
   return 0;
}
