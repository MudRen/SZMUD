
// Filename:   /d/jueqinggu/houshan.c
// Program:    Jiuer
// Date:       Aug 15, 2001


inherit ROOM;

void create()
{
		  set("short","��ɽС��");

		  set("long",@LONG
�ɴ�ͨ����ɽ��С����������ҫ�����֣�������ů�������ŵ�һ��
��Ļ��㣬�ּ����԰��á�С¹��ȥ��Ծ�����ǿɰ���˵�������Ŀ���
������
LONG);

	  set("exits",([ 
		"southdown" : __DIR__"shiliang",
		"northup" : __DIR__"duanchang",
			 ]));
	  
	  set("objects", ([
            "/d/wudang/npc/yetu" : 1,
			"/d/changbai/npc/deer" : 1,
        ]));

	  set("outdoors","jueqing");
	  set("cost",1);

	  setup();	
}

