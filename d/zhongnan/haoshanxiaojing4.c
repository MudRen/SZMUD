// Code of ShenZhou
// road: /zhongnan/haoshanxiaojing4.c

inherit ROOM;

void create()
{
        set("short","��ɽС��");

        set("long",@LONG
����ɽС·���������ɽ���У�Ҳ��֪ͨ���δ���ֻ��Ũ����죬Խ
��Խ����ɭ��Խ��Խ�ǻ�������ʱ����Ұ�޺����������������з�ë����
�����Ͷ��ϸ���һ����ɭɭ��С����
LONG);

		  set("exits",([ "northwest" : __DIR__"haoshanxiaojing3",
								"southeast" : __DIR__"haoshanxiaojing5",
							 ])
			  );
	  set("cost",2);
	  set("outdoors", "zhongnan");

		setup();

}
