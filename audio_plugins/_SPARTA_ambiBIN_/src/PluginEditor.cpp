/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.3.2

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
#include "saf_hoa.h"
//[/MiscUserDefs]

//==============================================================================
PluginEditor::PluginEditor (PluginProcessor* ownerFilter)
    : AudioProcessorEditor(ownerFilter), fileChooser ("File", File(), true, false, false,
      "*.sofa;*.nc;", String(),
      "Load SOFA File")
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    TBuseDefaultHRIRs.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (TBuseDefaultHRIRs.get());
    TBuseDefaultHRIRs->setButtonText (String());
    TBuseDefaultHRIRs->addListener (this);

    TBuseDefaultHRIRs->setBounds (614, 60, 21, 24);

    CBorderPreset.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (CBorderPreset.get());
    CBorderPreset->setEditableText (false);
    CBorderPreset->setJustificationType (Justification::centredLeft);
    CBorderPreset->setTextWhenNothingSelected (TRANS("Default"));
    CBorderPreset->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    CBorderPreset->addListener (this);

    CBorderPreset->setBounds (122, 62, 90, 20);

    CBchFormat.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (CBchFormat.get());
    CBchFormat->setEditableText (false);
    CBchFormat->setJustificationType (Justification::centredLeft);
    CBchFormat->setTextWhenNothingSelected (TRANS("ACN"));
    CBchFormat->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    CBchFormat->addItem (TRANS("ACN"), 1);
    CBchFormat->addListener (this);

    CBchFormat->setBounds (314, 63, 112, 20);

    CBnormScheme.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (CBnormScheme.get());
    CBnormScheme->setEditableText (false);
    CBnormScheme->setJustificationType (Justification::centredLeft);
    CBnormScheme->setTextWhenNothingSelected (TRANS("N3D"));
    CBnormScheme->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    CBnormScheme->addItem (TRANS("N3D"), 1);
    CBnormScheme->addItem (TRANS("SN3D"), 2);
    CBnormScheme->addListener (this);

    CBnormScheme->setBounds (314, 88, 112, 20);

    TBmaxRE.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (TBmaxRE.get());
    TBmaxRE->setButtonText (String());
    TBmaxRE->addListener (this);

    TBmaxRE->setBounds (132, 86, 22, 24);

    s_yaw.reset (new Slider ("new slider"));
    addAndMakeVisible (s_yaw.get());
    s_yaw->setRange (-180, 180, 0.01);
    s_yaw->setSliderStyle (Slider::LinearHorizontal);
    s_yaw->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    s_yaw->setColour (Slider::backgroundColourId, Colour (0xff263238));
    s_yaw->setColour (Slider::trackColourId, Colour (0xff181f22));
    s_yaw->setColour (Slider::textBoxTextColourId, Colours::white);
    s_yaw->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    s_yaw->addListener (this);

    s_yaw->setBounds (80, 144, 120, 38);

    s_pitch.reset (new Slider ("new slider"));
    addAndMakeVisible (s_pitch.get());
    s_pitch->setRange (-180, 180, 0.01);
    s_pitch->setSliderStyle (Slider::LinearVertical);
    s_pitch->setTextBoxStyle (Slider::TextBoxRight, false, 80, 20);
    s_pitch->setColour (Slider::backgroundColourId, Colour (0xff263238));
    s_pitch->setColour (Slider::trackColourId, Colour (0xff181f22));
    s_pitch->setColour (Slider::textBoxTextColourId, Colours::white);
    s_pitch->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    s_pitch->addListener (this);

    s_pitch->setBounds (208, 110, 96, 112);

    s_roll.reset (new Slider ("new slider"));
    addAndMakeVisible (s_roll.get());
    s_roll->setRange (-180, 180, 0.01);
    s_roll->setSliderStyle (Slider::LinearVertical);
    s_roll->setTextBoxStyle (Slider::TextBoxRight, false, 80, 20);
    s_roll->setColour (Slider::backgroundColourId, Colour (0xff263238));
    s_roll->setColour (Slider::trackColourId, Colour (0xff181f22));
    s_roll->setColour (Slider::textBoxTextColourId, Colours::white);
    s_roll->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    s_roll->addListener (this);

    s_roll->setBounds (328, 110, 96, 112);

    te_oscport.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (te_oscport.get());
    te_oscport->setMultiLine (false);
    te_oscport->setReturnKeyStartsNewLine (false);
    te_oscport->setReadOnly (false);
    te_oscport->setScrollbarsShown (true);
    te_oscport->setCaretVisible (false);
    te_oscport->setPopupMenuEnabled (true);
    te_oscport->setColour (TextEditor::textColourId, Colours::white);
    te_oscport->setColour (TextEditor::backgroundColourId, Colour (0x00ffffff));
    te_oscport->setColour (TextEditor::outlineColourId, Colour (0x68a3a2a2));
    te_oscport->setText (String());

    te_oscport->setBounds (16, 200, 56, 18);

    label_N_dirs.reset (new Label ("new label",
                                   String()));
    addAndMakeVisible (label_N_dirs.get());
    label_N_dirs->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label_N_dirs->setJustificationType (Justification::centredLeft);
    label_N_dirs->setEditable (false, false, false);
    label_N_dirs->setColour (Label::outlineColourId, Colour (0x68a3a2a2));
    label_N_dirs->setColour (TextEditor::textColourId, Colours::black);
    label_N_dirs->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label_N_dirs->setBounds (536, 120, 96, 24);

    label_HRIR_len.reset (new Label ("new label",
                                     String()));
    addAndMakeVisible (label_HRIR_len.get());
    label_HRIR_len->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label_HRIR_len->setJustificationType (Justification::centredLeft);
    label_HRIR_len->setEditable (false, false, false);
    label_HRIR_len->setColour (Label::outlineColourId, Colour (0x68a3a2a2));
    label_HRIR_len->setColour (TextEditor::textColourId, Colours::black);
    label_HRIR_len->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label_HRIR_len->setBounds (536, 144, 96, 24);

    label_HRIR_fs.reset (new Label ("new label",
                                    String()));
    addAndMakeVisible (label_HRIR_fs.get());
    label_HRIR_fs->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label_HRIR_fs->setJustificationType (Justification::centredLeft);
    label_HRIR_fs->setEditable (false, false, false);
    label_HRIR_fs->setColour (Label::outlineColourId, Colour (0x68a3a2a2));
    label_HRIR_fs->setColour (TextEditor::textColourId, Colours::black);
    label_HRIR_fs->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label_HRIR_fs->setBounds (536, 168, 96, 24);

    label_DAW_fs.reset (new Label ("new label",
                                   String()));
    addAndMakeVisible (label_DAW_fs.get());
    label_DAW_fs->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label_DAW_fs->setJustificationType (Justification::centredLeft);
    label_DAW_fs->setEditable (false, false, false);
    label_DAW_fs->setColour (Label::outlineColourId, Colour (0x68a3a2a2));
    label_DAW_fs->setColour (TextEditor::textColourId, Colours::black);
    label_DAW_fs->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label_DAW_fs->setBounds (536, 192, 96, 24);

    t_flipPitch.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (t_flipPitch.get());
    t_flipPitch->setButtonText (String());
    t_flipPitch->addListener (this);

    t_flipPitch->setBounds (260, 182, 23, 24);

    t_flipRoll.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (t_flipRoll.get());
    t_flipRoll->setButtonText (String());
    t_flipRoll->addListener (this);

    t_flipRoll->setBounds (376, 182, 23, 24);

    t_flipYaw.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (t_flipYaw.get());
    t_flipYaw->setButtonText (String());
    t_flipYaw->addListener (this);

    t_flipYaw->setBounds (128, 182, 23, 24);

    TBcompEQ.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (TBcompEQ.get());
    TBcompEQ->setButtonText (String());
    TBcompEQ->addListener (this);

    TBcompEQ->setBounds (656, -16, 32, 24);

    TBrpyFlag.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (TBrpyFlag.get());
    TBrpyFlag->setButtonText (String());
    TBrpyFlag->addListener (this);

    TBrpyFlag->setBounds (59, 160, 24, 24);

    TBenableRot.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (TBenableRot.get());
    TBenableRot->setButtonText (String());
    TBenableRot->addListener (this);

    TBenableRot->setBounds (59, 138, 24, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (656, 232);


    //[Constructor] You can add your own custom stuff here..

    /* handle to pluginProcessor */
	hVst = ownerFilter;

    /* init OpenGL */
    openGLContext.setMultisamplingEnabled(true);
    openGLContext.attachTo(*this);

    /* add options to combo boxes */
    CBorderPreset->addItem (TRANS("Omni"), INPUT_OMNI);
    CBorderPreset->addItem (TRANS("1st order"), INPUT_ORDER_FIRST);
    CBorderPreset->addItem (TRANS("2nd order"), INPUT_ORDER_SECOND);
    CBorderPreset->addItem (TRANS("3rd order"), INPUT_ORDER_THIRD);
    CBorderPreset->addItem (TRANS("4th order"), INPUT_ORDER_FOURTH);
    CBorderPreset->addItem (TRANS("5th order"), INPUT_ORDER_FIFTH);
    CBorderPreset->addItem (TRANS("6th order"), INPUT_ORDER_SIXTH);
    CBorderPreset->addItem (TRANS("7th order"), INPUT_ORDER_SEVENTH);

    /* file loader */
    addAndMakeVisible (fileChooser);
    fileChooser.addListener (this);
    fileChooser.setBounds (458, 86, 168, 20);

    /* grab current parameter settings */
    TBuseDefaultHRIRs->setToggleState(ambi_bin_getUseDefaultHRIRsflag(hVst->hAmbi), dontSendNotification);
    CBchFormat->setSelectedId(ambi_bin_getChOrder(hVst->hAmbi), dontSendNotification);
    CBnormScheme->setSelectedId(ambi_bin_getNormType(hVst->hAmbi), dontSendNotification);
    CBorderPreset->setSelectedId(ambi_bin_getInputOrderPreset(hVst->hAmbi), dontSendNotification);
    TBmaxRE->setToggleState(ambi_bin_getDecEnableMaxrE(hVst->hAmbi), dontSendNotification);
    TBcompEQ->setToggleState(ambi_bin_getEnablePhaseManip(hVst->hAmbi), dontSendNotification);
    TBenableRot->setToggleState(ambi_bin_getEnableRotation(hVst->hAmbi), dontSendNotification);
    s_yaw->setValue(ambi_bin_getYaw(hVst->hAmbi), dontSendNotification);
    s_pitch->setValue(ambi_bin_getPitch(hVst->hAmbi), dontSendNotification);
    s_roll->setValue(ambi_bin_getRoll(hVst->hAmbi), dontSendNotification);
    t_flipYaw->setToggleState((bool)ambi_bin_getFlipYaw(hVst->hAmbi), dontSendNotification);
    t_flipPitch->setToggleState((bool)ambi_bin_getFlipPitch(hVst->hAmbi), dontSendNotification);
    t_flipRoll->setToggleState((bool)ambi_bin_getFlipRoll(hVst->hAmbi), dontSendNotification);
    te_oscport->setText(String(hVst->getOscPortID()), dontSendNotification);
    TBrpyFlag->setToggleState((bool)ambi_bin_getRPYflag(hVst->hAmbi), dontSendNotification);

	/* Specify screen refresh rate */
    startTimer(40);//80); /*ms (40ms = 25 frames per second) */

    /* warnings */
    currentWarning = k_warning_none;

    //[/Constructor]
}

PluginEditor::~PluginEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    TBuseDefaultHRIRs = nullptr;
    CBorderPreset = nullptr;
    CBchFormat = nullptr;
    CBnormScheme = nullptr;
    TBmaxRE = nullptr;
    s_yaw = nullptr;
    s_pitch = nullptr;
    s_roll = nullptr;
    te_oscport = nullptr;
    label_N_dirs = nullptr;
    label_HRIR_len = nullptr;
    label_HRIR_fs = nullptr;
    label_DAW_fs = nullptr;
    t_flipPitch = nullptr;
    t_flipRoll = nullptr;
    t_flipYaw = nullptr;
    TBcompEQ = nullptr;
    TBrpyFlag = nullptr;
    TBenableRot = nullptr;


    //[Destructor]. You can add your own custom destruction code here..

    //[/Destructor]
}

//==============================================================================
void PluginEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    {
        int x = 0, y = 30, width = 656, height = 202;
        Colour fillColour1 = Colour (0xff5b6d76), fillColour2 = Colour (0xff073642);
        Colour strokeColour = Colour (0xffa3a4a5);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (ColourGradient (fillColour1,
                                       336.0f - 0.0f + x,
                                       152.0f - 30.0f + y,
                                       fillColour2,
                                       656.0f - 0.0f + x,
                                       232.0f - 30.0f + y,
                                       true));
        g.fillRect (x, y, width, height);
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 2);

    }

    {
        int x = 12, y = 58, width = 207, height = 54;
        Colour fillColour = Colour (0x13f4f4f4);
        Colour strokeColour = Colour (0x67a0a0a0);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 1);

    }

    {
        int x = 12, y = 57, width = 207, height = 29;
        Colour fillColour = Colour (0x08f4f4f4);
        Colour strokeColour = Colour (0x35a0a0a0);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 1);

    }

    {
        int x = 12, y = 111, width = 424, height = 112;
        Colour fillColour = Colour (0x13f4f4f4);
        Colour strokeColour = Colour (0x67a0a0a0);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 1);

    }

    {
        int x = 12, y = 136, width = 73, height = 87;
        Colour fillColour = Colour (0x08f4f4f4);
        Colour strokeColour = Colour (0x3aa0a0a0);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 1);

    }

    {
        int x = 218, y = 58, width = 218, height = 54;
        Colour fillColour = Colour (0x13f4f4f4);
        Colour strokeColour = Colour (0x67a0a0a0);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 1);

    }

    {
        int x = 446, y = 58, width = 196, height = 54;
        Colour fillColour = Colour (0x13f4f4f4);
        Colour strokeColour = Colour (0x67a0a0a0);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 1);

    }

    {
        int x = 0, y = 0, width = 656, height = 32;
        Colour fillColour = Colour (0xff073642);
        Colour strokeColour = Colour (0xdcbdbdbd);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 3);

    }

    {
        int x = -24, y = 0, width = 200, height = 32;
        String text (TRANS("AmbiBIN"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (18.80f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 164, y = 32, width = 149, height = 30;
        String text (TRANS("Decoding Settings"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 520, y = 32, width = 113, height = 30;
        String text (TRANS("Output"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 459, y = 56, width = 165, height = 30;
        String text (TRANS("Use Default HRIR set:"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 19, y = 56, width = 125, height = 30;
        String text (TRANS("Decode Order:"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 227, y = 56, width = 132, height = 30;
        String text (TRANS("CH Order:"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 227, y = 82, width = 132, height = 30;
        String text (TRANS("Norm:"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 19, y = 108, width = 133, height = 30;
        String text (TRANS("Rotation"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 19, y = 82, width = 125, height = 30;
        String text (TRANS("Enable max_rE:"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 125, y = 117, width = 63, height = 30;
        String text (TRANS("\\ypr[0]"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (11.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 223, y = 117, width = 63, height = 30;
        String text (TRANS("Pitch"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 341, y = 117, width = 63, height = 30;
        String text (TRANS("Roll"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 355, y = 200, width = 63, height = 24;
        String text (TRANS("+/-"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 240, y = 197, width = 63, height = 27;
        String text (TRANS("+/-"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 109, y = 197, width = 63, height = 27;
        String text (TRANS("+/-"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 93, y = 117, width = 60, height = 30;
        String text (TRANS("Yaw"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 261, y = 117, width = 63, height = 30;
        String text (TRANS("\\ypr[1]"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (11.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 373, y = 117, width = 63, height = 30;
        String text (TRANS("\\ypr[2]"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (11.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 446, y = 111, width = 196, height = 112;
        Colour fillColour = Colour (0x13f4f4f4);
        Colour strokeColour = Colour (0x67a0a0a0);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 1);

    }

    {
        int x = 459, y = 116, width = 132, height = 30;
        String text (TRANS("N dirs:"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 459, y = 140, width = 132, height = 30;
        String text (TRANS("HRIR len:"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 459, y = 164, width = 132, height = 30;
        String text (TRANS("HRIR fs:"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 459, y = 188, width = 132, height = 30;
        String text (TRANS("DAW fs:"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 19, y = 180, width = 63, height = 23;
        String text (TRANS("OSC port:"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (11.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 659, y = -15, width = 80, height = 30;
        String text (TRANS("Comp. EQ:"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 19, y = 160, width = 63, height = 23;
        String text (TRANS("R-P-Y:"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (11.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 19, y = 138, width = 61, height = 23;
        String text (TRANS("Enable:"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (11.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    //[UserPaint] Add your own custom painting code here..

	g.setColour(Colours::white);
	g.setFont(Font(11.00f, Font::plain));
	g.drawText(TRANS("Ver ") + JucePlugin_VersionString + BUILD_VER_SUFFIX + TRANS(", Build Date ") + __DATE__ + TRANS(" "),
		150, 16, 530, 11,
		Justification::centredLeft, true);

    /* display warning message */
    g.setColour(Colours::red);
    g.setFont(Font(11.00f, Font::plain));
    switch (currentWarning){
        case k_warning_none:
            break;
        case k_warning_frameSize:
            g.drawText(TRANS("Set frame size to multiple of ") + String(FRAME_SIZE),
                       getBounds().getWidth()-225, 16, 530, 11,
                       Justification::centredLeft, true);
            break;
        case k_warning_NinputCH:
            g.drawText(TRANS("Insufficient number of input channels (") + String(hVst->getTotalNumInputChannels()) +
                       TRANS("/") + String(ambi_bin_getNSHrequired(hVst->hAmbi)) + TRANS(")"),
                       getBounds().getWidth()-225, 16, 530, 11,
                       Justification::centredLeft, true);
            break;
        case k_warning_NoutputCH:
            g.drawText(TRANS("Insufficient number of output channels (") + String(hVst->getTotalNumOutputChannels()) +
                       TRANS("/") + String(ambi_bin_getNumEars()) + TRANS(")"),
                       getBounds().getWidth()-225, 16, 530, 11,
                       Justification::centredLeft, true);
            break;
    }

    //[/UserPaint]
}

void PluginEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..

    //[/UserResized]
}

void PluginEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == TBuseDefaultHRIRs.get())
    {
        //[UserButtonCode_TBuseDefaultHRIRs] -- add your button handler code here..
        ambi_bin_setUseDefaultHRIRsflag(hVst->hAmbi, (int)TBuseDefaultHRIRs->getToggleState());
        //[/UserButtonCode_TBuseDefaultHRIRs]
    }
    else if (buttonThatWasClicked == TBmaxRE.get())
    {
        //[UserButtonCode_TBmaxRE] -- add your button handler code here..
        ambi_bin_setDecEnableMaxrE(hVst->hAmbi, (int)TBmaxRE->getToggleState());
        //[/UserButtonCode_TBmaxRE]
    }
    else if (buttonThatWasClicked == t_flipPitch.get())
    {
        //[UserButtonCode_t_flipPitch] -- add your button handler code here..
        ambi_bin_setFlipPitch(hVst->hAmbi, (int)t_flipPitch->getToggleState());
        //[/UserButtonCode_t_flipPitch]
    }
    else if (buttonThatWasClicked == t_flipRoll.get())
    {
        //[UserButtonCode_t_flipRoll] -- add your button handler code here..
        ambi_bin_setFlipRoll(hVst->hAmbi, (int)t_flipRoll->getToggleState());
        //[/UserButtonCode_t_flipRoll]
    }
    else if (buttonThatWasClicked == t_flipYaw.get())
    {
        //[UserButtonCode_t_flipYaw] -- add your button handler code here..
        ambi_bin_setFlipYaw(hVst->hAmbi, (int)t_flipYaw->getToggleState());
        //[/UserButtonCode_t_flipYaw]
    }
    else if (buttonThatWasClicked == TBcompEQ.get())
    {
        //[UserButtonCode_TBcompEQ] -- add your button handler code here..
        ambi_bin_setEnablePhaseManip(hVst->hAmbi, (int)TBcompEQ->getToggleState());
        //[/UserButtonCode_TBcompEQ]
    }
    else if (buttonThatWasClicked == TBrpyFlag.get())
    {
        //[UserButtonCode_TBrpyFlag] -- add your button handler code here..
        ambi_bin_setRPYflag(hVst->hAmbi, (int)TBrpyFlag->getToggleState());
        //[/UserButtonCode_TBrpyFlag]
    }
    else if (buttonThatWasClicked == TBenableRot.get())
    {
        //[UserButtonCode_TBenableRot] -- add your button handler code here..
        ambi_bin_setEnableRotation(hVst->hAmbi, (int)TBenableRot->getToggleState());
        //[/UserButtonCode_TBenableRot]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void PluginEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == CBorderPreset.get())
    {
        //[UserComboBoxCode_CBorderPreset] -- add your combo box handling code here..
        ambi_bin_setInputOrderPreset(hVst->hAmbi, (INPUT_ORDERS)CBorderPreset->getSelectedId());
        //[/UserComboBoxCode_CBorderPreset]
    }
    else if (comboBoxThatHasChanged == CBchFormat.get())
    {
        //[UserComboBoxCode_CBchFormat] -- add your combo box handling code here..
        ambi_bin_setChOrder(hVst->hAmbi, CBchFormat->getSelectedId());
        //[/UserComboBoxCode_CBchFormat]
    }
    else if (comboBoxThatHasChanged == CBnormScheme.get())
    {
        //[UserComboBoxCode_CBnormScheme] -- add your combo box handling code here..
        ambi_bin_setNormType(hVst->hAmbi, CBnormScheme->getSelectedId());
        //[/UserComboBoxCode_CBnormScheme]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void PluginEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == s_yaw.get())
    {
        //[UserSliderCode_s_yaw] -- add your slider handling code here..
        ambi_bin_setYaw(hVst->hAmbi, (float)s_yaw->getValue());
        //[/UserSliderCode_s_yaw]
    }
    else if (sliderThatWasMoved == s_pitch.get())
    {
        //[UserSliderCode_s_pitch] -- add your slider handling code here..
        ambi_bin_setPitch(hVst->hAmbi, (float)s_pitch->getValue());
        //[/UserSliderCode_s_pitch]
    }
    else if (sliderThatWasMoved == s_roll.get())
    {
        //[UserSliderCode_s_roll] -- add your slider handling code here..
        ambi_bin_setRoll(hVst->hAmbi, (float)s_roll->getValue());
        //[/UserSliderCode_s_roll]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void PluginEditor::timerCallback()
{
    /* parameters whos values can change internally should be periodically refreshed */
    TBuseDefaultHRIRs->setToggleState(ambi_bin_getUseDefaultHRIRsflag(hVst->hAmbi), dontSendNotification);
    label_N_dirs->setText(String(ambi_bin_getNDirs(hVst->hAmbi)), dontSendNotification);
    label_HRIR_len->setText(String(ambi_bin_getHRIRlength(hVst->hAmbi)), dontSendNotification);
    label_HRIR_fs->setText(String(ambi_bin_getHRIRsamplerate(hVst->hAmbi)), dontSendNotification);
    label_DAW_fs->setText(String(ambi_bin_getDAWsamplerate(hVst->hAmbi)), dontSendNotification);
    s_yaw->setValue(ambi_bin_getYaw(hVst->hAmbi), dontSendNotification);
    s_pitch->setValue(ambi_bin_getPitch(hVst->hAmbi), dontSendNotification);
    s_roll->setValue(ambi_bin_getRoll(hVst->hAmbi), dontSendNotification);

	/* Some parameters shouldn't be enabled if playback is ongoing */
	if (hVst->getIsPlaying()) {
		CBorderPreset->setEnabled(false);
		fileChooser.setEnabled(false);
		TBuseDefaultHRIRs->setEnabled(false);
		TBmaxRE->setEnabled(false);
	}
	else {
		CBorderPreset->setWantsKeyboardFocus(false);
		CBorderPreset->setEnabled(true);
		fileChooser.setEnabled(true);
		TBuseDefaultHRIRs->setEnabled(true);
		TBmaxRE->setEnabled(true);
		ambi_bin_checkReInit(hVst->hAmbi);
	}

    /* display warning message, if needed */
    if ((hVst->getCurrentBlockSize() % FRAME_SIZE) != 0){
        currentWarning = k_warning_frameSize;
        repaint(0,0,getWidth(),32);
    }
    else if ((hVst->getCurrentNumInputs() < ambi_bin_getNSHrequired(hVst->hAmbi))){
        currentWarning = k_warning_NinputCH;
        repaint(0,0,getWidth(),32);
    }
    else if ((hVst->getCurrentNumOutputs() < ambi_bin_getNumEars())){
        currentWarning = k_warning_NoutputCH;
        repaint(0,0,getWidth(),32);
    }
    else if(currentWarning){
        currentWarning = k_warning_none;
        repaint(0,0,getWidth(),32);
    }

    /* check if OSC port has changed */
    if(hVst->getOscPortID() != te_oscport->getText().getIntValue())
        hVst->setOscPortID(te_oscport->getText().getIntValue());
}



//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PluginEditor" componentName=""
                 parentClasses="public AudioProcessorEditor, public Timer, private FilenameComponentListener"
                 constructorParams="PluginProcessor* ownerFilter" variableInitialisers="AudioProcessorEditor(ownerFilter), fileChooser (&quot;File&quot;, File(), true, false, false,&#10;                       &quot;*.sofa;*.nc;&quot;, String(),&#10;                       &quot;Load SOFA File&quot;)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="656" initialHeight="232">
  <BACKGROUND backgroundColour="ffffffff">
    <RECT pos="0 30 656 202" fill=" radial: 336 152, 656 232, 0=ff5b6d76, 1=ff073642"
          hasStroke="1" stroke="1.9, mitered, butt" strokeColour="solid: ffa3a4a5"/>
    <RECT pos="12 58 207 54" fill="solid: 13f4f4f4" hasStroke="1" stroke="0.8, mitered, butt"
          strokeColour="solid: 67a0a0a0"/>
    <RECT pos="12 57 207 29" fill="solid: 8f4f4f4" hasStroke="1" stroke="0.8, mitered, butt"
          strokeColour="solid: 35a0a0a0"/>
    <RECT pos="12 111 424 112" fill="solid: 13f4f4f4" hasStroke="1" stroke="0.8, mitered, butt"
          strokeColour="solid: 67a0a0a0"/>
    <RECT pos="12 136 73 87" fill="solid: 8f4f4f4" hasStroke="1" stroke="0.8, mitered, butt"
          strokeColour="solid: 3aa0a0a0"/>
    <RECT pos="218 58 218 54" fill="solid: 13f4f4f4" hasStroke="1" stroke="0.8, mitered, butt"
          strokeColour="solid: 67a0a0a0"/>
    <RECT pos="446 58 196 54" fill="solid: 13f4f4f4" hasStroke="1" stroke="0.8, mitered, butt"
          strokeColour="solid: 67a0a0a0"/>
    <RECT pos="0 0 656 32" fill="solid: ff073642" hasStroke="1" stroke="2.7, mitered, butt"
          strokeColour="solid: dcbdbdbd"/>
    <TEXT pos="-24 0 200 32" fill="solid: ffffffff" hasStroke="0" text="AmbiBIN"
          fontname="Default font" fontsize="18.80000000000000071054" kerning="0.00000000000000000000"
          bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
    <TEXT pos="164 32 149 30" fill="solid: ffffffff" hasStroke="0" text="Decoding Settings"
          fontname="Default font" fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
          bold="1" italic="0" justification="33" typefaceStyle="Bold"/>
    <TEXT pos="520 32 113 30" fill="solid: ffffffff" hasStroke="0" text="Output"
          fontname="Default font" fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
          bold="1" italic="0" justification="33" typefaceStyle="Bold"/>
    <TEXT pos="459 56 165 30" fill="solid: ffffffff" hasStroke="0" text="Use Default HRIR set:"
          fontname="Default font" fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
          bold="1" italic="0" justification="33" typefaceStyle="Bold"/>
    <TEXT pos="19 56 125 30" fill="solid: ffffffff" hasStroke="0" text="Decode Order:"
          fontname="Default font" fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
          bold="1" italic="0" justification="33" typefaceStyle="Bold"/>
    <TEXT pos="227 56 132 30" fill="solid: ffffffff" hasStroke="0" text="CH Order:"
          fontname="Default font" fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
          bold="1" italic="0" justification="33" typefaceStyle="Bold"/>
    <TEXT pos="227 82 132 30" fill="solid: ffffffff" hasStroke="0" text="Norm:"
          fontname="Default font" fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
          bold="1" italic="0" justification="33" typefaceStyle="Bold"/>
    <TEXT pos="19 108 133 30" fill="solid: ffffffff" hasStroke="0" text="Rotation"
          fontname="Default font" fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
          bold="1" italic="0" justification="33" typefaceStyle="Bold"/>
    <TEXT pos="19 82 125 30" fill="solid: ffffffff" hasStroke="0" text="Enable max_rE:"
          fontname="Default font" fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
          bold="1" italic="0" justification="33" typefaceStyle="Bold"/>
    <TEXT pos="125 117 63 30" fill="solid: ffffffff" hasStroke="0" text="\ypr[0]"
          fontname="Default font" fontsize="11.00000000000000000000" kerning="0.00000000000000000000"
          bold="0" italic="0" justification="36"/>
    <TEXT pos="223 117 63 30" fill="solid: ffffffff" hasStroke="0" text="Pitch"
          fontname="Default font" fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
          bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
    <TEXT pos="341 117 63 30" fill="solid: ffffffff" hasStroke="0" text="Roll"
          fontname="Default font" fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
          bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
    <TEXT pos="355 200 63 24" fill="solid: ffffffff" hasStroke="0" text="+/-"
          fontname="Default font" fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
          bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
    <TEXT pos="240 197 63 27" fill="solid: ffffffff" hasStroke="0" text="+/-"
          fontname="Default font" fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
          bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
    <TEXT pos="109 197 63 27" fill="solid: ffffffff" hasStroke="0" text="+/-"
          fontname="Default font" fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
          bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
    <TEXT pos="93 117 60 30" fill="solid: ffffffff" hasStroke="0" text="Yaw"
          fontname="Default font" fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
          bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
    <TEXT pos="261 117 63 30" fill="solid: ffffffff" hasStroke="0" text="\ypr[1]"
          fontname="Default font" fontsize="11.00000000000000000000" kerning="0.00000000000000000000"
          bold="0" italic="0" justification="36"/>
    <TEXT pos="373 117 63 30" fill="solid: ffffffff" hasStroke="0" text="\ypr[2]"
          fontname="Default font" fontsize="11.00000000000000000000" kerning="0.00000000000000000000"
          bold="0" italic="0" justification="36"/>
    <RECT pos="446 111 196 112" fill="solid: 13f4f4f4" hasStroke="1" stroke="0.8, mitered, butt"
          strokeColour="solid: 67a0a0a0"/>
    <TEXT pos="459 116 132 30" fill="solid: ffffffff" hasStroke="0" text="N dirs:"
          fontname="Default font" fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
          bold="1" italic="0" justification="33" typefaceStyle="Bold"/>
    <TEXT pos="459 140 132 30" fill="solid: ffffffff" hasStroke="0" text="HRIR len:"
          fontname="Default font" fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
          bold="1" italic="0" justification="33" typefaceStyle="Bold"/>
    <TEXT pos="459 164 132 30" fill="solid: ffffffff" hasStroke="0" text="HRIR fs:"
          fontname="Default font" fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
          bold="1" italic="0" justification="33" typefaceStyle="Bold"/>
    <TEXT pos="459 188 132 30" fill="solid: ffffffff" hasStroke="0" text="DAW fs:"
          fontname="Default font" fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
          bold="1" italic="0" justification="33" typefaceStyle="Bold"/>
    <TEXT pos="19 180 63 23" fill="solid: ffffffff" hasStroke="0" text="OSC port:"
          fontname="Default font" fontsize="11.00000000000000000000" kerning="0.00000000000000000000"
          bold="1" italic="0" justification="33" typefaceStyle="Bold"/>
    <TEXT pos="659 -15 80 30" fill="solid: ffffffff" hasStroke="0" text="Comp. EQ:"
          fontname="Default font" fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
          bold="1" italic="0" justification="33" typefaceStyle="Bold"/>
    <TEXT pos="19 160 63 23" fill="solid: ffffffff" hasStroke="0" text="R-P-Y:"
          fontname="Default font" fontsize="11.00000000000000000000" kerning="0.00000000000000000000"
          bold="1" italic="0" justification="33" typefaceStyle="Bold"/>
    <TEXT pos="19 138 61 23" fill="solid: ffffffff" hasStroke="0" text="Enable:"
          fontname="Default font" fontsize="11.00000000000000000000" kerning="0.00000000000000000000"
          bold="1" italic="0" justification="33" typefaceStyle="Bold"/>
  </BACKGROUND>
  <TOGGLEBUTTON name="new toggle button" id="f7f951a1b21e1a11" memberName="TBuseDefaultHRIRs"
                virtualName="" explicitFocusOrder="0" pos="614 60 21 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <COMBOBOX name="new combo box" id="d83602bab6f1a999" memberName="CBorderPreset"
            virtualName="" explicitFocusOrder="0" pos="122 62 90 20" editable="0"
            layout="33" items="" textWhenNonSelected="Default" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="a36915795f16ceb6" memberName="CBchFormat"
            virtualName="" explicitFocusOrder="0" pos="314 63 112 20" editable="0"
            layout="33" items="ACN" textWhenNonSelected="ACN" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="e10be54628a6df43" memberName="CBnormScheme"
            virtualName="" explicitFocusOrder="0" pos="314 88 112 20" editable="0"
            layout="33" items="N3D&#10;SN3D" textWhenNonSelected="N3D" textWhenNoItems="(no choices)"/>
  <TOGGLEBUTTON name="new toggle button" id="943aa789e193d13a" memberName="TBmaxRE"
                virtualName="" explicitFocusOrder="0" pos="132 86 22 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <SLIDER name="new slider" id="ace036a85eec9703" memberName="s_yaw" virtualName=""
          explicitFocusOrder="0" pos="80 144 120 38" bkgcol="ff263238"
          trackcol="ff181f22" textboxtext="ffffffff" textboxbkgd="ffffff"
          min="-180.00000000000000000000" max="180.00000000000000000000"
          int="0.01000000000000000021" style="LinearHorizontal" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <SLIDER name="new slider" id="9af7dd86cd139d85" memberName="s_pitch"
          virtualName="" explicitFocusOrder="0" pos="208 110 96 112" bkgcol="ff263238"
          trackcol="ff181f22" textboxtext="ffffffff" textboxbkgd="ffffff"
          min="-180.00000000000000000000" max="180.00000000000000000000"
          int="0.01000000000000000021" style="LinearVertical" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <SLIDER name="new slider" id="b5d39bb257b3289a" memberName="s_roll" virtualName=""
          explicitFocusOrder="0" pos="328 110 96 112" bkgcol="ff263238"
          trackcol="ff181f22" textboxtext="ffffffff" textboxbkgd="ffffff"
          min="-180.00000000000000000000" max="180.00000000000000000000"
          int="0.01000000000000000021" style="LinearVertical" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <TEXTEDITOR name="new text editor" id="1799da9e8cf495d6" memberName="te_oscport"
              virtualName="" explicitFocusOrder="0" pos="16 200 56 18" textcol="ffffffff"
              bkgcol="ffffff" outlinecol="68a3a2a2" initialText="" multiline="0"
              retKeyStartsLine="0" readonly="0" scrollbars="1" caret="0" popupmenu="1"/>
  <LABEL name="new label" id="167c5975ece5bfaa" memberName="label_N_dirs"
         virtualName="" explicitFocusOrder="0" pos="536 120 96 24" outlineCol="68a3a2a2"
         edTextCol="ff000000" edBkgCol="0" labelText="" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="e14d1c2e00d7849b" memberName="label_HRIR_len"
         virtualName="" explicitFocusOrder="0" pos="536 144 96 24" outlineCol="68a3a2a2"
         edTextCol="ff000000" edBkgCol="0" labelText="" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="f8b5274e0c8768f4" memberName="label_HRIR_fs"
         virtualName="" explicitFocusOrder="0" pos="536 168 96 24" outlineCol="68a3a2a2"
         edTextCol="ff000000" edBkgCol="0" labelText="" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="c59fb2aab2496c4e" memberName="label_DAW_fs"
         virtualName="" explicitFocusOrder="0" pos="536 192 96 24" outlineCol="68a3a2a2"
         edTextCol="ff000000" edBkgCol="0" labelText="" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="new toggle button" id="c58241ee52766d62" memberName="t_flipPitch"
                virtualName="" explicitFocusOrder="0" pos="260 182 23 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="717e9536768dfd8c" memberName="t_flipRoll"
                virtualName="" explicitFocusOrder="0" pos="376 182 23 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="ac47b63592b1d4cf" memberName="t_flipYaw"
                virtualName="" explicitFocusOrder="0" pos="128 182 23 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="d5b2026137993288" memberName="TBcompEQ"
                virtualName="" explicitFocusOrder="0" pos="656 -16 32 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="b4fec6d3e1a2bae2" memberName="TBrpyFlag"
                virtualName="" explicitFocusOrder="0" pos="59 160 24 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="dfb8e588ab02032d" memberName="TBenableRot"
                virtualName="" explicitFocusOrder="0" pos="59 138 24 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
