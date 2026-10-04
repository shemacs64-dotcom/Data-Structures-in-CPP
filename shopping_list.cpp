#include <iostream>
#include <string>
using namespace std;

class ShoppingList
{
public:
    string a[20];
    int n, pos;

    void create();
    void insertion();
    void deletion();
    void search();
    void display();
};

void ShoppingList::create()
{
    cout << "Enter number of items: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cout << "Enter item " << i + 1 << ": ";
        cin >> a[i];
    }
}

void ShoppingList::insertion()
{
    cout << "Enter the position to insert: ";
    cin >> pos;

    if(pos > n || pos < 0)
        cout << "Invalid location";
    else
    {
        for(int i = n - 1; i >= pos; i--)
            a[i + 1] = a[i];

        cout << "Enter the item to insert: ";
        cin >> a[pos];

        n++;

        cout << "List after insertion:\n";
        display();
    }
}

void ShoppingList::deletion()
{
    cout << "Enter the position you want to delete: ";
    cin >> pos;

    if(pos >= n || pos < 0)
        cout << "Invalid location";
    else
    {
        for(int i = pos + 1; i < n; i++)
            a[i - 1] = a[i];

        n--;

        cout << "List after deletion:\n";
        display();
    }
}

void ShoppingList::search()
{
    string e;
    int flag = 0;

    cout << "Enter the item to be searched: ";
    cin >> e;

    for(int i = 0; i < n; i++)
    {
        if(a[i] == e)
        {
            flag = 1;
            cout << "Item is found at position: " << i << endl;
            break;
        }
    }

    if(flag != 1)
        cout << "Item is not found";
}

void ShoppingList::display()
{
    cout << "The items in the shopping list are: ";

    for(int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;
}

int main()
{
    ShoppingList s;
    int ch;

    do
    {
        cout << "\n1. Create";
        cout << "\n2. Insertion";
        cout << "\n3. Deletion";
        cout << "\n4. Search";
        cout << "\n5. Display";
        cout << "\n6. Exit";

        cout << "\nEnter your choice: ";
        cin >> ch;

        switch(ch)
        {
            case 1: s.create(); break;
            case 2: s.insertion(); break;
            case 3: s.deletion(); break;
            case 4: s.search(); break;
            case 5: s.display(); break;
            case 6: cout << "Exiting..."; break;
            default: cout << "Invalid choice";
        }

    } while(ch != 6);

    return 0;
}
D
