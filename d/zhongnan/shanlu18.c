// Code of ShenZhou
// road: /zhongnan/shanlu18.c
// by sdong 08/98

inherit ROOM;

void create()
{
		  set("short","�綴��");

		  set("long",@LONG
����ǰ����һ���󶴣������󻨸��Ҽ��Ŷ��ɡ��������ϰϰ�������쬣�
�ʳƷ綴���˶�ɽ·�������ͱڶ���������ģ��ر�������С���������ͨ��
����������ͨ���嶥��
LONG);

		  set("exits",([ "eastdown" : __DIR__"shanlu17",
								"northup" : __DIR__"shanlu19",
								"enter": __DIR__"fengdong",
							 ])
			  );
	  set("cost",4);
	  set("outdoors", "zhongnan");
	  setup();
	  replace_program(ROOM);
}
