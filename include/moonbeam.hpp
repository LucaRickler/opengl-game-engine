#ifndef MOONBEAM_HPP
#define MOONBEAM_HPP

#include <dependencies.hpp>

#include <core/exception.hpp>

#include <core/memory/allocator.hpp>
#include <core/memory/linear-allocator.hpp>
#include <core/memory/stack-allocator.hpp>
#include <core/memory/block-list-allocator.hpp>
#include <core/memory/pool-allocator.hpp>
#include <core/memory/proxy-allocator.hpp>

#include <core/container/id-map.hpp>
#include <core/container/fixed-set.hpp>
#include <core/container/fixed-unordered-map.hpp>

#include <core/system.hpp>
#include <core/system-manager.hpp>
#include <core/entity.hpp>
#include <core/entity-manager.hpp>
#include <core/component.hpp>
#include <core/component-manager.hpp>

#include <transform.hpp>

#include <graphics/gl-object.hpp>
#include <graphics/window.hpp>
#include <graphics/buffer.hpp>
#include <graphics/uniform-buffer.hpp>
#include <graphics/shader.hpp>
#include <graphics/draw-shader.hpp>
#include <graphics/compute-shader.hpp>
#include <graphics/texture.hpp>
#include <graphics/texture2d.hpp>
#include <graphics/material.hpp>
#include <graphics/compute-material.hpp>
#include <graphics/vertex.hpp>
#include <graphics/mesh.hpp>
#include <model.hpp>
#include <graphics/camera.hpp>

#include <graphics/graphic-system.hpp>

#include <moonbeam-engine.hpp>

#endif