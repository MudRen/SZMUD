
// Filename:   /d/jueqinggu/houshan.c
// Program:    Jiuer
// Date:       Aug 15, 2001


inherit ROOM;

void create()
{
		  set("short","后山小径");

		  set("long",@LONG
由此通往后山的小道，阳光照耀在树林，地气和暖，鼻中闻到一阵
阵的花香，又见道旁白兔、小鹿来去奔跃，甚是可爱，说不出的心旷神
怡，。
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

