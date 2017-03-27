#ifndef STRUCTURED_POINT_CLOUD_CHAIN_H
#define STRUCTURED_POINT_CLOUD_CHAIN_H

#include "nanomap_types.h"
#include "structured_point_cloud.h"


struct EdgeVertex {
	Matrix4f			 	edge;
	StructuredPointCloudPtr vertex;
};

class StructuredPointCloudChain {
  public:

  	NanoMapTime GetMostRecentCloudTime();
  	void DeleteMemoryBeforeTime(NanoMapTime delete_time);

  	void UpdateEdge(uint32_t index, Matrix4f relative_transform);
  	void AddNextEdgeVertex(Matrix4f new_edge, StructuredPointCloudPtr new_cloud);


  private:
	std::deque<EdgeVertex> chain;
};

#endif