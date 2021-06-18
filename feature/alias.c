//Cracked by Kafei
// alias.c
// From ES2
// Marz added flood detection on (07/05/96)
#pragma save_binary

#include <ansi.h>
#include <dbase.h>
#include <name.h>
#include <message.h>

#define MAX_REPEAT 40
#define MAX_ALIASES 40
#define HISTORY_BUFFER_SIZE 10
// assuming 20 commands per tick is normal
#define CMDS_PER_TICK 20

mapping alias;

nosave string *history, last_input;
nosave int last_cmd, repeat_cnt = 0;
nosave int cnt = 0;

string process_input(string str)
{
	string *args, cmd, argstr;
	object me;
	int i, j;
        clear_written();
	if (str == "")
		 return "";
	else
		last_input = str;

	if (userp(this_object())
 	 && (this_object()->query_temp("quit/forced") ||
             !living(this_object())) )
		return "";

	if ( userp(this_object()) && living(this_object()) )
	{
	cnt++;
	me = this_object();
	if ( cnt >  3*CMDS_PER_TICK )
	{
		tell_object(me, "\n\n����Ϸ����������ָ�\n\n");

		if ( random(2) )
		{
		message_vision(HIR"��Ȼһ����������ͷ��ը�������������������\n"
		   "һ��������콵�£�������$N���ϡ�\n"NOR, me);

		me->set_temp("last_damage_from", "������������");
		me->unconcious();
		} else
		{
		message_vision(HIR"��Ȼһ����������ͷ��ը�������������������\n"
		   "һ��������콵�£�ֱ��$N��ȥ�������û���У�\n"NOR, me);
		}

		log_file("FLOODER", sprintf("%s(%s) was caught flooding on %s.\n",
			 me->query("name"), geteuid(me), ctime(time())));

		me->set_temp("quit/forced", 1);
		me->set_temp("quit/report_msg", "��������ָ��߳���Ϸ��Command Flooding����");
		if ( !command("quit") ) me->delete_temp("quit");
		return "";
	} else if (cnt > CMDS_PER_TICK)
	{
		i = (int)me->query("qi");
		j = 1+(cnt-CMDS_PER_TICK)/4;

		if (i > j) me->receive_damage("qi", j, "������������");
		else me->receive_damage("jing", j/2, "������������");
	}

	if( this_object()->query("language") == "BIG5" )
		str = "/adm/daemons/languaged"->toGB(str);

	}


	if( str[0]=='!' ) {
		if( pointerp(history) && sizeof(history) ) {
			if( sscanf(str, "!%d", i) )
				str = (string)history[(HISTORY_BUFFER_SIZE + last_cmd - i) % HISTORY_BUFFER_SIZE];
			else
				str = history[last_cmd];
		} else
			return "";
	} else {
		if( !pointerp(history) ) history = allocate(HISTORY_BUFFER_SIZE);
		last_cmd = (last_cmd + 1) % HISTORY_BUFFER_SIZE;
		history[last_cmd] = str;
	}

	if( mapp(alias) ) {

		if( !undefinedp(alias[str]) )
			return replace_string( alias[str], "$*", "" );

		if( sscanf(str, "%s %s", cmd, argstr)==2 && !undefinedp(alias[cmd]) ) {
			cmd = replace_string( alias[cmd], "$*", argstr );
			args = explode(argstr, " ");
			if( (j = sizeof(args)) )
				for(i=0; i<j; i++)
					cmd = replace_string( cmd, "$" + (i+1), args[i] );
			return cmd;
		}
	}

	last_input = (string)ALIAS_D->process_global_alias(str);
	log_command(last_input);
        return last_input;
}

void clear_cmd_count()
{
	cnt -= 2*CMDS_PER_TICK;
	if (cnt < 0) cnt = 0;
}

int query_cmd_count() { return cnt; }

int set_alias(string verb, string replace)
{
	if( !replace ) {
		if( mapp(alias) ) map_delete(alias, verb);
		return 1;
	} else {
		if( !mapp(alias) ) alias = ([ verb:replace ]);
		else if( sizeof(alias) > MAX_ALIASES )
			return notify_fail("���趨�� alias ̫���ˣ�����ɾ��һЩ�����õġ�\n");
		else alias[verb] = replace;
		return 1;
	}
}

mapping query_all_alias()
{
	return alias;
}
