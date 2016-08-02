module client_module;

import std.stdio;
import std.string;
import std.socket;
import std.conv;
import core.thread;

/**

**/
class Client_Module
{
	private:
		string ip;
		ushort port;
		Socket socket;
		bool isClosed;

	public:

		/****/
		this(string ip, ushort port){
			this.ip = ip;
			this.port = port;
			this.isClosed = false;
			socket = new TcpSocket();
			socket.setOption(SocketOptionLevel.SOCKET, SocketOption.REUSEADDR, true);
		}

		/****/
		int beginCommunication(){
			char[] msg;
			int i = 0;
			socket.connect(new InternetAddress(ip, port));
			while (!isClosed){
				msg = to!string(i).dup;
				auto received = socket.send(msg);

				if(received == 0){
					writefln("Server closed");
					isClosed = true;
				}
				else{
					writefln("Send : %s", msg[0 .. received]);
					received = socket.receive(msg);

					if(received == 0){
						writefln("Server closed");
						isClosed = true;
					}
					else{
						writefln("Receive : %s", msg[0 .. received]);
						i++;
						Thread.sleep(dur!("seconds")(1));
					}

				}

			}
			return 0;
		}


}
