// Code of ShenZhou

// road: /zhongnan/haoshanxiaojing1.c

inherit ROOM;

void create()
{
        set("short","��ɽС��");

        set("long",@LONG
	����ɽС·���������ɽ���У�Ҳ��֪ͨ���δ���ֻ��Ũ����죬Խ
��Խ����ɭ��Խ��Խ�ǻ�������ʱ����Ұ�޺����������������з�ë������
�Ǹ�С�š�������һ����ɭɭ��С����
LONG);

		  set("exits",([ "east" : __DIR__"houyuan",
								"southdown" : __DIR__"haoshanxiaojing2",
							 ])
			  );
	  set("cost",2);
	  set("outdoors", "zhongnan");

		  setup();


}

