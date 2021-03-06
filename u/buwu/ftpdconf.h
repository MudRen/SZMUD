/* ftpdconf.h: ftpd configuration */

#ifndef _FTPDCONF_H
#define _FTPDCONF_H

// The following defines are in <globals.h> which is included automatically.
// #include <uid.h>        /* gets define for ROOT_UID on tmi-2 */
// #include <config.h>
// 注释 by buwu

#include <mudlib.h> /* gets mud info define from The.Master.Of.Hero */
#include <net/socket.h> /* various socket defines from tmi-2 */

/*
-----------------------------------------------
   standard defines.
-----------------------------------------------
*/

/* FTPD_PORT port number on which the ftp daemon will listen.  On a UNIX
   system the user should type: ftp tmi.lp.mud.org 5554
   (depending on the hostname of the MUD and the port # set below).
   登录FTP的Port，只要设置成和进入MUD的Port不同就行了。    
*/
#define FTPD_PORT 4100

/* time in seconds that an ftp connection should be idle before it times out;
 * this is used as the default for all connections--see MAX_FTPD_IDLE
   在FTP上所能发呆的default值，按秒计算。超过这个时间就会自动断线。 
 */
#define FTPD_TIMEOUT 900

/* this is the maximum idle value that can be set with the SITE IDLE command;
 * note that when a user logs into ftp, they are assigned the value in
 * FTPD_TIMEOUT and may manually adjust it up to the limit of MAX_FTPD_IDLE
   在FTP上所能发呆的最大值，和上面那个不同的是可以由siteidle指令人工设定。 
 */
#define MAX_FTPD_IDLE 7200
 
/* HOME_DIR: given a username give the home directory path 
   使用者数据来自的目录。 */
#define HOME_DIR(name)  user_cwd(name) /* on TMI-2 */

/* If this is defined, it should point to a file that should be
 * displayed upon every successful login.
   进入FTP时的欢迎图像，一般应存于/adm/etc。 
 */
#define LOGIN_MSG       "/adm/etc/ftpd_welcome"

/* the name of the MUD 
   MUD 的名字*/
#define THE_MUD_NAME    INTERMUD_MUD_NAME

/* Maximum number of simultaneous ftp users. 
   最多能同时使用FTP的人数。 */
#define FTPD_MAX_USERS 10

/* the version # of the driver (__VERSION__ on MudOS muds) 
   Mudos的版本。不是ftp文件的版本喔。 */
#define THE_VERSION __VERSION__

/* Set this to be the size of each outgoing block of data during
 * file transfers.  This hasn't been tested with any value other
 * than 1024, so its generally good to leave this alone.
   传输文件最大值。 
 */
#define BLOCK_SIZE 1024

/* who to send bug reports to */
#define FTP_BUGS_EMAIL "robocoder@tmi-2 or annihilator@es2"

/*
-----------------------------------------------
   misc support defines.
-----------------------------------------------
*/

/* define this to allow "anonymous" ftp logins 
   没有id的用户登录FTP。*/
#undef ANONYMOUS_FTP

/* define this to allow guest wizards (without home directories) to login 
   没有home目录，即/u下目录的巫师登录FTP。*/
#undef GUEST_WIZARD_FTP

/* define this to support advisory file locking 
   对特殊的文件进行保护。 */
#undef FILE_LOCKING

/* define this to support individual site checking (from .login file) 
   对个别ID（如admin级）进行site限制。 */
#undef CHECK_SITE

/* define this to support .message files sent to user when they "cd" 
   当转换路径时给出的信息。*/
#define MESSAGE_FILES

#if 0
/*
 * (copied from ftpd.h)
 * these flags determine read level access (values are intentionally unique...
 * and are manually generated, so don't change them)
 */
#define VALID_READ       0              // rely on valid_read()
#define RESTRICTED_READ  1              // ditto, but limited to public dirs
#define WRITE_LIMIT_READ 2              // access limited by write access
#endif

/* define as (ie set to) one of the flags above */
#define READ_LEVEL (VALID_READ)

#if 0
/*
 * (copied from ftpd.h)
 * these flags determine write level access (values are intentionally unique...
 * and are manually generated, so don't change them)
 */
#define VALID_WRITE      0              // rely on valid_write()
#define RESTRICTED_WRITE 1              // ditto, but limited to public dirs
#define READ_ONLY        2              // no write access, at all
#endif

/* define as (ie set to) one of the flags above */
#define WRITE_LEVEL (RESTRICTED_WRITE)

/* define the following public dirs that you'll limit access to
 * for RESTRICTED_READ and/or RESTRICTED_WRITE; undefine any for which
 * the directory doesn't exist on your system
 */
#define PUB_DIR "/open"
#define FTP_DIR "/ftp"

/* define this array as the only set of users permitted to use ftp
   允许使用FTP的用户名称。 
 * Example:
 *   #define FTP_USERS ({ "buddha", "mobydick", "watcher" })
 */
#define FTP_USERS ({"buwu", "lara", "yujie", "scatter", "jiuer", "piao", "lisser", "april" })

/*
-----------------------------------------------
   debugging defines.
-----------------------------------------------
*/

/* define DEBUG to enable debugging info */
#undef DEBUG

/* player to whom to "tell" debugging info */
#define TP_CRE "ken"

/*
-----------------------------------------------
   log file defines.
-----------------------------------------------
*/

/* undefine this to disable all logging */
#define LOGGING

#ifdef LOGGING
/* define this to log all connections */
#define LOG_CONNECT
/* define this to determine where to log all file xfers 
FTP记录文件。 */
#define LOG_FILE        "FTPD"
/* define this to put a time stamp before all log entries */
#define LOG_TIME
/* define this to log cd's, time stamp, and file size commands */
#define LOG_CD_SIZE
/* define this to log failed connections */
#define LOG_NO_CONNECT

#else

#undef LOG_CONNECT
#undef LOG_FILE
#undef LOG_CD_SIZE
#undef LOG_TIME
#undef LOG_NO_CONNECT

#endif /* LOGGING */

/*
-----------------------------------------------
   consistency checks
-----------------------------------------------
*/

/* restricting ftp to a limited number of users and having anon ftp
 * at the same time is pointless
 */
#if defined(ANONYMOUS_FTP) && defined(FTP_USERS)
#undef ANONYMOUS_FTP
#endif

/*
 * server should restrict anonymous ftp by using a restricted directory
 */
#if defined(ANONYMOUS_FTP) && !defined(FTP_DIR)
#undef ANONYMOUS_FTP
#endif

/* guest wizards, if permitted to login, need some place to go */
#if defined(GUEST_WIZARD_FTP) && !defined(PUB_DIR)
#define PUB_DIR "/"
#endif

#endif /* _FTPDCONF_H */

