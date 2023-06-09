#include "shell.h"

/**
 * myexit - stops shell
 * @info: struct variables
 * Return: status return exit
 */
int myexit(info_t *info)
{
	int exitcheck;

	if (info->argv[1]) /* If there is an exit arguement */
	{
		exitcheck = _erratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * mycd - directory change
 * @info: struct variable
 * Return: Always 0
 */
int mycd(info_t *info)
{
	char *o, *dir, buffer[1024];
	int chdir_ret;

	o = getcwd(buffer, 1024);
	if (!o)
		_eputs("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_eputs(o);
			_eputchar('\n');
			return (1);
		}
		_eputs(_getenv(info, "OLDPWD=")), _eputchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _mychelp - current directory change
 * @info: arguments Structure
 * Return: 0 success
 */
int _mychelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_eputs("help call works. Function not yet implemented \n");
	if (0)
		_eputs(*arg_array); /* temp att_unused workaround */
	return (0);
}

