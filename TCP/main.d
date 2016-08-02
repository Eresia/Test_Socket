module main;

import std.stdio;
import std.conv;
import std.socket;

import client_module;
import server_module;

int main(string[] args) {
	if(args.length < 3){
		writeln(help());
		return -1;
	}

	if(args[1] == "-c"){
		if(args.length < 4){
			writeln(help());
			return -3;
		}

		immutable string ip = args[2];
		immutable ushort port = to!ushort(args[3]);

		if(port == 0){
			writefln("Port have to be a number > 0");
			return -4;
		}

		try{
			return new Client_Module(ip, port).beginCommunication();
		}
		catch(SocketAcceptException e){
			writefln(e.msg);
			return -6;
		}
		catch (SocketOSException e){
			writefln(e.msg);
			return -7;
		}

	}
	else if(args[1] == "-s"){
		immutable ushort port = to!ushort(args[2]);

		if(port == 0){
			writefln("Port have to be a number > 0");
			return -5;
		}

		try{
			return new Server_Module(port).launchServer();
		}
		catch(SocketAcceptException e){
			writefln(e.msg);
			return -6;
		}
		catch (SocketOSException e){
			writefln(e.msg);
			return -7;
		}
	}
	else{
		writeln(help());
		return -2;
	}
	writeln("Hello World !");
	return 0;
}

/****/
string help(){
	return "Usage : \ntestTCP.out [-c ip port] [-s port]\n-c : Create client\n-s : Create Server";
}
