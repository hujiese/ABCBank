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
	int Exec(); //��Ϣѭ��
	void ShowCursor() const;
	void HideCursor() const;
	JWindow* GetCurrent() const { return current_; }
	void SetCurrent(JWindow* win){ current_ = win; }
	JWindow* Root() const{ return root_; }
private:
	static JApplication* self_;
	JWindow* current_; //��ǰ���հ����Ĵ���
	JWindow* root_; //��
};
#define jApp JApplication::Instance()
}

#endif