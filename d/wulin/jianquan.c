// room /d/wulin/jianquan.c
//updated by Lara 2001/10/17
inherit ROOM;
void create()
{
        set("short", "剑气泉");
        set("long", @LONG
此处便是剑气泉了，在岩石上有几股泉水汩汩的流淌出来，相传曾有
两位武林高手在此比武，剑气穿透岩石而形成此泉水。这里的泉水清澈甘
醇，具解渴祛乏之效，武林人士都希望一品此泉之甘甜。
LONG
        );

        set("exits", ([
                "west" : __DIR__"shanlu",
        ]));     

        set("resource/water",1);
        set("no_clean_up", 0);
        set("cost", 1);
        setup();
        replace_program(ROOM);
}
