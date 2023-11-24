#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stdio.h>
#include <sstream>
#include <iomanip>

using namespace std;

class Array
{
private:
    vector <unsigned int> array;
    int arraySize;
public:
    
    void VectorClear()
    {
        array.clear();
    }
    void ArraySizeInput(int size)
    {
        arraySize = size;
    }
    
    void ElementReplase(int index)
    {
        unsigned int boofer;
        
        cin >> boofer;
        array[index] = boofer;
    }
    
    void ArrayInput()
    {
        unsigned int boofer;
        
        for (int i = 0; i < arraySize; i++)
        {
            cin >> boofer;
            array.push_back(boofer);
        }
    }
    
    void ArrayDispley (int nomber)
    {
        cout << "Array" << nomber << ' ';
        for (int i = 0; i < arraySize; i++)
        {
            cout << dec << array[i] << ' ';
        }
    }
    
    int GetArraySize()
    {
        return arraySize;
    }
    
    int GetArray(int index)
    {
        return array[index];
    }
};

class Hex: public Array
{
private:
    unsigned char massivHex [100];
    int arraySize;
public:
    
    void MassvClear()
    {
        for (int i = 0; i < 100; i++)
        {
            massivHex[i] = '0';
        }
    }
    
    void HexSizeInput(int size)
    {
        arraySize = size;
    }
    
    void HexMassivInput()
    {
        unsigned char boofer;
        
        for (int i = 0; i < arraySize; i++)
        {
            cin >> boofer;
            massivHex[i] = boofer;
        }
    }
    
    void HexDispley(int nomber)
    {
        cout << "Hex" << nomber << ' ';
        for (int i = arraySize - 1; i > -1; i--)
        {
            cout << massivHex[i];
        }
        cout << ' ';
    }
    
    vector <int> GetVector()
    {
        vector <int> result;
        
        for (int i = 0; i < arraySize; i++)
        {
             result.push_back(int(massivHex[i] - '0'));
        }
        return result;
    }
    
    int WhatSupper(char simbol)
    {
        int result = 0;
        
        switch (simbol) {
            case 'A':
                result = 10;
                break;
            case 'B':
                result = 11;
                break;
            case 'C':
                result = 12;
                break;
            case 'D':
                result = 13;
                break;
            case 'E':
                result = 14;
                break;
            case 'F':
                result = 15;
                break;
        }
        
        return result;
    }
    
    long long ConvertationToInt()
    {
        long long result = 0;
        int stepen = arraySize - 1;
        string element;
        vector <int> normalArray;
        
        for (int i = arraySize - 1; i > -1; i--)
        {
            if (isupper(massivHex[i]))
            {
                normalArray.push_back(WhatSupper(massivHex[i]));
            }
            else
            {
                normalArray.push_back(int(massivHex[i] - '0'));
            }
        }
        
        for (int k = 0; k < arraySize; k++)
        {
            result += normalArray[k] * pow(16, stepen);
            stepen--;
        }
        //3268edcba3 - 216508779427   348cadbe91 - 225698496145
        return result;
    }
};

class Money: public Array
{
private:
    vector <unsigned char> massivMoney;
    int massivSize;
public:
    
    void VectorClear()
    {
        massivMoney.clear();
    }
    
    stringstream ConvertationToDouble()
    {
        stringstream result;
        string elem;
        int index = massivSize - 1;
        
        for (; index > 1; index--)
        {
            elem += massivMoney[index];
        }
        elem += '.';
        for (; index > -1; index--)
        {
            elem += massivMoney[index];
        }
        result << elem;
        return result;
    }
    
    long double ConvertationToDoubleTwo()
    {
        long double result;
        string elem;
        int index = massivSize - 1;
        
        for (; index > 1; index--)
        {
            elem += massivMoney[index];
        }
        elem += '.';
        for (; index > -1; index--)
        {
            elem += massivMoney[index];
        }
        result = stold(elem);
        return result;
    }
    
    void MoneySizeInput(int size)
    {
        massivSize = size;
    }
    
    void MoneyMassivInput()
    {
        unsigned char boofer;
        
        for (int i = 0; i < massivSize; i++)
        {
            cin >> boofer;
            massivMoney.push_back(boofer);
        }
    }
    
    void MoneyDispley(int elem)
    {
        int index = massivSize - 1;
        
        cout << "Money" << elem << ' ';
        for (; index > 1; index--)
        {
            cout << massivMoney[index];
        }
        cout << '.';
        for (; index > -1; index--)
        {
            cout << massivMoney[index];
        }
        cout << ' ';
    }
};

void InHexConvertation(long double decElem)
{
    vector <long long> resultVector;
    string result;
    
    while (decElem > 15)
    {
        long long k = decElem / 16;
        resultVector.push_back(decElem - k * 16);
        decElem = k;
    }
    resultVector.push_back(decElem);
    
    for (int i = int(resultVector.size()) -1; i > -1; i--)
    {
        switch (resultVector[i]) {
            case 10:
                result += 'a';
                break;
            case 11:
                result += 'b';
                break;
            case 12:
                result += 'c';
                break;
            case 13:
                result += 'd';
                break;
            case 14:
                result += 'e';
                break;
            case 15:
                result += 'f';
                break;
            default:
                result += to_string(resultVector[i]);
                break;
        }
    }
    cout << result << endl;
}

void ArrayElementsSum(Array Object1, Array Object2)
{
    int arraySize = Object1.GetArraySize();
    
    cout << "Array1+Array2 ";
    
    for (int i = 0; i < arraySize; i++)
    {
        cout << dec << Object1.GetArray(i) + Object2.GetArray(i) << ' ';
    }
    cout << endl;
}

void GetHexSum(Hex ObjectH1, Hex ObjectH2)
{
    
    cout << "Hex1+Hex2 ";
    cout << fixed << hex << fixed << ObjectH1.ConvertationToInt() + ObjectH2.ConvertationToInt() << endl;
}

void GetHexDifference(Hex ObjectH1, Hex ObjectH2)
{
    
    if (ObjectH1.ConvertationToInt() < ObjectH2.ConvertationToInt())
    {
        cout << "Hex1-Hex2 -";
        cout << fixed << hex << fixed << ObjectH2.ConvertationToInt() - ObjectH1.ConvertationToInt() << endl;
    }
    else
    {
        cout << "Hex1-Hex2 ";
        cout << fixed << hex << fixed << ObjectH1.ConvertationToInt() - ObjectH2.ConvertationToInt() << endl;
    }
}

void GetHexCompos(Hex ObjectH1, Hex ObjectH2)
{
    
    cout << "Hex1*Hex2 ";
    cout << fixed << hex << fixed << ObjectH1.ConvertationToInt() * ObjectH2.ConvertationToInt() << endl;
}

void GetHexDivision(Hex ObjectH1, Hex ObjectH2)
{

    cout << "Hex1/Hex2 ";
    cout << fixed << hex << fixed << ObjectH1.ConvertationToInt() / ObjectH2.ConvertationToInt() << endl;
}

void NormalizeDouble(string result, int kol)
{
    switch (kol) {
        case 2:

            for(int i = 0; i < result.size(); i++)
                {
                    if (result[i] == '.')
                    {
                        cout << result[i] << result[i+1] << result[i+2];
                        break;
                    }
                    else
                    {
                        cout << result[i];
                    }
                }
            break;
        case 3:
            for(int i = 0; i < result.size(); i++)
                {
                    if (result[i] == '.')
                    {
                        cout << result[i] << result[i+1] << result[i+2] << result[i+3];
                        break;
                    }
                    else
                    {
                        cout << result[i];
                    }
                }
            break;
    }
    
}

void GetMoneySum(Money ObjectM1, Money ObjectM2)
{
    long double a, b;
    
    a = ObjectM1.ConvertationToDoubleTwo();
    b = ObjectM2.ConvertationToDoubleTwo();
    cout << "Money1+Money2 ";
    NormalizeDouble(to_string(a + b), 2);
    cout << endl;
}

void GetMoneyDifference(Money ObjectM1, Money ObjectM2)
{
    long double a, b;
    
    a = ObjectM1.ConvertationToDoubleTwo();
    b = ObjectM2.ConvertationToDoubleTwo();
    cout << "Money1-Money2 ";
    NormalizeDouble(to_string(a - b), 2);
    cout << endl;
}

void GetMoneyCompos(Money ObjectM1, Money ObjectM2, double chislo)
{
    double a, b;
    string result1, result2;

    a = ObjectM1.ConvertationToDoubleTwo();
    b = ObjectM2.ConvertationToDoubleTwo();
    
    cout << "Money1*chislo ";
    result1 = to_string(a * chislo);
    NormalizeDouble(result1, 2);
    
    cout << " Money2*chislo ";
    result2 = to_string(b * chislo);
    NormalizeDouble(result2, 2);
    
    cout << endl;
}

void GetMoneyDivision(Money ObjectM1, Money ObjectM2)
{
    long double a, b;

    a = ObjectM1.ConvertationToDoubleTwo();
    b = ObjectM2.ConvertationToDoubleTwo();
    cout << "Money1/Money2 ";
    NormalizeDouble(to_string(round(a/b*1000)/1000), 3);
    
    cout << endl;
}

int SizeInput()
{
    int size;
    
    cin >> size;
    return size;
}

double ChisloInput()
{
    double chislo = 0.0;
    
    cin >> chislo;
    return chislo;
}

void Control(Array Object1, Array Object2, Hex ObjectH1, Hex ObjectH2, Money ObjectM1, Money ObjectM2, double mnosh)
{
    int comand = 0;
    double chislo = mnosh;
    int index = 0;
    
    do{
        cin >> comand;
        switch (comand) {
            case 1:
                cin >> index;
                Object1.ElementReplase(index);
                Object1.ArrayDispley(1); //вывод значения Array1
                Object2.ArrayDispley(2); //вывод значения Array2
                cout << endl;
                ArrayElementsSum(Object1, Object2);
                break;
            case 2:
                cin >> index;
                Object2.ElementReplase(index);
                Object1.ArrayDispley(1); //вывод значения Array1
                Object2.ArrayDispley(2); //вывод значения Array2
                cout << endl;
                ArrayElementsSum(Object1, Object2);
                break;
            case 3:
                ObjectH1.MassvClear();
                ObjectH1.HexMassivInput();
                ObjectH1.HexDispley(1); //Вывод значения Hex1
                ObjectH2.HexDispley(2); //Вывод значения Hex2
                cout << endl;
                GetHexSum(ObjectH1, ObjectH2); //вывод суммы
                GetHexDifference(ObjectH1, ObjectH2); //вывод разницы
                GetHexCompos(ObjectH1, ObjectH2); //вывод произведения
                GetHexDivision(ObjectH1, ObjectH2); //вывод деления
                break;
            case 4:
                ObjectH2.MassvClear();
                ObjectH2.HexMassivInput();
                ObjectH1.HexDispley(1); //Вывод значения Hex1
                ObjectH2.HexDispley(2); //Вывод значения Hex2
                cout << endl;
                GetHexSum(ObjectH1, ObjectH2); //вывод суммы
                GetHexDifference(ObjectH1, ObjectH2); //вывод разницы
                GetHexCompos(ObjectH1, ObjectH2); //вывод произведения
                GetHexDivision(ObjectH1, ObjectH2); //вывод деления
                break;
            case 5:
                ObjectM1.VectorClear();
                ObjectM1.MoneyMassivInput();
                ObjectM1.MoneyDispley(1); //вывод значения класса Money1
                ObjectM2.MoneyDispley(2); //вывод значения класса Money2
                cout << endl;
                GetMoneySum(ObjectM1, ObjectM2);
                GetMoneyDifference(ObjectM1, ObjectM2);
                GetMoneyCompos(ObjectM1, ObjectM2, chislo);
                GetMoneyDivision(ObjectM1, ObjectM2);
                break;
            case 6:
                ObjectM2.VectorClear();
                ObjectM2.MoneyMassivInput();
                ObjectM1.MoneyDispley(1); //вывод значения класса Money1
                ObjectM2.MoneyDispley(2); //вывод значения класса Money2
                cout << endl;
                GetMoneySum(ObjectM1, ObjectM2);
                GetMoneyDifference(ObjectM1, ObjectM2);
                GetMoneyCompos(ObjectM1, ObjectM2, chislo);
                GetMoneyDivision(ObjectM1, ObjectM2);
                break;
            case 7:
                cin >> chislo;
                ObjectM1.MoneyDispley(1); //вывод значения класса Money1
                ObjectM2.MoneyDispley(2); //вывод значения класса Money2
                cout << endl;
                GetMoneySum(ObjectM1, ObjectM2);
                GetMoneyDifference(ObjectM1, ObjectM2);
                GetMoneyCompos(ObjectM1, ObjectM2, chislo);
                GetMoneyDivision(ObjectM1, ObjectM2);
                break;
        }
    }while(comand != 0);
}

int main()
{
    Array Object1, Object2;
    Hex ObjectH1, ObjectH2;
    Money ObjectM1, ObjectM2;
    
    double chislo = 0.0;
    int arraySize = SizeInput(); //инициализация и ввод array
    
    Object1.ArraySizeInput(arraySize); //передача размера в array1
    Object2.ArraySizeInput(arraySize);//передача размера array2
    
    Object1.ArrayInput(); //ввод элементов array1
    Object2.ArrayInput(); //ввод элементов array2
    
    Object1.ArrayDispley(1); //вывод значения Array1
    Object2.ArrayDispley(2); //вывод значения Array2
    cout << endl;
    
    ArrayElementsSum(Object1, Object2);
    
    arraySize = SizeInput(); //ввод размерности Hex
    
    ObjectH1.HexSizeInput(arraySize); //передача размера в Hex1
    ObjectH2.HexSizeInput(arraySize);//передача размера в Hex2
        
    ObjectH1.HexMassivInput(); //ввод элементов Hex1
    ObjectH2.HexMassivInput(); //ввод элементов Hex2
    
    ObjectH1.HexDispley(1); //Вывод значения Hex1
    ObjectH2.HexDispley(2); //Вывод значения Hex2
    cout << endl;
    
    GetHexSum(ObjectH1, ObjectH2); //вывод суммы
    GetHexDifference(ObjectH1, ObjectH2); //вывод разницы
    GetHexCompos(ObjectH1, ObjectH2); //вывод произведения
    GetHexDivision(ObjectH1, ObjectH2); //вывод деления
    
    arraySize = SizeInput(); //ввод размерности Money
    
    ObjectM1.MoneySizeInput(arraySize); //передача размера в Money1
    ObjectM2.MoneySizeInput(arraySize);//передача размера в Money2
    
    ObjectM1.MoneyMassivInput(); //ввод элементов Money1
    ObjectM2.MoneyMassivInput(); //ввод элементов Money2
    
    chislo = ChisloInput(); //Ввод последнего double числа
        
    ObjectM1.MoneyDispley(1); //вывод значения класса Money1
    ObjectM2.MoneyDispley(2); //вывод значения класса Money2
    cout << endl;
    
    GetMoneySum(ObjectM1, ObjectM2);
    GetMoneyDifference(ObjectM1, ObjectM2);
    GetMoneyCompos(ObjectM1, ObjectM2, chislo);
    GetMoneyDivision(ObjectM1, ObjectM2);
    
    Control(Object1, Object2, ObjectH1, ObjectH2, ObjectM1, ObjectM2, chislo);
    return 0;
}


