# Shell Project

## Overview

I'm excited to share my shell project, a simple implementation of a Unix-like shell in C.

## Features

### Command Execution

I implemented command execution using the `execve` system call, allowing me to run both built-in commands and external commands.

### Environment Variables

I added support for environment variables, enabling users to set and unset them using the `setenv` and `unsetenv` commands. I also included the `env` command to print the current environment variables.

### Built-in Commands

I created several built-in commands, including:

* `exit`: Exits the shell.
* `env`: Prints the current environment variables.
* `setenv`: Sets an environment variable.
* `unsetenv`: Unsets an environment variable.
* `cd`: Changes the current directory.
* `alias`: Sets an alias for a command.

### Other Features

I also implemented:

* Command history
* Tab completion
* Error handling

## Usage

### Running the Shell

To run the shell, simply compile the code and execute the resulting binary.

### Using the Shell

I designed the shell to be user-friendly, allowing users to execute commands, manage environment variables, and use built-in commands.

## Commands

### External Commands

I supported external commands using the `execve` system call.

### Built-in Commands

I created the following built-in commands:

* `exit`: Exits the shell.
* `env`: Prints the current environment variables.
* `setenv`: Sets an environment variable.
* `unsetenv`: Unsets an environment variable.
* `cd`: Changes the current directory.
* `alias`: Sets an alias for a command.

## Environment Variables

### Setting Environment Variables

I enabled setting environment variables using the `setenv` command.

### Unsetting Environment Variables

I allowed unsetting environment variables using the `unsetenv` command.

### Printing Environment Variables

I included the `env` command to print the current environment variables.

## Built-in Commands

### `exit`

I implemented the `exit` command to exit the shell.

### `env`

I created the `env` command to print the current environment variables.

### `setenv`

I added the `setenv` command to set an environment variable.

### `unsetenv`

I implemented the `unsetenv` command to unset an environment variable.

### `cd`

I supported changing the current directory using the `cd` command.

### `alias`

I enabled setting an alias for a command using the `alias` command.

## Error Handling

I implemented error handling for invalid commands, invalid arguments, and other errors.

## Limitations

While I'm proud of my shell project, I acknowledge its limitations, including:

* Limited command history
* Limited tab completion
* No support for pipes or redirection
* No support for job control

## Future Development

I plan to improve my shell in the future by:

* Adding support for pipes and redirection
* Adding support for job control
* Improving command history and tab completion
* Adding more built-in commands

## Conclusion

I'm thrilled to share my shell project, a simple implementation of a Unix-like shell in C. I hope you find it useful and interesting. I look forward to continuing to improve and expand my shell in the future.
