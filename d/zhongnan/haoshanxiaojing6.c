// Code of ShenZhou
// road: /zhongnan/haoshanxiaojing6.c

inherit ROOM;

void create()
{
        set("short","��ɽС��");

        set("long",@LONG
����ɽС·���������ɽ���У�Ҳ��֪ͨ���δ���ֻ��Ũ����죬Խ
��Խ����ɭ��Խ��Խ�ǻ�������ʱ����Ұ�޺����������������з�ë����
������һ����ɭɭ��С����������һ��С�¡�
LONG);

        set("exits",([ "northwest" : __DIR__"haoshanxiaojing5",
                        "south" : __DIR__"xiaosi",
                      ])
           );
	  set("cost",2);
	  set("outdoors", "zhongnan");

        setup();

        replace_program(ROOM);
}

