#include <iostream>
using namespace std;


class Matrix{
    private:
        int matrix[10][10] = {{0}};
        int _row, _col;

    public:
        Matrix(){}
        Matrix(int r, int c){
            _row = r;
            _col = c;
        }
        void createMatrix(int, int);
        void createMatrix(int);
        void createMatrix();
        void printMatrix();
        Matrix multiply(Matrix);
};

void Matrix :: createMatrix(int row, int col){

    this->_row = row;
    this->_col = col;

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<"Enter Element "<<i<<","<<j<<" : "; 
            cin>>matrix[i][j];
        }
    }
}

void Matrix :: createMatrix(int ind){
    for(int i=0; i<_row; i++){
        for(int j=0; j<_col; j++){
            matrix[i][j] = 0|ind;
        }
    }
}
void Matrix :: createMatrix(){

    int row, col;
    cout<<"Enter Rows of Matrix : "; cin>>row;
    cout<<"Enter Cols of Matrix : "; cin>>col;

    this->_row = row;
    this->_col = col;

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<"Enter Element "<<i<<","<<j<<" : "; 
            cin>>matrix[i][j];
        }
    }
}

void Matrix :: printMatrix(){
    for(int i=0; i<_row; i++){
        for(int j=0; j<_col; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

Matrix Matrix :: multiply(Matrix m2){


    Matrix m(this->_row, m2._col);

    if(this->_col != m2._row){
        cout<<"No Multiplication Possible";
        return m;
    }


    for(int i=0; i<this->_row; i++){
        for(int j=0; j<m2._col; j++){
            for(int k=0; k<this->_col; k++){
                m.matrix[i][j] += this->matrix[i][k]*m2.matrix[k][j];
            }
        }
    }

    return m;

}



int main(){

    Matrix m1;
    Matrix m2;
    Matrix m3;

    m1.createMatrix(3,3);
    m2.createMatrix(3,3);

    m3 = m1.multiply(m2);

    m3.printMatrix();

    

    return 0;
}