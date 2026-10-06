#include <iostream>
using namespace std;
#define MAX 5
class Parking
{
    int car[MAX];
    int top;
public:
    Parking()
    {
        top = -1;
    }
    void enterCar(int num)
    {
        if (top == MAX - 1)
        {
            cout << "Parking garage is full\n";
        }
        else
        {
            top++;
            car[top] = num;
            cout << "Car entered successfully\n";
        }
    }
    void leaveCar()
    {
        if (top == -1)
        {
            cout << "Parking garage is empty\n";
        }
        else
        {
            cout << "Car " << car[top] << " left the garage\n";
            top--;
        }
    }
    void display()
    {
        if (top == -1)
        {
            cout << "Parking garage is empty\n";
        }
        else
        {
            cout << "Cars in parking garage:\n";

            for (int i = top; i >= 0; i--)
            {
                cout << "Car " << car[i] << endl;
            }
        }
    }
};
int main()
{
    Parking p;
    int choice, num;
    do
    {
        cout << "\n--- CAR PARKING GARAGE ---\n";
        cout << "1. Enter a car\n";
        cout << "2. Leave a car\n";
        cout << "3. Display all cars\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter car number: ";
            cin >> num;
            p.enterCar(num);
            break;
        case 2:
            p.leaveCar();
            break;
        case 3:
            p.display();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 4);
    return 0;
}
