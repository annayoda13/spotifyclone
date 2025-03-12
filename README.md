The music player simulation consists of three main components: Track, Playlist, and Player. These components work together to simulate a basic music player that can play a list of tracks, skip to the next one, and manage the playlist. The program is designed to showcase the basic principles of object-oriented programming (OOP) by modeling real-world entities such as music tracks, playlists, and a player.

1. Track Class
The Track class is used to represent a single song or music track. Each Track has two properties:

title: The name of the song.
artist: The name of the artist or band who performed the song.
When a Track object is created, the constructor accepts two parameters: the track's title and the artist's name. There is also a method called displayTrackInfo(), which outputs the track's title and artist to the console. This simulates the functionality of a real music player showing the current song being played.

2. Playlist Class
The Playlist class represents a collection of Track objects. A playlist can hold multiple tracks, and the class provides methods to interact with the tracks in the playlist:

addTrack(): Adds a new track to the playlist.
getTrack(): Retrieves a specific track by its index. If the index is invalid (out of range), a default track with the name "No Track" and artist "Unknown Artist" is returned.
getTotalTracks(): Returns the total number of tracks in the playlist, allowing the program to keep track of the size of the playlist.
3. Player Class
The Player class represents the music player that handles playback of the Playlist. It has several responsibilities:

loadPlaylist(): Loads a given playlist into the player. This method initializes the Player with the playlist provided by the user.
play(): Plays the current track in the playlist by displaying its information (title and artist).
skip(): Skips to the next track in the playlist. If the player is already at the last track, it notifies the user that the end of the playlist has been reached.
The Player class uses an internal index (currentTrackIndex) to keep track of the current track being played. The user can skip to the next track in the playlist or start playing from the beginning of the playlist.

4. User Interaction
The program interacts with the user through the console. After loading the playlist into the player, the user is given options to control the playback:

Enter 'p' to play the current track.
Enter 's' to skip to the next track.
Enter 'q' to quit the program.
The user is continuously prompted for input until they choose to quit by entering 'q'. The player will display the current track's information when playing, and it will skip to the next track when requested.

# spotifyclone
