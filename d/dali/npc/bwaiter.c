// Code of ShenZhou
inherit NPC;
void create()
{
        set_name("龙光阁伙计", ({ "huoji" }));
        set("str", 20);
        set("gender", "男性");
        set("age", 18);
        set("long", "他是附近乡下找来帮忙的。\n");
        set("combat_exp", 250);
        set("attitude", "friendly");
        setup();
}

