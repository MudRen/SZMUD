// Code of ShenZhou
// huru.c ����Ȫ
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����Ȫ");
	set("long", @LONG
����һ��б���ŵ�ʯƤ����Ȫˮ�ӷ�϶�бų�������һ�����������ʯ��
�С������˲�֪���������ˣ����������ԡ�ˮ��䣼��ף��������飬�����ݲ裬
��ζ������Ƣ��Ȫ�ݼ���Դɽ������Ȫɽ������Դ�ڴ�Ȫ��
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"northup" : __DIR__"qingyuan",
		"southdown" : __DIR__"shanlu2",
	]));

	set("resource/water", 1);

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");
     set("fjing", 1);

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
