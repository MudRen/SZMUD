// welcome.c
// modified by lisser, 10/4/2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", HIC"���ֵĵ���"NOR);
	set ("long", "��ӭ���������ݡ����������һ�������ͺ�����������"HIR"down"NOR"������
�����ݡ�������ȥ����ð�հɣ�����������֣���ʹ��"HIY"help"NOR"ָ����Ϥ�����
�»����������滹�кܶ�Ļ���֪ʶ����ѧϰ����ȥ(enter)ѧϰ�ɡ�
");

	set("exits", ([ /* sizeof() == 2 */
		"enter" : __DIR__"welcome2",
		"down" :"/d/city/kedian",
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
		me->delete("newbie",1);
		return 1;
	}
	return ::valid_leave(me, dir);

}