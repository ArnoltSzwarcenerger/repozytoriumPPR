#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>


int main(){
    char msg[256]= "10";
    
    //tworzenie socketa
    int network_socket;
    network_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    //adres socketa
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;
    
    //nawiazywanie polaczenia
    int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    if(connection_status == -1){
        printf("There was an error making a connection to the remote socket \n\n");
    }
    //wyslanie do procesu 3
    int count = send(network_socket, msg, sizeof(msg), 0);
    if(count == -1)printf("\nerror w send()\n\n");
    
    close(network_socket);
    
return 0;
}
