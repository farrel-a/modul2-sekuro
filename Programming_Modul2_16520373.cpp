// NAMA/NIM : FARREL AHMAD/16520373
// PROGRAM Kalkulator Sederhana dan Kalkulator Integral
// MODUL 2 PROGRAMMING SEKURO
// SPESIFIKASI :
/*Program kalkulator yang dapat menghitung operasi sederhana dari dua
bilangan integer atau double floating point dan menghitung
integral tentu menggunakan pendekatan riemann dengan 100 partisi*/
#include <iostream>
#include <cmath>

using namespace std;

// fungsi kalkulator sederhana
// parameter input:
// a : angka pertama
// op : operator
// b : angka kedua
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
// fungsi integral
// parameter input (berurut) :
// l : batas bawah (lower bound)
// u : batas atas (upper bound)
// n1 : derajat polinom pembilang
// arr1[] : array penyimpan koefisien variabel x pada pembilang (numerator)
// n2 : derajat polinom penyebut
// arr2 [] : array penyimpan koefisien variabel x pada penyebut (denominator)
double integral(double l, double u, int n1, double arr1[], int n2, double arr2[])
{
    // integral riemann trapesium dengan 1000 partisi
    double f_lowern, f_uppern, f_lowerd, f_upperd, delta, i, result, res_upper, res_lower;
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
    int N1, N2, i;  // N1 input(N1), N2 input(N2), i bil.int for loop
    char com,op; // com input command, op input operator
    double n1,n2, iresult, lb, ub; //n1 & n2 : num1 & num2 kalkulator sederhana, iresult : integral result, lb : lower bound, ub : upper bound (integral)
    bool flag; // flag while loop
    flag = true;
    while(flag==true)
    {
    cout << "Welcome to Calculator++\nInsert\n'c' for basic caclulator\n'i' for integral calculator\n'e' for exit\nInsert Command: " ;
    cin >> com;  // input command
    if (com == 'e' || com == 'E')   //kondisional penyelesaian program/exit program
        {
            flag = false;
        }
    else if (com == 'c' || com == 'C') //kondisional kalkulator sederhana
    {
        cout << "\nCommand List for Basic Calculator: " << endl;
        cout << "'+' for addition\n'-' for substraction\n'*' for multiplication\n'/' for division\n'p' for power" << endl;
        cout << "Insert first number: ";
        cin >> n1;
        cout << "Insert operator: ";
        cin >> op;
        cout << "Insert second number: ";
        cin >> n2;
        cout << "\nResult = " << bcalc(n1, op, n2) << "\n" << endl;  // output kalkulator sederhana
    }
    else if (com == 'i' || com == 'I') //kondisional kalkulator integral
    {
        cout << "\nYou are about to define a function" << endl;
        cout << "Please define a numerator" <<endl;
        cout << "Insert numerator degree: ";   // pembilang derajat berapa?
        cin >> N1;
        double arrnum1[N1+1];      // tempat penyimpanan koefisien pembilang dalam array
        for (i = N1; i>=0; i--)
        {
            cout << "Insert coefficient of x^" << i << ": ";
            cin >> arrnum1[N1-i];
        }
        cout << "\nPlease define a denominator" << endl;
        cout << "Insert denominator degree: "; // penyebut derajat berapa?
        cin >> N2;
        double arrnum2[N2+1];  // tempat penyimpanan koefisien penyebut dalam array
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
        cout << "\nResult = " << iresult <<"\n"<<endl; // output integral tentu
    }
    else // kondisional input command tidak sesuai
    {
        cout << endl;
        cout << "Invalid Command" << endl;
        cout << endl;
    }
    }

    return 0;
}
