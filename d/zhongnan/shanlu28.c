// Code of ShenZhou
// road: /zhongnan/shanlu28.c
// by sdong 08/98

inherit ROOM;

void create()
{
		  set("short","С·");

		  set("long",@LONG
�˶�С·���߶����Ӳݣ������ߵ��˲��࣬���ܵľ�ɫ��Խ��Խ�����������Ѿ�
�쵽ɳĮ�ˡ�����ͨ������ɽ��������ͨ����������
LONG);

		  set("exits",([ "northwest" : __DIR__"shanlu29",
								"south" : __DIR__"shanlu27",
						  ])
			  );
	  set("cost",4);
	  set("outdoors", "zhongnan");
	  setup();
	  replace_program(ROOM);
}

