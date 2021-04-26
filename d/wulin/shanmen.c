// room /d/wulin/shanmen.c
//updated by Lara 2001/10/17
inherit ROOM;
void create()
{
        set("short", "山门");
        set("long", @LONG
“山重水复疑无路，柳暗花明又一村”，通过山洞，你来到了一个不
大起眼的山门前。抬头仰望，可以看到山门上写着“武林同盟”几个酣畅
淋漓的大字。这里往上走一小段路就是虎啸坪了。

LONG
        );

        set("exits", ([
         "out" : "/d/taishan/fengchan",
         "northup" : __DIR__"huxiao",
        ]));

        set("no_clean_up", 0);
        set("objects",([
                __DIR__"npc/yishi" : 2,
        ]));
        set("invalid_startroom", 1);       
        set("cost", 1);
        setup();
}


