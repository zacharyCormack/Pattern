#pragma once

class Gridline
{
	bool edge_activity;
	bool parity;
public:
	bool get_edge(bool use_parity);
	void switch_activity(bool toggler);
	Gridline(bool start, bool edge);
};
