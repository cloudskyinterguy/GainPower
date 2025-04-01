#pragma once

#include<vector>
#include<graphics.h>
#include<string>
#include <iostream>

class Atlas
{
public:
	Atlas() = default;
	~Atlas() = default;

	void load_from_file(LPCTSTR path_template, int num) {
		img_list.clear();
		img_list.resize(num);

		TCHAR path_file[256];

		for (size_t i = 0; i < num; i++)
		{
			_stprintf_s(path_file, path_template, i + 1);
			img_list[i] = new IMAGE();
			loadimage(img_list[i], path_file);
			if (check_image_valid(img_list[i]))
			{
				throw path_file;
			}
		}
	}

	void clear() {
		img_list.clear();
	}

	int getSize() {
		return (int)img_list.size();
	}

	IMAGE* getImage(int idx) {
		return img_list[idx];
	}

	void addImage(IMAGE* i) {
		img_list.push_back(i);
	}

	std::string getPath() {
		return path;
	}

private:
	std::vector<IMAGE*> img_list;
	std::string path;
};
