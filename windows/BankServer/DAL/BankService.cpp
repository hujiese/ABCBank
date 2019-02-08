#include "BankService.h"
#include "MysqlDB.h"

#include "../Server.h"
#include "../../Public/Logging.h"
#include "../../Public/Exception.h"
#include "../../Public/JUtil.h"

#include <sstream>
using namespace std;

using namespace DAL;
using namespace PUBLIC;

int BankService::UserLogin(const string& user, const string& pass)
{
	/*
	if (user != "admin" || pass != "123456")
		return 1;
		*/
	MysqlDB db;
	Server& server = Singleton<Server>::Instance();

	try
	{
		db.Open(server.GetDbServerIp().c_str(),
			server.GetDbUser().c_str(),
			server.GetDbPass().c_str(),
			server.GetDbName().c_str(),
			server.GetDbServerPort());

		stringstream ss;
		ss<<"select teller_name from teller where teller_name='"<<
			user<<"' and teller_pass='"<<
			pass<<"';";
		MysqlRecordset rs;
		rs = db.QuerySQL(ss.str().c_str());
		if (rs.GetRows() < 1)
			return 1;
	}
	catch (Exception& e)
	{
		LOG_INFO<<e.what();
		return -1;
	}

	return 0;
}


// 开户
int BankService::OpenAccount(Account& account)
{
	MysqlDB db;
	Server& server = Singleton<Server>::Instance();

	try
	{
		db.Open(server.GetDbServerIp().c_str(),
			server.GetDbUser().c_str(),
			server.GetDbPass().c_str(),
			server.GetDbName().c_str(),
			server.GetDbServerPort());

		db.StartTransaction();

		stringstream ss;
		ss<<"insert into bank_account values(null, '"<<
			account.name<<"', '"<<
			account.pass<<"', '"<<
			account.id<<"', "<<
			setprecision(2)<<setiosflags(ios::fixed)<<account.balance<<", now(), "<<
			0<<");";
		unsigned long long ret = db.ExecSQL(ss.str().c_str());


		ss.clear();
		ss.str("");
		account.account_id = static_cast<int>(db.GetInsertId());
		ss<<"insert into trans values(null, "<<
			account.account_id<<", null, "<<
			1<<", "<<
			setprecision(2)<<setiosflags(ios::fixed)<<account.balance<<", "<<
			setprecision(2)<<setiosflags(ios::fixed)<<account.balance<<
			",  now());";

		ret = db.ExecSQL(ss.str().c_str());

		db.Commit();

		ss.clear();
		ss.str("");
		ss<<"select open_date from bank_account where account_id='"<<
			account.account_id<<"';";
		MysqlRecordset rs = db.QuerySQL(ss.str().c_str());
		account.op_date = rs.GetItem(0, "open_date");

	}
	catch (Exception& e)
	{
		LOG_INFO<<e.what();
		db.Rollback();
		return -1;
	}

	return 0;
}


// 存款
int BankService::Deposit(Account& account)
{
	
	return 0;
}

// 取款
int BankService::WithDraw(Account& account)
{
	return 0;
}
// 转帐
int BankService::Transfer(Account& account, const string& otherAccountId)
{
	
	return 0;
}
// 查询余额
int BankService::BalanceInquiry(Account& account)
{
	
	return 0;
}

// 修改密码
int BankService::ChangePassword(Account& account, const string& newPass)
{
	
	return 0;
}

// 查询某日报表
int BankService::QueryDayBill(list<TransDetail>& result, int page, const string& date)
{
	
	return 0;
}
// 根据日期查询明细
int BankService::QueryHistoryBill(list<TransDetail>& result, int page, const string& begin, const string& end)
{
	
	return 0;
}
// 根据帐号查询明细
int BankService::QueryAccountHistoryBill(list<TransDetail>& result, int page, const string& accountId, const string& begin, const string& end)
{
	
	return 0;
}

// 销户
int BankService::CloseAccount(Account& account, double& interest)
{
	
	return 0;

}
