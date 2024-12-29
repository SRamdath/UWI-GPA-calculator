//Simon Ramdath convenience program, badly documented
// this currently works for 3 credit courses, if a course is 1 or 2 credits it's still easy to calculate. 
//Treat the course as a fraction of a regular course, that is 1 credits are .33 of a course and 2 credits are 
//.66, then multiply the gpa from the course by 1/3, or 2/3 depending. 
#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <typeinfo>
#include <cmath>
using namespace std;




void menu(){
	cout <<"0. Exit" <<endl;
	cout <<"1. Calculate New GPA" <<endl;
	cout <<"2. Calculate change in GPA"<<endl;
	cout <<"3. Calculate needed grades to reach target GPA" <<endl;
	cout <<endl;
	
}

double gradeFinder(string s){
	
	if(s=="A+"||s=="a+"||s=="4.3") 
		return 4.3;
	if(s=="A"||s=="a"||s=="4")
		return 4.0;
	if(s=="A-"||s=="a-"||s=="3.7")
		return 3.7;
	if(s=="B+"||s=="b+"||s=="3.3")
		return 3.3;
	if(s=="B"||s=="b"||s=="3")
		return 3.0;
	if(s=="B-"||s=="b-"||s=="2.7")
		return 2.7;
	if(s=="C+"||s=="c+"||s=="2.3")
		return 2.3;
	if(s=="C"||s=="c"||s=="2")
		return 2.0;
	if(s=="F1"||s=="f1"||s=="1.7")
		return 1.7;
	if(s=="F2"||s=="f2"||s=="1.3")
		return 1.3;
	else 
		return 0;
		
		
}

string GPAFinder(double i){  
	if((i>4.299 &&i<=4.3) || (i>4.3 && i<4.301)){
	
		return "A+";
	}
	else if((i>3.99 &&i<=4) || (i>4 && i<4.01)){
	
		return "A";
	}
	else if((i>3.69 &&i<=3.7) || (i>3.7 && i<3.701)){
	
		return "A-";
	}
	else if((i>3.209 &&i<=3.3) || (i>3.3 && i<3.301)){
	
		return "B+";
	}
	else if((i>2.99 &&i<=3.0) || (i>3.0 && i<3.001)){
	
		return "B";
	}
	else if((i>2.69 &&i<=2.7) || (i>2.7 && i<2.71)){
	
		return "B-";
	}
	else if((i>2.29 &&i<=2.3) || (i>2.3 && i<2.301)){
	
		return "C+";
	}
	else if((i>1.99 &&i<=2.0) || (i>2.0 && i<2.01)){
	
		return "C";
	}
	else if((i>1.69 &&i<=1.7) || (i>1.7 && i<1.71)){
	
		return "F1";
	}
	else if((i>1.39 &&i<=1.4) || (i>1.4 && i<1.41)){
	
		return "F2";
	}
		
	 else return "F3";
		
		
		
		
		
		
}

void option1(){
	int numcourses;
	string grade;
	double sum;
	double average;
		cout <<"Please enter the number of courses you wish to calculate the GPA for";
		cin  >> numcourses;
		
		for (int i=1; i<=numcourses; i++){
			cout <<"Please enter your grade for course " <<i <<": ";
			cin >>grade;
			sum=sum+gradeFinder(grade);
			
		}
		average=sum/numcourses;
		cout <<"Your GPA will be: "<<average <<endl;
	
}

void option2(){
	double numcourses;
	int currCourses;
	string grade;
	double sum;
	double average;
	double GPA;
	int credits=3;
	int effectivecourses;
		cout <<"Please enter your current GPA";
		cin >>GPA;
		cout <<"Please enter how many courses you have done(for degree GPA, year 1 courses do not count). ";
		
		
		cin >>currCourses;
		
		
		cout <<"Please enter the number of courses you wish to add to your GPA calculation. ";
		cin  >> numcourses;
		
		
		
	effectivecourses=numcourses;
		
		for (int i=1; i<=numcourses; i++){
			
			cout <<"Please enter your grade for course followed by the credits" <<i <<": ";
			cin >>grade;
			sum=sum+(gradeFinder(grade)*credits/3);
			effectivecourses-=1-(credits/3);
			
		}
		
		cout <<"Your updated GPA will be " <<((currCourses*GPA)+sum)/(effectivecourses+currCourses);
	
}

void option3(){
	srand (time(NULL));
	int numcourses;
	int currCourses;
	string grade;
	double sum;
	double average;
	double GPA;
	double target;
	double update;
	
	
	cout <<"Please enter your current GPA";
	cin >>GPA;
	cout <<"Please enter how many courses you have done(for degree GPA, year 1 courses do not count) ";
	cin >>currCourses;
	cout <<"Please enter your target GPA";
	cin >>target;
	cout <<"Please enter how many courses you want to accomplish this in: ";
	cin >>numcourses;
	
	double courses[numcourses];
	
	for(int i=0; i<numcourses; i++){
		courses[i]=0.0;
}
	double possible[11]={4.3,4,3.7,3.3,3,2.7,2.3,2,1.7,1.3,0};

	
	
	update=target*(numcourses+currCourses)-(currCourses*GPA);            ///////////////////
	
	average=update/(numcourses*1.0);
	
	if(average>=4.31){
	
		cout <<"Sorry, you cannot attain this GPA with these number of courses";
		return;
	}
	cout <<"For these next " <<numcourses <<" courses, you will need an average GPA of  " << average <<endl;
	cout <<"This can be accomplished by getting the grades : ";
	

	for(int i=0; i<11; i++){
		if(abs(possible[i]-average)<=0.001){
			
			for(int k=0;k<numcourses; k++){
				courses[k]=possible[i];
			}
			for (int i=0; i<numcourses; i++){
				cout <<i+1<<"  "<< GPAFinder(courses[i]) <<endl;
			
			}
			return;
		}
	}
	
	
	for(int i=11; i>=0; i--){
		if(possible[i]*numcourses>update){
		
			for(int k=0;k<numcourses; k++){
			
				courses[k]=possible[i];
			}
			
			break;
		}
		
	}
		
		
		
			double excess=courses[0]*numcourses-(average*numcourses);
			while(excess>=0.3){
				int random=rand()%numcourses;
				cout <<random <<endl;
				
				if(((courses[random]==3.7)||(courses[random]==2.7) ||(courses[random]==1.7))&&(excess>=0.4)){
						
							courses[random]=courses[random]-0.4;	
							excess= excess-0.4;
						
						}
				
					else {
					
						courses[random]=courses[random]-0.3;   
						excess= excess-0.3;
					}
					 
			}
			if((excess>0.0999 &&excess<=0.1)||(excess>0.1 && excess<0.1001)){
				bool found1=false;
				bool found2=false;
				int foundindex1=0;
				int foundindex2=0;
				
				for (int i=0; i<numcourses; i++){
					if((courses[i]-floor(courses[i])==0.7)){
						found1=true;
					    foundindex1=i;
					}
					else{ 
						if((courses[i]-floor(courses[i])!=0) && courses[i]!=4.3){
						
					found2=true;
					foundindex2=i;
						}
					}
				}
				if(found1 &&found2){
					courses[foundindex1]-=0.4;
					courses[foundindex2]+=0.3;
				}
				
			}
			
			if((excess>0.1999 &&excess<=0.2)||(excess>0.2 && excess<0.2001)){
				bool found1=false;
				bool found2=false;
				int count=0;
				int foundindex1=0;
				int foundindex2=0;
				int foundindex3=0;
				
				for (int i=0; i<numcourses; i++){
					if((courses[i]-floor(courses[i])==0.3)){
						found1=true;
					    foundindex1=i;
					}
					else{ 
						if((courses[i]-floor(courses[i])==0.7)){ 
							count++;
							foundindex3=i;
						
						if(count>=2){
						
							found2=true;
							foundindex2=i;
						}
					}
					}
				}
				if(found1 &&found2){
					courses[foundindex1]+=0.4;
					courses[foundindex2]-=0.3;
					courses[foundindex3]-=0.3;
				}
				
			}
			
			
			
			
		
			
			
			
			
			
			
			
			

	for (int i=0; i<numcourses; i++){
		cout <<courses[i];
		cout <<i+1<<"  "<< GPAFinder(courses[i]) <<endl;
	
	}
	
	
	
	
	
	
}
int main(){
	

	int opt;
	
	menu();
	cin >>opt;
	

	while(opt!=0){
	
		if (opt==1){
			option1();
			
		}
	
		if (opt==2){
			option2();
			
		}
		
		if(opt==3)
			option3();
			
			
			cout <<endl;
			menu();
			cin >>opt;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
	
	
	
	
}
