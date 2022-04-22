#include<iostream>
#include<cmath>
#include<algorithm>
#include"getOneGaussianByBoxMueller.h"
#include"EuropeanOption.h"


//definition of constructor
EuropeanOption::EuropeanOption(
	int nInt_,
	double strike_,
	double spot_,
	double vol_,
	double r_,
	double expiry_,
	double barrier_,
	long int nReps_){
		nInt = nInt_;
		strike = strike_;
		spot = spot_;
		vol = vol_;
		r = r_;
		expiry = expiry_;
		barrier = barrier_;
		nReps = nReps_,
		generatePath();
}

//method definition
void EuropeanOption::generatePath(){
	double thisDrift = (r * expiry - 0.5 * vol * vol * expiry) / double(nInt);
	double cumShocks = 0;
	thisPath.clear();

	for(int i = 0; i < nInt; i++){
		cumShocks += (thisDrift + vol * sqrt(expiry / double(nInt)) * getOneGaussianByBoxMueller());
		thisPath.push_back(spot * exp(cumShocks));
	}
}

//method definition
void EuropeanOption::printPath(){

	for(int i = 0;  i < nInt; i++){

		std::cout << thisPath[i] << "\n";

	}

}

//method definition
double EuropeanOption::getDownAndOutCallPrice(int nReps){

	double rollingSum = 0.0;

	for (unsigned long i = 0; i < nReps; i++){
		generatePath();
	  double thisPayoff = thisPath.back() - strike;
	  double thisMinimum = *min_element(thisPath.begin(), thisPath.end());

	  thisPayoff = thisPayoff > 0 ? thisPayoff : 0;
	  thisPayoff = thisMinimum > barrier ? thisPayoff : 0;
	  rollingSum += thisPayoff;

	}

	return exp(-r*expiry)*rollingSum/double(nReps);

}

//overloaded operator ();
// double EuropeanOption::operator()(char char1, char char2, int nReps){
// 	if ((char1 == 'A') & (char2 =='C'))      return getArithmeticAsianCallPrice(nReps);
// 	else if ((char1 == 'A') & (char2 =='P')) return getArithmeticAsianPutPrice(nReps);
// 	else if ((char1 == 'G') & (char2 =='C')) return getGeometricAsianCallPrice(nReps);
// 	else if ((char1 == 'G') & (char2 =='P')) return getGeometricAsianPutPrice(nReps);
// 	else return -99;
// }
