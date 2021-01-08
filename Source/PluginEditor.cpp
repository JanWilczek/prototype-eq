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
    gain.setRange(-80.0, 20.0, 0.1);
    gain.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    gain.setPopupDisplayEnabled(true, false, this);
    gain.setTextValueSuffix(" dB");
    gain.setValue(0.0);
    gain.addListener(this);

    addAndMakeVisible(&gain);

    cutoffFrequency.setSliderStyle(juce::Slider::Rotary);
    cutoffFrequency.setRange(0, processor.getSampleRate() / 2, 0.5);
    cutoffFrequency.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    cutoffFrequency.setPopupDisplayEnabled(true, false, this);
    cutoffFrequency.setTextValueSuffix(" Hz");
    cutoffFrequency.setValue(2000.0);
    cutoffFrequency.setSkewFactor(0.5);
    cutoffFrequency.addListener(this);

    addAndMakeVisible(&cutoffFrequency);
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
    g.drawFittedText("Cut-off frequency [Hz]", juce::Rectangle<int>{cutoffFrequency.getX() + cutoffFrequency.getWidth() / 2 - cutoffTextWidth / 2, gain.getY() - 40, cutoffTextWidth, 40}, juce::Justification::centred, 1);
}

void PrototypeEQAudioProcessorEditor::resized()
{
    gain.setBounds(40, 30, 20, getHeight() - 60);
    cutoffFrequency.setBounds(gain.getRight() + 100, gain.getY() + gain.getHeight() / 3, 100, 100);
}

void PrototypeEQAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
    if (slider == &gain)
    {
        audioProcessor.setGain(gain.getValue());
    }
    else if (slider == &cutoffFrequency)
    {
        audioProcessor.setCutoffFrequency(cutoffFrequency.getValue());
    }
}
