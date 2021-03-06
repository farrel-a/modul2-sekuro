// NAMA/NIM : FARREL AHMAD/16520373
// PROGRAM Kalkulator Sederhana dan Kalkulator Integral
// MODUL 2 PROGRAMMING SEKURO
// SPESIFIKASI :
/*Program kalkulator yang dapat menghitung operasi sederhana dan
integral dengan pendekatan riemann dengan 100 partisi*/
#include <iostream>
#include <cmath>

using namespace std;

double bcalc (double a, char op, double b)
{double calcresult;
    if (op == '+'){
        calcresult = a+b;}
    else if (op == '-')
        {
        calcresult = a-b;
        }
    else if (op == '*')
        {
        calcresult= a*b;
        }
    else if (op == '/')
        {
        calcresult= a/b;
        }
    else if (op == 'p' || op == 'P')
        {
        calcresult=pow(a,b);
        }
    return calcresult;
}

double integral(double l, double u, int n1, double arr1[], int n2, double arr2[])
{
    // integral riemann trapesium dengan 1000 partisi
    double f_lowern, f_uppern, f_lowerd, f_upperd, delta, i, result, f_result, res_upper, res_lower;
    int j,k;
    delta = (u-l)/1000;
    result = 0;
    for (i = 1; i<=1000 ; i++)
    {
        l+=delta;
        f_lowern = 0;
        f_uppern = 0;
        for (j = n1; j>=0; j--)
        {
            f_lowern += (arr1[n1-j]*pow((l-delta),j));
        }
        for (k = n1; k>=0; k--)
        {
            f_uppern += (arr1[n1-k]*pow(l,k));
        }
        f_lowerd = 0;
        f_upperd = 0;
        for (j = n2; j>=0; j--)
        {
            f_lowerd += (arr2[n2-j]*pow((l-delta),j));
        }
        for (k = n2; k>=0; k--)
        {
            f_upperd += (arr2[n2-k]*pow(l,k));
        }
        res_lower = f_lowern/f_lowerd;
        res_upper = f_uppern/f_upperd;
        result += ((res_upper + res_lower)* delta)/2;
    }
    return result;
}
int main()
{
    int N1, N2, i;
    char com,op;
    double n1,n2, iresult, lb, ub, cresult;
    bool flag;
    flag = true;
    while(flag==true)
    {
    cout << "Welcome to Calculator++\nInsert\n'c' for basic caclulator\n'i' for integral calculator\n'e' for exit\nInsert Command: " ;
    cin >> com;
    if (com == 'e')
        {
            flag = false;
        }
    else if (com == 'c')
    {
        cout << "\nCommand List for Basic Calculator: " << endl;
        cout << "'+' for addition\n'-' for substraction\n'*' for multiplication\n'/' for division\n'p' for power" << endl;
        cout << "Insert first number: ";
        cin >> n1;
        cout << "Insert operator: ";
        cin >> op;
        cout << "Insert second number: ";
        cin >> n2;
        cout << "\nResult = " << bcalc(n1, op, n2) << "\n" << endl;
    }
    else if (com == 'i' || com == 'I')
    {
        cout << "\nYou are about to define a function" << endl;
        cout << "Please define a numerator" <<endl;
        cout << "Insert numerator degree: ";   //pembagi derajat berapa?
        cin >> N1;
        double arrnum1[N1+1];      //tempat koefisien dalam array
        for (i = N1; i>=0; i--)
        {
            cout << "Insert coefficient of x^" << i << ": ";
            cin >> arrnum1[N1-i];
        }
        cout << "\nPlease define a denominator" << endl;
        cout << "Insert denominator degree: ";
        cin >> N2;
        double arrnum2[N2+1];
        for (i = N2; i>=0; i--)
        {
            cout << "Insert coefficient of x^" << i << ": ";
            cin >> arrnum2[N2-i];
        }
        cout << "Insert lower bound: "; //batas bawah
        cin >> lb;
        cout << "Insert upper bound: "; //batas atas
        cin >> ub;
        iresult = integral(lb, ub, N1, arrnum1, N2, arrnum2);
        cout << "\nResult = " << iresult <<"\n"<<endl;
    }
    else {
        cout << endl;
        cout << "Invalid Command" << endl;
        cout << endl;
    }
    }

    return 0;
}
