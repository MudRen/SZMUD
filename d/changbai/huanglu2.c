// Code of ShenZhou
// Room: huanglu2.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
���ǳǶ���һ����·��·�����ҵĳ�����ϥ�ĻĲݣ�Զ������һ�ˡ���
�Ըɿݵ������������˳�Ⱥ����ѻ���������������ڻ�Ұ��ԶԶ��ȥ��һ��
�����ľ���
LONG
	);

	set("exits", ([
		"southwest" : __DIR__"huanglu1",
                "enter" : __DIR__"ssmiao",
	]));

        set("objects",([
          //      __DIR__"npc/teng" : 1,
        ]));

        set("outdoors", "changbai");
        set("cost", 2);

	setup();
	replace_program(ROOM);
}
