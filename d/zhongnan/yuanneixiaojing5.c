// Code of ShenZhou
// road: /zhongnan/yuanneixiaojing5.c

inherit ROOM;

void create()
{
        set("short","Ժ��С��");

        set("long",@LONG
��ȫ��̵���Ժ�����Ϊ��󣬵���ɢ�ɽ�䣬ɽ�ϱ�ֲ��ɼ���֣�
Ȫˮ���ȣ����������ྲ��С������ͨ�ġ��ߵ���������ֻ��֦ͷ���䣬
����һ�����ʵĸо������ٵ����ɽ�ּ���Ѱ�ܴ�������������������
�����������������ϸ���һ��С����
            
LONG);

        set("exits",([ "west" : __DIR__"yuanneixiaojing6",
                        "south" : __DIR__"yuanneixiaojing4",
                        "north" : __DIR__"yinwutin",
				])
           );
	  set("cost",1);
	  set("outdoors", "zhongnan");

        setup();

        replace_program(ROOM);
}
