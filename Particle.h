#ifndef PARTICLE_H
#define PARTICLE_H
#include "sph_simulator.h"

class Particle
{
private:
	glm::vec3 force;
	glm::vec3 velocity;
    glm::vec3 position;
	glm::vec3 oldPosition;
	glm::vec3 color; //RGB

public:
	Particle()
	{
		clear();
	}

	Particle(glm::vec3 f, glm::vec3 v, glm::vec3 p)
	{
		force = f;
		velocity = v;
		position = p;
	}

	//Setters and getters
	glm::vec3 getForce() { return force; }
	glm::vec3 getVelocity() { return velocity; }
	glm::vec3 getPosition() { return position; }
	glm::vec3 getOldPosition() { return oldPosition; }
	glm::vec3 getColor() { return color; }

	void setForce(glm::vec3 f) { force = f; }
	void setVelocity(glm::vec3 v) { velocity = v; }
	void setPosition(glm::vec3 p) {
		position = p;
	}
	void setOldPosition(glm::vec3 p) { oldPosition = p; }
	void setColor(glm::vec3 c) { color = c; }

	//Important functions
	void clear()
	{
		force *= 0;
		velocity *= 0;
		position *= 0;
	}
	void clearForce() { force *= 0; }
	void clearVelocity() { velocity *= 0; }
	void clearPosition() { position *= 0; }
	void applyForce(glm::vec3 f) { this->force += f; }
};
#endif