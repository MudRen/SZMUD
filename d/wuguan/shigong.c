//Creatived by Snso
// /d/wuguan/shigong.c
//试功室

inherit ROOM;

void create()
{
                  set("short", "试功室");
                  set("long", @LONG
这里是泉州武馆的试功室，房间里有几排木人和几个放兵器的架子，玩家
可以在这里互相切磋武艺，讨论心得体会以便加快练功的速度。
LONG
                  );
                  set("valid_startroom", 1);

                  set("exits", ([
                  "northwest" : __DIR__"zoulang4",
                  ]));

                set("cost",1);


                setup();
}
