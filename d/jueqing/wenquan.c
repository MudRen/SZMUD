// Filename:   /d/jueqinggu/wenquan.c ��Ȫ
// Program:    Jiuer
// Date:       Aug 15, 2001


inherit ROOM;

void create()
{
		  set("short","��Ȫ");

		  set("long",@LONG
����һ�ص�����Ȫ��Ȫˮ���ǿ��˹��Ƶģ����⹾ཹ�ཱུ�ð����
������Ȫ���������ɵ�������һ���������Ѷ��������ӳ�յ�ƮƮ����
�ġ�
LONG);

	  set("exits",([ 
		"northwest" : __DIR__"shuitang",
			 ]));
	  
	  set("outdoors","jueqing");
	  set("cost",1);

	  setup();	
}

