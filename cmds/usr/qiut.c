// Code of ShenZhou
// quit.c
//last update: Marz added forced_quit on 07/06/96

#include <command.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

private int slow_quit(object);

void create() 
{
	seteuid(getuid());
	set("channel_id", "����ָ��");
	set("id", "quit");
}

int main(object me, string arg)
{
	if( (me->is_busy() || me->is_fighting() || me->query_temp("cursed", 1)) 
	&&  !me->query_temp("quit/forced") )
		return notify_fail("��������æ���������£������˳���Ϸ��\n");

	if ( me->query_temp("quit/forced") ) call_out("slow_quit", 0, me);
	
	if( me->query_temp("quitting") )
		return notify_fail("��Ϸ�˳������Ѿ����������ڽ����У�\n");

	if( environment(me)->query("invalid_startroom") ) 
	{
	// the following two lines added by Mongol. 6/12/97.  To avoid login
	// from hell, etc.
//		me->delete("startroom");
		me->set("startroom", "/d/city/kedian");
		tell_object( me, "\n����һ�����ܽ�����Ϸ�ĵط��˳����´ν�����Ϸ���ӱ�ĵط���ʼ��\n");
		me->set_temp("quitting", 1);
		tell_object( me, "\n��ʼ�˳���Ϸ�������� ...\n\n" );
		call_out("slow_quit", 10 + random(10), me);
	} else if( environment(me)->query("valid_startroom") ) {
		me->set("startroom", base_name(environment(me)));
		me->set_temp("quitting", 1);
		slow_quit(me);
	} else {
		tell_object( me, "\n��ʼ�˳���Ϸ�������� ...\n\n" );
		me->set("startroom", base_name(environment(me)));
		me->set_temp("quitting", 1);
		call_out("slow_quit", 10 + random(10), me);
	}

	return 1;
}

private int slow_quit(object me)
{
	int i, stage;
	string msg;
	object *inv, link_ob;

	if( objectp(me) && wizhood(me) == "(player)" ) {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			if( !inv[i]->query_autoload() )
				DROP_CMD->do_drop(me, inv[i]);

			if( me->query_encumbrance() > me->query_max_encumbrance() ) {
			    if( base_name(inv[i]) == GOLD_OB || base_name(inv[i]) == SILVER_OB ) {
				tell_object(me, "�����̫���Ǯ�����ˣ�ֻ�ý�"+inv[i]->name()+"�����ˣ�\n");
				destruct(inv[i]);
			    }
			}
		}
			
	}

	if ( me->query("bt/job") == 1 ){
		log_file("/job/bt-fangshe",sprintf("%s(%s) get %d exp , %d pot and %d training from quit at fangshe's job on %s\n",me->name(), me->query("id"),me->query("bt/exp"),me->query("bt/pot"),me->query("bt/lvl"), ctime(time())));
		me->delete("bt", 0);
		me->set("bt/job", 1);
	}
	if ( me->query("gm/job") == 1 ){
		log_file("/job/gm-bee",sprintf("%s(%s) get %d exp , %d pot and %d training from quit at gumu bee job on %s\n",me->name(), me->query("id"),me->query("gm/exp"),me->query("gm/pot"),me->query("gm/lvl"), ctime(time())));
		me->delete("gm", 0);
		me->set("gm/job", 1);
	}
	if (!me) return 1;
	link_ob = me->query_temp("link_ob");

	// We might be called on a link_dead player, so check this.
	if( link_ob ) {

		// Are we possessing in others body ?
		if( link_ob->is_character() ) {
			write("��Ļ��ǻص�" + link_ob->name(1) + "�����ϡ�\n");
			exec(link_ob, me);
			me->delete_temp("quitting");
			link_ob->setup();
			return 1;
		}

		link_ob->set("last_on", time());
		link_ob->set("last_from", query_ip_name(me));
		link_ob->save();
//                LOGIN_D->write_log(link_ob);
		destruct(link_ob);
	}

	write("��ӭ�´�������\n");
	message("system", me->name() + "�뿪��Ϸ��\n", environment(me), me);

	if (stringp(msg = me->query_temp("quit/report_msg")))
		CHANNEL_D->do_channel(this_object(), "sys", me->name() + msg);
	else	
		CHANNEL_D->do_channel(this_object(), "sys", me->name() + "�뿪��Ϸ�ˡ�");

	me->save();
	destruct(me);

	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : quit

����(��)����ʱ�뿪ʱ, �����ô�һָ�
HELP
    );
    return 1;
}

