#include "resource_manager.h"
#include "util.h"

#include <vector>

ResourceManager* ResourceManager::instance = nullptr;

ResourceManager* ResourceManager::getInstance()
{
	if (instance == nullptr)
	{
		instance = new ResourceManager();
	}
	return instance;
}

struct ImageResInfo
{
	std::string id;
	LPCTSTR path;

};

struct AtlasResInfo
{
	std::string id;
	LPCTSTR path;
	int num;

	AtlasResInfo(const std::string id, LPCTSTR path, int num) : id(id), path(path), num(num) {}
};

static const std::vector<ImageResInfo> image_info_list = {
	{"backgroud",_T(R"(res\groudback.png)")},
	{"ui_heart",_T(R"(res\ui_heart.png)")},

	{"player_attack_right",_T(R"(res\player\attack.png)")},
	{"player_dead_right",_T(R"(res\player\dead.png)")},
	{"player_fall_right",_T(R"(res\player\fall.png)")},
	{"player_idle_right",_T(R"(res\player\idle.png)")},
	{"player_jump_right",_T(R"(res\player\jump.png)")},
	{"player_run_right",_T(R"(res\player\run.png)")},
	{"player_roll_right",_T(R"(res\player\roll.png)")},

	{"player_vfx_attack_down",_T(R"(res\player\vfx_attack_down.png)")},
	{"player_vfx_attack_left",_T(R"(res\player\vfx_attack_left.png)")},
	{"player_vfx_attack_right",_T(R"(res\player\vfx_attack_right.png)")},
	{"player_vfx_attack_up",_T(R"(res\player\vfx_attack_up.png)")},
	{"player_vfx_jump",_T(R"(res\player\vfx_jump.png)")},
	{"player_vfx_land",_T(R"(res\player\vfx_land.png)")},
};

static const std::vector<AtlasResInfo> atlas_info_list = {
	//´ý×ö 3¸ö 5:50
};

void ResourceManager::load() {
	for (const auto& info : image_info_list)
	{
		IMAGE* img = new IMAGE();
		loadimage(img, info.path);
		
		if (!check_image_valid(img))
		{
			throw info.path;
		}

		image_pool[info.id] = img;
	}

	for (const auto& info : atlas_info_list)
	{
		Atlas* atlas = new Atlas();
		atlas->load_from_file(info.path, info.num);
		atlas_pool[info.id] = atlas;
	}
}

ResourceManager::ResourceManager() = default;
ResourceManager::~ResourceManager() = default;