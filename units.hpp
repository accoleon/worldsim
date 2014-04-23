// units.hpp
// Basic SoA unit
// Xu Junjie, Kevin
// University of Oregon
// 2014-04-16
namespace gensim {
	struct units {
		char* rateOfGrowth;
		char* movementMechanism;
		short* movementMagnitude;
		short* rateOfMutation;
		char* defenseMechanism;
		short* defenseMagnitude;
		char* offenseMechanism;
		short* offenseMagnitude;
		short* waterIntake;
		short* oxygenIntake;
		short* waterOutput;
		short* oxygenOutput;
		short* co2Intake;
		short* co2Output;
	};
	
	void addAnimal();
	void addPlant();
	void removeUnit(int index);	
} /* gensim */
