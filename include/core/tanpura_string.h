#pragma once

#include <map>
#include <string>
#include <vector>

#include "cinder/audio/audio.h"
#include "cinder/audio/Source.h"

namespace tanpura {
    class TanpuraString {
    public:
        //An enum to store the pitches available
        enum class Pitch {
            A,
            As,
            B,
            C,
            Cs,
            D,
            Ds,
            E,
            F,
            Fs,
            G,
            Gs,
        };
        
        /**
         * Constructor for a Tanpura String Object
         * @param pitch pitch that the sound file is
         * @param source_file_ the source file to create a buffer from
         */
        TanpuraString(string source_file_path, Pitch pitch);
        
        /**
         * Getter for mBufferPlayer
         * @return mBufferPlayer
         */
        const audio::BufferPlayerNodeRef &GetMBufferPlayer() const;
        
        /**
         * Getter for Gain Node
         * @return gain_
         */
        const audio::GainNodeRef &GetGain() const;

        /**
         * Getter for Pitch Name
         * @return gain_
         */
        const string &getPitchName() const;

    private:
        Pitch pitch_;
        string pitch_name_;

        audio::BufferPlayerNodeRef mBufferPlayer_;
        audio::SourceFileRef source_file_;
        audio::GainNodeRef gain_;
}