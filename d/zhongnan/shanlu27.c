// Code of ShenZhou
// road: /zhongnan/shanlu27.c
// by sdong 08/98

inherit ROOM;

void create()
{
		  set("short","ɽ·");

		  set("long",@LONG
�˶�ɽ·���߶����Ӳݣ������ߵ��˲��࣬����ͨ������ɽ������ͨ����������
LONG);

		  set("exits",([ "north" : __DIR__"shanlu28",
								"south" : __DIR__"shanlu26",
						  ])
			  );
	  set("cost",4);
    set("tjjob", 5);
	  set("outdoors", "zhongnan");
	  setup();
	  replace_program(ROOM);
}

