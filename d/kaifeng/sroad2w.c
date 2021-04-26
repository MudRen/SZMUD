//Room: /d/kaifeng/sroad2w.c
//by bravo
inherit ROOM;
void create()
{
        set("short", "南大街");
        set("long", @LONG
你走在南大街坚实的青石板地面上，各色人等往来其中，很是喧
闹。有时你可能会见到一些江湖装束的人物，他们口音各异，服饰也
五花八门，可是中气都很足，可不是好惹的。往东长长的大道就是南
大街。西南方是个很巍峨的建筑群，人进人出，十分热闹。西北通往
西大街。
LONG
        );

        set("exits", ([
                
                "northwest":__DIR__"wroad2s",
                "east":__DIR__"sroad2",
                
              ]));
       set("outdoors", "kaifeng");
               

        setup();
        replace_program(ROOM);
}
