// Code of ShenZhou
// taoran.c ��Ȼ���
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��Ȼ���");
	set("long", @LONG
����ר��Ʒ�������۲�Ҷ�ĵ��̣���������������ž����Ŀ�����֮�С�
ǽ����һ��Ŀ��(sign)��
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"xinmen",
	]));

        set("objects", ([ 
		__DIR__"npc/taolao" : 1,
        ]));

	set("item_desc",([
		"sign" : "������  ����ʮ��ͭ��\n"
			 "������  ����ʮ��ͭ��\n"
			 "������  ����ʮ��ͭ��\n"
			 "���򻨲裺��ʮ��ͭ��\n"
			 "��Ƭ    ����ʮ��ͭ��\n"
	]));

        set("no_clean_up", 0);

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
