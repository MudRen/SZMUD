// Code of ShenZhou
// road: /zhongnan/shanlu4.c

inherit ROOM;

void create()
{
		  set("short","ɽ·");
		  set("long",@LONG
����һ���ǳ�������е�ɽ·��һ·������ɽ���ϣ���;���Ǵ�����
�Ű�ɽ�֣�εȻɭ�㡣�ڴ˴�����������ɽ�ľ�ɫ��ֻ��ɽ�������ɽ��
ع�㣬���������֦ͷ�����䳪��������������������������ľ�ʯ����
����һƬ������ɽ�֡�
LONG);

        set("exits",([ "southdown" : __DIR__"sunmoonrock",
                        "northup" : __DIR__"shulin1",
                      ])
           );
	  set("cost",3);
	  set("outdoors", "zhongnan");

        setup();

        replace_program(ROOM);
}
