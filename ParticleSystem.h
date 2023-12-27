#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H
#include "sph_simulator.h"
#include "Particle.h"
#include <vector>
#include <random>
#include <stdlib.h>

class ParticleSystem
{
public:
	float dt;
	int noPt; // Number Of Particles
	std::vector<Particle> particleList;
    glm::vec3 gravity;
	float commonMass;
	float kinEn;
	float potEn;

	float worldColldConst;
	glm::vec3 world;
	glm::vec3 halfWorld;

	ParticleSystem(int numParticles, float stepsize);
	void initializeParticles();
	virtual void timestep(Particle& p);
	virtual void simulate();
	void clearForces();
	virtual void applyForces();
	void destroyParticles();
	void solveWorldCollision();
    ~ParticleSystem();
};

inline float random_float();

#endif