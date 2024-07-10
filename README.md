# sph: Smoothed Particle Hydrodynamics (SPH) Fluid Simulation

This project implements a fluid simulation using the Smoothed Particle Hydrodynamics (SPH) method, specifically focusing on the Density-Filtered SPH (DFSSPH) approach. It provides a framework for simulating fluid behavior by representing the fluid as a collection of particles that interact with each other.

## Features

- **DFSSPH Fluid Simulation**: Implements the DFSSPH algorithm for realistic fluid behavior.
- **Particle System Management**: Manages particle data structures efficiently using container classes.
- **Particle Properties**: Tracks essential fluid particle properties like position, velocity, and density.
- **Force Calculations**: Calculates forces acting on particles for fluid motion.
- **Neighbor Search**: Identifies neighboring particles for inter-particle interactions.
- **Visualization (Optional)**: Renders the simulated fluid using shaders (potentially OpenGL or Vulkan).
- **User Interface (Optional)**: Integrates ImGui for potential user interaction and visualization control (if implemented).

## Project Structure

### Core Data Structures
- `Container.h` & `Container.cpp`: Define container classes for efficient particle data management.
- `Particle.h`: Defines the structure of a fluid particle with its properties.

### Simulation Engine
- `ParticleSystem.h` & `ParticleSystem.cpp`: Handle core SPH functionalities like particle updates, force calculations, and neighbor searches.
- `sph_simulator.h` & `sph_simulator-DFSSPH`: Implement the DFSSPH algorithm for fluid simulation.

### Graphics & User Interface (Optional)
- `Shader.h`: Defines shaders for rendering particles (if implemented).
- `imgui` folder: Contains code for integrating the ImGui library for UI (if implemented).
- `ParticleRenderer.h`: Manages particle rendering using shaders (if implemented).

### Build System
- `Makefile`: Provides instructions for compiling the project code.

## Getting Started

1. Clone or download the project repository.
2. Ensure you have the necessary dependencies installed (check code for specific libraries).
3. Refer to the `Makefile` for build instructions.
4. Explore the codebase and comments for a deeper understanding of the implementation details.

> **Note**: The visualization and user interface functionalities might be optional based on the project's current state. Refer to the code for confirmation.
