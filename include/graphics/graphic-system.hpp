#ifndef MOONBEAM_GRAPHIC_SYSTEM_HPP
#define MOONBEAM_GRAPHIC_SYSTEM_HPP

#include <dependencies.hpp>
#include <core/system.hpp>
#include <graphics/uniform-buffer.hpp>

class GraphicSystem : public System {
public:
  GraphicSystem();
  ~GraphicSystem() override;

  void SetMainCamera(Camera* cam);
  Camera* GetMainCamera() const;

  DrawShader* LoadDrawShader(const std::string& name, const char* vertexPath, const char* fragmentPath);
  DrawShader* GetDrawShader(const std::string& name);
  void DestroyDrawShader(const std::string& name);

  ComputeShader* LoadComputeShader(const std::string& name, const std::string& filepath);
  ComputeShader* GetComputeShader(const std::string& name);
  void DestroyComputeShader(const std::string& name);

  Texture2D* LoadTexture2D(const std::string& name, const std::string& filepath);
  Texture2D* CreateTexture2D(const std::string& name, unsigned int width, unsigned int height);
  Texture* GetTexture(const std::string& name);
  void DestroyTexture(const std::string& name);

  void PreUpdate() override;
  void Update() override;
  void PostUpdate() override;

private:
  Camera* _main_camera;

  Shader** _shaders;
  Texture** _textures;
  Material** _materials;

  UniformBuffer<TransfMatrices> _matrices_buffer;
  TransfMatrices _matrices;

  void UpdateUniforms();

};

#endif