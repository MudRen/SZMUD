// Code of ShenZhou
// Room: /city/duchang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�ĳ�");
	set("long", @LONG
�����Ǿɶĳ��Ĵ��ã����ܵķ����ﴫ����ߺ������������������Ƕġ���
�š��ķ��䡣��֪Ϊ�Σ����ߵ�����ȴ���ŵö࣬ʮ�ְ�����һ������ͨ������
���Ǿ������ݵ�������Է��
LONG
	);

//	set("item_desc", ([
//		"paizi" : "��¥�Ĺ��������ڲ��Խ׶Ρ�\n",
//	]));
	set("exits", ([
//                "west" : __DIR__"qiyuan1",
		"up" : __DIR__"duchang2",
                "northwest" : __DIR__"sp9room",
                "north" :"/clone/misc/naihe/dc_door",
	]));

        set("objects", ([
                  "/kungfu/class/shenlong/shou" : 1, 
        ]));

	set("cost", 0);
	setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "northwest" && this_player()->query("age")<18)
                return notify_fail("Сë���������Ϲ�պ�ʲô?!\n");

//	if (dir == "west")
//		return notify_fail("�ĳ���ʱ�ر�!\n");
        return ::valid_leave(me, dir);
}

