//Creatived by Snso Zyu Tianhen
// /d/wuguan/xiulian.c
//进修室

inherit ROOM;

void create()
{
                  set("short", "进修室");
                  set("long", @LONG
这里是泉州武馆的进修室。房内并无特别摆设，地上放着几个蒲团，
屋里非常安静，这里真是个修身养性的好地方,练武之人都各自钻研着自
己的武学，互不打扰。西南面有一条小路可以通往外面。
LONG
                  );
                  set("valid_startroom", 1);

                  set("exits", ([
                      "southwest" : __DIR__"zoulang3",
                  ]));

	set("objects", ([
//            __DIR__"npc/dizi3" : 1,
	    ]));

                set("cost",1);

                set("no_steal",1);

                setup();
}
