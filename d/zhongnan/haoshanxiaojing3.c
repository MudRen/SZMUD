// Code of ShenZhou

// road: /zhongnan/haoshanxiaojing3.c

inherit ROOM;

void create()
{
        set("short","��ɽС��");

        set("long",@LONG
����ɽС·���������ɽ���У�Ҳ��֪ͨ���δ���ֻ��Ũ����죬Խ
��Խ����ɭ��Խ��Խ�ǻ�������ʱ����Ұ�޺����������������з�ë����
�����Ͷ��ϸ���һ����ɭɭ��С����
LONG);

	  set("exits",([ "northeast" : __DIR__"haoshanxiaojing2",
								"southeast" : __DIR__"haoshanxiaojing4",
							 ])
			  );
	  set("outdoors", "zhongnan");

	  setup();
}

