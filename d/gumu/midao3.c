// July 31,2000
// Code by April
// /gumu/midao3.c

inherit ROOM;

void create()
{
	set("short", "密道");

    set("long",@LONG
下降了约莫半个时辰，这路渐平，只是湿气却也渐重，脚下已有流水
，水没至踝，自腿而腹，渐与胸齐。你只觉得一股暗流把你往水里拉，再
往东走可能就要淹死了。
LONG);

          set("exits",([ "westup" : __DIR__"midao2",
                        "eastdown" : __DIR__"water1",
                         ])
                          );
          set("cost",5);

          setup();
}
