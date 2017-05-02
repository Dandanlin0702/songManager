#include "SongManagerDriver.h"

void SongManagerDriver::autogeneratePlaylist(AutogenerateType Type) {
   string songName, albumName, artistName;

   switch(Type) {
      case NAME:
         cout << "What is the song name you’d like to autogenerate a playlist from? \n> ";
         cin.ignore();
         getline (cin, songName);

         if (PlaylistLibrary_.hasPlaylist(songName)) {
            cout << "\"" << songName << "\"" << " playlist already exists. \n";
         } else {
            PlaylistLibrary_.addToPlaylist(songName, SongLibrary_.findSongByNAME(songName));
            cout << "\"" << songName << "\" playlist autogenerated successfully. \n";
         }

         break;
      case ARTIST:
         cout << "Who is the song artist you’d like to autogenerate a playlist from? \n> ";
         cin.ignore();
         getline (cin, artistName);

         if (PlaylistLibrary_.hasPlaylist(artistName)) {
            cout << "\"" << artistName << "\"" << " playlist already exists. \n";
         } else {
            // Create playlist based on the category type user wants to autogenerate from
            PlaylistLibrary_.addToPlaylist(artistName, SongLibrary_.findSongByARTIST(artistName));
            cout << "\"" << artistName << "\" playlist autogenerated successfully. \n";
         }

         break;
      case ALBUM:
         cout << "What is the song album you’d like to autogenerate a playlist from? \n> ";
         cin.ignore();
         getline (cin, albumName);

         if (PlaylistLibrary_.hasPlaylist(albumName)) {
            cout << "\"" << albumName << "\"" << " playlist already exists. \n";
         } else {
            PlaylistLibrary_.addToPlaylist(albumName, SongLibrary_.findSongByALBUM(albumName));
            cout << "\"" << albumName << "\" playlist autogenerated successfully. \n";
         }

         break;
      case MAGIC:
         if (PlaylistLibrary_.hasPlaylist("AUTOGENERATED")) {
            cout << "\"AUTOGENERATED\"" << " playlist already exists. \n";
         } else {
            vector<Song*> tempSongVector_;
            SongLibrary_.findSongByMAGIC(tempSongVector_);

            sort( tempSongVector_.begin(), tempSongVector_.end() );
            tempSongVector_.erase(unique(tempSongVector_.begin(), tempSongVector_.end()), tempSongVector_.end());

            PlaylistLibrary_.addToPlaylist("AUTOGENERATED", tempSongVector_);
            cout << "\"AUTOGENERATED\" playlist autogenerated successfully.\n";
         }
         break;
   }
}

void SongManagerDriver::displaySongs(string categoryType_) {
   if (categoryType_ == "NAME") {
      SongLibrary_.displaySongs(SongLibrary::NAME);
   } else if (categoryType_ == "ARTIST") {
      SongLibrary_.displaySongs(SongLibrary::ARTIST);
   } else if (categoryType_ == "ALBUM") {
      SongLibrary_.displaySongs(SongLibrary::ALBUM);
   } else {
      SongLibrary_.displaySongs(SongLibrary::PLAYS);
   }
}

void SongManagerDriver::addSongToLibrary(Song* songPointer_, int& songID_) {
   SongLibrary_.addSongToLibrary(songPointer_, songID_);
}

void SongManagerDriver::removeSongFromLibrary(int songID_) {
   SongLibrary_.removeSongFromLibrary(songID_);

}

void SongManagerDriver::loadSongToLibrary(Song* songPointer_, int songID_, int numberOfPlays_) {
   SongLibrary_.loadSongToLibrary(songPointer_, songID_, numberOfPlays_);
}

bool SongManagerDriver::isIDValid(int songID_) {
   return SongLibrary_.isIDValid(songID_);
}
void SongManagerDriver::getGeneralSongInfo(Song*& songPointer_, int songID_) {
   SongLibrary_.getGeneralSongInfo(songPointer_, songID_);
}
void SongManagerDriver::playSongs(int songID_, int& playTimes_, int& numberOfPlays_) {
   SongLibrary_.playSongs(songID_, playTimes_, numberOfPlays_);
}

// Playlist related functions
void SongManagerDriver::loadPlaylistToPlaylist(Playlist* playlistPointer_, vector<Song*> songPointerVector_) {
   PlaylistLibrary_.loadPlaylistToPlaylist(playlistPointer_, songPointerVector_);
}

bool SongManagerDriver::hasPlaylist(string playlistTitle_) {
   return PlaylistLibrary_.hasPlaylist(playlistTitle_);
}

void SongManagerDriver::createPlaylist(string playlistTitle_) {
   PlaylistLibrary_.createPlaylist(playlistTitle_);
}

void SongManagerDriver::removePlaylist(string playlistTitle_){
   PlaylistLibrary_.removePlaylist(playlistTitle_);
}

void SongManagerDriver::renamePlaylist(string playlistTitle_, string newPlaylistTitle_) {
   PlaylistLibrary_.renamePlaylist(playlistTitle_, newPlaylistTitle_);
}

void SongManagerDriver::addSongToPlaylist(string playlistTitle_, Song* songPointer_) {
   PlaylistLibrary_.addSongToPlaylist(playlistTitle_, songPointer_);
}

void SongManagerDriver::removeSongFromPlaylist(string playlistTitle_, Song* songPointer_) {
   PlaylistLibrary_.removeSongFromPlaylist(playlistTitle_, songPointer_);
}
bool SongManagerDriver::playlistHasSong(string playlistTitle_, Song* songPointer_) {
   return PlaylistLibrary_.playlistHasSong(playlistTitle_, songPointer_);
}
void SongManagerDriver::ratePlaylist(string playlistTitle_, int playlistRating_) {
   PlaylistLibrary_.ratePlaylist(playlistTitle_, playlistRating_);
}

void SongManagerDriver::displaySongsInPlaylist(Song* songPointer_, int numberOfPlays_,
                                          int songID_, int counter_) {
   PlaylistLibrary_.displaySongsInPlaylist(songPointer_, numberOfPlays_,
                                           songID_, counter_);
}

int SongManagerDriver::numberOfSongsInPlaylist(string playlistTitle_) {
   return PlaylistLibrary_.numberOfSongsInPlaylist(playlistTitle_);
}
