// Code of ShenZhou
// yongning.c ������
// qfy Nov 3, 1996
// modified by aln

#include <ansi.h>

inherit HARBOR;

void create()
{
        set("short", "������");
	set("long", @LONG
��������Ȫ������ۿ�֮һ���������ˮ���ƽ�˾�����ĿԶ��������
  һɫ��ε����覡�����ͣ������������ĸ��ִ�ֻ���ϱߵĹ�ɩ��������һ��
���˵Ĺ��¡�
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"south" : __DIR__"gushao",
		"northwest" : __DIR__"gangkou2",
	]));

        set("objects", ([ 
		__DIR__"npc/tiao-fu" : 1,
		__DIR__"npc/kuli" : 1,
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

        set("navigate/locx", 0);
        set("navigate/locy", -280);

	set("cost", 1);
        setup();
}
