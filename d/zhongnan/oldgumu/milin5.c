// Code of ShenZhou
// road: /zhongnan/milin5.c

inherit ROOM;

void create()
{
        set("short","����");

		  set("long",@LONG
�������У���ֻ����������һ�ɵ������̣����ż���Ļ��㣬����
���������һȺ���ɫ���۷��������Է�����ȥ��������һ����Ĺ����
��������ï�ܵ����֡�
LONG);


        set("exits",([ "south" : __DIR__"gumu",
                        "east" : __DIR__"milin1",
				"west" : __DIR__"milin7",
                      ])
           );
	  set("cost",2);
	  set("outdoors", "zhongnan");
        setup();
        replace_program(ROOM);
}
