// Code of ShenZhou

// road: /zhongnan/yuanneixiaojing6.c

inherit ROOM;

void create()
{
        set("short","Ժ��С��");

        set("long",@LONG
��ȫ��̵���Ժ�����Ϊ��󣬵���ɢ�ɽ�䣬ɽ�ϱ�ֲ��ɼ���֣�
Ȫˮ���ȣ����������ྲ��С������ͨ�ġ��ߵ���������ֻ��֦ͷ���䣬
����һ�����ʵĸо������ٵ����ɽ�ּ���Ѱ�ܴ����������������Ϻ�
��������һ��С����
LONG);

        set("exits",([ "south" : __DIR__"yuanneixiaojing7",
                        "east" : __DIR__"yuanneixiaojing5",
                      ])
           );
	  set("cost",1);
	  set("outdoors", "zhongnan");

        setup();

        replace_program(ROOM);
}

