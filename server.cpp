//#pragma comment(lib, "ws2_32.lib") // ���� ��� ������������ ��� �������������� ����� � ����������� ws2_32.lib
//#define _WINSOCK_DEPRECATED_NO_WARNINGS // ���������� ��������������
//#include <winsock2.h> // ��������� ����� winsock2.h ��� ������ � ��������� Winsock
//#include <iostream>
//
//#pragma warrning(disable: 4996)
//
//SOCKET Connections[100]; // ������ ��� �������� ���������� (������)
//int counter = 0; // ������� �������� ����������
//enum Packet { // ����������� ������������ Packet ��� ����� �������
//	P_ChatMessage, // ��� ������ ��� ��������� ����
//	P_Test // ��� ��� �������� ��������� ���������
//};
//
//void ClientHandler(int index) { // ������� ��� ��������� ����������� �������
//	while (true) {
//		int msg_size;
//		int result = recv(Connections[index], (char*)&msg_size, sizeof(int), NULL);
//
//		if (result <= 0) {
//			std::cout << "Client disconnected\n";
//			std::string disconnectMessage = "Client disconnected";
//			int disconnectMessageSize = disconnectMessage.size();
//			for (int i = 0; i < counter; i++) { // ���� �� ���� �����������
//				if (i != index) { // ���� ��� ������� �����������
//					send(Connections[i], (char*)&disconnectMessageSize, sizeof(int), NULL); // �������� ������� ���������
//					send(Connections[i], disconnectMessage.c_str(), disconnectMessageSize, NULL); // �������� ���������
//				}
//			}
//			closesocket(Connections[index]);
//			Connections[index] = Connections[counter - 1];
//			counter--;
//			break;
//		}
//
//		char* userMessage = new char[msg_size + 1];
//		recv(Connections[index], userMessage, msg_size, NULL);
//		std::cout << userMessage << std::endl;
//		for (int i = 0; i < counter; i++) { // ���� �� ���� �����������
//			if (i == index) { // ���� ��� ������� �����������
//				continue; // ����������
//			}
//			send(Connections[i], (char*)&msg_size, sizeof(int), NULL); // �������� ������� ���������
//			send(Connections[i], userMessage, msg_size, NULL); // �������� ���������
//		}
//	}
//}
//
//int main() {
//	WSAData wsaData; // ������ Windows Socket API
//	WORD DLLVersion = MAKEWORD(2, 1);
//	if (WSAStartup(DLLVersion, &wsaData) != 0) { // �������������� Winsock
//		std::cout << "WSA ERROR" << std::endl;
//	}
//	else {
//		std::cout << "Server started!" << std::endl;
//	}
//
//	SOCKADDR_IN addr; // �����
//	int sizeofaddr = sizeof(addr);
//	addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // IP_����� (127.0.0.1) - ���������
//	addr.sin_port = htons(9123); // ����
//	addr.sin_family = AF_INET; // ��������� ����, � ������ ������ IPv4
//
//	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL); // �������� ������ ��� ������������� �������� ����������
//	bind(sListen, (SOCKADDR*)&addr, sizeofaddr); // �������� ������ � ������
//	listen(sListen, SOMAXCONN); // ������� ������ � ����� ������������� �������� ����������
//
//	SOCKET newConnection; // ����� ��� ������������ ���������� � ����� ��������
//
//	for (int i=0; i<100; i++){
//		newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr); // ��������� �������� ����������
//		if (newConnection == 0) {
//			std::cout << "ACCEPT ERROR" << std::endl;
//		}
//		else {
//			std::cout << "Client connected!" << std::endl;
//			std::string msg = "Hello world!\n";
//			int msg_size = msg.size();
//			Packet msgtype = P_ChatMessage;
//			//send(newConnection, (char*)&msgtype, sizeof(Packet), NULL);
//			send(newConnection, (char*)&msg_size, sizeof(int), NULL);
//			send(newConnection, msg.c_str(), msg_size, NULL);
//
//			Connections[i] = newConnection; // ��������� ����� ��������������� ������� � ������ ����������
//			counter++;
//			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientHandler, (LPVOID)(i), NULL, NULL);
//		}
//	}
//}