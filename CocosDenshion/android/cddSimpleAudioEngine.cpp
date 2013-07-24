/****************************************************************************
Copyright (c) 2010 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#include "SimpleAudioEngine.h"
#include "jni/cddandroidAndroidJavaEngine.h"
#include "opensl/cddandroidOpenSLEngine.h"
#include "ccdandroidUtils.h"

namespace CocosDenshion {

    static SimpleAudioEngine *s_pEngine = 0;

    SimpleAudioEngine* SimpleAudioEngine::sharedEngine() {
        if (! s_pEngine) {
            // if (CocosDenshion::android::is_buggy_device()) {
                // use the Java Audio implementation until compatibility is confirmed
                s_pEngine = new CocosDenshion::android::AndroidJavaEngine();
            // } else {
            //     s_pEngine = new CocosDenshion::android::OpenSLEngine();
            // }
        }
    
        return s_pEngine;
    }

    void SimpleAudioEngine::end() {
        if (s_pEngine) {
            delete s_pEngine;
            s_pEngine = NULL;
        }
    }

    SimpleAudioEngine::SimpleAudioEngine() {
    }

    SimpleAudioEngine::~SimpleAudioEngine() {
    }

    // Empty implementations. On Android, only subclasses are meant to be used
    void SimpleAudioEngine::preloadBackgroundMusic(const char* pszFilePath) { }
    void SimpleAudioEngine::playBackgroundMusic(const char* pszFilePath, bool bLoop) { }
    void SimpleAudioEngine::stopBackgroundMusic(bool bReleaseData) { }
    void SimpleAudioEngine::pauseBackgroundMusic() { }
    void SimpleAudioEngine::resumeBackgroundMusic() { }
    void SimpleAudioEngine::rewindBackgroundMusic() { }
    bool SimpleAudioEngine::willPlayBackgroundMusic() { }
    bool SimpleAudioEngine::isBackgroundMusicPlaying() { }
    float SimpleAudioEngine::getBackgroundMusicVolume() { }
    void SimpleAudioEngine::setBackgroundMusicVolume(float volume) { }
    float SimpleAudioEngine::getEffectsVolume() { }
    void SimpleAudioEngine::setEffectsVolume(float volume) { }
    unsigned int SimpleAudioEngine::playEffect(const char* pszFilePath, bool bLoop) { }
    void SimpleAudioEngine::pauseEffect(unsigned int nSoundId) { }
    void SimpleAudioEngine::pauseAllEffects() { }
    void SimpleAudioEngine::resumeEffect(unsigned int nSoundId) { }
    void SimpleAudioEngine::resumeAllEffects() { }
    void SimpleAudioEngine::stopEffect(unsigned int nSoundId) { }
    void SimpleAudioEngine::stopAllEffects() { }
    void SimpleAudioEngine::preloadEffect(const char* pszFilePath) { }
    void SimpleAudioEngine::unloadEffect(const char* pszFilePath) { }
}
