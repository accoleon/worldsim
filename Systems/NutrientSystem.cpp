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
				world.nutrients[i].nutrientLevel++;
				if(world.nutrients[i].nutrientLevel > 100) {
					world.nutrients[i].nutrientLevel = 100;
				}
			}
		}
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
		nutrient_levels[index] -= reduction;
	}
	void NutrientSystem::increaseNutrient(int index, int addition){
		nutrient_levels[index] += addition;
	}
	
} /* gws */
