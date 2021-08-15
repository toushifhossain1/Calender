#include <iostream>
#include <list>
using namespace std;

struct reminder
{
    string rem_name;
    string rem_des;
    int date;
    string month;
};
 
list<reminder>reminderlist;

string months[12]={"January","February","March","April","May","June","July","August","September","October","November","December"}; 
 
int month(int i, int year)
{
    if(i==0 || i==2 || i==4 || i==6 || i==7 || i==9 || i==11)
        return 31;
    else if(i == 1)
    {
        if(year % 4 == 0)
        {
            return 29;
            
        }
        else
            return 28;
    }
    else
        return 30;
}
 
bool print_star(string month, int date)
{
    if(reminderlist.empty() == true)
    {
        return false;
    }
 
    for(list<reminder>::iterator it = reminderlist.begin(); it != reminderlist.end();)
    {
        if(it -> month == month && it -> date == date)
        {
           return true;
        }
    else
        ++it;
    }
    return false;
}

void calender(int year, int **dates, int &no_months)
{
    for(int i = 0; i < no_months; i++)
    {
       dates[i] = new int[month(i, year)];
       
         for(int j = 0; j < month(i, year); j++)
         {
            dates[i][j] = j + 1;
           
         }
    }
 
}
 
void print_calender(int **dates, int starting_point, int year)
{  
    cout<<"----------------------- " << year << " ------------------------";
    string shortdays[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
     for(int i = 0; i < 12; i++)
    {
        int counter = 0;
        if(starting_point == 7)
        {
            starting_point = 0;
            
        }
 
        cout << endl << "---------------------- " << months[i] << " ----------------------" << endl;
 
        for(int m = 0; m < 7; m++)
        {
            cout << shortdays[m] << "\t";
        }
        cout << endl;
 
            for(int j = 0; j < 6; j++)
            {
                    for(int k = 0; k < 7; k++)
                    {
                        if(j == 0 && k < starting_point)
                        {
                            cout << "  \t";
                        }
                        else if(j == 0 && k >= starting_point)
                        {
                            if(print_star(months[i], dates[i][counter]) == true)
                            {
                                cout << "*" << dates[i][counter] << " \t";
                                counter++;
                            }
                            else
                            {
                                cout << dates[i][counter] << "  \t";
                                counter++;
                            }
 
                        }
                        else if(j > 0)
                        {
                            if(month(i, year) > counter)
                            {
                                if(dates[i][j] < 10)
                                {
                                        if(print_star(months[i], dates[i][counter]) == true)
                                        {
                                            cout << "*" << dates[i][counter] << " \t";
                                            counter++;
                                        }
                                        else
                                        {
                                            cout << dates[i][counter] << "  \t";
                                            counter++;
                                        }
                                }
                                else
                                {
                                    if(print_star(months[i], dates[i][counter]) == true)
                                    {
                                        cout << "*" << dates[i][counter] << "\t";
                                        counter++;
                                    }
                                    else
                                    {
                                        cout << dates[i][counter] << " \t";
                                        counter++;
                                    }
 
 
                                }
                                  starting_point = k + 1;
                            }
                            else
                            {
                                break;
                                
                            }
                        }
 
                    }
                    cout << endl;
            }
            cout << endl;
    }
}
 
void add_reminder(int **dates, int starting_point, int year)
{
    cout << "          ADDING A REMINDER       " << endl;
    reminder rem;
    cout << "Reminder Name: ";
    getline(cin, rem.rem_name);
    cout << "Reminder details: ";
    getline(cin, rem.rem_des);
    cout << "Month: ";
    string month;
    getline(cin, month);
    cout << "Date: ";
    cin >> rem.date;
    cin.ignore();
    rem.month = month;
    reminderlist.push_back(rem);
    print_calender(dates, starting_point, year);
 
}
 
void update_reminder(int **dates, int starting_point, int year)
{
    cout << "          UPDATING A REMINDER       ";
    cout <<endl;
    if(reminderlist.empty() == true)
    {
        cout << "No Reminder Found" << endl;
        return;
    }
    
    string s_name, s_month, s_description;
    int s_date;
    cout << "Reminder Name: ";
    getline(cin, s_name);
    cout << "Month: ";
    getline(cin, s_month);
    cout << "Date: ";
    cin >> s_date;
    cin.ignore();
    for (list<reminder>::iterator it = reminderlist.begin() ; it != reminderlist.end(); ++it)
    {
        if(s_name == it -> rem_name)
           {
                      if(s_date == it -> date)
                        {
                            if(s_month == it -> month)
                            {
                                int selection;
                                do
                                    {
                                        cout << "Choose what to update: " << endl;
                                        cout << "1.Reminder Name" << endl;
                                        cout << "2.Reminder Details" << endl;
                                        cout << "3.Reminder Month" << endl;
                                        cout << "4.Reminder Date" << endl;
                                        cout << "0.Exit" << endl;
                                        cout << endl << "Input: ";
                                        
                                        cin >> selection;
                                        cin.ignore();
                                        if(selection == 1)
                                            {
                                                cout << "New Reminder Name: ";
                                                getline(cin, s_name);
                                                it -> rem_name = s_name;
                                            }
                                            else if(selection==2)
                                            {
                                                    cout << "New Reminder Details: ";
                                                    getline(cin, s_description);
                                                    it -> rem_des = s_description;
 
                                            }
                                            else if(selection == 3)
                                            {
                                                cout << "New Month: ";
                                                getline(cin, s_month);
                                                it -> month = s_month;
                                            }
                                            else if(selection==4)
                                            {
                                                    cout << "New Date: ";
                                                    cin >> s_date;
                                                    cin.ignore();
                                                    it -> date = s_date;
                                            }
                                            else if(selection > 4 || selection < 0)
                                            {
                                                cout << "Wrong Input";
                                                
                                            }
 
                                    }while(selection != 0);
                            }
                        }
 
           }
 
    }
    print_calender(dates, starting_point, year);
}
 
void delete_reminder(int **dates, int starting_point, int year)
{
    cout << "     DELETING A REMINDER     " << endl;
    if(reminderlist.empty() == true)
    {
        cout << "No Reminder Found" << endl;
        return;
    }
    string s_name, s_month; int s_date;
    
    
    cout << "Reminder Name: ";
    getline(cin, s_name);
    cout << "Month: ";
    getline(cin, s_month);
    cout << "Date: ";
    cin >> s_date;
    cin.ignore();
 
    for(list<reminder>::iterator it = reminderlist.begin(); it != reminderlist.end(); it++)
    {
        if(s_name == it -> rem_name)
                if(s_month == it -> month)
                    if(s_date == it -> date)
                    {
                        reminderlist.erase(it);
                        break;
                    }
    }
    print_calender(dates, starting_point, year);
}
 
void view_reminder()
{
 
    if(reminderlist.empty() == true)
    {
        cout << "No Reminder Found" << endl;
        return;
    }
 
    string s_month;
    
    cout << endl << "Month: ";
    getline(cin, s_month);
    cout << endl;
    
    for(list<reminder>::iterator it = reminderlist.begin(); it != reminderlist.end(); it++)
    {
        if(s_month == it -> month)
        {
            cout << "Reminder Name: " << it -> rem_name << endl;
            cout << "Reminder Details: " << it -> rem_des << endl;
            cout << "Month: " << it -> month << endl;
            cout << "Date: " << it -> date << endl;
        }
 
        cout << endl;
    }
}

//Zeller’s congruence algorithm to find the day
string satrting_day_find(int year){
    {
    int day=1,  month=1,j; // day and month are stated ase 1 for first day of the year
    

    if(year>=1  && month >=1 && month <=12 && day >=1 && day <=31) // corrects the month & year according to formula
    {
        if (month == 1)
        {
            month = 13;
            year--;
        }
        if (month == 2)
        {
            month = 14;
            year--;
        }
        int q = day;
        int m = month;
        int y = year;

        int m_1= ((26*(m+1))/10);
        int y_1 = (y/4);
        int y_2 = (y/100);
        int y_3 = (y/400);

        int h = (q+(m_1+y+(y_1)+(6*y_2)+(y_3))%7);
        
        switch (h)
        {
        case 0 :
            return("Saturday");
            
        case 1 :
            return("Sunday");
            
        case 2 :
            return("Monday");
            
        case 3 :
            return("Tuesday");
           
        case 4 :
            return("Wednesday");
            
        case 5 :
            return("Thursday");
            
        case 6 :
            return("Friday");
            
        }
    }

    
}
return("Error"); //This is returned if the user have given any invalid input
}

int main()
{
    string days[7]={ "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int year, i = 0; 
    string starting_day;
    cout << "Year: ";
    cin >> year;
    
    starting_day = satrting_day_find(year);

     while(i < 7)
    {
        if(starting_day == days[i])
        {
            break;
        }    
        else
        {
            if(i == 6 && starting_day != days[i])
            {
                cout<<"INVALID INPUT!";
                return 0;
            }
        }
        
        i++;
    }
 
    int starting_point;
     for(int i = 0; i < 7; i++)
    {
        if(starting_day == days[i])
        {
            starting_point = i;
            
        }
    }
 
 
    int no_months = 12;
    int **dates = new int*[no_months];
 
    calender(year, dates, no_months);
    print_calender(dates, starting_point, year);
 
    int selection;
    do
    {
    cout << "-----------------**********------------------" << endl;
    cout << "1.Add Reminder" << endl;
    cout << "2.Update Reminder" << endl;
    cout << "3.Delete a specific reminder" << endl;
    cout << "4.View all the reminders of a specific month" << endl;
    cout << "0.Exit" << endl;
    cout << "Input any of the above numbers to do a function: ";
    cin >> selection;
    cin.ignore();
    
    
    if(selection == 1)
    {
        add_reminder(dates, starting_point, year);
        
    }
    else if(selection == 2)
    {
        update_reminder(dates, starting_point, year);
        
    }
    else if (selection == 3)
    {
        delete_reminder(dates, starting_point, year);
        
    }
    else if(selection == 4)
    {
        view_reminder();
        
    }
    else if(selection == 0)
    {
        return 0;
        
    }
    else if(selection < 0 || selection > 4)
    {
        cout << " Wrong Input! ";
        
    }
    
  } while(selection != 0);
 
 
 
}
