// Code of ShenZhou
// road: /zhongnan/shanlu2.c

inherit ROOM;

void create()
{
        set("short","ɽ·");

        set("long",@LONG
����һ���ǳ�������е�ɽ·��һ·������ɽ���ϣ���;���Ǵ�����
�Ű�ɽ�֣�εȻɭ�㡣�ڴ˴�����������ɽ�ľ�ɫ��ֻ��ɽ�������ɽ��
ع�㣬��������һ����·�����������ǽ���������������᫵�ɽ·��
LONG);

        set("exits",([ "southdown" : __DIR__"shanlu1",
                        "northup" : __DIR__"jinliange",
                      ])
           );
	  set("cost",3);
	  set("outdoors", "zhongnan");

        setup();

        replace_program(ROOM);
}
