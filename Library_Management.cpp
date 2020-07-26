#include<iostream>
#include<string.h>
using namespace std;

#define max 50          //maximum size of character array

class lib       //class specifically contains the details of books i.e linked list storing data of books
{
public:
    char bookname[max];
    char author[max];
    double price,quantity;

public:
    lib *headerbook;            //header pointer of linked list containing data of Books
    lib *next;
    lib()                       //Constructor to initialize the object
    {
        headerbook = NULL;
        bookname[0] = '\0';
        author[0] = '\0';
        price = 0.0;
        quantity = 0;
    }

    void get()
    {
        cout<<"\nEnter name of the book                  :";           //book name
        cin>>bookname;
        cout<<"\nEnter author of the book                :";         //author name
        cin>>author;
        cout<<"\nEnter price of the book                 :";          //price of book
        cin>>price;
        cout<<"\nEnter quantity of the book in stock     :";  //Quantities of books in stock
        cin>>quantity;
    }

    void create()
    {
        int p;
        do
        {
            lib *nn;                            /*linked list consists of nodes which hold the data
                                                as mentioned in above get  Function*/
            nn = new lib;
            nn->get();
            nn->next = NULL;
            if (headerbook == NULL)             //insertion of node for first time
            {
                headerbook = nn;
            }

            else                                //insertion of nodes one after the other if linked list is already formed
            {
                lib *cn;
                cn = headerbook;
                while(cn->next!=NULL)
                {
                    cn = cn->next;
                }
                cn->next = nn;
            }
            cout<<"\nDo you want to continue?Press 1         :";// ask for continue i.e inserting node again.....
            cin>>p;
        }
        while(p==1);
    }
};

class student:public lib                //publicly inheritance of lib class to get data of books
//Specific class designated to store the student data which is present
//in each node of linked list
{
public:
    int d,m,y,fine;
    char stdname[max],New;
    double lib_id,no_books;
    char issuebookname[max];

public:
    student *headerstd,*next;           //headerstd i.e.header pointer to student linked list
    student()
    {
        //constructor to initialize the data members
        stdname[0] = '\0';
        lib_id = 0;
        no_books = 0;
        issuebookname[0] = '\0';
        headerstd = NULL;
        fine=0;
    }


    void getstd()                           //Function to get student data i.e his name and library ID
    {
        cout<<"\nEnter your name                         :";
        cin>>stdname;
        cout<<"\nEnter you library id                    :";
        cin>>lib_id;
    }
    void display()
    {
        //Displaying all details related to library and student
        cout<<"\nName                                      :"<<stdname<<endl;
        cout<<"\nLibrary Id                               :"<<lib_id<<endl;
        cout<<"\nNumber of books                   :"<<no_books<<endl;
        cout<<"\nIssued Book name                  :"<<issuebookname<<endl;
        cout<<"\nDues                                       :"<<fine<<endl;
    }
    void createstd()
    {
        //createstd() specifically helps to create the linked list
        //of students
        student *nn;
        nn = new student;
        nn->getstd();
        nn->no_books = 0;
        nn->next = NULL;
        if (headerstd == NULL)
        {
            headerstd = nn;
        }

        else
        {
            student *cn;
            cn = headerstd;
            while(cn->next!=NULL)
            {
                cn = cn->next;
            }
            cn->next = nn;
        }

    }
    void bookreturn()                   //manage the data related to returning of book
    {
        int dd,mm,yy;
        char tempbook[max];
        double tempid;
        int flag=0;                       //if book is present in library or not
        cout<<"\n Enter Book Name to be Returned           :";
       //asking the student about all the information about returning the book
        cin>>tempbook;
        cout<<"\nEnter Your Id number                      :";
        cin>>tempid;
        cout<<"\nEnter Today's date as: dd:mm:yyyy         :";
        cin>>dd>>mm>>yy;

        lib *t,*temp;
        t = headerbook;
        while(t!=NULL)   {
            flag=0;
            if(strcmp(tempbook,t->bookname) == 0)//check whether book is of library or not
            {
                temp = t;
                flag = 1;                   //if found then used the concept of Flag
                break;
            }
            t = t->next;
        }
        int fine1 = 0;
        int sd = 0,sm = 0,sy = 0;
        int flag2;
        student *s;
        s = headerstd;
        //s->display();
        if(flag == 1)               //if book belongs to library
        {
            while(s!=NULL)
            {
                flag2 = 0;
                if(tempid == s->lib_id  /*tempbook == s->issuebookname*/)//if person found
                    //checking the id of person
                {
                    t->quantity = t->quantity + 1;                   //increasing the quantity in stock
                    sd = (dd-(s->d));
                    sm = (mm-(s->m));
                    sy = (yy-(s->y));
                    cout<<sd<<"  "<<sm<<"  "<<sy;
                    fine1 = (sd + 30*sm + 365*sy);                  //Calculating the Fine
                
       //Fine imposed only if amount is greater than ten
                    if(fine1>10)
                    {
                        s->fine = fine1;
                    }
                    else
                    {
                        s->fine = 0;
                    }

                    flag2 = 1;
                    s->no_books = 0;
                    cout<<"Book Returned which was registered on you name.\n";
        /*if All data is encountered correct and fine is paid then Book is taken back is library */
                    cout<<"--------------------------------------------------------------------------------------\n";
                    cout<<"\t\tDetails\n\n";
                    cout<<"--------------------------------------------------------------------------------------\n";
                    s->display();
                    cout<<"--------------------------------------------------------------------------------------\n";//Now no book on persons name

                    break;
                }
                s = s->next;
            }
        }
        if(flag == 0)          //if book does not belong to library
        {
            cout<<"\nThis book does not belong to this library.\n";
        }
        if((flag2 == 0) && (flag==1))
        {
            cout<<"\nThe issued and returned book is different.\n";//if person is returning different book
        }
    }

    void bookissue()
    {
        char tempbook[max];
        double tempid;
        int flag=0;                       //if book is present in library or not
        cout<<"\n Enter Book Name to be Issued            :";
        cin>>tempbook;
        cout<<"\nEnter Your Id number                     :";
        cin>>tempid;

        lib *t,*temp;
        t = headerbook;
        while(t!=NULL)
        {
            flag=0;
            if(strcmp(tempbook,t->bookname) == 0 && t->quantity!=0)//Checking the asked book is present or not
            {
                temp = t;
                flag = 1;           //if found in library then loop is break
                break;
            }
            t = t->next;
        }

        int flag2;
        student *s;
        s = headerstd;
        //s->display();
        if(flag == 1)               //if book found in library then proceeding further
        {
            while(s!=NULL)
            {
                flag2 = 0;
                if(tempid == s->lib_id && s->no_books == 0)//if person found and book on his name
                {

                    flag2 = 1;
                    t->quantity = t->quantity - 1;//decreasing the quantity of Book inStock
                    strcpy(s->issuebookname,tempbook);
                    s->no_books = 1;
                    cout<<"\nEnter the issue date id                  :";//Asking About Issue Date
                    cin>>s->d>>s->m>>s->y;
                    cout<<"Book Found!!!!!!!!!!!\nIt is now Registered on your name.\n";//Book is registered on person's name
                    cout<<"----------------------------------------------------------------------------------\n";
                    cout<<"\t\t\tDetails\n\n";
                    cout<<"----------------------------------------------------------------------------------\n";
                    s->display();
                    cout<<"----------------------------------------------------------------------------------\n";//displaying persons details

                    break;
                }
                s = s->next;
            }
        }
        if(flag == 0)
        {
            cout<<"\nBook is Unavailable\n";            //if book is not in stock
        }
        if((flag2 == 0) && (flag==1))                      //if person is trying to issue more than one books
        {
            cout<<"\nYou have reached maximum book issue limit\n";
        }
    }
};

int main()
{
    int p1,switchvar;
    student s1;
    cout<<"----------------------------------------------------------------------------------- \n";
    cout<<"                     Pimpri Chinchwad College of Engineering                        \n";
    cout<<"                                PCCOE LIBRARY                                       \n";
    cout<<"-----------------------------------------------------------------------------------\n";
    cout<<"                              Applications Starts                                   \n";
    do
    {

        cout<<"--------------------------------------------------------------------------------------\n";
        cout<<"1.Add Book Details.\n2.Add Person Details\n3.Issue Book.\n4.Return Book.\n";
        cout<<"--------------------------------------------------------------------------------------\n";
        cout<<” ENTER YOUR CHOICE NUMBER\n”;
       cin>>switchvar;

        switch(switchvar)
        {
        case 1:
            s1.create();
            break;//to create the linked list having data of books

        case 2:
            s1.createstd();
            break;//to create the linked list having data of Students

        case 3:
            s1.bookissue();
            break;//Students wants to Issue the book

        case 4:
            s1.bookreturn();
            break;//Students wants to return book
        }
        cout<<"\nDo you want to continue to main menu?Press 1\n";
        cin>>p1;
    }
    while(p1==1);
}
