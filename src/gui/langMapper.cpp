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

#include "gui/langMapper.h"
#include "utils/fs.h"
#include "utils/log.h"
#include <filesystem>
#include <fstream>

namespace nl = nlohmann;

namespace giada::v
{
LangMap::LangMap()
: m_default("[Not set]")
{
	m_data[COMMON_OK]         = "Ok";
	m_data[COMMON_CANCEL]     = "Cancel";
	m_data[COMMON_YES]        = "Yes";
	m_data[COMMON_NO]         = "No";
	m_data[COMMON_OFF]        = "Off";
	m_data[COMMON_WARNING]    = "Warning";
	m_data[COMMON_CLOSE]      = "Close";
	m_data[COMMON_ADD]        = "Add";
	m_data[COMMON_CLEAR]      = "Clear";
	m_data[COMMON_RELOAD]     = "Reload";
	m_data[COMMON_RESET]      = "Reset";
	m_data[COMMON_ZOOMIN]     = "Zoom in";
	m_data[COMMON_ZOOMOUT]    = "Zoom out";
	m_data[COMMON_GRIDRES]    = "Grid resolution";
	m_data[COMMON_SNAPTOGRID] = "Snap to grid";

	m_data[MAIN_MENU_FILE]                 = "File";
	m_data[MAIN_MENU_FILE_OPENPROJECT]     = "Open project...";
	m_data[MAIN_MENU_FILE_SAVEPROJECT]     = "Save project...";
	m_data[MAIN_MENU_FILE_CLOSEPROJECT]    = "Close project";
	m_data[MAIN_MENU_FILE_QUIT]            = "Quit Giada";
	m_data[MAIN_MENU_EDIT]                 = "Edit";
	m_data[MAIN_MENU_EDIT_FREEALLSAMPLES]  = "Free all Sample channels";
	m_data[MAIN_MENU_EDIT_CLEARALLACTIONS] = "Clear all actions";
	m_data[MAIN_MENU_EDIT_SETUPMIDIINPUT]  = "Setup global MIDI input...";
	m_data[MAIN_MENU_CONFIG]               = "Config";
	m_data[MAIN_MENU_ABOUT]                = "About";

	m_data[MAIN_IO_LABEL_OUTMETER] = "Main output meter";
	m_data[MAIN_IO_LABEL_INMETER]  = "Main input meter";
	m_data[MAIN_IO_LABEL_OUTVOL]   = "Main output volume";
	m_data[MAIN_IO_LABEL_INVOL]    = "Main input volume";
	m_data[MAIN_IO_LABEL_INTOOUT]  = "Stream linker\n\nConnects input to output to enable \"hear what you're playing\" mode.";
	m_data[MAIN_IO_LABEL_FXOUT]    = "Main output plug-ins";
	m_data[MAIN_IO_LABEL_FXIN]     = "Main input plug-ins";

	m_data[MAIN_TIMER_LABEL_BPM]        = "Beats per minute (BPM)";
	m_data[MAIN_TIMER_LABEL_METER]      = "Beats and bars";
	m_data[MAIN_TIMER_LABEL_QUANTIZER]  = "Live quantizer";
	m_data[MAIN_TIMER_LABEL_MULTIPLIER] = "Beat multiplier";
	m_data[MAIN_TIMER_LABEL_DIVIDER]    = "Beat divider";

	m_data[MAIN_SEQUENCER_LABEL] = "Main sequencer";

	m_data[MAIN_TRANSPORT_LABEL_REWIND]         = "Rewind";
	m_data[MAIN_TRANSPORT_LABEL_PLAY]           = "Play/Stop";
	m_data[MAIN_TRANSPORT_LABEL_RECTRIGGERMODE] = "Record-on-signal mode\n\nIf enabled, action "
	                                              "and audio recording will start only when a signal (key press or audio) "
	                                              "is detected.";
	m_data[MAIN_TRANSPORT_LABEL_RECACTIONS]   = "Record actions";
	m_data[MAIN_TRANSPORT_LABEL_RECINPUT]     = "Record audio";
	m_data[MAIN_TRANSPORT_LABEL_RECINPUTMODE] = "Free loop-length mode\n\nIf enabled, the sequencer "
	                                            "will adjust to the length of your first audio recording. "
	                                            "Available only if there are no other audio samples in the "
	                                            "project.";
	m_data[MAIN_TRANSPORT_LABEL_METRONOME] = "Metronome";

	m_data[MAIN_COLUMN_BUTTON]                  = "Edit column";
	m_data[MAIN_COLUMN_BUTTON_ADDSAMPLECHANNEL] = "Add Sample channel";
	m_data[MAIN_COLUMN_BUTTON_ADDMIDICHANNEL]   = "Add MIDI channel";
	m_data[MAIN_COLUMN_BUTTON_REMOVE]           = "Remove";

	m_data[MAIN_CHANNEL_LABEL_PLAY]        = "Play/stop";
	m_data[MAIN_CHANNEL_LABEL_ARM]         = "Arm for recording";
	m_data[MAIN_CHANNEL_LABEL_STATUS]      = "Progress bar";
	m_data[MAIN_CHANNEL_LABEL_READACTIONS] = "Read actions\n\nToggles playback of pre-recorded "
	                                         "actions (key press, key release, ...).";
	m_data[MAIN_CHANNEL_LABEL_MODEBOX] = "Mode";
	m_data[MAIN_CHANNEL_LABEL_MUTE]    = "Mute";
	m_data[MAIN_CHANNEL_LABEL_SOLO]    = "Solo";
	m_data[MAIN_CHANNEL_LABEL_FX]      = "Plug-ins";
	m_data[MAIN_CHANNEL_LABEL_VOLUME]  = "Volume";

	m_data[MAIN_CHANNEL_MENU_INPUTMONITOR]           = "Input monitor";
	m_data[MAIN_CHANNEL_MENU_OVERDUBPROTECTION]      = "Overdub protection";
	m_data[MAIN_CHANNEL_MENU_LOADSAMPLE]             = "Load new sample...";
	m_data[MAIN_CHANNEL_MENU_EXPORTSAMPLE]           = "Export sample to file...";
	m_data[MAIN_CHANNEL_MENU_KEYBOARDINPUT]          = "Setup keyboard input...";
	m_data[MAIN_CHANNEL_MENU_MIDIINPUT]              = "Setup MIDI input...";
	m_data[MAIN_CHANNEL_MENU_MIDIOUTPUT]             = "Setup MIDI output...";
	m_data[MAIN_CHANNEL_MENU_EDITSAMPLE]             = "Edit sample...";
	m_data[MAIN_CHANNEL_MENU_EDITACTIONS]            = "Edit actions...";
	m_data[MAIN_CHANNEL_MENU_CLEARACTIONS]           = "Clear actions";
	m_data[MAIN_CHANNEL_MENU_CLEARACTIONS_ALL]       = "All";
	m_data[MAIN_CHANNEL_MENU_CLEARACTIONS_VOLUME]    = "Volume";
	m_data[MAIN_CHANNEL_MENU_CLEARACTIONS_STARTSTOP] = "Start/Stop";
	m_data[MAIN_CHANNEL_MENU_RENAME]                 = "Rename";
	m_data[MAIN_CHANNEL_MENU_CLONE]                  = "Clone";
	m_data[MAIN_CHANNEL_MENU_FREE]                   = "Free";
	m_data[MAIN_CHANNEL_MENU_DELETE]                 = "Delete";

	m_data[MISSINGASSETS_INTRO]      = "This project contains missing assets.";
	m_data[MISSINGASSETS_AUDIOFILES] = "Audio files not found in the project folder:";
	m_data[MISSINGASSETS_PLUGINS]    = "Audio plug-ins not found globally:";

	m_data[PLUGINCHOOSER_TITLE]               = "Available plugins";
	m_data[PLUGINCHOOSER_SORTBY]              = "Sort by";
	m_data[PLUGINCHOOSER_SORTBY_NAME]         = "Name";
	m_data[PLUGINCHOOSER_SORTBY_CATEGORY]     = "Category";
	m_data[PLUGINCHOOSER_SORTBY_MANIFACTURER] = "Manifacturer";
	m_data[PLUGINCHOOSER_SORTBY_FORMAT]       = "Format";

	m_data[PLUGINLIST_TITLE_MASTEROUT] = "Master Out Plug-ins";
	m_data[PLUGINLIST_TITLE_MASTERIN]  = "Master In Plug-ins";
	m_data[PLUGINLIST_TITLE_CHANNEL]   = "Channel Plug-ins";
	m_data[PLUGINLIST_ADDPLUGIN]       = "-- add new plugin --";

	m_data[CHANNELNAME_TITLE] = "New channel name";

	m_data[KEYGRABBER_TITLE] = "Key configuration";
	m_data[KEYGRABBER_BODY]  = "Press a key.\n\nCurrent binding: ";

	m_data[SAMPLEEDITOR_TITLE]                = "Sample Editor";
	m_data[SAMPLEEDITOR_RELOAD]               = "Reload";
	m_data[SAMPLEEDITOR_LOOP]                 = "Loop";
	m_data[SAMPLEEDITOR_INFO]                 = "File: {}\nSize: {} frames\nDuration {} seconds\nBit depth: {}\nFrequency: {} Hz";
	m_data[SAMPLEEDITOR_PAN]                  = "Pan";
	m_data[SAMPLEEDITOR_PITCH]                = "Pitch";
	m_data[SAMPLEEDITOR_PITCH_TOBAR]          = "To bar";
	m_data[SAMPLEEDITOR_PITCH_TOSONG]         = "To song";
	m_data[SAMPLEEDITOR_RANGE]                = "Range";
	m_data[SAMPLEEDITOR_SHIFT]                = "Shift";
	m_data[SAMPLEEDITOR_VOLUME]               = "Volume";
	m_data[SAMPLEEDITOR_TOOLS_CUT]            = "Cut";
	m_data[SAMPLEEDITOR_TOOLS_COPY]           = "Copy";
	m_data[SAMPLEEDITOR_TOOLS_PASTE]          = "Paste";
	m_data[SAMPLEEDITOR_TOOLS_TRIM]           = "Trim";
	m_data[SAMPLEEDITOR_TOOLS_SILENCE]        = "Silence";
	m_data[SAMPLEEDITOR_TOOLS_REVERSE]        = "Reverse";
	m_data[SAMPLEEDITOR_TOOLS_NORMALIZE]      = "Normalize";
	m_data[SAMPLEEDITOR_TOOLS_FADE_IN]        = "Fade in";
	m_data[SAMPLEEDITOR_TOOLS_FADE_OUT]       = "Fade out";
	m_data[SAMPLEEDITOR_TOOLS_SMOOTH_EDGES]   = "Smooth edges";
	m_data[SAMPLEEDITOR_TOOLS_SET_BEGIN_END]  = "Set begin/end here";
	m_data[SAMPLEEDITOR_TOOLS_TO_NEW_CHANNEL] = "Copy to new channel";

	m_data[MIDIINPUT_MASTER_TITLE]           = "MIDI Input Setup (global)";
	m_data[MIDIINPUT_MASTER_ENABLE]          = "Enable MIDI input";
	m_data[MIDIINPUT_MASTER_LEARN_REWIND]    = "Rewind";
	m_data[MIDIINPUT_MASTER_LEARN_PLAYSTOP]  = "Play/stop";
	m_data[MIDIINPUT_MASTER_LEARN_ACTIONREC] = "Action recording";
	m_data[MIDIINPUT_MASTER_LEARN_INPUTREC]  = "Input recording";
	m_data[MIDIINPUT_MASTER_LEARN_METRONOME] = "metronome";
	m_data[MIDIINPUT_MASTER_LEARN_INVOLUME]  = "Input volume";
	m_data[MIDIINPUT_MASTER_LEARN_OUTVOLUME] = "Output volume";
	m_data[MIDIINPUT_MASTER_LEARN_SEQDOUBLE] = "Sequencer ×2";
	m_data[MIDIINPUT_MASTER_LEARN_SEQHALF]   = "Sequencer ÷2";

	m_data[MIDIINPUT_CHANNEL_TITLE]             = "MIDI Input Setup";
	m_data[MIDIINPUT_CHANNEL_ENABLE]            = "Enable MIDI input";
	m_data[MIDIINPUT_CHANNEL_LEARN_CHANNEL]     = "Channel";
	m_data[MIDIINPUT_CHANNEL_LEARN_KEYPRESS]    = "Key press";
	m_data[MIDIINPUT_CHANNEL_LEARN_KEYREL]      = "Key release";
	m_data[MIDIINPUT_CHANNEL_LEARN_KEYKILL]     = "Key kill";
	m_data[MIDIINPUT_CHANNEL_LEARN_ARM]         = "Arm";
	m_data[MIDIINPUT_CHANNEL_LEARN_MUTE]        = "Mute";
	m_data[MIDIINPUT_CHANNEL_LEARN_SOLO]        = "Solo";
	m_data[MIDIINPUT_CHANNEL_LEARN_VOLUME]      = "Volume";
	m_data[MIDIINPUT_CHANNEL_LEARN_PITCH]       = "Pitch";
	m_data[MIDIINPUT_CHANNEL_LEARN_READACTIONS] = "Read actions";
}

const char* LangMap::get(const std::string& key) const
{
	if (m_data.count(key) == 0)
		return m_default.c_str();
	return m_data.at(key).c_str();
}

/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */

void LangMapper::init()
{
	m_mapsPath = u::fs::getLangMapsPath();

	u::log::print("[LangMapper::init] scanning langmaps directory '%s'...\n", m_mapsPath);

	if (!std::filesystem::exists(m_mapsPath))
	{
		u::log::print("[LangMapper::init] langmaps directory not found, using default language\n");
		return;
	}

	for (const auto& d : std::filesystem::directory_iterator(m_mapsPath))
	{
		// TODO - check if is a valid langMap file (verify headers)
		if (!d.is_regular_file())
			continue;
		m_langFiles.push_back(d.path().filename().string());
		u::log::print("[LangMapper::init] found langmap '%s'\n", m_langFiles.back());
	}

	u::log::print("[LangMapper::init] total langmaps found: %d\n", m_langFiles.size());
}

/* -------------------------------------------------------------------------- */

int LangMapper::read(const std::string& file)
{
	if (file.empty())
	{
		u::log::print("[LangMapper::read] langmap not specified, nothing to do\n");
		return G_FILE_NOT_SPECIFIED;
	}

	u::log::print("[LangMapper::read] reading langmap file '%s'\n", file);

	std::ifstream ifs(u::fs::join(m_mapsPath, file));
	if (!ifs.good())
		return G_FILE_UNREADABLE;

	nl::json j = nl::json::parse(ifs, nullptr, /*exceptions=*/false);
	if (j.is_discarded())
		return G_FILE_UNREADABLE;

	m_map.m_data = j.get<LangMap::Data>();

	return G_FILE_OK;
}

/* -------------------------------------------------------------------------- */

const char* LangMapper::get(const std::string& s) const
{
	return m_map.get(s);
}

/* -------------------------------------------------------------------------- */

const std::vector<std::string>& LangMapper::getMapFilesFound() const
{
	return m_langFiles;
}
} // namespace giada::v
