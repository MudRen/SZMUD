// Code of ShenZhou
// guard.c
// Ryu, 4/28/98

#include <ansi.h>;
inherit F_CLEAN_UP;

mapping default_dirs = ([
	"north":	"��",
	"south":	"��",
	"east":		"��",
	"west":		"��",
	"northup":	"����",
	"southup":	"�ϱ�",
	"eastup":	"����",
	"westup":	"����",
	"northdown":	"����",
	"southdown":	"�ϱ�",
	"eastdown":	"����",
	"westdown":	"����",
	"northeast":	"����",
	"northwest":	"����",
	"southeast":	"����",
	"southwest":	"����",
	"up":		"��",
	"down":		"��",
	"out":		"��",
	"enter":	"��",
	"in":		"��",
	"left":		"��",
	"right":	"��",
]);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string dest, dir;
	object env, obj, ob;
	mapping exit;

	if( !arg ) return notify_fail("��Ҫ��ס�ĸ�����\n");

	if( me->is_busy() )
		return notify_fail("��ǰһ��������û����ɡ�\n");

	env = environment(me);
	if(!env) return notify_fail("������Ҳ�ò����ء�\n");

	if( env->query("no_fight") || env->query("day_shop"))
		return notify_fail("�㲻�������ﵲ���˳�·��\n");

	if( strsrch(file_name(env), "/d/xiakedao/") >= 0 )
		return notify_fail("��������������ڵ���������·��\n");
	if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) ) 
			return notify_fail("������ס�ĸ�����\n");

//	if( !env->valid_leave(me, arg) ) return 0;

	if( !stringp(dest = me->query_temp("new_valid_dest")) ) 
		dest = exit[arg];

	if( !(obj = load_object(dest)) )
		return notify_fail("ERROR��\n");


	if( !undefinedp(default_dirs[arg]) )
		dir = default_dirs[arg];
	else
		dir = arg;

	if (objectp(ob=env->query("exit_blockers/"+dir)))
		return notify_fail(ob->query("name")+"�Ѿ���ס����"+dir+"ȥ�ĳ�·��\n");

	if (me->query_temp("exit_blocked")){
		message_vision("$N�ÿ�����"+me->query_temp("exit_blocked")+"ȥ��ͨ·��\n", me);
		env->delete("exit_blockers/"+me->query_temp("exit_blocked"));
		me->delete_temp("exit_blocked");
	}

	me->start_busy(1);
	me->set_temp("exit_blocked", dir);
    env->set("exit_blockers/"+dir, me);

	message_vision(CYN"$N��·�м�һվ����ס����" + dir + "ȥ�ĳ�·��\n"NOR, me);
	call_out("cost",3);
	return 1;
}

void cost()
{
	object env, obj, ob;
	object me = this_player();
	env = environment(me);

	if( !me->query_temp("exit_blocked") ) return;

	if(me->query("jingli",1)<200 || me->query("jing",1)<200)
	{
		message_vision("$N������ô�ã�ʵ����̫���ˣ�ֻ���ÿ�����"+me->query_temp("exit_blocked")+"ȥ��ͨ·��\n", me);
		env->delete("exit_blockers/"+me->query_temp("exit_blocked"));
		me->delete_temp("exit_blocked");
		return;
	}
	
	me->add("jingli", -me->query("max_jingli",1)/20);
	me->add("jing", -me->query("max_jing",1)/20);
	call_out("cost",3);
}

int help(object me)
{
	write(@HELP
ָ���ʽ : block <����>
 
���㵲ס��һ����ĳ�·��˭Ҳ���ù���
����㲻��������������·���뿪������伴�ɡ�

HELP
    );
    return 1;
}
