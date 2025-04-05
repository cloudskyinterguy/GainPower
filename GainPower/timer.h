#pragma once

#include<functional>

class Timer
{
public:
	Timer();
	~Timer();

	void on_update(int delta) {
		if (paused)
		{
			return;
		}

		pass_time += delta;
		if (pass_time > wait_time)
		{
			if ((!one_shot || (one_shot && !shotted)) && callback) {
				callback();
				shotted = true;
				pass_time = 0;
			}
		}
	}

	void re_start() {
		pass_time = 0;
		shotted = false;
	}

	void set_wait_time(int val) {
		wait_time = val;
	}

	void set_one_shot(bool flag) {
		one_shot = flag;
	}

	void set_callback(std::function<void()> cb) {
		callback = cb;
	}

	void pause() {
		paused = true;
	}

	void resume() {
		paused = false;
	}

private:
	int pass_time = 0; //�ѹ�ʱ��
	int wait_time = 0; //�ȴ�ʱ��
	bool paused = false; //�Ƿ���ͣ
	bool shotted = false; //�Ƿ񴥷�
	bool one_shot = false;//���δ���

	std::function<void()> callback;
};

Timer::Timer()
{
}

Timer::~Timer()
{
}