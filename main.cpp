#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
int option,pos,i;
struct contact
{
    string name,number,email,second_number;
    contact *next;
};
contact * head = NULL , * newcontact , * temp;
int len=0,lenSaver=0;
void pause_and_clear()
{
    cout <<endl<<endl;
    system("pause");
    system("cls");
}
int main()
{
    system("color 30");
    /*
        Color codes:
                    0 = Black       8 = Gray
                    1 = Blue        9 = Light Blue
                    2 = Green       A = Light Green
                    3 = Aqua        B = Light Aqua
                    4 = Red         C = Light Red
                    5 = Purple      D = Light Purple
                    6 = Yellow      E = Light Yellow
                    7 = White       F = Bright White
    */
    while(option!=6)
    {
        cout << "\n\n\t\t\t\t\t\t\t\tWelcome" << endl
             << "\n\n\t1.Add (add contacts)"
             << "\n\n\t2.View all (view all contacts)"
             << "\n\n\t3.Remove (remove a contact)"
             << "\n\n\t4.Search (search contacts)"
             << "\n\n\t5.Remove all (remove all contacts)"
             << "\n\n\t6.Exit (close application)"
             << "\n\n\t\tSelect an option: ";
        cin >> option;
        if (option==1)
        {
            newcontact=new contact;
            cout << "\n\n\t\tEnter the name: ";
            cin  >> newcontact->name;
            cout << "\n\n\t\tEnter the primary number: ";
            cin  >> newcontact->number;
            cout << "\n\n\t\tEnter the secondary number: ";
            cin  >> newcontact->second_number;
            cout << "\n\n\t\tEnter the e-mail: ";
            cin  >> newcontact->email;
            if (head == NULL)
            {
                head = newcontact;
                temp = newcontact;
            }
            else
            {
                temp->next=newcontact;
                temp=newcontact;
            }
            cout << "\n\n\t\tContact created.";
            pause_and_clear();
        }
        else if (option==2)
        {
            if(head==NULL)
            {
                cout << "\n\n\t\tContact list is empty.";
            }
            else
            {
                contact * trav = head;
                while(trav!=NULL)
                {
                    cout << "\n\n\t\tIndex: "<<len+1<<endl;
                    cout << "\n\t\tName: "<<trav->name<<endl;
                    cout << "\n\t\tPrimary Number: "<<trav->number<<endl;
                    cout << "\n\t\tSecondary Number: "<<trav->second_number<<endl;
                    cout << "\n\t\tE-mail: "<<trav->email<<endl;
                    trav = trav->next;
                    len++;
                }
                cout << "\n\n\t\t\tTotal contacts in the list: "<<len;
                lenSaver=len;
                len=0;
            }
            pause_and_clear();
        }
        else if (option==3)
        {
            contact*next_contact;
            temp = head;
            if(head == NULL)
            {
                cout<<"\n\n\t\tList is Empty.";
            }
            else
            {
                cout<<"\n\n\t\tEnter the index of the contact which needs to be deleted: ";
                cin>>pos;
                pos--;
                contact * trav = head;
                while(trav!=NULL)
                {
                    trav = trav->next;
                    len++;
                }
                lenSaver=len;
                len=0;
                if (pos > lenSaver)
                {
                    cout<<"\n\n\t\tInvalid Position.";
                }
                else if(pos == 0)
                {
                    temp = head;
                    head = head->next;
                    delete temp;
                    cout<<"\n\n\t\tContact has been deleted.";
                }
                else
                {
                    for (i = 1 ; i<pos ; i++)
                    {
                        temp = temp->next;
                    }
                    next_contact = temp->next;
                    temp->next = next_contact->next;
                    delete next_contact;
                    cout<<"\n\n\t\tContact has been deleted ";
                }
            }
            pause_and_clear();
        }
        else if (option==4)
        {
            contact *search_contact = head;
            string _search_;
            int count=1;
            bool found = false;
            if(head == NULL)
            {
                cout<<"\n\n\t\tList is Empty.";
            }
            else
            {
                cout <<"\n\n\t\tEnter your desired contact you want to search: ";
                cin  >>_search_;
                while (search_contact != NULL)
                {
                    if(_search_ == search_contact->name || _search_ == search_contact->number || _search_ == search_contact->second_number || _search_ == search_contact->email)
                    {
                        cout << "\n\n\t\tIndex: " <<count
                             << "\n\n\t\tName: " << search_contact->name
                             << "\n\n\t\tPrimary Phone number: " << search_contact->number
                             << "\n\n\t\tSecondary Phone number: " << search_contact->second_number
                             << "\n\n\t\tE-mail address: " << search_contact->email;
                        found =true;
                        break;
                    }
                    search_contact = search_contact->next;
                    count++;
                }
                if (found == false)
                {
                    cout<<"\n\n\t\tDesired contact not found."<<endl;
                }
            }
            pause_and_clear();
        }
        else if (option==5)
        {
            if(head == NULL)
            {
                cout<<"\n\n\t\tList is Empty."<<endl;
            }
            else
            {
                while (head != NULL)
                {
                    head = head->next;
                    delete head;
                }
                cout<<"\n\t\tALL contact list has been deleted "<<endl;
            }
            pause_and_clear();
        }
        else if (option==6)
        {
            cout << "\n\n\t\tThank you for using.";
        }
        else
        {
            cout << "\n\n\t\tPlease make a correct selection of 1,2,3,4,5 or 6.";
            pause_and_clear();
        }
    }
    return 0;
}
