#ifndef __JFORM_H_
#define __JFORM_H_
#include "JWindow.h"
#include "JEvent.h"
namespace JFC
{
class JForm:public JWindow
{
public:
	JForm();
	JForm(SHORT x, SHORT y, SHORT width, SHORT height,
		JWindow* parent = jApp->Root());

	virtual ~JForm();
	virtual void OnKeyEvent(JEvent* e);
	virtual void Draw();
};
}

#endif