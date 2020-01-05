#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;


//declaring global constants
static string all="abcdefghijklmnopqrstuvwxyz! ?:,ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static int len=all.size();
       int pop_size=20;
       int split1=pop_size/2+2;
       int split2=pop_size-2;

//initialization::function for genetic algorithm
void RandomPop(string name,int name_len){
	int generation=1;
	string arr[pop_size];
	int fit_score[pop_size]={0};

 //create random pop and calc fitness
    for(int i=0;i<pop_size;i++){
		for(int j=0;j<name_len;j++){
			int rdm=rand()%len;
			arr[i]+=all[rdm];
			if(all[rdm]==name[j]){
				fit_score[i]++;
			}
		}
	}
	
start:
	string newArr[pop_size];
	int newFit_score[pop_size]={};
	int index1,index2,index3,index4,best=0,best2=0,best3=0,best4=0;
	
	//first best fit parent will be added directly to new-gen
	for(int i=0;i<pop_size;i++){
		if(best<fit_score[i]){
			best=fit_score[i];
			index1=i;
		}
	}
	cout<<"GEN:"<<generation<<"::Goal:"<<name_len<<"::Fitness: "<<fit_score[index1]<<" ::   "<<arr[index1]<<"\n";
	newArr[0]=arr[index1];
	newFit_score[0]=fit_score[index1];

	//second best fit parent will be added directly to new-gen
	for(int i=0;i<pop_size;i++){
		if(best2<fit_score[i] && index1!=i){
			best2=fit_score[i];
			index2=i;
		}
	}
	newArr[1]=arr[index2];
	newFit_score[1]=fit_score[index2];

	//index3
	for(int i=0;i<pop_size;i++){
		if(best3<fit_score[i] && index1!=i && index2!=i){
			best3=fit_score[i];
			index3=i;
		}
	}

	if(index3<=0 && index3<pop_size){
	   newArr[2]=arr[index3];
	   newFit_score[2]=fit_score[index3];
}
		//index4
	for(int i=0;i<pop_size;i++){
		if(best4<fit_score[i] && index1!=i && index2!=i && index3!=i){
			best4=fit_score[i];
			index4=i;
		}
	}

	if(index4<=0 && index4<pop_size){
	newArr[3]=arr[index4];
	newFit_score[3]=fit_score[index4];
}

    //selection of 2 parents for mating  ....IMPORTANT**************************************************
                                           //select 2 best fitest array's index 
	for(int j=0;j<name_len/2;j++){
			newArr[4]+=arr[index1][j];      //mating 2 arrays to each other ...half half
			newArr[5]+=arr[index2][j];
		}

    for(int k=name_len/2;k<name_len;k++){    //other half mating
			newArr[4]+=arr[index1][k];
			newArr[5]+=arr[index2][k];
		}
		int rm=rand()%32;                        //the most important part --> insert random character in between to avoid saturation point
		int rm1=rand()%name_len;
		newArr[4][rm1]=all[rm];
		rm1=rand()%name_len;
		newArr[5][rm1]=all[rm];
        
		//*************************************************
		
		//selection pool created with first 4 fittest index and their values
	int index_array[4]={index1,index2,index3,index4}; 
	int pnum1=index_array[rand()%4];
	int pnum2=index_array[rand()%4];        
    for(int j=0;j<name_len;j++){
			if(newArr[4][j]==name[j]){
				newFit_score[4]++;
			}
			if(newArr[5][j]==name[j]){
				newFit_score[5]++;
			}
		}
    
	//crossover next of 8 new-gen  with these 2 parents from selection pool and few from all
	for(int i=6;i<pop_size;i++){
		for(int j=0;j<name_len;j++){
			int num=rand()%10;   ///for random probability upto 10
			if(num<split1){
				newArr[i]+=arr[pnum1][i];           //add random index from best-0fit 1
			}
			else if(num>=split1 && num<split2){
				newArr[i]+=arr[pnum2][i];
			}
			else{
				int rdm=rand()%name_len;
				newArr[i]+=all[rdm];
			}
			if(newArr[i][j]==name[j]){
				newFit_score[i]++;
			}
		}
	}
	for(int i=0;i<pop_size;i++){
		arr[i]=newArr[i];
	    fit_score[i]=newFit_score[i];
	}
	
	generation++;
	cout<<"\n";
   if(best<=name_len-1){
      goto start;
    }
}



int main(){
    srand((time(0)));
    
    string name="to be or not to be, that is the question!";
	int name_len = name.size();
	string pool;

    RandomPop(name,name_len);
        
	return 0;
}
