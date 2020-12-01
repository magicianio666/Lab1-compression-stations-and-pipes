#include <QCoreApplication>
#include <iostream>
#include <fstream>

using namespace std;

struct tube
{
  char id[5];
  double dlina;
  double diametr;
  bool inorder;  //in order ->1; out of order ->0
};

struct cs  //compression station
{
  char id[5];
  char name[10];
  int cech_n;  // ammount of cech
  int cech_w;  // ammount of cech working
  double eff;  //effectiveness
};
void printmenu()
{
    cout<<"1. Add tube"<<endl<<"2. Add compression station"<<endl<<"3. See all objects"<<endl<<"4. Update pipe"<<endl<<"5. Update cs"<<endl<<"0. Exit"<<endl;
    cout<<"Type command number"<<endl;
}
tube newtube ()
{
    tube t;
    cout<<"Type pipe id:"<<endl;
    cin>>t.id;
    cout<<"Type pipe length:"<<endl;
    cin>>t.dlina;
    cout<<"Type pipe diameter:"<<endl;
    cin>>t.diametr;
    cout<<"Type pipe condition:"<<endl;
    cin>>t.inorder;
    return t;
}
void printtube(tube t)
{
    cout<<"pipe id:"<<endl;
    cout<<t.id<<endl;
    cout<<"pipe length:"<<endl;
    cout<<t.dlina<<endl;
    cout<<"pipe diameter:"<<endl;
    cout<<t.diametr<<endl;
    cout<<"pipe condition:"<<endl;
    cout<<t.inorder<<endl;
};
void savetube(tube t)
{
    fstream fs;
    fs.open("tube.txt",fstream::out);
    fs<<t.id<<endl<<t.dlina<<endl<<t.diametr<<endl<<t.inorder<<endl;
    fs.close();
}
tube loadtube()
{
    tube t;
    fstream fs;
    fs.open("tube.txt",fstream::in);
    fs>>t.id>>t.dlina>>t.diametr>>t.inorder;
    fs.close();
    return t;
}
tube edittube (tube t)
{
    cout<<"Type pipe id:"<<endl;
    cin>>t.id;
    cout<<"Type pipe length:"<<endl;
    cin>>t.dlina;
    cout<<"Type pipe diameter:"<<endl;
    cin>>t.diametr;
    cout<<"Type pipe condition:"<<endl;
    cin>>t.inorder;
    return t;
}
cs newcs ()
{
    cs c;
    cout<<"Type compression station id:"<<endl;
    cin>>c.id;
    cout<<"Type compression station name:"<<endl;
    cin>>c.name;
    cout<<"Type compression station ammount of cech:"<<endl;
    cin>>c.cech_n;
    cout<<"Type compression station ammount of cech in work:"<<endl;
    cin>>c.cech_w;
    cout<<"Type compression station effectiveness:"<<endl;
    cin>>c.eff;
    return c;
}
void printcs(cs c)
{
    cout<<"id compression station:"<<endl;
    cout<<c.id<<endl;
    cout<<"compression station name:"<<endl;
    cout<<c.name<<endl;
    cout<<"compression station ammount of cech:"<<endl;
    cout<<c.cech_n<<endl;
    cout<<"compression station ammount of cech in work:"<<endl;
    cout<<c.cech_w<<endl;
    cout<<"compression station effectiveness:"<<endl;
    cout<<c.eff<<endl;
}
void savecs(cs c)
{
    fstream fs;
    fs.open("cs.txt",fstream::out);
    fs<<c.id<<endl<<c.name<<endl<<c.cech_n<<endl<<c.cech_w<<endl<<c.eff<<endl;
    fs.close();
}
cs loadcs()
{
    cs c;
    fstream fs;
    fs.open("cs.txt",fstream::in);
    fs>>c.id>>c.name>>c.cech_n>>c.cech_w>>c.eff;
    fs.close();
    return c;
}
cs editcs (cs c)
{
    cout<<"Type compression station id:"<<endl;
    cin>>c.id;
    cout<<"Type compression station name:"<<endl;
    cin>>c.name;
    cout<<"Type compression station ammount of cech:"<<endl;
    cin>>c.cech_n;
    cout<<"Type compression station ammount of cech in work:"<<endl;
    cin>>c.cech_w;
    cout<<"Type compression station effectiveness:"<<endl;
    cin>>c.eff;
    return c;
}

int order=0;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int S,button;//signal
    setlocale(LC_ALL, "Russian");

    cout<<"Hello, this is a program all about tubes and compression stations"<<endl;
    tryStart:
    cout<<"Type 1 to start:";
    cin.clear();
    cin>> button;
    switch(button){
    case 1:
    {
        printmenu();
        tryAgain:
        cout<<"Type your command:";
        cin.clear();
        cin>> S;

        switch(S) {
        case 1:
        {
            tube t=newtube();
            printtube(t);
            savetube(t);
            order=1;
            goto tryAgain;
        }
        break;
        case 2:
        {
            cs c=newcs();
            printcs(c);
            savecs(c);
            goto tryAgain;
        }
        break;
        case 3:
        {
            if (order==1)
            {
                fstream fs;
                tube t=loadtube();
                printtube(t);
                cs c=loadcs();
                printcs(c);
                goto tryAgain;
            }
             else
            {
                cout<<"No information stored"<<endl;
                goto tryAgain;
            }
        }
        break;
        case 4:
        {
            tube t=loadtube();
            printtube(t);
            t=edittube(t);
            printtube(t);
            savetube(t);
            goto tryAgain;
        break;
        }
        case 5:
        {
            cs c=loadcs();
            printcs(c);
            c=editcs(c);
            printcs(c);
            savecs(c);
            goto tryAgain;
        break;
        }
        case 0:
        {
            cout<<"You escaped the program"<<endl;
            goto tryStart;
        break;
        }
        default:
        {
            cout<<"Invalid command number"<<endl;
            goto tryAgain;
        break;
        }
    }
    break;
    }
    default:
    cout<<"Print 1 to start"<<endl;
    goto tryStart;
    break;
}
    return a.exec();
}
