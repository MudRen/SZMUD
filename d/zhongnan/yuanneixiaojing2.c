// Code of ShenZhou
// road: /zhongnan/yuanneixiaojing2.c

inherit ROOM;

void create()
{
        set("short","Ժ��С��");

        set("long",@LONG
��ȫ��̵���Ժ�����Ϊ��󣬵���ɢ�ɽ�䣬ɽ�ϱ�ֲ��ɼ���֣�
Ȫˮ���ȣ����������ྲ��С������ͨ�ġ��ߵ���������ֻ��֦ͷ���䣬
����һ�����ʵĸо������ٵ����ɽ�ּ���Ѱ�ܴ�������������������
��������һ��С����
LONG);

        set("exits",([ "west" : __DIR__"yuanneixiaojing1",
                        "north" : __DIR__"yuanneixiaojing3",
                      ])
           );
	  set("cost",1);
	  set("outdoors", "zhongnan");

        setup();

        replace_program(ROOM);
}
