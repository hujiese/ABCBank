#include "TransferForm.h"

#include "FormManager.h"
#include "MainMenuForm.h"
#include "Validator.h"

#include "../JFC/JMessageBox.h"

using namespace UI;

TransferForm::TransferForm()
	: JForm(0, 0, 0, 0, 0)
{
}

TransferForm::~TransferForm()
{
}

TransferForm::TransferForm(SHORT x, SHORT y, SHORT w, SHORT h,
						   const std::string& title)
	: JForm(x, y, w, h),
	  title_(title)
{

	lblAccountId_ = new JLabel(14, 5, 11, 1, "ACCOUNT ID:", this);
	editAccountId_ = new JEdit(26, 5, 21, 1, "", this);
	lblAccountIdTip_ = new JLabel(50, 5, 11, 1, "长度6位，数字", this);

	lblPass_ = new JLabel(8, 8, 17, 1, "ACCOUNT PASSWORD:", this);
	editPass_ = new JEdit(26, 8, 21, 1, "", this, JEdit::EM_PASSWORD);
	lblPassTip_ = new JLabel(50, 8, 11, 1, "长度6-8位", this);

	lblMoney_ = new JLabel(19, 11, 12, 1, "MONEY:", this);
	editMoney_ = new JEdit(26, 11, 21, 1, "", this);
	lblMoneyTip_ = new JLabel(50, 11, 15, 1, "小数最多两位", this);

	lblAccountId2_ = new JLabel(11, 14, 14, 1, "TO ACCOUNT ID:", this);
	editOtherAccountId_ = new JEdit(26, 14, 21, 1, "", this);
	lblAccountId2Tip_ = new JLabel(50, 14, 11, 1, "长度6位，数字", this);


	btnSubmit_ = new JButton(5, 20, 10, 3, "SUBMIT", this);
	btnReset_ =	new JButton(50, 20, 10, 3,"RESET", this);
	btnCancel_ = new JButton(65, 20, 10, 3,"CANCEL", this);

	editAccountId_->SetValidator(ValidateAccountId);
	editPass_->SetValidator(ValidatePass);
	editMoney_->SetValidator(ValidateMoney);
	editOtherAccountId_->SetValidator(ValidateAccountId);


}

void TransferForm::Draw()
{
	DrawBorder();
	SetTextColor(FCOLOR_BLUE);
	SetBkColor(BCOLOR_WHITE);
	JRECT rect = { 1, 1, Width()-2, Height()-2 };
	FillRect(rect);

	DrawText(5, 2, title_);
	DrawHLine(3, 2, Width()-3, '-');

	JForm::Draw();
}

void TransferForm::DrawBorder()
{
	SetTextColor(FCOLOR_YELLO);
	SetBkColor(BCOLOR_RED);
	DrawHLine(0, 0, Width()-1, '-');
	DrawHLine(Height()-1, 0, Width()-1, '-');
	DrawVLine(0, 1, Height()-2, ' ');
	DrawVLine(Width()-1, 1, Height()-2, ' ');
}

void TransferForm::OnKeyEvent(JEvent* e)
{
	int key = e->GetEventCode();
	if (key == KEY_ESC)
	{
		Reset();
		JForm* form;
		//ClearWindow();
		form = Singleton<FormManager>::Instance().Get("MainMenuForm");
		dynamic_cast<MainMenuForm*>(form)->GetItems()[3]->SetCurrent();
		form->ClearWindow();
		form->Show();
		e->Done();
	}
	else if (key == KEY_ENTER)
	{
		if (e->GetSender() == btnCancel_)
		{
			Reset();
			JForm* form;
			//ClearWindow();
			form = Singleton<FormManager>::Instance().Get("MainMenuForm");
			dynamic_cast<MainMenuForm*>(form)->GetItems()[3]->SetCurrent();
			form->ClearWindow();
			form->Show();
			e->Done();
		}
		else if (e->GetSender() == btnReset_)
		{
			Reset();
			editAccountId_->SetCurrent();
			Show();
			e->Done();
		}
		else if (e->GetSender() == btnSubmit_)
		{
			Submit();
			e->Done();
		}
	}

	JForm::OnKeyEvent(e);
}

void TransferForm::Reset()
{
	editAccountId_->SetText("");
	editPass_->SetText("");
	editMoney_->SetText("");
	editOtherAccountId_->SetText("");

}

void TransferForm::Submit()
{
	if (editAccountId_->GetText().length() < 6)
	{
		std::vector<std::string> v;
		v.push_back(" YES ");
		std::string msg = "帐号小于6位";

		int result = JMessageBox::Show("-ERROR-", msg,v);
		ClearWindow();
		Show();
		editAccountId_->Show();
		return;
	}
	if (editPass_->GetText().length() < 6)
	{
		std::vector<std::string> v;
		v.push_back(" YES ");
		std::string msg = "密码小于6位";

		int result = JMessageBox::Show("-ERROR-", msg,v);
		ClearWindow();
		Show();
		editPass_->Show();
		return;
	}
	if (editOtherAccountId_->GetText().length() < 6)
	{
		std::vector<std::string> v;
		v.push_back(" YES ");
		std::string msg = "帐号小于6位";

		int result = JMessageBox::Show("-ERROR-", msg,v);
		ClearWindow();
		Show();
		editAccountId_->Show();
		return;
	}
	if (editMoney_->GetText().empty())
	{
		std::vector<std::string> v;
		v.push_back(" YES ");
		std::string msg = "金额不能为空";

		JMessageBox::Show("-ERROR-", msg, v);
		ClearWindow();
		Show();
		editAccountId_->Show();
		return;
	}
	if (editAccountId_->GetText() == editOtherAccountId_->GetText())
	{
		std::vector<std::string> v;
		v.push_back(" YES ");
		std::string msg = "不能转入到自身帐户";

		JMessageBox::Show("-ERROR-", msg, v);
		ClearWindow();
		Show();
		editAccountId_->Show();
		return;
	}

	// 以下为实际的转帐操作
}