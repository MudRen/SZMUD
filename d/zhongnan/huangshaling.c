// Code of ShenZhou
// road: /zhongnan/huangshaling.c

inherit ROOM;

void create()
{
        set("short","��ɳ��");

        set("long",@LONG
�˴�λ�����ɽ������ֻ��Զ������ԭ�ϣ�������һ���ɻ�ɳ�ѻ����ɵ�
ɽ�룬����Ϊ���ء��ݵ�����˵���������̳���һλ����½���ɵ��ˣ��÷���
ǲ��һ�ɻ�ɳ���ɡ�������һƬ���֡�
LONG);

        set("exits",([ "east" : __DIR__"milin8",
                      ])
           );
	  set("cost",2);
	  set("outdoors", "zhongnan");
        setup();

        replace_program(ROOM);
}

