#ifndef __JAPPLICATION_H_
#define __JAPPLICATION_H_

namespace JFC
{
class JWindow;

class JApplication
{
public:
	JApplication();
	~JApplication();

	static JApplication* JApplication::Instance(){ return self_; };
	int Exec(); //消息循环
	void ShowCursor() const;
	void HideCursor() const;
	JWindow* GetCurrent() const { return current_; }
	void SetCurrent(JWindow* win){ current_ = win; }
	JWindow* Root() const{ return root_; }
private:
	static JApplication* self_;
	JWindow* current_; //当前接收按键的窗口
	JWindow* root_; //根
};
#define jApp JApplication::Instance()
}

#endif