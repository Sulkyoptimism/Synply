#pragma once
#include "inc/rpc/server.h"
#include <queue>

class receiver
{
private:
	int port = 0;
	bool quit = false;
	bool trigger_hotload = false;
	bool note_ready = false;
	std::queue<std::pair<std::string, int>> syn_notes;
	int notes_in_count = 0;
public:
	receiver(int port);
	void run();
	void reset_hotload();
	void reset_note();
	void hotload();
	bool get_hotload();
	bool get_note_ready();
	void pop_next();

	std::queue<std::pair<std::string, int>> get_next_note();


};

