#include <iostream>
using namespace std;

struct node
{
    int info;
    struct node *next;
};

struct node *first = NULL;
struct node *last = NULL;

class linked_list
{
public:
    void addBeginning(int value);
    void addEnd(int value);
    void removeCoach(int value);
    void display();
};

void linked_list::addBeginning(int value)
{
    struct node *ptr;
    ptr = new node;

    ptr->info = value;
    ptr->next = NULL;

    if (first == NULL)
    {
        first = last = ptr;
    }
    else
    {
        ptr->next = first;
        first = ptr;
    }

    cout << "Coach added at beginning\n";
}

void linked_list::addEnd(int value)
{
    struct node *ptr;
    ptr = new node;

    ptr->info = value;
    ptr->next = NULL;

    if (first == NULL)
    {
        first = last = ptr;
    }
    else
    {
        last->next = ptr;
        last = ptr;
    }

    cout << "Coach added at end\n";
}

void linked_list::removeCoach(int value)
{
    struct node *temp, *loc;

    if (first == NULL)
    {
        cout << "Train is empty\n";
        return;
    }

    if (first->info == value)
    {
        if (first == last)
        {
            first = last = NULL;
        }
        else
        {
            first = first->next;
        }

        cout << "Coach removed successfully\n";
        return;
    }

    temp = first;

    while (temp->next != NULL &&
           temp->next->info != value)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        cout << "Coach not found\n";
        return;
    }

    loc = temp->next;
    temp->next = loc->next;

    if (loc == last)
    {
        last = temp;
    }

    cout << "Coach removed successfully\n";
}

void linked_list::display()
{
    struct node *ptr;

    if (first == NULL)
    {
        cout << "Train is empty\n";
        return;
    }

    cout << "Train Coaches: ";

    for (ptr = first; ptr != NULL; ptr = ptr->next)
    {
        cout << "Coach" << ptr->info;

        if (ptr->next != NULL)
            cout << " -> ";
    }

    cout << endl;
}

int main()
{
    linked_list train;
    int choice, num;

    do
    {
        cout << "\n--- TRAIN COACH MANAGEMENT ---\n";
        cout << "1. Add coach at beginning\n";
        cout << "2. Add coach at end\n";
        cout << "3. Remove a coach\n";
        cout << "4. Display all coaches\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter coach number: ";
            cin >> num;
            train.addBeginning(num);
            break;

        case 2:
            cout << "Enter coach number: ";
            cin >> num;
            train.addEnd(num);
            break;

        case 3:
            cout << "Enter coach number to remove: ";
            cin >> num;
            train.removeCoach(num);
            break;

        case 4:
            train.display();
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}
