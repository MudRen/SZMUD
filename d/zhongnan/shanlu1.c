// Code of ShenZhou
// road: /zhongnan/shanlu1.c

inherit ROOM;

void create()
{
        set("short", "ɽ·");

        set("long",@LONG
����һ���ǳ�������е�ɽ·��һ·������ɽ���ϣ���;���Ǵ�����
�Ű�ɽ�֣�εȻɭ�㡣�ڴ˴�����������ɽ�ľ�ɫ��ֻ��ɽ�������ɽ��
ع�㣬��������һ����·������������һ�����ѵ�ɽ·����������һ����
·��
LONG);

        set("exits",([ "southdown" : __DIR__"daolu",
                        "northup" : __DIR__"shanlu2",
                      ])
           );
	  set("cost",3);
        set("fjing", 1);
	  set("outdoors", "zhongnan");

        setup();

        replace_program(ROOM);
}
