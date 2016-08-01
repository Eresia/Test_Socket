module main;

import std.stdio;

import client;
import server;

int main(string[] args) {
	if(args.length < 2){
		writeln("Not enough argument");
		return -1;
	}
	writeln("Hello World !");
	return 0;
}
