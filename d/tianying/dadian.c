// Code of ShenZhou
// room: dadian.c

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
����һ����ΰ�Ĵ�ƽʱ��ӥ�������Ǿ������﷢��ʩ���
�����ż���������������������İ������ߡ����Ե��ŵ�ǽ�Ϲ���һ
����ͼ��ͼ�ϻ���һֻ��ӥ�����߻���һ������(duilian)��
LONG );

        set("exits", ([
                "west" : __DIR__"zoulang1",
                "south" : __DIR__"guangchang",
		"east" : __DIR__"zoulang3",
		"north" : __DIR__"zoulang5",
        ]));

	set("item_desc", ([
		"duilian" : HIC "\n���¹���  ��ӥչ��\n" NOR + HIC 				"ʥ������  �ջ�����\n" NOR,
	]));

        setup();
        replace_program(ROOM);
}
