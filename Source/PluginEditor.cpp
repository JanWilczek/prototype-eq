/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
PrototypeEQAudioProcessorEditor::PrototypeEQAudioProcessorEditor (PrototypeEQAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);

    gain.setSliderStyle(juce::Slider::LinearBarVertical);
    gain.setRange(-10.0, 10.0, 0.1);
    gain.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    gain.setPopupDisplayEnabled(true, false, this);
    gain.setTextValueSuffix(" dB");
    gain.setValue(0.0);

    addAndMakeVisible(&gain);

    cutoff_frequency.setSliderStyle(juce::Slider::Rotary);
    cutoff_frequency.setRange(0, processor.getSampleRate() / 2, 0.5);
    cutoff_frequency.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    cutoff_frequency.setPopupDisplayEnabled(true, false, this);
    cutoff_frequency.setTextValueSuffix(" Hz");
    cutoff_frequency.setValue(2000.0);

    addAndMakeVisible(&cutoff_frequency);
}

PrototypeEQAudioProcessorEditor::~PrototypeEQAudioProcessorEditor()
{
}

//==============================================================================
void PrototypeEQAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    auto textBoxWidth = 100;
    g.drawFittedText("Gain [dB]", juce::Rectangle<int>{gain.getX() + gain.getWidth() / 2 - textBoxWidth / 2, gain.getY() - 40, textBoxWidth, 40}, juce::Justification::centred, 1);
    auto cutoffTextWidth = 200;
    g.drawFittedText("Cut-off frequency [Hz]", juce::Rectangle<int>{cutoff_frequency.getX() + cutoff_frequency.getWidth() / 2 - cutoffTextWidth / 2, gain.getY() - 40, cutoffTextWidth, 40}, juce::Justification::centred, 1);
}

void PrototypeEQAudioProcessorEditor::resized()
{
    gain.setBounds(40, 30, 20, getHeight() - 60);
    cutoff_frequency.setBounds(gain.getRight() + 100, gain.getY() + gain.getHeight() / 3, 100, 100);
}

void PrototypeEQAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
    if (slider == &gain)
    {
        audioProcessor.setGain(gain.getValue());
    }
    else if (slider == &cutoff_frequency)
    {
        audioProcessor.setCutoffFrequency(cutoff_frequency.getValue());
    }
}
