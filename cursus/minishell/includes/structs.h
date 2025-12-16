/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 23:30:20 by serjimen          #+#    #+#             */
/*   Updated: 2025/09/06 02:52:13 by sergio-jime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file strutcs.h
 * @brief Header file for minishell data structures.
 * This file contains the definitions for all core data structures used
 * throughout the minishell project.
 */
#ifndef STRUCTS_H
# define STRUCTS_H

/**
 * @struct t_env
 * @brief Node for the environment variable linked list.
 * @var s_env::key A dynamically allocated string for the variable name.
 * @var s_env::value A dynamically allocated string for the variable value.
 * @var s_env::full_env A dynamically allocated string for the full
 * "KEY=value".
 * @var s_env::next A pointer to the next node in the linked list.
 */
typedef struct s_env
{
	char			*key;
	char			*value;
	char			*full_env;
	struct s_env	*next;
}					t_env;

/**
 * @brief Enumeration for the different types of tokens.
 * This enum defines the possible categories a token can fall into.
 * The lexer will use these types to classify each word and operator from
 * the input string, which the parser will later use to build the command
 * execution tree.
 */
typedef enum e_token_type
{
	WORD,			/**< A sequence of characters that is not an operator. */
	PIPE,			/**< Represents the '|' symbol for piping commands. */
	REDIR_IN,		/**< Represents the '<' symbol for input redirection. */
	REDIR_OUT,		/**< Represents the '>' symbol for output redirection. */
	APPEND,			/**< Represents the '>>' symbol for appending output. */
	HEREDOC,		/**< Represents the '<<' symbol for here-document. */
}			t_token_type;

/**
 * @brief Structure for a single token in the command line.
 * This structure represents a single lexical token. It holds the string value
 * of the token,, its classified type, and a pointer to the next token in the
 * sequence, forming a linked list. This linked list of token is the direct
 * output of the lexing phase and the primary input for the parsing phase.
 * @var s_token::value A dynamically allocated string containing the token's
 * literal value.
 * @var s_token::type The classified type of the token, as defined by the
 * 'e_token_type'.
 * @var s_token::next A pointer to the next token in the list. A NULL value
 * indicates the end of the token stream.
 */
typedef struct s_token
{
	char			*value;
	t_token_type	type;
	struct s_token	*next;
}					t_token;

/**
 * @brief 
 * 
 */
typedef struct s_redir
{
	t_token_type	type;
	char			*file;
	struct s_redir	*next;
}					t_redir;

/**
 * @brief 
 * 
 */
typedef struct s_arg
{
	char			*value;
	struct s_arg	*next;
}					t_arg;

/**
 * @brief Structure for a parsed command.
 * This structure represents a single command identified by the parser.
 * @var s_command::cmd_args A dynamically allocated NULL-terminated array
 * of strings representing the command and its arguments.
 * @var s_command::cmd_argc The number of arguments in the 'cmd_args' array.
 * @var s_command::type The classified type of the command, as defined by the
 * 'e_cmd_type' enum.
 * @var s_command::next A pointer to the next command in the parsed command
 * stream.
 */
typedef struct s_command
{
	t_arg				*args;
	size_t				cmd_argc;
	t_redir				*redirs;
	struct s_command	*next;
}						t_command;

#endif