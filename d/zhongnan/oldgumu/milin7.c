// Code of ShenZhou
// road: /zhongnan/milin7.c

inherit ROOM;

void create()
{
        set("short","����");

        set("long",@LONG
�������У���ֻ����������һ�ɵ������̣����ż���Ļ��㣬����
���������һȺ���ɫ���۷��������Է�����ȥ���������Ĩ��߾���ï
�ܵ����֡�
LONG);


        set("exits",([ "south" : __DIR__"milin8",
                        "east" : __DIR__"milin5",

                      ])
           );
	  set("cost",2);
	  set("outdoors", "zhongnan");
        setup();
        replace_program(ROOM);
}
