//shendan.c

#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("巫师神丹", ({"shen dan", "shen", "dan"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "这是分冥子的宝物之一, 用於测试大米。(武当用途)\n");
                set("value", 1000000000);
        }

        setup();
}

int do_eat(string arg)
{
        mapping skill_status;
        string *sname;
        int i, point, count, new_shen, new_exp, new_pot;
        object me = this_player();
        object ob = this_object();

        if (!id(arg))
        return notify_fail("你要吃什么？\n");

        write("神呀, 赐给我神奇的力量!\n");

                me->add("max_neili", 1000);
                me->add("eff_jingli", 1000);
                me->add("max_jingli", 1000);

                me->set_skill("literate", 150);
                me->set_skill("force", 150);
                me->set_skill("taiji-shengong", 150);
                me->set_skill("strike", 150);
                me->set_skill("cuff", 150);
                me->set_skill("dodge", 150);
                me->set_skill("parry", 150);
                me->set_skill("mian-zhang", 150);
                me->set_skill("taiji-jian", 150);
                me->set_skill("taiji-quan", 150);
                me->set_skill("tiyunzong", 150);
                me->set_skill("sword", 150);
                me->set_skill("taoism", 150);

                me->add("shen", 100000);

        destruct(ob);
        return 1;
}

