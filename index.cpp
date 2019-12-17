//============================================================================
// Name        : 学生成绩管理.cpp
// Author      : foxfish
// Version     :
// Copyright   : Your copyright notice
// Description : main
//============================================================================

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <map>
#include <vector>
using namespace std;
#include "student.h"
#include "slist.h"
#include "iofunc.h"
#include "statistics.h"

int main() {
	//建立链表
	create();
	//读取文件
	if(!getfromdata()){
		cout<<"当前无学生数据，请使用add命令添加"<<endl;
	}
	//循环，读取命令
	char cmd[51];
	while(1){
		cout<<"main-->>";
		for(int i=0;i<51;++i){
			cmd[i]=0;
		}
		cin.getline(cmd, 50,'\n');

		if(!strcmp(cmd,"exit")){
			save();
			break;
		}else if(cmd[0]==0){
			continue;
		}else if(!strcmd(cmd,"add",3)){
			add();
		}else if(!strcmd(cmd,"list",4)){
			if(!list(cmd+4+1))
				cout<<"list error"<<endl;
		}else if(!strcmd(cmd,"saveas",6)){
			if(!saveas())
				cout<<"open error"<<endl;
		}else if(!strcmd(cmd,"save",4)){
			save();
		}else if(!strcmd(cmd,"remove",6)){
			if(!remove(cmd+6+1))
				cout<<"cannot find"<<endl;
		}else if(!strcmd(cmd,"help",4)){
			help();
		}else if(!strcmd(cmd,"sort",4)){
			if(!sortlist(cmd+4+1))
				cout<<"input error"<<endl;
		}else if(!strcmd(cmd,"change",6)){
			if(!change(cmd+6+1))
				cout<<"cannot find or input error"<<endl;
		}else if(!strcmd(cmd,"get",3)){
			if(!search(cmd+3+1))
				cout<<"cannot find"<<endl;
		}else if(!strcmd(cmd,"statistics",10)){
			if(!statistics(cmd+10+1))
				cout<<"input error"<<endl;
		}else if(!strcmd(cmd,"average",7)){
			if(!average(cmd+7+1))
				cout<<"input error"<<endl;
		}else{
			cout<<"找不到命令"<<cmd<<endl;
			continue;
		}
	}
	//退出时保存文件

	return 0;
}
