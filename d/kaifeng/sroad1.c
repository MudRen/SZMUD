//Room: /d/kaifeng/sroad1.c
//by bravo
inherit ROOM;
void create()
{
        set("short", "开封街");
        set("long", @LONG
开封街就是因为通往开封府而得名。这一带来往行人很少，做生
意的就更是绝迹了。包大人好象有甚麽想不开的，派了好多兵在这
里守卫，连江湖人物都不敢轻率踏入。
LONG
        );

        set("exits", ([
                
                "south":__DIR__"sroad2",
                "north":__DIR__"guangchang",
        ]));

           set("outdoors", "kaifeng");
         set("objects",([
           __DIR__"/npc/bing":2,
         ]));
        setup();
        replace_program(ROOM);
}
