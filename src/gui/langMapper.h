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

#ifndef G_LANGMAPPER_H
#define G_LANGMAPPER_H

#include "deps/json/single_include/nlohmann/json.hpp"
#include <string>
#include <unordered_map>
#include <vector>

namespace giada::v
{
class LangMap
{
public:
	friend class LangMapper;

	using Data = std::unordered_map<std::string, std::string>;

	static constexpr auto COMMON_OK         = "common_ok";
	static constexpr auto COMMON_CANCEL     = "common_cancel";
	static constexpr auto COMMON_YES        = "common_yes";
	static constexpr auto COMMON_NO         = "common_no";
	static constexpr auto COMMON_OFF        = "common_off";
	static constexpr auto COMMON_WARNING    = "common_warning";
	static constexpr auto COMMON_CLOSE      = "common_close";
	static constexpr auto COMMON_ADD        = "common_add";
	static constexpr auto COMMON_CLEAR      = "common_clear";
	static constexpr auto COMMON_RELOAD     = "common_reload";
	static constexpr auto COMMON_RESET      = "common_reset";
	static constexpr auto COMMON_ZOOMIN     = "common_zoomIn";
	static constexpr auto COMMON_ZOOMOUT    = "common_zoomOut";
	static constexpr auto COMMON_GRIDRES    = "common_gridRes";
	static constexpr auto COMMON_SNAPTOGRID = "common_snapToGrid";

	static constexpr auto MAIN_MENU_FILE                 = "main_menu_file";
	static constexpr auto MAIN_MENU_FILE_OPENPROJECT     = "main_menu_file_openProject";
	static constexpr auto MAIN_MENU_FILE_SAVEPROJECT     = "main_menu_file_saveProject";
	static constexpr auto MAIN_MENU_FILE_CLOSEPROJECT    = "main_menu_file_closeProject";
	static constexpr auto MAIN_MENU_FILE_QUIT            = "main_menu_file_quit";
	static constexpr auto MAIN_MENU_EDIT                 = "main_menu_edit";
	static constexpr auto MAIN_MENU_EDIT_FREEALLSAMPLES  = "main_menu_edit_freeAllSamples";
	static constexpr auto MAIN_MENU_EDIT_CLEARALLACTIONS = "main_menu_edit_clearAllActions";
	static constexpr auto MAIN_MENU_EDIT_SETUPMIDIINPUT  = "main_menu_edit_setupMidiInput";
	static constexpr auto MAIN_MENU_CONFIG               = "main_menu_config";
	static constexpr auto MAIN_MENU_ABOUT                = "main_menu_about";

	static constexpr auto MAIN_IO_LABEL_OUTMETER = "main_IO_label_outMeter";
	static constexpr auto MAIN_IO_LABEL_INMETER  = "main_IO_label_inMeter";
	static constexpr auto MAIN_IO_LABEL_OUTVOL   = "main_IO_label_outVol";
	static constexpr auto MAIN_IO_LABEL_INVOL    = "main_IO_label_inVol";
	static constexpr auto MAIN_IO_LABEL_INTOOUT  = "main_IO_label_inToOut";
	static constexpr auto MAIN_IO_LABEL_FXOUT    = "main_IO_label_fxOut";
	static constexpr auto MAIN_IO_LABEL_FXIN     = "main_IO_label_fxIn";

	static constexpr auto MAIN_TIMER_LABEL_BPM        = "main_mainTimer_label_bpm";
	static constexpr auto MAIN_TIMER_LABEL_METER      = "main_mainTimer_label_meter";
	static constexpr auto MAIN_TIMER_LABEL_QUANTIZER  = "main_mainTimer_label_quantizer";
	static constexpr auto MAIN_TIMER_LABEL_MULTIPLIER = "main_mainTimer_label_multiplier";
	static constexpr auto MAIN_TIMER_LABEL_DIVIDER    = "main_mainTimer_label_divider";

	static constexpr auto MAIN_SEQUENCER_LABEL = "main_sequencer_label";

	static constexpr auto MAIN_TRANSPORT_LABEL_REWIND         = "main_transport_label_rewind";
	static constexpr auto MAIN_TRANSPORT_LABEL_PLAY           = "main_transport_label_play";
	static constexpr auto MAIN_TRANSPORT_LABEL_RECTRIGGERMODE = "main_transport_label_recTriggerMode";
	static constexpr auto MAIN_TRANSPORT_LABEL_RECACTIONS     = "main_transport_label_recActions";
	static constexpr auto MAIN_TRANSPORT_LABEL_RECINPUT       = "main_transport_label_recInput";
	static constexpr auto MAIN_TRANSPORT_LABEL_RECINPUTMODE   = "main_transport_label_recInputMode";
	static constexpr auto MAIN_TRANSPORT_LABEL_METRONOME      = "main_transport_label_metronome";

	static constexpr auto MAIN_COLUMN_BUTTON                  = "main_column_button";
	static constexpr auto MAIN_COLUMN_BUTTON_ADDSAMPLECHANNEL = "main_column_button_addSampleChannel";
	static constexpr auto MAIN_COLUMN_BUTTON_ADDMIDICHANNEL   = "main_column_button_addMidiChannel";
	static constexpr auto MAIN_COLUMN_BUTTON_REMOVE           = "main_column_button_remove";

	static constexpr auto MAIN_CHANNEL_LABEL_PLAY        = "main_channel_label_play";
	static constexpr auto MAIN_CHANNEL_LABEL_ARM         = "main_channel_label_arm";
	static constexpr auto MAIN_CHANNEL_LABEL_STATUS      = "main_channel_label_status";
	static constexpr auto MAIN_CHANNEL_LABEL_READACTIONS = "main_channel_label_readActions";
	static constexpr auto MAIN_CHANNEL_LABEL_MODEBOX     = "main_channel_label_modeBox";
	static constexpr auto MAIN_CHANNEL_LABEL_MUTE        = "main_channel_label_mute";
	static constexpr auto MAIN_CHANNEL_LABEL_SOLO        = "main_channel_label_solo";
	static constexpr auto MAIN_CHANNEL_LABEL_FX          = "main_channel_label_fx";
	static constexpr auto MAIN_CHANNEL_LABEL_VOLUME      = "main_channel_label_volume";

	static constexpr auto MAIN_CHANNEL_MENU_INPUTMONITOR           = "main_channel_menu_inputMonitor";
	static constexpr auto MAIN_CHANNEL_MENU_OVERDUBPROTECTION      = "main_channel_menu_overdubProtection";
	static constexpr auto MAIN_CHANNEL_MENU_LOADSAMPLE             = "main_channel_menu_loadSample";
	static constexpr auto MAIN_CHANNEL_MENU_EXPORTSAMPLE           = "main_channel_menu_exportSample";
	static constexpr auto MAIN_CHANNEL_MENU_KEYBOARDINPUT          = "main_channel_menu_keyboardInput";
	static constexpr auto MAIN_CHANNEL_MENU_MIDIINPUT              = "main_channel_menu_midiInput";
	static constexpr auto MAIN_CHANNEL_MENU_MIDIOUTPUT             = "main_channel_menu_midiOutput";
	static constexpr auto MAIN_CHANNEL_MENU_EDITSAMPLE             = "main_channel_menu_editSample";
	static constexpr auto MAIN_CHANNEL_MENU_EDITACTIONS            = "main_channel_menu_editActions";
	static constexpr auto MAIN_CHANNEL_MENU_CLEARACTIONS           = "main_channel_menu_clearActions";
	static constexpr auto MAIN_CHANNEL_MENU_CLEARACTIONS_ALL       = "main_channel_menu_clearActions_all";
	static constexpr auto MAIN_CHANNEL_MENU_CLEARACTIONS_VOLUME    = "main_channel_menu_clearActions_volume";
	static constexpr auto MAIN_CHANNEL_MENU_CLEARACTIONS_STARTSTOP = "main_channel_menu_clearActions_startStop";
	static constexpr auto MAIN_CHANNEL_MENU_RENAME                 = "main_channel_menu_rename";
	static constexpr auto MAIN_CHANNEL_MENU_CLONE                  = "main_channel_menu_clone";
	static constexpr auto MAIN_CHANNEL_MENU_FREE                   = "main_channel_menu_free";
	static constexpr auto MAIN_CHANNEL_MENU_DELETE                 = "main_channel_menu_delete";

	static constexpr auto MISSINGASSETS_INTRO      = "missingAssets_intro";
	static constexpr auto MISSINGASSETS_AUDIOFILES = "missingAssets_audioFiles";
	static constexpr auto MISSINGASSETS_PLUGINS    = "missingAssets_plugIns";

	static constexpr auto PLUGINCHOOSER_TITLE               = "pluginChooser_title";
	static constexpr auto PLUGINCHOOSER_SORTBY              = "pluginChooser_sortBy";
	static constexpr auto PLUGINCHOOSER_SORTBY_NAME         = "pluginChooser_sortBy_name";
	static constexpr auto PLUGINCHOOSER_SORTBY_CATEGORY     = "pluginChooser_sortBy_category";
	static constexpr auto PLUGINCHOOSER_SORTBY_MANIFACTURER = "pluginChooser_sortBy_manifacturer";
	static constexpr auto PLUGINCHOOSER_SORTBY_FORMAT       = "pluginChooser_sortBy_format";

	static constexpr auto PLUGINLIST_TITLE_MASTEROUT = "pluginList_title_masterOut";
	static constexpr auto PLUGINLIST_TITLE_MASTERIN  = "pluginList_title_masterIn";
	static constexpr auto PLUGINLIST_TITLE_CHANNEL   = "pluginList_title_channel";
	static constexpr auto PLUGINLIST_ADDPLUGIN       = "pluginList_addPlugin";

	static constexpr auto CHANNELNAME_TITLE = "channelName_title";

	static constexpr auto KEYGRABBER_TITLE = "keyGrabber_title";
	static constexpr auto KEYGRABBER_BODY  = "keyGrabber_body";

	static constexpr auto SAMPLEEDITOR_TITLE                = "sampleEditor_title";
	static constexpr auto SAMPLEEDITOR_RELOAD               = "sampleEditor_reload";
	static constexpr auto SAMPLEEDITOR_LOOP                 = "sampleEditor_loop";
	static constexpr auto SAMPLEEDITOR_INFO                 = "sampleEditor_info";
	static constexpr auto SAMPLEEDITOR_PAN                  = "sampleEditor_pan";
	static constexpr auto SAMPLEEDITOR_PITCH                = "sampleEditor_pitch";
	static constexpr auto SAMPLEEDITOR_PITCH_TOBAR          = "sampleEditor_pitch_toBar";
	static constexpr auto SAMPLEEDITOR_PITCH_TOSONG         = "sampleEditor_pitch_toSong";
	static constexpr auto SAMPLEEDITOR_RANGE                = "sampleEditor_range";
	static constexpr auto SAMPLEEDITOR_SHIFT                = "sampleEditor_shift";
	static constexpr auto SAMPLEEDITOR_VOLUME               = "sampleEditor_volume";
	static constexpr auto SAMPLEEDITOR_TOOLS_CUT            = "sampleEditor_tools_cut";
	static constexpr auto SAMPLEEDITOR_TOOLS_COPY           = "sampleEditor_tools_copy";
	static constexpr auto SAMPLEEDITOR_TOOLS_PASTE          = "sampleEditor_tools_paste";
	static constexpr auto SAMPLEEDITOR_TOOLS_TRIM           = "sampleEditor_tools_trim";
	static constexpr auto SAMPLEEDITOR_TOOLS_SILENCE        = "sampleEditor_tools_silence";
	static constexpr auto SAMPLEEDITOR_TOOLS_REVERSE        = "sampleEditor_tools_reverse";
	static constexpr auto SAMPLEEDITOR_TOOLS_NORMALIZE      = "sampleEditor_tools_normalize";
	static constexpr auto SAMPLEEDITOR_TOOLS_FADE_IN        = "sampleEditor_tools_fadeIn";
	static constexpr auto SAMPLEEDITOR_TOOLS_FADE_OUT       = "sampleEditor_tools_fadeOut";
	static constexpr auto SAMPLEEDITOR_TOOLS_SMOOTH_EDGES   = "sampleEditor_tools_smoothEdgdes";
	static constexpr auto SAMPLEEDITOR_TOOLS_SET_BEGIN_END  = "sampleEditor_tools_setBeginEnd";
	static constexpr auto SAMPLEEDITOR_TOOLS_TO_NEW_CHANNEL = "sampleEditor_tools_toNewChannel";

	static constexpr auto MIDIINPUT_MASTER_TITLE           = "midiInput_master_title";
	static constexpr auto MIDIINPUT_MASTER_ENABLE          = "midiInput_master_enable";
	static constexpr auto MIDIINPUT_MASTER_LEARN_REWIND    = "midiInput_master_learn_rewind";
	static constexpr auto MIDIINPUT_MASTER_LEARN_PLAYSTOP  = "midiInput_master_learn_playStop";
	static constexpr auto MIDIINPUT_MASTER_LEARN_ACTIONREC = "midiInput_master_learn_actionRec";
	static constexpr auto MIDIINPUT_MASTER_LEARN_INPUTREC  = "midiInput_master_learn_inputRec";
	static constexpr auto MIDIINPUT_MASTER_LEARN_METRONOME = "midiInput_master_learn_metronome";
	static constexpr auto MIDIINPUT_MASTER_LEARN_INVOLUME  = "midiInput_master_learn_inVolume";
	static constexpr auto MIDIINPUT_MASTER_LEARN_OUTVOLUME = "midiInput_master_learn_outVolume";
	static constexpr auto MIDIINPUT_MASTER_LEARN_SEQDOUBLE = "midiInput_master_learn_seqDouble";
	static constexpr auto MIDIINPUT_MASTER_LEARN_SEQHALF   = "midiInput_master_learn_seqHalf";

	static constexpr auto MIDIINPUT_CHANNEL_TITLE             = "midiInput_channel_title";
	static constexpr auto MIDIINPUT_CHANNEL_ENABLE            = "midiInput_channel_enable";
	static constexpr auto MIDIINPUT_CHANNEL_LEARN_CHANNEL     = "midiInput_channel_learn_channel";
	static constexpr auto MIDIINPUT_CHANNEL_LEARN_KEYPRESS    = "midiInput_channel_learn_keyPress";
	static constexpr auto MIDIINPUT_CHANNEL_LEARN_KEYREL      = "midiInput_channel_learn_keyRel";
	static constexpr auto MIDIINPUT_CHANNEL_LEARN_KEYKILL     = "midiInput_channel_learn_keyKill";
	static constexpr auto MIDIINPUT_CHANNEL_LEARN_ARM         = "midiInput_channel_learn_arm";
	static constexpr auto MIDIINPUT_CHANNEL_LEARN_MUTE        = "midiInput_channel_learn_mute";
	static constexpr auto MIDIINPUT_CHANNEL_LEARN_SOLO        = "midiInput_channel_learn_solo";
	static constexpr auto MIDIINPUT_CHANNEL_LEARN_VOLUME      = "midiInput_channel_learn_volume";
	static constexpr auto MIDIINPUT_CHANNEL_LEARN_PITCH       = "midiInput_channel_learn_pitch";
	static constexpr auto MIDIINPUT_CHANNEL_LEARN_READACTIONS = "midiInput_channel_learn_readActions";

	LangMap();

	const char* get(const std::string&) const;

private:
	Data        m_data;
	std::string m_default;
};

/* -------------------------------------------------------------------------- */

class LangMapper final
{
public:
	/* getMapFilesFound
	Returns a reference to the list of langmaps found. */

	const std::vector<std::string>& getMapFilesFound() const;

	/* get
	Gets a key in the currently loaded langmap file. */

	const char* get(const std::string&) const;

	/* init
	Parses the langmap folders and find the available langmaps. */

	void init();

	/* read
	Reads a langmap from file 'file' and sets it as the current one. */

	int read(const std::string& file);

private:
	/* m_mapsPath
	Path to folder containing langmap files, different between OSes. */

	std::string m_mapsPath;

	/* m_langFiles
	The available .langmap files. Each element of the vector represents 
	a .langmap file found in the langmap folder. */

	std::vector<std::string> m_langFiles;

	/* maps
	The current langmap selected and loaded. It might be the default one (En_US) 
    if no langmaps have been found. */

	LangMap m_map;
};
} // namespace giada::v

#endif
