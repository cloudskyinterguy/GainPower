#pragma once

#pragma comment(lib,"winmm.lib")
#pragma comment(lib, "msimg32")

#include<graphics.h>

struct Rect
{
	int x, y;
	int width, height;
};

inline void putimage_ex(IMAGE* imgae, const Rect* src = nullptr, const Rect* dest)
{
	static BLENDFUNCTION blend_func = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };
	
	AlphaBlend(GetImageHDC(GetWorkingImage()), dest->x, dest->y, dest->width, dest->height,
		GetImageHDC(imgae), src ? src->x : 0, src ? src->y : 0, src ? src->width : imgae->getwidth(), src ? src->height : imgae->getheight(), blend_func);
}

static inline bool check_image_valid(IMAGE* img) {
	return GetImageBuffer(img);
}
