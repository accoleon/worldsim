#Genetic World Simulator


World Simulation Visualization with mutating organisms, based on an 
Entity-Component Architecture and data/task parallelism.

##Install/Prerequisites
[SDL 2.0.3](http://www.libsdl.org/download-2.0.php)

[OpenGL 3.3](http://www.opengl.org)

[GLEW](http://www.glew.sourceforge.net)

[Intel C++ Studio XE 2013 for Linux](https://registrationcenter.intel.com/RegCenter/NComForm.aspx?ProductID=1534&pass=yes)

##Get/Build
	git clone https://github.com/accoleon/worldsim
	make

##Run
	./worldsim integer
	integer is the number of entities of each type created. Note: anything past 100000 creates slowdown on most standard hardware
	ALWAYS INCLUDE AN INTEGER ARGUMENT, RESULTS IN UNDEFINED BEHAVIOR ELSEWHERE WITHOUT ONE

##References
[SFML 2.1 Tutorials](http://www.sfml-dev.org/tutorials/2.1/)
