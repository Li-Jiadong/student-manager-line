/*
 * student.h
 *
 *  Created on: Dec 12, 2019
 *      Author: foxfish
 *      本文件用于定义结构体，并设置一些相关方法
 */

#ifndef STUDENT_H_
#define STUDENT_H_
struct student{
	long long id;//十位
	char name[20];
	char sex;// 男和女
	float math,eng,cs;
	float aver;//平均成绩
	student *next;
	student *before;
	/*
	 * bool re;
	 * if(cmp(a,b,re));
	 * if(re)
	 * cout<<s<<endl;
	 * */
	friend bool cmp(student a,student b,bool &re,char in='a'){
		if(in=='m'){
			re=a.math<b.math;
			return 1;
		}else if(in=='e'){
			re=a.eng<b.eng;
			return 1;
		}else if(in=='c'){
			re=a.cs<b.cs;
			return 1;
		}else if(in=='a'){
			re=a.aver<b.aver;
			return 1;
		}else{
			return 0;
		}
	}
	friend bool changescore(student s,float to,char in){
		if(to<=100&&to>0){
			if(in=='m'){
				s.math=to;
				return 1;
			}else if(in=='e'){
				s.eng=to;
				return 1;
			}else if(in=='c'){
				s.cs=to;
				return 1;
			}else{
				return 0;
			}
			s.aver=(s.math+s.eng+s.cs)/3+1e-6;
		}else{
			return 0;
		}
	}
	friend bool inpfc(student &s){
		//增加输入判断！！！不写id
		cin>>s.name;
		cin>>s.sex;
		s.sex=toupper(s.sex);
		if(s.sex!='M'&&s.sex!='W') return 0;
		cin>>s.math;
		if(cin.fail()||s.math<0||s.math>100)
			return 0;
		cin>>s.eng;
		if(cin.fail()||s.eng<0||s.eng>100)
			return 0;
		cin>>s.cs;
		if(cin.fail()||s.cs<0||s.cs>100)
			return 0;
		s.aver=(s.math+s.eng+s.cs)/3+1e-6;
		return 1;
	}
	friend bool operator < (student a,student b){
		return a.aver<b.aver;
	}
	friend ifstream& operator >>(ifstream &fin,student *s){
		fin>>s->id>>s->name>>s->sex>>s->math>>s->eng>>s->cs>>s->aver;
		return fin;
	}
	friend istream& operator >>(istream &in,student &s){
		in>>s.id>>s.name>>s.sex>>s.math>>s.eng>>s.cs;
		s.aver=(s.math+s.eng+s.cs)/3+1e-6;
		return in;
	}
	friend ostream& operator <<(ostream &out,student &s){
		out<<setw(10)<<s.id<<"  "<<setw(8)<<s.name<<"  ";
		out<<s.sex<<"  "<<s.math<<"  "<<s.eng<<"  "<<s.cs<<"  ";
		out<<s.aver;
		return out;
	}
	friend ofstream& operator <<(ofstream &out,student &s){
		out<<setw(10)<<s.id<<"  "<<setw(8)<<s.name<<"  ";
		out<<s.sex<<"  "<<s.math<<"  "<<s.eng<<"  "<<s.cs<<"  ";
		out<<s.aver;
		return out;
	}
};
bool title(){
	cout<<"学号\t姓名\t性别\t";
	cout<<"数学\t";
	cout<<"英语\t";
	cout<<"计算机\t";
	cout<<"平均";
	cout<<endl;
	return 0;
}
bool changeitem(char c,student &s){
	float in;
	cin>>in;
	if(!cin.fail()){
		if(in>=0||in<=100){
			if(c=='m')
				s.math=in;
			else if(c=='e')
				s.eng=in;
			else if(c=='c')
				s.cs=in;
			else
				return 0;
		}else{
			return 0;
		}
	}else{
		cin.clear();
		cin.ignore(1024,'\n');
		return 0;
	}
	return 1;
}


#endif /* STUDENT_H_ */
