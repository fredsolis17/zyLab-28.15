#ifndef PLAYLISTNODE_H
#define PLAYLISTNODE_H
#include <iostream>
#include <string>

using namespace std;

class PlaylistNode {
public:
   PlaylistNode();
   PlaylistNode(const string& uniqueID, const string& songName, const string& artistName, int songLength);
   
   string GetID() const;
   string GetSongName() const;
   string GetArtistName() const;
   int GetSongLength() const;
   PlaylistNode* GetNext() const;

   void SetNext(PlaylistNode* nodePtr);
   void InsertAfter(PlaylistNode* nodePtr);

   void PrintPlaylistNode() const;
