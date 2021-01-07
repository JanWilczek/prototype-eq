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
class PrototypeEQAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                         private juce::Slider::Listener
{
public:
    PrototypeEQAudioProcessorEditor (PrototypeEQAudioProcessor&);
    ~PrototypeEQAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    void sliderValueChanged(juce::Slider* slider) override;

    PrototypeEQAudioProcessor& audioProcessor;
    juce::Slider gain;
    juce::Slider cutoff_frequency;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PrototypeEQAudioProcessorEditor)
};
