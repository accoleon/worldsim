// SurvivalSystem.cpp
// 
// Cagle, Sam
// University of Oregon
// 2014-05-10

#include <iostream>
using std::cout;
using std::endl;
#include <string>
#include <stdlib.h>
#include <time.h>
using std::string;
#include "SurvivalSystem.h"
#include "../World.h"

namespace gws {
	SurvivalSystem::SurvivalSystem(World& world) : world(world) {

	}
	SurvivalSystem::~SurvivalSystem() {}
	void SurvivalSystem::update() {
		//Main AI controller for how each Entity will move throughout the World
		// KX: I suggest using index-based looping, e.g.
		auto end = world.survivors.size();
		// every iteration checks the var instead of calling a function
		for(auto i = 0; i < end; ++i){
			// KX: Have to rethink your current implementation in stencil form
			
			//Get this entity's positions
			//We are guaranteed that the ID in the positions vector will be the same ID in the survivals vector
			survival_type stype = world.survivors[i].getSType();
			PositionComponent* this_pos = &(world.positions[i]);
			PositionComponent* north;
			PositionComponent* northeast;
			PositionComponent* east;
			PositionComponent* southeast;
			PositionComponent* south;
			PositionComponent* southwest;
			PositionComponent* west;
			PositionComponent* northeast;
			//tbb::concurrent_vector<PositionComponent*>::iterator (*pos_iter);
			for(auto pos_iter = world.positions.cbegin(); pos_iter != world.positions.cend(); pos_iter++){
				//Get the 9 positions needed
				if( pos_iter->x == this_pos->x && pos_iter->y == (this_pos->y)+1 ){
					north = (*pos_iter);
				}else if( pos_iter->x == (this_pos->x)+1 && pos_iter->y == (this_pos->y)+1){
					northeast = (*pos_iter);
				}else if( pos_iter->x == (this_pos->x)+1 && pos_iter->y == (this_pos->y)){
					east = (*pos_iter);
				}else if( pos_iter->x == (this_pos->x)+1 && pos_iter->y == (this_pos->y)-1){
					southeast = (*pos_iter);
				}else if( pos_iter->x == (this_pos->x) && pos_iter->y == (this_pos->y)-1){
					south = (*pos_iter);
				}else if( pos_iter->x == (this_pos->x)-1 && pos_iter->y == (this_pos->y)-1){
					southwest = (*pos_iter);
				}else if( pos_iter->x == (this_pos->x)+1 && pos_iter->y == (this_pos->y)){
					west = (*pos_iter);
				}else if( pos_iter->x == (this_pos->x)-1 && pos_iter->y == (this_pos->y)+1){
					northeast = (*pos_iter);
				}
			}
			int nutrientReq = world.nutrients[start_id].nutrientLevel;
			int waterReq    = world.waters[start_id].waterLevel;
			switch(stype){
				case EXPLORE:
					//EXPLORE entities will always seek out new resources instead of staying put
					//Riskier strategy
					//Try random directions first					
					if(tryRandom(i) == -1){
						//Then try clockwise
						if(tryClockwise(i) == -1){
							//Organism dies
							death_array[this_pos->ID] = 0;
						}
					}
				case STATIONARY:
					//STATIONARY entities will always consume existing resources before exploring to new ones
					//Note: will not breed.
					//Selfish but safe for that round
					
					if(world.nutrients[this_pos->ID].nutrientLevel > nutrientReq && world.waters[this_pos->ID].waterLevel > waterReq){
						//Consume current position before attempting to move
						world.nutrients[this_pos->ID].nutrientLevel = world.nutrients[this_pos->ID].nutrientLevel - nutrientReq;
						world.waters[this_pos->ID].waterLevel = world.waters[this_pos->ID].waterLevel - waterReq;
					}else{
						//Move after the current resources are dried up
						if(tryRandom(i) == -1){
							if(tryClockwise(i) == -1){
								death_array[this_pos->ID] = 0; 
							}
						}
					}
				case NORTH:
					//NORTH entities will always go as far north as they can.
					if(world.nutrients[north->ID].nutrientLevel > nutrientReq && world.waters[north->ID].waterLevel > waterReq){
						//First case
						//Attempt to go north, and then consume the nutrients/water there if possible
						north->ID = i; //Write the new position
						this_pos->ID = 0; //Set the old position to be empty
						world.nutrients[north->ID].nutrientLevel = world.nutrients[north->ID].nutrientLevel - nutrientReq;
						world.waters[north->ID].waterLevel = world.waters[north->ID].waterLevel - waterReq;
					}else if(world.nutrients[this_pos->ID].nutrientLevel > nutrientReq && world.waters[this_pos->ID].waterLevel > waterReq){
						//Consume current position after attempting to move
						world.nutrients[this_pos->ID].nutrientLevel = world.nutrients[this_pos->ID].nutrientLevel - nutrientReq;
						world.waters[this_pos->ID].waterLevel = world.waters[this_pos->ID].waterLevel - waterReq;
					}else{
						//If there are no nutrients
						//Organism dies 
						death_array[this_pos->ID] = 0; 
					}
				case EAST:
					//EAST entities will always go as far east as they can.
					if(world.nutrients[east->ID].nutrientLevel > nutrientReq && world.waters[east->ID].waterLevel > waterReq){
						east->ID = i; //Write the new position
						this_pos->ID = 0; //Set the old position to be empty
						world.nutrients[east->ID].nutrientLevel = world.nutrients[east->ID].nutrientLevel - nutrientReq;
						world.waters[east->ID].waterLevel = world.waters[east->ID].waterLevel - waterReq;
					}else if(world.nutrients[this_pos->ID].nutrientLevel > nutrientReq && world.waters[this_pos->ID].waterLevel > waterReq){
						//Consume current position after attempting to move
						world.nutrients[this_pos->ID].nutrientLevel = world.nutrients[this_pos->ID].nutrientLevel - nutrientReq;
						world.waters[this_pos->ID].waterLevel = world.waters[this_pos->ID].waterLevel - waterReq;
					}else{
						//If there are no nutrients
						//Organism dies 
						death_array[this_pos->ID] = 0; 
					}
				case SOUTH:
					//SOUTH entities will always go as far south as they can.
					if(world.nutrients[south->ID].nutrientLevel > nutrientReq && world.waters[south->ID].waterLevel > waterReq){
						//South
						south->ID = i;
						this_pos->ID = 0;
						world.nutrients[south->ID].nutrientLevel = world.nutrients[south->ID].nutrientLevel - nutrientReq;
						world.waters[south->ID].waterLevel = world.waters[south->ID].waterLevel - waterReq;
					}else if(world.nutrients[this_pos->ID].nutrientLevel > nutrientReq && world.waters[this_pos->ID].waterLevel > waterReq){
						//Consume current position after attempting to move
						world.nutrients[this_pos->ID].nutrientLevel = world.nutrients[this_pos->ID].nutrientLevel - nutrientReq;
						world.waters[this_pos->ID].waterLevel = world.waters[this_pos->ID].waterLevel - waterReq;
					}else{
						//If there are no nutrients
						//Organism dies 
						death_array[this_pos->ID] = 0; 
					}
				case WEST:
					//WEST entities will always go as far west as they can.
					if(world.nutrients[west->ID].nutrientLevel > nutrientReq && world.waters[west->ID].waterLevel > waterReq){
						//West
						west->ID = i;
						this_pos->ID = 0;
						world.nutrients[west->ID].nutrientLevel = world.nutrients[west->ID].nutrientLevel - nutrientReq;
						world.waters[west->ID].waterLevel = world.waters[west->ID].waterLevel - waterReq;
					}else if(world.nutrients[this_pos->ID].nutrientLevel > nutrientReq && world.waters[this_pos->ID].waterLevel > waterReq){
						//Consume current position after attempting to move
						world.nutrients[this_pos->ID].nutrientLevel = world.nutrients[this_pos->ID].nutrientLevel - nutrientReq;
						world.waters[this_pos->ID].waterLevel = world.waters[this_pos->ID].waterLevel - waterReq;
					}else{
						//If there are no nutrients
						//Organism dies 
						death_array[this_pos->ID] = 0; 
					}
				default:
					//Should never hit this case
					//Means that the organism didn't have an AI type
					return -1;
			}
		}
	}
	
	int SurvivalSystem::tryRandom(int start_id){
		
		survival_type stype = world.survivors[start_id].getSType();
		PositionComponent* this_pos = &(world.positions[start_id]);
		PositionComponent* north;
		PositionComponent* northeast;
		PositionComponent* east;
		PositionComponent* southeast;
		PositionComponent* south;
		PositionComponent* southwest;
		PositionComponent* west;
		PositionComponent* northeast;
		//tbb::concurrent_vector<PositionComponent*>::iterator (*pos_iter);
		for(auto pos_iter = world.positions.cbegin(); pos_iter != world.positions.cend(); pos_iter++){
			//Get the 9 positions needed
			if( pos_iter->x == this_pos->x && pos_iter->y == (this_pos->y)+1 ){
				north = (*pos_iter);
			}else if( pos_iter->x == (this_pos->x)+1 && pos_iter->y == (this_pos->y)+1){
				northeast = (*pos_iter);
			}else if( pos_iter->x == (this_pos->x)+1 && pos_iter->y == (this_pos->y)){
				east = (*pos_iter);
			}else if( pos_iter->x == (this_pos->x)+1 && pos_iter->y == (this_pos->y)-1){
				southeast = (*pos_iter);
			}else if( pos_iter->x == (this_pos->x) && pos_iter->y == (this_pos->y)-1){
				south = (*pos_iter);
			}else if( pos_iter->x == (this_pos->x)-1 && pos_iter->y == (this_pos->y)-1){
				southwest = (*pos_iter);
			}else if( pos_iter->x == (this_pos->x)+1 && pos_iter->y == (this_pos->y)){
				west = (*pos_iter);
			}else if( pos_iter->x == (this_pos->x)-1 && pos_iter->y == (this_pos->y)+1){
				northeast = (*pos_iter);
			}
		}
		int nutrientReq = world.nutrients[start_id].nutrientLevel;
		int waterReq    = world.waters[start_id].waterLevel;
		
		srand(time(NULL));
		int random_dir = rand() % 9 + 1; //Get a random direction from 1 through 8
		
		//Try a random direction first, then go clockwise starting from north 
		if(random_dir == 1)
			if(world.nutrients[north->ID].nutrientLevel > nutrientReq && world.waters[north->ID].waterLevel > waterReq){
				//First case
				//Attempt to go north, and then consume the nutrients/water there if possible
				north->ID = start_id; //Write the new position
				this_pos->ID = 0; //Set the old position to be empty
				world.nutrients[north->ID].nutrientLevel = world.nutrients[north->ID].nutrientLevel - nutrientReq;
				world.waters[north->ID].waterLevel = world.waters[north->ID].waterLevel - waterReq;
				return 0;
			}
		}else if(random_dir == 2){
			if(world.nutrients[northeast->ID].nutrientLevel > nutrientReq && world.waters[northeast->ID].waterLevel > waterReq){
				//Northeast
				northeast->ID = start_id;
				this_pos->ID = 0;
				world.nutrients[northeast->ID].nutrientLevel = world.nutrients[northeast->ID].nutrientLevel - nutrientReq;
				world.waters[northeast->ID].waterLevel = world.waters[northeast->ID].waterLevel - waterReq;
				return 0;
			}
		}else if(random_dir == 3){
			if(world.nutrients[east->ID].nutrientLevel > nutrientReq && world.waters[east->ID].waterLevel > waterReq){
				//East
				east->ID = start_id;
				this_pos->ID = 0;
				world.nutrients[east->ID].nutrientLevel = world.nutrients[east->ID].nutrientLevel - nutrientReq;
				world.waters[east->ID].waterLevel = world.waters[east->ID].waterLevel - waterReq;
				return 0;
			}
		}else if(random_dir == 4){
			if(world.nutrients[southeast->ID].nutrientLevel > nutrientReq && world.waters[southeast->ID].waterLevel > waterReq){
				//Southeast
				southeast->ID = start_id;
				this_pos->ID = 0;
				world.nutrients[southeast->ID].nutrientLevel = world.nutrients[southeast->ID].nutrientLevel - nutrientReq;
				world.waters[southeast->ID].waterLevel = world.waters[southeast->ID].waterLevel - waterReq;
			}
		}else if(random_dir == 5){
			if(world.nutrients[south->ID].nutrientLevel > nutrientReq && world.waters[south->ID].waterLevel > waterReq){
				//South
				south->ID = start_id;
				this_pos->ID = 0;
				world.nutrients[south->ID].nutrientLevel = world.nutrients[south->ID].nutrientLevel - nutrientReq;
				world.waters[south->ID].waterLevel = world.waters[south->ID].waterLevel - waterReq;
				return 0;
			}
		}else if(random_dir == 6){
			if(world.nutrients[southwest->ID].nutrientLevel > nutrientReq && world.waters[southwest->ID].waterLevel > waterReq){
				//Southwest
				southwest->ID = start_id;
				this_pos->ID = 0;
				world.nutrients[southwest->ID].nutrientLevel = world.nutrients[southwest->ID].nutrientLevel - nutrientReq;
				world.waters[southwest->ID].waterLevel = world.waters[southwest->ID].waterLevel - waterReq;
				return 0;
			}
		}else if(random_dir == 7){
			if(world.nutrients[west->ID].nutrientLevel > nutrientReq && world.waters[west->ID].waterLevel > waterReq){
				//West
				west->ID = start_id;
				this_pos->ID = 0;
				world.nutrients[west->ID].nutrientLevel = world.nutrients[west->ID].nutrientLevel - nutrientReq;
				world.waters[west->ID].waterLevel = world.waters[west->ID].waterLevel - waterReq;
				return 0;
			}
		}else if(random_dir == 8){
			if(world.nutrients[northwest->ID].nutrientLevel > nutrientReq && world.waters[northwest->ID].waterLevel > waterReq){
				//Northwest
				northwest->ID = start_id;
				this_pos->ID = 0;
				world.nutrients[northwest->ID].nutrientLevel = world.nutrients[northwest->ID].nutrientLevel - nutrientReq;
				world.waters[northwest->ID].waterLevel = world.waters[northwest->ID].waterLevel - waterReq;
				return 0;
			}
		}
		return -1;
	}
	
	int SurvivalSystem::tryClockwise(int start_id){
		survival_type stype = world.survivors[start_id].getSType();
		PositionComponent* this_pos = &(world.positions[start_id]);
		PositionComponent* north;
		PositionComponent* northeast;
		PositionComponent* east;
		PositionComponent* southeast;
		PositionComponent* south;
		PositionComponent* southwest;
		PositionComponent* west;
		PositionComponent* northwest;
		//tbb::concurrent_vector<PositionComponent*>::iterator (*pos_iter);
		for(auto pos_iter = world.positions.cbegin(); pos_iter != world.positions.cend(); pos_iter++){
			//Get the 9 positions needed
			if( pos_iter->x == this_pos->x && pos_iter->y == (this_pos->y)+1 ){
				north = (*pos_iter);
			}else if( pos_iter->x == (this_pos->x)+1 && pos_iter->y == (this_pos->y)+1){
				northeast = (*pos_iter);
			}else if( pos_iter->x == (this_pos->x)+1 && pos_iter->y == (this_pos->y)){
				east = (*pos_iter);
			}else if( pos_iter->x == (this_pos->x)+1 && pos_iter->y == (this_pos->y)-1){
				southeast = (*pos_iter);
			}else if( pos_iter->x == (this_pos->x) && pos_iter->y == (this_pos->y)-1){
				south = (*pos_iter);
			}else if( pos_iter->x == (this_pos->x)-1 && pos_iter->y == (this_pos->y)-1){
				southwest = (*pos_iter);
			}else if( pos_iter->x == (this_pos->x)+1 && pos_iter->y == (this_pos->y)){
				west = (*pos_iter);
			}else if( pos_iter->x == (this_pos->x)-1 && pos_iter->y == (this_pos->y)+1){
				northwest = (*pos_iter);
			}
		}
		int nutrientReq = world.nutrients[start_id].nutrientLevel;
		int waterReq    = world.waters[start_id].waterLevel;
		
		if(world.nutrients[north->ID].nutrientLevel > nutrientReq && world.waters[north->ID].waterLevel > waterReq){
			//First case
			//Attempt to go north, and then consume the nutrients/water there if possible
			north->ID = start_id; //Write the new position
			this_pos->ID = 0; //Set the old position to be empty
			world.nutrients[north->ID].nutrientLevel = world.nutrients[north->ID].nutrientLevel - nutrientReq;
			world.waters[north->ID].waterLevel = world.waters[north->ID].waterLevel - waterReq;
			return 0;
		}else if(world.nutrients[northeast->ID].nutrientLevel > nutrientReq && world.waters[northeast->ID].waterLevel > waterReq){
			//Northeast
			northeast->ID = start_id;
			this_pos->ID = 0;
			world.nutrients[northeast->ID].nutrientLevel = world.nutrients[northeast->ID].nutrientLevel - nutrientReq;
			world.waters[northeast->ID].waterLevel = world.waters[northeast->ID].waterLevel - waterReq;
			return 0;
		}else if(world.nutrients[east->ID].nutrientLevel > nutrientReq && world.waters[east->ID].waterLevel > waterReq){
			//East
			east->ID = start_id;
			this_pos->ID = 0;
			world.nutrients[east->ID].nutrientLevel = world.nutrients[east->ID].nutrientLevel - nutrientReq;
			world.waters[east->ID].waterLevel = world.waters[east->ID].waterLevel - waterReq;
			return 0;
		}else if(world.nutrients[southeast->ID].nutrientLevel > nutrientReq && world.waters[southeast->ID].waterLevel > waterReq){
			//Southeast
			southeast->ID = start_id;
			this_pos->ID = 0;
			world.nutrients[southeast->ID].nutrientLevel = world.nutrients[southeast->ID].nutrientLevel - nutrientReq;
			world.waters[southeast->ID].waterLevel = world.waters[southeast->ID].waterLevel - waterReq;
			return 0;
		}else if(world.nutrients[south->ID].nutrientLevel > nutrientReq && world.waters[south->ID].waterLevel > waterReq){
			//South
			south->ID = start_id;
			this_pos->ID = 0;
			world.nutrients[south->ID].nutrientLevel = world.nutrients[south->ID].nutrientLevel - nutrientReq;
			world.waters[south->ID].waterLevel = world.waters[south->ID].waterLevel - waterReq;
			return 0;
		}else if(world.nutrients[southwest->ID].nutrientLevel > nutrientReq && world.waters[southwest->ID].waterLevel > waterReq){
			//Southwest
			southwest->ID = start_id;
			this_pos->ID = 0;
			world.nutrients[southwest->ID].nutrientLevel = world.nutrients[southwest->ID].nutrientLevel - nutrientReq;
			world.waters[southwest->ID].waterLevel = world.waters[southwest->ID].waterLevel - waterReq;
			return 0;
		}else if(world.nutrients[west->ID].nutrientLevel > nutrientReq && world.waters[west->ID].waterLevel > waterReq){
			//West
			west->ID = start_id;
			this_pos->ID = 0;
			world.nutrients[west->ID].nutrientLevel = world.nutrients[west->ID].nutrientLevel - nutrientReq;
			world.waters[west->ID].waterLevel = world.waters[west->ID].waterLevel - waterReq;
			return 0;
		}else if(world.nutrients[northwest->ID].nutrientLevel > nutrientReq && world.waters[northwest->ID].waterLevel > waterReq){
			//Northwest
			northwest->ID = start_id;
			this_pos->ID = 0;
			world.nutrients[northwest->ID].nutrientLevel = world.nutrients[northwest->ID].nutrientLevel - nutrientReq;
			world.waters[northwest->ID].waterLevel = world.waters[northwest->ID].waterLevel - waterReq;
			return 0;
		}else if(world.nutrients[this_pos->ID].nutrientLevel > nutrientReq && world.waters[this_pos->ID].waterLevel > waterReq){
			//If there are no available nutrients elsewhere, consume the current position
			world.nutrients[this_pos->ID].nutrientLevel = world.nutrients[this_pos->ID].nutrientLevel - nutrientReq;
			world.waters[this_pos->ID].waterLevel = world.waters[this_pos->ID].waterLevel - waterReq;;
			return 0;
		}else{
			//Unsuccessful
			return -1;
		}
		return -1;
	}
	
	string SurvivalSystem::getName() {
		return "SurvivalSystem";
	}
	SystemType SurvivalSystem::getType() {
		return SurvivalSys;
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