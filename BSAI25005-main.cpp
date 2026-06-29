#include"BSAI25005-HugeInteger.h"
#include "BSAI25005-HugeFraction.h"
#include<iostream>
#include<conio.h>
void displayMenu()
{
    cout << "================ HugeInteger Operations ================\n";
    cout << " 1. Add (A + B)\n";
    cout << " 2. Add and Assign (A += B)\n";
    cout << " 3. Subtract (A - B)\n";
    cout << " 4. Subtract and Assign (A -= B)\n";
    cout << " 5. Quantity Wise Addition\n";
    cout << " 6. Quantity Wise Subtraction\n";
    cout << " 7. Quantity Wise Less Than\n";
    cout << " 8. Quantity Wise Equality\n";
    cout << " 9. Less Than (A < B)\n";
    cout << "10. Greater Than (A > B)\n";
    cout << "11. Less Than or Equal (A <= B)\n";
    cout << "12. Greater Than or Equal (A >= B)\n";
    cout << "13. Equality (A == B)\n";
    cout << "14. Pre Increment (++A)\n";
    cout << "15. Post Increment (A++)\n";
    cout << "16. Multiply (A * B)\n";
    cout << "17. Multiply and Assign (A *= B)\n";
    cout << "18. Divide (A / B)\n";
    cout << "19. Divide and Assign (A /= B)\n";
    cout << "20. Modulus (A % B)\n";
    cout << "21. Unary Minus (-A)\n";
    cout << "22. Access Digit [i]\n";
    cout << " 0. Exit\n";
    cout << "========================================================\n";
    cout << "Selection: ";
}
void main_1()
{
    ifstream rdr("input.txt");
    int noi;
    rdr >> noi;
    HugeInteger* Is = new HugeInteger[noi];

    for (int i = 0; i < noi; i++)
        rdr >> Is[i];
    ofstream fout("save.txt");

    int choice;

    do
    {
        system("cls");

        cout << "======= Loaded HugeIntegers =======\n";
        for (int i = 0; i < noi; i++)
            cout << i << " : " << Is[i] << endl;

        cout << endl;

        displayMenu();
        cin >> choice;

        int a, b, pos;
        switch (choice)
        {

        case 1: 
            cout << "Enter index A: "; cin >> a;
            cout << "Enter index B: "; cin >> b;

            cout << "Result = " << Is[a] + Is[b] << endl;
            break;

        case 2:
            cout << "Enter index A: "; cin >> a;
            cout << "Enter index B: "; cin >> b;

            Is[a] += Is[b];
            cout << "Updated A = " << Is[a] << endl;
            break;

        case 3:
            cout << "Enter index A: "; cin >> a;
            cout << "Enter index B: "; cin >> b;

            cout << "Result = " << Is[a] - Is[b] << endl;
            break;

        case 4: 
            cout << "Enter index A: "; cin >> a;
            cout << "Enter index B: "; cin >> b;

            Is[a] -= Is[b];
            cout << "Updated A = " << Is[a] << endl;
            break;

        case 5:
            cout << "Enter index A: "; cin >> a;
            cout << "Enter index B: "; cin >> b;

            cout << Is[a].ADDQuantityWise(Is[b]) << endl;
            break;

        case 6:
            cout << "Enter index A: "; cin >> a;
            cout << "Enter index B: "; cin >> b;

            cout << Is[a].SUBQuantityWise(Is[b]) << endl;
            break;

        case 7:
            cout << "Enter index A: "; cin >> a;
            cout << "Enter index B: "; cin >> b;

            cout << (Is[a].LessThanQuantityWise(Is[b]) ? "True" : "False") << endl;
            break;

        case 8:
            cout << "Enter index A: "; cin >> a;
            cout << "Enter index B: "; cin >> b;

            cout << (Is[a].EqualQuantityWise(Is[b]) ? "True" : "False") << endl;
            break;

        case 9:
            cout << "Enter index A: "; cin >> a;
            cout << "Enter index B: "; cin >> b;

            cout << (Is[a] < Is[b] ? "True" : "False") << endl;
            break;

        case 10:
            cout << "Enter index A: "; cin >> a;
            cout << "Enter index B: "; cin >> b;

            cout << (Is[a] > Is[b] ? "True" : "False") << endl;
            break;

        case 11:
            cout << "Enter index A: "; cin >> a;
            cout << "Enter index B: "; cin >> b;

            cout << (Is[a] <= Is[b] ? "True" : "False") << endl;
            break;

        case 12:
            cout << "Enter index A: "; cin >> a;
            cout << "Enter index B: "; cin >> b;

            cout << (Is[a] >= Is[b] ? "True" : "False") << endl;
            break;

        case 13:
            cout << "Enter index A: "; cin >> a;
            cout << "Enter index B: "; cin >> b;

            cout << (Is[a] == Is[b] ? "True" : "False") << endl;
            break;

        case 14:
            cout << "Enter index: "; cin >> a;

            cout << "Before: " << Is[a] << endl;
            cout << "After: " << ++Is[a] << endl;
            break;

        case 15:
            cout << "Enter index: "; cin >> a;

            cout << "Returned: " << Is[a]++ << endl;
            cout << "After: " << Is[a] << endl;
            break;

        case 16:
            cout << "Enter index A: "; cin >> a;
            cout << "Enter index B: "; cin >> b;

            cout << "Result = " << Is[a] * Is[b] << endl;
            break;

        case 17:
            cout << "Enter index A: "; cin >> a;
            cout << "Enter index B: "; cin >> b;

            Is[a] *= Is[b];
            cout << "Updated A = " << Is[a] << endl;
            break;

        case 18:
            cout << "Enter index A: "; cin >> a;
            cout << "Enter index B: "; cin >> b;

            if (Is[b] == HugeInteger(0))
                cout << "Division by zero!\n";
            else
                cout << "Result = " << Is[a] / Is[b] << endl;
            break;

        case 19:
            cout << "Enter index A: "; cin >> a;
            cout << "Enter index B: "; cin >> b;

            if (Is[b] == HugeInteger(0))
                cout << "Division by zero!\n";
            else
            {
                Is[a] /= Is[b];
                cout << "Updated A = " << Is[a] << endl;
            }
            break;

        case 20:
            cout << "Enter index A: "; cin >> a;
            cout << "Enter index B: "; cin >> b;

            if (Is[b] == HugeInteger(0))
                cout << "Modulo by zero!\n";
            else
                cout << "Result = " << Is[a] % Is[b] << endl;
            break;

        case 21:
            cout << "Enter index: "; cin >> a;

            cout << "Result = " << -Is[a] << endl;
            break;

        case 22:
            cout << "Enter HugeInteger index: ";
            cin >> a;

            cout << "Enter digit index (0 = ones place): ";
            cin >> pos;

            cout << "Digit = " << Is[a][pos] << endl;
            break;

        }
        if (choice != 0)
        {
            cout << "\nPress any key...";
            _getch();
        }

    } while (choice != 0);

    delete[] Is;
    return;
}
void displayFractionMenu()
{
    cout << "=========== HugeFraction Operations ===========\n";
    cout << " 1. Add (A + B)\n";
    cout << " 2. Add and Assign (A += B)\n";
    cout << " 3. Subtract (A - B)\n";
    cout << " 4. Subtract and Assign (A -= B)\n";
    cout << " 5. Multiply (A * B)\n";
    cout << " 6. Multiply and Assign (A *= B)\n";
    cout << " 7. Divide (A / B)\n";
    cout << " 8. Divide and Assign (A /= B)\n";
    cout << " 9. Less Than (A < B)\n";
    cout << "10. Greater Than (A > B)\n";
    cout << "11. Less Than or Equal (A <= B)\n";
    cout << "12. Greater Than or Equal (A >= B)\n";
    cout << "13. Equality (A == B)\n";
    cout << "14. Inequality (A != B)\n";
    cout << "15. Unary Minus (-A)\n";
    cout << "16. Assignment (A = B)\n";
    cout << " 0. Exit\n";
    cout << "================================================\n";
}
void main_2()
{
    ifstream rdr("fractions.txt");

    if (!rdr)
    {
        cout << "File not found!\n";
        exit(1);
    }

    int n;
    rdr >> n;

    HugeFraction* Fs = new HugeFraction[n];

    for (int i = 0; i < n; i++)
        rdr >> Fs[i];

    int choice;

    do
    {
        system("cls");

        cout << "======= Loaded Fractions =======\n";
        for (int i = 0; i < n; i++)
            cout << i << " : " << Fs[i] << endl;

        cout << endl;

        displayFractionMenu();
        cin >> choice;

        int a, b;

        switch (choice)
        {
        case 1:
            cout << "Enter index A: "; cin >> a;
            cout << "Enter index B: "; cin >> b;
            cout << Fs[a] + Fs[b];
            break;

        case 2:
            cout << "Enter index A: "; cin >> a;
            cout << "Enter index B: "; cin >> b;
            Fs[a] += Fs[b];
            cout << Fs[a];
            break;

        case 3:
            cout << "Enter index A: "; cin >> a;
            cout << "Enter index B: "; cin >> b;
            cout << Fs[a] - Fs[b];
            break;

        case 4:
            cout << "Enter index A: "; cin >> a;
            cout << "Enter index B: "; cin >> b;
            Fs[a] -= Fs[b];
            cout << Fs[a];
            break;

        case 5:
            cout << "Enter index A: "; cin >> a;
            cout << "Enter index B: "; cin >> b;
            cout << Fs[a] * Fs[b];
            break;

        case 6:
            cout << "Enter index A: "; cin >> a;
            cout << "Enter index B: "; cin >> b;
            Fs[a] *= Fs[b];
            cout << Fs[a];
            break;

        case 7:
            cout << "Enter index A: "; cin >> a;
            cout << "Enter index B: "; cin >> b;
            cout << Fs[a] / Fs[b];
            break;

        case 8:
            cout << "Enter index A: "; cin >> a;
            cout << "Enter index B: "; cin >> b;
            Fs[a] /= Fs[b];
            cout << Fs[a];
            break;

        case 9:
            cout << "Enter index A: "; cin >> a;
            cout << "Enter index B: "; cin >> b;
            cout << (Fs[a] < Fs[b] ? "True" : "False");
            break;

        case 10:
            cout << "Enter index A: "; cin >> a;
            cout << "Enter index B: "; cin >> b;
            cout << (Fs[a] > Fs[b] ? "True" : "False");
            break;

        case 11:
            cout << "Enter index A: "; cin >> a;
            cout << "Enter index B: "; cin >> b;
            cout << (Fs[a] <= Fs[b] ? "True" : "False");
            break;

        case 12:
            cout << "Enter index A: "; cin >> a;
            cout << "Enter index B: "; cin >> b;
            cout << (Fs[a] >= Fs[b] ? "True" : "False");
            break;

        case 13:
            cout << "Enter index A: "; cin >> a;
            cout << "Enter index B: "; cin >> b;
            cout << (Fs[a] == Fs[b] ? "True" : "False");
            break;

        case 14:
            cout << "Enter index A: "; cin >> a;
            cout << "Enter index B: "; cin >> b;
            cout << (Fs[a] != Fs[b] ? "True" : "False");
            break;

        case 15:
            cout << "Enter index A: "; cin >> a;
            cout << -Fs[a];
            break;

        case 16:
            cout << "Enter index A: "; cin >> a;
            cout << "Enter index B: "; cin >> b;
            Fs[a] = Fs[b];
            cout << Fs[a];
            break;
        }
        if (choice != 0)
        {
            cout << "\nPress any key...";
            _getch();
        }

    } while (choice != 0);

    delete[] Fs;
    return ;
}
int main()
{
    int choice;
    do
    {
        system("cls");
        cout << "=========== Huge Integer and Fractions ===========\n";
        cout << " 1. Huge Integers\n";
        cout << " 2. Huge Fraction\n";
        cout << " 0. Exit\n";
        cout << "==================================================\n";
        cin >> choice;
        if (choice == 1)
        {
            main_1();
        }
        else if (choice == 2)
        {
            main_2();
        }

    } while (choice != 0);

    return 0;
}