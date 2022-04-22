# optionPricer
R package build in Rcpp for calculating the theoretical value of call options. Currently only European down-and-out call options supported. See optionPricer_script.R for more details on how to use the package.

Calculates Black-Scholes-Merton formula based on multiple Monte Carlo simulations. The main advantage are quick calculations thanks to the use of C++. 
Package can be installed with the command 

```
install.packages("optionPricer_0.1.0.tar.gz",
                 type = "source",
                 repos = NULL)
```
                 
downAndOut_europeanCallPrice() function takes the following arguments:

nInt- is the number of trading days to simulate until the maturity day,\
strike - strike price (price at which the asset can be bought),\
spot - current price of the underlying asset,\
vol - volatility of the underlying instrument,\
r - annualized risk-free rate,\
expiry - time to expiry,\
barrier - barrier level at which the call option is canceled,\
nReps - number of Monte Carlo simulations.\

Example: 

```
set.seed(123)\
optionPricer::downAndOut_europeanCallPrice(nInt = 126, \
                                           strike = 100, \
                                           spot = 105, \
                                           vol = 0.22, \
                                           r = 0.05, \
                                           expiry = 0.5, \
                                           barrier = 95, \
                                           nReps = 100000)\
```
                                           
 Based on the example from https://github.com/pawelsakowski/AF-RCPP-2021-2022. 
