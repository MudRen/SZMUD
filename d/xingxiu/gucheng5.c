// Code of ShenZhou
// �����
// maco
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIW"�����ɽ��"NOR);
	set("long", @LONG
���ǹų����ģ�Ҳ�ǰ���ɽ��(mountain)��ɽ���¡�����
������������ͨ��ѩ�ף�Ө�ⴿ������̧ͷ������ֻ���Ŀ�����
�����Ǿ�����������̾����֮�档
LONG
	);

	set("exits", ([
		"east" : __DIR__"gucheng3",
	]));
	set("item_desc", ([
	"mountain" : "������ɽ�壬����ɽ������Щ����ۼ����ƺ����������̤�ţ�Ҳ����Դ������ȥ��\n",
	]));

	set("outdoors","xingxiu");
	set("cost", 1);
	setup();
}


void init()
{
        add_action("do_jump", "jump");
        add_action("do_climb", "climb");
}
int do_climb(string arg)
{
	if( !arg || arg=="" ) return notify_fail("�������Ķ�����\n");

	if( arg == "up") return notify_fail("ɽ������̤�Ŵ����£�ȫ��һƬ�⻬������������ȥ��Ǭ��ֱ�����������԰ɡ�\n");
	else return notify_fail("�㲻�����������\n");
}

int do_jump(string arg)
{
	object me, weapon;
	string msg, type;

	me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg=="up" )
	{
		if (me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("����æ���ء�\n");

		if(me->query("rided"))
		return notify_fail("����������������ɣ�\n");

		if( me->query_skill("dodge") < 200 ) {
		message_vision("$N���������һ�����ϰ���塣\n", me);
		message_vision("�������̫����$Nһ��̤����ɽ�ڣ��޷���ʹ�����������顱��һ��ˤ�µ�����\n", me);
		me->start_busy(1);
		me->receive_damage("qi", 50+random(20), "�ʰ����ʧ��ˤ����");
		return 1;
		}

		if( !objectp(weapon = me->query_temp("weapon")) ) 
		msg = "$N�������������ͱ��ϱ�ȥ���ϵ����࣬�ư���壬һ�������ٱ������࣬�ѵ�̤�ŵ����ڡ�\n";
		else {
			type = weapon->query("skill_type");
			if(type == "sword" || type == "sword" || type == "pike" ) 
			msg = "$N�������������ͱ��ϱ�ȥ���ϵ����࣬��"+weapon->name()+"������壬һ�������ٱ������࣬�ѵ�̤�ŵ����ڡ�\n";
			else msg = "$N�������������ͱ��ϱ�ȥ���ϵ����࣬"+weapon->name()+"�������һ����һ�������ٱ������࣬�ѵ�̤�ŵ����ڡ�\n";
		}
			message_vision(msg, me);

			me->move("/d/xingxiu/baiyufeng");
			message("vision", me->name() + "��ɽ������������\n", 
			environment(me), ({me}) );
			me->start_busy(1);
			return 1;

	}
}	
