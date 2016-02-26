#pragma once 
#include <vector>
#include "utils/mathlib.h"
#include "zTypes.h"

namespace VDFS
{
	class FileIndex;
}

namespace ZenConvert
{
	class ZenParser;
	class zCProgMeshProto
	{
	public:
		struct SubMesh
		{
			zCMaterialData m_Material;
			std::vector<zTriangle> m_TriangleList;
			std::vector<zWedge> m_WedgeList;
			std::vector<float> m_ColorList;
			std::vector<uint16_t> m_TrianglePlaneIndexList;
			std::vector<zTPlane> m_TrianglePlaneList;
			std::vector<zTriangleEdges>	m_TriEdgeList;
			std::vector<zEdge> m_EdgeList;
			std::vector<float> m_EdgeScoreList;	
			std::vector<uint16_t> m_WedgeMap;			
		};
		
		zCProgMeshProto(){}

		/**
		 * @brief Loads the mesh from the given VDF-Archive
		 */
		zCProgMeshProto(const std::string& fileName, VDFS::FileIndex& fileIndex);

		/**
		 * @brief Reads the mesh-object from the given binary stream
		 */
		void readObjectData(ZenParser& parser);

		/**
		@ brief returns the vector of vertex-positions
		*/
		const std::vector<Math::float3>& getVertices() const { return m_Vertices; }

		/**
		@ brief returns the vector of features
		*/
		const std::vector<zTMSH_FeatureChunk>& getFeatures() const { return m_Features; }

		/**
		 * @brief returns the vector of the materials used by this mesh
		 */
		const std::vector<zCMaterialData>& getMaterials() const { return m_Materials; }

		/**
		 * @brief getter for the boudingboxes
		 */
		void getBoundingBox(Math::float3& min, Math::float3& max)const{min = m_BBMin; max = m_BBMax;}

		/**
		 * @brief Returns the submesh with the given index
		 */
		const SubMesh& getSubmesh(size_t idx)const{return m_SubMeshes[idx];}
		size_t getNumSubmeshes()const{return m_SubMeshes.size(); }

		/**
		 * @brief Returns the global position-list
		 */
		const std::vector<Math::float3> getPositionList()const{return m_Vertices;}
	private:

		/**
		 * @brief vector of vertex-positions for this mesh
		 */
		std::vector<Math::float3> m_Vertices;
		std::vector<Math::float3> m_Normals;

		/** 
		 * @brief Featues for the vertices with the corresponding index
		 */
		std::vector<zTMSH_FeatureChunk> m_Features;

		/** 
		* @brief List of submeshes
		*/
		std::vector<SubMesh> m_SubMeshes;

		/**
		* @brief All materials used by this mesh
		*/
		std::vector<zCMaterialData> m_Materials;

		/**
		 * @brief Whether this mesh is using alphatest
		 */
		uint8_t m_IsUsingAlphaTest;

		/**
		 * @brief Bounding-box of this mesh
		 */
		Math::float3 m_BBMin;
		Math::float3 m_BBMax;
	};
}