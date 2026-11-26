#ifndef _ACCOUNTS_HPP_
#define _ACCOUNTS_HPP_

#include "Service.hpp"

extern size_t userSize;
extern size_t currentId;
extern std::wstring currentStatus;

extern std::wstring* loginArr;
extern std::wstring* passArr;
extern std::wstring* statusArr;
extern size_t* userIdArr;

extern double* awardArr;
extern double* fineArr;

extern std::size_t maxLogin;
extern std::size_t minLogin;
extern std::size_t maxPass;
extern std::size_t minPass;

extern bool isSetCreated;

extern std::unordered_set<wchar_t> loginSymbols;
extern std::unordered_set<wchar_t> passSymbols;

void ShowUsers(int mode = 0);
void ChangeAccounts();
void CreateNewAccount();

void CreateSet();
bool CheckLogin(const std::wstring & login);
bool CheckPass(const std::wstring& pass);


#endif // !_ACCOUNTS_HPP_