#include <stdlib.h>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <EVENT/MCParticle.h>
#include <IMPL/MCParticleImpl.h>
#include <EVENT/LCCollection.h>
#include "DecayChain.hh"
#include "ConstantStorage.hh"
#include "MathOperator.hh"
#include <UTIL/PIDHandler.h>
#include <UTIL/LCRelationNavigator.h>

#ifndef _MCOperator_hh
#define _MCOperator_hh
namespace TTbarAnalysis 
{
	class MCOperator 
	{
		public:
		//
		//	Constants
		//
		
		//
		//	Constructors
		//
			MCOperator (EVENT::LCCollection * col, EVENT::LCCollection * rel);
			virtual ~MCOperator () {};
		//
		//	Methods
		//
			bool CheckProcessForPair(int pdg);
			bool IsReconstructed(EVENT::MCParticle * particle);
			std::vector< EVENT::MCParticle * > GetPairParticles(int pdg);
			std::vector< EVENT::MCParticle * > GetPairParticles(MESONS type);
			float GetAccuracy(EVENT::MCParticle * particle, float a, float b);
			DecayChain * Construct(std::string name, int pdg, std::vector<MESONS> typeOfProducts);
			bool CheckForUnification(EVENT::MCParticle * particle, int pdg);
			bool CheckParticle(EVENT::MCParticle * particle, MESONS type);
			std::vector< EVENT::MCParticle * > SelectDaughtersOfType(EVENT::MCParticle * parent, MESONS type);
			MESONS GetParticleType(EVENT::MCParticle * particle); 
			EVENT::MCParticle * FindExceptionalChild(EVENT::MCParticle * parent, MESONS parentType);
			EVENT::MCParticle * FindYoungestChild(EVENT::MCParticle * parent, MESONS type);
			bool CheckForColorString(EVENT::MCParticle * daughter, int pdgOfParent);
			EVENT::MCParticle * GetConsistentDaughter(EVENT::MCParticle * parent, EVENT::MCParticle * service, MESONS type);
			std::vector< EVENT::MCParticle * > SelectStableCloseDaughters(EVENT::MCParticle * parent,int excludePDG = 0, bool selectReco = false, std::vector<EVENT::MCParticle *> * misReconstructed = NULL);//
			bool CheckCompatibility(const std::vector< EVENT::MCParticle * > & daughters, EVENT::MCParticle * parent, int plusCharge = 0);
			DecayChain * RefineDecayChain(DecayChain * initial, std::vector<MESONS> typeOfProducts);
			std::vector< EVENT::MCParticle * > CheckDaughterVisibility(const std::vector< EVENT::MCParticle * > & daughters);
		private:
		//
		//	Data
		//
			EVENT::LCCollection * myCollection;
			EVENT::LCCollection * myRelCollection;
			double myPrimaryVertex[3];
			float myAngleCut;
			int myCurrentParentPDG;
		//
		//	Private methods
		//
			EVENT::MCParticle * cureDoubleCharmDecay(std::vector< EVENT::MCParticle * > & selected);
	};
} /* TTbarAnalysis */
#endif
