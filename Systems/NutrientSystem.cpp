// NutrientSystem.cpp
// 
// Cagle, Sam
// University of Oregon
// 2014-05-10

#include <cilk/cilk.h>
#include <iostream>
using std::cout;
using std::endl;
#include <string>

using std::string;
#include <map>
#include "NutrientSystem.h"
#include "../World.h"

namespace gws {
	NutrientSystem::NutrientSystem(World& world) : world(world) {

	}
	NutrientSystem::~NutrientSystem() {}
	void NutrientSystem::update() {
		auto end = world.nutrients.size();
		cilk_for (auto i = 0; i < end; ++i) {
			if(world.nutrients[i].active) {
				/* Update changes made by other systems */
				std::map<int,int>::iterator it = nutrient_levels.find(i);
				if(it != nutrient_levels.end()) {
					world.nutrients[i].nutrientLevel = getNutrient(i);
				}
				/* Increment all nutrients */
				world.nutrients[i].nutrientLevel++;
				/* Cap nutrient levels */
				if(world.nutrients[i].nutrientLevel > world.nutrients[i].max) {
					world.nutrients[i].nutrientLevel = 100;	
				}
			}
		}
		/* Clear map for next cycle of updates */
		nutrient_levels.clear();
	}
	string NutrientSystem::getName() {
		return "NutrientSystem";
	}
	SystemType NutrientSystem::getType() {
		return NutrientSys;
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
		nutrient_levels[index] = world.nutrients[index].nutrientLevel - reduction;
	}
	void NutrientSystem::increaseNutrient(int index, int addition){
		nutrient_levels[index] = world.nutrients[index].nutrientLevel + addition;
	}
	
} /* gws */
