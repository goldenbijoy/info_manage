#include <bits/stdc++.h>
using namespace std;

int Registration(int id);
int Search(int id);
int Delete(int id);
int Log_in(int id);
int Edit(int id);
int view_info(int id);

//string first_name,last_name,birthday,join_date,email,gender;
//string adress,designation,password, ID,salary;

template <typename T>
  string NumberToString ( T Number )
  {
     stringstream ss;
     ss << Number;
     return ss.str();
  }


char Home()
{
     system("cls");
     puts("WELCOME TO the Employee management\n\n") ;
     puts("-------------------------------");
     puts("Enter 'R' to Registration       ");
     puts("\nEnter 'S' to Search           ");
     puts("\nEnter 'D' to delete            ");
     puts("\nEnter 'V' to view info       ");
     puts("\nEnter 'E' to Edit info       ");
     puts("\nEnter 'Q' to quit             ");
     printf("\n-------------------------------\n\n");
     char ch;
     cin>>ch;
     return toupper(ch);
}


int main()
{
    char x;
    while(x!='Q'){
        x = Home();
        fstream myfile;
        myfile.open("info.txt");
        int total,i;
        string z;
        getline(myfile,z);
        stringstream ss(z);
        ss>>total;
        ss>>i;
        if(x=='R'){
            total++,i++;
            myfile.close();
            Registration(i);
        }
        else if(x=='S'){
            cout<<"Input id number : ";
            int z; cin>>z;
            Search(z);
        }
        else if(x=='D'){
            cout<<"input id number: ";
            int z;cin>>z;
            z = Delete(z);
            if(z) total--;
        }
        else if(x=='V'){
            cout<<"enter your id: ";
            int z; cin>>z;
            view_info(z);
        }
        else if(x=='E'){
            cout<<"Enter your id: ";
            int z; cin>>z;
            Edit(z);
        }
        ofstream m;
        m.open("info.txt");
        m<<total<<" "<<i;
        m.close();
    }
}

int view_info(int id)
{
    if(Log_in(id)){
        fstream myfile;
        string z = "data/" + NumberToString(id);
        myfile.open(z);
        string line;
        while(getline(myfile,line)){
            cout<<line<<endl;
        }
        myfile.close();
        system("pause");
    }
}

int Edit(int id)
{
   if(Log_in(id)) Registration(id);
}

int Delete(int id)
{
    string z,k;
    k = "data/";
    z = k + NumberToString(id);
    //cout<<z<<endl;
    //ofstream myfile;
    //myfile.open(k);
    int l = Log_in(id);
    if(l==0){
        cout<<"can't delete"<<endl;
        return 0;
    }
    cout<<"id deleted"<<endl;
    system("pause");
    if( (remove(z.c_str()) ==0 ) ) return 1;
    else return 0;

}

int Log_in(int id)
{
    string k,l;
    //NumberToString(id);
    l = "data/";
    k = l + NumberToString(id);
    fstream myfile;
    myfile.open(k);
    int x = 0;
    while(getline(myfile,k)){
        x++;
        if(x==9) break;
    }
    //cout<<k<<endl;
    x = 0;
    while(x<3){
        cout<<"Your id: "<<id<<endl;
        cout<<"enter your password: "<<endl;
        string z;
        cin>>z;
        if(z==k){
            return 1;
        }
        else{
            cout<<"wrong password try again"<<endl;
        }
        x++;
    }
    cout<<"too many attempt!"<<endl;
    system("pause");
    return 0;
}

int Search(int id)
{
    ifstream myfile;
    string k = "data/";
    string z;
    z = k + NumberToString(id);
    myfile.open(z);
    if(myfile.is_open() ){
        cout<<"This id exist"<<endl;
        myfile.close();
    }
    else{
        cout<<"this id not exist"<<endl;
    }
    system("pause");
}

int Registration(int id)
{
    getchar();
    ofstream myfile;
    string z,k;
    k = "data/";
    z = k + NumberToString(id);
    myfile.open(z);
    cout<<"Enter Your first name: ";
    getline(cin,z);
    myfile<<z<<"\n";
    cout<<"Enter Your Last name: ";
    getline(cin,z);
    myfile<<z<<"\n";
    cout<<"Enter Your Birthday: ";
    getline(cin,z);
    myfile<<z<<"\n";
    cout<<"Enter Your Join date: ";
    getline(cin,z);
    myfile<<z<<"\n";
    cout<<"Enter Your Email: ";
    getline(cin,z);
    myfile<<z<<"\n";
    cout<<"Enter Your Gender: ";
    getline(cin,z);
    myfile<<z<<"\n";
    cout<<"Enter Your address: ";
    getline(cin,z);
    myfile<<z<<"\n";
    cout<<"Enter Your Designation: ";
    getline(cin,z);
    myfile<<z<<"\n";
    cout<<"Enter Your Password: ";
    getline(cin,z);
    myfile<<z<<"\n";
    cout<<"Enter salary: ";
    getline(cin,z);
    myfile<<z<<"\n";
    cout<<"Your Id : "<<id<<" Don't forget it "<<endl;
    system("pause");
    //getchar();
    myfile.close();
}
