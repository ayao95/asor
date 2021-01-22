#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#include <sys/types.h> 
#include <sys/socket.h>


#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h> 

#include <time.h>


int main (int argc, char**argv) {

  int error;
  if (argc < 2) {
    printf("Introduce la dirección.\n");
    return -1;
  }

  struct addrinfo hints;
  struct addrinfo *result, *iterator;

  //Rellenamos el hints para hacer los criterios de búsqueda.
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_DGRAM;
  hints.ai_flags = AI_PASSIVE;

  //getaddrinfo
  error=getaddrinfo(argv[1], argv[2], &hints, &result);
  if ( error != 0) {
      printf("ERROR: No se ha podido ejecutar el getaddrinfo.El error es:%i",error);
      exit(EXIT_FAILURE);
  }

  //socket
  int socketUDP = socket(result->ai_family, result->ai_socktype, result->ai_protocol);


  //bind
  if (bind(socketUDP, result->ai_addr, result->ai_addrlen) != 0) {
    printf("ERROR: No se ha podido ejecutar el bind.");
    exit(EXIT_FAILURE);
  }

  freeaddrinfo(result);

  
  char buf[2];
  char host[NI_MAXHOST];
  char serv[NI_MAXSERV];

  struct sockaddr_storage client_addr;
  socklen_t client_addrlen = sizeof(client_addr);
  int i = 0;
  int status;
  for (i = 0; i < 2; i++){
    pid_t pid;
    pid = fork();

    if (pid == 0) {
      while(1){
        ssize_t bytes = recvfrom(socketUDP, buf, 2, 0, (struct sockaddr *) &client_addr, &client_addrlen);
        buf[1] = '\0';

        getnameinfo((struct sockaddr *) &client_addr, client_addrlen, host, NI_MAXHOST, serv, NI_MAXSERV, NI_NUMERICHOST|NI_NUMERICSERV);

        printf("%i byte(s) de %s:%s cuyo PID: %d\n", bytes, host, serv, getpid());

        time_t tiempo = time(NULL);
        struct tm *tm = localtime(&tiempo);
        size_t max;
        char s[50];

        if (buf[0] == 't'){
          size_t bytesT = strftime(s, max, "%I:%M:%S %p", tm);
          s[bytesT] = '\0';

          sendto(socketUDP, s, bytesT, 0, (struct sockaddr *) &client_addr, client_addrlen);

        }else if (buf[0] =='d'){
          size_t bytesT = strftime(s, max, "%Y-%m-%d", tm);
          s[bytesT] = '\0';

          sendto(socketUDP, s, bytesT, 0, (struct sockaddr *) &client_addr, client_addrlen);
        }else if (buf[0] =='q'){
          printf("Saliendo...\n");
          exit(0);
        }else{
          printf("Comando no soportado: %c...\n", buf[0]);
        }
      }
    }
    else {
      pid = wait(&status);
    }
  }
  return 0;
}
