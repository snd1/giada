/* -----------------------------------------------------------------------------
 *
 * Giada - Your Hardcore Loopmachine
 *
 * -----------------------------------------------------------------------------
 *
 * Copyright (C) 2010-2022 Giovanni A. Zuliani | Monocasual Laboratories
 *
 * This file is part of Giada - Your Hardcore Loopmachine.
 *
 * Giada - Your Hardcore Loopmachine is free software: you can
 * redistribute it and/or modify it under the terms of the GNU General
 * Public License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 *
 * Giada - Your Hardcore Loopmachine is distributed in the hope that it
 * will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Giada - Your Hardcore Loopmachine. If not, see
 * <http://www.gnu.org/licenses/>.
 *
 * -------------------------------------------------------------------------- */

#ifndef GE_TAB_MISC_H
#define GE_TAB_MISC_H

#include "deps/geompp/src/rect.hpp"
#include "glue/config.h"
#include <FL/Fl_Group.H>

namespace giada::v
{
class geChoice;
class geStringMenu;
class geTabMisc : public Fl_Group
{
public:
	geTabMisc(geompp::Rect<int>);

	void save();

private:
	c::config::MiscData m_data;

	geChoice*     m_debugMsg;
	geChoice*     m_tooltips;
	geStringMenu* m_langMap;
};
} // namespace giada::v

#endif
