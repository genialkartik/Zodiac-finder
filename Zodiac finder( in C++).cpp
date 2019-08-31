#include<iostream>
#include<string.h>
#include<stdio.h>
#include<fstream>
using namespace std;
class info
{
public:
    string name;
    int year;
    int month;
    int date;

    void data()
    {	ofstream fout;
        //start name
        cout<<"Enter your name\t\t";
        cin>>name;
        //start year born
        cout<<"Enter the Date:"<<endl;
cin>>date;
cout<<"Enter the Month:"<<endl;
cin>>month;
cout<<"Enter year born\t\t\n\n\n";
cin>>year;
cout<<name<<endl;
cout<<endl<<"Your date of birth is: "<<date<<"/"<<month<<"/"<<year<<endl;
  
    }
    void rec(){
		cout<<name<<endl;
		cout<<"DOB: "<<date<<"/"<<month<<"/"<<year<<endl;
	}
};
class western_zodiac:public info
{
public:

int western() {
	info::data();
	ofstream fout;

if ((date>=20 && date<31 && month==1)||(date<=18 && date>=1 && month==2))
{fout<<"and \nYour Zodiac Sign is AQUARIUS.."<<endl;
cout<<"and \nYour Zodiac Sign is AQUARIUS.."<<endl;
}
else if ((date>=19 && date<31 && month==2)||(date<=20 && date>=1 && month==3))
{fout<<"Your Zodiac Sign is PISCES.."<<endl;
cout<<"Your Zodiac Sign is PISCES.."<<endl;
}
else if ((date>=21 && date<31 && month==3)||(date<=19 && date>=1 && month==4)) 
{fout<<"Your Zodiac Sign is ARIES.."<<endl;
cout<<"Your Zodiac Sign is ARIES.."<<endl;
}
else if ((date>=20 && date<31 && month==4)||(date<=20 && date>=1 && month==5))
{fout<<"Your Zodiac Sign is TAURUS.."<<endl;
cout<<"Your Zodiac Sign is TAURUS.."<<endl;
}
else if ((date>=21 && date<31 && month==5)||(date<=20 && date>=1 && month==6))
{fout<<"Your Zodiac Sign is GEMINI.."<<endl;
cout<<"Your Zodiac Sign is GEMINI.."<<endl;
}
else if ((date>=21 && date<31 && month==6)||(date<=22 && date>=1 && month==7))
{fout<<"Your Zodiac Sign is CANCER.."<<endl;
cout<<"Your Zodiac Sign is CANCER.."<<endl;
}
else if ((date>=23 && date<31 && month==7)||(date<=22 && date>=1 && month==8)) 
{fout<<"Your Zodiac Sign is LEO.."<<endl;
cout<<"Your Zodiac Sign is LEO.."<<endl; 
}
else if ((date>=23 && date<31 && month==8)||(date<=22 && date>=1 && month==9)) 
{fout<<"Your Zodiac Sign is VIRGO.."<<endl;
cout<<"Your Zodiac Sign is VIRGO.."<<endl;
}
else if ((date>=23 && date<31 && month==9)||(date<=22 && date>=1 && month==10)) 
{fout<<"Your Zodiac Sign is LIBRA.."<<endl;
cout<<"Your Zodiac Sign is LIBRA.."<<endl;
}
else if ((date>=23 && date<31 && month==10)||(date<=21 && date>=1 && month==11))
{fout<<"Your Zodiac Sign is SCORPIO.."<<endl;
cout<<"Your Zodiac Sign is SCORPIO.."<<endl;
}
else if ((date>=22 && date<31 && month==11)||(date<=21 && date>=1 && month==12)) 
{fout<<"Your Zodiac Sign is SAGUITTARIUS.."<<endl;
cout<<"Your Zodiac Sign is SAGUITTARIUS.."<<endl;
}
else if ((date>=22 && date<31 && month==12)||(date<=19 && date>=1 && month==1))
{fout<<"Your Zodiac Sign is CAPRICORN.."<<endl;
cout<<"Your Zodiac Sign is CAPRICORN.."<<endl;
}
else 
cout<<"You Have entered wrong input"<<endl;
return 0;
}

int display(){
	info::rec();
	cout<<"display";
cout<<"Name: "<<name<<"\nDOB: "<<date<<"/"<<month<<"/"<<year<<endl;
return 0;
		}
};


void west();
void record();

int main()
{
	 
	fstream file;
    cout<<"\t\t************      ZODIAC       ************"<<endl;
	cout<<"\n\nwhich type Zodiac do you want to known?\n1. western\nor\n2. display record.\n"<<endl;
	int n; cin>>n;
	file.open("west.dat",ios::binary|ios::in|ios::out);
		if (n==1){
		
			west();
			cout<<"west() closed";
			record();
			}
		else if(n==2){
			cout<<"record";
			record();
		}
		else{
			cout<<"something wrong";
		}
		file.close();
	return 0;
}
void west(){
	cout<<"west()";
	western_zodiac w;
	fstream file;
	w.western();
	file.write((char*)(&w), sizeof(western_zodiac));
	file.close();
	cout<<"file close";
}
void record(){
	ifstream fin;
	fin.open("west.dat",ios::binary|ios::in);
	cout<<"record initiate\n";
	western_zodiac w;	
	if(!fin)
	{
		cout<<"file doesn't exist\n";
		return;
	}
	while(fin.read((char*)(&w), sizeof(western_zodiac)))
	{
		cout<<"file found";
		w.display();
	}
	fin.close();
}

