require(PhylGeo)

# SET WD TO SOURCE FILE LOCATION !!!!

modes <- c(rep("global",4), rep("local",16))
scenarios <- paste(modesDists, rep(c("Envi", "Neut", "Dens", "Hybr"),4), sep = "")

runs = round(seq(250, 300, len = 10))

dispOptions = 4
fitOptions = 7

dispersal =  rep(c(0,0.5, 2,4), each = fitOptions)
density = rep(c(0,seq(0,1,len = fitOptions-2),1),dispOptions)
environment = rep(c(0,seq(1,0,len = fitOptions-2),1),dispOptions)

pars <- list()

for (i in 1:20){pars[[i]] = createCompletePar(x = 100,y = 100, runs = runs, modes = modes[i],scenario = scenarios[i], dispersal = dispersal[i],specRate = 1,density = density[i],environment = environment[i], fitnessBaseMortalityRatio = 5, densityCut = 1,seed = 1000)}


system.time(simulationOut <- fullModBatch(pars, parallel = T)) 

save(simulationOut, pars, file = "results100x100.Rdata" )
