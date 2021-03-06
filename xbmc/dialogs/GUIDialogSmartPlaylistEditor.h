#pragma once

/*
 *      Copyright (C) 2005-2013 Team XBMC
 *      http://kodi.tv
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#include "guilib/GUIDialog.h"
#include "playlists/SmartPlayList.h"

class CFileItemList;

class CGUIDialogSmartPlaylistEditor :
      public CGUIDialog
{
public:
  enum PLAYLIST_TYPE { TYPE_SONGS = 1, TYPE_ALBUMS, TYPE_ARTISTS, TYPE_MIXED, TYPE_MUSICVIDEOS, TYPE_MOVIES, TYPE_TVSHOWS, TYPE_EPISODES };

  CGUIDialogSmartPlaylistEditor(void);
  ~CGUIDialogSmartPlaylistEditor(void) override;
  bool OnMessage(CGUIMessage& message) override;
  bool OnBack(int actionID) override;
  void OnInitWindow() override;
  void OnDeinitWindow(int nextWindowID) override;

  static bool EditPlaylist(const std::string &path, const std::string &type = "");
  static bool NewPlaylist(const std::string &type);

protected:
  void OnRuleList(int item);
  void OnRuleAdd();
  void OnRuleRemove(int item);
  void OnMatch();
  void OnLimit();
  void OnName();
  void OnType();
  void OnOrder();
  void OnOrderDirection();
  void OnGroupBy();
  void OnGroupMixed();
  void OnOK();
  void OnCancel();
  void OnPopupMenu(int item);
  void UpdateButtons();
  void UpdateRuleControlButtons();
  int GetSelectedItem();
  void HighlightItem(int item);
  std::vector<PLAYLIST_TYPE> GetAllowedTypes(const std::string& mode);
  PLAYLIST_TYPE ConvertType(const std::string &type);
  std::string ConvertType(PLAYLIST_TYPE type);
  std::string GetLocalizedType(PLAYLIST_TYPE type);

  CSmartPlaylist m_playlist;

  // our list of rules for display purposes
  CFileItemList* m_ruleLabels;

  std::string m_path;
  bool m_cancelled;
  std::string m_mode;  // mode we're in (partymode etc.)
};
