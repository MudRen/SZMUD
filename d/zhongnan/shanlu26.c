// Code of ShenZhou
// road: /zhongnan/shanlu26.c
// by sdong 08/98

inherit ROOM;

void create()
{
		  set("short","ɽ·");

		  set("long",@LONG
�˶�ɽ·���߶����Ӳݣ������ߵ��˲��࣬����ͨ������ɽ������ͨ����������
LONG);

		  set("exits",([ "north" : __DIR__"shanlu27",
								"south" : __DIR__"shanlu25",
						  ])
			  );
	  set("cost",4);
	  set("outdoors", "zhongnan");
	  setup();
	  replace_program(ROOM);
}

