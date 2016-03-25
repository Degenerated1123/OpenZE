#pragma once
#include <vector>
#include <inttypes.h>

namespace ZenConvert
{
	/**
	* @brief Modified ZTEX to DDS conversion
	*/
	int convertZTEX2DDS( const std::vector<uint8_t>& ztexData, std::vector<uint8_t>& ddsData, bool optionForceARGB = false);

	/**
	 * @brief Convert dds to RGBA8
	 */
	void convertDDSToRGBA8( const std::vector<uint8_t>& ddsData, std::vector<uint8_t>& rgba8Data, int mip=0);
}