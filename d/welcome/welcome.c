// welcome.c
// modified by lisser, 10/4/2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", HIC"���ֵĵ���"NOR);
	set ("long", "��ӭ���������ݡ����������һ���������к�����������"HIR"down"NOR"����
�����ݡ�������ȥ����ð�հɣ�����������֣���ʹ��"HIY"help"NOR"ָ����Ϥ�����
�»����������滹�кܶ�Ļ���֪ʶ����ѧϰ����ȥ(enter)ѧϰ�ɡ�

        ����"HIY" help newbie "NOR"�����̻ش��������ӵ����ʣ�


");

	set("exits", ([ /* sizeof() == 2 */
		"enter" : __DIR__"welcome2",
		"down" :"/d/city/kedian",
		"xkd" : "/d/xiakedao/shatan",
		]));

	set("valid_startroom", "1");
	set("no_fight", 1);

setup();
}

int valid_leave(object me, string dir)
{
	me = this_player();

	if( dir=="enter" ) return 1;

	if( dir=="down" ) {
		me->delete("newbie", "yes");
	}
	return ::valid_leave(me, dir);
}
