// Code of ShenZhou
// road: /zhongnan/daolu.c

inherit ROOM;

void create()
{
        set("short","��·");

        set("long",@LONG
�˴�λ�����ɽɽ�š�Ρ�������ɽ���Թ�����������������������
ʥ�ء������������ɽ���������������أ�����Խʮ���أ�����˰�
���������������ɽ֮�ơ������ɿ���һ������������һ��ͨ������
���ľ�С·��������������ɽ.
LONG);

		  set("exits",([ "west" : __DIR__"xiaojing1",
								"northup" : __DIR__"shanlu1",
								"south" : "/d/emei/emroad4",
								"east" : __DIR__"puguansi",
							 ])
			  );
	  set("cost",2);
	  set("outdoors", "zhongnan");


		  setup();


}

