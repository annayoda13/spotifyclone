#include <iostream>
#include <string>

class Track {
public:
    std::string title;
    std::string artist;
    
    Track(std::string t, std::string a) : title(t), artist(a) {}
    
    void displayTrackInfo() {
        std::cout << "Now playing: " << title << " by " << artist << std::endl;
    }
};
#include <vector>

class Playlist {
private:
    std::vector<Track> tracks;
public:
    void addTrack(const Track &track) {
        tracks.push_back(track);
    }

    Track getTrack(int index) {
        if (index >= 0 && index < tracks.size()) {
            return tracks[index];
        }
        // Return a default track in case of invalid index
        return Track("No Track", "Unknown Artist");
    }

    int getTotalTracks() {
        return tracks.size();
    }
};
class Player {
private:
    Playlist playlist;
    int currentTrackIndex;
    
public:
    Player() : currentTrackIndex(0) {}

    void loadPlaylist(const Playlist &pl) {
        playlist = pl;
    }

    void play() {
        if (currentTrackIndex < playlist.getTotalTracks()) {
            Track currentTrack = playlist.getTrack(currentTrackIndex);
            currentTrack.displayTrackInfo();
        } else {
            std::cout << "End of playlist!" << std::endl;
        }
    }

    void skip() {
        if (currentTrackIndex < playlist.getTotalTracks() - 1) {
            currentTrackIndex++;
            play();
        } else {
            std::cout << "You've reached the end of the playlist!" << std::endl;
        }
    }
};
#include <iostream>

int main() {
    // Create some sample tracks
    Track track1("Shape of You", "Ed Sheeran");
    Track track2("Blinding Lights", "The Weeknd");
    Track track3("Levitating", "Dua Lipa");

    // Create a playlist and add tracks to it
    Playlist playlist;
    playlist.addTrack(track1);
    playlist.addTrack(track2);
    playlist.addTrack(track3);

    // Create a player and load the playlist
    Player player;
    player.loadPlaylist(playlist);

    // Simulate playing and skipping tracks
    char userChoice;
    while (true) {
        std::cout << "Enter 'p' to play or 's' to skip, or 'q' to quit: ";
        std::cin >> userChoice;

        if (userChoice == 'p') {
            player.play();
        } else if (userChoice == 's') {
            player.skip();
        } else if (userChoice == 'q') {
            break;
        } else {
            std::cout << "Invalid input, please try again!" << std::endl;
        }
    }

    return 0;
}


