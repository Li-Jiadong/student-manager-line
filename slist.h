/*
 * slist.h
 *
 *  Created on: Dec 12, 2019
 *      Author: foxfish
 *      本文件用于链表的建立和基本操作
 */

#ifndef SLIST_H_
#define SLIST_H_
student *head=0,*tail=0;
int num=0;
bool create(){
	head=new student();
	tail=head;
	tail->next=0;
	tail->before=0;
	return 1;
}
bool add(){
	long long in;
	while(1){
		cout<<"add-->>";
		cin>>in;
		if(cin.fail()){
			cout<<"input error"<<endl;
			cin.clear();
			cin.ignore(1024,'\n');
			continue;
		}
		if(in==0){
			break;
		}else if(in>1e10-1&&in<1e11){
			student *s=new student();
			s->id=in;
			if(inpfc(*s)){
				tail->next=s;
				s->before=tail;
				tail=s;
				tail->next=0;
				++num;
			}else{
				cout<<"input error"<<endl;
				delete s;
				cin.clear();
				cin.ignore(1024,'\n');
				continue;
			}
		}else{
			cout<<"input error"<<endl;
			cin.clear();
			cin.ignore(1024,'\n');
			continue;
		}
	}
	cin.ignore(1024,'\n');
	return 1;
}
bool list(char cmd[]){
	student *p=head;
	int i=0;
	bool a=0,m=0,e=0,c=0;
	while(cmd[i]!='-'){
		++i;
		if(cmd[i]==0){
			i=-1;
			break;
		}
	}++i;
	if(i!=0&&cmd[i]==0) return 0;
	while(i!=0){
		if(cmd[i]=='a')
			a=1;
		else if(cmd[i]=='m')
			m=1;
		else if(cmd[i]=='e')
			e=1;
		else if(cmd[i]=='c')
			c=1;
		else if(cmd[i]==' '||cmd[i]==0)
			break;
		else return 0;
		++i;
	}
	cout<<"序号\t";
	cout<<"学号\t姓名\t性别\t";
	if(a||m) cout<<"数学\t";
	if(a||e) cout<<"英语\t";
	if(a||c) cout<<"计算机\t";
	if(a) cout<<"平均";
	cout<<endl;
	i=1;
	while(p->next!=0){
		//cout<<p->next<<endl;
		p=p->next;
		cout<<i<<"\t";
		cout<<p->id<<"\t";
		cout<<p->name<<"\t";
		cout<<p->sex<<"\t";
		if(a||m) cout<<p->math<<"\t";
		if(a||e) cout<<p->eng<<"\t";
		if(a||c) cout<<p->cs<<"\t";
		if(a) cout<<p->aver<<"\t";
		++i;
		cout<<endl;
	}
	return 1;
}
bool remove(char cmd[]){
	student *p=head,*be;
	int i=0;
	bool n=0,id=0;
	while(cmd[i]!='-'){
		++i;
		if(cmd[i]==0){
			i=-1;
			break;
		}
	}++i;
	while(i!=0){
		if(cmd[i]=='n')
			n=1;
		else if(cmd[i]=='i')
			id=1;
		else if(cmd[i]==' ')
			break;
		else return 0;
		++i;
	}
	//cout<<i<<" "<<n<<" "<<id<<endl;
	if(i==0||id){
		long long rid=0;
		while(cmd[i]<'1'||cmd[i]>'9'){
			if(cmd[i]==0) return 0;
			++i;
		}
		while(cmd[i]>='0'&&cmd[i]<='9'){
			rid=rid*10+cmd[i]-'0';
			++i;
		}
		if(p->next==0) return 0;
		while(p->next!=0){
			be=p;
			p=p->next;
			if(p->id==rid){
				be->next=p->next;
				p->next->before=be;
				delete p;
				break;
			}else if(p->next==0){
				return 0;
			}
		}
	}else if(n){
		int rn=0;
		while(cmd[i]<'1'||cmd[i]>'9'){
			++i;
		}
		//cout<<i<<endl;
		while(cmd[i]>='0'&&cmd[i]<='9'){
			rn=rn*10+cmd[i]-'0';
			++i;
		}
		//cout<<rn<<endl;
		if(p->next==0) return 0;
		for(int j=0;j<rn;++j){
			if(p->next==0) return 0;
			be=p;
			p=p->next;
		}
		be->next=p->next;
		p->next->before=be;
		delete p;
	}
	return 1;
}

bool search(char cmd[]){
	student *p=head,*be;
	int i=0;
	bool n=0,id=0;
	while(cmd[i]!='-'){
		++i;
		if(cmd[i]==0){
			i=-1;
			break;
		}
	}++i;
	while(i!=0){
		if(cmd[i]=='n')
			n=1;
		else if(cmd[i]=='i')
			id=1;
		else if(cmd[i]==' ')
			break;
		else return 0;
		++i;
	}
	if(i==0||id){
		long long rid=0;
		while(cmd[i]<'1'||cmd[i]>'9'){
			if(cmd[i]==0) return 0;
			++i;
		}
		while(cmd[i]>='0'&&cmd[i]<='9'){
			rid=rid*10+cmd[i]-'0';
			++i;
		}
		if(p->next==0) return 0;
		while(p->next!=0){
			p=p->next;
			if(p->id==rid){
				title();
				cout<<*p<<endl;
				break;
			}else if(p->next==0){
				return 0;
			}
		}
	}else if(n){
		if(p->next==0) return 0;
		char name[20];
		istringstream iss(cmd+i);
		iss>>name;
		//cout<<name<<endl;
		int istitle=0;
		while(p->next!=0){
			p=p->next;
			if(!strcmp(name,p->name)){
				if(!istitle){
					istitle=1;
					title();
				}
				cout<<*p<<endl;
			}
		}
		if(!istitle) return 0;
	}
	return 1;
}
bool change(char cmd[]){
	student *p=head,*be;
	int i=0;
	bool n=0,id=0,m=0,e=0,c=0,a=0,none=0;
	while(cmd[i]!='-'){
		++i;
		if(cmd[i]==0){
			i=-1;
			break;
		}
	}++i;
	if(i==0) none=1;
	while(none==0){
		if(cmd[i]=='n')
			n=1;
		else if(cmd[i]=='i')
			id=1;
		else if(cmd[i]=='m')
			m=1;
		else if(cmd[i]=='e')
			e=1;
		else if(cmd[i]=='c')
			c=1;
		else if(cmd[i]=='a')
			a=1;
		else if(cmd[i]==' ')
			break;
		else return 0;
		++i;
	}
	if(none||id){
		if(!e&&!c&&!m) none=1;
		long long rid=0;
		while(cmd[i]<'1'||cmd[i]>'9'){
			if(cmd[i]==0) return 0;
			++i;
		}
		while(cmd[i]>='0'&&cmd[i]<='9'){
			rid=rid*10+cmd[i]-'0';
			++i;
		}
		if(p->next==0) return 0;
		while(p->next!=0){
			be=p;
			p=p->next;
			if(p->id==rid){
				cout<<"change for "<<p->name<<"("<<p->id<<")"<<">>";
				if(none||a){
					if(changeitem('m',*p)&&changeitem('e',*p)&&changeitem('c',*p)){

					}else{
						return 0;
					}
				}else{
					if(m){
						if(changeitem('m',*p)){

						}else return 0;
					}
					if(e){
						if(changeitem('e',*p)){

						}else return 0;
					}
					if(c){
						if(changeitem('c',*p)){

						}else return 0;
					}
				}
				break;
			}else if(p->next==0){
				return 0;
			}
		}
	}else if(n){
		if(!e&&!c&&!m) none=1;
		int rn=0;
		while(cmd[i]<'1'||cmd[i]>'9'){
			++i;
		}
		//cout<<i<<endl;
		while(cmd[i]>='0'&&cmd[i]<='9'){
			rn=rn*10+cmd[i]-'0';
			++i;
		}
		//cout<<rn<<endl;

		if(p->next==0) return 0;
		for(int j=0;j<rn;++j){
			if(p->next==0) return 0;
			p=p->next;
		}
		cout<<"change for "<<p->name<<"("<<p->id<<")"<<">>";
		if(none||a){
			if(changeitem('m',*p)&&changeitem('e',*p)&&changeitem('c',*p)){

			}else{
				return 0;
			}
		}else{
			if(m){
				if(changeitem('m',*p)){

				}else return 0;
			}
			if(e){
				if(changeitem('e',*p)){

				}else return 0;
			}
			if(c){
				if(changeitem('c',*p)){

				}else return 0;
			}
		}

	}
	cin.ignore(1024,'\n');
	return 1;
}
#endif /* SLIST_H_ */
