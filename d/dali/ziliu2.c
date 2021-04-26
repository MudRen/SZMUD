// Code of ShenZhou
// Room: /d/dali/ziliu2.c

inherit ROOM;

void create()
{
        set("short", "大厅");
        set("long", @LONG
进入大厅，抬头迎面先看见一个大匾，上面写著「邦国柱石」,
从笔迹看,似乎出自大理国君段智兴手笔。大匾下是四张紫檀交
椅,两边又并排放着八张香木椅。陈设则并不豪华,可见主人甚为
清正。
LONG
        );
        set("cost", 1);
        set("wangfu", 1);

        set("exits", ([ /* sizeof() == 1 */
                "east" : __DIR__"ziliu1.c",
                ]));
        set("objects", ([
                "/kungfu/class/dali/zhu.c" : 1,
                ]));
     

        set("no_clean_up", 0);

        setup();
}
