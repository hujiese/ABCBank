#ifndef __JBUTTON_H_
#define __JBUTTON_H_

#include "JWindow.h"
#include <string>

namespace JFC
{
class JButton : public JWindow
{
public:
	JButton();
	JButton(SHORT x, SHORT y, SHORT width, SHORT height, 
		    const std::string text = std::string(),
		    JWindow* parent = jApp->Root());
	virtual void Draw();
	virtual ~JButton();
private:
	std::string text_;
};
}


#endif