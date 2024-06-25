#include <iostream>
#include <string>
#include "Connect.h"
#include <bcrypt.h>
#include "hash.h"
#pragma comment(lib,"bcrypt.lib")

std::string hashToString(std::string str)
{
	std::wstring password(str.begin(), str.end());

	BCRYPT_ALG_HANDLE hAlg;
	BCRYPT_HASH_HANDLE hHash;
	DWORD cbData = (DWORD)(password.length() * sizeof(wchar_t)); // 데이터의 크기를 계산합니다.
	BYTE* pbHash = new BYTE[32]; // 해시 값을 저장할 버퍼를 할당합니다.
	DWORD cbHash;
	NTSTATUS status;

	// SHA-256 해시 알고리즘 프로바이더를 엽니다.
	status = BCryptOpenAlgorithmProvider(&hAlg, BCRYPT_SHA256_ALGORITHM, NULL, 0);
	if (status != ERROR_SUCCESS) {
		std::cout << L"알고리즘 프로바이더 열기 실패 " << std::endl;
		return"";
	}

	// 해시 객체를 생성합니다.
	status = BCryptCreateHash(hAlg, &hHash, NULL, 0, NULL, 0, 0);
	if (status != ERROR_SUCCESS) {
		std::cout << L"해시 객체 생성 실패 " << std::endl;
		return"";
	}

	// 데이터를 해싱합니다.
	status = BCryptHashData(hHash, (PBYTE)password.c_str(), cbData, 0);
	if (status != ERROR_SUCCESS) {
		std::cout << L"데이터 해싱 실패 " << std::endl;
		return"";
	}

	// 해시 값을 가져옵니다.
	status = BCryptGetProperty(hHash, BCRYPT_HASH_LENGTH, (PBYTE)&cbHash, sizeof(DWORD), &cbData, 0);
	if (status != ERROR_SUCCESS) {
		std::cout << L"해시 값 가져오기 실패 " << std::endl;
		return"";
	}

	// 해시 값을 저장합니다.
	status = BCryptFinishHash(hHash, pbHash, cbHash, 0);
	if (status != ERROR_SUCCESS) {
		std::cout << "해시 값 완료 실패 " << std::endl;
		return"";
	}

	// 해시 값을 출력합니다.
	std::string hashedPassword;
	for (DWORD i = 0; i < cbHash; i++) {
		// 각 바이트를 16진수 문자열로 변환하여 hashedPassword에 추가합니다.
		char hex[3]; // 16진수 문자열을 저장할 임시 버퍼
		sprintf(hex, "%02x", pbHash[i]); // 각 바이트를 16진수 문자열로 변환하여 hex에 저장합니다.
		hashedPassword += hex; // 변환된 16진수 문자열을 hashedPassword에 추가합니다.
	}

	// 자원을 정리합니다.
	delete[] pbHash;
	BCryptDestroyHash(hHash);
	BCryptCloseAlgorithmProvider(hAlg, 0);

	return hashedPassword;
}