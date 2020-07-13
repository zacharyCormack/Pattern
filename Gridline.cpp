#include "Gridline.hpp"

Gridline::Gridline(bool start, bool edge) {
	parity = start;
	edge_activity = edge^start;
}

bool Gridline::get_edge(bool use_parity) {
	return (use_parity ? parity : 0) ^ edge_activity;
}

void Gridline::switch_activity(bool toggler) {
	edge_activity = parity^toggler;
}
