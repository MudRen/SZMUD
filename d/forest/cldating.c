// Code of ShenZhou
// /d/huanghe/changle/dating.c
// by aln  2 / 98

#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short", "大厅");
        set("long",
"大厅中一股肃杀威严之气。厅堂极为宽大，能容下数十人之众。\n"
"只见四周桌上点着明晃晃的巨烛，正中空着一张虎皮交椅。不时有帮\n"
"众经过这里，都是屏息静气地低头走过。贝海石背后立着一个牌子，\n"
"上面潦草地写着："HIW"贝总管日理万机，难免有所疏忽。若有差错无需向\n"NOR 
HIW"神仙禀报，稍等片刻便可得到下一次工作。"NOR"看来神仙也拿他没办法，\n"
"有什么事儿，自认倒霉吧。:(\n\n");

        set("exits", ([
		"out" : __DIR__"cldamen",
		"north" : __DIR__"clzoulang1",
        ]));
        set("no_fight","在长乐帮的地盘上还是别太放肆的好。\n");

        set("cost", 1);

        set("objects",([
                __DIR__"npc/cl_bei" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
