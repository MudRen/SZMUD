
// Filename:   /d/jueqinggu/yutree.c
// Program:    Jiuer
// Date:       Aug 15, 2001


inherit ROOM;

void create()
{
		  set("short","������");

		  set("long",@LONG
�����ռ�����㣬ȺɽΧ��֮�У���Բ������Ķ����·���ۣ�����
���裬ֻ��ǰ�߰��ɴ�������������า����������һ����ש�ߵĴ�
Ҥ��
LONG);

	  set("exits",([ 
		"down" : __DIR__"huowanshi",
			 ]));
	  
	  set("objects",([
		  "/d/xingxiu/npc/spider3" : 1,
		   ]));
	  
	  set("outdoors","jueqing");
	  set("cost",1);

	  setup();	
}

