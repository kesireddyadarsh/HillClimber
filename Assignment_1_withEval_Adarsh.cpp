#include<iostream>
#include<cstdlib>

using namespace std;

int vec[100];
int vec_temp[100];
int count=0;


double eval(int* eval_vec){
	int total_zeros=0,total_ones=0;
	for(int i=0;i<100;i++){
		if( i == 0 && eval_vec[i] ==0){
			total_zeros++;
		}
		if(i%2 == 0 && i <= 45 && eval_vec[i] ==0 && i !=0){
			total_zeros++;
		}
		if(i%2 != 0 && i <= 45 && eval_vec[i] == 1){
			total_ones++;
		}
		if(i>45 && eval_vec[i] ==0){
			total_ones++;
		}
	}
	int total_sum = total_ones+total_zeros;
	double fitness_value = 0;
	cout<<"This is total_sum = "<<total_sum<<endl;
	//return total_sum;
	if(total_sum == 0){
		cout<<"Are you coming in here???"<<endl;
		return fitness_value;
	}else if(total_sum>0 && total_sum<=45){
		fitness_value = total_sum;
	}else if(total_sum>45 && total_sum<=90){
		fitness_value = 90-total_sum;
	}else if(total_sum>90 && total_sum<=96){
		fitness_value = 16*total_sum;
	}else if(total_sum >96){
		fitness_value = 100;
	}
	return fitness_value;
}

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


/*int main(){
	cout<<"Lets get some code working!!"<<endl;
	int temp[100];
	for(int i=0; i<100;i++){
		if( i == 0 ){
			temp[i]=0;
		}
		if(i%2 == 0 && i <= 45 && i!=0){
			temp[i] =0;
		}
		if(i%2 != 0 && i <= 45 ){
			temp[i]=1;
		}
		if(i>45 ){
			temp[i]=0;
		}
	}
	for(int i=0;i<16;i++){
		temp[50+i]=1;
	}
	cout<<"This is array::"<<endl;
	for(int j=0;j<100;j++){
		cout<<temp[j];
	}
	double fitness=eval(temp);
	cout<<"fitness ="<<fitness<<endl;
	return 0;
}*/
