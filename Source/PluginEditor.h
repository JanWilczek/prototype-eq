/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class PrototypeEQAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    PrototypeEQAudioProcessorEditor (PrototypeEQAudioProcessor&);
    ~PrototypeEQAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    PrototypeEQAudioProcessor& audioProcessor;
    juce::Slider gain;
    juce::Slider cutoff_frequency;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PrototypeEQAudioProcessorEditor)
};
