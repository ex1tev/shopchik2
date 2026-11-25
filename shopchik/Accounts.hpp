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

extern std::size_t maxLogin;
extern std::size_t minLogin;
extern std::size_t maxPass;
extern std::size_t minPass;

extern std::unordered_set<wchar_t> loginSymbols;
extern std::unordered_set<wchar_t> passSymbols;

void ChangeAccounts();
void CreateNewAccount();

void CreateSet();
bool CheckLogin(const std::wstring & login);


#endif // !_ACCOUNTS_HPP_