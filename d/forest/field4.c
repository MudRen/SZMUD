// Code of ShenZhou
// Jay 9/04/96

inherit ROOM;

void create()
{
    int i;
        set("short", "���");
        set("long", @LONG
������һƬũ���Զ����һЩ��ׯ�������������𡣴�ׯ��Χ
��һ������أ�������һЩ���ڸ�����ũ�ˡ����ﲻʱ����һ����
��Ȯ�͡�
LONG
        );

        set("exits", ([
		"north" : "/d/huanghe/bank1",
//		"east" : "/d/village/wexit",
		"southwest" : __DIR__"field3",
        ]));

        set("objects", ([ "/d/village/npc/dog": 1 ]) );

	set("outdoors", "forest");
	set("cost", 2);
        setup();
	replace_program(ROOM);
}

