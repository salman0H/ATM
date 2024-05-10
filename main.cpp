#include <iostream>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <string>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
//#include <ncurses.h>
using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void back_size()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int orginalwidth = csbi.dwSize.X;
    int orginalheight = csbi.dwSize.Y;

    system("pause");

    COORD bufferSize = {static_cast<SHORT>(orginalwidth), static_cast<SHORT>(orginalheight)};
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), bufferSize);

    system("pause");
}
///------------------------------------------------------------------
void go_to_x_y(int x,int y)
{
    COORD c = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
///------------------------------------------------------------------
void screen()
{
    //back_size();
    char block = 219;
    char top = 177;
    char bottom = 178;
	for(int i=0;i<30;++i)
	{
		if(i==0 || i==29)
		{
		    for(int j=0;j<100;++j)
            {
            cout<<top;
            Sleep(0.8);
            }
		}else{
            for(int j=0;j<=99;++j){
                if(j==0 || j==99)
                {
                    cout<<top;
                    Sleep(2);
                }
                else
                {
                    cout<<" ";
                }
            }
        }
	cout<<endl;
	}
	//system("cls");
}
///------------------------------------------------------------------
void maximizewindow()
{
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd,SW_SHOWMAXIMIZED);
}

///------------------------------------------------------------------
class Address{
    friend istream &operator >>(istream &in,Address &obj);
    friend ostream &operator <<(ostream &out,Address &obj);
public:
    Address();
    Address(string ,long int );
    Address(const Address &);
    void setCity(string );
    void setzipCode(long int );
    void setAddrass(string ,long int );
    string getCity();
    long int getzipCode();
private:
    long int zipCode;
    string City;
};
Address::Address()
{
    City = "IRAN";
    zipCode = 123456;
}
Address::Address(string _City,long int _zipCode)
{
    setCity(_City);
    setzipCode(_zipCode);
}
Address::Address(const Address &obj)
{
    City = obj.City;
    zipCode = obj.zipCode;
}
void Address::setCity(string C)
{
    City = C;
}
void Address::setzipCode(long int zip)
{
    zipCode = zip;
}
void Address::setAddrass(string coun, long int z)
{
    setCity(coun);
    setzipCode(z);
}
string Address::getCity()
{
    return City;
}
long int Address::getzipCode()
{
    return zipCode;
}
istream &operator >>(istream &in,Address &obj)
{
    go_to_x_y(15,11);
    cout << "Enter Your City: ";
    in >> obj.City;
    go_to_x_y(15,12);
    cout << "Enter Your Zip Code: (Must Have 10 Numbers) ";
    in >> obj.zipCode;
    return in;
}
ostream &operator <<(ostream &out,Address &obj)
{
    out << obj.City << " " << obj.zipCode << " " ;
    return out;
}
///------------------------------------------------------------------
class Date {
    friend istream &operator>>(istream &in, Date &obj);
    friend ostream &operator<<(ostream &out, Date &obj);
public:
    Date(const Date &);
    Date(int, int, int);
    Date();
    void setdate(int, int, int);
    int getday();
    int getmonth();
    int getyear();
    bool operator ==(Date );
    bool operator >(Date );
    Date operator =(Date );
private:
    int day;
    int month;
    int year;
    int days_of_month[13] = {0, 30, 30, 30, 30, 30, 30, 31, 31, 31, 31, 31, 31};
};
Date::Date()
{
    day = 0;
    month = 0;
    year = 0;
}
Date::Date(int _d, int _m, int _y) {
    setdate(_d, _m, _y);
}
Date::Date(const Date &obj)
{
    day = obj.day;
    month = obj.month;
    year = obj.year;
}
void Date::setdate(int _day, int _month, int _year)
{
    if (_year > 0) {
            year = _year;
        } else {
            year = 1402;
        }

    if (_month > 0 && _month < 13) {
            month = _month;
        } else {
            month = 1;
        }
    if (_day > 0 && _day <= days_of_month[month]) {
            day = _day;
        } else {
            day = 1;
        }
}
int Date::getday()
{
    return day;
}
int Date::getmonth()
{
    return month;
}
int Date::getyear()
{
    return year;
}
bool Date::operator ==(Date obj)
{
    if(day == obj.day && month == obj.month)
    {
        return true;
    }else{
        return false;
    }
}
bool Date::operator >(Date obj)
{
    if(day > obj.day && month > obj.month)
    {
        return true;
    }else{
        return false;
    }
}
Date Date::operator =(Date obj)
{
    this -> day = obj.day;
    this -> month = obj.month;
    this -> year = obj.year;
    return *this;
}
istream &operator >>(istream &in, Date &obj)
{
    go_to_x_y(15,7);
    cout << "Enter Day: ";
    in >> obj.day;
    go_to_x_y(15,8);
    cout << "Enter Month: ";
    in >> obj.month;
    go_to_x_y(15,9);
    cout << "Enter Year: ";
    in >> obj.year;
    return in;
}
ostream &operator <<(ostream &out, Date &obj)
{
    out << obj.day << '/' << obj.month << '/' << obj.year << endl;
    return out;
}
///------------------------------------------------------------------
class Time {
    //friend istream &operator >>(istream &in,Time &obj);
    friend ostream &operator <<(ostream &out,Time &obj);
private:
    time_t currentTime;

public:
    Time() {
        currentTime = time(0);
    }

    void printCurrentTime() const {
        struct tm* timeinfo = localtime(&currentTime);

        cout << setfill('0') << setw(2);

        cout << setw(2) << timeinfo->tm_hour << ":"
             << setw(2) << timeinfo->tm_min << ":"
             << setw(2) << timeinfo->tm_sec << endl;
        cout << setw(2) << timeinfo->tm_mday << "/"
             << setw(2) << timeinfo->tm_mon + 1 << "/"
             << setw(2) << timeinfo->tm_year + 1900 <<endl;
    }

};
ostream &operator <<(ostream &out,Time &obj)
{
    struct tm* timeinfo = localtime(&obj.currentTime);
    out << setfill('0') << setw(2);
    go_to_x_y(15,8);
    out << "System Time:" << '\t' << '\t'
        << "System Date: " << endl;
    go_to_x_y(15,9);
    out << setw(2) << timeinfo->tm_hour << ":"
        << setw(2) << timeinfo->tm_min << ":"
        << setw(2) << timeinfo->tm_sec;
    go_to_x_y(28,9);
    out << '\t' << '\t'
        << setw(2) << timeinfo->tm_mday << "/"
        << setw(2) << timeinfo->tm_mon + 1 << "/"
        << setw(2) << timeinfo->tm_year + 1900 <<endl;
        return out;

}

///------------------------------------------------------------------
class account
{
    friend void login(account &obj);
    friend istream &operator >>(istream &in,account &obj);
    friend fstream information(account &obj);
public:
    account(long long int a_n,int pass,string f,string l,double b,Date d,Time t,Address lo)
    {
        setaccount_number(a_n);
        setpassword(pass);
        setfirst_name(f);
        setlast_name(l);
        setbalance(b);
        setbithday(d);
        setadd_account(t);
        setlocation(lo);
    }
    account()
    {
        account_number = 12345678;
        password = 1234;
        first_name = "Salman";
        last_name = "Hashemi";
        balance = 0;
        birthday = Date();
        add_account = Time();
        location = Address();
    }
    void setaccount_number(long long int number)
    {
        account_number = number;
    }
    void setpassword(int pass)
    {
        password = pass;
    }
    void setfirst_name(string fname)
    {
        first_name = fname;
    }
    void setlast_name(string lname)
    {
        last_name = lname;
    }
    void setbalance(double value)
    {
        balance = value;
    }
    void setbithday(Date date)
    {
        birthday = date;
    }
    void setadd_account(Time time)
    {
        add_account = time;
    }
    void setlocation(Address address)
    {
        location = address;
    }
    long long int getaccount_number()
    {
        return account_number;
    }
    int getpassword()
    {
        return password;
    }

    bool checkpasswoed(int pass)
    {
        if(pass == password)
        {
            return true;
        }
        return false;
    }
    bool checkaccount_number(long long int identify)
    {
        if(identify == account_number)
        {
            return true;
        }
        return false;
    }
    void Showbalance()
    {
        cout << "Your Balance: " << balance << endl;
    }
    void withdraw(double money) // kam kardan az hesab da sorat vojod vajh
    {
        if(money <= balance)
        {
            balance -= money;
            go_to_x_y(15,7);
            Showbalance();
        }else{
            go_to_x_y(15,7);
            cout << "You don't have Enough balance.";
        }
    }
    void deposit(double money) // variz vajh
    {
        balance += money;
        go_to_x_y(15,7);
        Showbalance();
    }

    void logout();


private:
    long long int account_number;
    int password;
    string first_name;
    string last_name;
    double balance;
    Date birthday;
    Time add_account;
    Address location;
    string comment;
};

istream &operator >>(istream &in,account &obj)
{
    srand(time(0));
    int randomNumber = rand() % 10000;
    long long int randomaccount = rand() % 100000000;
    double coustomer = 0;
    int menu_item = 0, run, x = 6;
	bool running = true;

    go_to_x_y(15,6);
    cout << "your Account Number: " << randomaccount;
    obj.account_number = randomaccount;
    go_to_x_y(15,7);
    cout << "Enter Your First Name: ";
    in >> obj.first_name;
    go_to_x_y(15,8);
    cout << "Enter Your Last Name: ";
    in >> obj.last_name;
    system("cls");
    screen();
    go_to_x_y(15,6);
    cout << "Enter your Birthday: " << endl;
    in >> obj.birthday;
    go_to_x_y(15,10);
    cout << "Enter Your Location You Live: " << endl;
    in >> obj.location;
    system("cls");
    screen();
    go_to_x_y(15,5);
    cout << "your Account Number: " << randomaccount;
    go_to_x_y(15,6);
    cout << "Your Password: " << randomNumber << endl;
    obj.password = randomNumber;
    go_to_x_y(15,7);
    cout << "Time You Create Your Account: " << endl;
    cout << obj.add_account;
    Sleep(2400);
    system("cls");
    screen();

    go_to_x_y(28,6);
    cout << "->";
    while(running)
	{
        go_to_x_y(30,6);
        cout << "1. increase value.";
        go_to_x_y(30,7);
        cout << "2. finish.";

        system("pause>nul");

		if(GetAsyncKeyState(VK_DOWN) && x != 7)
			{
				go_to_x_y(28,x);
				cout << "  ";
				x++;
				go_to_x_y(28,x);
				cout << "->";
				menu_item++;
				continue;

			}

		if(GetAsyncKeyState(VK_UP) && x != 6)
			{
				go_to_x_y(28,x);
				cout << "  ";
				x--;
				go_to_x_y(28,x);
				cout << "->";
				menu_item--;
				continue;
			}

		if(GetAsyncKeyState(VK_RETURN)){
                switch(menu_item)
                {
                    case 0:
                    {
                        system("cls");
                        screen();
                        go_to_x_y(30,6);
                        cout << "Enter Your Money: ";
                        cin >> coustomer;
                        obj.balance += coustomer;
                        break;
                    }
                case 1:
                    {
                        system("cls");
                        screen();
                        go_to_x_y(30,6);
                        cout << "Finish";
                        system("cls");
                        screen();
                        running = false;
                        break;
                    }
                }
		}

		}

    Sleep(700);

    return in;

}
///------------------------------------------------------------------
fstream information(account &obj)
{
    fstream info("information.txt", ios::app);
    info << "Account Number: " << obj.account_number << endl
         << "Name: " << obj.first_name << " " << obj.last_name << '\t'
         << "Balance: " << obj.balance << endl
         << "Birthday: " << obj.birthday
         << obj.add_account
         << "Password: " << obj.password << '\t'
         << "Address: " << obj.location << endl;
    if(obj.comment.length() > 0)
    {
        info << "Your Mention: " << obj.comment << endl;
    }
    info << "---------------------------------------" << endl;
    info.close();
}
///------------------------------------------------------------------
void login(account &obj)
    {
    int coustomer = 0;
    int menu_item = 0, x = 6;
	bool running = true;

	system("cls");
	screen();
    go_to_x_y(13,6);
    cout << "->";
    while(running)
	{
        go_to_x_y(15,6);
        cout << "1. Sing Up";
        go_to_x_y(15,7);
        cout << "2. Login";
        go_to_x_y(15,8);
        cout << "3. Add Comment";
        go_to_x_y(15,9);
        cout << "4. Theme";
        go_to_x_y(15,10);
        cout << "5. Logout";

        system("pause>nul");

		if(GetAsyncKeyState(VK_DOWN) && x != 10)
			{
				go_to_x_y(13,x);
				cout << "  ";
				x++;
				go_to_x_y(13,x);
				cout << "->";
				menu_item++;
				continue;
			}

		if(GetAsyncKeyState(VK_UP) && x != 6)
			{
				go_to_x_y(13,x);
				cout << "  ";
				x--;
				go_to_x_y(13,x);
				cout << "->";
				menu_item--;
				continue;
			}

		if(GetAsyncKeyState(VK_RETURN)){
                switch(menu_item)
                {
                case 0:
                    {
                        system("cls");
                        screen();
                        cin >> obj;
                        break;
                    }
                case 1:
                    {
                        long long int id;
                        double pass;

                        system("cls");
                        screen();
                        go_to_x_y(15,6);
                        cout << "Enter your Account Number: ";
                        cin >> id;
                        go_to_x_y(15,7);
                        cout << "Enter your Password: ";
                        cin >> pass;
                        if(obj.checkaccount_number(id) && obj.checkpasswoed(pass))
                        {
                            bool number = true;
                            while(number)
                            {
                                system("cls");
                                screen();
                                go_to_x_y(15,6);
                                cout << "1. Withdraw";
                                go_to_x_y(15,7);
                                cout << "2. Deposit";
                                go_to_x_y(15,8);
                                cout << "3. Buy Mobile Charge";
                                go_to_x_y(15,9);
                                cout << "4. Show Balance";
                                go_to_x_y(15,10);
                                cout << "5. Account Detail";
                                go_to_x_y(15,11);
                                cout << "6. Change Password";
                                go_to_x_y(15,12);
                                cout << "7. Log out";
                                go_to_x_y(20,13);
                                cin >> coustomer;
                                system("cls");
                                screen();
                                switch(coustomer)
                                {
                                case 1:
                                    {
                                        double value = 0;
                                        go_to_x_y(15,6);
                                        cout << "Enter Money: ";
                                        cin >> value;
                                        obj.withdraw(value);
                                        Sleep(1000);
                                        system("cls");
                                        //number = false;
                                        break;
                                    }
                                case 2:
                                    {
                                        double value = 0;
                                        go_to_x_y(15,6);
                                        cout << "Enter Money: ";
                                        cin >> value;
                                        obj.deposit(value);
                                        Sleep(1000);
                                        system("cls");
                                        //number = false;
                                        break;
                                    }
                                case 3:
                                    {
                                        double value = 0;
                                        go_to_x_y(15,6);
                                        cout << "Enter Charge: ";
                                        cin >> value;
                                        obj.withdraw(value);
                                        Sleep(1000);
                                        system("cls");
                                        //number = false;
                                        break;
                                    }
                                case 4:
                                    {
                                        go_to_x_y(15,6);
                                        obj.Showbalance();
                                        Sleep(700);
                                        //number = false;
                                        break;
                                    }
                                case 5:
                                    {
                                        string detail;
                                        go_to_x_y(13,6);
                                        cout << "Please Enter Write Your Detail: ";
                                        cin >> detail;
                                        if(detail == "account_number")
                                        {
                                            system("cls");
                                            screen();
                                            go_to_x_y(15,6);
                                            cout << "Account Number: " << obj.account_number;
                                            Sleep(4000);
                                            continue;
                                        }else if(detail == "password")
                                        {
                                            system("cls");
                                            screen();
                                            go_to_x_y(15,6);
                                            cout << "Password: " << obj.password;
                                            Sleep(4000);
                                            continue;
                                        }else if(detail == "personal")
                                        {
                                            system("cls");
                                            screen();
                                            go_to_x_y(10,6);
                                            cout << "Personal Information: \n";
                                            go_to_x_y(15,7);
                                            cout << "Address: ";
                                            go_to_x_y(15,8);
                                            cout << obj.location;
                                            go_to_x_y(15,9);
                                            cout << "Time Add Your Account: ";
                                            go_to_x_y(15,10);
                                            cout << obj.add_account;
                                            go_to_x_y(15,11);
                                            cout << "Birthday: " << obj.birthday;
                                            Sleep(4000);
                                            continue;
                                        }else if(detail == "balance")
                                        {
                                            system("cls");
                                            screen();
                                            go_to_x_y(15,6);
                                            obj.Showbalance();
                                            Sleep(4000);
                                            continue;
                                        }else if(detail == "all")
                                        {
                                            system("cls");
                                            screen();
                                            go_to_x_y(10,4);
                                            cout << "Personal Information: \n";
                                            go_to_x_y(15,5);
                                            cout << "Address: \n";
                                            go_to_x_y(15,6);
                                            cout << obj.location;
                                            go_to_x_y(15,7);
                                            cout << "Time Add Your Account: \n";
                                            go_to_x_y(15,8);
                                            cout << obj.add_account;
                                            go_to_x_y(15,9);
                                            cout << "Birthday: ";
                                            go_to_x_y(15,10);
                                            cout << obj.birthday;
                                            go_to_x_y(10,11);
                                            obj.Showbalance();
                                            go_to_x_y(10,12);
                                            cout << "Account Number: " << obj.account_number;
                                            go_to_x_y(10,13);
                                            cout << "Password: " << obj.password;
                                            Sleep(5000);
                                            continue;
                                        }else{
                                            system("cls");
                                            screen();
                                            go_to_x_y(15,6);
                                            cout << "Wrong Input.";
                                            Sleep(1000);
                                            break;
                                        }
                                    }
                                case 6:
                                    {
                                        int change_pass = 0;
                                        int help_pass = 0;
                                        go_to_x_y(10,6);
                                        cout << "Enter your New Password: ";
                                        cin >> change_pass;
                                        if((change_pass % 10000) >= 0 )
                                        {
                                            system("cls");
                                            screen();
                                            for(int i=0;i<4;i++)
                                            {
                                                help_pass += (change_pass / 10);
                                                help_pass *= 10;
                                                change_pass /= 10;
                                            }
                                            obj.setpassword(help_pass);
                                            go_to_x_y(10,6);
                                            cout << "New Password: " << obj.password;
                                            break;
                                        }else{
                                            system("cls");
                                            screen();
                                            go_to_x_y(10,6);
                                            cout << "Wrong Input.";
                                            Sleep(1000);
                                            break;

                                        }
                                    }
                                case 7:
                                    {
                                        number = false;
                                        coustomer = 0;
                                        break;
                                    }
                                }
                            }

                        }else{
                            system("cls");
                            screen();
                            break;
                        }
                    }
                case 2:
                    {
                        system("cls");
                        screen();
                        go_to_x_y(15,6);
                        cout << "1. Comment your Mention";
                        go_to_x_y(15,7);
                        cout << "2. Exit";
                        go_to_x_y(20,8);
                        cin >> coustomer;
                        if(coustomer == 1)
                        {
                            system("cls");
                            screen();
                            string mention;
                            go_to_x_y(15,6);
                            cout << "Write Your Comment: ";
                            cin >> mention;
                            obj.comment = mention;
                            system("cls");
                            break;
                        }else{
                            break;
                        }
                    }
                case 3:
                    {
                            system("cls");
                            screen();
                            go_to_x_y(15,6);
                            cout << "1. white and Black";
                            go_to_x_y(15,7);
                            cout << "2. Aqua and Black";
                            go_to_x_y(15,8);
                            cout << "3. Aqua and Purple";
                            go_to_x_y(15,9);
                            cout << "4. Black and Red";
                            go_to_x_y(15,10);
                            cout << "5. White and Blue";
                            go_to_x_y(15,11);
                            cout << "6. Red and White";
                            go_to_x_y(15,12);
                            cout << "7. Log out";
                            go_to_x_y(20,13);
                            cin >> coustomer;
                            if(coustomer == 1)
                            {
                                system("color 70");
                                system("cls");
                                screen();
                                break;
                            }else if(coustomer == 2)
                            {
                                system("color 30");
                                system("cls");
                                screen();
                                break;
                            }else if(coustomer == 3)
                            {
                                system("color B5");
                                system("cls");
                                screen();
                                break;
                            }else if(coustomer == 4)
                            {
                                system("color 04");
                                system("cls");
                                screen();
                                break;
                            }else if(coustomer == 5)
                            {
                                system("color F1");
                                system("cls");
                                screen();
                                break;
                            }else if(coustomer == 6)
                            {
                                system("color C7");
                                system("cls");
                                screen();
                                break;
                            }else if(coustomer == 7){
                                system("cls");
                                screen();
                                break;
                            }
                    }
                case 4:
                    {
                        system("cls");
                        screen();
                        go_to_x_y(45,6);
                        cout << "Logout";
                        Sleep(500);
                        running = false;
                        break;
                    }
                }
		}

		}
    }
///------------------------------------------------------------------
int main()
{
    maximizewindow();
    //back_size();

    account person;
    login(person);
    information(person);

    go_to_x_y(4,80);
    getch();
    go_to_x_y(4,90);
    return 0;
}
