// Code of ShenZhou
// road: /zhongnan/yuanneixiaojing1.c

inherit ROOM;

void create()
{
        set("short","Ժ��С��");

        set("long",@LONG
��ȫ��̵���Ժ�����Ϊ��󣬵���ɢ�ɽ�䣬ɽ�ϱ�ֲ��ɼ���֣�
Ȫˮ���ȣ����������ྲ��С������ͨ�ġ��ߵ���������ֻ��֦ͷ���䣬
����һ�����ʵĸо������ٵ����ɽ�ּ���Ѱ�ܴ�������������������
������������������������һ��С����
LONG);

        set("exits",([ "southwest" : __DIR__"dadian",
                        "east" : __DIR__"yuanneixiaojing2",
                        "north" : __DIR__"yuanneixiaojing4",
				])
           );
	  set("cost",2);
	  set("outdoors", "zhongnan");

        setup();

        replace_program(ROOM);
}
