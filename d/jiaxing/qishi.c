// Code of ShenZhou
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
ֻ���ô�һ�䷿�У�����һ��ʯ������ֻ����֮�⣬�յ���
��һ�����С����Ű���һ�Ŵ�(bed)��
LONG
        );
        set("exits", ([
		"west" : __DIR__"mzqianting",
	]));

	set("objects", ([
		__DIR__"npc/heibai" : 1,
	]));
        set("item_desc", ([ 
                "bed" : "����ͨͨ��һ�Ŵ���\n",
        ]));

        set("no_clean_up", 0);

	set("cost", 0);
	setup();
        replace_program(ROOM);
}
