// Code of ShenZhou
// road: /zhongnan/milin3.c

inherit ROOM;

void create()
{
        set("short","����");

        set("long",@LONG
�������У���ֻ����������һ�ɵ������̣����ż���Ļ��㣬����
���������һȺ���ɫ���۷��������Է�����ȥ��������һ����Ĺ����
��������ï�ܵ����֡�
LONG);


        set("exits",([ "north" : __DIR__"milin1",
                        "east" : __DIR__"milin2",
				"south" : __DIR__"milin4",
				"west" : __DIR__"gumu",
                      ])
           );
	  set("cost",2);
	  set("outdoors", "zhongnan");
        setup();
        replace_program(ROOM);
}
