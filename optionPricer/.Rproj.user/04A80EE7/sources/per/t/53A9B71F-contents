install.packages("C:/Users/marci/Desktop/UW/III Semester/applied_finance/optionPricer_package/optionPricer_0.1.0.tar.gz",
                 type = "source",
                 repos = NULL)

remove.packages("optionPricer")
detach("package::optionPricer", unload = T)

optionPricer::downAndOut_europeanCallPrice(nInt = 126, strike = 100, spot = 105, vol = 0.22, r = 0.05, expiry = 0.5, barrier = 95, nReps = 1000)
