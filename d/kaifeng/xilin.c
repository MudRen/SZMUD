//Room: /d/kaifeng/xilin.c
//by bravo
inherit ROOM;
void create()
{
        set("short", "西林观");
        set("long", @LONG
西林观是天下第一大道观。观中林木婆娑，冠盖亭亭观中道士匆
匆来去，没人得空理你，更没人接待你。你觉得到一种宽松的失落。
LONG
        );

        set("exits", ([
                
                "northeast":__DIR__"wroad2s",
                
              ]));

        setup();
        replace_program(ROOM);
}
