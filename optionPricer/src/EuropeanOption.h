#include<vector>

class EuropeanOption{
public:

	//constructor
	EuropeanOption(
		int nInt_,
		double strike_,
		double spot_,
		double vol_,
		double r_,
		double barrier_,
		double expiry_,
		long int nReps_
		);

	//destructor
	~EuropeanOption(){};

	//methods
	void generatePath();
	void printPath();
	double getDownAndOutCallPrice(int nReps);
	// double operator()(char char1, char char2, int nReps);
	
	//members
	std::vector<double> thisPath;
	int nInt;
	double strike;
	double spot;
	double vol;
	double r;
	double barrier;
	double expiry;
	long int nReps;

};
