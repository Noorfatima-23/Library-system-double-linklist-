#include <iostream>
using namespace std;
struct song
{
    int id;
    string title, artist;
    int duration;
    song* p;  
    song* n; 
};

class playlist
{
private:
    song *start, *cur, *temp;
public:
    playlist()
    {
        start = NULL;
        cur = start;
    }
    void insertSong()
    {
        temp = new song;
        cout << "Enter ID: ";
        cin >> temp->id;
        cout << "Enter Title: ";
        cin >> temp->title;
        cout << "Enter Artist: ";
        cin >> temp->artist;
        cout << "Enter Duration (sec): ";
        cin >> temp->duration;
        temp->n = NULL;
        temp->p = NULL;
        if (start == NULL)
        {
            start = temp;
            cur = temp;
        }
        else
        {
            cur = start;
            while (cur->n != NULL)
                cur = cur->n;
            cur->n = temp;
            temp->p = cur;
        }

        cout << "Song Added"<<endl;
    }
    void displaySongs()
    {
        if (start == NULL)
        {
            cout << "Playlist empty"<<endl;
            return;
        }
        cur = start;
        int count = 0;
		int total = 0;
        while (cur != NULL)
        {
            cout <<"ID"<< cur->id <<endl;
                cout<<"title" << cur->title <<endl;
                cout<<"Artist" << cur->artist <<endl;
                 cout<<"duration"<< cur->duration << "sec"<<endl;
            total += cur->duration;
            count++;
            cur = cur->n;
        }

        cout << "Total Songs: " << count << endl;
        cout << "Total Duration: " << total << " seconds"<<endl;
    }
    void searchSong()
    {
        string key;
        cout << "Enter Title or Artist: ";
        cin >> key;
        cur = start;
        while (cur != NULL)
        {
            if (cur->title == key || cur->artist == key)
            {
                cout << "Found: " << cur->title
                     << " by " << cur->artist << endl;
                return;
            }
            cur = cur->n;
        }

        cout << "Song not found"<<endl;
    }
    void modifySong()
    {
        int key;
        cout << "Enter ID to modify: ";
        cin >> key;
        cur = start;
        while (cur != NULL && cur->id != key)
            cur = cur->n;
        if (cur == NULL)
        {
            cout << "Song not found"<<endl;
            return;
        }
        cout << "New Title: ";
        cin >> cur->title;
        cout << "New Artist: ";
        cin >> cur->artist;
        cout << "New Duration: ";
        cin >> cur->duration;
        cout << "Song Updated"<<endl;
    }
    void playNext()
    {
        if (cur == NULL)
        {
            cout << "No songs"<<endl;
            return;
        }

        if (cur->n != NULL)
            cur = cur->n;

        cout << "Now Playing: "
             << cur->title << endl;
    }
    void playPrevious()
    {
        if (cur == NULL)
        {
            cout << "No songs\n";
            return;
        }

        if (cur->p != NULL)
            cur = cur->p;

        cout << "Now Playing: "
             << cur->title << endl;
    }
};
int main()
{
    playlist p;
    int choice;

    do
    {
        cout << "\n===== PLAYLIST MENU =====\n";
        cout << "1 Insert Song\n";
        cout << "2 Search Song\n";
        cout << "3 Modify Song\n";
        cout << "4 Display Songs\n";
        cout << "5 Play Next\n";
        cout << "6 Play Previous\n";
        cout << "7 Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: p.insertSong();
		 break;
        case 2: p.searchSong();
		 break;
        case 3: p.modifySong();
		 break;
        case 4: p.displaySongs(); 
		break;
        case 5: p.playNext();
		 break;
        case 6: p.playPrevious();
		 break;
        case 7: cout << "Exit"<<endl;
		 break;
        default: cout << "Invalid"<<endl;
        }

    } while (choice != 7);

    return 0;
}

