/*
 * TeamSpeak 3 G-key plugin
 * Author: Jules Blok (jules@aerix.nl)
 *
 * Copyright (c) 2008-2012 TeamSpeak Systems GmbH
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/* Global variables */
extern bool pttActive;
extern bool vadActive;
extern bool inputActive;
extern bool whisperActive;

/* High-level TeamSpeak functions */

/* Error handler */
void ErrorMessage(uint64 scHandlerID, char* message);

/* Getters */
uint64 GetActiveServerConnectionHandlerID();
uint64 GetServerHandleByVariable(char* value, size_t flag);
uint64 GetChannelIDByVariable(uint64 scHandlerID, char* value, size_t flag);
anyID GetClientIDByVariable(uint64 scHandlerID, char* value, size_t flag);
uint64 GetParentChannel(uint64 scHandlerID, uint64 subchannel);
uint64 GetChannelIDFromPath(uint64 scHandlerID, char* path);

/* Communication */
int SetPushToTalk(uint64 scHandlerID, bool shouldTalk);
int SetVoiceActivation(uint64 scHandlerID, bool shouldActivate);
int SetContinuousTransmission(uint64 scHandlerID, bool shouldActivate);
int SetInputMute(uint64 scHandlerID, bool shouldMute);
int SetOutputMute(uint64 scHandlerID, bool shouldMute);

/* Whispering */
void GetWhisperList(uint64 scHandlerID);
int SetWhisperList(uint64 scHandlerID, bool shouldWhisper);
void WhisperListClear(uint64 scHandlerID);
void WhisperAddClient(uint64 scHandlerID, anyID client);
void WhisperAddChannel(uint64 scHandlerID, uint64 channel);

/* Server interaction */
int SetActiveServer(uint64 handle);
int SetGlobalAway(bool isAway);
int JoinChannel(uint64 scHandlerID, uint64 channel);
int ServerKickClient(uint64 scHandlerID, anyID client);
int ChannelKickClient(uint64 scHandlerID, anyID client);
int JoinChannelRelative(uint64 scHandlerID, bool next);
inline int JoinNextChannel(uint64 scHandlerID) { return JoinChannelRelative(scHandlerID, true); }
inline int JoinPrevChannel(uint64 scHandlerID) { return JoinChannelRelative(scHandlerID, false); }
int SetActiveServerRelative(uint64 scHandlerID, bool next);
inline int SetNextActiveServer(uint64 scHandlerID) { return SetActiveServerRelative(scHandlerID, true); }
inline int SetPrevActiveServer(uint64 scHandlerID) { return SetActiveServerRelative(scHandlerID, false); }

/* Miscellaneous */
int SetMasterVolume(uint64 scHandlerID, float value);
int MuteClient(uint64 scHandlerID, anyID client);
int UnmuteClient(uint64 scHandlerID, anyID client);

#endif
