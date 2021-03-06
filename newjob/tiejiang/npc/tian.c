//Cracked by Cheap
// tian chunlan 
// 11-08-01
#include <ansi.h>
inherit NPC;
//inherit F_VENDOR;
inherit F_DEALER;

void create()
{
        set_name("田春兰", ({ "tian chunlan", "tian", "chunlan" }));
        set_color("$HIW$");
        set("title", "老板娘");
        set("shen_type", 0);

        set("gender", "女性");
        set_max_encumbrance(100000000);
        set("age", 38);
        set("long",
                "她是一个年过三十的中年妇女。\n"
                "她在这一带也蛮有名气，因为她时常帮助一些穷人。\n"
                "因此人人都称呼她活观音。\n");
        set("no_get_from", 1);
        set("max_jing", 5000);
        set("jing", 5000);
        set("max_jingli", 500);
        set("jingli", 500);
        set("max_qi", 500);
        set("qi", 500);
        set("PKS", 1000000);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_temp("apply/attack", 120);
        set_temp("apply/attack", 120);
        set_temp("apply/damage", 50);

        set("combat_exp", 60000);
        set("attitude", "friendly");
        set("vendor_goods", ({
              "/newjob/tiejiang/obj/gao.c",
              "/newjob/tiejiang/obj/gangqian.c",
              "/newjob/tiejiang/obj/datiechui.c",
        }));
        setup();
 
 }

void init()
{
        ::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

void unconcious()
{
        message_vision("\n突然，只见$N闪身拉开柜台下一道暗门，钻了进去，咔嚓从里边把门锁上了。\n",
                this_object());
        destruct(this_object());
}

void die()
{
        message_vision("\n$N死了。\n", this_object());
        destruct(this_object());
}
int do_list()
{
        string *goods;
        object *inv;
        int i;

        inv = all_inventory(this_object());

        if (!sizeof(inv) && !arrayp(goods = query("vendor_goods")))
                return notify_fail("目前没有可以卖的东西。\n");
        printf("你可以向%s购买下列物品：\n", query("name"));
        for (i = 0; i < sizeof(inv);i++)
                if (!inv[i]->query("equipped") && !inv[i]->query("money_id"))
                printf("%30-s：%s\n", inv[i]->short(),
                MONEY_D->price_str(inv[i]->query("value") * 300 / 5));
        if (arrayp(goods = query("vendor_goods")))
                for (i = 0; i < sizeof(goods);i++)
                        printf("%30-s：%s\n", goods[i]->short(),
                        MONEY_D->price_str(goods[i]->query("value")));
        return 1;
}
