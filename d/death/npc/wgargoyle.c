 // Code of ShenZhou
// gargoyle.c

#include <ansi.h>
#include <command.h>
#include <login.h>

inherit NPC;

string *death_msg = ({
        HIW "白无常说道：喂！新来的，你叫什么名字？\n\n" NOR,
        HIW "白无常用奇异的眼光盯着你，好像要看穿你的一切似的。\n\n" NOR,
        HIW "白无常「哼」的一声，从袖中掏出一本像帐册的东西翻看着。\n\n" NOR,
        HIW "白无常合上册子，说道：咦？阳寿未尽？怎么可能？\n\n" NOR,
        HIW "白无常搔了搔头，叹道：罢了罢了，你走吧。\n\n"
                "一股阴冷的浓雾突然出现，很快地包围了你。\n\n" NOR,
});

void create()
{
        set_name("白无常", ({ "white gargoyle", "gargoyle" }) );
        set("long",
                "白无常伸着长长的舌头瞪着你，死白的脸上看不出任何喜怒哀乐。\n");
        set("attitude", "peaceful");
        set("chat_chance", 15);
        set("chat_msg", ({
//              (: this_object(), "random_move" :),
                "白无常发出一阵像呻吟的声音，当他发现你正注视着他的时候，瞪了你一眼。\n",
                "白无常把长长的舌头伸出来，缓缓地舔了舔自己又白又长的手指。\n"
        }) );
        set("age", 217);
        set("combat_exp", 20000);
        set("max_jing", 900);
        set("max_jingli", 900);
        set("max_qi", 900);
        set("max_neili", 900);
        set_skill("dodge", 40);
        set_skill("unarmed", 40);
        setup();
}

void init()
{
        ::init();
        if( !previous_object()
        ||      !userp(previous_object())
        ||      wizardp(previous_object()) ) return;
        call_out( "death_stage", 30, previous_object(), 0 );
}

void death_stage(object ob, int stage)
{
        int i;
        object *inv;
        object cloth;
        if( !ob || !present(ob) ) return;

        tell_object(ob, death_msg[stage]);
        if( ++stage < sizeof(death_msg) ) {
                call_out( "death_stage", 5, ob, stage );
                return;
        } else
                ob->reincarnate();
                                ob->delete("death_update");

        inv =  all_inventory(ob);
        for (i = 0; i < sizeof(inv); i++)
                DROP_CMD->do_drop(ob, inv[i]);
        if(ob->query("xkd/set", 1)) ob->move("/d/xiakedao/shatan");
        else ob->move(REVIVE_ROOM);
        cloth = new ( "/clone/misc/cloth" );
        cloth->move( ob );
        cloth->wear();
        message("vision",
                "你忽然发现前面多了一个人影，不过那人影又好像已经在那里\n"
                "很久了，只是你一直没发觉。\n", environment(ob), ob);
}

