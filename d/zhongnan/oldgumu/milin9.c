// Code of ShenZhou
// road: /zhongnan/milin9.c

inherit ROOM;

void create()
{
        set("short","����");

        set("long",@LONG
�������У���ֻ����������һ�ɵ������̣����ż���Ļ��㣬����
���������һȺ���ɫ���۷��������Է�����ȥ���������Ĩ��߾���ï
�ܵ����֡�
LONG);

        set("item_desc",(["shibei" : "

			���Ϲ�Ĺ��
			����ֹ����

\n",]));


        set("exits",([ "north" : __DIR__"milin8",
                        "east" : __DIR__"milin6",

                      ])
           );
	  set("cost",2);
	  set("outdoors", "zhongnan");
        setup();
        replace_program(ROOM);
}

