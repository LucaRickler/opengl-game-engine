#ifndef MOONBEAM_GRAPHIC_SYSTEM_HPP
#define MOONBEAM_GRAPHIC_SYSTEM_HPP

#include <dependencies.hpp>
#include <core/system.hpp>

class GraphicSystem : public System {
public:
  GraphicSystem();
  virtual ~GraphicSystem();

  virtual void PreUpdate();
  virtual void Update();
  virtual void PostUpdate();
};

#endif