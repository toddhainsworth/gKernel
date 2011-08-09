// ---------------------------------------------------------------------------------
// Basic Source to show a Kernel Boot
// Author: GeissT of Hackforums.net
// Description: The kernel is not really a kernel but it just shows how one would
//              work, the program acts as if it were an operating system, it does
//              not have a filesystem and has some basic commands, in later
//              versions it will use the host computers (Linux's) filesystem for
//              file storage.
// ---------------------------------------------------------------------------------

#include <stdio.h> // just some standard IO stuff.
#include <string.h> // for string manipulation.
#include <stdlib.h> // for exit() function.
#include <time.h> // to make the program sleep, simulating work.

#define HYDROS_VER 0.1

// char lastcmd[50] = "test";

void strip_newline();
int prompt();
// void cmdhand();
int help();
void echo();
void out();
void now();
void makelast();
void version();
int shutdown();
void cls();
void last(char command[50]);
void users();

void strip_newline( char *str, int size )
{
    int i;

    // remove the null terminator
    for (  i = 0; i < size; ++i )
    {
        if ( str[i] == '\n' )
        {
            str[i] = '\0';

            // we're done, so just exit the function by returning
            return;
        }
    }
    // if we get all the way to here, there must not have been a newline!
}

void main(void)
{
	system("clear");
	printf("Booting the kernel....\n");
	sleep(3); // just resting, yes i am working here.
	printf("Kernel successfully booted!\n");
	prompt();
}

int prompt()
{
	char cmd[50]; // declaring the string for command input.
	printf("user||>> "); // display the prompt.
	fgets(cmd, 50, stdin); // fgets() is used for standard input.
	strip_newline(cmd, 50);

	if(strcmp(cmd, "help") == 0) // help command
	{
		help();
	}
	if(strcmp(cmd, "exit") == 0) // exit command
	{
		shutdown();
		return 0;
	}
	if(strcmp(cmd, "echo") == 0) // echo command
	{
		echo();
	}
	if(strcmp(cmd, "ver") == 0) // returns the version of HydrOS
	{
		version();
	}
	if(strcmp(cmd, "usr") == 0) // returns the list of users logged on.
	{
		users();
	}
	if(strcmp(cmd, "out") == 0) // output to a file
	{
		out();
	}
	if(strcmp(cmd, "cls") == 0) // cls command to clear screen
	{
		cls();
	}
	if(strcmp(cmd, "now") == 0) // time command
	{
		now();
	}
	if(strcmp(cmd, "last") == 0) // 'last' command
	{
		last(cmd);
	}
	else // if the command is not valid....
	{
		printf("Command not found!\n");
		prompt();
	}
	return 0;
}

void echo() // echo what the user types
{
	char echo[50];
	printf("What would you like to echo?\n");
	fgets(echo, 50, stdin);
	strip_newline(echo, 50);
	printf("%s\n", echo);
	prompt();
}

void version()
{
	printf("HydrOS Version: %.1f \n", HYDROS_VER);
	prompt();
}

int help()
{
	printf("\n");
	printf("***********\n");
	printf("HydrOS Help\n");
	printf("***********\n");
	printf("\n");
	printf("help: \t Displays this text\n");
	printf("echo: \t Echo the typed text\n");
	printf("ver: \t Display the current HydrOS version\n");
	printf("usr: \t Displays User Information\n");
	printf("now: \t Prints the current time\n");
	printf("cls: \t Clears the screen and returns to prompt\n");
	printf("exit: \t Shutdown HydrOS\n");
	printf("\n");
	prompt();
}

void out()
{
	char saved[100];
	printf("What would you like saved?");
	fgets(saved, 100, stdin);
	printf("You typed: %s\n", saved);
	prompt();
}

void users()
{
	printf("No user functions available!\n");
	printf("More will be added in later releases!\n");
	prompt();
}

void cls()
{
	system("clear"); // sends the clear command to the system.
	prompt();
}

void now()
{
	time_t now;
  	time(&now);

  	printf("Time: \t%s", ctime(&now)); 

	prompt();
}

void makelast(char hydcmd[50])
{
	last(hydcmd);
}

void last(char command[50])
{
	printf("The last command was: %s\n", command);
	prompt();
}

int shutdown()
{
    printf("Shutting down....\n");
    exit(0);
}
