// Code of ShenZhou
// Room: /d/dali/garden9.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", RED"�軨Ժ"NOR);
	set("long", @LONG
�������ر��ǲ軨��������ɫ��Ѥ�����ˡ�������ʱʱ��
�۷������䡣��ʯ·��ȴ����һ����Ʒ���ֲ軨(flower)��
LONG
	);

	set("item_desc", ([
		"flower" : RED"ץ��������
�װ������ߵģ���������ױ�ع������ٰ����һĨ���Σ�һ
˿�����Ľ�����ץ����������������˿���ˣ����ǡ���魽����ˡ�
"NOR,
]));
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([
		"south" : __DIR__"garden8",
		]));

	set("valid_startroom", 1);

    setup();
}

