// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_RENDERER_MEDIA_ANDROID_PROXY_MEDIA_KEYS_H_
#define CONTENT_RENDERER_MEDIA_ANDROID_PROXY_MEDIA_KEYS_H_

#include "base/basictypes.h"
#include "media/base/media_keys.h"

class GURL;

namespace content {

class WebMediaPlayerProxyAndroid;

// MediaKeys wrapper of the WebMediaPlayerProxyAndroid.
// TODO(xhwang): Remove |player_id| from WebMediaPlayerProxyAndroid, make
// WebMediaPlayerProxyAndroid a subclass of media::MediaKeys, then remove this
// class!
class ProxyMediaKeys : public media::MediaKeys {
 public:
  ProxyMediaKeys(WebMediaPlayerProxyAndroid* proxy,
                 int media_keys_id,
                 const media::KeyAddedCB& key_added_cb,
                 const media::KeyErrorCB& key_error_cb,
                 const media::KeyMessageCB& key_message_cb);
  virtual ~ProxyMediaKeys();

  void InitializeCDM(const std::string& key_system, const GURL& frame_url);

  // MediaKeys implementation.
  virtual bool GenerateKeyRequest(const std::string& type,
                                  const uint8* init_data,
                                  int init_data_length) OVERRIDE;
  virtual void AddKey(const uint8* key, int key_length,
                      const uint8* init_data, int init_data_length,
                      const std::string& session_id) OVERRIDE;
  virtual void CancelKeyRequest(const std::string& session_id) OVERRIDE;

  // Callbacks.
  void OnKeyAdded(const std::string& session_id);
  void OnKeyError(const std::string& session_id,
                  media::MediaKeys::KeyError error_code,
                  int system_code);
  void OnKeyMessage(const std::string& session_id,
                    const std::vector<uint8>& message,
                    const std::string& destination_url);

 private:
  WebMediaPlayerProxyAndroid* proxy_;
  int media_keys_id_;
  media::KeyAddedCB key_added_cb_;
  media::KeyErrorCB key_error_cb_;
  media::KeyMessageCB key_message_cb_;

  DISALLOW_COPY_AND_ASSIGN (ProxyMediaKeys);
};

}  // namespace content

#endif  // CONTENT_RENDERER_MEDIA_ANDROID_PROXY_MEDIA_KEYS_H_
