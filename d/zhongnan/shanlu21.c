// Code of ShenZhou
// road: /zhongnan/shanlu21.c
// by sdong 08/98

inherit ROOM;

void create()
{
		  set("short","������");

		  set("long",@LONG
����ǰ����һ���󶴣����������쬣���ʢ�����м�����������ˡ�
ԭ������Ǳ������˶�ɽ·�������ͱڶ���������ģ��ر�������С���
������ͨ������������Ҳ��һ��С·��
LONG);

		  set("exits",([ "westdown" : __DIR__"shanlu22",
							  "southdown" : __DIR__"shanlu20",
								"enter": __DIR__"bingdong",
							 ])
			  );
	  set("cost",4);
	  set("outdoors", "zhongnan");
	  setup();
	  replace_program(ROOM);
}
