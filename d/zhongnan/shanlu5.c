// Code of ShenZhou
// road: /zhongnan/shanlu5.c

inherit ROOM;

void create()
{
        set("short","ɽ��");

        set("long",@LONG
�˶�ɽ·�������ͱڶ���������ģ��ر�������С���ʱ�ͱڱ߱���
����ɽ赣�������������䵱ɽ�ﴵ��ʱ�������ر�С�ģ���Ȼһʧ�㣬
��Ҫ����������Ԩ�ˡ�������һ����Ŀյء���������һ����ҡ�
LONG);

        set("exits",([ "southdown" : __DIR__"laoqurock",
                        "northup" : __DIR__"dajiaochang",
                      ])
           );
	  set("cost",4);
	  set("outdoors", "zhongnan");

        setup();

        replace_program(ROOM);
}

