// NutrientSystem.cpp
// 
// Cagle, Sam
// University of Oregon
// 2014-05-10

#include <iostream>
using std::cout;
using std::endl;
#include <string>

using std::string;
#include <map>
#include "NutrientSystem.h"

namespace gws {
	NutrientSystem::NutrientSystem(World& world) : world(world) {

	}
	NutrientSystem::~NutrientSystem() {}
	void NutrientSystem::Update() {
	}
	string NutrientSystem::getName() {
		return "NutrientSystem";
	}
	int NutrientSystem::getNutrient(int index){
		return nutrient_levels[index];
	}
	void NutrientSystem::setNutrient(int index, int set){
		nutrient_levels[index] = set;
	}
	int NutrientSystem::compareNutrient(int former, int latter){
		if(nutrient_levels[former] > nutrient_levels[latter]){
			return 1;
		}else if (nutrient_levels[former] == nutrient_levels[latter]){
			return 0;
		}else{
			return -1;
		}
	}
	void NutrientSystem::reduceNutrient(int index, int reduction){
		nutrient_levels[index] -= reduction;
	}
	void NutrientSystem::increaseNutrient(int index, int addition){
		nutrient_levels[index] += addition;
	}
	
} /* gws */