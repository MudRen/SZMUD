// Code of ShenZhou
// help.c

#include <ansi.h>
#include "/doc/help.h"

inherit F_CLEAN_UP;

string *default_search = DEFAULT_SEARCH_PATHS;


string setcolor(string msg)
{
        msg = replace_string(msg, "$BLK$", BLK);
        msg = replace_string(msg, "$RED$", RED);
        msg = replace_string(msg, "$GRN$", GRN);
        msg = replace_string(msg, "$YEL$", YEL);
        msg = replace_string(msg, "$BLU$", BLU);
        msg = replace_string(msg, "$MGA$", MAG);
        msg = replace_string(msg, "$CYN$", CYN);
        msg = replace_string(msg, "$WHT$", WHT);
        msg = replace_string(msg, "$HIR$", HIR);
        msg = replace_string(msg, "$HIG$", HIG);
        msg = replace_string(msg, "$HIY$", HIY);
        msg = replace_string(msg, "$HIB$", HIB);
        msg = replace_string(msg, "$HIM$", HIM);
        msg = replace_string(msg, "$HIC$", HIC);
        msg = replace_string(msg, "$HIW$", HIW);
        msg = replace_string(msg, "$NOR$", NOR);
        msg = replace_string(msg, "$HBRED$", HBRED);
        msg = replace_string(msg, "$HBGRN$", HBGRN);
        msg = replace_string(msg, "$HBYEL$", HBYEL);
        msg = replace_string(msg, "$HBBLU$", HBBLU);
        msg = replace_string(msg, "$HBMAG$", HBMAG);
        msg = replace_string(msg, "$HBCYN$", HBCYN);
        msg = replace_string(msg, "$HBWHT$", HBWHT);
        msg = replace_string(msg, "$BBLK$", BBLK);
        msg = replace_string(msg, "$BRED$", BRED);
        msg = replace_string(msg, "$BGRN$", BGRN);
        msg = replace_string(msg, "$BYEL$", BYEL);
        msg = replace_string(msg, "$BBLU$", BBLU);
        msg = replace_string(msg, "$BMAG$", BMAG);
        msg = replace_string(msg, "$BCYN$", BCYN);
        msg = replace_string(msg, "$SPARK$", BLINK);
/*	msg = replace_string(msg, "$BOLD$", BOLD);
        msg = replace_string(msg, "$CLR$", CLR);
        msg = replace_string(msg, "$HOME$", HOME);
        msg = replace_string(msg, "$REF$", REF);
        msg = replace_string(msg, "$BIGTOP$", BIGTOP);
        msg = replace_string(msg, "$BIGBOT$", BIGBOT);
        msg = replace_string(msg, "$SAVEC$", SAVEC);
        msg = replace_string(msg, "$REST$", REST);
        msg = replace_string(msg, "$SINGW$", SINGW);
        msg = replace_string(msg, "$DBL$", DBL);
        msg = replace_string(msg, "$FRTOP$", FRTOP);
        msg = replace_string(msg, "$FRBOT$", FRBOT);
        msg = replace_string(msg, "$UNFR$", UNFR);
        msg = replace_string(msg, "$U$", U);
        msg = replace_string(msg, "$REV$", REV);
        msg = replace_string(msg, "$HIREV$", HIREV);*///discard by Karlopex@sz
	return msg+NOR;
}

int main(object me, string arg)
{
	int i;
	string file, *search;

	// If no topic specified, give the topics.
	if( !arg ) {
		cat(HELP_DIR + "help/topics");
		return 1;
	}

	// Else, try if a command name is specified.
	seteuid(getuid());
	if( stringp(file = me->find_command(arg)) ) {
		notify_fail("�����ָ����ڣ����ǲ�û����ϸ��˵���ļ���\n");
		return file->help(me);
	}

	// Search the individual search path first.
	if( pointerp(search = me->query("help_search_path")) ) {
		i = sizeof(search);
		while(i--) if( file_size(search[i] + arg)>0 ) {
			me->start_more( read_file(search[i] + arg) );
			return 1;
		}
	}

	// Support efun/lfun help with same name as other topics such as
	// ed() and ed command.
	sscanf(arg, "%s()", arg);

	// Finally, search the default search paths.
	if( pointerp(default_search) ) {
		i = sizeof(default_search);
		while(i--) if( file_size(default_search[i] + arg)>0 ) {
			me->start_more( setcolor(read_file(default_search[i] + arg)) );
			return 1;
		}
	}

	return notify_fail("û��������������˵���ļ���\n");
}

int help(object me)
{
	write(@HELP
ָ���ʽ��help <����>              ���磺> help cmds
          help <��������>()        ���磺> help call_out()

���ָ���ṩ�����ĳһ�������ϸ˵���ļ������ǲ�ָ�����⣬���ṩ���й�
������ļ���
HELP
	);
	return 1;
}

