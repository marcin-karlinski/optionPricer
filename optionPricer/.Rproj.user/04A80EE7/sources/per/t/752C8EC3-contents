#include<Rcpp.h>
#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include"EuropeanOption.h"

using std::vector;
using std::cout;
using std::cin;
using namespace Rcpp;

// [[Rcpp::export]]
double downAndOut_europeanCallPrice(
	int nInt,
	double strike,
	double spot,
	double vol,
	double r,
	double expiry,
	double barrier,
	long int nReps
){

	// set the seed
	srand( time(NULL) );

	//create a new instance of class
	EuropeanOption myEuropean(nInt, strike, spot, vol, r, expiry, barrier, nReps);

	return myEuropean.getDownAndOutCallPrice(nReps);
}
