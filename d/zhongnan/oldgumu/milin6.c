// Code of ShenZhou
// road: /zhongnan/milin6.c

inherit ROOM;

void create()
{
        set("short","����");

        set("long",@LONG
�������У���ֻ����������һ�ɵ������̣����ż���Ļ��㣬����
���������һȺ���ɫ���۷��������Է�����ȥ��������һ����Ĺ����
��������ï�ܵ����֡�
LONG);

        set("exits",([ "west" : __DIR__"milin9",
                        "east" : __DIR__"milin4",
				"north" : __DIR__"gumu",
                      ])
           );
	  set("cost",2);
	  set("outdoors", "zhongnan");
        setup();
        replace_program(ROOM);
}
