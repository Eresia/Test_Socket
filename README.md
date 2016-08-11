#Test_Socket
Permet de tester les sockets UPD/TCP de manière atomique

La partie UDP est developpée en C et la partie TCP en D.
 
##Utilisation

###TCP-IPV4
Dans le dosier "TCP" :

Coté client : ./testTCP.out -c ip port 
Coté serveur : ./testTCP.out -s port

###TCP-IPV6
Dans le dosier "TCP_IPV6" :

Coté client : ./testTCP_IPV6.out -c ip port 
Coté serveur : ./testTCP_IPV6.out -s port

###UDP-IPV4
Dans le dosier "UDP" :

Coté client : ./testUDP.out -c ip port
Coté serveur : ./testUDP.out -s port

