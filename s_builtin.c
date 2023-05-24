#include "shell.h"

/**
 * shellExit - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: exits with a given exit status
 * (0) if info->arguments[0] != "exit"
 */
int shellExit(info_t *info)
{
  int exitStatus;
  
  if (info->arguments[1]) /* If there is an exit argument */
  {
    exitStatus = safeAtoi(info->arguments[1]);
    if (exitStatus == -1)
    {
      info->status = 2;
      printError(info, "Illegal number: ");
      printErrorMessage(info->arguments[1]);
      printNewLine();
      return (1);
    }
    info->errorNumber = safeAtoi(info->arguments[1]);
    return (-2);
  }
  info->errorNumber = -1;
  return (-2);
}

/**
 * handleChangeDirectory - Helper function for changeDirectory
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * @currentDir: Current directory
 * @targetDir: Target directory
 * Return: chdir result
 */
int handleChangeDirectory(info_t *info, char *currentDir, char *targetDir)
{
  int chdirResult;
  
  if (!info->arguments[1])
  {
    targetDir = getEnvironmentVariable(info, "HOME=");
    if (!targetDir)
      chdirResult = chdir((targetDir = getEnvironmentVariable(info, "PWD=")) ? targetDir : "/");
    else
      chdirResult = chdir(targetDir);
  }
  else if (safeStringCompare(info->arguments[1], "-") == 0)
  {
    if (!getEnvironmentVariable(info, "OLDPWD="))
    {
      printStandardOutput(currentDir);
      printNewLine();
      return (1);
    }
    printStandardOutput(getEnvironmentVariable(info, "OLDPWD="));
    printNewLine();
    chdirResult = chdir((targetDir = getEnvironmentVariable(info, "OLDPWD=")) ? targetDir : "/");
  }
  else
    chdirResult = chdir(info->arguments[1]);

  return chdirResult;
}

/**
 * changeDirectory - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int changeDirectory(info_t *info)
{
  char *currentDir, *targetDir, buffer[1024];
  int chdirResult;

  currentDir = getCWD(buffer, 1024);
  if (!currentDir)
  {
    printStandardOutput("TODO: >>getcwd failure emsg here<<\n");
    return (1);
  }

  chdirResult = handleChangeDirectory(info, currentDir, targetDir);

  if (chdirResult == -1)
  {
    printError(info, "can't cd to ");
    printErrorMessage(info->arguments[1]);
    printNewLine();
  }
  else
  {
    setEnvironmentVariable(info, "OLDPWD", getEnvironmentVariable(info, "PWD="));
    setEnvironmentVariable(info, "PWD", getCWD(buffer, 1024));
  }

  return (0);
}

/**
 * showHelp - displays help information
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int showHelp(info_t *info)
{
  char **argArray;

  argArray = info->arguments;
  printStandardOutput("help call works. Function not yet implemented \n");
  if (0)
    printStandardOutput(*argArray); /* temp att_unused workaround */
  return (0);
}
