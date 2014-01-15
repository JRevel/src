#ifndef BUTTON_SELECT_GUI_H_INCLUDED
#define BUTTON_SELECT_GUI_H_INCLUDED

class GuiButtonSelect : public Gui
{
public:
    GuiButtonSelect(Vec dim, Vec buttonDim, int buttonCount);



private:
    std::vector<GuiButton*> m_buttons;
    Vec m_buttonDim, m_dim;
    int m_buttonCount;
};

#endif // BUTTON_SELECT_GUI_H_INCLUDED
