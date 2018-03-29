#include <iostream>
#include <cstring>
using namespace std;

class  matrix
	double *p;	
	int row;
	int column;
	bool flag;
	
public:
	matrix(){
		p=new double[1][1];
		p[0][0]=0.0;
		flag=false;
	}

	matrix (int i){
		column=i;
		row=j;
		p=new double [i][7];
		for (i=0; i<num; i++) for (int j=0; j<num; j++) p[i][j]=0.0;
		flag=false;
	}

	matrix (int i, int j){
		column=i;
		row=j;
		p=new double [i][j];
		for (i=0; i<num; i++) for (j=0; j<num; j++) p[i][j]=0.0;
		flag=false;
	}
	
	~matrix(){
		delete [] p;
	}

	float get(int i, int j){
	
		return p[i][j];
	}

	
	
	void print(){
		for (int i=0; i<num; i++) {
			for (int j=0; j<num; j++) cout << p[i][j];
			cout << endl;
		}
	};


	}

	void add(matrix target_matrix){
		for (int i=0; i<num; i++) for (int j=0; j<num; j++)  this->p[i][j]+=target_matrix.get(i,j)
	};

	void sub(matrix target_matrix){
		for (int i=0; i<num; i++) for (int j=0; j<num; j++)  this->p[i][j]-=target_matrix.get(i,j)
	};

	void mul(matrix target_matrix){
		for (int i=0; i<num; i++) for (int j=0; j<num; j++)  this->p[i][j]*=target_matrix.get(i,j)
	};
	void mul(int digit){
		for (int i=0; i<num; i++) for (int j=0; j<num; j++)  this->p[i][j]*=digit;
	};





};
int main(){
	matrix a;
	matrix b(7);
	matrix c(4,8);
	b.print();
	b.add(c,1,1);
	b.print();
	b.mul(c,1,1);

	return 0;
}