#ifndef COMPUTE_MATERIAL_HPP
#define COMPUTE_MATERIAL_HPP

#include <graphics/material.hpp>

class ComputeMaterial: public Material {
public:
  ComputeMaterial();
  virtual ~ComputeMaterial();

  void Dispatch(bool async = false);
  void SetWorkGroups(unsigned int groupsX,
                     unsigned int groupsY, 
                     unsigned int groupsZ);

private:
  unsigned int _groupsX, _groupsY, _groupsZ;
  bool CheckWorkGroups(unsigned int groupsX,
                       unsigned int groupsY, 
                       unsigned int groupsZ);
  bool CheckWorkGroup(unsigned int size, int axis);
};

#endif