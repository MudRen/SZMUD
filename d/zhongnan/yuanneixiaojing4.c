// Code of ShenZhou
// road: /zhongnan/yuanneixiaojing4.c

inherit ROOM;

void create()
{
        set("short","Ժ��С��");

        set("long",@LONG
��ȫ��̵���Ժ�����Ϊ��󣬵���ɢ�ɽ�䣬ɽ�ϱ�ֲ��ɼ���֣�
Ȫˮ���ȣ����������ྲ��С������ͨ�ġ��ߵ���������ֻ��֦ͷ���䣬
����һ�����ʵĸо������ٵ����ɽ�ּ���Ѱ�ܴ�������������������
���ϸ���һ��С����
LONG);

        set("exits",([ "north" : __DIR__"yuanneixiaojing5",
                        "south" : __DIR__"yuanneixiaojing1",
                      ])
           );
	  set("cost",1);
	  set("outdoors", "zhongnan");

        setup();

        replace_program(ROOM);
}
