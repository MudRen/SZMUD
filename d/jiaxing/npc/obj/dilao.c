// Code of ShenZhou
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�������һ�ţ�Ψһ��һ�߹����Ǵ�����һ����������Ŀ׶���
������ġ��ı������͵ط������⣬ԭ������ǽ�ھ��Ǹ���������
LONG
        );

        set_light(0);
        set("sleep_room", "1");
        set("no_fight", "1");

        set("exits", ([
		"out" : __DIR__"workroom",
	]));
        set("item_desc", ([
                "dianzi" : "һ֧����Ĳݵ��ӣ�������ȥ�����������ǿ����壬\n",
        ]));

	set("objects", ([
		__DIR__"obj/tiechuang" : 1,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
    if ( (dir=="out") && present("liaokao",me))
		return notify_fail("�㱻����������Ŷ������á�\n");
        return ::valid_leave(me, dir);
}

