// Code of ShenZhou
// road: /zhongnan/shanlu23.c
// by sdong 08/98

inherit ROOM;

void create()
{
		  set("short","ɽ·");

		  set("long",@LONG
�˶�ɽ·�������ͱڶ���������ģ��ر�������С���������ͨ��
ɽ�ţ�����ͨ���嶥��
LONG);

		  set("exits",([ "westdown" : __DIR__"shanlu24",
								"eastup" : __DIR__"shanlu22",
						  ])
			  );
	  set("cost",4);
	  set("outdoors", "zhongnan");
	  setup();
	  replace_program(ROOM);
}

