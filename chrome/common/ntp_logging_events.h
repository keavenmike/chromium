// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_COMMON_NTP_LOGGING_EVENTS_H_
#define CHROME_COMMON_NTP_LOGGING_EVENTS_H_

// The different types of events that are logged from the NTP.
enum NTPLoggingEventType {
  // The user moused over an NTP tile or title.
  NTP_MOUSEOVER = 0,

  // The page attempted to load a thumbnail image.
  NTP_THUMBNAIL_ATTEMPT = 1,

  // There was an error in loading a thumbnail image.
  NTP_THUMBNAIL_ERROR = 2,

  NTP_NUM_EVENT_TYPES
};

#endif  // CHROME_COMMON_NTP_LOGGING_EVENTS_H_
