#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>
#include <ros/ros.h>
#include <ros/console.h>
#include <Eigen/Dense>
#include <Eigen/Eigen>
#include <Eigen/Core>
#include <Eigen/Dense>
using Eigen::Vector3d;
#include "backward.hpp"



#define inf 1>>20
struct MappingNode;
typedef MappingNode* MappingNodePtr;

struct MappingNode
{     
    int id;        // 1--> open set, -1 --> closed set
    Eigen::Vector3d coord; 
    Eigen::Vector3i dir;   // direction of expanding
    Eigen::Vector3i index;

    Vector3d velocity; // 添加速度
    double time;       // 添加时间

    double g_score, f_score;
    MappingNodePtr Father;
    std::multimap<double, MappingNodePtr>::iterator nodeMapIt;

    MappingNode(Eigen::Vector3i _index, Eigen::Vector3d _coord){  
		id = 0;
		index = _index;
		coord = _coord;
		dir   = Eigen::Vector3i::Zero();

    velocity = Vector3d::Zero();
    time = 0.0;

		g_score = inf;
		f_score = inf;
		Father = NULL;
    }

    MappingNode(){};
    ~MappingNode(){};
};


#endif
