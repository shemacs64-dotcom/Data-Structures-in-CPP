#include <iostream>
#include <cstdlib>
using namespace std;
int top = -1;
class StackArray
{
public:
    string stack[100];
    void push(string element);
    string pop();
    void display();
};
void StackArray::push(string element)
{
    if (top == 99)
    {
        cout << "Stack is full";
        exit(1);
    }
    else
    {
        top = top + 1;
        stack[top] = element;
    }
}
string StackArray::pop()
{
    if (top == -1)
    {
        cout << "Stack is empty";
        exit(1);
    }
    else
    {
        return stack[top--];
    }
}
void StackArray::display()
{
    int i;
    cout << "\nBrowser History:\n";
    for (i = top; i >= 0; i--)
    {
        cout << stack[i] << endl;
    }
}
int main()
{
    StackArray s;
    int ch;
    string page, page1, page2;
    do
    {
        cout << "\n1. Visit Page";
        cout << "\n2. Press Back";
        cout << "\n3. Display History";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the page to visit: ";
            cin >> page;
            s.push(page);
            cout << "Page visited successfully";
            break;
        case 2:
            if (top == -1)
            {
                cout << "No previous page";
            }
            else
            {
                page1 = s.pop();
                cout << "Back pressed";
                cout << "\nRemoved page: " << page1;
                if (top != -1)
                    cout << "\nCurrent page: " << s.stack[top];
            }
            break;
        case 3:
            s.display();
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice";
        }
    } while (ch != 4);
    return 0;
}
