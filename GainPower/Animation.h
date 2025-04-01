#pragma once

#include "util.h"
#include "atlas.h"
#include "Vector2.h"
#include "timer.h"

class Animation
{
public:
	enum class AnchorMode
	{
		Centered,
		BottomCentered,
	};

public:
	Animation() {
		timer.set_one_shot(false);
		timer.set_callback(
			[&]() {
				current_frame_idx++;
				if (current_frame_idx >= frame_list.size())
				{
					if (is_loop)
					{
						current_frame_idx = 0;
						timer.resume();
					}
					else
					{
						if (on_finished)
						{
							on_finished();
						}
					}
				}
			});
		timer.set_wait_time(10);
	}

	void restart() {
		timer.resume();

		current_frame_idx = 0;
	}

	void setAnchorMode(AnchorMode mode) {
		anchor_mode = mode;
	}

	void setPosition(Vector2& vector){
		this->position = vector;
	}

	void setLoop(bool flag) {
		is_loop = flag;
	}

	void setInterval(int interval) {
		this->interval = interval;
	}

	~Animation() = default;

	//裁切长条
	void addFrame(IMAGE*img,int num){
		int w = img->getwidth();
		int h = img->getheight();

		int frameWidth = w / num;

		for (size_t i = 0; i < num; i++)
		{
			Rect rect_src;
			rect_src.x = i * frameWidth;
			rect_src.y = 0;

			rect_src.width = frameWidth;
			rect_src.height = h;

			frame_list.push_back(Frame(rect_src, img));
		}
	}

	void addFrame(Atlas* atlas) {
		for (size_t i = 0; i < atlas->getSize(); i++)
		{
			Rect rect_src;
			rect_src.x = 0;
			rect_src.y = 0;
			rect_src.height = atlas->getImage(i)->getheight();
			rect_src.width = atlas->getImage(i)->getwidth();
			frame_list.push_back(Frame(rect_src, atlas->getImage(i)));
		}
	}

	void on_update(int delta) {
		timer.on_update(delta);
	}

	//TODO
	void on_render() {

	}

private:

	struct Frame	//用来记录和代表一帧
	{
		Rect src;
		IMAGE* img = nullptr;

		Frame() = default;
		Frame(const Rect& src, IMAGE* img) : src(src), img(img) {}

		~Frame() = default;
	};

private:
	Timer timer;
	Vector2 position;
	std::vector<Frame> frame_list;
	int current_frame_idx = 0;
	bool is_loop = true;
	int interval = 10;
	std::function<void()> on_finished;
	AnchorMode anchor_mode = AnchorMode::BottomCentered;
};


