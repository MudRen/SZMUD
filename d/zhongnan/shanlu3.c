// Code of ShenZhou
// road: /zhongnan/shanlu3.c

inherit ROOM;

void create()
{
        set("short","ɽ·");

        set("long",@LONG
����һ���ǳ�������е�ɽ·��һ·������ɽ���ϣ���;���Ǵ�����
�Ű�ɽ�֣�εȻɭ�㡣�ڴ˴�����������ɽ�ľ�ɫ��ֻ��ɽ�������ɽ��
ع�㣬���������֦ͷ�����䳪�������������������¡���������һ��ɽ
·��
LONG);

        set("exits",([ "eastdown" : __DIR__"jinliange",
                        "westup" : __DIR__"sunmoonrock",
                      ])
           );
	  set("cost",2);
	  set("outdoors", "zhongnan");

        setup();

        replace_program(ROOM);
}

