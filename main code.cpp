#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<iomanip>
#include<conio.h>
#include <unistd.h>
using namespace std;
string takePasswdFromUser(char sp = '*');

class Date{
protected:
    int date,month,year;
public:
    friend istream& operator>>(istream &,Date&);
    int getyear();
    friend ostream& operator<<(ostream&,Date&);
    int getmonth(){return month;}
    int getdate(){return date;}
    void setdate(int d,int m,int y){date=d;month=m;year=y;}
};
istream& operator>>(istream &cin,Date &d){
    cin>>d.date;
    cin>>d.month;
    cin>>d.year;
    return cin;
}
ostream& operator<<(ostream&,Date &d){
    cout<<d.date<<"/"<<d.month<<"/"<<d.year;
    return cout;
}
int Date::getyear()
{
    return year;
}
class person{
protected:
    Date dob;        //dob
    string firstname,lastname,mobile_no,email;
    int age;
public:
    void get_person_details();
    string get_fname();
    string get_lname();
    string get_no();
    string get_email();
    int get_age();
    void modln1(string newn1){lastname=newn1;}
    void modph1(string ph1){mobile_no=ph1;}
    void mode1(string newe1){email=newe1;}
};
string person::get_fname()
{
    return firstname;
}
string person::get_lname()
{
    return lastname;
}
string person::get_no()
{
    return mobile_no;
}
string person::get_email()
{
    return email;
}
int person::get_age()
{
    return age;
}
void person::get_person_details(){
    cout<<endl<<"Enter first name               :";
    cin>>firstname;
    cout<<endl<<"Enter last name                :";
    cin>>lastname;
    cout<<endl<<"Enter mobile number            :";
    cin>>mobile_no;
    cout<<endl<<"Enter Email ID                 :";
    cin>>email;
    do
    {
        cout<<endl<<"Enter age                      : ";
        cin>>age;
    }while (age<=0 || age >=120);
    do{
    cout<<endl<<"Enter date of birth(dd/mm/yyyy): ";
    cin>>dob;
    }while(dob.getdate()<=0 || dob.getdate()>31 || dob.getmonth()<=0 || dob.getmonth()>12 || dob.getyear()<=0 || dob.getyear()>=2500);

}

class lawyer:public person{
protected:
    string lawyer_id;
    float lawyer_sal;
public:
    void get_lawyer_details();
    string get_lawyerid();
    float get_lawyer_sal();
};
string lawyer::get_lawyerid()
{
    return lawyer_id;
}
float lawyer::get_lawyer_sal()
{
    return lawyer_sal;
}
void lawyer::get_lawyer_details(){
    get_person_details();
    do{
            cout<<endl<<"Enter salary                   : ";
            cin>>lawyer_sal;
    }while(lawyer_sal<=0);
    cout<<endl<<"Enter lawyer ID                : ";
    cin>>lawyer_id;
}

class judge:public person{
protected:
    int exp;
    string judge_id;
public:
    void get_judge_details();
    string get_judgeid();
    int get_judge_exp();
};
string judge::get_judgeid()
{
    return judge_id;
}
int judge::get_judge_exp()
{
    return exp;
}
void judge::get_judge_details(){
    get_person_details();
    do{
            cout<<endl<<"Enter number of years of experience: ";
            cin>>exp;
    }while(exp<0);
    cout<<endl<<"Enter judge is ID                : "<<judge_id;
    cin>>judge_id;
}

class plaintiff:public person{
protected:
    string p_address;
public:
    lawyer l1;
    void get_plaintiff_details();
    string get_paddress();
    void get_plaintiff_lawyer();
};
string plaintiff::get_paddress()
{
    return p_address;
}
void plaintiff::get_plaintiff_details(){
    get_person_details();
    cout<<endl<<"Enter address                     : ";
    cin>>p_address;
}
void plaintiff::get_plaintiff_lawyer()
{
    l1.get_lawyer_details();
}
class defendant:public person{
protected:
    string d_address;
    bool previous;
public:
    lawyer l2;
    string get_daddress();
    void get_defendant_details();
    void get_defendant_lawyer();
};
string defendant::get_daddress()
{
    return d_address;
}
void defendant::get_defendant_details(){
    get_person_details();
    cout<<endl<<"Enter address                     : ";
    cin>>d_address;
    cout<<endl<<"Does defendant have previous criminal records: ";
    cout<<endl<<"(1 - YES , 0 - NO) : ";
    cin>>previous;
}
void defendant::get_defendant_lawyer()
{
    l2.get_lawyer_details();
}
class cases{
protected:
    Date d3;
    string caseno;
    string status;
    string type;
    string statement;
    plaintiff p1;
    defendant d1;
    judge j1;
    bool hearing;
public:
    void input();
    string get_gettype();
    string get_status();
    string get_caseno();
    void display1();
    int getyear1();
    void display2();
    void modln(string newn){p1.modln1(newn);}
    void modph(string ph){p1.modph1(ph);}
    void mode(string newe){p1.mode1(newe);}
    void modln2(string newn){d1.modln1(newn);}
    void modph2(string ph){d1.modph1(ph);}
    void mode2(string newe){d1.mode1(newe);}
    void setstat(string a){status = a;}
};

fstream file;
cases c1;
int cases::getyear1()
{
    return d3.getyear();
}
void cases::input()
{
    cout<<endl<<"Enter case number                    : ";
    cin>>caseno;
    do
    {
        cout<<endl<<"Enter type of case (Criminal, Family, Corporate) : ";
        cin>>type;
    }while (type!="Criminal" && type!="criminal" && type!="Family" && type!="family"&& type!="Corporate" && type!="corporate");
    cout<<endl<<endl<<"Enter plaintiff details: ";
    p1.get_plaintiff_details();
    cout<<endl<<endl<<"Enter plaintiff lawyer details: ";
    c1.p1.l1.get_lawyer_details();
    cout<<endl<<endl<<"Enter details of defendent";
    d1.get_defendant_details();
    cout<<endl<<endl<<"Enter defendant lawyer details: ";
    c1.d1.l2.get_lawyer_details();
    cout<<endl<<endl<<"Enter details of judge: ";
    j1.get_judge_details();
    cout<<endl<<endl<<"Enter status of the case: ";
    cin>>status;
    if (status=="Completed"||status=="completed")
    {
        do{
        cout<<"Enter date of judgement : ";
        cin>>d3;

        if (d3.getdate()>31 || d3.getdate()<=0 || d3.getmonth()>12 || d3.getmonth()<=0 || d3.getyear()>2022 || d3.getyear()<=0)
        {
            cout<<"Invalid input\n";
        }
        }while (d3.getdate()>31 || d3.getdate()<=0 || d3.getmonth()>12 || d3.getmonth()<=0 || d3.getyear()>2022 || d3.getyear()<=0);
    }

    else
    {
        d3.setdate(0,0,9999);
    }
}
string cases::get_caseno()
{
    return caseno;
}
string cases::get_gettype()
{
    return type;
}
string cases::get_status()
{
    return status;
}
void cases::display2()
{
    cout<<endl<<"Case number:"<<c1.get_caseno();
    cout<<endl<<"Case type:"<<c1.get_gettype();
    cout<<endl<<"----------------------------------------------------------";
    cout<<endl<<endl<<"PLAINTIFF DETAILS";
    cout<<endl<<"Name               :"<<p1.get_fname()<<" "<<p1.get_lname();
    cout<<endl<<"Mobile number      :"<<p1.get_no();
    cout<<endl<<"Email ID           :"<<p1.get_email();
    cout<<endl<<"Age                :"<<p1.get_age();
    cout<<endl<<"----------------------------------------------------------";
    cout<<endl<<endl<<"PLAINTIFF LAWYER DETAILS";
    cout<<endl<<"Name               :"<<c1.p1.l1.get_fname()<<" "<<c1.p1.l1.get_lname();
    cout<<endl<<"Mobile number      :"<<c1.p1.l1.get_no();
    cout<<endl<<"Email ID           :"<<c1.p1.l1.get_email();
    cout<<endl<<"Age                :"<<c1.p1.l1.get_age();
    cout<<endl<<"Lawyer ID          :"<<c1.p1.l1.get_lawyerid();
    cout<<endl<<"Lawyer salary      : "<<c1.p1.l1.get_lawyer_sal();
    cout<<endl<<"----------------------------------------------------------";
    cout<<endl<<endl<<"DEFENDANT DETAILS";
    cout<<endl<<"Name               :"<<d1.get_fname()<<" "<<d1.get_lname();
    cout<<endl<<"Mobile number      :"<<d1.get_no();
    cout<<endl<<"Email ID           :"<<d1.get_email();
    cout<<endl<<"Age                :"<<d1.get_age();
    cout<<endl<<"----------------------------------------------------------";
    cout<<endl<<endl<<"DEFENDANT LAWYER DETAILS";
    cout<<endl<<"Name               :"<<c1.d1.l2.get_fname()<<" "<<c1.d1.l2.get_lname();
    cout<<endl<<"Mobile number      :"<<c1.d1.l2.get_no();
    cout<<endl<<"Email ID           :"<<c1.d1.l2.get_email();
    cout<<endl<<"Age                :"<<c1.d1.l2.get_age();
    cout<<endl<<"Lawyer ID          :"<<c1.d1.l2.get_lawyerid();
    cout<<endl<<"Lawyer salary      : "<<c1.d1.l2.get_lawyer_sal();
    cout<<endl<<"----------------------------------------------------------";
    cout<<endl<<endl<<"JUDGE DETAILS";
    cout<<endl<<"JUDGE ID           :"<<j1.get_judgeid();
    cout<<endl<<"Name               :"<<j1.get_fname()<<" "<<j1.get_lname();
    cout<<endl<<"Mobile number      :"<<j1.get_no();
    cout<<endl<<"Email ID           :"<<j1.get_email();
    cout<<endl<<"Age                :"<<j1.get_age();
    cout<<endl<<"Years of experience:"<<j1.get_judge_exp();
    cout<<endl<<"----------------------------------------------------------";
}


void cases::display1(){
    cout<<setw(20)<<right<<get_caseno();
    cout<<setw(20)<<right<<get_gettype();
    cout<<setw(20)<<right<<p1.get_fname()<<" "<<p1.get_lname();
    cout<<setw(20)<<right<<p1.l1.get_fname()<<" "<<p1.l1.get_lname();//
    cout<<setw(20)<<right<<d1.get_fname()<<" "<<d1.get_lname();
    cout<<setw(20)<<right<<d1.l2.get_fname()<<" "<<d1.l2.get_lname();
    //schedule_hearing();
}
void schedule()
{
    string cno;
    int f=0;
    cout<<"Enter case number : ";
    cin>>cno;
    file.open("courts.bin",ios::binary|ios::in);
    fstream file1;
    file1.open("hearingdate.bin",ios::binary|ios::app);
    file1.close();
    file1.open("hearingdate.bin",ios::binary|ios::in);
    while (file.read((char*)&c1,sizeof(c1)))
    {
        if (c1.get_caseno()==cno)
        {
            f=1;
            string t=c1.get_status();
            if (t=="Completed"||t=="completed")
            {
                cout<<"Case is completed. Can't schedule hearing";
            }

            else
            {
                while(true)
                {
                    int count=0;
                    Date temp1,temp2;;
                    do
                    {
                        cout<<"Enter date to schedule hearing : ";
                        cin>>temp1;
                        if (temp1.getdate()<=0 || temp1.getdate()>31 || temp1.getmonth()<=0 || temp1.getmonth()>12 || temp1.getyear()<2022)
                        {
                            cout<<"Invalid input."<<endl;
                        }
                    }while(temp1.getdate()<=0 || temp1.getdate()>31 || temp1.getmonth()<=0 || temp1.getmonth()>12 || temp1.getyear()<2022);
                    while (file1.read((char*)&temp2,sizeof(temp2)))
                    {
                        int d1,m1,y1,d2,m2,y2;
                        d1=temp1.getdate();
                        d2=temp2.getdate();
                        m1=temp1.getmonth();
                        m2=temp2.getmonth();
                        y1=temp1.getyear();
                        y2=temp2.getyear();
                        if (d1==d2 && m1==m2 && y1==y2)
                        {
                            count++;
                        }

                    }
                    file1.close();

                    if (count<=3)
                    {
                        cout<<"Hearing succesfully scheduled.";
                        file1.open("hearingdate.bin",ios::binary|ios::app);
                        file1.write((char*)&temp1,sizeof(temp1));
                        break;
                    }

                    else
                    {
                        cout<<"Date not possible. Enter another date.\n";
                    }
                }
            }
        }

    }

    if (f==0)
    {
        cout<<"Case number not available.\n";
    }
    file.close();
    file1.close();
}


void add_new_case(){
    file.open("courts.bin",ios::binary|ios::app);
    c1.input();
    file.write((char*)&c1,sizeof(c1));
    file.close();
}

/*void modify()
{
    int ch1;
    fstream file1;

    do
    {
        file.open("courts.bin",ios::binary|ios::in);
        file1.open("temp.bin",ios::binary|ios::out);
        cout<<endl<<"\n\t1. Modify plaintiff details";
        cout<<"\n\t2. Modify defendant details";
        cout<<"\n\t3. Modify status";
        cout<<"\n\t4. Back to main menu";
        cout<<"\nEnter your choice : ";
        cin>>ch1;
        string cno;
        int ch2;
        if (ch1==1)
        {
            int f=0;
            cout<<"Enter case number : ";
            cin>>cno;

            while (file.read((char *)&c1,sizeof(c1)))
            {
                string c2=c1.get_caseno();
                if (c2==cno)
                {
                    f=1;
                }

            }

            if (f==0)
            {
                cout<<endl<<"Case number not found.\n";
                break;
            }
            do
            {
                cout<<endl<<"\n\t1. Modify last name";
                cout<<"\n\t2. Modify phone number";
                cout<<"\n\t3. Modify email";
                cout<<"\n\t4. Back to main menu";
                cout<<"\nEnter your choice : ";
                cin>>ch2;
                if (ch2==1)
                {
                    string n;
                    cout<<"Enter last name : ";
                    cin>>n;
                    while(file.read((char * )&c1,sizeof(c1)))
                    {
                        string c2=c1.get_caseno();
                        if (c2==cno)
                        {
                            c1.modln(n);
                            file1.write((char*)&c1,sizeof(c1));
                            f=1;
                        }
                        else
                        {
                            file1.write((char *)&c1,sizeof(c1));
                        }

                    }
                    if (f==0)
                    {
                        cout<<"Case number not available."<<endl;
                    }
                    else
                    {
                        cout<<"Record modified. Display to check"<<endl;
                    }
                    file.close();
                    file1.close();
                    remove("courts.bin");
                    rename("temp.bin","courts.bin");

                }

                else if (ch2==2)
                {
                    string n;
                    cout<<"Enter phone number : ";
                    cin>>n;
                    while(file.read((char * )&c1,sizeof(c1)))
                    {
                        string c2=c1.get_caseno();
                        if (c2==cno)
                        {
                            c1.modph(n);
                            file1.write((char *)&c1,sizeof(c1));
                            f=1;
                        }
                        else
                        {
                            file1.write((char *)&c1,sizeof(c1));
                        }

                    }
                    if (f==1)
                    {
                        cout<<"Record modified. Display to check"<<endl;
                    }
                    file.close();
                    file1.close();
                    remove("courts.bin");
                    rename("temp.bin","courts.bin");
                }

                else if (ch2==3)
                {
                    string n;
                    cout<<"Enter email id : ";
                    cin>>n;
                    while(file.read((char * )&c1,sizeof(c1)))
                    {
                        string c2=c1.get_caseno();
                        if (c2==cno)
                        {
                            c1.mode(n);
                            file1.write((char *)&c1,sizeof(c1));
                            f=1;
                        }
                        else
                        {
                            file1.write((char *)&c1,sizeof(c1));
                        }

                    }
                    if (f==0)
                    {
                        cout<<"Case number not available."<<endl;
                    }
                    else
                    {
                        cout<<"Record modified. Display to check"<<endl;
                    }
                    file.close();
                    file1.close();
                    remove("courts.bin");
                    rename("temp.bin","courts.bin");
                }
                else if (ch2!=4)
                {
                    cout<<"Invalid choice\n";
                }
            } while (ch2!=4);

        }

        else if (ch1==2)
        {
            int f=0;
            cout<<"Enter case number : ";
            cin>>cno;

            while (file.read((char *)&c1,sizeof(c1)))
            {
                string c2=c1.get_caseno();
                if (c2==cno)
                {
                    f=1;
                }

            }

            if (f==0)
            {
                cout<<endl<<"Case number not found.\n";
                break;
            }
            do
            {
                cout<<endl<<"\n\t1. Modify last name";
                cout<<"\n\t2. Modify phone number";
                cout<<"\n\t3. Modify email";
                cout<<"\n\t4. Back to main menu";
                cout<<"\nEnter your choice : ";
                cin>>ch2;
                if (ch2==1)
                {
                    string n;
                    cout<<"Enter last name : ";
                    cin>>n;
                    while(file.read((char * )&c1,sizeof(c1)))
                    {
                        string c2=c1.get_caseno();
                        if (c2==cno)
                        {
                            c1.modln2(n);
                            file1.write((char *)&c1,sizeof(c1));
                            f=1;
                        }
                        else
                        {
                            file1.write((char *)&c1,sizeof(c1));
                        }

                    }
                    if(f==1)
                    {
                        cout<<"Record modified. Display to check"<<endl;
                    }
                    file.close();
                    file1.close();
                    remove("courts.bin");
                    rename("temp.bin","courts.bin");

                }

                else if (ch2==2)
                {
                    string n;
                    cout<<"Enter phone number : ";
                    cin>>n;
                    while(file.read((char * )&c1,sizeof(c1)))
                    {
                        string c2=c1.get_caseno();
                        if (c2==cno)
                        {
                            c1.modph2(n);
                            file1.write((char *)&c1,sizeof(c1));
                            f=1;
                        }
                        else
                        {
                            file1.write((char *)&c1,sizeof(c1));
                        }

                    }
                    if (f==0)
                    {
                        cout<<"Case number not available."<<endl;
                    }
                    else
                    {
                        cout<<"Record modified. Display to check"<<endl;
                    }
                    file.close();
                    file1.close();
                    remove("courts.bin");
                    rename("temp.bin","courts.bin");
                }

                else if (ch2==3)
                {
                    string n;
                    cout<<"Enter email id : ";
                    cin>>n;
                    while(file.read((char * )&c1,sizeof(c1)))
                    {
                        string c2=c1.get_caseno();
                        if (c2==cno)
                        {
                            c1.mode2(n);
                            file1.write((char *)&c1,sizeof(c1));
                            f=1;
                        }
                        else
                        {
                            file1.write((char *)&c1,sizeof(c1));
                        }

                    }
                    if (f==0)
                    {
                        cout<<"Case number not available."<<endl;
                    }
                    else
                    {
                        cout<<"Record modified. Display to check"<<endl;
                    }
                    file.close();
                    file1.close();
                    remove("courts.bin");
                    rename("temp.bin","courts.bin");
                }
                else if (ch2!=4)
                {
                    cout<<"Invalid choice\n";
                }
            } while (ch2!=4);
        }

        else if (ch1==3)
        {
            int f=0;
            cout<<"Enter case number : ";
            cin>>cno;
            while (file.read((char*)&c1,sizeof(c1)))
            {
                string c2=c1.get_caseno();
                if (c2==cno)
                {
                    f=1;
                    string stat2=c1.get_status();
                    if (stat2=="Pending")
                    {
                        c1.setstat("Ongoing");
                    }

                    else if (stat2=="Completed")
                    {
                        cout<<"Case already completed"<<endl;
                    }

                    else{
                        if (c1.getyear1()==9999)
                        {
                            cout<<"Hearing not yet scheduled";
                        }
                        else{
                            c1.setstat("Completed");
                        }
                    }
                    file1.write((char *)&c1,sizeof(c1));

                }

                else
                {
                    file1.write((char *)&c1,sizeof(c1));
                }
            }

            if(f==1){
                cout<<"Record modified. Display to check"<<endl;
            }
            file.close();
            file1.close();
            remove("courts.bin");
            rename("temp.bin","courts.bin");

        }

        else if (ch1!=4)
        {
            cout<<"Invalid choice.\n";
        }
    }while(ch1!=4);
}*/
void modify()
{
    int ch1;
    fstream file1;

    do
    {
        file.open("courts.bin",ios::binary|ios::in);
        file1.open("temp.bin",ios::binary|ios::app);
        cout<<endl<<"\n\t1. Modify plaintiff details";
        cout<<"\n\t2. Modify defendant details";
        cout<<"\n\t3. Modify status";
        cout<<"\n\t4. Back to main menu";
        cout<<"\nEnter your choice : ";
        cin>>ch1;
        string cno;
        int ch2;
        if (ch1==1)
        {
            int f=0;
            cout<<"Enter case number : ";
            cin>>cno;
            do
            {
                cout<<endl<<"\n\t1. Modify last name";
                cout<<"\n\t2. Modify phone number";
                cout<<"\n\t3. Modify email";
                cout<<"\n\t4. Back to main menu";
                cout<<"\nEnter your choice : ";
                cin>>ch2;
                if (ch2==1)
                {
                    string n;
                    cout<<"Enter last name : ";
                    cin>>n;
                    while(file.read((char * )&c1,sizeof(c1)))
                    {
                        string c2=c1.get_caseno();
                        if (c2==cno)
                        {
                            c1.modln(n);
                            file1.write((char*)&c1,sizeof(c1));
                            f=1;
                        }
                        else
                        {
                            file1.write((char *)&c1,sizeof(c1));
                        }

                    }
                    if (f==0)
                    {
                        cout<<"Case number not available."<<endl;
                    }
                    else
                    {
                        cout<<"Record modified. Display to check"<<endl;
                    }
                    file.close();
                    file1.close();
                    remove("courts.bin");
                    rename("temp.bin","courts.bin");

                }

                else if (ch2==2)
                {
                    string n;
                    cout<<"Enter phone number : ";
                    cin>>n;
                    while(file.read((char * )&c1,sizeof(c1)))
                    {
                        string c2=c1.get_caseno();
                        if (c2==cno)
                        {
                            c1.modph(n);
                            file1.write((char *)&c1,sizeof(c1));
                            f=1;
                        }
                        else
                        {
                            file1.write((char *)&c1,sizeof(c1));
                        }

                    }
                    if (f==0)
                    {
                        cout<<"Case number not available."<<endl;
                    }
                    else
                    {
                        cout<<"Record modified. Display to check"<<endl;
                    }
                    file.close();
                    file1.close();
                    remove("courts.bin");
                    rename("temp.bin","courts.bin");
                }

                else if (ch2==3)
                {
                    string n;
                    cout<<"Enter email id : ";
                    cin>>n;
                    while(file.read((char * )&c1,sizeof(c1)))
                    {
                        string c2=c1.get_caseno();
                        if (c2==cno)
                        {
                            c1.mode(n);
                            file1.write((char *)&c1,sizeof(c1));
                            f=1;
                        }
                        else
                        {
                            file1.write((char *)&c1,sizeof(c1));
                        }

                    }
                    if (f==0)
                    {
                        cout<<"Case number not available."<<endl;
                    }
                    else
                    {
                        cout<<"Record modified. Display to check"<<endl;
                    }
                    file.close();
                    file1.close();
                    remove("courts.bin");
                    rename("temp.bin","courts.bin");
                }
                else if (ch2!=4)
                {
                    cout<<"Invalid choice\n";
                }
            } while (ch2!=4);

        }

        else if (ch1==2)
        {
            int f=0;
            cout<<"Enter case number : ";
            cin>>cno;
            do
            {
                cout<<endl<<"\n\t1. Modify last name";
                cout<<"\n\t2. Modify phone number";
                cout<<"\n\t3. Modify email";
                cout<<"\n\t4. Back to main menu";
                cout<<"\nEnter your choice : ";
                cin>>ch2;
                if (ch2==1)
                {
                    string n;
                    cout<<"Enter last name : ";
                    cin>>n;
                    while(file.read((char * )&c1,sizeof(c1)))
                    {
                        string c2=c1.get_caseno();
                        if (c2==cno)
                        {
                            c1.modln2(n);
                            file1.write((char *)&c1,sizeof(c1));
                            f=1;
                        }
                        else
                        {
                            file1.write((char *)&c1,sizeof(c1));
                        }

                    }
                    if (f==0)
                    {
                        cout<<"Case number not available."<<endl;
                    }
                    else
                    {
                        cout<<"Record modified. Display to check"<<endl;
                    }
                    file.close();
                    file1.close();
                    remove("courts.bin");
                    rename("temp.bin","courts.bin");

                }

                else if (ch2==2)
                {
                    string n;
                    cout<<"Enter phone number : ";
                    cin>>n;
                    while(file.read((char * )&c1,sizeof(c1)))
                    {
                        string c2=c1.get_caseno();
                        if (c2==cno)
                        {
                            c1.modph2(n);
                            file1.write((char *)&c1,sizeof(c1));
                            f=1;
                        }
                        else
                        {
                            file1.write((char *)&c1,sizeof(c1));
                        }

                    }
                    if (f==0)
                    {
                        cout<<"Case number not available."<<endl;
                    }
                    else
                    {
                        cout<<"Record modified. Display to check"<<endl;
                    }
                    file.close();
                    file1.close();
                    remove("courts.bin");
                    rename("temp.bin","courts.bin");
                }

                else if (ch2==3)
                {
                    string n;
                    cout<<"Enter email id : ";
                    cin>>n;
                    while(file.read((char * )&c1,sizeof(c1)))
                    {
                        string c2=c1.get_caseno();
                        if (c2==cno)
                        {
                            c1.mode2(n);
                            file1.write((char *)&c1,sizeof(c1));
                            f=1;
                        }
                        else
                        {
                            file1.write((char *)&c1,sizeof(c1));
                        }

                    }
                    if (f==0)
                    {
                        cout<<"Case number not available."<<endl;
                    }
                    else
                    {
                        cout<<"Record modified. Display to check"<<endl;
                    }
                    file.close();
                    file1.close();
                    remove("courts.bin");
                    rename("temp.bin","courts.bin");
                }
                else if (ch2!=4)
                {
                    cout<<"Invalid choice\n";
                }
            } while (ch2!=4);
        }

        else if (ch1==3)
        {
            int f=0;
            cout<<"Enter case number : ";
            cin>>cno;
            while (file.read((char*)&c1,sizeof(c1)))
            {
                string c2=c1.get_caseno();
                if (c2==cno)
                {
                    f=1;
                    string stat2=c1.get_status();
                    if (stat2=="Pending")
                    {
                        c1.setstat("Ongoing");
                    }

                    else if (stat2=="Completed")
                    {
                        cout<<"Case already completed"<<endl;
                    }

                    else{
                        if (c1.getyear1()==9999)
                        {
                            cout<<"Hearing not yet scheduled";
                        }
                        else{
                            c1.setstat("Completed");
                        }
                    }
                    file1.write((char *)&c1,sizeof(c1));

                }

                else
                {
                    file1.write((char *)&c1,sizeof(c1));
                }
            }

            if (f==0)
            {
                cout<<"Case number not available."<<endl;
            }
            else
            {
                cout<<"Record modified. Display to check"<<endl;
            }
            file.close();
            file1.close();
            remove("courts.bin");
            rename("temp.bin","courts.bin");

        }

        else if (ch1!=4)
        {
            cout<<"Invalid choice.\n";
        }
    }while(ch1!=4);
}
void search_case()
{
    int f=0;
    file.open("courts.bin",ios::binary|ios::in);
    string s_id;
    cout<<endl<<"Enter case number to search: ";
    cin>>s_id;
    while(file.read((char*)&c1,sizeof(c1))){
            string id = c1.get_caseno();
            if(id==s_id){
                f=1;
                cout<<endl<<"Record found";
                c1.display2();
            }
    }
    file.close();
    if(f==0){
        cout<<endl<<"No record found!";
    }
}

void display_all(){
    file.open("courts.bin",ios::binary|ios::in);
    cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
    cout<<endl<<setw(20)<<right<<"CaseNumber"<<setw(20)<<"CaseType"<<setw(30)<<"PlaintiffName"<<setw(30)<<"Plaintiff'sLawyer"<<setw(30)<<"DefendantName"<<setw(30)<<"Defendant'sLawyer";
    cout<<endl<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
    while(file.read((char*)&c1,sizeof(c1))){
        cout<<endl;
        c1.display1();
    }
    file.close();
}

void delete1()
{
    int ch1;
    fstream file1;
    file.open("courts.bin",ios::binary|ios::in);
    file1.open("temp.bin",ios::binary|ios::out);
    do
    {
        cout<<endl<<"\n\t1. Delete by case number";
        cout<<"\n\t2. Delete all old cases";
        cout<<"\n\t3. Back to Main menu";
        cout<<"\nEnter your choice : ";
        cin>>ch1;
        if (ch1==1)
        {
            string cno;
            int f2=0,f1=0;
            cout<<"Enter case number to delete : ";
            cin>>cno;
            while (file.read((char *)&c1,sizeof(c1)))
            {
                string id = c1.get_caseno();
                if (id==cno)
                {
                    f1=1;
                    if (c1.getyear1()<1972 && (c1.get_status()=="Completed"|| c1.get_status()=="completed"))
                    {
                        f2=1;
                    }

                    else
                    {
                        file1.write((char *)&c1,sizeof(c1));
                    }
                }

                else
                {
                    file1.write((char *)&c1,sizeof(c1));
                }

            }

            if (f1==0)
            {
                cout<<endl<<"Case not found."<<endl;
            }
            else if (f1==1 && f2==0)
            {
                cout<<"\nCase too recent to delete."<<endl;
            }
            else
            {
                cout<<"\nRecord deleted. Display to check";
            }

            file.close();
            file1.close();
            remove("courts.bin");
            rename("temp.bin","courts.bin");

        }

        else if (ch1==2)
        {
            int f2=0;
            while (file.read((char *)&c1,sizeof(c1)))
            {
                if (c1.getyear1()<1972 && (c1.get_status()=="Completed" || c1.get_status()=="completed"))
                {
                    f2=1;
                }
                else
                {
                    file1.write((char *)&c1,sizeof(c1));
                }
            }

            if (f2==0)
            {
                cout<<"\nNo old records to delete\n";
            }
            else
            {
                cout<<"Records deleted. Display to check.";
            }

            file.close();
            file1.close();
            remove("courts.bin");
            rename("temp.bin","courts.bin");

        }

        else if (ch1!=3)
        {
            cout<<"\nInvalid input.\n";
        }
    }while (ch1!=3);
}

enum IN {

	// 13 is ASCII for carriage
	// return
	IN_BACK = 8,
	IN_RET = 13

};

// Function that accepts the password
string takePasswdFromUser(char sp)
{
	// Stores the password
	string passwd = "";
	char ch_ipt;

	// Until condition is true
	while (true) {

		ch_ipt = getch();

		// if the ch_ipt
		if (ch_ipt == IN::IN_RET) {
			cout << endl;
			return passwd;
		}
		else if (ch_ipt == IN::IN_BACK
				&& passwd.length() != 0) {
			passwd.pop_back();

			// Cout statement is very
			// important as it will erase
			// previously printed character
			cout << "\b \b";

			continue;
		}

		// Without using this, program
		// will crash as \b can't be
		// print in beginning of line
		else if (ch_ipt == IN::IN_BACK
				&& passwd.length() == 0) {
			continue;
		}

		passwd.push_back(ch_ipt);
		cout << sp;
	}
}


int main()
{
    int ch1;
    int ch,ch2;

    do
    {
            system("cls");
            cout<<endl<<"\t\t----------------------------";
            cout<<endl<<"\t\t  COURT CASE RECORDS";
            cout<<endl<<"\t\t----------------------------";
            cout<<endl<<"\n\t\t 1. Admin";
            cout<<endl<<"\t\t 2. User";
            cout<<endl<<"\t\t 3. Exit";
            cout<<endl<<"\n\t  Enter your choice : ";
            cin>>ch1;
            if (ch1==1)
            {
                string user,pass;
                do
                {
                    sleep(1);
                    system("cls");
                    cout<<endl<<"\t\t-------------------";
                    cout<<endl<<"\t\t      LOGIN";
                    cout<<endl<<"\t\t-------------------";
                    cout<<endl<<"\n\t\t Enter username (0 to exit): ";
                    cin>>user;
                    if (user=="0")
                    {
                        exit(0);
                    }
                    cout<<endl<<"\t\t Enter password : ";
                    pass=takePasswdFromUser();

                    if (user!="admin" || pass!="admin123")
                    {
                        cout<<"\n\n\t\t Invalid input."<<endl;
                    }

                }while(user!="admin" || pass!="admin123");


                do
                {
                    //system("cls");
                    cout<<endl<<"\t\t-------------------";
                    cout<<endl<<"\t\t       ADMIN";
                    cout<<endl<<"\t\t-------------------";
                    cout<<endl<<"\n\t\t1.Add new case";
                    cout<<endl<<"\t\t2.Modify case";
                    cout<<endl<<"\t\t3.Schedule hearing";
                    cout<<endl<<"\t\t4.Search case";
                    cout<<endl<<"\t\t5.Display all cases";
                    cout<<endl<<"\t\t6.Delete case";
                    cout<<endl<<"\t\t7.Exit";
                    cout<<endl<<"\t Enter your choice : ";
                    cin>>ch;
                    if(ch==1)
                    {
                        add_new_case();
                    }
                    else if (ch==2)
                    {
                        modify();
                    }
                    else if(ch==3)
                    {
                        schedule();
                    }
                    else if(ch==4)
                    {
                        search_case();
                    }
                    else if(ch==5)
                    {
                        display_all();
                    }
                    else if(ch==6)
                    {
                        delete1();
                    }
                    else if (ch!=7)
                    {
                        cout<<"Invalid input.\n";
                    }
                }while(ch!=7);
            }

            else if (ch1==2)
            {
                do
                {
                    cout<<endl<<"\t\t-------------------";
                    cout<<endl<<"\t\t       USER";
                    cout<<endl<<"\t\t-------------------";
                    cout<<endl<<"\n\t\t1.Search case";
                    cout<<endl<<"\t\t2.Display all cases";
                    cout<<endl<<"\t\t3.Exit";
                    cout<<endl<<"\t Enter your choice : ";
                    cin>>ch2;
                    if(ch2==1)
                    {
                        search_case();
                    }
                    else if(ch2==2)
                    {
                        display_all();
                    }
                }while(ch2!=3);
            }

            else if (ch1!=3)
            {
                cout<<"Invalid input";
            }
    }while(ch1!=3);
}
