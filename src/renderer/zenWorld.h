#pragma once 
#include <vector>
#include "utils/mathlib.h"

namespace Renderer
{
	class ZenWorldMesh;
	class ZenWorld
	{
	public:
		ZenWorld(const std::string& zen);
		~ZenWorld();

		void render(const Math::Matrix& viewProj);
	private:
		std::vector<Renderer::ZenWorldMesh*> m_Meshes;
		std::vector<Math::float3> m_VobPositions;
	};
}