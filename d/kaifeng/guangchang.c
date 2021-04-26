//Room: /d/kaifeng/guangchang.c
//by bravo
inherit ROOM;
void create()
{
        set("short", "青天广场");
        set("long", @LONG
这里是开封府前广场。好空旷的地方，只有稀稀落落几个没精打
采的行人。北面就是开封府了，南边是开封街。广场周围种了一圈遮
阳树，但骄阳仍把青天广场地面晒得滚烫冒烟。
LONG
        );

        set("exits", ([
                "west" : __DIR__"wroad1",
                "east":__DIR__"eroad1",
                "south":__DIR__"sroad1",
                "north":__DIR__"fumen",
        ]));

       set("objects",([__DIR__"npc/wujiang":1,]));
       set("outdoors", "kaifeng");
       setup(); 
       replace_program(ROOM); 
       }
