// Code of ShenZhou
// road: /zhongnan/shanlu22.c
// by sdong 08/98

inherit ROOM;

void create()
{
		  set("short","ɽ·");

		  set("long",@LONG
�˶�ɽ·�������ͱڶ���������ģ��ر�������С���������ͨ��
ɽ�ţ�����ͨ���嶥��
LONG);

		  set("exits",([ "westdown" : __DIR__"shanlu23",
								"eastup" : __DIR__"shanlu21",
						  ])
			  );
	  set("cost",4);
	  set("outdoors", "zhongnan");
	  setup();
	  replace_program(ROOM);
}

