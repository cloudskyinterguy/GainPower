#pragma once
#include"atlas.h"

#include <graphics.h>
#include <string>
#include <unordered_map>

class ResourceManager
{
public:
	static ResourceManager* getInstance();

	void load();

	Atlas* find_altas(const std::string& id);
	IMAGE* find_image(const std::string& id);

private:
	
	static ResourceManager* instance;

	std::unordered_map<std::string, Atlas*> atlas_pool;
	std::unordered_map<std::string, IMAGE*> image_pool;

private:

	ResourceManager();
	~ResourceManager();

	void filp_image(IMAGE* src_img,IMAGE* dst_img,int num_h = 1);
	void filp_image(std::string& src_id,std::string& dst_id,int num_h = 1);
	void filp_atlas(std::string& src_id,std::string& dst_id);

};

