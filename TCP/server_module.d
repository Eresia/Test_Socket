module server_module;

import std.socket;

import create_client_connexion;

/****/
class Server_Module{

	private:
		ushort port;
		Socket server;
		Client_Information[] clients;
		bool stopServer = false;

	public:

		/****/
		this(ushort port){
			this.port = port;
			this.server = new TcpSocket();
			this.server.setOption(SocketOptionLevel.SOCKET, SocketOption.REUSEADDR, true);
		    this.server.bind(new InternetAddress(port));
		}

		/****/
		int launchServer(){
			server.listen(1);

			while (!stopServer){
				Socket clientSocket = server.accept();
				ulong length;

				clients.length += 1;
				length = clients.length;
				clients[length-1] = Client_Information(clientSocket);
				new Create_Client_Connexion(clients[length-1]).start();

			}

			return 0;
		}
}
