// Code of ShenZhou
// anhai.c ������
// qfy Nov 3, 1996
// modified by aln 4 / 98

#include <ansi.h>

inherit HARBOR;

void create()
{
        set("short", "������");
	set("long", @LONG
��������Ȫ������ۿ�֮һ���������ˮ���ƽ�˾�����ĿԶ��������
  һɫ��ε����覡�����ͣ������������ĸ��ִ�ֻ������������ɩ����
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"east" : __DIR__"gushao",
		"north" : __DIR__"gangkou2",
	]));

        set("objects", ([ 
		__DIR__"npc/kuli" : 1,
		__DIR__"npc/tiao-fu" : 1,
		__DIR__"npc/langren" : 2,
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

        set("navigate/locx", 0);
        set("navigate/locy", -300);

	set("cost", 1);
        setup();
}
