// Code of ShenZhou
// chengtian.c ������
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
����Ȫ����������󰲵������Ա������������ȷ�ǣ������˳����
�ڹ㳡������һ��̳������������ͨ����ͩ��·��
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"northeast" : __DIR__"gtxiang",
		"west" : __DIR__"citong_s2",
	]));

	set("objects", ([ 
                __DIR__"npc/monk" : 1,
	]));

        set("no_clean_up", 0);

	set("cost", 1);
        setup();
}
