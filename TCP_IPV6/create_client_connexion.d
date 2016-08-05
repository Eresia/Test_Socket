module create_client_connexion;

import std.stdio;
import std.string;
import std.socket;

import core.thread;

/****/
struct Client_Information{
	private:
		Socket socket;
		bool isClosed;

	public:

		/****/
		void createClient(Socket socket){
			this.socket = socket;
			this.isClosed = false;
		}

		/****/
		bool clientIsClosed(){
			return isClosed;
		}

		/****/
		void close(){
			isClosed = true;
		}
}

/****/
class Create_Client_Connexion : Thread {

	private :
		Client_Information client;

		void run(){
			while(!client.clientIsClosed()){

				char[1024] buffer;
		        auto received = client.socket.receive(buffer);

				if(received == 0){
					writefln("Client disconnected");
					client.close();
				}
				else{
					writefln("The client said: %s", buffer[0 .. received]);

					client.socket.send(buffer[0 .. received]);
					writefln("Answer : %s\n", buffer[0 .. received]);
				}

			}
		}

	public:

		/****/
		this(Client_Information client){
			super(&run);
			this.client = client;
		}
}
