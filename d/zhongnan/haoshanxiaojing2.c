// Code of ShenZhou
// road: /zhongnan/haoshanxiaojing2.c

inherit ROOM;

void create()
{
        set("short","��ɽС��");

        set("long",@LONG
����ɽС·���������ɽ���У�Ҳ��֪ͨ���δ���ֻ��Ũ����죬Խ
��Խ����ɭ��Խ��Խ�ǻ�������ʱ����Ұ�޺����������������з�ë����
���ƺ�����ɽ�������������ϸ���һ����ɭɭ��С����
LONG);

		  set("exits",([ "northup" : __DIR__"haoshanxiaojing1",
								"southwest" : __DIR__"haoshanxiaojing3",
				"west" : __DIR__"yushuidong",
							 ])
			  );
	  set("cost",2);
	  set("outdoors", "zhongnan");

		  setup();

}

