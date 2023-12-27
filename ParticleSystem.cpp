
#define SIGN(x) (x >= 0 ? 1.0 : -1.0)
#include "ParticleSystem.h"
#include <iostream>

ParticleSystem::ParticleSystem(int numParticles, float h)
{
    particleList.clear();
    noPt = numParticles;
    commonMass = 1.0f;
    dt = h;

    world = glm::vec3(20.0f, 20.0f, 20.0f);
    gravity = glm::vec3(0.0f, -9.81f, 0.0f);
    halfWorld = world * 0.5f;

    worldColldConst = 0.5f;

    initializeParticles();
}

void ParticleSystem::initializeParticles()
{
	for (int i = 0; i < noPt; i++)
	{
		Particle particle;
		
		particle.clearForce();

		particle.setColor(glm::vec3(0, 0, 255));

		particle.setPosition(glm::vec3(halfWorld.x*random_float(), halfWorld.y*random_float(),
				halfWorld.z*random_float()));

		particleList.push_back(particle);
	}
}

void ParticleSystem::simulate()
{
    clearForces();
    applyForces();


    solveWorldCollision();

    for (auto& p : particleList)
    {
        timestep(p);
    }
}

void ParticleSystem::timestep(Particle& p)
{
	glm::vec3 curPos = p.getPosition();
	glm::vec3 curVel = p.getVelocity();
	glm::vec3 curForce = p.getForce();

	
	// Assume mass = 1
	glm::vec3 newVel = curVel + curForce*(dt/commonMass);
	glm::vec3 newPos = curPos + newVel*dt;

	p.setPosition(newPos);
	p.setVelocity(newVel);
}

void ParticleSystem::clearForces()
{
	for (auto& p : particleList)
		p.clearForce();
}

void ParticleSystem::destroyParticles()
{
	particleList.clear();
}

void ParticleSystem::solveWorldCollision()
{
	glm::vec3 tempVel;
	glm::vec3 tempPos;
	glm::vec3 tempPos2;
	for (auto& p : particleList)
	{
		tempVel = p.getVelocity();
		tempPos = p.getPosition();
		tempPos2 = p.getPosition();

		if (p.getPosition().x <= -halfWorld.x || p.getPosition().x >= halfWorld.x)
		{
			tempVel.x = tempVel.x * -worldColldConst;
			tempPos.x = SIGN(tempPos.x) * halfWorld.x;
		}

		if (p.getPosition().y <= -halfWorld.y || p.getPosition().y >= halfWorld.y)
		{
			tempVel.y = tempVel.y * -worldColldConst;
			tempPos.y = SIGN(tempPos.y) * halfWorld.y;
		}

		if (p.getPosition().z <= -halfWorld.z || p.getPosition().z >= halfWorld.z)
		{
			p.setOldPosition(tempPos2);
			tempVel.z = tempVel.z * -worldColldConst;
			tempPos.z = SIGN(tempPos.z) * halfWorld.z;
		}

		p.setVelocity(tempVel);
		p.setPosition(tempPos);
	}
}

ParticleSystem::~ParticleSystem()
{
    destroyParticles();
}

void ParticleSystem::applyForces()
{
    for (auto& p : particleList) {
        p.applyForce(gravity * commonMass);
    }
}

inline float random_float()
{
	static std::random_device rd;
	static std::uniform_real_distribution<float> distribution(-0.9f, 0.9f);
	static std::mt19937 generator{rd()};
	return distribution(generator);
}