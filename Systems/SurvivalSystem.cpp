// SurvivalSystem.cpp
// 
// Cagle, Sam
// University of Oregon
// 2014-05-10

#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include "SurvivalSystem.h"

namespace gws {
	SurvivalSystem::SurvivalSystem(World& world) : world(world) {

	}
	SurvivalSystem::~SurvivalSystem() {}
	void SurvivalSystem::Update(int index) {
		//Main AI controller for how each Entity will move throughout the World
		survival_type stype = survival_types[index];
		switch(stype){
			case EXPLORE:
				//EXPLORE entities will always seek out new resources instead of staying put
				//Riskier strategy
				
				
				//Pseduocode for how this strategy will look
				//if(nutrients immediately available in one of 8 nearby cells){
				//  Key point: Explores before finishing off resources
				//	go there
				//	consume nutrients
				//	
				//}else{
				//	pick one at random
				//}
				
				return;
			case STATIONARY:
				//STATIONARY entities will always consume existing resources before exploring to new ones
				//Note: will not breed.
				//Selfish but safe for that round
				
				//Pseduocode for how this strategy will look
				//if(nutrients(x, y) > 0){
				//	consume nutrient
				//}else{
				//	if nutrients are immediately available in one of the 8 nearby cells{
				//		go there
				//	}else{
				//		pick one at random
				//	}
				//}
				return;
			case BREED:
				//BREED entities will always consume existing resrouces before exploring to new ones
				//Differs from STATIONARY in that they will also reproduce with no regard to how many nutrients are available to them
				//Unselfish, unsafe. Extra entities will consume resources faster leading to a quicker death
				
				//if(can breed){
				//	breed
				//}else{
				//	//if(nutrients(x, y) > 0){
				//	//	consume nutrient
				//	//}else{
				//	//	if nutrients are immediately available in one of the 8 nearby cells{
				//	//		go there
				//	//	}else{
				//	//		pick one at random
				//	//	}
				//	//}
				//}
				return;
			case NORTH:
				//NORTH entities will always go as far north as they can.
				return;
			case EAST:
				//EAST entities will always go as far north as they can.
				return;
			case SOUTH:
				//SOUTH entities will always go as far north as they can.
				return;
			case WEST:
				//WEST entities will always go as far north as they can.
				return;
		}
	}
	string SurvivalSystem::getName() {
		return "SurvivalSystem";
	}
	void SurvivalSystem::setSurvivalType(int index, survival_type new_type){
		survival_types[index] = new_type;
	}
	string SurvivalSystem::getSurvivalType(int index){
		survival_type stype = survival_types[index];
		switch(stype){
			case EXPLORE:
				return "EXPLORE";
			case STATIONARY:
				return "STATIONARY";
			case BREED:
				return "BREED";
			case NORTH:
				return "NORTH";
			case EAST:
				return "EAST";
			case SOUTH:
				return "SOUTH";
			case WEST:
				return "WEST";
		}
		return "ERROR: no type for given index specified";
	}
} /* gws */