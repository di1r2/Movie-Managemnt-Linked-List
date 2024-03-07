#include <iostream>
#include <string.h>
using namespace std;
const int n = 40;
int counter = 1;
class movieinformation
{
private:
    struct movie
    {

        char movietitle[n];
        char actors[n];
        char year[n];
        char director[n];
        char moviegenre[n];
        movie *next;
    };
    movie *head;

public:
    movieinformation()
    {
        head = NULL;
    }

    void insertmovieinformationatbeginning();
    void insertmovieinformationatspecificpostion(int n);
    void insertmovieinformationatend();
    void deletemovieinformationfrombeginning();
    void deletemovieinformationfromspecificplace(int);
    void deletemovieinformationfromend();
    void searchmovieinformation(char key[n]);
    void displaymovieinformation();
};
void movieinformation::insertmovieinformationatbeginning()
{
    movie *temp;
    temp = new movie;

    cout << "\n enter movie's title :";
    cin.ignore();
    cin.getline(temp->movietitle, n);
    cout << "\n enter movie's actor :";
    cin.getline(temp->actors, n);
    cout << "\n enter the year movie released :";
    cin.getline(temp->year, n);
    cout << "\n enter movie's director  :";
    cin.getline(temp->director, n);
    cout << "\n enter movie's genre :";
    cin.getline(temp->moviegenre, n);

    if (head == NULL)
    {
        head = temp;
        temp->next = NULL;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}
void movieinformation::insertmovieinformationatspecificpostion(int n)
{
    movie *temp1, *temp2, *temp;
    temp = new movie;
    cout << "\n enter position u want to insert in:";
    cin >> n;

    if (head != NULL)

    {
        temp2 = head;
    }

    for (int i = 1; i < n; i++)
    {
        temp1 = temp2;
        temp2 = temp2->next;
    }
    cin.ignore();
    cout << "\n enter movie's titles:";
    cin.getline(temp->movietitle, n);
    cout << "\n enter movie's actor :";
    cin.getline(temp->actors, n);
    cout << "\n enter the year movie released :";
    cin.getline(temp->year, n);
    cout << "\n enter movie's director  :";
    cin.getline(temp->director, n);
    cout << "\n enter movie's genre :";
    cin.getline(temp->moviegenre, n);

    temp1->next = temp;
    temp->next = temp2;
}
void movieinformation::insertmovieinformationatend()
{
    movie *temp, *temp1;
    temp = new movie;
    cout << "\n enter movie's title :";
    cin.ignore();
    cin.getline(temp->movietitle, n);
    cout << "\n enter movie's actor :";
    cin.getline(temp->actors, n);
    cout << "\n enter the year movie released:";
    cin.getline(temp->year, n);
    cout << "\n enter movie's director  :";
    cin.getline(temp->director, n);
    cout << "\n enter movie's genre :";
    cin.getline(temp->moviegenre, n);
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp1 = head;
        while (temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }
}
void movieinformation::deletemovieinformationfrombeginning()
{
    movie *temp;
    if (head == NULL)
    {
        cout << " \n no data to be deleted";
    }
    else
    {
        temp = head;
        head = head->next;
        delete temp;
        cout << "\n you deleted movie information from beginning";
    }
}
void movieinformation::deletemovieinformationfromspecificplace(int n)
{
    movie *temp, *temp1;
    cout << " \n enter th position you want to delete from:";
    cin >> n;
    temp = head;
    if (temp == NULL)
    {
        cout << " \n There is no any  movie information ";
    }
    else
    {
        for (int i = 1; i < n; i++)
        {
            temp1 = temp;
            temp = temp->next;
        };
        temp1->next = temp->next;
        delete temp;
        cout << "\n you deleted movie information from "
             << " position " << n;
    }
}
void movieinformation::deletemovieinformationfromend()
{
    movie *temp, *temp1;
    temp = head;
    if (temp == NULL)
    {
        cout << " Movie information is empty";
    }
    else if (temp->next == NULL)
    {
        head = NULL;
        delete temp;
        cout << "\n you deleted movie information from end";
    }
    else
    {
        while (temp->next != NULL)
        {
            temp1 = temp;
            temp = temp->next;
        }
        delete temp;
        temp1->next = NULL;
        cout << "\n you deleted movie information from end";
    }
}
void movieinformation::searchmovieinformation(char key[n])
{
    movie *temp;
    temp = head;
    cout << " enter movie title  you need to search:";
    cin.ignore();
    cin.getline(key, n);
    while (temp != NULL)
    {
        if (strcmp(key, temp->movietitle) == 0)
        {
            cout << "movie information with movie title " << key << " is found at node " << counter;
        }
        temp = temp->next;
        counter++;
    }
    if (temp == NULL)
    {
        cout << " no movie information with movie title " << key << " in list";
    }
}
void movieinformation::displaymovieinformation()
{
    movie *temp;
    temp = head;
    if (temp == NULL)
    {
        cout << "\n no any movie information";
    }
    else
    {
        cout << "\t"
             << "NO"
             << "\t"
             << " TITLE"
             << "\t"
             << "ACTOR"
             << "\t"
             << " YEAR"
             << "\t"
             << "DIRECTOR"
             << "\t"
             << "GENRE" << endl;
        do
        {
            cout << "\t" << counter << "\t" << temp->movietitle << "\t" << temp->actors << "\t" << temp->year << "\t" << temp->director << "\t" << temp->moviegenre << endl;
            temp = temp->next;
            counter++;

        } while (temp != NULL);
    }
}

int main()
{
    movieinformation ob;
    char d, s;
    char key[n];
    do
    {
        cout << " \n click 1 to add movie information at beginning:";
        cout << " \n click 2 to add movie information at position you need:";
        cout << " \n click 3 to add movie information at end:";
        cout << " \n click 4 to delete movie information from beginning:";
        cout << " \n click 5 to delete movie information from position u need :";
        cout << " \n click 6 to delete from end :";
        cout << " \n click  7 search movie information by movie title  :";
        cout << " \n click 8 to  display  movie information :";
        cin >> d;
        switch (d)
        {
        case '1':
            ob.insertmovieinformationatbeginning();
            break;
        case '2':

            ob.insertmovieinformationatspecificpostion(n);
            break;
        case '3':
            ob.insertmovieinformationatend();
            break;
        case '4':
            ob.deletemovieinformationfrombeginning();
            break;
        case '5':
            ob.deletemovieinformationfromspecificplace(n);
            break;
        case '6':
            ob.deletemovieinformationfromend();
            break;
        case '7':
            ob.searchmovieinformation(key);
            break;
        case '8':
            ob.displaymovieinformation();
            break;
        default:
            cout << " \n invalid input";
        }

        cout << " \n any key but not 1 to continue:";
        cin >> s;
    } while (s != '1');

    return 0;
}
