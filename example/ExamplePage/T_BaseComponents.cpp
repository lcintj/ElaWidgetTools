﻿#include "T_BaseComponents.h"

#include <QHBoxLayout>
#include <QVBoxLayout>

#include "ElaCheckBox.h"
#include "ElaComboBox.h"
#include "ElaMenu.h"
#include "ElaMessageButton.h"
#include "ElaMultiSelectComboBox.h"
#include "ElaPlainTextEdit.h"
#include "ElaProgressBar.h"
#include "ElaRadioButton.h"
#include "ElaScrollPageArea.h"
#include "ElaSlider.h"
#include "ElaSpinBox.h"
#include "ElaText.h"
#include "ElaTheme.h"
#include "ElaToggleButton.h"
#include "ElaToggleSwitch.h"
#include "ElaToolButton.h"
T_BaseComponents::T_BaseComponents(QWidget* parent)
    : ElaScrollPage(parent)
{
    ElaText* subTitleText = new ElaText(this);
    subTitleText->setText("https://github.com/Liniyous/ElaWidgetTools");
    subTitleText->setTextInteractionFlags(Qt::TextSelectableByMouse);
    subTitleText->setTextPixelSize(11);

    ElaToolButton* documentationButton = new ElaToolButton(this);
    documentationButton->setFixedHeight(35);
    documentationButton->setIsTransparent(false);
    documentationButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    //_toolButton->setPopupMode(QToolButton::MenuButtonPopup);
    documentationButton->setText("Documentation");
    documentationButton->setElaIcon(ElaIconType::FileDoc);
    ElaMenu* documentationMenu = new ElaMenu(this);
    documentationMenu->addElaIconAction(ElaIconType::CardsBlank, "CardsBlank");
    documentationMenu->addElaIconAction(ElaIconType::EarthAmericas, "EarthAmericas");
    documentationButton->setMenu(documentationMenu);

    ElaToolButton* sourceButton = new ElaToolButton(this);
    sourceButton->setFixedHeight(35);
    sourceButton->setIsTransparent(false);
    sourceButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    sourceButton->setText("Source");
    sourceButton->setElaIcon(ElaIconType::NfcSymbol);
    ElaMenu* sourceMenu = new ElaMenu(this);
    sourceMenu->addElaIconAction(ElaIconType::FireBurner, "FireBurner");
    sourceMenu->addElaIconAction(ElaIconType::Galaxy, "Galaxy~~~~");
    sourceButton->setMenu(sourceMenu);

    ElaToolButton* themeButton = new ElaToolButton(this);
    themeButton->setFixedSize(35, 35);
    themeButton->setIsTransparent(false);
    themeButton->setElaIcon(ElaIconType::MoonStars);
    connect(themeButton, &ElaToolButton::clicked, this, [=]() {
        eTheme->setThemeMode(eTheme->getThemeMode() == ElaThemeType::Light ? ElaThemeType::Dark : ElaThemeType::Light);
    });

    QHBoxLayout* buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(documentationButton);
    buttonLayout->addSpacing(5);
    buttonLayout->addWidget(sourceButton);
    buttonLayout->addStretch();
    buttonLayout->addWidget(themeButton);
    buttonLayout->addSpacing(15);

    ElaText* desText = new ElaText(this);
    desText->setText("一些常用的基础组件被放置于此，可在此界面体验其效果并按需添加进项目中");
    desText->setTextPixelSize(13);

    _toggleSwitch = new ElaToggleSwitch(this);
    ElaScrollPageArea* toggleSwitchArea = new ElaScrollPageArea(this);
    QHBoxLayout* toggleSwitchLayout = new QHBoxLayout(toggleSwitchArea);
    ElaText* toggleSwitchText = new ElaText("ElaToggleSwitch", this);
    toggleSwitchText->setTextPixelSize(15);
    toggleSwitchLayout->addWidget(toggleSwitchText);
    toggleSwitchLayout->addWidget(_toggleSwitch);
    toggleSwitchLayout->addStretch();

    _toggleButton = new ElaToggleButton("Head", this);
    ElaScrollPageArea* toggleButtonArea = new ElaScrollPageArea(this);
    QHBoxLayout* toggleButtonLayout = new QHBoxLayout(toggleButtonArea);
    ElaText* toggleButtonText = new ElaText("ElaToggleButton", this);
    toggleButtonText->setTextPixelSize(15);
    toggleButtonLayout->addWidget(toggleButtonText);
    toggleButtonLayout->addWidget(_toggleButton);
    toggleButtonLayout->addStretch();

    _comboBox = new ElaComboBox(this);
    QStringList comboList{
        "我愿投身前途未卜的群星",
        "潜行 步伐小心翼翼",
        "不留游走痕迹",
        "如同一簇幽灵",
        "所谓 道德加上伦理",
        "抱歉只能律己"};
    _comboBox->addItems(comboList);
    ElaScrollPageArea* comboBoxArea = new ElaScrollPageArea(this);
    QHBoxLayout* comboBoxLayout = new QHBoxLayout(comboBoxArea);
    ElaText* comboBoxText = new ElaText("ElaComboBox", this);
    comboBoxText->setTextPixelSize(15);
    comboBoxLayout->addWidget(comboBoxText);
    comboBoxLayout->addWidget(_comboBox);
    comboBoxLayout->addStretch();

    _multiSelectComboBox = new ElaMultiSelectComboBox(this);
    QStringList multiComboList{"执念的鱼", "提着灯闯过远洋的甄选", "继续下潜", "无需誓言", "我的心像自沉的旧母舰", "没入深渊", "我曾凝望曾是航向的日出"};
    QStringList multiSelectComboList{"执念的鱼", "提着灯闯过远洋的甄选", "无需誓言", "我的心像自沉的旧母舰"};
    _multiSelectComboBox->addItems(multiComboList);
    _multiSelectComboBox->setCurrentSelection(multiSelectComboList);
    ElaScrollPageArea* multiSelectComboBoxArea = new ElaScrollPageArea(this);
    QHBoxLayout* multiSelectComboBoxLayout = new QHBoxLayout(multiSelectComboBoxArea);
    ElaText* multiSelectComboBoxText = new ElaText("ElaMutilSelectComboBox", this);
    multiSelectComboBoxText->setTextPixelSize(15);
    multiSelectComboBoxLayout->addWidget(multiSelectComboBoxText);
    multiSelectComboBoxLayout->addWidget(_multiSelectComboBox);
    multiSelectComboBoxLayout->addStretch();

    _messageButton = new ElaMessageButton("Success", this);
    _messageButton->setBarTitle("Success");
    _messageButton->setBarText("点燃星 亲手点燃黑暗森林的火星 蒙昧初醒 而我却 轻声告别这新生的黎明");

    _infoMessageButton = new ElaMessageButton("Info", this);
    _infoMessageButton->setBarTitle("Information");
    _infoMessageButton->setBarText("点燃星 亲手点燃黑暗森林的火星 蒙昧初醒 而我却 轻声告别这新生的黎明");
    _infoMessageButton->setMessageMode(ElaMessageBarType::Information);
    _infoMessageButton->setPositionPolicy(ElaMessageBarType::TopLeft);

    _warningMessageButton = new ElaMessageButton("Warning", this);
    _warningMessageButton->setBarTitle("Warning");
    _warningMessageButton->setBarText("点燃星 亲手点燃黑暗森林的火星 蒙昧初醒 而我却 轻声告别这新生的黎明");
    _warningMessageButton->setMessageMode(ElaMessageBarType::Warning);
    _warningMessageButton->setPositionPolicy(ElaMessageBarType::BottomLeft);

    _errorMessageButton = new ElaMessageButton("Error", this);
    _errorMessageButton->setBarTitle("Error");
    _errorMessageButton->setBarText("点燃星 亲手点燃黑暗森林的火星 蒙昧初醒 而我却 轻声告别这新生的黎明");
    _errorMessageButton->setMessageMode(ElaMessageBarType::Error);
    _errorMessageButton->setPositionPolicy(ElaMessageBarType::BottomRight);

    ElaScrollPageArea* messageButtonArea = new ElaScrollPageArea(this);
    QHBoxLayout* messageButtonLayout = new QHBoxLayout(messageButtonArea);
    ElaText* messageButtonText = new ElaText("ElaMessageButton", this);
    messageButtonText->setTextPixelSize(15);
    messageButtonLayout->addWidget(messageButtonText);
    messageButtonLayout->addWidget(_messageButton);
    messageButtonLayout->addWidget(_infoMessageButton);
    messageButtonLayout->addWidget(_warningMessageButton);
    messageButtonLayout->addWidget(_errorMessageButton);
    messageButtonLayout->addStretch();

    _checkBox = new ElaCheckBox("CheckBox", this);
    ElaScrollPageArea* checkBoxArea = new ElaScrollPageArea(this);
    QHBoxLayout* checkBoxLayout = new QHBoxLayout(checkBoxArea);
    ElaText* checkBoxText = new ElaText("ElacheckBox", this);
    checkBoxText->setTextPixelSize(15);
    checkBoxLayout->addWidget(checkBoxText);
    checkBoxLayout->addWidget(_checkBox);
    checkBoxLayout->addStretch();

    _spinBox = new ElaSpinBox(this);
    ElaScrollPageArea* spinBoxArea = new ElaScrollPageArea(this);
    QHBoxLayout* spinBoxLayout = new QHBoxLayout(spinBoxArea);
    ElaText* spinBoxText = new ElaText("ElaSpinBox", this);
    spinBoxText->setTextPixelSize(15);
    spinBoxLayout->addWidget(spinBoxText);
    spinBoxLayout->addWidget(_spinBox);
    spinBoxLayout->addStretch();

    _slider = new ElaSlider(this);
    ElaScrollPageArea* sliderArea = new ElaScrollPageArea(this);
    QHBoxLayout* sliderLayout = new QHBoxLayout(sliderArea);
    ElaText* sliderText = new ElaText("ElaSlider", this);
    sliderText->setTextPixelSize(15);
    sliderLayout->addWidget(sliderText);
    sliderLayout->addWidget(_slider);
    sliderLayout->addStretch();

    _radioButton = new ElaRadioButton("RadioButton", this);
    ElaScrollPageArea* radioButtonArea = new ElaScrollPageArea(this);
    QHBoxLayout* radioButtonLayout = new QHBoxLayout(radioButtonArea);
    ElaText* radioButtonText = new ElaText("ElaRadioButton", this);
    radioButtonText->setTextPixelSize(15);
    radioButtonLayout->addWidget(radioButtonText);
    radioButtonLayout->addWidget(_radioButton);
    radioButtonLayout->addStretch();

    _progressBar = new ElaProgressBar(this);
    _progressBar->setMinimum(0);
    _progressBar->setMaximum(0);
    ElaScrollPageArea* progressBarArea = new ElaScrollPageArea(this);
    QHBoxLayout* progressBarLayout = new QHBoxLayout(progressBarArea);
    ElaText* progressBarText = new ElaText("ElaProgressBar", this);
    progressBarText->setTextPixelSize(15);
    progressBarLayout->addWidget(progressBarText);
    progressBarLayout->addWidget(_progressBar);
    progressBarLayout->addStretch();

    ElaPlainTextEdit* edit = new ElaPlainTextEdit(this);
    edit->setPlainText("这是一个ElaPlainTextEdit  暂时放在这里");

    QWidget* centralWidget = new QWidget(this);
    centralWidget->setWindowTitle("ElaBaseComponents");
    QVBoxLayout* centerLayout = new QVBoxLayout(centralWidget);
    centerLayout->addWidget(subTitleText);
    centerLayout->addSpacing(5);
    centerLayout->addLayout(buttonLayout);
    centerLayout->addSpacing(5);
    centerLayout->addWidget(desText);
    centerLayout->addSpacing(5);
    centerLayout->addWidget(toggleSwitchArea);
    centerLayout->addWidget(toggleButtonArea);
    centerLayout->addWidget(comboBoxArea);
    centerLayout->addWidget(multiSelectComboBoxArea);
    centerLayout->addWidget(messageButtonArea);
    centerLayout->addWidget(checkBoxArea);
    centerLayout->addWidget(spinBoxArea);
    centerLayout->addWidget(sliderArea);
    centerLayout->addWidget(radioButtonArea);
    centerLayout->addWidget(progressBarArea);
    centerLayout->addWidget(edit);
    centerLayout->addStretch();
    centerLayout->setContentsMargins(0, 0, 0, 0);
    addCentralWidget(centralWidget, true, true, 0);
}

T_BaseComponents::~T_BaseComponents()
{
}
