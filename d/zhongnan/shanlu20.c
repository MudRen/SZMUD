// Code of ShenZhou
// road: /zhongnan/shanlu20.c
// by sdong 08/98

inherit ROOM;

void create()
{
		  set("short","ɽ·");

		  set("long",@LONG
�˶�ɽ·�������ͱڶ���������ģ��ر�������С���������ͨ��������
����ͨ���嶥��
LONG);

		  set("exits",([ "southdown" : __DIR__"shanlu19",
								"northup" : __DIR__"shanlu21",
							 ])
			  );
	  set("cost",10);
	  set("outdoors", "zhongnan");
	  setup();
	  replace_program(ROOM);
}
