// Code of ShenZhou
// road: /zhongnan/yuanneixiaojing3.c

inherit ROOM;

void create()
{
        set("short","Ժ��С��");

        set("long",@LONG
	��ȫ��̵���Ժ�����Ϊ��󣬵���ɢ�ɽ�䣬ɽ�ϱ�ֲ��ɼ���֣�
Ȫˮ���ȣ����������ྲ��С������ͨ�ġ��ߵ���������ֻ��֦ͷ���䣬��
��һ�����ʵĸо������ٵ����ɽ�ּ���Ѱ�ܴ�������������������һ����
��ߵ�¥��������һ��С����
            
LONG);

        set("exits",([ "north" : __DIR__"jingge",
                        "south" : __DIR__"yuanneixiaojing2",
                      ])
           );
	  set("cost",1);
	  set("outdoors", "zhongnan");

        setup();

        replace_program(ROOM);
}
