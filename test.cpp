#include <librealsense2/rs.hpp> // Include RealSense Cross Platform API

// Create a Pipeline - this serves as a top-level API for streaming and processing frames
rs2::pipeline p;

// Configure and start the pipeline
p.start();
