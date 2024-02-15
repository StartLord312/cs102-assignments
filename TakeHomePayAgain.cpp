
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main(){

double lft;
double income;
double net;
double nettax = 0;
double bracket = 0;

//each set bracket, 6 vals max index 5
vector<double> incomeLevels {10275, 41775, 89075, 170050, 215950, 539900 };

//tax % from each limited bracket
vector<double> taxes {.1, .12, .22, .24, .32, .35, .37 };

cout << "Enter your yearly income: " << endl;
cin >> income;
if(income < 15080){
cout << "This is less than minimum wage for a yearly salary." << endl; return 1; //maybe make this cerr?
}

double sst = income * .062;
double mt = income * .0145;

for(int i = 0; i < 6; i++ ){ //iterate through number of income levels to find bracket
if(income > incomeLevels[i]){
bracket = i;
}
}
for(int i = 0; i <= bracket ; i++){
if(i == 0){
nettax += 10275 * .1;
}else{
nettax += ((incomeLevels[i] - incomeLevels[i - 1]) * taxes[i]);
}
}
//here we assign lft or "leftover" its value
lft = income - incomeLevels[bracket];

nettax += lft * taxes[bracket + 1];

cout << bracket << " " << nettax << " " << lft;

//gives correct tax amounts for 25l and 751500
//need formatting and erros for below min wage salary



}




