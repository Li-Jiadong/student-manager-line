/*
 * statisticcs.h
 *
 *  Created on: Dec 13, 2019
 *      Author: foxfish
 *      本文件用于写一些统计的方法，
 *      如排序，平均，统计各分数段的人数，不及格人数等
 */

#ifndef STATISTICS_H_
#define STATISTICS_H_
bool average(char cmd[]){
	student *p=head;
	int i=0;
	bool a=0,m=0,e=0,c=0,none=0;
	while(cmd[i]!='-'){
		++i;
		if(cmd[i]==0){
			i=-1;
			break;
		}
	}++i;
	if(i==0) none=1;
	if(!none&&cmd[i]==0) return 0;
	while(!none){
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

	float mave=0,eave=0,cave=0,aave=0;
	while(p->next!=0){
		//cout<<p->next<<endl;
		p=p->next;
		if(a||m) mave+=p->math;
		if(a||e) eave+=p->eng;
		if(a||c) cave+=p->cs;
		if(a||none) aave+=p->aver;
	}
	if(a||m) cout<<"数学平均分:"<<mave/num+1e-6<<endl;
	if(a||e) cout<<"英语平均分:"<<eave/num+1e-6<<endl;
	if(a||c) cout<<"计算机平均分:"<<cave/num+1e-6<<endl;
	if(a||none) cout<<"全部成绩平均分:"<<aave/num+1e-6<<endl;
	return 1;
}
bool stanum(float score,int &nno,int &nok,int &ng,int &nb){
	if(score>=90) ++nb;
	else if(score>=80) ++ng;
	else if(score>=60) ++nok;
	else ++nno;
	return 1;
}
bool statistics(char cmd[]){
	student *p=head;
	int i=0;
	bool a=0,m=0,e=0,c=0,none=0;
	while(cmd[i]!='-'){
		++i;
		if(cmd[i]==0){
			i=-1;
			break;
		}
	}++i;
	if(i==0) none=1;
	if(!none&&cmd[i]==0) return 0;
	while(!none){
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
	int mno=0,mok=0,mg=0,mb=0;
	int eno=0,eok=0,eg=0,eb=0;
	int cno=0,cok=0,cg=0,cb=0;
	int ano=0,aok=0,ag=0,ab=0;
	while(p->next!=0){
		//cout<<p->next<<endl;
		p=p->next;
		if(m) stanum(p->math,mno,mok,mg,mb);
		if(e) stanum(p->eng,eno,eok,eg,eb);
		if(c) stanum(p->cs,cno,cok,cg,cb);
		if(a||none) stanum(p->aver,ano,aok,ag,ab);
	}
	if(m){
		cout<<"数学及格"<<mok+mg+mb<<"人，不及格"<<mno<<"人。"<<endl;
		cout<<"其中良好"<<mg<<"人，优秀"<<mb<<"人。"<<endl;
	}
	if(e){
		cout<<"英语及格"<<eok+eg+eb<<"人，不及格"<<eno<<"人。"<<endl;
		cout<<"其中良好"<<eg<<"人，优秀"<<eb<<"人。"<<endl;
	}
	if(c){
		cout<<"计算机及格"<<cok+cg+cb<<"人，不及格"<<cno<<"人。"<<endl;
		cout<<"其中良好"<<cg<<"人，优秀"<<cb<<"人。"<<endl;
	}
	if(a||none){
		cout<<"及格"<<aok+ag+ab<<"人，不及格"<<ano<<"人。"<<endl;
		cout<<"其中良好"<<ag<<"人，优秀"<<ab<<"人。"<<endl;
	}
	return 1;
}
bool nodecmp(student *a,float value,int item,bool order){
	if(item==0){
		return (a->aver<value)^order||a->aver==value;
	}else if(item==1){
		return (a->math<value)^order||a->math==value;
	}else if(item==2){
		return (a->eng<value)^order||a->eng==value;
	}else if(item==3){
		return (a->cs<value)^order||a->cs==value;
	}
	return 1;
}
void nodeswap(student *a,student *b){
	student temp;

	temp.aver=a->aver;
	temp.cs=a->cs;
	temp.eng=a->eng;
	temp.id=a->id;
	temp.math=a->math;
	temp.sex=a->sex;
	strcpy(temp.name,a->name);

	a->aver=b->aver;
	a->cs=b->cs;
	a->eng=b->eng;
	a->id=b->id;
	a->math=b->math;
	a->sex=b->sex;
	strcpy(a->name,b->name);

	b->aver=temp.aver;
	b->cs=temp.cs;
	b->eng=temp.eng;
	b->id=temp.id;
	b->math=temp.math;
	b->sex=temp.sex;
	strcpy(b->name,temp.name);
}
student* quickmid(int item,bool order,student *h,student *t){
	int key;
	if(item==0)
		key=h->aver;
	else if(item==1)
		key=h->math;
	else if(item==2)
		key=h->eng;
	else if(item==3)
		key=h->cs;
	while(h!=t){
		while(h!=t && nodecmp(t,key,item,!order)){
			t=t->before;
		}
		if(h!=t) nodeswap(h,t);
		while(h!=t && nodecmp(h,key,item,order)){
			h=h->next;
		}
		if(h!=t) nodeswap(h,t);
	}
	return h;
}
void quicklistsort(int item,bool order,student *h,student *t){
	if(h!=t){
		student *key=quickmid(item,order,h,t);
		if(h!=key)quicklistsort(item,order,h,key->before);
		if(t!=key)quicklistsort(item,order,key->next,t);
	}
}
bool sortlist(char cmd[]){
	student *p=head;
	int i=0;
	bool a=0,m=0,e=0,c=0,none=0,u=0,d=0;
	while(cmd[i]!='-'){
		++i;
		if(cmd[i]==0){
			i=-1;
			break;
		}
	}++i;
	if(i==0) none=1;
	if(!none&&cmd[i]==0) return 0;
	while(!none){
		if(cmd[i]=='a')
			if(m||e||c) return 0;
			else a=1;
		else if(cmd[i]=='m')
			if(a||e||c) return 0;
			else m=1;
		else if(cmd[i]=='e')
			if(a||m||c) return 0;
			else e=1;
		else if(cmd[i]=='c')
			if(a||m||e) return 0;
			else c=1;
		else if(cmd[i]=='u'){
			if(d) return 0;
			u=1;
		}else if(cmd[i]=='d'){
			if(u) return 0;
			d=1;
		}
		else if(cmd[i]==' '||cmd[i]==0)
			break;
		else return 0;
		++i;
	}
	bool order=1;
	int item=0;
	if(none||d) order=1;
	else if(u) order=0;
	if(a) item=0;
	else if(m) item=1;
	else if(e) item=2;
	else if(c) item=3;
	quicklistsort(item,order,head->next,tail);
	return 1;
}


#endif /* STATISTICS_H_ */
