/*
 * main.cpp
 *
 *  Created on: 24.06.2014
 *      Author: Paul
 *              Betim Musa <musab@informatik.uni-freiburg.de>
 */

#include "Grid.h"
#include "PhylSimModel.h"
#include "./RandomGen.h"
//#include "Utils/RandomGen.h"
//#include "Parameters.h"
#include "stdexcept"
#include "string"
#include "iostream"



int main(){
  unsigned int runs = 10000; // number of Generations
	bool neutral = false; // neutral model or not
	bool dd = true; // Density dependent or independent model
	bool env = false; // environmentally dependent or independent model
	bool mort = true; // mortality fitness
	bool repro = false; // reproductive fitness
	int dispersal = 3; // 1 = global dispersal, 2 = nearest neighbor dispersal, 3= kernel dispersal
	int xDim = 100; // Number of grid cells in x-direction
	int yDim = 100; // number of grid cells in y-direction
//	srand(1500);
	double specrate = 1.0;
	int densityCut = 2;
	int dispersalCut = 2;
	int mortalityStrength = 10;
	std:: string saveLoc = "C:/Users/Paul/Documents/GitHub/phylogeography/results/saveLocation";
	RandomGen ran;
	ran.seedrand(1000);
  
  double envStrength = 1.0;
  double compStrength = 1.0;
	// Just to test
	//Parameters* pa = new Parameters();
	//std::cout << "Value of numberOfRuns: " << pa->getParameterValue<int>(std::string("numberOfRuns")) << std::endl;

	// avoid inconsistent input
	if(neutral && dd) throw std::runtime_error("A neutral model can't be density dependent!");
	if(neutral && env) throw std::runtime_error("A neutral model can't be depending on the environment!");



	//Running the model
  
	PhylSimModel Model(xDim,yDim,dispersal, runs, specrate, dd, env, neutral, mort, 
  mortalityStrength, repro, dispersalCut, densityCut, saveLoc, envStrength, compStrength);   
  Model.update(runs);
//	Model.get_data();
//	Model.getclimate();
//	Model.gettraits();
	if(dispersal ==1)
	{
	Model.m_Global->m_Phylogeny.prunePhylogeny(runs);
	Model.m_Global->m_Phylogeny.writePhylogeny(1,  Model.m_Global->m_Phylogeny.m_PrunedPhylo,'P');
	Model.m_Global->m_Phylogeny.writePhylogeny(1,  Model.m_Global->m_Phylogeny.m_FullPhylogeny,'F');
	Model.m_Global->m_Phylogeny.writeSpeciesData();
	}
	else
	{
	Model.m_Local->m_Phylogeny.prunePhylogeny(runs);
	Model.m_Local->m_Phylogeny.writePhylogeny(1, Model.m_Local->m_Phylogeny.m_PrunedPhylo,'P');
	Model.m_Local->m_Phylogeny.writePhylogeny(1, Model.m_Local->m_Phylogeny.m_FullPhylogeny,'F');
	Model.m_Local->m_Phylogeny.writeSpeciesData();
	}

	return 0;
}

