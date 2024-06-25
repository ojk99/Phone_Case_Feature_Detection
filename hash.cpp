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
	DWORD cbData = (DWORD)(password.length() * sizeof(wchar_t)); // �������� ũ�⸦ ����մϴ�.
	BYTE* pbHash = new BYTE[32]; // �ؽ� ���� ������ ���۸� �Ҵ��մϴ�.
	DWORD cbHash;
	NTSTATUS status;

	// SHA-256 �ؽ� �˰��� ���ι��̴��� ���ϴ�.
	status = BCryptOpenAlgorithmProvider(&hAlg, BCRYPT_SHA256_ALGORITHM, NULL, 0);
	if (status != ERROR_SUCCESS) {
		std::cout << L"�˰��� ���ι��̴� ���� ���� " << std::endl;
		return"";
	}

	// �ؽ� ��ü�� �����մϴ�.
	status = BCryptCreateHash(hAlg, &hHash, NULL, 0, NULL, 0, 0);
	if (status != ERROR_SUCCESS) {
		std::cout << L"�ؽ� ��ü ���� ���� " << std::endl;
		return"";
	}

	// �����͸� �ؽ��մϴ�.
	status = BCryptHashData(hHash, (PBYTE)password.c_str(), cbData, 0);
	if (status != ERROR_SUCCESS) {
		std::cout << L"������ �ؽ� ���� " << std::endl;
		return"";
	}

	// �ؽ� ���� �����ɴϴ�.
	status = BCryptGetProperty(hHash, BCRYPT_HASH_LENGTH, (PBYTE)&cbHash, sizeof(DWORD), &cbData, 0);
	if (status != ERROR_SUCCESS) {
		std::cout << L"�ؽ� �� �������� ���� " << std::endl;
		return"";
	}

	// �ؽ� ���� �����մϴ�.
	status = BCryptFinishHash(hHash, pbHash, cbHash, 0);
	if (status != ERROR_SUCCESS) {
		std::cout << "�ؽ� �� �Ϸ� ���� " << std::endl;
		return"";
	}

	// �ؽ� ���� ����մϴ�.
	std::string hashedPassword;
	for (DWORD i = 0; i < cbHash; i++) {
		// �� ����Ʈ�� 16���� ���ڿ��� ��ȯ�Ͽ� hashedPassword�� �߰��մϴ�.
		char hex[3]; // 16���� ���ڿ��� ������ �ӽ� ����
		sprintf(hex, "%02x", pbHash[i]); // �� ����Ʈ�� 16���� ���ڿ��� ��ȯ�Ͽ� hex�� �����մϴ�.
		hashedPassword += hex; // ��ȯ�� 16���� ���ڿ��� hashedPassword�� �߰��մϴ�.
	}

	// �ڿ��� �����մϴ�.
	delete[] pbHash;
	BCryptDestroyHash(hHash);
	BCryptCloseAlgorithmProvider(hAlg, 0);

	return hashedPassword;
}