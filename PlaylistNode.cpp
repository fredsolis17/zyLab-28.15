#include "PlaylistNode.h"

using namespace std;

PlaylistNode::PlaylistNode() : uniqueID("none"), songName("none"), artistName("none"), songLength(0), nextNodePtr(nullptr) {}

PlaylistNode::PlaylistNode(const string& uniqueID, const string& songName, const string& artistName, int songLength)
   : uniqueID(uniqueID), songName(songName), artistName(artistName), songLength(songLength), nextNodePtr(nullptr) {}

string PlaylistNode::GetID() const {
   return uniqueID;
}

string PlaylistNode::GetSongName() const {
   return songName;
}

string PlaylistNode::GetArtistName() const {
   return artistName;
}

int PlaylistNode::GetSongLength() const {
   return songLength;
}

PlaylistNode* PlaylistNode::GetNext() const {
   return nextNodePtr;
}

void PlaylistNode::SetNext(PlaylistNode* nodePtr) {
   nextNodePtr = nodePtr;
}

void PlaylistNode::PrintPlaylistNode() const {
   cout << "Unique ID: " << uniqueID << endl;
   cout << "Song Name: " << songName << endl;
   cout << "Artist Name: " << artistName << endl;
   cout << "Song Length (in seconds): " << songLength << endl;
}

void PlaylistNode::InsertAfter(PlaylistNode* nodePtr) {
   nodePtr->nextNodePtr = nextNodePtr;
   nextNodePtr = nodePtr;
}

void PlaylistNode::PrintPlaylistNode() const {
   cout << "Unique ID: " << uniqueID << endl;
   cout << "Song Name: " << songName << endl;
   cout << "Artist Name: " << artistName << endl;
   cout << "Song Length (in seconds): " << songLength << endl;
}
