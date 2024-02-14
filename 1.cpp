#include <iostream>;
int main()
{
int rows, cols;
// Input the number of rows and columns for the 2D array
std::cout<<"Enter the number of rows:";
std::cin>>rows;
std::cout<<"Enter the number of columns:";
std::cin>>cols;
// Create a 2D array
int** twoDArray = new int*[rows];
for (int i = 0; i <rows;  ++i) {
twoDArray[i] = new int[cols];
}
// Input data into the 2D array
std::cout<<"Enter the elements of the 2D array:" <<std::endl;
for (int i = 0; i<rows;  ++i) {
for (int j = 0; j < cols; ++j) {
std::cout <<"Enter element at row "<< i + 1 << "and column " << j + 1<<": " ;
std::cin >> twoDArray[i][j];
}
}
// Calculate the size of the 1D array
int oneDSize = rows * cols;
int* oneDArray = new int[oneDSize];
// Copy data from 2D to 1D array in column-major order
int index = 0;
for (int j = 0; j <cols; ++j) {
for (int i = 0; i < rows; ++i) {
oneDArray[index] = twoDArray[i][j];
index++;
}
}
// Display the 1D array
std::cout <<"1D array (Column Major Order): " ;
for (int i = 0; i<oneDSize; ++i) {
std::cout <<oneDArray[i] ;
}
std::cout<< std::endl;

// Deallocate memory
for (int i = 0; i < rows; ++i) {
delete[] twoDArray[i];
}
delete[] twoDArray;
delete[] oneDArray;
return 0;
}
