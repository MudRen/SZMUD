// Code of ShenZhou
// citong_x1.c ��ͩ��·
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ͩ��·");
	set("long", @LONG
����Ȫ�ݵ���Ҫ�ɵ�����ֱ��㣬��ˮ���������ַǷ������߱���������
��Ԫ�¼����ŵ��š�������һ���ӻ��̣�ר��Ů�˼��õĶ�����
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"citong_w2",
		"east" : __DIR__"zhongxin",
		"north" : __DIR__"zahuopu",
	]));

        set("objects", ([ 
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
//	replace_program(ROOM);
}
/*

int valid_leave(object me, string dir)
{
	if ( dir == "north" && me->query("gender") == "����" && !wizardp(me) )
		return notify_fail("��һ�������˵�Ů�˵���ȥ���ʲô��\n");

	return ::valid_leave(me, dir);
}
*/
