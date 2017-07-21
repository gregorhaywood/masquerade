#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>

#define PORT_NO 6500
#define ADDRESS_SIZE sizeof(struct sockaddr_in)

int main(){
  //set server address
  typedef struct sockaddr_in* socketAddr;
  socketAddr serverAddr = (socketAddr)calloc(ADDRESS_SIZE, 1);
  serverAddr->sin_family = AF_INET;
  serverAddr->sin_port = htons(PORT_NO);
  serverAddr->sin_addr.s_addr = inet_addr("127.0.0.1");

  //??
  int clientSocket = socket(PF_INET, SOCK_STREAM, 0);

  //connect
  connect(clientSocket, (struct sockaddr*) serverAddr, ADDRESS_SIZE);


  //use connection
  char* buffer = (char*)"Client connection";
  printf("Sending: %s\n",buffer);
  int nBytes = 18;
  send(clientSocket, buffer, nBytes, 0);
  recv(clientSocket, buffer, nBytes, 0);
  printf("Received from server: %s\n\n",buffer);

  free(serverAddr);
  return 0;
}
