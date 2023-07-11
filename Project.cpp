#include <iostream>
using namespace std;

struct node
{
    string name;
    int roll;
    int atten;
    int UT;
    int Prelims;
    bool achive;
    int MockP;
    int TotalInternal;
    node *next;
};

class List
{
    node *head;

public:
    List()
    {
        head = NULL;
    };

    void insert(string name, int roll, int atten, int UT, int Prelims, bool achive, int MockP)
    {
        if (head == NULL)
        {
            head = new node;
            head->name = name;
            head->roll = roll;
            head->atten = atten;
            head->UT = UT;
            head->Prelims = Prelims;
            head->achive = achive;
            head->MockP = MockP;
            head->TotalInternal = TotalCalculation(atten, UT, Prelims, achive, MockP);
            head->next = NULL;
        }
        else
        {
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            };
            node *NEW = new node;
            NEW->name = name;
            NEW->name = name;
            NEW->roll = roll;
            NEW->atten = atten;
            NEW->UT = UT;
            NEW->Prelims = Prelims;
            NEW->achive = achive;
            NEW->MockP = MockP;
            NEW->TotalInternal = TotalCalculation(atten, UT, Prelims, achive, MockP);
            NEW->next = NULL;
            temp->next = NEW;
        }
    }

    int TotalCalculation(int atten, int UT, int Prelims, bool achive, int MockP)
    {
        int Fatten = (atten * 20) / 100;
        int FUT = (UT * 20) / 100;
        int FPrelims = (Prelims * 30) / 100;
        int FMockP = (MockP * 30) / 100;
        int total = Fatten + FUT + FPrelims + FMockP;
        // Achivements are considered as extra. If there is any achivement
        // then extra 5 marks will be added in total internal marks

        // if achivemets and tota marks not 100 then give marks of attendance
        if (achive && (total < 100))
        {
            int a = 100 - total;
            if (a <= 95)
            {
                total = total + 5;
            }
            else
            {
                total = total + a;
            }
        }

        return total;
    }

    void display()
    {
        node *temp2 = head;
        cout << endl;
        cout << "Roll"
             << " | "
             << "Name"
             << " | "
             << "Attend"
             << " | "
             << "UT"
             << " | "
             << "Prelims"
             << " | "
             << "MockP"
             << " | "
             << "TotalInternal";
        cout << endl;
        cout << "-------------------------------------------------";
        cout << endl;
        while (temp2 != NULL)
        {

            cout << "  " << temp2->roll << " | " << temp2->name << " | " << temp2->atten << " | " << temp2->UT << " | " << temp2->Prelims << " | " << temp2->MockP << " | " << temp2->TotalInternal;
            cout << endl;
            temp2 = temp2->next;
        }
    }

    void dispalySpecific(int roll)
    {
        node *temp3 = head;
        int c = 0;
        while (temp3->roll != roll)
        {
            if (temp3->next == NULL)
            {
                cout << "Roll number does not exist !!!";
                c += 1;
                break;
            }
            else
            {
                temp3 = temp3->next;
            }
        }
        if (c == 0)
        {
            cout << endl;
            cout << " Roll : " << temp3->roll << " | Name : " << temp3->name << " | Attendance : " << temp3->atten << " | Unit Test : " << temp3->UT << " | Prelims : " << temp3->Prelims << " | Mock Practical : " << temp3->MockP << " | Total : " << temp3->TotalInternal;
        };
    }

    void Entries()
    {
        node *temp4 = head;
        int count = 0;
        while (temp4 != NULL)
        {
            count++;
            temp4 = temp4->next;
        }

        cout << "Number of ENTRIES : " << count;
    }
};

int main()
{

    int ch;
    char d;
    string name;
    int roll;
    int atten;
    int UT;
    int Prelims;
    bool achive;
    int MockP;
    List obj;
    do
    {
        cout << endl
             << endl;
        cout << "\t------------------MENU-------------------";
        cout << "\n\tEnter 1 : To Enter New Stundent Data";
        cout << "\n\tEnter 2 : To display all data ";
        cout << "\n\tEnter 3 : To display data of particular student ";
        cout << "\n\tEnter 4 : For total entries ";
        cout << "\n\tEnter 5 : To exit ";
        cout << "\nEnter your choice : ";
        cin >> ch;

        if (ch == 1)
        {
            cout << endl;
            cout << "Enter the Name ----- : ";
            cin >> name;
            cout << "Enter Roll NO. ----- : ";
            cin >> roll;
            cout << "Enter Attendance --- : ";
            cin >> atten;
            cout << "Enter Unit Test ---- : ";
            cin >> UT;
            cout << "Enter Prelims ------ : ";
            cin >> Prelims;
            cout << "Enter Mock Practical : ";
            cin >> MockP;
            cout << "Is Achivement   (y/n): ";
            cin >> d;
            if (d == 'y')
            {
                achive = true;
            }
            else
            {
                achive = false;
            }
            obj.insert(name, roll, atten, UT, Prelims, achive, MockP);
        }
        else if (ch == 2)
        {
            obj.display();
        }
        else if (ch == 3)
        {
            cout << "Enter roll number : ";
            cin >> roll;
            obj.dispalySpecific(roll);
        }
        else
        {
            obj.Entries();
        }
    } while (ch != 5);

    return 0;
}