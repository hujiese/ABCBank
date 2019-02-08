#include "QueryDayBillForm.h"

#include "FormManager.h"
#include "DetailStatementForm.h"
#include "Validator.h"

#include "../JFC/JMessageBox.h"

using namespace UI;

QueryDayBillForm::QueryDayBillForm()
	: JForm(0, 0, 0, 0, 0)
{
}

QueryDayBillForm::~QueryDayBillForm()
{
}

QueryDayBillForm::QueryDayBillForm(SHORT x, SHORT y, SHORT w, SHORT h)
	: JForm(x, y, w, h)
{
	editDate_ = new JEdit(29, 9, 20, 1, "", this);
	btnQuery_ = new JButton(28, 13, 11, 3, "QUERY", this);
	btnCancel_ = new JButton(41, 13, 10, 3, "CANCEL", this);

	editDate_->SetValidator(ValidateDate);
}

void QueryDayBillForm::Draw()
{
	DrawBorder();
	SetTextColor(FCOLOR_BLUE);
	SetBkColor(BCOLOR_WHITE);
	DrawText(3, 2, "-DETAIL QUERY-");
	DrawText(10, 4, "Date:");
	DrawText(39, 4, "YYYY-MM-DD");
	DrawText(10, 6, "(Default:2013-07-01)");
	JForm::Draw();
}

void QueryDayBillForm::DrawBorder()
{
	SetTextColor(FCOLOR_YELLO);
	SetBkColor(BCOLOR_RED);
	DrawHLine(0, 0, Width()-1, '-');
	DrawHLine(Height()-1, 0, Width()-1, '-');
	DrawVLine(0, 1, Height()-2, ' ');
	DrawVLine(Width()-1, 1, Height()-2, ' ');
}

void QueryDayBillForm::OnKeyEvent(JEvent* e)
{
	int key = e->GetEventCode();
	if (key == KEY_ESC)
	{
		JForm* form;
		ClearWindow();
		form = Singleton<FormManager>::Instance().Get("DetailStatementForm");
		dynamic_cast<DetailStatementForm*>(form)->btnDetail1_->SetCurrent();
		form->Show();
		e->Done();
	}
	else if (key == KEY_ENTER)
	{
		if (e->GetSender() == btnCancel_)
		{
			JForm* form;
			ClearWindow();
			form = Singleton<FormManager>::Instance().Get("DetailStatementForm");
			dynamic_cast<DetailStatementForm*>(form)->btnDetail1_->SetCurrent();
			form->Show();
			e->Done();
		}
		if (e->GetSender() == btnQuery_)
		{
			Query();
			e->Done();
		}
	}

	JForm::OnKeyEvent(e);
}

void QueryDayBillForm::Query()
{
	if (editDate_->GetText().length() < 10)
	{
		std::vector<std::string> v;
		v.push_back(" YES ");
		std::string msg = "����С��10λ";

		int result = JMessageBox::Show("-ERROR-", msg,v);
		ClearWindow();
		Show();
		editDate_->Show();
		return;
	}

	// ����Ϊʵ�ʵĲ�ѯ����
}

void QueryDayBillForm::Reset()
{
	editDate_->SetText("");
}