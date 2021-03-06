// room /d/wulin/longyin.c
//updated by Lara 2001/10/17
inherit ROOM;
void create()
{
        set("short", "龙吟坡");
        set("long", @LONG
走完了又高又陡的石阶，终于爬上了龙吟坡，你已经微露疲态。从这
里往上的山路崎岖蜿蜒，极其难走，其势犹如一条巨龙盘踞而上。山风吹
过，回声共鸣高亢入云，令人豪气顿生。龙吟坡刚健爽朗的风格与虎啸坪
威严肃穆的气势相映成趣，一如武林绝顶高手的决斗，一如战场上千军万
马的厮杀。
LONG
        );

        set("exits", ([
                "southdown" : __DIR__"huxiao",
                "northup" : __DIR__"shanlu",
        ]));

        set("objects",([
                __DIR__"npc/yishi" : 1,
        ]));

        set("no_clean_up", 0);       
        set("cost", 1);
        setup();
}
