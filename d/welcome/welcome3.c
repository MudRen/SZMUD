// welcome.c
// modified by lisser, 10/4/2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", HIC"������"NOR);
        set ("long", "������һ�������⣬���ܵı������ϰ��������θ���ĳ��̱��У���
�ϻ�ɢ���ż�����е����������������������ͷ��ߵ�ʹ�÷�������ʹ��
"HIG"get <��Ʒ��>"NOR"����ӵ��ϼ����������߷��ߣ�����"HIY"wield <������Ʒ��>
"NOR"����װ����������"HIY"wear <������Ʒ��>"NOR"����װ�����ߡ�
");

	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"welcome2",
		]));
	set("objects", ([
		"/d/city/obj/gangjian" : 1,
		"/clone/armor/beixin" : 1,
		]));

	set("valid_startroom", "1");
        // set("no_fight", "1");

	setup();
}

int valid_leave(object me, string dir)
{
	me = this_player();

	if( dir=="west" && present("gangjian", me) || present("beixin", me))
		return notify_fail("�㲻�ܰѶ������ߣ�����drop <��Ʒ��>������¶������뿪��\n");
			
	return ::valid_leave(me, dir);

}
