// Code of ShenZhou
// chchong 2002/02/01
// /d/kaifeng/tiandi1.c
inherit FERRY;

void create()
{
    int i;
        set("short", "田地");
        set("long", @LONG
这里林木渐渐稀疏，不远处有些村庄，炊烟袅袅升起。村庄周围
是一块块的田地，向南就是一条波涛翻滚的大江(river)，浊流滚滚。
过两岸渡船来来往往，江边一长溜摆满了鱼摊，渔家就将船泊在岸边，
几个破萝支一块木板，板上摆满了活蹦乱跳的汉江鲤鱼。
LONG
        );

        set("exits", ([
                "north" : __DIR__"tiandi1",
        ]));
        set("item_desc", ([
        "river" : "近岸处有一叶小舟，也许喊(yell)一声船家就能听见。\n",
        ]));
        set("resource/water", 1);
        set("outdoors","kaifeng");
        set("cost", 1);
        set("name", "江");
        set("boat", __DIR__"duchuan");
         set("opposite", __DIR__"hhbian");
        setup();
}

