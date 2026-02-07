#include <iostream>
using namespace std;
struct book
{
    string isbn, title, author;
    int year;
    book *previous;
    book *next;
};
class library
{
private:
    book *start, *cur, *temp;
public:
    library()
    {
        start = NULL;
    }

    void addbook()
    {
        temp = new book;
        cout << "Enter ISBN: ";
        cin >> temp->isbn;
        cout << "Enter Title: ";
        cin >> temp->title;  
        cout << "Enter Author: ";
        cin >> temp->author;  
        cout << "Enter Year: ";
        cin >> temp->year;
        temp->next = NULL;
        temp->previous = NULL;
        if (start == NULL)
            start = temp;
        else
        {
            cur = start;
            while (cur->next != NULL)
                cur = cur->next;
            cur->next = temp;
            temp->previous = cur;
        }

        cout << "Book Added"<<endl;
    }
    void displaybook()
    {
        if (start == NULL)
        {
            cout << "No books found"<<endl;
            return;
        }

        cur = start;
        int count = 1;
        while (cur != NULL)
        {
            cout << count <<endl;
            cout << cur->isbn  <<endl;
            cout << cur->title  <<endl;
            cout << cur->author <<endl; 
            cout << cur->year << endl;
            cur = cur->next;
            count++;
        }
    }

    void searchbook()
    {
        string key;
        cout << "Enter ISBN: ";
        cin >> key;
        cur = start;
        while (cur != NULL)
        {
            if (cur->isbn == key)
            {
                cout << "Found: " << cur->title << endl;
                return;
            }
            cur = cur->next;
        }

        cout << "Not Found"<<endl;
    }

    void modifybook()
    {
        string key;
        cout << "Enter ISBN to modify:";
        cin >> key;
        cur = start;
        while (cur != NULL && cur->isbn != key)
            cur = cur->next;
        if (cur == NULL)
        {
            cout << "Not Found"<<endl;
            return;
        }
        cout << "New Title:";
        cin >> cur->title;
        cout << "New Author:";
        cin >> cur->author;
        cout << "New Year:";
        cin >> cur->year;
        cout << "Updated"<<endl;
    }
};

int main()
{
    library l;
    int choice;
    do
    {
        cout << "1 Add"<<endl;
		cout<<"2 Display"<<endl;
		cout<<"3 Search"<<endl;
		cout<<"4 Modify"<<endl;
		cout<<"5 Exit"<<endl;
		cout<<"Choice: "<<endl;
        cin >> choice;
        switch (choice)
        {
        case 1: l.addbook(); break;
        case 2: l.displaybook(); break;
        case 3: l.searchbook(); break;
        case 4: l.modifybook(); break;
        }
    } while (choice != 5);
    return 0;
}

