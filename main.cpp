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


//����� 1--------------------------------------------------------------------------------------------------------------------------------------------
#ifdef lab5_1
#include <QTime>
#include <QCoreApplication>
#define MAXFLOOR '7'       //���ᨬ���� �⠦
#define MINFLOOR '0'       //��������� �⠦

//�㭪�� ����প�
void delay(int time)
{
    QTime dieTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, time);
}

//���⪠ ���� cin
#define BUFF_CLEAR std::cin.ignore(10000, '\n')

//�㭪�� ���䨪�樨 �����
void inputVerification(char& input)
{
    if(input == 'q' || input =='Q') return;
    while (std::cin.fail() || MINFLOOR < MINFLOOR || input > MAXFLOOR)
    {
        std::cin.clear();
        BUFF_CLEAR;
        std::cout<<"������ ������⥫�� �᫮�� ���祭�� �� 1 �� 7\n";
        std::cin>>input;
    }
}

//�㭪�� ����
void elevator(char& number, char& currentFloor, std::string place[])
{
    //�᫨ �������� ���짮��⥫�� �⠦ ����� ⥪�饣� ���� �����
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

    //�᫨ �������� ���짮��⥫�� �⠦ ����� ⥪�饣� ���� ����
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
        else std::cout<<"�� ��室���� �� �⠦� "<<currentFloor<<"\n";
    std::cout<<"������ ����� �⠦� ��� q ��� ��室� �� �ணࠬ��\n";
    std::cout<<"0 - Parking\n"<<"1 - Entertainment\n"<<"2 - Home\n"<<"3 - Cinema\n"<<"4 - Dishes\n"<<"5 - Casino\n"
            <<"6  - Cafe\n"<<"7 - Shoes\n";
    std::cin>>number;
    inputVerification(number);
    BUFF_CLEAR;
}

int main()
{
    char currentFloor{'0'};   //��६����� ��� �࠭���� ⥪�饣� �⠦�
    char number;              //��६����� ��� �࠭���� ����� �⠦� ���������� ���짮��⥫��
    std::string place[MAXFLOOR+1]{"Parking", "Entertainment", "Home", "Cinema", "Dishes", "Casino", "Cafe", "Shoes"};
    std::cout<<"������ ����� �⠦� ��� q ��� ��室� �� �ணࠬ��\n";
    std::cout<<"0 - Parking\n"<<"1 - Entertainment\n"<<"2 - Home\n"<<"3 - Cinema\n"<<"4 - Dishes\n"<<"5 - Casino\n"
            <<"6  - Cafe\n"<<"7 - Shoes\n";
    std::cin>>number;
    inputVerification(number);
    BUFF_CLEAR;
    while(number!='q' && number!='Q')
    {
        elevator(number, currentFloor, place);
    }
    std::cout<<"�ᥣ� ��襣�!";
    return 0;
}
#endif
//-----------------------------------------------------------------------------------------------------------------------------------------------------

//����� 2---------------------------------------------------------------------------------------------------------------------------------
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

//����� 3---------------------------------------------------------------------------------------------------------------------------------
#ifdef lab5_3
int main()
{
    auto z = 7;
    int m = 300;
    auto fx = 300.600006;
    auto cht = z;

    std::cout<<"����� m = "<<&m<<"\n����� fx = "<<&fx<<"\n����� cht = "<<&cht;
    std::cout<<"\n���祭�� �� ����� m = "<<*(&m)<<"\n���祭�� �� ����� fx = "<<*(&fx)<<"\n���祭�� �� ����� cht = "<<*(&cht);
    auto *ptrM = &m;
    auto *ptrFx = &fx;
    auto *ptrCht  = &cht;
    std::cout<<"\n���� m = "<<ptrM<<"\n���� fx = "<<ptrFx<<"\n���� cht = "<<ptrCht;
    std::cout<<"\n���祭�� �� ����� m = "<<*ptrM<<"\n���祭�� �� ����� fx = "<<*ptrFx<<"\n���祭�� �� ����� cht = "<<*ptrCht;
    return 0;
}
#endif
//---------------------------------------------------------------------------------------------------------------------------------

//����� 4----------------------------------------------------------------------------------------------------------------------------
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

//����� 5--------------------------------------------------------------------------------------------------------------------------------
#ifdef lab5_5

// �㭪�� ��� ���� ��ਠ�� ����⠭����
void printArr(char (&arr)[5], int n)
{
    for (int i = 0; i < n; i++)
        std::cout<<arr[i]<< " ";
    std::cout<<"\n";
}

// ������ ��� ��� �����樨 ����⠭����
void heapPermutation(char (&arr)[5], int size, int n)
{
    //�᫨ ࠧ��� �⠭������ 1 � ���⠥��� ����祭�� ����⠭����
    if (size == 1) {
        printArr(arr, n);
        return;
    }

    for (int i = 0; i < size; i++) {
        heapPermutation(arr, size - 1, n);

      //�᫨ ࠧ��� ����� � ���塞 ���⠬� ���� � ��᫥���� �����
        if (size % 2 == 1)
            std::swap(arr[0], arr[size - 1]);

      //�᫨ ࠧ��� ��� � ���塞 ���⠬� i-� � ��᫥���� �����
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

//����� 6--------------------------------------------------------------------------------------------------------------------------------------------------
#ifdef lab5_6
//#define POINTER
#define STDFUNCTION
#include <functional>

#ifdef POINTER
bool logic(int a, int b, bool(*func)(int, int) )
{
    return func(a,b);
}

//�
bool andFunc(int a, int b)
{
    return a && b;
}

//���
bool orFunc(int a, int b)
{
    return a || b;
}

//�᪫���饥 ���
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

//�
bool andFunc(int a, int b)
{
    return a && b;
}

//���
bool orFunc(int a, int b)
{
    return a || b;
}

//�᪫���饥 ���
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

//����� 7--------------------------------------------------------------------------------------------------------------------------------------------------
#ifdef lab5_7
#define SIZE 12
void printArr(int arr[], int size)
{
    for(int i = 0; i < size; ++i)
        std::cout<<arr[i]<<" ";
}

//�㥪�� ��� ������ ���� � ������ 童��� ���ᨢ�
void swapArr(int arr[], int size)
{
    for(int i = 0; i < size; ++i)
        if(i & 1) std::swap(arr[i], arr[i-1]);
}

//�㭪�� ������ ��� ᨬ����� ������� ॣ��� �� ���孨� � ��ப�
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

//����� 8---------------------------------------------------------------------------------------------------------------------------------------------
#ifdef lab5_8
#include <ctime>

//�㭪�� ��� ������ ������⢠ ��� � �᫥
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

//�㭪�� ����⠭������� ��ப�
void strRecovery(std::string &text)
{
    int i = 0;
    while(text[i]!='\0')        //��ॡ�ࠥ� ������� �� ���� ��ப�
    {
        if(std::isdigit(text[i]))
        {
            std::string number;  //��ப� ��� �࠭���� �᫠ � ���� ��ப�
            int j = i;

            while(std::isdigit(text[j])) //���� ���祭�� �� ������� �᫮, ������塞 ��� � ��ப�
            {
                number+=text[j];
                ++j;
            }

            //�����塞 � �� ����
            text.replace(i, Exponent(stoi(number)), stoi(number)-1, text[i+Exponent(stoi(number))]);
            i+=stoi(number);
        }
        else ++i;
    }
}

//stoi(text) - �㭪�� ��� ����祭�� ������⢠ ᨬ�����
int main()
{
     std::string text{"11AB1C4D"};
     strRecovery(text);
     std::cout<<text;

     return 0;
}
#endif
//---------------------------------------------------------------------------------------------------------------------------------------------------

//����� 9--------------------------------------------------------------------------------------------------------------------------------------------
#ifdef lab5_9

void spaceDelete(std::string &text)
{
    //����塞 �� �஡���� ᨬ���� � ��砫� ��ப�
    while (isspace(text[0]))
        text.erase(0, 1);

    int i = 0;
    //��ॡ�ࠥ� �� �ᥬ ����⠬ �� ���� ��ப�
    while(text[i]!= '\0')
    {
        //�᫨ ᨬ��� ⠡��樨 �����塞 ��� �� �஡����
        if(text[i] == '\t')
            text[i] = ' ';

        //�᫨ 2 ����� ᨬ���� �஡����, 㤠�塞 1 �� ���
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
    std::vector<std::string> input; //����� ��ப ��� �࠭���� ��������� ������
    std::string name;               //����
    int i = 0;

    do
    {
        std::cout << "������ " << i << "-� ��ப� ��� Enter ��� �����襭�� ";
        std::getline(std::cin, name);
        input.push_back(name);
        ++i;
    }

    //���� ��ப� �� �㫥��� � ��� ���� 䠩��
    while(!name.empty() && !std::cin.eof());
    input.pop_back();
    std::sort(input.begin(), input.end());
    auto it = input.begin();

    std::cout<<"�����஢���� ��ப�:\n";
    while (it != input.end())
      {
       std::cout << *it << "\n"; // �뢮��� ���祭�� �����, �� ����� 㪠�뢠�� �����
       ++it; // � ���室�� � ᫥���饬� ������
      }
}

#endif

