# Generated by using Rcpp::compileAttributes() -> do not edit by hand
# Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

downAndOut_europeanCallPrice <- function(nInt, strike, spot, vol, r, expiry, barrier, nReps) {
    .Call(`_optionPricer_downAndOut_europeanCallPrice`, nInt, strike, spot, vol, r, expiry, barrier, nReps)
}

rcpp_hello <- function() {
    .Call(`_optionPricer_rcpp_hello`)
}

