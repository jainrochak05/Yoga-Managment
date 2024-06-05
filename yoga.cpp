#include<iostream>
#include<conio.h>
#include<string.h>
#include<string>
#include<cstring>
#include<fstream>
#include<windows.h>
using namespace std;

void playSuccessSound() { 
    // Play success sound
    Beep(1500, 700); 
}

void playErrorSound() {
    // Play error sound
    Beep(500, 700); 
}
void Color(int color)
{
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
class declaration
{   public:
	string id, name, age, address, contact, designation, experience;
	string status;
	declaration ()
	{ status = "Not Paid" ; }
};


class count
{   public:
	int counter;
	count ()
      {counter = 0 ;}
};


class member : public count, public declaration
{   public:
	declaration m[50];
	int mn;
	string back;
	int memberid, status1, status2, fee, memberfee;

	member ()
	{ fee=0; memberid=0; status1=0; status2=0; memberfee=0; }

	void get_data()
	{
        ofstream myfile;
   	    myfile.open("yoga_management.txt",ios::app);

        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tHow many members do you want to add: ";
		cin >> mn;
        myfile << "*********************************************************************************" << endl << endl;
    		myfile << "  Details Of All The Members In The YOGA Classes" << endl << endl;
    	    myfile << "*****************************************************************************" << endl << endl;
            myfile << "ID" << "\t\t\t" << "NAME" << "\t\t\t" << "AGE" << "\t\t\t" << "Contact\n\n";
		for(int i = 0; i < mn; i++)
		{	cout << "\n\n\t\t\t\t\t\t\t\tAlot unique ID to member " << i + 1 << ": ";
			cin.ignore();
			getline(cin, m[memberid].id);
			cout << "\n\n\t\t\t\t\t\t\t\tName                      : ";
			getline(cin, m[memberid].name);
			cout << "\n\n\t\t\t\t\t\t\t\tAge                       : ";
			getline(cin, m[memberid].age);
			cout << "\n\n\t\t\t\t\t\t\t\tAddress                   : ";
			getline(cin, m[memberid].address);
			cout << "\n\n\t\t\t\t\t\t\t\tContact                   : ";
			getline(cin, m[memberid].contact);
			memberid++;
			counter++;
			back:
			cout << endl << endl;
			cout << "\t\t\t\t\t\t\t\tProceed Forward[Y/N]      : ";
			cin >> back;
			if(back == "Y" || back == "y")
			{ 	cout << "\n\n\t\t\t\t\t\t\t\tYou filled all Entries of " << i + 1 << "/" << mn << " member successfully...";
				getch();
				cout << endl;
			}
			else if(back =="N" || back == "n")
				break;

			else
			{   cout << "\n\t\t\t\t\t\t\t\tWrong Input";
				goto back;
			}
            myfile << m[i].id << "\t\t\t" << m[i].name << "\t\t\t" << m[i].age << "\t\t\t" << m[i].contact << endl << endl;

            
		}
	}

	void show_data()
	{
       // ofstream myfile1;
        //myfile1.open("Project2.txt",ios::app);
        string n;
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tEnter the member's UID ";
    	cin >> n;

        if(n == "0")
        {
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tOOPS!!!!"<< endl;
            cout << "\t\t\t\t\t\t\t\t\tNote: No Record To Display  Plz Go Back And Enter Some Entries...";
        }
    	else
    	{   int i;
        	for(i = 0; i < memberid; i++)
        	{
        		status1 = 0;
        	    if(n == m[i].id)
        	    {   status1 = 1;
        	        break;
        	    }
        	}

        		if(status1)

            	{   cout << "\n\n\n\n\n\n\n\n\n\n";
        		    cout << "\t\t\t\t\t\t\t\t**************************************************" << endl << endl;
        		    cout << "\t\t\t\t\t\t\t\tMembers's ID                 :" << m[i].id << endl << endl;
        	    	cout << "\t\t\t\t\t\t\t\tMembers's Name               :" << m[i].name << endl << endl;
        	    	cout << "\t\t\t\t\t\t\t\tMember's Age                 :" << m[i].age << endl << endl;
        	    	cout << "\t\t\t\t\t\t\t\tMember's Address             :" << m[i].address << endl << endl;
        	    	cout << "\t\t\t\t\t\t\t\tMembers's Contact            :" << m[i].contact << endl << endl;
        	    	cout << "\t\t\t\t\t\t\t\t**************************************************" << endl << endl;
        	    	cout << "\t\t\t\t\t\t\t\tPress any key to choose another option...";
        		}
            	else
   		    	{   cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tNo such ID in database" << endl;
        	    	cout << "\t\t\t\t\t\t\t\tPress any key to choose another option...";
            	}
        }
        getch();
	}

	void all_members_data()
   	{
   	    
   	    if(memberid == 0)
      	{
      		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tOOPS!!!!\n";
      		cout << "\t\t\t\t\t\t\tNote: No Record To Display  Plz Go Back And Enter Some Entries...";
    	}
	 	else
		{   cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t**************************************************************************" << endl << endl;
    		cout << "\t\t\t\t\t\t\t\t\t  Details Of All The Members In The YOGA Classes" << endl << endl;
    	    cout << "\t\t\t\t\t\t*********************************************************************************" << endl << endl;
            cout << "\t\t\t\t\t\tID" << "\t\t\t" << "NAME" << "\t\t\t" << "AGE" << "\t\t\t" << "Contact\n\n";

       		for(int i = 0; i < memberid; i++)
       		 cout << "\t\t\t\t\t\t" << m[i].id << "\t\t\t" << m[i].name << "\t\t\t" << m[i].age << "\t\t\t" << m[i].contact << endl << endl;

        	cout << "\t\t\t\t\t\t*********************************************************************************" << endl << endl;
       		cout<<"\n\t\t\t\t\t\tPress any key to choose another option...";
       	}
       	
      
        getch();
    }


   	void total_members()
    {
        int i = counter;
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t**********************************************" << endl << endl;
        cout << "\t\t\t\t\t\t\t\tTotal Members in YOGA Classes: " << i <<"\n\n\t\t\t\t\t\t\t\t********************************************\n\n";
        cout << "\t\t\t\t\t\t\t\tPress any key to choose another option...";
        getch();

    }


    void record_fee()
    {
        string n;
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tEnter the member's ID  to Record Fee> ";
    	cin >> n;
        if(n == "0")
        {
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tOOPS!!!!"<< endl;
            cout << "\t\t\t\t\t\t\tNote: No Record To Display  Plz Go Back And Enter Some Entries...";
        }
    	else
    	{   int i;
        	for(i = 0; i < memberid; i++)
        	{   status2 = 0;
        	    if(n == m[i].id)
        	    {   status2 = 1;
        	        break;
        	    }
        	}

        		if(status2)
            	{   fee++;
        	    	memberfee += 1000;
        	    	m[i].status = "    Paid";
        		    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tFee Paid...";
        		}
            	else
   		    	{
        		    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tNo such ID in database " << endl;
        	    	cout << "\t\t\t\t\t\t\tPress any key to choose another option...";
            	}
        }
        getch();
	}
 
	void show_fee()
	{  	if(memberid == 0)
      	{
      		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tOOPS!!!!" << endl;
      		cout << "\t\t\t\t\t\t\tNote: No Record To Display  Plz Go Back And Enter Some Entries...";
    	}
	 	else
		{
    		cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t***************************************************************************" << endl << endl;
    		cout << "\t\t\t\t\t\t\t\t\tFee Record Of All The Members In The YOGA Classes" << endl << endl;
    	    cout << "\t\t\t\t\t\t**********************************************************************************" << endl << endl;
			cout << "\t\t\t\t\t\tTotal Members: " << counter <<"\n\n\t\t\t\t\t\tMembers that paid fee: " << fee << endl << endl;
			cout << "\t\t\t\t\t\tID" << "\t\t\t" << "NAME" << "\t\t\t" << "Contact" << "\t\t\t" << "Status\n\n";

       		for(int i = 0; i < memberid; i++)
        	 cout << "\t\t\t\t\t\t" << m[i].id << "\t\t\t" << m[i].name << "\t\t\t" << m[i].contact << "\t\t" << m[i].status << endl;

        	cout << "\t\t\t\t\t\t***********************************************************************************" << endl << endl;
       		cout<<"\n\t\t\t\t\t\tPress any key to choose another option...";
       	}
        getch();
	}
};


class trainer : public count , public declaration
{   public:
	declaration t[50];
	int i, en;
	string back;
	int pay, trainerid, status3, status4, trn_pay_given;

	trainer ()
		{ pay = 0; trainerid = 0; status3 = 0; status4 = 0; trn_pay_given = 0 ; }

	void get_data()
	{  
        ofstream myfile;
        myfile.open("yoga_management.txt",ios::app);
         cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tHow many trainers do you want to add: ";
		cin >> en;
        myfile << "***************************************************************************************" << endl << endl;
    	myfile << "Details Of All The Trainers In The YOGA Classes" << endl << endl;
        myfile << "***************************************************************************************" << endl << endl;
		myfile << "ID" << "\t\t\t" << "NAME" << "\t\t\t" << "AGE" << "\t\t\t" << "DESIGNATION\n\n";
		for(i = 0; i < en; i++)
		{	cout << "\n\n\t\t\t\t\t\t\t\tAlot unique ID to trainer " << i + 1 << ": ";
			cin.ignore();
			getline(cin, t[trainerid].id);
			cout << "\n\n\t\t\t\t\t\t\t\tName                       : ";
			getline(cin, t[trainerid].name);
			cout << "\n\n\t\t\t\t\t\t\t\tAge                        : ";
			getline(cin, t[trainerid].age);
		    cout << "\n\n\t\t\t\t\t\t\t\tDesignation                : ";
			getline(cin, t[trainerid].designation);
			cout << "\n\n\t\t\t\t\t\t\t\tExperience                 : ";
			getline(cin, t[trainerid].experience);
			trainerid++;
			counter++;
			cout << endl << endl;
			back1:
			cout << "\t\t\t\t\t\t\t\tProceed Forward[Y/N]       : ";
			cin >> back;

			if(back == "Y" || back == "y")
			{	cout << "\n\n\t\t\t\t\t\t\t\tYou filled all Entries of " << i + 1 << "/" << en << " trainer successfully...";
				getch();
				cout << endl;
			}
			else if(back =="N" || back == "n")
			    break;
			else
			{   cout << "\n\t\t\t\t\t\t\t\tWrong Input" << endl;
				goto back1;
			}

            myfile <<t[i].id <<"\t\t\t" <<t[i].name <<"\t\t\t" <<t[i].age <<"\t\t\t" <<t[i].designation <<endl <<endl;
		}
        myfile.close();
	}

	void show_data()
	{
		int i;string n;
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tEnter the trainer's ID  to display Record: ";
    	cin >> n;
        if(n == "0")
        {
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tOOPS!!!!"<< endl;
            cout << "\t\t\t\t\t\t\t\t\tNote: No Record To Display  Plz Go Back And Enter Some Entries...";
        }

    	else
    	{
        	for(i = 0; i < trainerid; i++)
        	{   status3 = 0;
        	    if(n == t[i].id)
        	    {   status3 = 1;
        	        break;
        	    }
        	}
    	}
        	if(status3)
            {   cout << "\n\n\n\n\n\n\n\n\n\n";
        	    cout << "\t\t\t\t\t\t\t\t*********************************************" << endl << endl;
        	    cout << "\t\t\t\t\t\t\t\t(1) Trainer's ID                 :" << t[i].id << endl << endl;
        	    cout << "\t\t\t\t\t\t\t\t(2) Trainer's Name               :" << t[i].name << endl << endl;
        	    cout << "\t\t\t\t\t\t\t\t(3) Trainer's Age                :" << t[i].age << endl << endl;
        	    cout << "\t\t\t\t\t\t\t\t(4) Trainer's Designation        :" << t[i].designation << endl << endl;
        	    cout << "\t\t\t\t\t\t\t\t(5) Trainer's Experience         :" << t[i].experience << endl << endl;
        	    cout << "\t\t\t\t\t\t\t\t*********************************************" << endl << endl;
        	    cout << "\n\t\t\t\t\t\t\t\tPress any key to choose another option...";
        	}

            else
   		    { cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tNo such ID in database " << endl;
        	  cout << "\t\t\t\t\t\t\t\tPress any key to choose another option...";
            }
        getch();
}

	void all_trainers_data()
   	{   int i;
    
      	if(trainerid == 0)
      	{
      		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tOOPS!!!!" << endl;
      		cout << "\t\t\t\t\t\t\tNote: No Record To Display  Plz Go Back And Enter Some Entries...";
    	}
	 	else
		{   cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t*********************************************************************************" << endl << endl;
    		cout << "\t\t\t\t\t\t\t\t\tDetails Of All The Trainers In The YOGA Classes" << endl << endl;
    	    cout << "\t\t\t\t\t\t*******************************************************************************************" << endl << endl;
    		cout << "\t\t\t\t\t\tID" << "\t\t\t" << "NAME" << "\t\t\t" << "AGE" << "\t\t\t" << "DESIGNATION\n\n";

       		for(i = 0; i < trainerid; i++)
       		 cout <<"\t\t\t\t\t\t" <<t[i].id <<"\t\t\t" <<t[i].name <<"\t\t\t" <<t[i].age <<"\t\t\t" <<t[i].designation <<endl <<endl;

        	cout <<"\t\t\t\t\t\t********************************************************************************************" <<endl <<endl;
       		cout <<"\t\t\t\t\t\tPress any key to choose another option...";
       	}
       	
        getch();
    }

    void total_trainers()
    {
     
        int i = counter;
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t**********************************************" << endl << endl;
        cout << "\t\t\t\t\t\t\t\tTotal Trainers in YOGA Classes: " << i << endl << endl;
        cout << "\t\t\t\t\t\t\t\t**********************************************" << endl << endl;
        cout << "\t\t\t\t\t\t\t\tPress any key to choose another option...";
        getch();
    }

    void record_pay()
    {
        string n;
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tEnter the trainer's ID  to Record payment: ";
    	cin >> n;
        if(n == "0")
        {   cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tOOPS!!!!" << endl;
            cout << "\t\t\t\t\t\t\tNote: No Record To Display  Plz Go Back And Enter Some Entries...";
        }
    	else
    	{   int i;
        	for(i = 0; i < trainerid; i++)
        	{   status4 = 0;
        	    if(n == t[i].id)
        	    {   status4 = 1;
        	        break;
        	    }
        	}

        		if(status4)
            	{   pay++;
        	    	trn_pay_given += 10000;
        	    	t[i].status = "Paid";
        		    system("cls");
        		    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tPay Given...";
        		}
            	else
   		    	{   system("cls");
        		    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tNo such ID in database " << endl;
        	    	cout << "\t\t\t\t\t\t\tPress any key to choose another option...";
            	}
        }
        getch();
	}

	void show_pay()
	{ 	if(trainerid == 0)
      	{   system("cls");
      		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tOOPS!!!!" << endl;
      		cout << "\t\t\t\t\t\t\tNote: No Record To Display  Plz Go Back And Enter Some Entries...";
    	}
	 	else
		{
			cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t*******************************************************************************" << endl << endl;
    		cout << "\t\t\t\t\t\t\t\t\tPay Record Of All The Trainers In The YOGA Classes" << endl << endl;
    	    cout << "\t\t\t\t\t\t*****************************************************************************" << endl << endl;
			cout << "\t\t\t\t\t\tTotal Trainers: " << counter << endl << endl;
			cout << "\t\t\t\t\t\tTrainers that Received Pay:" << pay << endl << endl;
        	cout << "\t\t\t\t\t\tID" << "\t\t\t" << "NAME" << "\t\t\t" << "Designation" << "\t\t\t" << "Status\n\n";

       		for(int i = 0; i < trainerid; i++)
        		cout <<"\t\t\t\t\t\t" <<t[i].id <<"\t\t\t" <<t[i].name <<"\t\t\t" <<t[i].designation <<"\t\t\t" <<t[i].status <<endl;

        	cout << "\t\t\t\t\t\t*****************************************************************************" << endl << endl;
       		cout<<"\n\t\t\t\t\t\tPress any key to choose another option...";
       	}
        getch();
	}
};


class Time_Table
{   private:
		string mon, tue, wed, thurs, fri, satur, sun;
		int chk;
	public:
		Time_Table();

		friend void feedbackmenu(Time_Table tt);
		friend void wronginput(Time_Table tt);
		friend void get_Time_Table(Time_Table tt);
		friend void show_Time_Table(Time_Table tt);
};
    Time_Table::Time_Table()
    {
         chk=0;
    }

	void feedbackmenu(Time_Table tt)
	    {   cout << "\t\t\t\t\t\t\t\t***********************************************" << endl << endl;
			cout << "\t\t\t\t\t\t\t\t(1) Hatha Yoga        \t(2) Vinyasa Flow" << endl << endl;
			cout << "\t\t\t\t\t\t\t\t(3) Restorive Yoga    \t(4) Power Yoga" << endl << endl;
			cout << "\t\t\t\t\t\t\t\t(5) Mindfullness and Meditation\t(6)Yin Yoga " << endl << endl;
            cout << "\t\t\t\t\t\t\t\t(7) OFF day" << endl << endl;
			cout << "\t\t\t\t\t\t\t\t***********************************************" << endl << endl;
			cout << "\t\t\t\t\t\t\t\tEnter your choice: ";
		}

	void wronginput(Time_Table tt)
	    {
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tWrong Input" << endl;
    			cout << "\t\t\t\t\t\t\t\t\tPress any key to choose another option...";
				getch();
		}

	void get_Time_Table(Time_Table tt)
		{   tt.chk++;
			monday:
			cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t\tFor Monday" << endl << endl;
            feedbackmenu(tt);
			cin >>tt.mon;
			if(tt.mon == "1")
				tt.mon = "Hatha Yoga";
	        else if(tt.mon == "2")
				tt.mon = "Vinyasa Flow";
            else if(tt.mon == "3")
				tt.mon = "Restorative Yoga";
		    else if(tt.mon == "4")
				tt.mon = "Power Yoga";
	        else if(tt.mon == "5")
				tt.mon = "Mindfullness and Meditation";
	        else if(tt.mon == "6")
				tt.mon = " Yin Yoga";
            else if(tt.mon == "7")
                tt.mon = "OFF day";
		    else
			{   wronginput(tt);
				goto monday;
			}
			
            tuesday:
			cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t\tFor Tuesday" << endl << endl;
			feedbackmenu(tt);
			cin >>tt.tue;
			if(tt.tue == "1")
				tt.tue = "Hatha Yoga";
		    else if(tt.tue == "2")
				tt.tue = "Vinyasa Flow";
		    else if(tt.tue == "3")
				tt.tue = "Restorative Yoga";
	        else if(tt.tue == "4")
				tt.tue = "Power Yoga";
		    else if(tt.tue == "5")
				tt.tue = "Mindfullness and Meditation";
            else if(tt.tue == "6")
				tt.tue = " Yin Yoga";
            else if(tt.tue == "7")
                tt.tue = "OFF day";
	        else
			{   wronginput(tt);
				goto tuesday;
			}
			wednesday:
			cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t\tFor Wednesday" << endl << endl;
	        feedbackmenu(tt);
			cin >>tt.wed;
			if(tt.wed == "1")
				tt.wed = "Hatha Yoga";
            else if(tt.wed == "2")
				tt.wed = "Vinyasa Flow";
            else if(tt.wed == "3")
				tt.wed = "Restorative Yoga";
            else if(tt.wed == "4")
				tt.wed = "Power Yoga";
            else if(tt.wed == "5")
				tt.wed = "Mindfullness and Meditation";
	        else if(tt.wed == "6")
				tt.wed = " Yin Yoga";
            else if(tt.wed == "7")
                tt.wed = "OFF day";
			else
			{   wronginput(tt);
				goto wednesday;
			}
			thursday:

			cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t\tFor Thursday" << endl << endl;
		    feedbackmenu(tt);
			cin >>tt.thurs;
			if(tt.thurs == "1")
				tt.thurs = "Hatha Yoga";
	        else if(tt.thurs == "2")
				tt.thurs = "Vinyasa Flow";
            else if(tt.thurs == "3")
				tt.thurs = "Restorative Yoga";
            else if(tt.thurs == "4")
				tt.thurs = "Power Yoga";
            else if(tt.thurs == "5")
				tt.thurs = "Mindfullness and Meditation";
            else if(tt.thurs == "6")
				tt.thurs = " Yin Yoga";
            else if(tt.thurs == "7")
                tt.thurs = "OFF day";
	        else
			{   wronginput(tt);
				goto thursday;
			}
            
            friday:

            cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t\tFor Friday" << endl << endl;
		    feedbackmenu(tt);
			cin >>tt.fri;
			if(tt.fri == "1")
				tt.fri = "Hatha Yoga";
	        else if(tt.fri == "2")
				tt.fri = "Vinyasa Flow";
            else if(tt.fri == "3")
				tt.fri = "Restorative Yoga";
            else if(tt.fri == "4")
				tt.fri = "Power Yoga";
            else if(tt.fri == "5")
				tt.fri = "Mindfullness and Meditation";
            else if(tt.fri == "6")
				tt.fri = " Yin Yoga";
            else if(tt.fri == "7")
                tt.fri = "OFF day";
	        else
			{   wronginput(tt);
				goto friday;
			}

			saturday:


			cout << "\t\t\t\t\t\t\t\tFor Saturday" << endl << endl;
		    feedbackmenu(tt);
			cin >>tt.satur;
			if(tt.satur == "1")
				tt.satur = "Hatha Yoga";
            else if(tt.satur == "2")
				tt.satur = "Vinyasa Flow";
            else if(tt.satur == "3")
				tt.satur = "Restorative Yoga";
	        else if(tt.tue == "4")
				tt.satur = "Power Yoga";
            else if(tt.satur == "5")
				tt.satur = "Mindfullness and Meditation";
            else if(tt.satur == "6")
				tt.satur = " Yin Yoga";
            else if(tt.satur == "7")
                tt.satur = "OFF day";
			else
			{   wronginput(tt);
				goto saturday;
			}
			sunday:

			cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t\tFor Sunday" << endl << endl;
            feedbackmenu(tt);
			cin >>tt.sun;
			if(tt.sun == "1")
				tt.sun = "Hatha Yoga";
			else if(tt.sun == "2")
				tt.sun = "Vinyasa Flow";
			else if(tt.sun == "3")
				tt.sun = "Restorative Yoga";
			else if(tt.sun == "4")
             	tt.sun = "Power Yoga";
	    	else if(tt.sun == "5")
				tt.sun = "Mindfullness and Meditation";
			else if(tt.sun == "6")
				tt.sun = " Yin Yoga";
            else if(tt.sun == "7")
                tt.sun = "OFF day";
        	else
			{   wronginput(tt);
				goto sunday;
			}

			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tTime Table has been Resetted...";
			getch();
	  if(tt.chk == 0)
		{
			cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t******************************************" << endl << endl;
			cout << "\t\t\t\t\t\t\t\t\t\tNo record to show" << endl << endl;
			cout << "\t\t\t\t\t\t\t\t********************************************************" << endl << endl;
			cout << "\t\t\t\t\t\t\t\tPress any key to choose another option...";
			getch();
		}
		else
		{
			cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tYOGA Classes Time Table" << endl << endl;
			cout << "\t\t\t\t\t\t\t\t****************************************************" << endl << endl;
			cout << "\t\t\t\t\t\t\t\tMonday           :" << tt.mon << endl << endl;
			cout << "\t\t\t\t\t\t\t\tTuesday          :" << tt.tue << endl << endl;
			cout << "\t\t\t\t\t\t\t\tWednesday        :" << tt.wed << endl << endl;
			cout << "\t\t\t\t\t\t\t\tThursday         :" << tt.thurs << endl << endl;
			cout << "\t\t\t\t\t\t\t\tFriday           :" << tt.fri << endl <<endl;
			cout << "\t\t\t\t\t\t\t\tSaturday         :" << tt.satur << endl << endl;
			cout << "\t\t\t\t\t\t\t\tSunday           :" << tt.sun << endl << endl;
			cout << "\t\t\t\t\t\t\t\t---------------------------------------------" << endl << endl;
			cout << "\t\t\t\t\t\t\t\tPress any key to choose another option...";
			getch();
		}
		ofstream myfile;
		myfile.open("yoga_management.txt",ios::app);
            myfile << "\n\n*****************************************\n\n";
            myfile << "YOGA Classes Time Table" << endl << endl;
			myfile << "*********************************************" << endl << endl;
			myfile << "Monday           :" << tt.mon << endl << endl;
			myfile << "Tuesday          :" << tt.tue << endl << endl;
			myfile << "Wednesday        :" << tt.wed << endl << endl;
			myfile << "Thursday         :" << tt.thurs << endl << endl;
			myfile << "Friday           :" << tt.fri << endl <<endl;
			myfile << "Saturday         :" << tt.satur << endl << endl;
			myfile << "Sunday           :" << tt.sun << endl << endl;
			myfile << "**********************************************" << endl << endl;


	}



void login()
{   string pass , adminid;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\YOGA DATABASE SYSTEM\n";
	cout << "\t\t\t\t\t\t\t\*******************************************\n\n\t\t\t\t\t\t\t\t\tLOGIN\n";
    cout << "\t\t\t\t\t\t\t\*******************************************\n\n\t\t\t\t\t\t\t\t\t Enter the Admin ID: ";
    cin>>adminid;
    if(adminid=="admin123")
	{
        cout << "\t\t\t\t\t\t\t\t\t***************************************\n\n\t\t\t\t\t\t\t\Enter Password: ";

	    cin>>pass;
	    if(pass=="yoga123")
	    {
        	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\  WELCOME!  ";
            playSuccessSound();

   	    }
	    else
	    {
        	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\ttOOPS !! , Wrongs password " << endl;
            playErrorSound();
	    	cout << "\t\t\t\t\t\t\t\t\tPlease Try Again\n\n\t\t\t\t\t\t\t\Press any key to choose another option...";
	    	getch();

        	login();
	    }    
    }
	else
	{
    	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\OOPS !! , No such Admin ID exists. " << endl;
        playErrorSound();
		cout << "\t\t\t\t\t\t\t\t\tPlease Try Again\n\n\t\t\t\t\t\t\t\Press any key to choose another option...";
		getch();

    	login();
	}
}


int main()
{
	system("Color 02"); 
	string ch1, ch2, ch3, ch4, ch5, ch6 ;
    member m1; trainer t1;Time_Table tt;
    ofstream myfile;
    myfile.open("yoga_management.txt", ios::app);
    myfile << "\t\t\t\t\t\t\t\t" << "YOGA DATABASE SYSTEM" << endl << endl;

cout << "\n\n\n\n\n\n\n\n\n";
cout << "\t\t\t*****************************************************************************************\n";
cout << "\t\t\t*                                                                                       *\n";
cout << "\t\t\t*                                           		                                       *\n";
cout << "\t\t\t*                                                                                       *\n";
cout << "\t\t\t*                                       WELCOME TO                                      *\n";
cout << "\t\t\t*                                                                                       *\n";
cout << "\t\t\t*                           THE YOGA CLASSES MANAGEGEMT SYSTEM                          *\n";
cout << "\t\t\t*                                                                                       *\n";
cout << "\t\t\t*                                                                                       *\n";
cout << "\t\t\t*****************************************************************************************\n";
cout << "\n\n\n\n\t\t\t\t\t";
cout << "Press any key to choose another option...";
getch();


    login();


	mainmenu:

    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t   Welcome to the yoga Management System   " << endl << endl;
    cout << "\t\t\t\t\t\t********************************************" << endl << endl;
    cout << "\t\t\t\t\t\t(1) Database" << endl << endl;
    cout << "\t\t\t\t\t\t(2) Time Table" << endl << endl;
    cout << "\t\t\t\t\t\t(3) Exit" << endl << endl;
    cout << "\t\t\t\t\t\t********************************************" << endl << endl;
    cout << "\t\t\t\t\t\tEnter Your Choice:\t\t";
    cin >> ch1;
    cout << endl << endl << endl;

    if(ch1 == "1")
    {	menu:

        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t   Main Menu   " << endl << endl;
        cout << "\t\t\t\t\t\t**********************************************" << endl << endl;
        cout << "\t\t\t\t\t\t(1) Enter into Member's DataBase" << endl << endl;
        cout << "\t\t\t\t\t\t(2) Enter into Trainers's DataBase" << endl << endl;
        cout << "\t\t\t\t\t\t(3) Enter in Monetary Database" << endl << endl;
		cout << "\t\t\t\t\t\t(4) Go Back" << endl << endl;
        cout << "\t\t\t\t\t\t**********************************************" << endl << endl;
        cout << "\t\t\t\t\t\tEnter Your choice:     ";
        cin >> ch2;

        	if(ch2 == "1")
           	{   memberdatabase:

            	cout << "\n\n";
            	cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t Welcome To Members's DataBase " << endl << endl;
            	cout << "\t\t\t\t\t\t***********************************************" << endl << endl;
            	cout << "\t\t\t\t\t\t(1) Add New Member's Information              " << endl << endl;
            	cout << "\t\t\t\t\t\t(2) Display Member's Information              " << endl << endl;
            	cout << "\t\t\t\t\t\t(3) Detail OF ALL The Members In The YOGA Classes      " << endl << endl;
            	cout << "\t\t\t\t\t\t(4) Total Number of Members in YOGA Classes            " << endl << endl;
				cout << "\t\t\t\t\t\t(5) Go Back                                   " << endl << endl;
				cout << "\t\t\t\t\t\t***********************************************" << endl << endl;
            	cout << "\t\t\t\t\t\tEnter your choice:     ";
            	cin >> ch3;

               	if(ch3 == "1")
               	{
              		m1.get_data();
               		goto memberdatabase;
				}
			    else if(ch3 == "2")
               	{
          	        m1.show_data();
			    	cout << "\n";
                	goto memberdatabase;
                }
                else if(ch3 == "3")
                {
                    m1.all_members_data();
                    goto memberdatabase;
				}

                else if(ch3 == "4")
                {   m1.total_members();
                    goto memberdatabase;
                }
                else if(ch3 == "5")
				 	goto menu;

                else
				{   system("cls");
                    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tWrong Input" << endl;
   					cout << "\t\t\t\t\t\t\tPress any key to choose another option...";
					getch();
                    goto memberdatabase;
                }
            }

            else if(ch2 == "2")
            {   trainerdatabase:
               	cout << "\n\n";
               	cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t    Welcome To Trainer's DataBase   " << endl << endl;
               	cout << "\t\t\t\t\t\t**********************************************" << endl << endl;
               	cout << "\t\t\t\t\t\t(1) Add New Trainer's Information             " << endl << endl;
               	cout << "\t\t\t\t\t\t(2) Display Trainer's Information             " << endl << endl;
               	cout << "\t\t\t\t\t\t(3) Detail OF ALL The Trainers In The YOGA Classes     " << endl << endl;
               	cout << "\t\t\t\t\t\t(4) Total Number of Trainers in YOGA Classes           " << endl << endl;
				cout << "\t\t\t\t\t\t(5) Go Back                                   " << endl << endl;
				cout << "\t\t\t\t\t\t**********************************************" << endl << endl;
               	cout << "\t\t\t\t\t\tEnter your choice:     ";
               	cin >> ch4;

               	if(ch4 == "1")
               	{
              		t1.get_data();
               		goto trainerdatabase;
				}
               	else if(ch4 == "2")
               	{
          	        t1.show_data();
			    	cout << "\n";
                	goto trainerdatabase;
                }
                else if(ch4 == "3")
                {
                    t1.all_trainers_data();
                    goto trainerdatabase;
				}
                else if(ch4 == "4")
                {   t1.total_trainers();
                    goto trainerdatabase;
                }
                else if(ch4 == "5")
                   	goto menu;
                else
				{
                    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tWrong Input" << endl;
   					cout << "\t\t\t\t\t\t\tPress any key to choose another option...";
					getch();
                    goto trainerdatabase;
                }
            }

            else if(ch2 == "3")
            {   get_data:

				cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\t    Welcome To Monetary DataBase       "<< endl << endl;
				cout << "\t\t\t\t\t\t********************************************" << endl << endl;
				cout << "\t\t\t\t\t\t(1) Record fee(member database)" << endl << endl;
				cout << "\t\t\t\t\t\t(2) View Recorded Fee(member database)" << endl << endl;
				cout << "\t\t\t\t\t\t(3) View members details(member database)" << endl << endl;
				cout << "\t\t\t\t\t\t********************************************" << endl << endl;
				cout << "\t\t\t\t\t\t(4) Record Payment(trainer database)" << endl << endl;
				cout << "\t\t\t\t\t\t(5) View Recorded Payment(trainer database)" << endl << endl;
				cout << "\t\t\t\t\t\t(6) View trainers details(trainer database)" << endl << endl;
				cout << "\t\t\t\t\t\t********************************************" << endl << endl;
				cout << "\t\t\t\t\t\t(7) Check and Balance(Overview)" << endl << endl;
				cout << "\t\t\t\t\t\t(8) Go back" << endl << endl;
				cout << "\t\t\t\t\t\tEnter your choice:     ";
				cin >> ch5;

				if(ch5 == "1")
				{
					m1.record_fee();
					goto get_data;
				}
		        else if(ch5 == "2")
				{
					m1.show_fee();
					goto get_data;
				}
		        else if(ch5 == "3")
				{
					m1.all_members_data();
					goto get_data;
				}
				else if(ch5 == "4")
				{
					t1.record_pay();
					goto get_data;
				}
				else if(ch5 == "5")
				{
					t1.show_pay();
					goto get_data;
				}
				else if(ch5 == "6")
				{
					t1.all_trainers_data();
					goto get_data;
				}
				else if(ch5 == "7")
				{
					if(m1.memberfee != 0)
					{
						cout << "\n\n\n\n\n\n\t\t\t\t\t\t********************************************" << endl << endl;
						cout << "\t\t\t\t\t\tTotal Members: " << m1.counter << endl << endl;
						cout << "\t\t\t\t\t\tMembers that paid fee: " << m1.fee << endl << endl;
						cout << "\t\t\t\t\t\tTotal Fee Received: " << m1.memberfee << endl << endl;
						cout << "\t\t\t\t\t\tTotal Trainers: " << t1.counter << endl << endl;
						cout << "\t\t\t\t\t\tTrainers that Received Pay:" << t1.pay << endl << endl;
						cout << "\t\t\t\t\t\tTotal Payment Given: " << t1.trn_pay_given << endl << endl;
						int total = m1.memberfee - t1.trn_pay_given;
						cout << "\t\t\t\t\t\tTotal Money Earned: " << total << endl << endl;
						if(total > 0)
						   cout << "\t\t\t\t\t\tWOW!!! You are in Profit!" << endl << endl;
						else
						   cout << "\t\t\t\t\t\tAlas!!! You are in Loss!" << endl << endl;

						cout << "\t\t\t\t\t\t*********************************************" << endl << endl;
						cout << "\t\t\t\t\t\tPress any key to choose another option...";
        				getch();
					}
					else
					{
      					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tOOPS!!!!" << endl;
      					cout << "\t\t\t\t\tNote: No Record To Display plz Go Back And Enter Some Entries...";
      					getch();
					}
					goto get_data;
				}
				else if(ch5 == "8")
				{
					goto menu;
				}

				else
				{
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tWrong Input" << endl;
    				cout << "\t\t\t\t\t\t\tPress any key to choose another option...";
					getch();
					goto get_data;
				}
            	goto menu;
			}
            else if(ch2 == "4")
    		    goto mainmenu;

			else
			{
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tWrong Input" << endl;
    			cout << "\t\t\t\t\t\t\tPress any key to choose another option...";
				getch();
				goto menu;
			}
	}

	else if(ch1 == "2")
    {

	    Time_Table:
        get_Time_Table(tt);
		cout << "\n\n\t\t\t\t\t\t(1) Reset Time Table" << endl << endl;
		cout << "\t\t\t\t\t\t(2) Go back" << endl << endl;
		cout << "\t\t\t\t\t\t***********************************************" << endl << endl;
		cout << "\t\t\t\t\t\tEnter your choice:     ";
		cin >> ch6;
		if(ch6 == "1")
		{   get_Time_Table(tt);
			goto mainmenu;
		}
		else if(ch6 == "2")
			goto mainmenu;
		else
		{
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tWrong Input" << endl;
    		cout << "\t\t\t\t\t\t\tPress any key to choose another option...";
			getch();
			goto Time_Table;
		}
	}

 	else if(ch1 == "3")
 	{
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t****************************************************************************************\n";
	cout<<"\t\t\t*                                           		                                     *\n";
	cout<<"\t\t\t*                             THANK YOU FOR USING OUR                                   *\n";
	cout<<"\t\t\t*                                                                                       *\n";
	cout<<"\t\t\t*                              YOGA Classes DATABASE SYSTEM                             *\n";
	cout<<"\t\t\t*****************************************************************************************\n";
	cout<<"\n\n\n\n\t\t\t";
 	}

else
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tWrong Input" << endl;
    cout << "\t\t\t\t\t\t\tPress any key to choose another option...";
	getch();
    goto mainmenu;
}
return 0;
} 