#include <iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

int vec[100];
int vec_temp[100];
int count=0;

double eval(int *pj);

void print(int* print_array){
	for(int i=0;i<100;i++){
		cout<<print_array[i];
	}
	cout<<endl;
}

void generate_vector(int* vec_for_generation){
	for(int i=0;i<100;i++)
		vec_for_generation[i]=0;
	int random_number = rand()%100;
	int temp_random_number;
	for(int i=0;i<random_number;i++){
		int temp_random_number = rand()%100;
		vec_for_generation[temp_random_number] = 1;
	}
}

void mutate(int* mut_vec){
	int random_number= rand()%100;
	for(int i=0;i<random_number;i++){
		int temp_random_number = rand()%100;
		if( mut_vec[temp_random_number]==1){
			mut_vec[temp_random_number]=0;
		}else{
			mut_vec[temp_random_number]=1;
		}
	}
}

void make_carbon_copy(int* winning_vec,int* lossing_vec){
	for(int i=0;i<100;i++)
		lossing_vec[i]=winning_vec[i];
}

int main()
{
  	generate_vector(vec);
	generate_vector(vec_temp);
	/*cout<<"Vec ::"<<endl;
	print(vec);
	cout<<"Vec_temp ::"<<endl;
	print(vec_temp);*/
	for(int j=0;j<1000;j++){
		int fitness_vec = eval(vec);
		int fitness_vec_temp = eval(vec_temp);
		cout<<"Fitness_vec = "<<fitness_vec<<endl;
		cout<<"fitness_vec_temp ="<<fitness_vec_temp<<endl;
		if(fitness_vec > fitness_vec_temp){
			make_carbon_copy(vec,vec_temp);
			mutate(vec_temp);
		}else{
			make_carbon_copy(vec_temp,vec);
			mutate(vec);
		}
	}
	return 0;
}

