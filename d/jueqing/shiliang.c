
// Filename:   /d/jueqinggu/shiliang.c
// Program:    Jiuer
// Date:       Aug 15, 2001


inherit ROOM;

void create()
{
		  set("short","ʯ��");

		  set("long",@LONG
�����ľ����ϡ�٣�����͸���⻬�����ͻ����ʯ�壬����������
С������ǰ����һ��ͻ�ذ���ľ��ڡ�
LONG);

	  set("exits",([ 
		"eastdown" : __DIR__"qinghuaao5",
		"northup" : __DIR__"houshan",
		"west" : __DIR__"huowanshi",
			 ]));
	  
	  set("outdoors","jueqing");
	  set("cost",1);

	  setup();	
}

