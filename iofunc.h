/*
 * iofun.h
 *
 *  Created on: Dec 12, 2019
 *      Author: foxfish
 *      本文件用于文件操作，输入输出
 */

#ifndef IOFUNC_H_
#define IOFUNC_H_
fstream data;
char sourse[100];
bool getfromdata(){
	data.open("data.stu",ios::in);
	if(data.fail()){
		data.close();
		return 0;
	}
	if(data.peek() == EOF){
		data.close();
		return 0;
	}
	//data>>num;
//	for(int i=0;i<num;++i){
//		student *s=new student();
//		data>>*s;
//		tail->next=s;
//		tail=s;
//		tail->next=0;
//	}
	while(!data.eof()){
		student *s=new student();
		data>>s->id;
		//cout<<"bb"<<endl;
		if(!data.fail()){
			data>>s->name>>s->sex;
			data>>s->math>>s->eng>>s->cs;
			data>>s->aver;
			tail->next=s;
			s->before=tail;
			tail=s;
			tail->next=0;
			//cout<<tail->next;
			++num;
		}else{
//			cout<<"aa"<<endl;
			data.clear();
			data.ignore(1024,'\n');
			delete s;
		}

	}
	data.close();
	return 1;
}
bool save(){
	data.open("data.stu",ios::out);
	student *p=head;
	//data<<num<<endl;
	while(p->next!=0){
		p=p->next;
		data<<*p<<endl;
	}
	data.close();
	return 1;
}
bool saveas(){
	cout<<"save as>>";
	cin>>sourse;
	fstream des;
	des.open(sourse,ios::out);
	if(des.fail()){
		return 0;
	}
	student *p=head;
	des<<"加上条目"<<endl;
	while(p->next!=0){
		p=p->next;
		des<<*p<<endl;
	}
	des.close();
	cin.ignore(1024,'\n');
	return 1;
}
bool strcmd(char *a,char *b,int n){
	char cmd[11];
	for(int i=0;i<n;++i){
		cmd[i]=a[i];
	}
	cmd[n]=0;
	return strcmp(cmd,b);
}
bool help(){
	cout<<"帮助文档未完善"<<endl;
	return 1;
}

#endif /* IOFUNC_H_ */
