// Code of ShenZhou
// Room: huanglu1.c

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
		"southwest" : __DIR__"dongcheng",
                "northeast" : __DIR__"huanglu2",
	]));

        set("objects",([
         //       __DIR__"npc/juren1" : 1,
         //       __DIR__"npc/juren4" : 1,
        ]));

        set("outdoors", "changbai");
        set("cost", 2);

	setup();
	replace_program(ROOM);
}

