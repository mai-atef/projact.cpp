#include <iostream>
#include <fstream>
#include <string.h>
using namespace std ;

class Student{
	public:
		int id , age ;
		char name[10]  ;
		
	public:
		void write_in_file() ;
		void get_fch_fstring() ;
		void read_from_file() ;
		void search() ;
		void copy() ;
		void length() ;
		void update () ;
		void delete_record() ;
};

void  write_in_file(){
	
	cout<<"\n" ;
	cout<<"****write****\n" ;
	char c ;
	ofstream outfile("path") ;
	Student s1 ;
	
	start:
	cout<<"input student id\n" ;
	cin>>s1.id ;
	cout<<"input student age\n" ;
	cin>>s1.age ;
	cout<<"input student name\n" ;
	cin>>s1.name ;

	if(outfile.is_open()){
		outfile.write(   (char*) &s1, sizeof(s1) ) ;
	    cout <<"Enter another record? (Y/N) ";
        cin >> c;
	}
	if(c=='y'||c=='Y'){
		goto start;
	} 
	else{
    	outfile.close() ;
	}
	
}
void get_fch_fstring(){
	
	cout<<"\n" ;
	cout<<"****get_fch_fstring****\n" ;
		char string[10] , ch ;
	ifstream infile ;
	infile.open("path",ios::in) ;
	int k ;
	cout<<"if you want to get the first charecter press (1)\nif you want to get the first word press (2)\n" ;
	cin>>k ;
	
	if(k==1){
	infile.get(ch) ;
	cout<<"the first charecter in the file is: "<<ch ;
	}
	else if(k==2){
	infile>>string ;
	cout<<"the first word in the file is: "<<string ;
	}
	
	else{
		cout<<"wrong input" ;
	}
}
void read_from_file(){

    Student s1;
    ifstream infile ;
    infile.open("path",ios::in) ;
     
    if(infile.is_open())
    {
        int id = 0;
        while(!infile.eof())
        {
            infile.read((char*)&s1,sizeof(s1));
            if(s1.id != id)
            {
                cout<<"ID:"<<s1.id << "\t" <<"Age:"<<s1.age<<"\t"<<"Name:"<<s1.name << endl;
                id = s1.id;
            }
        }
    }
    else
    {
        cout << "Cannot open the specified file !!";
    }
    infile.close();


	
}
void search(){
	cout<<"\n" ;
	cout<<"****search****\n" ;
	
	bool found = false ;
	Student s1 ;
	char string[10] ;
	cout<<"input the name you want to search: " ;
	cin>>string ;
	ifstream infile ;
	infile.open("my-file.txt", ios::in) ;
	while(!infile.eof()){
		infile.read((char*) &s1, sizeof(s1));
		if(strcmp(string,s1.name)==0){
			
		    	found =true ;
            cout<<"\n************found*************\n" ;
            cout << "ID" << "\t" << "Name" << "\t"<< "Age" << endl;
            cout << "----------------------------------" << endl;
            cout << s1.id << "\t" << s1.name << "\t" << s1.age<<"\n" ;
				break ;
					}
				
	}
	
			if(!found){
			cout<<"**************sorry, not found**************\n" ;
		}
			infile.close() ;
}
void copy(){
	char ch ;
	ofstream outfile("path") ;
	ifstream infile("mpath") ;
	
	while(infile.get(ch)){
		outfile.put(ch) ;
	}
	
	
		cout<<"\n" ;
	cout<<"*****file is copied*****\n" ;
	cout<<"the copied information is:\n" ;
 	read_from_file() ;
}
void length(){
	char ch;
	ifstream infile;
	infile.open("path",ios::in);
	if(infile.is_open()){
	
	infile.seekg(0,ios::end);
	cout<<"the length of the file is:"<<infile.tellg()<<endl;
}else{
	cout<<"the file can't open";
}
    infile.close();
}
void update (){
	
Student s;
char str[10];
fstream allFile("path", ios::in|ios::out);
cout << "Enter the name you want to update its record ";
 cin >> str;
 
while(!allFile.eof())
{
allFile.read((char*)&s,sizeof(s));
if(strcmp(str,s.name)==0)
{
cout << "Enter the new name for the student " << str << " ";
cin >> s.name;
cout << "Enter the new id for the student " << str << " ";
cin >> s.id;
cout << "Enter the new age for the student " << str << " ";
cin >> s.age;
streampos curPosition = allFile.tellg();
int studentSize = sizeof(s);
allFile.seekp(curPosition - studentSize,ios::beg);
allFile.write((char*)&s,sizeof(s));
allFile.seekg(curPosition - studentSize,ios::beg);
allFile.read((char*)&s,sizeof(s));
cout << "ID\tName\tAge"<<endl;
cout <<"------------------"<<endl;
cout << s.id << "\t" << s.name << "\t" << s.age<<endl;

break;
}

} 
}
void delete_record(){
	
	Student s;
	int id=0;
	char str[10];
	ifstream infile("path",ios::in);
	ofstream Temp("path",ios::out);
	if(infile.is_open()){
		while(!infile.eof()){
			infile.read((char*)&s, sizeof(s));
			if(strcmp(str,s.name)!=0&&id!=s.id){
				id=s.id;
				Temp.write((char*)&s, sizeof(s));
			}
		}
		infile.close();
		Temp.close();
		remove("path");
		rename("path","path");
	}
}
int main(){
	
	start :
	cout<<"*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*& Start *&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&\n" ;
	cout<<"to record inf in the file press       (1)\n" ;
	cout<<"to read inf from the file press       (2)\n" ;
	cout<<"to search about a name press          (3)\n" ;
	cout<<"to copy from(my-file) to another file (4)\n" ;
	cout<<"length                                (5)\n" ;
	cout<<"update the file                       (6)\n" ;
	cout<<"delete a record from the file         (7)\n" ;
	int x ;
	cin>> x ;
	switch(x) {
		case 1:
	    	write_in_file() ;
	    	   break;
    	case 2:
	        read_from_file() ;
	        	break;	
		case 3:
			search() ;
			    break;
		case 4:
			copy() ;
			
		        break;
		case 5:
			length() ;
			    break;	
		case 6:
			update() ;
			    break;
		case 7:
			delete_record()  ;
			    break;
	}

	char test ;
	cout<<"do you want to go again(y/n)" ;
	cin>>test ;
	if(test=='y'||test=='Y'){
		goto start ;
	}

else{
	cout<<" good buy ya zmeely\n" ;
}

	
	return 0 ;
}

































