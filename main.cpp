//#define lab5_1
//#define lab5_2
//#define lab5_3
//#define lab5_4
//#define lab5_5
//#define lab5_6
//#define lab5_7
//#define lab5_8
//#define lab5_9
#define lab5_10

#define lab5_12
#include <iostream>


//Задача 1--------------------------------------------------------------------------------------------------------------------------------------------
#ifdef lab5_1
#include <QTime>
#include <QCoreApplication>
#define MAXFLOOR '7'       //Максимальный этаж
#define MINFLOOR '0'       //Минимальный этаж

//Функция задержки
void delay(int time)
{
    QTime dieTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, time);
}

//Очистка буфера cin
#define BUFF_CLEAR std::cin.ignore(10000, '\n')

//Функция верификации ввода
void inputVerification(char& input)
{
    if(input == 'q' || input =='Q') return;
    while (std::cin.fail() || MINFLOOR < MINFLOOR || input > MAXFLOOR)
    {
        std::cin.clear();
        BUFF_CLEAR;
        std::cout<<"Вводите положительные числовые значения от 1 до 7\n";
        std::cin>>input;
    }
}

//Функция лифта
void elevator(char& number, char& currentFloor, std::string place[])
{
    //Если введенный пользователем этаж больше текущего едем вверх
    if(number > currentFloor)
    {
        for(char i = currentFloor; i <= number; ++i)
        {
            delay(1000);
            std::cout<<"\n"<<i;
        }
        currentFloor = number;
        std::cout<<" - "<<place[currentFloor & 0xf]<<"\n";
    }

    //Если введенный пользователем этаж меньше текущего едем вниз
    else if(number < currentFloor)
        {
            for(char i = currentFloor; i >= number; --i)
            {
                delay(1000);
                std::cout<<"\n"<<i;
            }

            currentFloor = number;
            std::cout<<" - "<<place[currentFloor & 0xf]<<"\n";
        }
        else std::cout<<"Вы находитесь на этаже "<<currentFloor<<"\n";
    std::cout<<"Введите номер этажа или q для выхода из программы\n";
    std::cout<<"0 - Parking\n"<<"1 - Entertainment\n"<<"2 - Home\n"<<"3 - Cinema\n"<<"4 - Dishes\n"<<"5 - Casino\n"
            <<"6  - Cafe\n"<<"7 - Shoes\n";
    std::cin>>number;
    inputVerification(number);
    BUFF_CLEAR;
}

int main()
{
    char currentFloor{'0'};   //Переменная для хранения текущего этажа
    char number;              //Переменная для хнранения номера этажа введенного пользователем
    std::string place[MAXFLOOR+1]{"Parking", "Entertainment", "Home", "Cinema", "Dishes", "Casino", "Cafe", "Shoes"};
    std::cout<<"Введите номер этажа или q для выхода из программы\n";
    std::cout<<"0 - Parking\n"<<"1 - Entertainment\n"<<"2 - Home\n"<<"3 - Cinema\n"<<"4 - Dishes\n"<<"5 - Casino\n"
            <<"6  - Cafe\n"<<"7 - Shoes\n";
    std::cin>>number;
    inputVerification(number);
    BUFF_CLEAR;
    while(number!='q' && number!='Q')
    {
        elevator(number, currentFloor, place);
    }
    std::cout<<"Всего хорошего!";
    return 0;
}
#endif
//-----------------------------------------------------------------------------------------------------------------------------------------------------

//Задача 2---------------------------------------------------------------------------------------------------------------------------------
#ifdef lab5_2

enum class ENIMALS{
    PIG,
    CHIKEN,
    GOAT,
    CAT,
    DOG
};

int printNumberOfLegs(ENIMALS enimals)
{
    switch(enimals)
    {
    case ENIMALS::PIG: return 4;
    case ENIMALS::CHIKEN: return 2;
    case ENIMALS::GOAT: return 4;
    case ENIMALS::CAT: return 4;
    case ENIMALS::DOG: return 4;
    default:std::cout<<"Invalid parameter";return 0;
    }
}
 std::string getAnimalName(ENIMALS enimals)
 {
     switch(enimals)
     {
        case ENIMALS::PIG: return "pig";
        case ENIMALS::CHIKEN: return "chiken";
        case ENIMALS::GOAT: return "goat";
        case ENIMALS::CAT: return "cat";
        case ENIMALS::DOG: return "dog";
        default:std::cout<<"Invalid parameter";return 0;
     }
 }



int main()
{
    std::cout<<"The "<<getAnimalName(ENIMALS::PIG)<<" has "<<printNumberOfLegs(ENIMALS::PIG)<<" legs";
}
#endif
//--------------------------------------------------------------------------------------------------------------------------------------

//Задача 3---------------------------------------------------------------------------------------------------------------------------------
#ifdef lab5_3
int main()
{
    auto z = 7;
    int m = 300;
    auto fx = 300.600006;
    auto cht = z;

    std::cout<<"Адррес m = "<<&m<<"\nАдррес fx = "<<&fx<<"\nАдррес cht = "<<&cht;
    std::cout<<"\nЗначение по адресу m = "<<*(&m)<<"\nЗначение по адресу fx = "<<*(&fx)<<"\nЗначение по адресу cht = "<<*(&cht);
    auto *ptrM = &m;
    auto *ptrFx = &fx;
    auto *ptrCht  = &cht;
    std::cout<<"\nАдрес m = "<<ptrM<<"\nАдрес fx = "<<ptrFx<<"\nАдрес cht = "<<ptrCht;
    std::cout<<"\nЗначение по адресу m = "<<*ptrM<<"\nЗначение по адресу fx = "<<*ptrFx<<"\nЗначение по адресу cht = "<<*ptrCht;
    return 0;
}
#endif
//---------------------------------------------------------------------------------------------------------------------------------

//Задача 4----------------------------------------------------------------------------------------------------------------------------
#ifdef lab5_4


int main()
{
    constexpr int size = 5;
    int arr[size] = {5, 7, 2, 9, 8};
    int *ptr = arr;
    for(int i = 0; i < size; ++i)
        std::cout<<ptr+i<<" ";
    std::cout<<"\n";
    for(int i = 0; i < size; ++i)
        std::cout<<ptr[i]<<" ";
    return 0;
}
#endif
//----------------------------------------------------------------------------------------------------------------------------

//Задача 5--------------------------------------------------------------------------------------------------------------------------------
#ifdef lab5_5

// Функция для печати варианта перестановки
void printArr(char (&arr)[5], int n)
{
    for (int i = 0; i < n; i++)
        std::cout<<arr[i]<< " ";
    std::cout<<"\n";
}

// Алгоритм кучи для генерации перестановок
void heapPermutation(char (&arr)[5], int size, int n)
{
    //Если размер становится 1 то печатается полцченая перестановка
    if (size == 1) {
        printArr(arr, n);
        return;
    }

    for (int i = 0; i < size; i++) {
        heapPermutation(arr, size - 1, n);

      //Если размер нечетный то меняем местами первый и последний элемент
        if (size % 2 == 1)
            std::swap(arr[0], arr[size - 1]);

      //Если размер четный то меняем местами i-й и последний элемент
        else
            std::swap(arr[i], arr[size - 1]);
    }
}

int main()
{
    char arr[]{"UVWN"};
    int n = (sizeof arr / sizeof arr[0]) - 1;
    heapPermutation(arr, n, n);
    return 0;
}
#endif
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

//Задача 6--------------------------------------------------------------------------------------------------------------------------------------------------
#ifdef lab5_6
//#define POINTER
#define STDFUNCTION
#include <functional>

#ifdef POINTER
bool logic(int a, int b, bool(*func)(int, int) )
{
    return func(a,b);
}

//И
bool andFunc(int a, int b)
{
    return a && b;
}

//Или
bool orFunc(int a, int b)
{
    return a || b;
}

//Исключающее или
bool xorFunc(int a, int b)
{
    return a ^ b;
}
#endif

#ifdef STDFUNCTION
bool logic(int a, int b, std::function<bool(int, int)>func)
{
    return func(a,b);
}

//И
bool andFunc(int a, int b)
{
    return a && b;
}

//Или
bool orFunc(int a, int b)
{
    return a || b;
}

//Исключающее или
bool xorFunc(int a, int b)
{
    return a ^ b;
}
#endif
int main()
{
    std::cout<<std::boolalpha<<logic(3, 0, andFunc)<<"\n";
    std::cout<<logic(3, 0, orFunc)<<"\n";
    std::cout<<logic(3, 3, xorFunc)<<"\n";
}

#endif
//-----------------------------------------------------------------------------------------------------------------------------------------------------

//Задача 7--------------------------------------------------------------------------------------------------------------------------------------------------
#ifdef lab5_7
#define SIZE 12
void printArr(int arr[], int size)
{
    for(int i = 0; i < size; ++i)
        std::cout<<arr[i]<<" ";
}

//Фуекция для обмена четных и нечетных членов массива
void swapArr(int arr[], int size)
{
    for(int i = 0; i < size; ++i)
        if(i & 1) std::swap(arr[i], arr[i-1]);
}

//Функция замены всех символов нижнего регситра на верхний в строке
void upper(std::string &text)
{
    for(int i = 0; i < static_cast<int>(text.length()); ++i)
        if(std::islower(text[i])) text[i]-=32;
}

int main()
{
    int *ptr{new int[SIZE]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}};
    printArr(ptr, SIZE);
    std::cout<<"\n";
    swapArr(ptr, SIZE);
    printArr(ptr, SIZE);
    std::cout<<"\n";
    std::string text{"hoW muCH is The fiSH"};
    upper(text);
    std::cout<<text;
    delete []ptr;
}
#endif
//-----------------------------------------------------------------------------------------------------------------------------------------------------

//Задача 8---------------------------------------------------------------------------------------------------------------------------------------------
#ifdef lab5_8
#include <ctime>

//Функция для подсчета количества цифр в числе
int Exponent(int number)
{
    int res = 0;
    while(number > 0)
    {
      number/= 10;
      res++;
    }
    return res;
}

//Функция восстановления строки
void strRecovery(std::string &text)
{
    int i = 0;
    while(text[i]!='\0')        //Перебираем индексы до конца строки
    {
        if(std::isdigit(text[i]))
        {
            std::string number;  //строка для хранения числа в виде строки
            int j = i;

            while(std::isdigit(text[j])) //Пока значение по индексу число, добавляем его в строку
            {
                number+=text[j];
                ++j;
            }

            //Заменяем то что нжно
            text.replace(i, Exponent(stoi(number)), stoi(number)-1, text[i+Exponent(stoi(number))]);
            i+=stoi(number);
        }
        else ++i;
    }
}

//stoi(text) - функция для получения количества символов
int main()
{
     std::string text{"11AB1C4D"};
     strRecovery(text);
     std::cout<<text;

     return 0;
}
#endif
//---------------------------------------------------------------------------------------------------------------------------------------------------

//Задача 9--------------------------------------------------------------------------------------------------------------------------------------------
#ifdef lab5_9

void spaceDelete(std::string &text)
{
    //Удаляем все пробельные символы в начале строки
    while (isspace(text[0]))
        text.erase(0, 1);

    int i = 0;
    //Перебираем по всем элементам до конца строки
    while(text[i]!= '\0')
    {
        //Если символ табуляции заменяем его на пробельный
        if(text[i] == '\t')
            text[i] = ' ';

        //Если 2 подряд символа пробельные, удаляем 1 из них
        if(isspace(text[i]) && isspace(text[i+1]))
        {
            text.erase(i, 1);
        }
        else ++i;
    }
}


int main()
{
    std::string input = " \t\t aa dad \t\t   a \t sd";
    std::cout<<input<<"\n";
    spaceDelete(input);
    std::cout<<input;

}
#endif
//---------------------------------------------------------------------------------------------------------------------------------------------------

#ifdef lab5_10
#include <vector>
#include <algorithm>
#define SIZE 25
//using namespace std;
int main()
{
    std::vector<std::string> input; //Вектор строк для хранения введенных данных
    std::string name;               //Буфер
    int i = 0;

    do
    {
        std::cout << "Введите " << i << "-ю строку или Enter для завершения ";
        std::getline(std::cin, name);
        input.push_back(name);
        ++i;
    }

    //Пока строка не нулевая и нет конца файла
    while(!name.empty() && !std::cin.eof());
    input.pop_back();
    std::sort(input.begin(), input.end());
    auto it = input.begin();

    std::cout<<"Отсортированные строки:\n";
    while (it != input.end())
      {
       std::cout << *it << "\n"; // выводим значение элемента, на который указывает итератор
       ++it; // и переходим к следующему элементу
      }
}

#endif

