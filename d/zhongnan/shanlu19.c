// Code of ShenZhou
// road: /zhongnan/shanlu19.c
// by sdong 08/98

inherit ROOM;

void create()
{
		  set("short","ɽ·");

		  set("long",@LONG
�˶�ɽ·�������ͱڶ���������ģ��ر�������С���������ͨ��������
����ͨ���嶥��
LONG);

		  set("exits",([ "southdown" : __DIR__"shanlu18",
								"northup" : __DIR__"shanlu20",
							 ])
			  );
	  set("cost",4);
	  set("outdoors", "zhongnan");
	  setup();
	  replace_program(ROOM);
}

