#include "FormManager.h"

#include "LoginForm.h"
#include "MainMenuForm.h"
#include "OpenAccountForm.h"
#include "DepositForm.h"
#include "WithdrawalForm.h"
#include "TransferForm.h"
#include "BalanceInquiryForm.h"
#include "ChangePasswordForm.h"
#include "DetailStatementForm.h"
#include "CloseAccountForm.h"

#include "QueryDayBillForm.h"
#include "QueryHistoryBillForm.h"
#include "QueryAccountHistoryBillForm.h"


using namespace UI;

FormManager::FormManager()
{
	forms_["LoginForm"] = new LoginForm(0, 0, 80, 25);
	forms_["MainMenuForm"] = new MainMenuForm(0, 0, 80, 25);
	forms_["OpenAccountForm"] = new OpenAccountForm(0, 0, 80, 25, "Open Account");
	forms_["DepositForm"] = new DepositForm(0, 0, 80, 25, "Deposit");
	forms_["WithdrawalForm"] = new WithdrawalForm(0, 0, 80, 25, "Withdraw");
	forms_["TransferForm"] = new TransferForm(0, 0, 80, 25, "Transfer");
	forms_["BalanceInquiryForm"] = new BalanceInquiryForm(0, 0, 80, 25, "BalanceInquiry");
	forms_["ChangePasswordForm"] = new ChangePasswordForm(0, 0, 80, 25, "ChangePassword");
	forms_["DetailStatementForm"] = new DetailStatementForm(0, 0, 80, 25, "Detail Statement");
	forms_["CloseAccountForm"] = new CloseAccountForm(0, 0, 80, 25, "Close Account");
	forms_["QueryDayBillForm"] = new QueryDayBillForm(13, 5, 54, 13);
	forms_["QueryHistoryBillForm"] = new QueryHistoryBillForm(13, 5, 54, 13);
	forms_["QueryAccountHistoryBillForm"] = new QueryAccountHistoryBillForm(13, 5, 54, 15);
}

FormManager::~FormManager()
{
}
