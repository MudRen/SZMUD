// Code of ShenZhou
// chchong 2002/02/01
// /d/kaifeng/hhbian.c
inherit FERRY;

void create()
{
    int i;
        set("short", "黄河岸边");
        set("long", @LONG
这里是黄河岸边。黄河流淌到这里，已经沉积不少的泥沙。黄色
的河水在河床里翻滚着，咆哮着，卷起一个个巨大的漩窝。向北就是
有名的渡口，在滚滚的大江(river)边。
LONG
        );

        set("exits", ([
                "south" :"/d/huanghe/bank3",
        ]));
        set("item_desc", ([
        "river" : "近岸处有一叶小舟，也许喊(yell)一声船家就能听见。\n",
        ]));
        set("resource/water", 1);
        set("outdoors","kaifeng");
        set("cost", 1);
        set("name", "江");
        set("boat", __DIR__"duchuan");
         set("opposite", __DIR__"tiandi2");
        setup();
}

